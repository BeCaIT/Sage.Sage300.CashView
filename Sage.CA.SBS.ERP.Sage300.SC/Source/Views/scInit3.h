/*---------------------------------------------------------------------------

    File        :   scInit3.h
    Purpose     :   Extra members (data and function) for the view handle

    Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.

---------------------------------------------------------------------------*/


#ifndef __scInit3_h
// Ensures header is only included once.
#define __scInit3_h        1



struct VEXTRA : public VBASE {
   // Add whatever extra members required
	BOOL bActive;
	CHAR sVersion[SIZEOF_VERSION];
	WORD wDataLevel;
	WORD hAppl; // table handle for CSAPP
	LPVOID lpMeter; // Set to NULL for new activation protocol
	PCACTAPPL pActAppl;
};



#endif
