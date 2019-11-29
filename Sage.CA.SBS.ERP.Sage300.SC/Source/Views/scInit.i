/*--------------------------------------------------------------------

    File    :  scInit.i
    Purpose :  Resource ids.
               BE SURE TO ADD A `#INCLUDE "scInit.i"'
               LINE TO YYYY.RC AND A DEPENDENCY TO YYYY.MAK.

    Copyright � 2019 Sage Software Asia Pte Ltd. All rights reserved.

--------------------------------------------------------------------*/


#ifndef __scInit_i
// Ensures header is only included once.
#define __scInit_i        1


#ifdef __cplusplus
extern "C" {
#endif


//////////////////////////////////////////////////////////////////////
// Change these definitions as necessary

// +++

#define  SCINIT_NAME              58500
#define  SCINIT_KEY_OFFSET        (SCINIT_NAME + 2)
#define  SCINIT_FLD_OFFSET        (SCINIT_KEY_OFFSET + 5)
#define  SCINIT_PRESENTS_OFFSET   (SCINIT_FLD_OFFSET + 150)
#define  SCINIT_ERROR_OFFSET      (SCINIT_PRESENTS_OFFSET + 250)

// View name (eg-Phone List) & noun (eg-Phone number)
// The noun is a single record. The name is the set of all records.
#define  IDS_SCINIT_VIEW_NAME     SCINIT_NAME
#define  IDS_SCINIT_VIEW_NOUN     (SCINIT_NAME + 1)

// Key names: add as many keys as needed
#define  IDS_SCINIT_KEY_NAME      (SCINIT_KEY_OFFSET + 0)

// Field names: add as many fields as needed
#include "SCINITT.GEN"
//#include "SCINIT2T.GEN"

// Presentation strings: add any definitions, or remove these lines
// if no presentation information is needed.
#define  IDS_SCINIT_PROCESSCMD_ACTIVATE		(SCINIT_PRESENTS_OFFSET + 0)
#define  IDS_SCINIT_PROCESSCMD_DEACTIVATE		(SCINIT_PRESENTS_OFFSET + 1)

// ---


#ifdef __cplusplus
}
#endif


#endif
