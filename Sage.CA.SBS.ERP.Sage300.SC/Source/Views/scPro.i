/*--------------------------------------------------------------------

    File    :  scPro.i
    Purpose :  Resource ids.
               BE SURE TO ADD A `#INCLUDE "scPro.i"'
               LINE TO YYYY.RC AND A DEPENDENCY TO YYYY.MAK.

    Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.

--------------------------------------------------------------------*/


#ifndef __scPro_i
// Ensures header is only included once.
#define __scPro_i        1


#ifdef __cplusplus
extern "C" {
#endif


//////////////////////////////////////////////////////////////////////
// Change these definitions as necessary

// +++

#define  SCPRO_NAME              50000
#define  SCPRO_KEY_OFFSET        (SCPRO_NAME + 2)
#define  SCPRO_FLD_OFFSET        (SCPRO_KEY_OFFSET + 5)
#define  SCPRO_PRESENTS_OFFSET   (SCPRO_FLD_OFFSET + 150)
#define  SCPRO_ERROR_OFFSET      (SCPRO_PRESENTS_OFFSET + 250)

// View name (eg-Phone List) & noun (eg-Phone number)
// The noun is a single record. The name is the set of all records.
#define  IDS_SCPRO_VIEW_NAME     SCPRO_NAME
#define  IDS_SCPRO_VIEW_NOUN     (SCPRO_NAME + 1)

// Key names: add as many keys as needed
#define  IDS_SCPRO_KEY_NAME      (SCPRO_KEY_OFFSET + 0)

// Field names: add as many fields as needed
#include "SCPROT.GEN"
//#include "SCPRO2T.GEN"

// Presentation strings: add any definitions, or remove these lines
// if no presentation information is needed.
#define	IDS_SCPRO_METER_CAPTION						(SCPRO_PRESENTS_OFFSET + 10)
#define	IDS_SCPRO_METER_SCBAL_NORMAL_LABEL		(SCPRO_PRESENTS_OFFSET + 11)
#define	IDS_SCPRO_METER_SCBAL_PENDING_LABEL		(SCPRO_PRESENTS_OFFSET + 12)
#define	IDS_SCPRO_METER_SCTRAN_NORMAL_LABEL		(SCPRO_PRESENTS_OFFSET + 13)
#define	IDS_SCPRO_METER_SCTRAN_PENDING_LABEL	(SCPRO_PRESENTS_OFFSET + 14)

// ---
#define	IDS_SCPRO_EMAIL_SUBJECT_ALERT				(SCPRO_PRESENTS_OFFSET + 20)
#define	IDS_SCPRO_EMAIL_SUBJECT_ALERTLOAN		(SCPRO_PRESENTS_OFFSET + 21)
#define	IDS_SCPRO_EMAIL_SUBJECT_LOAN				(SCPRO_PRESENTS_OFFSET + 22)

#ifdef __cplusplus
}
#endif


#endif
