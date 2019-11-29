/*--------------------------------------------------------------------

    File        :   scInit.h
    Purpose     :   External definitions for this view.

    Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.

--------------------------------------------------------------------*/



#ifndef __scInit_h
// Ensures header is only included once.
#define __scInit_h        1


#ifdef __cplusplus
extern "C" {
#endif


//////////////////////////////////////////////////////////////////////
// Change these definitions as necessary

// +++

// Define the view's roto ID. For subclass views should be original base view
#define  SCINIT_ROTOID          "SC0999"


// Define view field index numbers.
#include "SCINITI.GEN"
//#include "SCINIT2I.GEN"


// Define view field sizes.
#include "SCINITS.GEN"
//#include "SCINIT2S.GEN"

// ---

#define	SCINIT_PROCESSCMD_ACTIVATE		0
#define	SCINIT_PROCESSCMD_DEACTIVATE	1


#ifdef __cplusplus
}
#endif


#endif

