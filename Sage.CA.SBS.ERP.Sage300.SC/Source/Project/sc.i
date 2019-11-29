/*--------------------------------------------------------------------

    File        :   sc.i
    Purpose     :   Shared resource ids. (Shared amongst views)

    Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.

--------------------------------------------------------------------*/

#ifndef __sc_i
#define __sc_i


#define SYS_OFFSET         60000


//////////////////////////////////////////////////////////////////////
// Change these definitions as necessary

// +++

// Set the following to a value that fits in with your application's
// string resource scheme
//#define SC_ERROR_OFFSET    32700
#define SC_ERROR_OFFSET    59900

#include "scerr.i"



// Set the following to values that fit in with your application's
// string resource scheme
//#define  SC_DP_OFFSET    32500
#define  SC_DP_OFFSET    59800
#define  SC_DP_APPLID    "SC" // application prefix
#define  SC_DP_APPLVER   "63A" // application version

#include "scdp.i"



// Add shared string ID's as necessary
#define	SC_PRESENTS_OFFSET			59000

#define	IDS_SC_YES						(SC_PRESENTS_OFFSET + 0)
#define	IDS_SC_NO						(SC_PRESENTS_OFFSET + 1)

#define	IDS_SC_RECTYPE_NORMAL		(SC_PRESENTS_OFFSET + 2)
#define	IDS_SC_RECTYPE_PENDING		(SC_PRESENTS_OFFSET + 3)

// Shared Error Code
#define	SC_SHARED_ERROR_OFFSET			59400

#define	IDERR_SC_FIELD_ISBLANK			(SC_SHARED_ERROR_OFFSET + 1)
#define	IDERR_SC_FIELD_NOTSPECIFIED	(SC_SHARED_ERROR_OFFSET + 2)

#define	IDERR_SC_EMAIL_INVALID			(SC_SHARED_ERROR_OFFSET + 10)

#define	IDERR_SC_OPTIONS_NOT_SET		(SC_SHARED_ERROR_OFFSET + 50)


//
//// Security Resources
#define	SC_RSC_OFFSET				59300

#define	IDS_SC_RSC_SCSETUP		(SC_RSC_OFFSET + 0)
#define	IDS_SC_RSC_SCINQUIRY		(SC_RSC_OFFSET + 10)
#define	IDS_SC_RSC_SCPROCESS		(SC_RSC_OFFSET + 11)
#define	IDS_SC_RSC_SCFCENTRY		(SC_RSC_OFFSET + 21)
#define	IDS_SC_RSC_SCLINQUIRY	(SC_RSC_OFFSET + 30)
#define	IDS_SC_RSC_SCLENTRY		(SC_RSC_OFFSET + 31)


// ---


#endif
