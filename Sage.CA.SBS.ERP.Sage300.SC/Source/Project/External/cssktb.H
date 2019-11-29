//*************************************************************
//** Name:  CSSKTB.H
//** View:  Schedules
//** Copyright (c) 1992-2019 Sage Software, Inc.  All rights reserved.
//*************************************************************

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __CSSKTB_H
#define __CSSKTB_H

//View Roto ID
#define CSSKTB_VIEW "CS0030"

//View Keys
#define CSSKTB_KEY1 0

//View Field Indices
#define IDX_CSSKTB_SCHEDKEY    1
#define IDX_CSSKTB_SCHEDDESC   2
#define IDX_CSSKTB_INTERVAL    3
#define IDX_CSSKTB_FREQUENCY   4
#define IDX_CSSKTB_PHASE       5
#define IDX_CSSKTB_WEEKDAY     6
#define IDX_CSSKTB_MONTHDAY    7
#define IDX_CSSKTB_WEEK        8
#define IDX_CSSKTB_MONTH       9
#define IDX_CSSKTB_WDFSUN      10
#define IDX_CSSKTB_WDFMON      11
#define IDX_CSSKTB_WDFTUE      12
#define IDX_CSSKTB_WDFWED      13
#define IDX_CSSKTB_WDFTHU      14
#define IDX_CSSKTB_WDFFRI      15
#define IDX_CSSKTB_WDFSAT      16
#define IDX_CSSKTB_LASTDATE    17
#define IDX_CSSKTB_ACTIVEDATE  18
#define IDX_CSSKTB_REMINDLEAD  19
#define IDX_CSSKTB_USERMODE    20
#define IDX_CSSKTB_USERID      21
#define IDX_CSSKTB_RUNCURRENT  101
#define IDX_CSSKTB_RUNNEXT     102
#define IDX_CSSKTB_RUNSTART    103
#define IDX_CSSKTB_INVOKEDATE  106
#define IDX_CSSKTB_SUGGESTDAT  107
#define IDX_CSSKTB_USERNAME    111
#define IDX_CSSKTB_ISDUE       112
#define IDX_CSSKTB_ISRUN       114
#define IDX_CSSKTB_FILTRATION  115
#define IDX_CSSKTB_FILTERDATE  116
#define IDX_CSSKTB_FILTER      117
#define IDX_CSSKTB_REMIND      118
#define IDX_CSSKTB_OPERATION   121

//View Field Lengths
#define SIZEOF_CSSKTB_SCHEDKEY    12
#define SIZEOF_CSSKTB_SCHEDDESC   60
#define SIZEOF_CSSKTB_INTERVAL    2
#define SIZEOF_CSSKTB_FREQUENCY   2
#define SIZEOF_CSSKTB_PHASE       2
#define SIZEOF_CSSKTB_WEEKDAY     2
#define SIZEOF_CSSKTB_MONTHDAY    2
#define SIZEOF_CSSKTB_WEEK        2
#define SIZEOF_CSSKTB_MONTH       2
#define SIZEOF_CSSKTB_WDFSUN      2
#define SIZEOF_CSSKTB_WDFMON      2
#define SIZEOF_CSSKTB_WDFTUE      2
#define SIZEOF_CSSKTB_WDFWED      2
#define SIZEOF_CSSKTB_WDFTHU      2
#define SIZEOF_CSSKTB_WDFFRI      2
#define SIZEOF_CSSKTB_WDFSAT      2
#define SIZEOF_CSSKTB_LASTDATE    5
#define SIZEOF_CSSKTB_ACTIVEDATE  5
#define SIZEOF_CSSKTB_REMINDLEAD  2
#define SIZEOF_CSSKTB_USERMODE    2
#define SIZEOF_CSSKTB_USERID      8
#define SIZEOF_CSSKTB_RUNCURRENT  5
#define SIZEOF_CSSKTB_RUNNEXT     5
#define SIZEOF_CSSKTB_RUNSTART    5
#define SIZEOF_CSSKTB_INVOKEDATE  5
#define SIZEOF_CSSKTB_SUGGESTDAT  5
#define SIZEOF_CSSKTB_USERNAME    60
#define SIZEOF_CSSKTB_ISDUE       2
#define SIZEOF_CSSKTB_ISRUN       2
#define SIZEOF_CSSKTB_FILTRATION  2
#define SIZEOF_CSSKTB_FILTERDATE  5
#define SIZEOF_CSSKTB_FILTER      200
#define SIZEOF_CSSKTB_REMIND      60
#define SIZEOF_CSSKTB_OPERATION   2

//Macros which commonize referencing fields in the manner GENTABLE does
#define CSSKTB_IDX(__f__)   (IDX_CSSKTB_##__f__)
#define CSSKTB_SIZ(__f__)   (SIZEOF_CSSKTB_##__f__)

#endif

#ifdef __cplusplus
}
#endif
