/*--------------------------------------------------------------------

    File        :   scEng.c
    Purpose     :   Entry point for resource only DLL.

    Copyright (c) 1993-2007 Sage Software, Inc.  All rights reserved.

--------------------------------------------------------------------*/

#include <windows.h>

/* Minimum amount of code for a DLL */

int FAR PASCAL LibMain (HANDLE hInstance, WORD wDataSeg,
                        WORD wHeapSize, LPSTR lpszCmdLine)
{
   if (wHeapSize > 0)
      UnlockData (0);

   return 1;
}
