/*--------------------------------------------------------------------

    File        :   scTran.h
    Purpose     :   External definitions for this view.

    Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.

--------------------------------------------------------------------*/



#ifndef __scTran_h
// Ensures header is only included once.
#define __scTran_h        1


#ifdef __cplusplus
extern "C" {
#endif


//////////////////////////////////////////////////////////////////////
// Change these definitions as necessary

// +++

// Define the view's roto ID. For subclass views should be original base view
#define  SCTRAN_ROTOID          "SC0110"


// Define view field index numbers.
#include "SCTRANI.GEN"
#include "SCTRAN2I.GEN"


// Define view field sizes.
#include "SCTRANS.GEN"
#include "SCTRAN2S.GEN"

// ---


#ifdef __cplusplus
}
#endif


#endif

