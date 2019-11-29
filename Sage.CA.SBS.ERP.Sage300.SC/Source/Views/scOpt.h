/*--------------------------------------------------------------------

    File        :   scOpt.h
    Purpose     :   External definitions for this view.

    Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.

--------------------------------------------------------------------*/



#ifndef __scOpt_h
// Ensures header is only included once.
#define __scOpt_h        1


#ifdef __cplusplus
extern "C" {
#endif


//////////////////////////////////////////////////////////////////////
// Change these definitions as necessary

// +++

// Define the view's roto ID. For subclass views should be original base view
#define  SCOPT_ROTOID          "SC0001"


// Define view field index numbers.
#include "SCOPTI.GEN"
#include "SCOPT2I.GEN"


// Define view field sizes.
#include "SCOPTS.GEN"
#include "SCOPT2S.GEN"

// ---

//
//// Job Titles
#define	SCOPT_JOBTITLE_0		0
#define	SCOPT_JOBTITLE_1		1
#define	SCOPT_JOBTITLE_2		2
#define	SCOPT_JOBTITLE_3		3
#define	SCOPT_JOBTITLE_4		4
#define	SCOPT_JOBTITLE_5		5
#define	SCOPT_JOBTITLE_15		15

//
//// Countries
#define	SCOPT_COUNTRY_OTHERS			SC_COUNTRY_OTHERS
#define	SCOPT_COUNTRY_SINGAPORE		SC_COUNTRY_SINGAPORE
#define	SCOPT_COUNTRY_MALAYSIA		SC_COUNTRY_MALAYSIA
#define	SCOPT_COUNTRY_HONGKONG		SC_COUNTRY_HONGKONG
#define	SCOPT_COUNTRY_AUSTRALIA		SC_COUNTRY_AUSTRALIA
#define	SCOPT_COUNTRY_NEWZEALAND	SC_COUNTRY_NEWZEALAND

////
////// Country Currencies
//#define	SCOPT_COUNTRY_OTHERS_CURR			"   "
//#define	SCOPT_COUNTRY_SINGAPORE_CURR		"SGD"
//#define	SCOPT_COUNTRY_MALAYSIA_CURR		"MYR"
//#define	SCOPT_COUNTRY_HONGKONG_CURR		"HKD"
//#define	SCOPT_COUNTRY_AUSTRALIA_CURR		"AUD"
//#define	SCOPT_COUNTRY_NEWZEALAND_CURR		"NZD"

//
//// SIC
#define	SCOPT_SIC_NONE		' '

//
//// SIC Singapore
#define	SCOPT_SIC_SG_A		'A'
#define	SCOPT_SIC_SG_B		'B'
#define	SCOPT_SIC_SG_C		'C'
#define	SCOPT_SIC_SG_D		'D'
#define	SCOPT_SIC_SG_E		'E'
#define	SCOPT_SIC_SG_F		'F'
#define	SCOPT_SIC_SG_G		'G'
#define	SCOPT_SIC_SG_H		'H'
#define	SCOPT_SIC_SG_I		'I'
#define	SCOPT_SIC_SG_J		'J'
#define	SCOPT_SIC_SG_K		'K'
#define	SCOPT_SIC_SG_L		'L'
#define	SCOPT_SIC_SG_M		'M'
#define	SCOPT_SIC_SG_N		'N'
#define	SCOPT_SIC_SG_O		'O'
#define	SCOPT_SIC_SG_P		'P'
#define	SCOPT_SIC_SG_Q		'Q'
#define	SCOPT_SIC_SG_R		'R'
#define	SCOPT_SIC_SG_S		'S'
#define	SCOPT_SIC_SG_T		'T'
#define	SCOPT_SIC_SG_U		'U'
#define	SCOPT_SIC_SG_V		'V'

//
//// SIC Malaysia
#define	SCOPT_SIC_MY_A		'A'
#define	SCOPT_SIC_MY_B		'B'
#define	SCOPT_SIC_MY_C		'C'
#define	SCOPT_SIC_MY_D		'D'
#define	SCOPT_SIC_MY_E		'E'
#define	SCOPT_SIC_MY_F		'F'
#define	SCOPT_SIC_MY_G		'G'
#define	SCOPT_SIC_MY_H		'H'
#define	SCOPT_SIC_MY_I		'I'
#define	SCOPT_SIC_MY_J		'J'
#define	SCOPT_SIC_MY_K		'K'

//
//// SIC Hong Kong
#define	SCOPT_SIC_HK_A		'A'
#define	SCOPT_SIC_HK_B		'B'
#define	SCOPT_SIC_HK_C		'C'
#define	SCOPT_SIC_HK_D		'D'
#define	SCOPT_SIC_HK_E		'E'
#define	SCOPT_SIC_HK_F		'F'
#define	SCOPT_SIC_HK_G		'G'
#define	SCOPT_SIC_HK_H		'H'
#define	SCOPT_SIC_HK_I		'I'
#define	SCOPT_SIC_HK_J		'J'
#define	SCOPT_SIC_HK_K		'K'
#define	SCOPT_SIC_HK_L		'L'
#define	SCOPT_SIC_HK_M		'M'
#define	SCOPT_SIC_HK_N		'N'
#define	SCOPT_SIC_HK_O		'O'
#define	SCOPT_SIC_HK_P		'P'
#define	SCOPT_SIC_HK_Q		'Q'
#define	SCOPT_SIC_HK_R		'R'
#define	SCOPT_SIC_HK_S		'S'
#define	SCOPT_SIC_HK_T		'T'
#define	SCOPT_SIC_HK_U		'U'

//
//// SIC Australia
#define	SCOPT_SIC_AU_A		'A'
#define	SCOPT_SIC_AU_B		'B'
#define	SCOPT_SIC_AU_C		'C'
#define	SCOPT_SIC_AU_D		'D'
#define	SCOPT_SIC_AU_E		'E'
#define	SCOPT_SIC_AU_F		'F'
#define	SCOPT_SIC_AU_G		'G'
#define	SCOPT_SIC_AU_H		'H'
#define	SCOPT_SIC_AU_I		'I'
#define	SCOPT_SIC_AU_J		'J'
#define	SCOPT_SIC_AU_K		'K'
#define	SCOPT_SIC_AU_L		'L'
#define	SCOPT_SIC_AU_M		'M'
#define	SCOPT_SIC_AU_N		'N'
#define	SCOPT_SIC_AU_O		'O'
#define	SCOPT_SIC_AU_P		'P'
#define	SCOPT_SIC_AU_Q		'Q'
#define	SCOPT_SIC_AU_R		'R'
#define	SCOPT_SIC_AU_S		'S'

//
//// SIC New Zealand
#define	SCOPT_SIC_NZ_A		'A'
#define	SCOPT_SIC_NZ_B		'B'
#define	SCOPT_SIC_NZ_C		'C'
#define	SCOPT_SIC_NZ_D		'D'
#define	SCOPT_SIC_NZ_E		'E'
#define	SCOPT_SIC_NZ_F		'F'
#define	SCOPT_SIC_NZ_G		'G'
#define	SCOPT_SIC_NZ_H		'H'
#define	SCOPT_SIC_NZ_I		'I'
#define	SCOPT_SIC_NZ_J		'J'
#define	SCOPT_SIC_NZ_K		'K'
#define	SCOPT_SIC_NZ_L		'L'
#define	SCOPT_SIC_NZ_M		'M'
#define	SCOPT_SIC_NZ_N		'N'
#define	SCOPT_SIC_NZ_O		'O'
#define	SCOPT_SIC_NZ_P		'P'
#define	SCOPT_SIC_NZ_Q		'Q'
#define	SCOPT_SIC_NZ_R		'R'
#define	SCOPT_SIC_NZ_S		'S'

//
//// Entity Type
#define	SCOPT_ENTITYTYPE_0		0

//
//// Entity Type - Singapore
#define	SCOPT_ENTITYTYPE_SG_1	1
#define	SCOPT_ENTITYTYPE_SG_2	2
#define	SCOPT_ENTITYTYPE_SG_3	3
#define	SCOPT_ENTITYTYPE_SG_4	4
#define	SCOPT_ENTITYTYPE_SG_5	5

//
//// Entity Type - Malaysia
#define	SCOPT_ENTITYTYPE_MY_1	1
#define	SCOPT_ENTITYTYPE_MY_2	2
#define	SCOPT_ENTITYTYPE_MY_3	3
#define	SCOPT_ENTITYTYPE_MY_4	4
#define	SCOPT_ENTITYTYPE_MY_5	5

//
//// Entity Type - Hong Kong
#define	SCOPT_ENTITYTYPE_HK_1	1
#define	SCOPT_ENTITYTYPE_HK_2	2
#define	SCOPT_ENTITYTYPE_HK_3	3
#define	SCOPT_ENTITYTYPE_HK_4	4
#define	SCOPT_ENTITYTYPE_HK_5	5

//
//// Entity Type - Australia
#define	SCOPT_ENTITYTYPE_AU_1	1
#define	SCOPT_ENTITYTYPE_AU_2	2
#define	SCOPT_ENTITYTYPE_AU_3	3
#define	SCOPT_ENTITYTYPE_AU_4	4
#define	SCOPT_ENTITYTYPE_AU_5	5

//
//// Entity Type - New Zealand
#define	SCOPT_ENTITYTYPE_NZ_1	1
#define	SCOPT_ENTITYTYPE_NZ_2	2
#define	SCOPT_ENTITYTYPE_NZ_3	3
#define	SCOPT_ENTITYTYPE_NZ_4	4
#define	SCOPT_ENTITYTYPE_NZ_5	5


//
//// Document Number
#define	SCOPT_DOCNUM_PREFIX		"FE    "

#ifdef __cplusplus
}
#endif


#endif

