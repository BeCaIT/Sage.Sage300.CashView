//*************************************************************
//** Name:  A4WUSER.H
//** View:  Users
//** Copyright (c) 1992-2019 Sage Software, Inc.  All rights reserved.
//*************************************************************

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __A4WUSER_H
#define __A4WUSER_H

//View Roto ID
#define A4WUSER_VIEW "AS0003"

//View Keys
#define A4WUSER_KEY1 0

//View Field Indices
#define IDX_A4WUSER_USERID      0
#define IDX_A4WUSER_USERNAME    1
#define IDX_A4WUSER_PASSWORD    2
#define IDX_A4WUSER_ACCTTYPE    3
#define IDX_A4WUSER_ACCTSTATUS  4
#define IDX_A4WUSER_LANGUAGE    5
#define IDX_A4WUSER_LANGLIST    6
#define IDX_A4WUSER_CHNGEPASS   7
#define IDX_A4WUSER_NOCHNGPASS  8
#define IDX_A4WUSER_PASSNOEXP   9
#define IDX_A4WUSER_DISABLED    10
#define IDX_A4WUSER_LOCKEDOUT   11
#define IDX_A4WUSER_RESTRICTED  12
#define IDX_A4WUSER_OKMONDAY    13
#define IDX_A4WUSER_OKTUESDAY   14
#define IDX_A4WUSER_OKWEDNESDY  15
#define IDX_A4WUSER_OKTHURSDAY  16
#define IDX_A4WUSER_OKFRIDAY    17
#define IDX_A4WUSER_OKSATURDAY  18
#define IDX_A4WUSER_OKSUNDAY    19
#define IDX_A4WUSER_TIMEBEGIN   20
#define IDX_A4WUSER_TIMEEND     21
#define IDX_A4WUSER_AUTHMETH    22
#define IDX_A4WUSER_WINDOMAIN   23
#define IDX_A4WUSER_WINUSER     24
#define IDX_A4WUSER_PHONE       25
#define IDX_A4WUSER_EMAIL1      26
#define IDX_A4WUSER_EMAIL2      27
#define IDX_A4WUSER_ROLE        28
#define IDX_A4WUSER_OPTIN       29

//View Field Lengths
#define SIZEOF_A4WUSER_USERID      8
#define SIZEOF_A4WUSER_USERNAME    60
#define SIZEOF_A4WUSER_PASSWORD    64
#define SIZEOF_A4WUSER_ACCTTYPE    2
#define SIZEOF_A4WUSER_ACCTSTATUS  2
#define SIZEOF_A4WUSER_LANGUAGE    3
#define SIZEOF_A4WUSER_LANGLIST    2
#define SIZEOF_A4WUSER_CHNGEPASS   4
#define SIZEOF_A4WUSER_NOCHNGPASS  4
#define SIZEOF_A4WUSER_PASSNOEXP   4
#define SIZEOF_A4WUSER_DISABLED    4
#define SIZEOF_A4WUSER_LOCKEDOUT   4
#define SIZEOF_A4WUSER_RESTRICTED  4
#define SIZEOF_A4WUSER_OKMONDAY    4
#define SIZEOF_A4WUSER_OKTUESDAY   4
#define SIZEOF_A4WUSER_OKWEDNESDY  4
#define SIZEOF_A4WUSER_OKTHURSDAY  4
#define SIZEOF_A4WUSER_OKFRIDAY    4
#define SIZEOF_A4WUSER_OKSATURDAY  4
#define SIZEOF_A4WUSER_OKSUNDAY    4
#define SIZEOF_A4WUSER_TIMEBEGIN   5
#define SIZEOF_A4WUSER_TIMEEND     5
#define SIZEOF_A4WUSER_AUTHMETH    2
#define SIZEOF_A4WUSER_WINDOMAIN   15
#define SIZEOF_A4WUSER_WINUSER     256
#define SIZEOF_A4WUSER_PHONE       30
#define SIZEOF_A4WUSER_EMAIL1      50
#define SIZEOF_A4WUSER_EMAIL2      50
#define SIZEOF_A4WUSER_ROLE        2
#define SIZEOF_A4WUSER_OPTIN       4

//Macros which commonize referencing fields in the manner GENTABLE does
#define A4WUSER_IDX(__f__)   (IDX_A4WUSER_##__f__)
#define A4WUSER_SIZ(__f__)   (SIZEOF_A4WUSER_##__f__)

#endif

#ifdef __cplusplus
}
#endif
