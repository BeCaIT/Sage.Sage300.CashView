//*************************************************************
//** Name:  GLAMF.H
//** View:  Accounts
//** Copyright (c) 1992-2019 Sage Software, Inc.  All rights reserved.
//*************************************************************

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __GLAMF_H
#define __GLAMF_H

//View Roto ID
#define GLAMF_VIEW "GL0001"

//View Keys
#define GLAMF_KEY1 0
#define GLAMF_KEY2 1
#define GLAMF_KEY3 2
#define GLAMF_KEY4 3
#define GLAMF_KEY5 4
#define GLAMF_KEY6 5
#define GLAMF_KEY7 6
#define GLAMF_KEY8 7
#define GLAMF_KEY9 8
#define GLAMF_KEY10 9
#define GLAMF_KEY11 10
#define GLAMF_KEY12 11
#define GLAMF_KEY13 12
#define GLAMF_KEY14 13

//View Field Indices
#define IDX_GLAMF_ACCTID      1
#define IDX_GLAMF_CREATEDATE  2
#define IDX_GLAMF_ACCTDESC    3
#define IDX_GLAMF_ACCTTYPE    4
#define IDX_GLAMF_ACCTBAL     5
#define IDX_GLAMF_ACTIVESW    6
#define IDX_GLAMF_CONSLDSW    7
#define IDX_GLAMF_QTYSW       8
#define IDX_GLAMF_UOM         9
#define IDX_GLAMF_ALLOCSW     10
#define IDX_GLAMF_ACCTOFSET   11
#define IDX_GLAMF_ACCTSRTY    12
#define IDX_GLAMF_MCSW        13
#define IDX_GLAMF_SPECSW      14
#define IDX_GLAMF_ACCTGRPID   15
#define IDX_GLAMF_CTRLACCTSW  16
#define IDX_GLAMF_SRCELDGID   17
#define IDX_GLAMF_ALLOCTOT    18
#define IDX_GLAMF_ABRKID      19
#define IDX_GLAMF_YRACCTCLOS  20
#define IDX_GLAMF_ACCTFMTTD   21
#define IDX_GLAMF_ACSEGVAL01  22
#define IDX_GLAMF_ACSEGVAL02  23
#define IDX_GLAMF_ACSEGVAL03  24
#define IDX_GLAMF_ACSEGVAL04  25
#define IDX_GLAMF_ACSEGVAL05  26
#define IDX_GLAMF_ACSEGVAL06  27
#define IDX_GLAMF_ACSEGVAL07  28
#define IDX_GLAMF_ACSEGVAL08  29
#define IDX_GLAMF_ACSEGVAL09  30
#define IDX_GLAMF_ACSEGVAL10  31
#define IDX_GLAMF_ACCTSEGVAL  32
#define IDX_GLAMF_ACCTGRPCPY  33
#define IDX_GLAMF_POSTOSEGID  34
#define IDX_GLAMF_DEFCURNCOD  35
#define IDX_GLAMF_CUOM        36
#define IDX_GLAMF_SAMEUOMSW   37
#define IDX_GLAMF_GSSTATUS    38
#define IDX_GLAMF_OVALUES     39
#define IDX_GLAMF_TOVALUES    40
#define IDX_GLAMF_PROCESSCMD  41
#define IDX_GLAMF_ACCTGRPCOD  42
#define IDX_GLAMF_ACCTGRPSCD  43
#define IDX_GLAMF_ROLLUPSW    44
#define IDX_GLAMF_TOPPARSW    45
#define IDX_GLAMF_RFRACCT     46
#define IDX_GLAMF_RTOACCT     47
#define IDX_GLAMF_RFRSEG1     48
#define IDX_GLAMF_RTOSEG1     49
#define IDX_GLAMF_RFRSEG2     50
#define IDX_GLAMF_RTOSEG2     51
#define IDX_GLAMF_RFRSEG3     52
#define IDX_GLAMF_RTOSEG3     53
#define IDX_GLAMF_RFRSEG4     54
#define IDX_GLAMF_RTOSEG4     55
#define IDX_GLAMF_RFRSEG5     56
#define IDX_GLAMF_RTOSEG5     57
#define IDX_GLAMF_RFRSEG6     58
#define IDX_GLAMF_RTOSEG6     59
#define IDX_GLAMF_RFRSEG7     60
#define IDX_GLAMF_RTOSEG7     61
#define IDX_GLAMF_RFRSEG8     62
#define IDX_GLAMF_RTOSEG8     63
#define IDX_GLAMF_RFRSEG9     64
#define IDX_GLAMF_RTOSEG9     65
#define IDX_GLAMF_RFRSEG10    66
#define IDX_GLAMF_RTOSEG10    67
#define IDX_GLAMF_ROPTFLD1    68
#define IDX_GLAMF_ROPTFLD2    69
#define IDX_GLAMF_ROPTFLD3    70
#define IDX_GLAMF_ROPTFRVAL1  71
#define IDX_GLAMF_ROPTTOVAL1  72
#define IDX_GLAMF_ROPTFRVAL2  73
#define IDX_GLAMF_ROPTTOVAL2  74
#define IDX_GLAMF_ROPTFRVAL3  75
#define IDX_GLAMF_ROPTTOVAL3  76
#define IDX_GLAMF_RACCTTYPE   77
#define IDX_GLAMF_RFRGRPID    78
#define IDX_GLAMF_RTOGRPID    79
#define IDX_GLAMF_RQTYSW      80
#define IDX_GLAMF_RCNT        81
#define IDX_GLAMF_ROVERLAP    82

//View Field Lengths
#define SIZEOF_GLAMF_ACCTID      45
#define SIZEOF_GLAMF_CREATEDATE  5
#define SIZEOF_GLAMF_ACCTDESC    60
#define SIZEOF_GLAMF_ACCTTYPE    1
#define SIZEOF_GLAMF_ACCTBAL     1
#define SIZEOF_GLAMF_ACTIVESW    2
#define SIZEOF_GLAMF_CONSLDSW    2
#define SIZEOF_GLAMF_QTYSW       2
#define SIZEOF_GLAMF_UOM         6
#define SIZEOF_GLAMF_ALLOCSW     2
#define SIZEOF_GLAMF_ACCTOFSET   45
#define SIZEOF_GLAMF_ACCTSRTY    2
#define SIZEOF_GLAMF_MCSW        2
#define SIZEOF_GLAMF_SPECSW      2
#define SIZEOF_GLAMF_ACCTGRPID   2
#define SIZEOF_GLAMF_CTRLACCTSW  2
#define SIZEOF_GLAMF_SRCELDGID   2
#define SIZEOF_GLAMF_ALLOCTOT    8
#define SIZEOF_GLAMF_ABRKID      6
#define SIZEOF_GLAMF_YRACCTCLOS  4
#define SIZEOF_GLAMF_ACCTFMTTD   45
#define SIZEOF_GLAMF_ACSEGVAL01  15
#define SIZEOF_GLAMF_ACSEGVAL02  15
#define SIZEOF_GLAMF_ACSEGVAL03  15
#define SIZEOF_GLAMF_ACSEGVAL04  15
#define SIZEOF_GLAMF_ACSEGVAL05  15
#define SIZEOF_GLAMF_ACSEGVAL06  15
#define SIZEOF_GLAMF_ACSEGVAL07  15
#define SIZEOF_GLAMF_ACSEGVAL08  15
#define SIZEOF_GLAMF_ACSEGVAL09  15
#define SIZEOF_GLAMF_ACSEGVAL10  15
#define SIZEOF_GLAMF_ACCTSEGVAL  15
#define SIZEOF_GLAMF_ACCTGRPCPY  4
#define SIZEOF_GLAMF_POSTOSEGID  6
#define SIZEOF_GLAMF_DEFCURNCOD  3
#define SIZEOF_GLAMF_CUOM        6
#define SIZEOF_GLAMF_SAMEUOMSW   2
#define SIZEOF_GLAMF_GSSTATUS    2
#define SIZEOF_GLAMF_OVALUES     4
#define SIZEOF_GLAMF_TOVALUES    4
#define SIZEOF_GLAMF_PROCESSCMD  2
#define SIZEOF_GLAMF_ACCTGRPCOD  12
#define SIZEOF_GLAMF_ACCTGRPSCD  12
#define SIZEOF_GLAMF_ROLLUPSW    2
#define SIZEOF_GLAMF_TOPPARSW    2
#define SIZEOF_GLAMF_RFRACCT     45
#define SIZEOF_GLAMF_RTOACCT     45
#define SIZEOF_GLAMF_RFRSEG1     15
#define SIZEOF_GLAMF_RTOSEG1     15
#define SIZEOF_GLAMF_RFRSEG2     15
#define SIZEOF_GLAMF_RTOSEG2     15
#define SIZEOF_GLAMF_RFRSEG3     15
#define SIZEOF_GLAMF_RTOSEG3     15
#define SIZEOF_GLAMF_RFRSEG4     15
#define SIZEOF_GLAMF_RTOSEG4     15
#define SIZEOF_GLAMF_RFRSEG5     15
#define SIZEOF_GLAMF_RTOSEG5     15
#define SIZEOF_GLAMF_RFRSEG6     15
#define SIZEOF_GLAMF_RTOSEG6     15
#define SIZEOF_GLAMF_RFRSEG7     15
#define SIZEOF_GLAMF_RTOSEG7     15
#define SIZEOF_GLAMF_RFRSEG8     15
#define SIZEOF_GLAMF_RTOSEG8     15
#define SIZEOF_GLAMF_RFRSEG9     15
#define SIZEOF_GLAMF_RTOSEG9     15
#define SIZEOF_GLAMF_RFRSEG10    15
#define SIZEOF_GLAMF_RTOSEG10    15
#define SIZEOF_GLAMF_ROPTFLD1    12
#define SIZEOF_GLAMF_ROPTFLD2    12
#define SIZEOF_GLAMF_ROPTFLD3    12
#define SIZEOF_GLAMF_ROPTFRVAL1  60
#define SIZEOF_GLAMF_ROPTTOVAL1  60
#define SIZEOF_GLAMF_ROPTFRVAL2  60
#define SIZEOF_GLAMF_ROPTTOVAL2  60
#define SIZEOF_GLAMF_ROPTFRVAL3  60
#define SIZEOF_GLAMF_ROPTTOVAL3  60
#define SIZEOF_GLAMF_RACCTTYPE   2
#define SIZEOF_GLAMF_RFRGRPID    12
#define SIZEOF_GLAMF_RTOGRPID    12
#define SIZEOF_GLAMF_RQTYSW      2
#define SIZEOF_GLAMF_RCNT        4
#define SIZEOF_GLAMF_ROVERLAP    2

//Macros which commonize referencing fields in the manner GENTABLE does
#define GLAMF_IDX(__f__)   (IDX_GLAMF_##__f__)
#define GLAMF_SIZ(__f__)   (SIZEOF_GLAMF_##__f__)

#endif

#ifdef __cplusplus
}
#endif
