/*--------------------------------------------------------------------

	 File        :   scEmail.h
	 Purpose     :   External definitions for this view.

	 Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.

--------------------------------------------------------------------*/



#ifndef __scEmail_h
// Ensures header is only included once.
#define __scEmail_h        1

#ifdef __cplusplus
extern "C" {
#endif

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
	LPSTR sEmailAttachment);


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
	LPSTR sEmailAttachment);

long WINAPI emailSendDefault(
	LPVOID rvh,
	LPVOID view,
	LPSTR sEmailTo,
	LPSTR sEmailCC,
	LPSTR sEmailSubject,
	LPSTR sEmailBody,
	LPSTR sEmailAttachment);

#ifdef __cplusplus
}
#endif


#endif