/*--------------------------------------------------------------------

    File    :  scSchdl.i
    Purpose :  Resource ids.
               BE SURE TO ADD A `#INCLUDE "scSchdl.i"'
               LINE TO YYYY.RC AND A DEPENDENCY TO YYYY.MAK.

    Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.

--------------------------------------------------------------------*/


#ifndef __scSchdl_i
// Ensures header is only included once.
#define __scSchdl_i        1


#ifdef __cplusplus
extern "C" {
#endif


//////////////////////////////////////////////////////////////////////
// Change these definitions as necessary

// +++

#define  SCSCHDL_NAME              0
#define  SCSCHDL_KEY_OFFSET        300
#define  SCSCHDL_FLD_OFFSET        600
#define  SCSCHDL_PRESENTS_OFFSET   5000
#define  SCSCHDL_ERROR_OFFSET      10000

// View name (eg-Phone List) & noun (eg-Phone number)
// The noun is a single record. The name is the set of all records.
#define  IDS_SCSCHDL_VIEW_NAME     SCSCHDL_NAME
#define  IDS_SCSCHDL_VIEW_NOUN     (SCSCHDL_NAME + 1)

// Key names: add as many keys as needed
#define  IDS_SCSCHDL_KEY_NAME      (SCSCHDL_KEY_OFFSET + 0)

// Field names: add as many fields as needed
#include "SCSCHDLT.GEN"
//#include "SCSCHDL2T.GEN"

// Presentation strings: add any definitions, or remove these lines
// if no presentation information is needed.
#define  IDS_SCSCHDL_TYPE_0        (SCSCHDL_PRESENTS_OFFSET + 0)
#define  IDS_SCSCHDL_TYPE_1        (SCSCHDL_PRESENTS_OFFSET + 1)

// ---


#ifdef __cplusplus
}
#endif


#endif
