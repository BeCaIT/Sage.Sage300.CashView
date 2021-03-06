//*************************************************************
//** Name:  GLFISC.H
//** View:  Fiscal Sets
//** Copyright (c) 1992-2019 Sage Software, Inc.  All rights reserved.
//*************************************************************

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __GLFISC_H
#define __GLFISC_H

//View Roto ID
#define GLFISC_VIEW "GL0003"

//View Keys
#define GLFISC_KEY1 0
#define GLFISC_KEY2 1

//View Field Indices
#define IDX_GLFISC_ACCTID      1
#define IDX_GLFISC_FSCSYR      2
#define IDX_GLFISC_FSCSDSG     3
#define IDX_GLFISC_FSCSCURN    4
#define IDX_GLFISC_CURNTYPE    5
#define IDX_GLFISC_SWRVL       6
#define IDX_GLFISC_CODERVL     7
#define IDX_GLFISC_SCURNDEC    8
#define IDX_GLFISC_OPENBAL     9
#define IDX_GLFISC_NETPERD1    10
#define IDX_GLFISC_NETPERD2    11
#define IDX_GLFISC_NETPERD3    12
#define IDX_GLFISC_NETPERD4    13
#define IDX_GLFISC_NETPERD5    14
#define IDX_GLFISC_NETPERD6    15
#define IDX_GLFISC_NETPERD7    16
#define IDX_GLFISC_NETPERD8    17
#define IDX_GLFISC_NETPERD9    18
#define IDX_GLFISC_NETPERD10   19
#define IDX_GLFISC_NETPERD11   20
#define IDX_GLFISC_NETPERD12   21
#define IDX_GLFISC_NETPERD13   22
#define IDX_GLFISC_NETPERD14   23
#define IDX_GLFISC_NETPERD15   24
#define IDX_GLFISC_DATECONV    25
#define IDX_GLFISC_SPECURNSW   26
#define IDX_GLFISC_NETCHGSW    27
#define IDX_GLFISC_CONVSW      28
#define IDX_GLFISC_TOTALAMT    29
#define IDX_GLFISC_PERD01BAL   30
#define IDX_GLFISC_PERD02BAL   31
#define IDX_GLFISC_PERD03BAL   32
#define IDX_GLFISC_PERD04BAL   33
#define IDX_GLFISC_PERD05BAL   34
#define IDX_GLFISC_PERD06BAL   35
#define IDX_GLFISC_PERD07BAL   36
#define IDX_GLFISC_PERD08BAL   37
#define IDX_GLFISC_PERD09BAL   38
#define IDX_GLFISC_PERD10BAL   39
#define IDX_GLFISC_PERD11BAL   40
#define IDX_GLFISC_PERD12BAL   41
#define IDX_GLFISC_PERD13BAL   42
#define IDX_GLFISC_PERD14BAL   43
#define IDX_GLFISC_PERD15BAL   44
#define IDX_GLFISC_REPLACESW   45
#define IDX_GLFISC_RATETYPE    46
#define IDX_GLFISC_OVRDRATE    47
#define IDX_GLFISC_ACTIVITYSW  48
#define IDX_GLFISC_ROLLUPSW    49

//View Field Lengths
#define SIZEOF_GLFISC_ACCTID      45
#define SIZEOF_GLFISC_FSCSYR      4
#define SIZEOF_GLFISC_FSCSDSG     1
#define SIZEOF_GLFISC_FSCSCURN    3
#define SIZEOF_GLFISC_CURNTYPE    1
#define SIZEOF_GLFISC_SWRVL       2
#define SIZEOF_GLFISC_CODERVL     6
#define SIZEOF_GLFISC_SCURNDEC    1
#define SIZEOF_GLFISC_OPENBAL     10
#define SIZEOF_GLFISC_NETPERD1    10
#define SIZEOF_GLFISC_NETPERD2    10
#define SIZEOF_GLFISC_NETPERD3    10
#define SIZEOF_GLFISC_NETPERD4    10
#define SIZEOF_GLFISC_NETPERD5    10
#define SIZEOF_GLFISC_NETPERD6    10
#define SIZEOF_GLFISC_NETPERD7    10
#define SIZEOF_GLFISC_NETPERD8    10
#define SIZEOF_GLFISC_NETPERD9    10
#define SIZEOF_GLFISC_NETPERD10   10
#define SIZEOF_GLFISC_NETPERD11   10
#define SIZEOF_GLFISC_NETPERD12   10
#define SIZEOF_GLFISC_NETPERD13   10
#define SIZEOF_GLFISC_NETPERD14   10
#define SIZEOF_GLFISC_NETPERD15   10
#define SIZEOF_GLFISC_DATECONV    5
#define SIZEOF_GLFISC_SPECURNSW   2
#define SIZEOF_GLFISC_NETCHGSW    2
#define SIZEOF_GLFISC_CONVSW      2
#define SIZEOF_GLFISC_TOTALAMT    10
#define SIZEOF_GLFISC_PERD01BAL   10
#define SIZEOF_GLFISC_PERD02BAL   10
#define SIZEOF_GLFISC_PERD03BAL   10
#define SIZEOF_GLFISC_PERD04BAL   10
#define SIZEOF_GLFISC_PERD05BAL   10
#define SIZEOF_GLFISC_PERD06BAL   10
#define SIZEOF_GLFISC_PERD07BAL   10
#define SIZEOF_GLFISC_PERD08BAL   10
#define SIZEOF_GLFISC_PERD09BAL   10
#define SIZEOF_GLFISC_PERD10BAL   10
#define SIZEOF_GLFISC_PERD11BAL   10
#define SIZEOF_GLFISC_PERD12BAL   10
#define SIZEOF_GLFISC_PERD13BAL   10
#define SIZEOF_GLFISC_PERD14BAL   10
#define SIZEOF_GLFISC_PERD15BAL   10
#define SIZEOF_GLFISC_REPLACESW   2
#define SIZEOF_GLFISC_RATETYPE    2
#define SIZEOF_GLFISC_OVRDRATE    8
#define SIZEOF_GLFISC_ACTIVITYSW  2
#define SIZEOF_GLFISC_ROLLUPSW    2

//Macros which commonize referencing fields in the manner GENTABLE does
#define GLFISC_IDX(__f__)   (IDX_GLFISC_##__f__)
#define GLFISC_SIZ(__f__)   (SIZEOF_GLFISC_##__f__)

#endif

#ifdef __cplusplus
}
#endif
