/*--------------------------------------------------------------------

    File    :  scTran.i
    Purpose :  Resource ids.
               BE SURE TO ADD A `#INCLUDE "scTran.i"'
               LINE TO YYYY.RC AND A DEPENDENCY TO YYYY.MAK.

    Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.

--------------------------------------------------------------------*/


#ifndef __scTran_i
// Ensures header is only included once.
#define __scTran_i        1


#ifdef __cplusplus
extern "C" {
#endif


//////////////////////////////////////////////////////////////////////
// Change these definitions as necessary

// +++

#define  SCTRAN_NAME              6000
#define  SCTRAN_KEY_OFFSET        (SCTRAN_NAME + 2)
#define  SCTRAN_FLD_OFFSET        (SCTRAN_KEY_OFFSET + 5)
#define  SCTRAN_PRESENTS_OFFSET   (SCTRAN_FLD_OFFSET + 150)
#define  SCTRAN_ERROR_OFFSET      (SCTRAN_PRESENTS_OFFSET + 250)

// View name (eg-Phone List) & noun (eg-Phone number)
// The noun is a single record. The name is the set of all records.
#define  IDS_SCTRAN_VIEW_NAME     SCTRAN_NAME
#define  IDS_SCTRAN_VIEW_NOUN     (SCTRAN_NAME + 1)

// Key names: add as many keys as needed
#define  IDS_SCTRAN_KEY_NAME      (SCTRAN_KEY_OFFSET + 0)

// Field names: add as many fields as needed
#include "SCTRANT.GEN"
#include "SCTRAN2T.GEN"

// Presentation strings: add any definitions, or remove these lines
// if no presentation information is needed.
#define  IDS_SCTRAN_TYPE_0        (SCTRAN_PRESENTS_OFFSET + 0)
#define  IDS_SCTRAN_TYPE_1        (SCTRAN_PRESENTS_OFFSET + 1)

// ---


#ifdef __cplusplus
}
#endif


#endif
