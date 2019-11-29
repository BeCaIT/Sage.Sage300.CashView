/*--------------------------------------------------------------------

    File        :   scAcct.h
    Purpose     :   External definitions for this view.

    Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.

--------------------------------------------------------------------*/



#ifndef __scAcct_h
// Ensures header is only included once.
#define __scAcct_h        1


#ifdef __cplusplus
extern "C" {
#endif


//////////////////////////////////////////////////////////////////////
// Change these definitions as necessary

// +++
#include	"glamf.h"
//#include	"glfisc.h"


// Define the view's roto ID. For subclass views should be original base view
#define  SCACCT_ROTOID          "SC0010"


#define	SCACCT_PROCESSCMD_DEFAULT	0
#define	SCACCT_PROCESSCMD_INCLUDE	1


// Define view field index numbers.
#include "SCACCTI.GEN"
#include "SCACCT2I.GEN"


// Define view field sizes.
#include "SCACCTS.GEN"
#include "SCACCT2S.GEN"

// ---


#ifdef __cplusplus
}
#endif


#endif

