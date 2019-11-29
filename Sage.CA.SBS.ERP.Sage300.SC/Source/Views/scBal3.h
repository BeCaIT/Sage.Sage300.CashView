/*---------------------------------------------------------------------------

    File        :   scBal3.h
    Purpose     :   Extra members (data and function) for the view handle

    Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.

---------------------------------------------------------------------------*/


#ifndef __scBal3_h
// Ensures header is only included once.
#define __scBal3_h        1



struct VEXTRA : public VBASE {
   // Add whatever extra members required
	CHAR curYear[SIZEOF_YEAR];
	WORD curPeriod;
};



#endif
