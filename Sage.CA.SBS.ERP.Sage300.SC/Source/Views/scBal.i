/*--------------------------------------------------------------------

    File    :  scBal.i
    Purpose :  Resource ids.
               BE SURE TO ADD A `#INCLUDE "scBal.i"'
               LINE TO YYYY.RC AND A DEPENDENCY TO YYYY.MAK.

    Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.

--------------------------------------------------------------------*/


#ifndef __scBal_i
// Ensures header is only included once.
#define __scBal_i        1


#ifdef __cplusplus
extern "C" {
#endif


//////////////////////////////////////////////////////////////////////
// Change these definitions as necessary

// +++

#define  SCBAL_NAME              5000
#define  SCBAL_KEY_OFFSET        (SCBAL_NAME + 2)
#define  SCBAL_FLD_OFFSET        (SCBAL_KEY_OFFSET + 5)
#define  SCBAL_PRESENTS_OFFSET   (SCBAL_FLD_OFFSET + 150)
#define  SCBAL_ERROR_OFFSET      (SCBAL_PRESENTS_OFFSET + 250)

// View name (eg-Phone List) & noun (eg-Phone number)
// The noun is a single record. The name is the set of all records.
#define  IDS_SCBAL_VIEW_NAME     SCBAL_NAME
#define  IDS_SCBAL_VIEW_NOUN     (SCBAL_NAME + 1)

// Key names: add as many keys as needed
#define  IDS_SCBAL_KEY_NAME      (SCBAL_KEY_OFFSET + 0)

// Field names: add as many fields as needed
#include "SCBALT.GEN"
#include "SCBAL2T.GEN"

// Presentation strings: add any definitions, or remove these lines
// if no presentation information is needed.
#define  IDS_SCBAL_TYPE_0        (SCBAL_PRESENTS_OFFSET + 0)
#define  IDS_SCBAL_TYPE_1        (SCBAL_PRESENTS_OFFSET + 1)

// ---


#ifdef __cplusplus
}
#endif


#endif
