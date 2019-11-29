/*---------------------------------------------------------------------------

    File        :   scLoan3.h
    Purpose     :   Extra members (data and function) for the view handle

    Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.

---------------------------------------------------------------------------*/


#ifndef __scLoan3_h
// Ensures header is only included once.
#define __scLoan3_h        1



struct VEXTRA : public VBASE {
   // Add whatever extra members required
	WORD wCountry;
	CHAR sUserEmail[SIZEOF_EMAIL + 1];
};



#endif
