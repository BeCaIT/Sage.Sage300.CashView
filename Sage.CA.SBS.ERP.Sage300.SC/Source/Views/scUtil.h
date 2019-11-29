/*--------------------------------------------------------------------

	 File        :   scUtil.h
	 Purpose     :   External definitions for this view.

	 Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.

--------------------------------------------------------------------*/

#include <plustype.h>

#ifndef __scUtil_h
// Ensures header is only included once.
#define __scUtil_h        1

#ifdef __cplusplus
extern "C" {
#endif


#define	SIZEOF_CLIENTID	10


VOID WINAPI strEncrypt(
	LPBYTE target, 
	LPBYTE source, 
	INT size);


VOID WINAPI licGetClientId(
	INT pib, 
	LPSTR buffer);


VOID WINAPI licConvertClientId(
	LPSTR buffer, 
	int limit);

int WINAPI rscLoadHTML(A4WAPI::HPIB pib, LPSTR pgmID, UINT code, LPSTR buffer, UINT length);

//
//
//
WORD WINAPI GetIniFileKey(A4WAPI::HPIB pib, LPSTR pgmID, LPSTR primaryKey, LPSTR secondaryKey, LPVOID buffer, A4WAPI::LPINT size);


//
// MACRO
#define strInit(STR) blkSet(STR, 0, sizeof(STR))

#ifdef __cplusplus
}
#endif


#endif