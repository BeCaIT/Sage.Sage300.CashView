/*---------------------------------------------------------------------------

    File        :   scTran3.h
    Purpose     :   Extra members (data and function) for the view handle

    Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.

---------------------------------------------------------------------------*/


#ifndef __scTran3_h
// Ensures header is only included once.
#define __scTran3_h        1



struct VEXTRA : public VBASE {
   // Add whatever extra members required
	WORD	fcPeriod1E;
	WORD	fcPeriod2E;
	WORD	fcPeriod3E;
	WORD	fcPeriod4E;
	WORD	fcPeriod5E;
	CHAR	sDocNumDef[SC_SIZEOF_DOCNUM];
};



#endif
