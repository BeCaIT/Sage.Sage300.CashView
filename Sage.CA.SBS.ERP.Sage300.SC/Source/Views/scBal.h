/*--------------------------------------------------------------------

    File        :   scBal.h
    Purpose     :   External definitions for this view.

    Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.

--------------------------------------------------------------------*/



#ifndef __scBal_h
// Ensures header is only included once.
#define __scBal_h        1


#ifdef __cplusplus
extern "C" {
#endif


//////////////////////////////////////////////////////////////////////
// Change these definitions as necessary

// +++
#include	"glamf.h"
#include	"glacgrp.h"


// Define the view's roto ID. For subclass views should be original base view
#define  SCBAL_ROTOID          "SC0100"


// Define view field index numbers.
#include "SCBALI.GEN"
#include "SCBAL2I.GEN"


// Define view field sizes.
#include "SCBALS.GEN"
#include "SCBAL2S.GEN"

// ---


#ifdef __cplusplus
}
#endif


#endif

