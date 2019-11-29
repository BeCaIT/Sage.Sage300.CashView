//*************************************************************
//** Name:  GLACGRP.H
//** View:  Account Groups
//** Copyright (c) 1992-2019 Sage Software, Inc.  All rights reserved.
//*************************************************************

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __GLACGRP_H
#define __GLACGRP_H

//View Roto ID
#define GLACGRP_VIEW "GL0055"

//View Keys
#define GLACGRP_KEY1 0
#define GLACGRP_KEY2 1

//View Field Indices
#define IDX_GLACGRP_ACCTGRPCOD  1
#define IDX_GLACGRP_ACCTGRPDES  2
#define IDX_GLACGRP_SORTCODE    3
#define IDX_GLACGRP_GRPCOD      4

//View Field Lengths
#define SIZEOF_GLACGRP_ACCTGRPCOD  12
#define SIZEOF_GLACGRP_ACCTGRPDES  60
#define SIZEOF_GLACGRP_SORTCODE    12
#define SIZEOF_GLACGRP_GRPCOD      2

//Macros which commonize referencing fields in the manner GENTABLE does
#define GLACGRP_IDX(__f__)   (IDX_GLACGRP_##__f__)
#define GLACGRP_SIZ(__f__)   (SIZEOF_GLACGRP_##__f__)

#endif

#ifdef __cplusplus
}
#endif
