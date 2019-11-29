/*--------------------------------------------------------------------

    File    :  scLoan.i
    Purpose :  Resource ids.
               BE SURE TO ADD A `#INCLUDE "scLoan.i"'
               LINE TO YYYY.RC AND A DEPENDENCY TO YYYY.MAK.

    Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.

--------------------------------------------------------------------*/


#ifndef __scLoan_i
// Ensures header is only included once.
#define __scLoan_i        1


#ifdef __cplusplus
extern "C" {
#endif


//////////////////////////////////////////////////////////////////////
// Change these definitions as necessary

// +++

#define  SCLOAN_NAME              10000
#define  SCLOAN_KEY_OFFSET        (SCLOAN_NAME + 2)
#define  SCLOAN_FLD_OFFSET        (SCLOAN_KEY_OFFSET + 5)
#define  SCLOAN_PRESENTS_OFFSET   (SCLOAN_FLD_OFFSET + 150)
#define  SCLOAN_ERROR_OFFSET      (SCLOAN_PRESENTS_OFFSET + 250)

// View name (eg-Phone List) & noun (eg-Phone number)
// The noun is a single record. The name is the set of all records.
#define  IDS_SCLOAN_VIEW_NAME     SCLOAN_NAME
#define  IDS_SCLOAN_VIEW_NOUN     (SCLOAN_NAME + 1)

// Key names: add as many keys as needed
#define  IDS_SCLOAN_KEY_NAME		(SCLOAN_KEY_OFFSET + 0)
#define  IDS_SCLOAN_KEY1_NAME    (SCLOAN_KEY_OFFSET + 1)

// Field names: add as many fields as needed
#include "SCLOANT.GEN"
#include "SCLOAN2T.GEN"

// Presentation strings: add any definitions, or remove these lines
// if no presentation information is needed.
#define IDS_SCLOAN_STATUS_PENDING		(SCLOAN_PRESENTS_OFFSET + 0)
#define IDS_SCLOAN_STATUS_SUBMITTED		(SCLOAN_PRESENTS_OFFSET + 1)
#define IDS_SCLOAN_STATUS_CANCELLED		(SCLOAN_PRESENTS_OFFSET + 2)
#define IDS_SCLOAN_STATUS_REJECTED		(SCLOAN_PRESENTS_OFFSET + 3)
#define IDS_SCLOAN_STATUS_APPROVED		(SCLOAN_PRESENTS_OFFSET + 4)

#define IDS_SCLOAN_CTACMETHOD_EMAIL		(SCLOAN_PRESENTS_OFFSET + 10)
#define IDS_SCLOAN_CTACMETHOD_PHONE		(SCLOAN_PRESENTS_OFFSET + 11)
#define IDS_SCLOAN_CTACMETHOD_MOBILE	(SCLOAN_PRESENTS_OFFSET + 12)

#define IDS_SCLOAN_MESSAGE_RESEND		(SCLOAN_PRESENTS_OFFSET + 15)

#define IDS_SCLOAN_MESSAGE_SG_SUBJECT	(SCLOAN_PRESENTS_OFFSET + 20)
#define IDS_SCLOAN_MESSAGE_SG_BODY		(SCLOAN_PRESENTS_OFFSET + 21)

// ---

#define IDERR_SCLOAN_AMOUNT_REQUEST		(SCLOAN_ERROR_OFFSET + 0)

#define IDERR_SCLOAN_SUBMIT_FAILED		(SCLOAN_ERROR_OFFSET + 10)


#ifdef __cplusplus
}
#endif


#endif
