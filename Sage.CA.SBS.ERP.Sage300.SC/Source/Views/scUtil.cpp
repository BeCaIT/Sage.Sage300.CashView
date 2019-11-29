/*--------------------------------------------------------------------

	 File        :   scUtil.cpp
	 Purpose     :   Supporting routines for view functions with code
						  specific to this view.

	 Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.

--------------------------------------------------------------------*/

/////////////////////////////////////////////////////////////////////////////
// The following files are suitable candidates for precompiled headers

#include <plusapi.h>

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include <rotoview.h>
#include <roto.h>

#if defined(__cplusplus)
namespace A4WAPI {
#endif

#include "scUtil.h"

VOID WINAPI strEncrypt(
	LPBYTE target, 
	LPBYTE source, 
	INT size)
{
	for (int i = 0; i < size; i++)
		target[i] = source[i] ^ 255;
}

VOID WINAPI licGetClientId(
	HPIB pib, 
	LPSTR buffer)
{
	CHAR smLicenseFile[] = "SMxxx0.yyy";
	CHAR cSecret = (CHAR)255;

	ibGetSystemVersion(pib, (LPBYTE)& smLicenseFile[2]);

	SMSERIESINFO smInfo;
	smInfo.wSize = sizeof(smInfo);
	smGetSeriesInfo(&smInfo);

	if (smInfo.wProduct == EDITION_CORPORATE)
	{
		blkCopy(&smLicenseFile[7], "PLS", 3);
		cSecret = (CHAR)170;
	}
	else
		blkCopy(&smLicenseFile[7], "LIC", 3);

	CHAR path[MAXLONGPATHLEN];
	utlGetSitePath(path, MAXLONGPATHLEN);
	utlMakePath(path, path, smLicenseFile);

	FHANDLE fHandle;

	if (!filOpen(path, &fHandle, __O_READ))
	{
		DWORD dwSize = 0;
		filSize(fHandle, &dwSize);

		if (dwSize > 0)
		{
			LPBYTE buf = new BYTE[dwSize];
			WORD wRead = 0;

			if (!filRead(fHandle, buf, (WORD)dwSize, &wRead))
			{
				if (wRead > 0)
				{
					for (INT i = 0; i < wRead; i++)
						buf[i] ^= cSecret;

					blkCopy(buffer, &buf[235], SIZEOF_CLIENTID);
				}
			}
		}

		filClose(fHandle);
	}
}

VOID WINAPI licConvertClientId(
	LPSTR buffer, 
	int limit)
{
	CHAR szClientIdTemp[SIZEOF_CLIENTID + 1];
	CHAR szClientId[SIZEOF_CLIENTID + 1];

	strCopyZB(szClientIdTemp, buffer, SIZEOF_CLIENTID);
	sprintf(szClientId, "%0*s", 10, szClientIdTemp);
	strCopyBZ(buffer, limit, szClientId);

	//
	//// Convert first 3 digits
	for (int i = 0; i < 3; i++)
		buffer[i] = 'A' + (buffer[i] - '0');

	//
	//// Convert the rest 7 digits
	for (int i = 3; i < SIZEOF_CLIENTID; i++)
		buffer[i] = (buffer[i] >= '5') ? buffer[i] - 5 : buffer[i] + 5;
}

int WINAPI rscLoadHTML(HPIB pib, LPSTR pgmID, UINT code, LPSTR buffer, UINT length)
{
	DWORD dwRscLength = 0;

	HINSTANCE hInstance = NULL;

	if (rscLoadRscDLL(pib, (PCBYTE)pgmID, &hInstance))
	{
		HRSRC hRsrc = FindResource(hInstance, MAKEINTRESOURCE(code), RT_HTML);
		if (hRsrc != NULL)
		{
			dwRscLength = SizeofResource(hInstance, hRsrc);
			if (dwRscLength > length)
				dwRscLength = length;

			HGLOBAL hGlobal = LoadResource(hInstance, hRsrc);			
			if (hGlobal != NULL)
			{
				LPCSTR lpcHTML = (LPCSTR)LockResource(hGlobal);
				if (lpcHTML != NULL)
				{
					blkCopy(buffer, lpcHTML, dwRscLength);
				}
				UnlockResource(lpcHTML);

				FreeResource(hGlobal);
			}
		}
	}

	return dwRscLength;
}

WORD WINAPI GetIniFileKey(
	HPIB pib, 
	LPSTR pgmID,
	LPSTR primaryKey, 
	LPSTR secondaryKey, 
	LPVOID buffer, 
	LPINT size)
{
	WORD result = 0;

	HSIB sib = ibGetSIB(pib);

	WORD wHandle = 0;
	result = pgmRscFileOpen(sib, "SC", &wHandle);
	if (!result)
	{
		result = pgmRscFileRead(wHandle, primaryKey, secondaryKey, buffer, size);
		pgmRscFileClose(wHandle);
	}

	return result;
}

#if defined(__cplusplus)
}
#endif
