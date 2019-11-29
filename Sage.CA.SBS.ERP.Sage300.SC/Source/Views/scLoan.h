/*--------------------------------------------------------------------

    File        :   scLoan.h
    Purpose     :   External definitions for this view.

    Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.

--------------------------------------------------------------------*/



#ifndef __scLoan_h
// Ensures header is only included once.
#define __scLoan_h        1


#ifdef __cplusplus
extern "C" {
#endif


//////////////////////////////////////////////////////////////////////
// Change these definitions as necessary

// +++

// Define the view's roto ID. For subclass views should be original base view
#define  SCLOAN_ROTOID          "SC0200"


// Define view field index numbers.
#include "SCLOANI.GEN"
#include "SCLOAN2I.GEN"


// Define view field sizes.
#include "SCLOANS.GEN"
#include "SCLOAN2S.GEN"

// ---

#define	SCLOAN_STATUS_PENDING	0
#define	SCLOAN_STATUS_SUBMITTED	1
#define	SCLOAN_STATUS_CANCELLED	2
#define	SCLOAN_STATUS_REJECTED	3
#define	SCLOAN_STATUS_APPROVED	4


#define	SCLOAN_ERROR_SUBMIT_FAILED	ERRNUM_APPLICATION_DEFINE(0)


#ifdef __cplusplus
}
#endif


#endif

