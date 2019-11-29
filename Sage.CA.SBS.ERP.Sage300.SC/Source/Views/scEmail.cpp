/*--------------------------------------------------------------------

	 File        :   scEmail.cpp
	 Purpose     :   Supporting routines for view functions with code
						  specific to this view.

	 Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.

--------------------------------------------------------------------*/

/////////////////////////////////////////////////////////////////////////////
// The following files are suitable candidates for precompiled headers
#import "c:\program files\common files\system\ado\msado15.dll" rename_namespace("ADODB") rename("EOF", "EndOfFile") raw_interfaces_only
#import <cdosys.dll> no_namespace auto_search auto_rename named_guids raw_interfaces_only

#include <windows.h>
#include <tchar.h>

#include "cdosys.tlh"

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

#include "scEmail.h"

long WINAPI emailSendRaw(
	LPSTR sEmailHost,
	WORD sEmailPort,
	BOOL bEmailSSL,
	LPSTR sEmailUser,
	LPSTR sEmailPassword,
	LPSTR sEmailFrom,
	LPSTR sEmailTo,
	LPSTR sEmailCC,
	LPSTR sEmailSubject,
	LPSTR sEmailBody,
	LPSTR sEmailAttachment)
{
	//
	// Starting Email
	//
	CoInitialize(NULL);

	HRESULT hr = S_OK;

	try
	{
		//
		// Compose Message
		//
		IMessage* pMessage = NULL;
		hr = CoCreateInstance(__uuidof(Message), NULL, CLSCTX_INPROC_SERVER, __uuidof(IMessage), (void**)& pMessage);

		//_variant_t vTo = "charles.cheng@apptalics.com;tvbkhanh@gmail.com";
		//_variant_t vText =
		//	"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\">"
		//	"<HTML>"
		//	"  <BODY>"
		//	"   <p><FONT COLOR=\"#663399\"><b>This is a Test</b></FONT></p>"
		//	"  </BODY>"
		//	"</HTML>";
		ADODB::_Stream* pStream = NULL;
		hr = CoCreateInstance(__uuidof(ADODB::Stream), NULL, CLSCTX_INPROC_SERVER, __uuidof(ADODB::_Stream), (void**)& pStream);
		hr = pStream->put_Charset(_bstr_t("utf-8"));
		//hr = pStream->Open(_variant_t(NULL), ADODB::adModeWrite, ADODB::adOpenStreamUnspecified, _bstr_t(""), _bstr_t(""));
		_variant_t  varOption((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
		hr = pStream->Open(varOption,
			ADODB::adModeUnknown,
			ADODB::adOpenStreamUnspecified,
			_bstr_t(L""), _bstr_t(L""));
		hr = pStream->WriteText(_bstr_t(sEmailBody), ADODB::adWriteChar);

		IDataSource* pDataSource = NULL;
		hr = pMessage->get_DataSource(&pDataSource);
		hr = pDataSource->OpenObject(pStream, _bstr_t("_Stream"));
		//hr = pMessage->get_DataSource()->OpenObject(pStream, "_Stream");

		//hr = pMessage->put_AutoGenerateTextBody(TRUE);
		hr = pMessage->put_MimeFormatted(TRUE);

		hr = pMessage->put_To(_bstr_t(sEmailTo));
		hr = pMessage->put_CC(_bstr_t(sEmailCC));
		hr = pMessage->put_From(_bstr_t(sEmailFrom));
		hr = pMessage->put_Subject(_bstr_t(sEmailSubject));
		//hr = pMessage->put_HTMLBody(_bstr_t(sEmailBody));

		//
		// Process Attachment
		//
		//if (sEmailAttachment != NULL)
		//{
		//	CHAR sPath[MAXLONGPATHLEN + 1];
		//	A4WAPI::strCopyZB(sPath, sEmailAttachment, MAXLONGPATHLEN);
		//	if (A4WAPI::filExists(sPath) == 0)
		//	{
		//		IBodyPart* pBodyPart = NULL;
		//		pMessage->get_BodyPart(&pBodyPart);
		//		pMessage->AddAttachment(_bstr_t(sPath), _bstr_t(), _bstr_t(), NULL);
		//	}
		//}

		IConfiguration* pConfiguration = NULL;
		hr = CoCreateInstance(__uuidof(Configuration), NULL, CLSCTX_INPROC_SERVER, __uuidof(IConfiguration), (void**)& pConfiguration);

		ADODB::Fields* pFields = NULL;
		ADODB::Field* pField = NULL;

		hr = pConfiguration->get_Fields(&pFields);
		// cdoSendUsingMethod
		hr = pFields->get_Item(_variant_t(cdoSendUsingMethod), &pField);
		hr = pField->put_Value(_variant_t((long)cdoSendUsingPort));
		pField->Release();
		pField = NULL;
		// cdoSMTPServer
		hr = pFields->get_Item(_variant_t(cdoSMTPServer), &pField);
		hr = pField->put_Value(_variant_t(sEmailHost)); // SMTP Server
		pField->Release();
		pField = NULL;
		// cdoSMTPServerPort
		hr = pFields->get_Item(_variant_t(cdoSMTPServerPort), &pField);
		hr = pField->put_Value(_variant_t((long)sEmailPort)); // SMTP Port
		pField->Release();
		pField = NULL;
		// cdoSMTPUseSSL
		hr = pFields->get_Item(_variant_t(cdoSMTPUseSSL), &pField);
		hr = pField->put_Value(_variant_t((bool)(bEmailSSL == 1))); // SMTP Port
		pField->Release();
		pField = NULL;
		// cdoSMTPAuthenticate
		pFields->get_Item(_variant_t(cdoSMTPAuthenticate), &pField);
		pField->put_Value(_variant_t(cdoBasic));
		pField->Release();
		pField = NULL;
		// cdoSendUserName
		pFields->get_Item(_variant_t(cdoSendUserName), &pField);
		pField->put_Value(_variant_t(sEmailUser));
		pField->Release();
		pField = NULL;
		// cdoSendPassword
		pFields->get_Item(_variant_t(cdoSendPassword), &pField);
		pField->put_Value(_variant_t(sEmailPassword));
		pField->Release();
		pField = NULL;

		hr = pFields->Update();
		pFields->Release();
		pFields = NULL;

		hr = pMessage->putref_Configuration(pConfiguration);
		pConfiguration->Release();
		pConfiguration = NULL;
		//
		hr = pMessage->Send();

		//
		// Release attachments locking
		//
		IBodyParts* bodyParts;
		pMessage->get_Attachments(&bodyParts);
		bodyParts->DeleteAll();
		//
		pDataSource->Release();
		pDataSource = NULL;
		//
		pStream->Release();
		pStream = NULL;
		//
		pMessage->Release();
		pMessage = NULL;
	}
	catch (_com_error& e)
	{
		hr = 1;
	}

	CoUninitialize();

	return hr;
}


long WINAPI emailSend(
	LPSTR sEmailHost,
	WORD sEmailPort,
	BOOL bEmailSSL,
	LPSTR sEmailUser,
	LPSTR sEmailPassword,
	LPSTR sEmailFrom,
	LPSTR sEmailTo,
	LPSTR sEmailCC,
	LPSTR sEmailSubject,
	LPSTR sEmailBody,
	LPSTR sEmailAttachment)
{
	//
	// Starting Email
	//
	CoInitialize(NULL);

	HRESULT hr = S_OK;

	try
	{
		//
		// Compose Message
		//
		IMessage* pMessage = NULL;
		hr = CoCreateInstance(__uuidof(Message), NULL, CLSCTX_INPROC_SERVER, __uuidof(IMessage), (void**)& pMessage);

		//_variant_t vTo = "charles.cheng@apptalics.com;tvbkhanh@gmail.com";
		//_variant_t vText =
		//	"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\">"
		//	"<HTML>"
		//	"  <BODY>"
		//	"   <p><FONT COLOR=\"#663399\"><b>This is a Test</b></FONT></p>"
		//	"  </BODY>"
		//	"</HTML>";

		hr = pMessage->put_To(_bstr_t(sEmailTo));
		hr = pMessage->put_CC(_bstr_t(sEmailCC));
		hr = pMessage->put_From(_bstr_t(sEmailFrom));
		hr = pMessage->put_Subject(_bstr_t(sEmailSubject));
		hr = pMessage->put_HTMLBody(_bstr_t(sEmailBody));

		hr = pMessage->put_AutoGenerateTextBody(TRUE);
		hr = pMessage->put_MimeFormatted(TRUE);

		//
		// Process Attachment
		//
		if (sEmailAttachment != NULL)
		{
			CHAR sPath[MAXLONGPATHLEN + 1];
			A4WAPI::strCopyZB(sPath, sEmailAttachment, MAXLONGPATHLEN);
			if (A4WAPI::filExists(sPath) == 0)
			{
				IBodyPart* pBodyPart = NULL;
				pMessage->get_BodyPart(&pBodyPart);
				pMessage->AddAttachment(_bstr_t(sPath), _bstr_t(), _bstr_t(), NULL);
			}
		}

		IConfiguration* pConfiguration = NULL;
		hr = CoCreateInstance(__uuidof(Configuration), NULL, CLSCTX_INPROC_SERVER, __uuidof(IConfiguration), (void**)& pConfiguration);

		ADODB::Fields* pFields = NULL;
		ADODB::Field* pField = NULL;

		hr = pConfiguration->get_Fields(&pFields);
		// cdoSendUsingMethod
		hr = pFields->get_Item(_variant_t(cdoSendUsingMethod), &pField);
		hr = pField->put_Value(_variant_t((long)cdoSendUsingPort));
		pField->Release();
		pField = NULL;
		// cdoSMTPServer
		hr = pFields->get_Item(_variant_t(cdoSMTPServer), &pField);
		hr = pField->put_Value(_variant_t(sEmailHost)); // SMTP Server
		pField->Release();
		pField = NULL;
		// cdoSMTPServerPort
		hr = pFields->get_Item(_variant_t(cdoSMTPServerPort), &pField);
		hr = pField->put_Value(_variant_t((long)sEmailPort)); // SMTP Port
		pField->Release();
		pField = NULL;
		// cdoSMTPUseSSL
		hr = pFields->get_Item(_variant_t(cdoSMTPUseSSL), &pField);
		hr = pField->put_Value(_variant_t((bool)(bEmailSSL == 1))); // SMTP Port
		pField->Release();
		pField = NULL;
		// cdoSMTPAuthenticate
		pFields->get_Item(_variant_t(cdoSMTPAuthenticate), &pField);
		pField->put_Value(_variant_t(cdoBasic));
		pField->Release();
		pField = NULL;
		// cdoSendUserName
		pFields->get_Item(_variant_t(cdoSendUserName), &pField);
		pField->put_Value(_variant_t(sEmailUser));
		pField->Release();
		pField = NULL;
		// cdoSendPassword
		pFields->get_Item(_variant_t(cdoSendPassword), &pField);
		pField->put_Value(_variant_t(sEmailPassword));
		pField->Release();
		pField = NULL;

		hr = pFields->Update();
		pFields->Release();
		pFields = NULL;

		hr = pMessage->putref_Configuration(pConfiguration);
		pConfiguration->Release();
		pConfiguration = NULL;
		//
		hr = pMessage->Send();

		//
		// Release attachments locking
		//
		IBodyParts* bodyParts;
		pMessage->get_Attachments(&bodyParts);
		bodyParts->DeleteAll();
		//
		pMessage->Release();
		pMessage = NULL;
	}
	catch (_com_error& e)
	{
		hr = 1;
	}

	CoUninitialize();

	return hr;
}

long WINAPI emailSendDefault(
	LPVOID rvh,
	LPVOID view,
	LPSTR sEmailTo,
	LPSTR sEmailCC,
	LPSTR sEmailSubject,
	LPSTR sEmailBody,
	LPSTR sEmailAttachment)
{
	return 0;
}

#if defined(__cplusplus)
}
#endif
