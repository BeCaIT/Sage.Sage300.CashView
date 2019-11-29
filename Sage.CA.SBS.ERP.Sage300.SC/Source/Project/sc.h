/*--------------------------------------------------------------------

    File        :   sc.h
    Purpose     :   Shared application-wide definitions

    Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.

--------------------------------------------------------------------*/


#ifndef __sc_h
// Ensures header is only included once.
#define __sc_h        1


#ifdef __cplusplus
extern "C" {
#endif


//////////////////////////////////////////////////////////////////////
// Add shared definitions as necessary

//
//// Field Sizes
#define	SC_SIZEOF_CUSTVEND	12
#define	SC_SIZEOF_DOCNUM		22
#define	SC_SIZEOF_DOCNUMNBR	5
#define	SC_SIZEOF_PAYMENTNBR	3
#define	SC_SIZEOF_DOCPREFIX	6

#define	SC_EMAIL_MAX_SIZE		900000

//
//// Yes No
#define	SC_NO						0
#define	SC_YES					1

//
//// Record Types
#define	SC_RECTYPE_NORMAL		0
#define	SC_RECTYPE_PENDING	1

//
//// Security Resources
#define	SC_RSC_SCSETUP		"SCSETUP"
#define	SC_RSC_SCINQUIRY	"SCINQUIRY"
#define	SC_RSC_SCPROCESS	"SCPROCESS"
#define	SC_RSC_SCFCENTRY	"SCFCENTRY"
#define	SC_RSC_SCLINQUIRY	"SCLINQUIRY"
#define	SC_RSC_SCLENTRY	"SCLENTRY"




//
//// Error Codes
#define	SC_ERROR_OPTIONS_NOT_SET	ERRNUM_APPLICATION_DEFINE(0);

//////////////////////////////////////////////////////////////////////
// Supported Countries Definitions

//
//// Country Code
#define SC_COUNTRY_OTHERS					0
#define SC_COUNTRY_SINGAPORE				702
#define SC_COUNTRY_MALAYSIA				458
#define SC_COUNTRY_HONGKONG				344
#define SC_COUNTRY_AUSTRALIA				36
#define SC_COUNTRY_NEWZEALAND				554

#define SC_COUNTRY_CURR_OTHERS			"   "
#define SC_COUNTRY_CURR_SINGAPORE		"SGD"
#define SC_COUNTRY_CURR_MALAYSIA			"MYR"
#define SC_COUNTRY_CURR_HONGKONG			"HKR"
#define SC_COUNTRY_CURR_AUSTRALIA		"AUD"
#define SC_COUNTRY_CURR_NEWZEALAND		"NZD"

#define SC_COUNTRY_EMAIL_OTHERS			""
#define SC_COUNTRY_EMAIL_SINGAPORE		"Standard Chartered <sage.sgbizbanking@sc.com>"
#define SC_COUNTRY_EMAIL_MALAYSIA		"Standard Chartered <scbmy-sage@sc.com>"
#define SC_COUNTRY_EMAIL_HONGKONG		""
#define SC_COUNTRY_EMAIL_AUSTRALIA		""
#define SC_COUNTRY_EMAIL_NEWZEALAND		""

#define SC_COUNTRY_LCAP_OTHERS			"0"
#define SC_COUNTRY_LCAP_SINGAPORE		"300000.00"
#define SC_COUNTRY_LCAP_MALAYSIA			"1500000.00"
#define SC_COUNTRY_LCAP_HONGKONG			"0"
#define SC_COUNTRY_LCAP_AUSTRALIA		"0"
#define SC_COUNTRY_LCAP_NEWZEALAND		"0"

//
//////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif


#endif
