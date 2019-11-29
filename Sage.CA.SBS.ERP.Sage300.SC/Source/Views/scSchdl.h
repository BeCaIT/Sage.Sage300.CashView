/*--------------------------------------------------------------------

    File        :   scSchdl.h
    Purpose     :   External definitions for this view.

    Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.

--------------------------------------------------------------------*/



#ifndef __scSchdl_h
// Ensures header is only included once.
#define __scSchdl_h        1


#ifdef __cplusplus
extern "C" {
#endif


//////////////////////////////////////////////////////////////////////
// Change these definitions as necessary

// +++
#include "csSktb.h"

// Define the view's roto ID. For subclass views should be original base view
#define  SCSCHDL_ROTOID          "SC0899"


// Define view field index numbers.
#include "SCSCHDLI.GEN"
//#include "SCSCHDL2I.GEN"


// Define view field sizes.
#include "SCSCHDLS.GEN"
//#include "SCSCHDL2S.GEN"

// ---


#ifdef __cplusplus
}
#endif


#endif

