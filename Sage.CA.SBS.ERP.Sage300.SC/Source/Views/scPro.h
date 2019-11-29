/*--------------------------------------------------------------------

    File        :   scPro.h
    Purpose     :   External definitions for this view.

    Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.

--------------------------------------------------------------------*/



#ifndef __scPro_h
// Ensures header is only included once.
#define __scPro_h        1


#ifdef __cplusplus
extern "C" {
#endif


//////////////////////////////////////////////////////////////////////
// Change these definitions as necessary

// +++

// Define the view's roto ID. For subclass views should be original base view
#define  SCPRO_ROTOID          "SC0800"


// Define view field index numbers.
#include "SCPROI.GEN"
//#include "SCPRO2I.GEN"


// Define view field sizes.
#include "SCPROS.GEN"
//#include "SCPRO2S.GEN"

// ---
#define	SCPRO_PROCESSCMD_NORMAL		0
#define	SCPRO_PROCESSCMD_FORCE		1

#define	SCPRO_EMAIL_MAX_MESSAGE		1048576 // in bytes ~= 1MB


#ifdef __cplusplus
}
#endif


#endif