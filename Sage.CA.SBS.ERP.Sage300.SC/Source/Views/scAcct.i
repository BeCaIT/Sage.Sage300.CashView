/*--------------------------------------------------------------------

    File    :  scAcct.i
    Purpose :  Resource ids.
               BE SURE TO ADD A `#INCLUDE "scAcct.i"'
               LINE TO YYYY.RC AND A DEPENDENCY TO YYYY.MAK.

    Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.

--------------------------------------------------------------------*/


#ifndef __scAcct_i
// Ensures header is only included once.
#define __scAcct_i        1


#ifdef __cplusplus
extern "C" {
#endif


//////////////////////////////////////////////////////////////////////
// Change these definitions as necessary

// +++

#define  SCACCT_NAME              1500
#define  SCACCT_KEY_OFFSET        (SCACCT_NAME + 2)
#define  SCACCT_FLD_OFFSET        (SCACCT_KEY_OFFSET + 5)
#define  SCACCT_PRESENTS_OFFSET   (SCACCT_FLD_OFFSET + 150)
#define  SCACCT_ERROR_OFFSET      (SCACCT_PRESENTS_OFFSET + 250)

// View name (eg-Phone List) & noun (eg-Phone number)
// The noun is a single record. The name is the set of all records.
#define  IDS_SCACCT_VIEW_NAME     SCACCT_NAME
#define  IDS_SCACCT_VIEW_NOUN     (SCACCT_NAME + 1)

// Key names: add as many keys as needed
#define  IDS_SCACCT_KEY_NAME      (SCACCT_KEY_OFFSET + 0)

// Field names: add as many fields as needed
#include "SCACCTT.GEN"
#include "SCACCT2T.GEN"

// Presentation strings: add any definitions, or remove these lines
// if no presentation information is needed.
#define  IDS_SCACCT_TYPE_0        (SCACCT_PRESENTS_OFFSET + 0)
#define  IDS_SCACCT_TYPE_1        (SCACCT_PRESENTS_OFFSET + 1)

// ---


#ifdef __cplusplus
}
#endif


#endif
