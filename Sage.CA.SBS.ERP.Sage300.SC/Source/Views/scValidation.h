/*--------------------------------------------------------------------

	 File        :   scValidation.h
	 Purpose     :   Common Validation functions

	 Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.

--------------------------------------------------------------------*/



#ifndef __scValidation_h
// Ensures header is only included once.
#define __scValidation_h        1

#include "plusapi.h"


#ifdef __cplusplus
extern "C" {
#endif


//
// Validate text blank text field
////
BOOL WINAPI NotBlankValid(
	LPV lpv,
	LONG lField,
	LPSTR lpValue)
{
	INT i;

	for (i = FindFieldDef(lField)->wLength - 1; i >= 0; i--)
		if (lpValue[i] != ' ')
			break;

	if (i < 0)
	{
		ReportError(lpv, IDERR_SC_FIELD_ISBLANK, MAKERSC(FindFieldMap(lField)->title), NULL, NULL);
		return FALSE;
	}

	return TRUE;
}


BOOL WINAPI EmailValid(
	LPV lpv,
	LONG lField,
	LPSTR lpValue)
{
	CHAR sEmail[MAX_FIELD_LENGTH + 1];
	strCopyZB(sEmail, lpValue, FindFieldDef(lField)->wLength);

	if (utlIsValidEmail(sEmail))
		return TRUE;

	ReportError(lpv, IDERR_SC_EMAIL_INVALID, MAKERSC(FindFieldMap(lField)->title), NULL, NULL);
	return FALSE;
}

#ifdef __cplusplus
}
#endif


#endif