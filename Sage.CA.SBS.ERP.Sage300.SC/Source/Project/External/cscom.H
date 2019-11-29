//*************************************************************
//** Name:  CSCOM.H
//** View:  Company Profile
//** Copyright (c) 1992-2019 Sage Software, Inc.  All rights reserved.
//*************************************************************

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __CSCOM_H
#define __CSCOM_H

//View Roto ID
#define CSCOM_VIEW "CS0001"

//View Keys
#define CSCOM_KEY1 0

//View Field Indices
#define IDX_CSCOM_ORGID       1
#define IDX_CSCOM_CONAME      2
#define IDX_CSCOM_ADDR01      3
#define IDX_CSCOM_ADDR02      4
#define IDX_CSCOM_ADDR03      5
#define IDX_CSCOM_ADDR04      6
#define IDX_CSCOM_CITY        7
#define IDX_CSCOM_STATE       8
#define IDX_CSCOM_POSTAL      9
#define IDX_CSCOM_COUNTRY     10
#define IDX_CSCOM_LOCTYPE     11
#define IDX_CSCOM_LOCCODE     12
#define IDX_CSCOM_PHONEFMT    13
#define IDX_CSCOM_PHONE       14
#define IDX_CSCOM_FAX         15
#define IDX_CSCOM_CONTACT     16
#define IDX_CSCOM_CNTRYCODE   17
#define IDX_CSCOM_BRANCH      18
#define IDX_CSCOM_PERDFSC     19
#define IDX_CSCOM_QTR4PERD    20
#define IDX_CSCOM_HOMECUR     21
#define IDX_CSCOM_MULTICURSW  22
#define IDX_CSCOM_RATETYPE    23
#define IDX_CSCOM_WARNDAYS    24
#define IDX_CSCOM_EUROCURSW   50
#define IDX_CSCOM_REPORTCUR   51
#define IDX_CSCOM_HNDLCKFSC   52
#define IDX_CSCOM_HNDINAACCT  53
#define IDX_CSCOM_HNDNEXACCT  54
#define IDX_CSCOM_GNLSSMTHD   55
#define IDX_CSCOM_TAXNBR      56
#define IDX_CSCOM_LEGALNAME   57
#define IDX_CSCOM_BRN         58

//View Field Lengths
#define SIZEOF_CSCOM_ORGID       6
#define SIZEOF_CSCOM_CONAME      60
#define SIZEOF_CSCOM_ADDR01      60
#define SIZEOF_CSCOM_ADDR02      60
#define SIZEOF_CSCOM_ADDR03      60
#define SIZEOF_CSCOM_ADDR04      60
#define SIZEOF_CSCOM_CITY        30
#define SIZEOF_CSCOM_STATE       30
#define SIZEOF_CSCOM_POSTAL      20
#define SIZEOF_CSCOM_COUNTRY     30
#define SIZEOF_CSCOM_LOCTYPE     6
#define SIZEOF_CSCOM_LOCCODE     30
#define SIZEOF_CSCOM_PHONEFMT    2
#define SIZEOF_CSCOM_PHONE       30
#define SIZEOF_CSCOM_FAX         30
#define SIZEOF_CSCOM_CONTACT     60
#define SIZEOF_CSCOM_CNTRYCODE   6
#define SIZEOF_CSCOM_BRANCH      6
#define SIZEOF_CSCOM_PERDFSC     2
#define SIZEOF_CSCOM_QTR4PERD    2
#define SIZEOF_CSCOM_HOMECUR     3
#define SIZEOF_CSCOM_MULTICURSW  2
#define SIZEOF_CSCOM_RATETYPE    2
#define SIZEOF_CSCOM_WARNDAYS    2
#define SIZEOF_CSCOM_EUROCURSW   2
#define SIZEOF_CSCOM_REPORTCUR   3
#define SIZEOF_CSCOM_HNDLCKFSC   2
#define SIZEOF_CSCOM_HNDINAACCT  2
#define SIZEOF_CSCOM_HNDNEXACCT  2
#define SIZEOF_CSCOM_GNLSSMTHD   2
#define SIZEOF_CSCOM_TAXNBR      20
#define SIZEOF_CSCOM_LEGALNAME   60
#define SIZEOF_CSCOM_BRN         30

//Macros which commonize referencing fields in the manner GENTABLE does
#define CSCOM_IDX(__f__)   (IDX_CSCOM_##__f__)
#define CSCOM_SIZ(__f__)   (SIZEOF_CSCOM_##__f__)

#endif

#ifdef __cplusplus
}
#endif
