//*************************************************************
//** Name:  CSCBSK.H
//** View:
//** Copyright (c) 1992-2019 Sage Software, Inc.  All rights reserved.
//*************************************************************

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __CSCBSK_H
#define __CSCBSK_H

//View Roto ID
#define CSCBSK_VIEW "CS0050"

//View Field Indices
#define IDX_CSCBSK_SCHEDKEY    1
#define IDX_CSCBSK_SCHEDLINK   2
#define IDX_CSCBSK_OPCODE      3
#define IDX_CSCBSK_MODE        4
#define IDX_CSCBSK_RUNDATE     5
#define IDX_CSCBSK_EXPIRY      6
#define IDX_CSCBSK_ACTIVE      7
#define IDX_CSCBSK_RUNNEXT     8
#define IDX_CSCBSK_RUNPREV     9

//View Field Lengths
#define SIZEOF_CSCBSK_SCHEDKEY    12
#define SIZEOF_CSCBSK_SCHEDLINK   10
#define SIZEOF_CSCBSK_OPCODE      4
#define SIZEOF_CSCBSK_MODE        2
#define SIZEOF_CSCBSK_RUNDATE     5
#define SIZEOF_CSCBSK_EXPIRY      5
#define SIZEOF_CSCBSK_ACTIVE      2
#define SIZEOF_CSCBSK_RUNNEXT     5
#define SIZEOF_CSCBSK_RUNPREV     5

//Macros which commonize referencing fields in the manner GENTABLE does
#define CSCBSK_IDX(__f__)   (IDX_CSCBSK_##__f__)
#define CSCBSK_SIZ(__f__)   (SIZEOF_CSCBSK_##__f__)

#endif

#ifdef __cplusplus
}
#endif
