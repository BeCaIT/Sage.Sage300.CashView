/*--------------------------------------------------------------------

    File        :   scOpt1.c
    Purpose     :   Supporting routines for view functions with code
                    specific to this view.

    Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.

--------------------------------------------------------------------*/

/////////////////////////////////////////////////////////////////////////////
// The following files are suitable candidates for precompiled headers

#include <plusapi.h>

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include <rotoview.h>
#include <roto.h>

#include <repcmd.h>

#include "scEmail.h"
#include "scUtil.h"

#if defined(__cplusplus)
namespace A4WAPI {
#endif

#include "sc.h"
#include "sc.i"

/////////////////////////////////////////////////////////////////////////////


#include "scOpt.h"
#include "scOpt.i"
#include "scOpt1.h"
#include "scOpt2.h"

//////////////////////////////////////////////////////////////////////
// +++

// #include "composite .H file(s)"
#include "cscom.h"



#if BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT>0

// Database table definition -- used by dbOpenTable and dbCreateTable.
// All views must have at least one. Subclass views do not need to
// specify the wFlags or wFirstAuditField members. Views with calculated
// fields should define a separate DBTABLE used to buffer those values;
// only the wRecordLength and wNoOfFields members are then used. Views with
// multiple tables must define one complete DBTABLE for each physical table.
// This structure is passed directly to dbCreateTable.
DBTABLE dbtableDef = {
   {'S','C','O','P','T',' ',' ',' '},
   sizeof (RECORD),
   SCOPT_FLD_COUNT,
   SCOPT_KEY_COUNT,
   FLG_MP_RECORD,
   SCOPT_FLD_AUDIT
};

DBTABLE dbtable2Def = {
	{' ',' ',' ',' ',' ',' ',' ',' '},
   sizeof (RECORD2),
   SCOPT2_FLD_COUNT,
   0,
   0,
   0
};

#endif



#if SCOPT_FLD_COUNT>0

// Database table field definitions. Modify and add fields as required.
// Note that there must be a primary key and audit stamp fields. Exceptions
// to this are for calculated field tables and subclass view tables.
// There must be one DBFIELD array for each DBTABLE structure defined above.
// This structure is passed directly to dbCreateTable.
DBFIELD dbfieldDefs [SCOPT_FLD_COUNT] = {
#include "SCOPTF.GEN"
};

DBFIELD dbfield2Defs [SCOPT2_FLD_COUNT] = {
#include "SCOPT2F.GEN"
};

#endif



#if SCOPT_KEY_COUNT>0

// Database table key definitions. This is a variable-length array of WORDs.
// The format consists of a sequence of key definitions, where each key
// definition has three parts: 1) flags, 2) number of segments,
// 3) variable-length list of database field numbers comprising key.
// For each physical database table needed, a ****KeyDef must be defined.
// This structure is passed directly to dbCreateTable.
WORD SCOPTKeyDef [] = {
   0, // flags - no special attributes
   1, // one segments
   SCOPT_FLD_DUMMY, // field number (0-origin)
};

//WORD SCOPT2KeyDef [] = {
//   0, // flags - no special attributes
//   1, // one segments
//   SCOPT2_FLD_yourkey, // field number (0-origin)
//};

#endif



#if BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT>0

// List of database table definitions. This array is indexed by the tblNo
// member of the fldIdxMap structure in order to determine a view field's
// table, field and key structure. The prior three structures are
// aggregated into each entry below.
extern TBLMAP tables [BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT] = {
   // DBTABLE     DBFIELD       LPWORD
   {&dbtableDef,  dbfieldDefs,  SCOPTKeyDef}, // make one entry for each table
	{&dbtable2Def, dbfield2Defs, NULL      }, // make one entry for each table
};

#endif



#if KEY_COUNT>0

// View key definitions. Used to map from key number to corresponding view
// field information.
extern KEYMAP keyNumMap [KEY_COUNT] = {
   // name rsc ID     segs  array of view field indexes
   {IDS_SCOPT_KEY_NAME, 1,   {SCOPT_IDX(DUMMY)}}, // make one entry for each key
};

#endif



#if HCHY_CMP_COUNT+DMND_CMP_COUNT+IMP_CMP_COUNT>0

// This array defines the view field indexes in this view which are
// foreign keys to composed views. Note that neither header nor detail
// composites are included. It maps from (mostly non-key) fields in this
// view to key fields in the composites. If this view has N instances
// of a composed view key, the count field (normally 0) can be set
// to N-1 to indicate this, and the next N-1 lines filled with
// the appropriate additional definitions.
extern KEYMAP hierarchyKeyMap [] = {
   // count  segs  array of view field indexes
   {0,       1,    {SCOPT_IDX(yourkey)}}
};

#endif



#if FLD_IDX_COUNT>0

// Mapping from a view field number to a view field index.
// The ordering of this array is not important. Note that field number 0
// is actually at index 0 in this array.
extern LONG fldNumToIdx [FLD_IDX_COUNT] = {
#include "SCOPTX.GEN"
#include "SCOPT2X.GEN"
};

#endif



// Presentation info: For each field having presentation information
// create a set of initialized structures which will be referenced
// in fldIdxMap.
//
//// Job Title List
DECLARE_LIST_NUMS(JobTitle) {
	SCOPT_JOBTITLE_0,
	SCOPT_JOBTITLE_1,
	SCOPT_JOBTITLE_2,
	SCOPT_JOBTITLE_3,
	SCOPT_JOBTITLE_4,
	SCOPT_JOBTITLE_5,
	SCOPT_JOBTITLE_15,
};
DECLARE_LIST_STRS(JobTitle) {
	IDS_SCOPT_JOBTITLE_0,
	IDS_SCOPT_JOBTITLE_1,
	IDS_SCOPT_JOBTITLE_2,
	IDS_SCOPT_JOBTITLE_3,
	IDS_SCOPT_JOBTITLE_4,
	IDS_SCOPT_JOBTITLE_5,
	IDS_SCOPT_JOBTITLE_15,
};
DECLARE_LIST(JobTitle);

//
//// Country List
DECLARE_LIST_NUMS(Country) {
	SCOPT_COUNTRY_OTHERS,
	SCOPT_COUNTRY_SINGAPORE,
	SCOPT_COUNTRY_MALAYSIA,
//	SCOPT_COUNTRY_HONGKONG,
//	SCOPT_COUNTRY_AUSTRALIA,
//	SCOPT_COUNTRY_NEWZEALAND
};
DECLARE_LIST_STRS(Country) {
	IDS_SCOPT_COUNTRY_OTHERS,
	IDS_SCOPT_COUNTRY_SINGAPORE,
	IDS_SCOPT_COUNTRY_MALAYSIA,
//	IDS_SCOPT_COUNTRY_HONGKONG,
//	IDS_SCOPT_COUNTRY_AUSTRALIA,
//	IDS_SCOPT_COUNTRY_NEWZEALAND
};
DECLARE_LIST(Country);

//
//// Industry List
DECLARE_LIST_NUMS(Industry) {
	SCOPT_SIC_NONE,
};
DECLARE_LIST_STRS(Industry) {
	IDS_SCOPT_SIC_NONE,
};
DECLARE_LIST(Industry);

//
//// Industry Singapore List
DECLARE_LIST_NUMS(IndustrySG) {
	SCOPT_SIC_NONE,
	SCOPT_SIC_SG_A,
	SCOPT_SIC_SG_B,
	SCOPT_SIC_SG_C,
	SCOPT_SIC_SG_D,
	SCOPT_SIC_SG_E,
	SCOPT_SIC_SG_F,
	SCOPT_SIC_SG_G,
	SCOPT_SIC_SG_H,
	SCOPT_SIC_SG_I,
	SCOPT_SIC_SG_J,
	SCOPT_SIC_SG_K,
	SCOPT_SIC_SG_L,
	SCOPT_SIC_SG_M,
	SCOPT_SIC_SG_N,
	SCOPT_SIC_SG_O,
	SCOPT_SIC_SG_P,
	SCOPT_SIC_SG_Q,
	SCOPT_SIC_SG_R,
	SCOPT_SIC_SG_S,
	SCOPT_SIC_SG_T,
	SCOPT_SIC_SG_U,
	SCOPT_SIC_SG_V,
};
DECLARE_LIST_STRS(IndustrySG) {
	IDS_SCOPT_SIC_NONE,
	IDS_SCOPT_SIC_SG_A,
	IDS_SCOPT_SIC_SG_B,
	IDS_SCOPT_SIC_SG_C,
	IDS_SCOPT_SIC_SG_D,
	IDS_SCOPT_SIC_SG_E,
	IDS_SCOPT_SIC_SG_F,
	IDS_SCOPT_SIC_SG_G,
	IDS_SCOPT_SIC_SG_H,
	IDS_SCOPT_SIC_SG_I,
	IDS_SCOPT_SIC_SG_J,
	IDS_SCOPT_SIC_SG_K,
	IDS_SCOPT_SIC_SG_L,
	IDS_SCOPT_SIC_SG_M,
	IDS_SCOPT_SIC_SG_N,
	IDS_SCOPT_SIC_SG_O,
	IDS_SCOPT_SIC_SG_P,
	IDS_SCOPT_SIC_SG_Q,
	IDS_SCOPT_SIC_SG_R,
	IDS_SCOPT_SIC_SG_S,
	IDS_SCOPT_SIC_SG_T,
	IDS_SCOPT_SIC_SG_U,
	IDS_SCOPT_SIC_SG_V,
};
DECLARE_LIST(IndustrySG);

//
//// Industry Malaysia List
DECLARE_LIST_NUMS(IndustryMY) {
	SCOPT_SIC_NONE,
	SCOPT_SIC_MY_A,
	SCOPT_SIC_MY_B,
	SCOPT_SIC_MY_C,
	SCOPT_SIC_MY_D,
	SCOPT_SIC_MY_E,
	SCOPT_SIC_MY_F,
	SCOPT_SIC_MY_G,
	SCOPT_SIC_MY_H,
	SCOPT_SIC_MY_I,
	SCOPT_SIC_MY_J,
	SCOPT_SIC_MY_K,
};
DECLARE_LIST_STRS(IndustryMY) {
	IDS_SCOPT_SIC_NONE,
	IDS_SCOPT_SIC_MY_A,
	IDS_SCOPT_SIC_MY_B,
	IDS_SCOPT_SIC_MY_C,
	IDS_SCOPT_SIC_MY_D,
	IDS_SCOPT_SIC_MY_E,
	IDS_SCOPT_SIC_MY_F,
	IDS_SCOPT_SIC_MY_G,
	IDS_SCOPT_SIC_MY_H,
	IDS_SCOPT_SIC_MY_I,
	IDS_SCOPT_SIC_MY_J,
	IDS_SCOPT_SIC_MY_K,
};
DECLARE_LIST(IndustryMY);

//
//// Industry Hong Kong List
DECLARE_LIST_NUMS(IndustryHK) {
	SCOPT_SIC_NONE,
	SCOPT_SIC_HK_A,
	SCOPT_SIC_HK_B,
	SCOPT_SIC_HK_C,
	SCOPT_SIC_HK_D,
	SCOPT_SIC_HK_E,
	SCOPT_SIC_HK_F,
	SCOPT_SIC_HK_G,
	SCOPT_SIC_HK_H,
	SCOPT_SIC_HK_I,
	SCOPT_SIC_HK_J,
	SCOPT_SIC_HK_K,
	SCOPT_SIC_HK_L,
	SCOPT_SIC_HK_M,
	SCOPT_SIC_HK_N,
	SCOPT_SIC_HK_O,
	SCOPT_SIC_HK_P,
	SCOPT_SIC_HK_Q,
	SCOPT_SIC_HK_R,
	SCOPT_SIC_HK_S,
	SCOPT_SIC_HK_T,
	SCOPT_SIC_HK_U,
};
DECLARE_LIST_STRS(IndustryHK) {
	IDS_SCOPT_SIC_NONE,
	IDS_SCOPT_SIC_HK_A,
	IDS_SCOPT_SIC_HK_B,
	IDS_SCOPT_SIC_HK_C,
	IDS_SCOPT_SIC_HK_D,
	IDS_SCOPT_SIC_HK_E,
	IDS_SCOPT_SIC_HK_F,
	IDS_SCOPT_SIC_HK_G,
	IDS_SCOPT_SIC_HK_H,
	IDS_SCOPT_SIC_HK_I,
	IDS_SCOPT_SIC_HK_J,
	IDS_SCOPT_SIC_HK_K,
	IDS_SCOPT_SIC_HK_L,
	IDS_SCOPT_SIC_HK_M,
	IDS_SCOPT_SIC_HK_N,
	IDS_SCOPT_SIC_HK_O,
	IDS_SCOPT_SIC_HK_P,
	IDS_SCOPT_SIC_HK_Q,
	IDS_SCOPT_SIC_HK_R,
	IDS_SCOPT_SIC_HK_S,
	IDS_SCOPT_SIC_HK_T,
	IDS_SCOPT_SIC_HK_U,
};
DECLARE_LIST(IndustryHK);

//
//// Industry Australia List
DECLARE_LIST_NUMS(IndustryAU) {
	SCOPT_SIC_NONE,
	SCOPT_SIC_AU_A,
	SCOPT_SIC_AU_B,
	SCOPT_SIC_AU_C,
	SCOPT_SIC_AU_D,
	SCOPT_SIC_AU_E,
	SCOPT_SIC_AU_F,
	SCOPT_SIC_AU_G,
	SCOPT_SIC_AU_H,
	SCOPT_SIC_AU_I,
	SCOPT_SIC_AU_J,
	SCOPT_SIC_AU_K,
	SCOPT_SIC_AU_L,
	SCOPT_SIC_AU_M,
	SCOPT_SIC_AU_N,
	SCOPT_SIC_AU_O,
	SCOPT_SIC_AU_P,
	SCOPT_SIC_AU_Q,
	SCOPT_SIC_AU_R,
	SCOPT_SIC_AU_S,
};
DECLARE_LIST_STRS(IndustryAU) {
	IDS_SCOPT_SIC_NONE,
	IDS_SCOPT_SIC_AU_A,
	IDS_SCOPT_SIC_AU_B,
	IDS_SCOPT_SIC_AU_C,
	IDS_SCOPT_SIC_AU_D,
	IDS_SCOPT_SIC_AU_E,
	IDS_SCOPT_SIC_AU_F,
	IDS_SCOPT_SIC_AU_G,
	IDS_SCOPT_SIC_AU_H,
	IDS_SCOPT_SIC_AU_I,
	IDS_SCOPT_SIC_AU_J,
	IDS_SCOPT_SIC_AU_K,
	IDS_SCOPT_SIC_AU_L,
	IDS_SCOPT_SIC_AU_M,
	IDS_SCOPT_SIC_AU_N,
	IDS_SCOPT_SIC_AU_O,
	IDS_SCOPT_SIC_AU_P,
	IDS_SCOPT_SIC_AU_Q,
	IDS_SCOPT_SIC_AU_R,
	IDS_SCOPT_SIC_AU_S,
};
DECLARE_LIST(IndustryAU);

//
//// Industry New Zealand List
DECLARE_LIST_NUMS(IndustryNZ) {
	SCOPT_SIC_NONE,
	SCOPT_SIC_NZ_A,
	SCOPT_SIC_NZ_B,
	SCOPT_SIC_NZ_C,
	SCOPT_SIC_NZ_D,
	SCOPT_SIC_NZ_E,
	SCOPT_SIC_NZ_F,
	SCOPT_SIC_NZ_G,
	SCOPT_SIC_NZ_H,
	SCOPT_SIC_NZ_I,
	SCOPT_SIC_NZ_J,
	SCOPT_SIC_NZ_K,
	SCOPT_SIC_NZ_L,
	SCOPT_SIC_NZ_M,
	SCOPT_SIC_NZ_N,
	SCOPT_SIC_NZ_O,
	SCOPT_SIC_NZ_P,
	SCOPT_SIC_NZ_Q,
	SCOPT_SIC_NZ_R,
	SCOPT_SIC_NZ_S,
};
DECLARE_LIST_STRS(IndustryNZ) {
	IDS_SCOPT_SIC_NONE,
	IDS_SCOPT_SIC_NZ_A,
	IDS_SCOPT_SIC_NZ_B,
	IDS_SCOPT_SIC_NZ_C,
	IDS_SCOPT_SIC_NZ_D,
	IDS_SCOPT_SIC_NZ_E,
	IDS_SCOPT_SIC_NZ_F,
	IDS_SCOPT_SIC_NZ_G,
	IDS_SCOPT_SIC_NZ_H,
	IDS_SCOPT_SIC_NZ_I,
	IDS_SCOPT_SIC_NZ_J,
	IDS_SCOPT_SIC_NZ_K,
	IDS_SCOPT_SIC_NZ_L,
	IDS_SCOPT_SIC_NZ_M,
	IDS_SCOPT_SIC_NZ_N,
	IDS_SCOPT_SIC_NZ_O,
	IDS_SCOPT_SIC_NZ_P,
	IDS_SCOPT_SIC_NZ_Q,
	IDS_SCOPT_SIC_NZ_R,
	IDS_SCOPT_SIC_NZ_S,
};
DECLARE_LIST(IndustryNZ);

//
// Entity Type List
DECLARE_LIST_NUMS(EntityType) {
	SCOPT_ENTITYTYPE_0,
};
DECLARE_LIST_STRS(EntityType) {
	IDS_SCOPT_ENTITYTYPE_0,
};
DECLARE_LIST(EntityType);

//
// Entity Type Singapore List
DECLARE_LIST_NUMS(EntityTypeSG) {
	SCOPT_ENTITYTYPE_0,
	SCOPT_ENTITYTYPE_SG_1,
	SCOPT_ENTITYTYPE_SG_2,
	SCOPT_ENTITYTYPE_SG_3,
	SCOPT_ENTITYTYPE_SG_4,
	SCOPT_ENTITYTYPE_SG_5,
};
DECLARE_LIST_STRS(EntityTypeSG) {
	IDS_SCOPT_ENTITYTYPE_0,
	IDS_SCOPT_ENTITYTYPE_SG_1,
	IDS_SCOPT_ENTITYTYPE_SG_2,
	IDS_SCOPT_ENTITYTYPE_SG_3,
	IDS_SCOPT_ENTITYTYPE_SG_4,
	IDS_SCOPT_ENTITYTYPE_SG_5,
};
DECLARE_LIST(EntityTypeSG);

//
// Entity Type Malaysia List
DECLARE_LIST_NUMS(EntityTypeMY) {
	SCOPT_ENTITYTYPE_0,
	SCOPT_ENTITYTYPE_MY_1,
	SCOPT_ENTITYTYPE_MY_2,
	SCOPT_ENTITYTYPE_MY_3,
	SCOPT_ENTITYTYPE_MY_4,
	SCOPT_ENTITYTYPE_MY_5,
};
DECLARE_LIST_STRS(EntityTypeMY) {
	IDS_SCOPT_ENTITYTYPE_0,
	IDS_SCOPT_ENTITYTYPE_MY_1,
	IDS_SCOPT_ENTITYTYPE_MY_2,
	IDS_SCOPT_ENTITYTYPE_MY_3,
	IDS_SCOPT_ENTITYTYPE_MY_4,
	IDS_SCOPT_ENTITYTYPE_MY_5,
};
DECLARE_LIST(EntityTypeMY);

//
// Entity Type Hong Kong List
DECLARE_LIST_NUMS(EntityTypeHK) {
	SCOPT_ENTITYTYPE_0,
	SCOPT_ENTITYTYPE_HK_1,
	SCOPT_ENTITYTYPE_HK_2,
	SCOPT_ENTITYTYPE_HK_3,
	SCOPT_ENTITYTYPE_HK_4,
	SCOPT_ENTITYTYPE_HK_5,
};
DECLARE_LIST_STRS(EntityTypeHK) {
	IDS_SCOPT_ENTITYTYPE_0,
	IDS_SCOPT_ENTITYTYPE_HK_1,
	IDS_SCOPT_ENTITYTYPE_HK_2,
	IDS_SCOPT_ENTITYTYPE_HK_3,
	IDS_SCOPT_ENTITYTYPE_HK_4,
	IDS_SCOPT_ENTITYTYPE_HK_5,
};
DECLARE_LIST(EntityTypeHK);

//
// Entity Type Australia List
DECLARE_LIST_NUMS(EntityTypeAU) {
	SCOPT_ENTITYTYPE_0,
	SCOPT_ENTITYTYPE_AU_1,
	SCOPT_ENTITYTYPE_AU_2,
	SCOPT_ENTITYTYPE_AU_3,
	SCOPT_ENTITYTYPE_AU_4,
	SCOPT_ENTITYTYPE_AU_5,
};
DECLARE_LIST_STRS(EntityTypeAU) {
	IDS_SCOPT_ENTITYTYPE_0,
	IDS_SCOPT_ENTITYTYPE_AU_1,
	IDS_SCOPT_ENTITYTYPE_AU_2,
	IDS_SCOPT_ENTITYTYPE_AU_3,
	IDS_SCOPT_ENTITYTYPE_AU_4,
	IDS_SCOPT_ENTITYTYPE_AU_5,
};
DECLARE_LIST(EntityTypeAU);

//
// Entity Type New Zealand List
DECLARE_LIST_NUMS(EntityTypeNZ) {
	SCOPT_ENTITYTYPE_0,
	SCOPT_ENTITYTYPE_NZ_1,
	SCOPT_ENTITYTYPE_NZ_2,
	SCOPT_ENTITYTYPE_NZ_3,
	SCOPT_ENTITYTYPE_NZ_4,
	SCOPT_ENTITYTYPE_NZ_5,
};
DECLARE_LIST_STRS(EntityTypeNZ) {
	IDS_SCOPT_ENTITYTYPE_0,
	IDS_SCOPT_ENTITYTYPE_NZ_1,
	IDS_SCOPT_ENTITYTYPE_NZ_2,
	IDS_SCOPT_ENTITYTYPE_NZ_3,
	IDS_SCOPT_ENTITYTYPE_NZ_4,
	IDS_SCOPT_ENTITYTYPE_NZ_5,
};
DECLARE_LIST(EntityTypeNZ);

//
////
DECLARE_MASK(BRYear, IDS_SCOPT_BRYEAR_MASK);
DECLARE_MASK(DocNumPrefix, IDS_SCOPT_DOCNUM_PREFIX_MASK);
DECLARE_MASK(BRN, IDS_SCOPT_BRN_MASK);

// Field validation function declarations. Those declared here are done as
// examples. Remove, add or edit them as needed.
#include "SCOPTV.GEN"
#include "SCOPT2V.GEN"

// Mapping from view field index to view field definition, storage and
// presentation. This array is indexed directly by view field index,
// therefore you must ensure that view field index N is at subscript N here.
// If there are any gaps in the assignment of view field indexes, they
// must be marked in here with a tblNo entry of -1.
extern IDXMAP fldIdxMap [IDXIDX(FLD_IDX_LIMIT)] = {
   {0                  , -1}, // view field index 0 reserved by template
#include "SCOPTM.GEN"
#include "SCOPT2M.GEN"
};


#if CMP_COUNT+MAN_CMP_COUNT>0
// Composite names: all composite names must be listed here, including
// implicit and manual compositions. Their ordering is important:
// header, detail, hierarchy, demand, implicit, then manual composites.
#define	CSCOM_CMP	0

extern CMPNAME cmpNameList [CMP_COUNT+MAN_CMP_COUNT] = {
   {CSCOM_VIEW},
};
#endif

#if defined(SUBCLASS_VIEW)
// A subclass view must define the roto ID used to call the base view here.
// Because of the way chaining works, this is your own roto ID!
extern CHAR subCmpName [SIZEOF_ROTOIDSTR + 1] = "@@####";
#endif



#if RSC_COUNT>0
// Security resources. Entered are the complete standard set. Add, edit or
//  remove lines as necessary. The resource permission bitsets resulting from
//  each row will be bitwise-OR-ed together.
// A "default" bitset may be defined for cases where the use of a resource
//  is implicit or unnecessary; this is done by specifying NULL for the
//  resource name.
// If the permission bitset of a resource depends on additional resources,
//  they can be specified by inserting a third structure member after the
//  bitset field; this is a pointer to a PERMISSIONMAP structure defining
//  another bitset to be bitwise-AND-ed with the main one; these may be
//  nested arbitrarily deeply.
extern PERMISSIONMAP permission [RSC_COUNT] = {
   // The following demonstrates the implementation of a default "inquiry"
   // resource which is on at all times. Remove if not needed
   //{NULL              , (SEC_INQUIRE)},
   // Add, edit, or delete resources and bitsets as necessary.
	{SC_RSC_SCINQUIRY	, (SEC_INQUIRE)},
	{SC_RSC_SCSETUP	, (SEC_ADD | SEC_MODIFY | SEC_INQUIRE)},
	//{SC_RSC_RESOURCE1, (SEC_ADD | SEC_MODIFY | SEC_DELETE | SEC_INQUIRE | SEC_POST)},
   //{SC_RSC_RESOURCE2, (SEC_ADD | SEC_MODIFY | SEC_DELETE | SEC_INQUIRE | SEC_POST)},
   //{SC_RSC_RESOURCE3, (SEC_ADD | SEC_MODIFY | SEC_DELETE | SEC_INQUIRE | SEC_POST)},
};
#endif


#ifdef DO_HEADERETC
// Mapping from detail fields to dependent header fields.
// NOTE: It is assumed the type information of each view field index pair
// matches exactly!
extern DETAILMAP headerFields [DO_HEADERETC] = {
   {SCOPT_IDX(yours), header_IDX(headers)}, // make an entry for each dependent pair
};
#endif



////////////////////////////////////////////////////////////////////////////
// Field validation function declarations. Those defined here are done as
// examples. Remove, add or edit them as needed.


BOOL WINAPI NotBlankValid(
	LPV lpv,
	LONG lField,
	LPSTR lpValue)
{
	INT i;

	for (i = FindFieldDef(lField)->wLength - 1; i >= 0; i--)
		if (lpValue[i] != ' ')
			break;

	if (i < 0)
	{
		ReportError(lpv, IDERR_SC_FIELD_ISBLANK, MAKERSC(FindFieldMap(lField)->title), NULL, NULL);
		return FALSE;
	}

	return TRUE;
}


BOOL WINAPI EmailValid(
	LPV lpv,
	LONG lField,
	LPSTR lpValue)
{
	CHAR sEmail[MAX_FIELD_LENGTH + 1];
	strCopyZB(sEmail, lpValue, FindFieldDef(lField)->wLength);

	if (utlIsValidEmail(sEmail))
		return TRUE;

	ReportError(lpv, IDERR_SC_EMAIL_INVALID, MAKERSC(FindFieldMap(lField)->title), NULL, NULL);
	return FALSE;
}


BOOL WINAPI BRYearValid(
	LPV lpv,
	LONG lField,
	LPSTR lpValue)
{
	WORD wYear;
	strToWord(lpValue, &wYear, FindFieldDef(lField)->wLength);

	DBDATE dbDate;
	dtGetDate(&dbDate);

	if (wYear < 1900 || wYear > dbDate.wYear)
	{
		ReportError(lpv, IDERR_SCOPT_BRYEAR_INVALID, MAKERSC(FindFieldMap(lField)->title), NULL, NULL);
		return FALSE;
	}

	return TRUE;
}


BOOL WINAPI BRNValid(
	LPV lpv,
	LONG lField,
	LPSTR lpValue)
{
	return NotBlankValid(lpv, lField, lpValue);
}


BOOL WINAPI RListSValid(
	LPV lpv,
	LONG lField,
	LPSTR lpValue)
{
	BOOL result = ValidateList(lpv, FindPresentsInfo(lpv, lField), lField, lpValue);

	if (result == FALSE)
		ReportError(lpv, IDERR_SC_FIELD_NOTSPECIFIED, MAKERSC(FindFieldMap(lField)->title), NULL, NULL);

	return result;
}

BOOL WINAPI RListNValid(
	LPV lpv,
	LONG lField,
	LPDBSINT lpValue)
{
	BOOL result = ValidateList(lpv, FindPresentsInfo(lpv, lField), lField, lpValue);

	if (result == FALSE)
		ReportError(lpv, IDERR_SC_FIELD_NOTSPECIFIED, MAKERSC(FindFieldMap(lField)->title), NULL, NULL);

	return result;
}


BOOL WINAPI JobTitleValid(
	LPV lpv,
	LONG lField,
	LPDBSINT lpValue)
{
	if (RListNValid(lpv, lField, lpValue))
		if (*lpValue > 0)
			return TRUE;
		else
			ReportError(lpv, IDERR_SC_FIELD_NOTSPECIFIED, MAKERSC(FindFieldMap(lField)->title), NULL, NULL);

	return FALSE;
}


BOOL WINAPI IndustryValid(
	LPV lpv,
	LONG lField,
	LPSTR lpValue)
{
	DBSINT country = *(LPDBSINT)FindFieldValue(lpv, SCOPT_IDX(COUNTRY));

	if (country > 0 && lpValue[0] != ' ')
		return TRUE;
	else if (country == 0)
		return RListSValid(lpv, lField, lpValue);

	ReportError(lpv, IDERR_SC_FIELD_NOTSPECIFIED, MAKERSC(FindFieldMap(lField)->title), NULL, NULL);
	return FALSE;
}

BOOL WINAPI EntTypeValid(
	LPV lpv,
	LONG lField,
	LPDBSINT lpValue)
{
	DBSINT country = *(LPDBSINT)FindFieldValue(lpv, SCOPT_IDX(COUNTRY));

	if (country > 0 && *lpValue > 0)
		return TRUE;
	else if (country == 0)
		return RListNValid(lpv, lField, lpValue);

	ReportError(lpv, IDERR_SC_FIELD_NOTSPECIFIED, MAKERSC(FindFieldMap(lField)->title), NULL, NULL);
	return FALSE;
}

BOOL WINAPI FCPeriodsValid(
	LPV lpv,
	LONG lField,
	LPDBSINT lpValue)
{
	LPRECORD lpr = (LPRECORD)FindRecord(lpv)[0];

	switch (lField)
	{
		case SCOPT_IDX(FCPERIOD1E):
			if ((*lpValue > 1) && (*lpValue < lpr->fcPeriod2E))
				return TRUE;

		case SCOPT_IDX(FCPERIOD2E):
			if ((*lpValue > lpr->fcPeriod1E) && (*lpValue < lpr->fcPeriod3E))
				return TRUE;

		case SCOPT_IDX(FCPERIOD3E):
			if ((*lpValue > lpr->fcPeriod2E) && (*lpValue < lpr->fcPeriod4E))
				return TRUE;

		case SCOPT_IDX(FCPERIOD4E):
			if ((*lpValue > lpr->fcPeriod3E) && (*lpValue < lpr->fcPeriod5E))
				return TRUE;

		case SCOPT_IDX(FCPERIOD5E):
			if (*lpValue > lpr->fcPeriod4E)
				return TRUE;

		default:
			break;
	}

	ReportError(lpv, IDERR_SCOPT_PERIOD_SEQUENCE, NULL, NULL, NULL);
	return FALSE;
}

BOOL WINAPI DocNumLValid(
	LPV lpv,
	LONG lField,
	LPDBSINT lpValue)
{
	if (*lpValue <= 0 || *lpValue > SC_SIZEOF_DOCNUM)
	{
		ReportError(lpv, IDERR_SCOPT_DOCNUM_LENGTH, MAKERSC(FindFieldMap(lField)->title), NULL, NULL);
		return FALSE;
	}

	return TRUE;
}


BOOL WINAPI DocNumNValid(
	LPV lpv,
	LONG lField,
	LPBCD lpValue)
{
	return TRUE;
}


//////////////////////////////////////////////////////////////////////
// Helpers
VOID GetYearFromBRNSG(
	LPV lpv)
{
	LPRECORD2 lpr2 = (LPRECORD2)FindRecord(lpv)[1];

	CHAR sBRN[SCOPT_SIZ(BRN) + 1];
	strCopyZB(sBRN, lpr2->brn, SCOPT_SIZ(BRN));

	WORD wYear = 0;

	if (strLength(sBRN) == 10)
	{
		if ((sBRN[0] >= 'R')
			&& (sBRN[1] >= '0' && sBRN[1] <= '9')
			&& (sBRN[2] >= '0' && sBRN[2] <= '9'))
		{
			wYear = (sBRN[0] - 'R' + 18) * 100 + (sBRN[1] - '0') * 10 + (sBRN[2] - '0');
		}
		else if ((sBRN[9] >= 'A' && sBRN[9] <= 'Z')
			&& (sBRN[0] >= '0' && sBRN[0] <= '9')
			&& (sBRN[1] >= '0' && sBRN[1] <= '9')
			&& (sBRN[2] >= '0' && sBRN[2] <= '9')
			&& (sBRN[3] >= '0' && sBRN[3] <= '9')
			&& (sBRN[4] >= '0' && sBRN[4] <= '9')
			&& (sBRN[5] >= '0' && sBRN[5] <= '9')
			&& (sBRN[6] >= '0' && sBRN[6] <= '9')
			&& (sBRN[7] >= '0' && sBRN[7] <= '9'))
		{
			wYear = (sBRN[0] - '0') * 1000 + (sBRN[1] - '0') * 100 + (sBRN[2] - '0') * 10 + (sBRN[3] - '0');
		}
	}

	if (wYear != 0)
	{
		wordToStr(wYear, SCOPT_SIZ(BRYEAR), FindFieldValue(lpv, SCOPT_IDX(BRYEAR)), ' ');
		wordToStr(wYear, SCOPT_SIZ(BRYEARC), FindFieldValue(lpv, SCOPT_IDX(BRYEARC)), ' ');
	}
}

VOID GetYearFromBRN(
	LPV lpv)
{
	LPRECORD lpr = (LPRECORD)FindRecord(lpv)[0];
	switch (lpr->country)
	{
		case SCOPT_COUNTRY_SINGAPORE:
			GetYearFromBRNSG(lpv);
			break;

		default:
			break;
	}
}


//////////////////////////////////////////////////////////////////////
// Supporting functions for view entry points with view specific code.



#if defined(DO_APPLYHEADERFIELDS)

VIEWBASE ApplyHeaderFields (LPV lpv, INT op)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, ApplyHeaderFieldsBase (lpv, op));
   return e;
}

#endif



#ifdef DO_ATTRIBETC
/*---------------------------------------------------------------------------
   These functions replace the default internal field-level attribute access
   and maintenance. These are useful when the normal attribute maintenance
   supplied in the scOpt.c file needs to be augmented. An example is when
   the view has been placed in import or export mode, and there are a large
   number of fields which are enabled or editable on a modal basis; in these
   cases the attribute functions are defined so that whenever these attributes
   are requested they return TRUE unconditionally.
*/

// AttribClear: Clears the specified attribute in the given field
void WINAPI AttribClear (LPV lpv, LONG field, LONG bit)
{
   lpv->alAttributes[IDXIDX(field)] &= ~bit;
}



// AttribGet: Returns the complete set of the field's attributes
LONG WINAPI AttribGet (LPV lpv, LONG field)
{
   LONG mask;

   switch ( lpv->sysAccess ) {
      case SYSACCESS_EXPORT:  mask = ATTR_ENABLED;                break;
      case SYSACCESS_IMPORT:  mask = ATTR_ENABLED|ATTR_EDITABLE;  break;
      case SYSACCESS_POST:    mask = ATTR_ENABLED|ATTR_EDITABLE;  break;
      default:                mask = 0L;                          break;
   }

	if ((field == SCOPT_IDX(COUNTRY))
		&& lpv->bExists)
	{
		DBSINT country = *(LPDBSINT)FindFieldValue(lpv, SCOPT_IDX(COUNTRY));
		if (country != SC_COUNTRY_OTHERS)
			return (lpv->alAttributes[IDXIDX(field)] & ~ATTR_EDITABLE);
	}

	return lpv->alAttributes[IDXIDX(field)] | mask;
}



// AttribPut: Sets the complete set of the field's attributes
void WINAPI AttribPut (LPV lpv, LONG field, LONG bit)
{
   lpv->alAttributes[IDXIDX(field)] = bit;
}



// AttribSet: Sets the specified attribute in the given field
void WINAPI AttribSet (LPV lpv, LONG field, LONG bit)
{
   lpv->alAttributes[IDXIDX(field)] |= bit;
}



// AttribTest: returns TRUE if the specified attribute is currently set for
//  the given field, FALSE otherwise.
BOOL WINAPI AttribTest (LPV lpv, LONG field, LONG bit)
{
   return (AttribGet (lpv, field) & bit)!=0;
}

#endif



#if defined(DO_AUTOCANCELBODY)

VIEWBASE AutoCancelBody (LPV lpv, LONG field)
{
   ERRNUM e = ERRNUM_SUCCESS;
#if HDR_CMP_COUNT>0 && (SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS)
   INT i;
   LPKEYMAP k = FindKeyDef (0);

   for ( i=k->segments-DTL_SEG_COUNT; i--; )
      if ( k->indexes[i]==field )
         goto cancel_revisions;
   return e;

cancel_revisions:
 #if HAS_REVISIONS
   if ( lpv->bRevisioned ) {
      CHECK_CALL (e, rvMapDatabaseErrorToExtended (
         lpv->wLinkNo, RevisionInnerCancel (lpv, 1+HDR_HAS_REVISIONS, NULL)));
      CHECK_CALL (e, rvMapDatabaseErrorToExtended (
         lpv->wLinkNo, RevisionInnerCreate (lpv, 1+HDR_HAS_REVISIONS)));
  #if !HDR_HAS_REVISIONS
      CHECK_CALL (e, MapToDetails (lpv, VIEW_OP_CANCEL));
  #else
      CHECK_CALL (e, MapToDetails (lpv, VIEW_OP_REVISION_CANCEL, 1+HDR_HAS_REVISIONS));
  #endif
      CHECK_CALL (e, BaseNotifyFire (
         lpv, INSTANCE_NOTIFY_REVISION_CANCELLED, 1, (LPVOID) TRUE));
   }
 #endif
#endif
   CHECK_CALL (e, InitBodyGen (lpv, INITBODYGEN_NOINSERT |
                                    INITBODYGEN_NOGENERATE |
                                    INITBODYGEN_NOTOPEN));
   return e;
}

#endif



#if defined(DO_BASENOTIFY)

VIEWCALL BaseNotify (
   LPVOID context, // LPNOTIFYCONTEXT as passed to viewInstanceNotify
   LONG reason, // Reason for notification (see INSTANCE_NOTIFY_... in ROTOVIEW.H)
   LONG rotoID, // caller's rotoID (optional)
   LONG info, // value depends on reason
   LPVOID extra, // value depends on reason
   LPRVH rvh, // notifier's rotoview handle: can be used to call back to the notifier
   LPVOID view) // notifier's view handle: can be used to call back to the notifier

// Override for the template's stock subclass notification handler.
// The template automatically calls viewInstanceNotify() passing this
// function when this subclass view is opened. Overriding it gives you
// the opportunity to take action whenever the base view notifies you.
// It is important that you call BaseNotifyBase() (the original body)
// because there is certain maintenance that is needed.

{
   ERRNUM e = ERRNUM_SUCCESS;
   LPNOTIFYCONTEXT n = (LPNOTIFYCONTEXT) context;
   LPV lpv = n->lpv;

   CHECK_CALL (e, BaseNotifyBase (context, reason, rotoID, info, extra, rvh, view));
   return e;
}

#endif



#ifdef DO_CALCULATEFIELDS
/*--------------------------------------------------------------------
    This function is called by scOptInit, scOptRead and scOptFetch.  All
    other field values have been set.  Sets the values for any calculated
    fields.
*/
VIEWBASE GetRateInfo(
	LPV lpv)
{
	ERRNUM e = ERRNUM_SUCCESS;
	LPRECORD2 lpr2 = (LPRECORD2)FindRecord(lpv)[1];

	if (!lpv->CompanyInfo.boMulticurrency)
	//
	//// Company is Single Currency
	{
		blkCopy(lpr2->rateDate, lpr2->curDate, SIZEOF_DATE);

		if (!blkCompare(lpr2->homeCur, lpr2->rptCur, SIZEOF_CURRENCY_CODE))
			strToBcd("1", lpr2->rate, SIZEOF_RATE, RATE_DECIMALS);
		else
			strToBcd("-1", lpr2->rate, SIZEOF_RATE, RATE_DECIMALS);
	}
	else
	//
	//// Company is Multi-currencies
	{
		if (!blkCompare(lpr2->homeCur, lpr2->rptCur, SIZEOF_CURRENCY_CODE))
		{
			blkCopy(lpr2->rateDate, lpr2->curDate, SIZEOF_DATE);
			strToBcd("1", lpr2->rate, SIZEOF_RATE, RATE_DECIMALS);
		}
		else
		{
			//
			//// Find Exchange Rate
			DBQHANDLE qHandle = 0;
			WORD wFetched = 0;
			CURNCY_RATEINFO rateInfo;

			CHAR sQuery[MAX_RECORD_LENGTH + 1];
			sprintf(sQuery,
				"select top 1 *\n"
				"from CSCRD\n"
				"where\n"
				"	(HOMECUR = '%.3s' and SOURCECUR = '%.3s')\n"
				"	or (HOMECUR = '%.3s' and SOURCECUR = '%.3s')\n"
				"order by RATEDATE desc",
				lpr2->homeCur, lpr2->rptCur,
				lpr2->rptCur, lpr2->homeCur);

			CHECK_CALL(e, ErrorMapDatabaseToExtended(lpv->wLinkNo, dbQueryRun(lpv->wLinkNo, sQuery, 0, &qHandle)));

			if (DB_ERRNUM_IS_SUCCESS(dbQueryResultFetch(lpv->wLinkNo, qHandle, (LPVOID)& rateInfo.sHomeCurrency, (WORD)1, &wFetched))
				&& wFetched == 1)
				//
				//// Exchange rate found
			{
				blkCopy(lpr2->rate, rateInfo.Rate, SIZEOF_RATE);
				blkCopy(lpr2->rateDate, rateInfo.RateDate, SIZEOF_DATE);
				lpr2->rateOper = rateInfo.wRateOperator;

				if (blkCompare(lpr2->rptCur, rateInfo.sHomeCurrency, SIZEOF_CURRENCY_CODE))
					//
					//// Found Rate from Reporting (Country Currency) to Functional currency
					//// Revert operator
					lpr2->rateOper = (rateInfo.wRateOperator == RATE_OPERATOR_MULTIPLY) ? RATE_OPERATOR_DIVIDE : RATE_OPERATOR_MULTIPLY;
			}
			else
				//
				//// Exchange rate not found
			{
				blkCopy(lpr2->rateDate, lpr2->curDate, SIZEOF_DATE);
				strToBcd("-1", lpr2->rate, SIZEOF_RATE, RATE_DECIMALS);
			}

			CHECK_CALL(e, ErrorMapDatabaseToExtended(lpv->wLinkNo, dbQueryResultFree(lpv->wLinkNo, qHandle)));
		}
	}

	return e;
}

VIEWBASE CalculateFields (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;

	LPRECORD		lpr = (LPRECORD)FindRecord(lpv)[0];
	LPRECORD2	lpr2 = (LPRECORD2)FindRecord(lpv)[1];

	switch (lpr->country)
	{
		case SCOPT_COUNTRY_SINGAPORE:
			GetYearFromBRNSG(lpv);
			lpr2->industrySG[0] = lpr->industry[0];
			lpr2->entTypeSG = lpr->entityType;
			blkCopy(lpr2->rptCur, SC_COUNTRY_CURR_SINGAPORE, SIZEOF_CURRENCY_CODE);
			break;

		case SCOPT_COUNTRY_MALAYSIA:
			lpr2->industryMY[0] = lpr->industry[0];
			lpr2->entTypeMY = lpr->entityType;
			blkCopy(lpr2->rptCur, SC_COUNTRY_CURR_MALAYSIA, SIZEOF_CURRENCY_CODE);
			break;

		case SCOPT_COUNTRY_HONGKONG:
			lpr2->industryHK[0] = lpr->industry[0];
			lpr2->entTypeHK = lpr->entityType;
			blkCopy(lpr2->rptCur, SC_COUNTRY_CURR_HONGKONG, SIZEOF_CURRENCY_CODE);
			break;

		case SCOPT_COUNTRY_AUSTRALIA:
			lpr2->industryAU[0] = lpr->industry[0];
			lpr2->entTypeAU = lpr->entityType;
			blkCopy(lpr2->rptCur, SC_COUNTRY_CURR_AUSTRALIA, SIZEOF_CURRENCY_CODE);
			break;

		case SCOPT_COUNTRY_NEWZEALAND:
			lpr2->industryNZ[0] = lpr->industry[0];
			lpr2->entTypeNZ = lpr->entityType;
			blkCopy(lpr2->rptCur, SC_COUNTRY_CURR_NEWZEALAND, SIZEOF_CURRENCY_CODE);
			break;

		default:
			break;
	}

	//
	////
	lpr2->fcPeriod1S = 1;
	lpr2->fcPeriod2S = lpr->fcPeriod1E + 1;
	lpr2->fcPeriod3S = lpr->fcPeriod2E + 1;
	lpr2->fcPeriod4S = lpr->fcPeriod3E + 1;
	lpr2->fcPeriod5S = lpr->fcPeriod4E + 1;
	lpr2->fcPeriod6S = lpr->fcPeriod5E + 1;

	//
	////
	DBDATE currentDate;
	dtGetDate(&currentDate);
	dtDateToBCD(&currentDate, lpr2->curDate);
	BOOL bPeriodStatus;
	CHAR szCurrentYear[SIZEOF_YEAR + 1];
	blkSet(szCurrentYear, 0, sizeof(szCurrentYear));
	if (fscPeriod(lpv->hpib, lpv->wLinkNo, lpr2->curDate, (LPWORD)& lpr2->curPeriod, szCurrentYear, &bPeriodStatus) == TRUE)
		strCopyBZ(lpr2->curYear, SIZEOF_YEAR, szCurrentYear);
	else
	{
		//
		// If we reach here, mean the fiscal calendar for the current day is not created.
		// This usually happen for the first few days of the year where users forgot to create new Fiscal Year.
		// We will get the last period of the "LATEST" (means Last) year.
		FISCINFO fscLatestYear;
		if (fscLastYear(lpv->hpib, lpv->wLinkNo, &fscLatestYear) == TRUE)
		{
			blkCopy(lpr2->curYear, fscLatestYear.sYear, SIZEOF_YEAR);
			lpr2->curPeriod = fscLatestYear.wFiscalPeriods; 
		}
		else
		{
			//
			// One we reached here, means we can't even find latest year in Fiscal Calendar.
			// Fall back to 2019-12 since this is the time we release this program. No back-dated calculation.
			strCopyBZ(lpr2->curYear, SIZEOF_YEAR, "2019");
			lpr2->curPeriod = (WORD)12;
		}
	}

	for (INT i = 0; i < SIZEOF_PASSWORD; i++)
		lpr2->emailPswdS[i] = '*';

	CHECK_CALL(e, GetRateInfo(lpv));

   return e;
}

#endif



#if defined(DO_CANCELBODY)

VIEWBASE CancelBody (
   LPV lpv, // View handle
   INT level) // Revision nesting level [1...(HDR_HAS_REVISIONS+1)]

// Override of the template's CancelBody() function. Original functionality
// is in CancelBodyBase(). This function is the common point of control from
// which cancellation of revisions, nested included, occurs. It is called
// Called within: scOptCancel(), scOptRevisionCancel()

{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, CancelBodyBase (lpv, level));
   return e;
}

#endif



#ifdef DO_COMPOSEETC
/*--------------------------------------------------------------------
    This function is called by scOptCompose.
*/

VIEWBASE ComposeEtc (LPV  lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;

   return e;
}

#endif



#if defined(DO_COMPOSITENOTIFY)

VIEWBASE CompositeNotify (
   LPVOID context, // LPCMPNOTIFYCONTEXT as passed to viewInstanceNotify
   LONG reason, // Reason for notification (see INSTANCE_NOTIFY_... in ROTOVIEW.H)
   LONG rotoID, // caller's rotoID (optional)
   LONG info, // value depends on reason
   LPVOID extra, // value depends on reason
   LPRVH rvh, // notifier's rotoview handle: can be used to call back to the notifier
   LPVOID view) // notifier's view handle: can be used to call back to the notifier

// Override for the template's stock composite notification handler.
// The template automatically calls viewInstanceNotify() passing this
// function during scOptCompose() when the composite's cmpNameList[] entry
// has CMPNAME_OPTION_NOTIFY specified in it. Overriding this functions gives
// you the opportunity to take action whenever the composite view notifies you.
// It is important that you call CompositeNotifyBase() (the original body)
// because there is certain maintenance that is needed.

{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, CompositeNotifyBase (context, reason, rotoID, info, extra, rvh, view));

   switch ( reason ) {
      case INSTANCE_NOTIFY_FIELD_VALUE: {
         LPCMPNOTIFYCONTEXT n = (LPCMPNOTIFYCONTEXT) context;

         switch ( info ) { // index of field that changed
            case cmp_IDX(name):
               // Do something significant
               break;
            default:
               break;
         }
         break;
      }

      case INSTANCE_NOTIFY_RECORD_WRITTEN: {
         LPCMPNOTIFYCONTEXT n = (LPCMPNOTIFYCONTEXT) context;

         // Do something significant
         break;
      }
   }

   return ERRNUM_SUCCESS;
}

#endif



#ifdef DO_CONCURRENCYETC
/*---------------------------------------------------------------------------
   ConcurrencyEtc: called when scOptUpdate is done and there is a concurrency
   error detected in the time stamp. A list of fields which this view wants
   to change but which have been updated already by another caller is passed
   in the conflictIdx array member in the view handle. The number of fields
   in conflictIdx is passed to this function. You should attempt to reconcile
   values of fields for those for which it makes sense - eg - amounts or
   quantities.

   There are 3 record sets used: record[] has the most current field values
   you are trying to save, recordRead[] has the field values as you retrieved
   them from the database, and recordTemp[] has the actual field values as
   they exist in the database (the ones over which a conflict was signalled).
   When you merge values, update the recordTemp[] set.

   It may be that for some fields it doesn't make sense at all,
   meaning you should return DBS_CONFLICT to indicate the concurrency
   problem cannot be resolved. Note that fields having the ATTR_CALCULATE
   attribute are passed in since there is no way to determine the manner
   in which they are calculated. If you return DBS_SUCCESS indicating the
   fields were successfully reconciled CalculateFields() will be called to
   recalculate any altered fields, and the record will be reverified before
   being updated, since the new field values may be invalid. If all this
   succeeds, the reconciled record will successfully be saved to disk.
*/
DB_ERRNUM WINAPI ConcurrencyEtc (LPV lpv, INT fields)
{
   INT i;
   LONG f;
   INT size;
   LPSTR mine, old, New;

   for ( i=0; i<fields; i++ ) {
      f = lpv->conflicts[i].field;
      if ( FindFieldMapV (lpv, f)->tblNo>=BASE_TBL_COUNT+TBL_COUNT )
         continue; // ignore fields that you know are purely calculated
      size = FindFieldDefV (lpv, f)->wLength;
      mine = FindFieldValueAux (lpv, f, FindRecord (lpv));
      New = FindFieldValueAux (lpv, f, FindRecordTemp (lpv));
      old = FindFieldValueAux (lpv, f, FindRecordRead (lpv));
      switch ( f ) {
         case SCOPT_IDX(yours):
            break;
         default:
            return DBS_CONFLICT;
      }
   }
   return DBS_SUCCESS;
}
#endif



#if defined(DO_CREATEETC)

// CreateEtc() is called in the course of creating a view's table(s), in order
// to seed it with records as required by your application. Note that this
// callout takes a view handle, even though scOptCreate() does not. Effectively,
// when CreateEtc() is defined, fileAdd() opens a instance of the view. If this
// is a subclass view, then it is called after tables and/or columns have been
// added, but before keys are added.

VIEWBASE CreateEtc (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;
   INT t = 0;

# if SUBCLASS_LEVEL==NOT_SUBCLASS
   // add a single record or somesuch
# else
   LPVIEWDEF base = &lpv->subCmp;

   for (;;) {
      CHECK_FETCH (e, viewFetch (base->rvh, base->view));
      CHECK_CALL (e, BaseGetKey (lpv));

      // Set values as necessary

#  if SUBCLASS_LEVEL==ALTER_SUBCLASS
      CHECK_CALL (e, BasePutData (lpv));
#  endif
      // Uncomment the following xxxVerify() statement if you are modifying
      // field values in the base view. Note, however, that many views have
      // complex relationships with other views that may not work if not
      // properly composed.
      //CHECK_CALL (e, xxxVerify (lpv, TRUE));
#  if SUBCLASS_LEVEL==JOIN_SUBCLASS
      for ( t=BASE_TBL_COUNT; t<BASE_TBL_COUNT+TBL_COUNT; t++ ) {
         DB_ERRNUM d = dbInsert (lpv->wLinkNo,
                                 (FindTableHandle (lpv)) [t],
                                 (FindRecord (lpv)) [t]);

         fileError (lpv->wLinkNo, lpv->hpib, d);
         CHECK_CALL (e, rvMapDatabaseErrorToExtended (lpv->wLinkNo, d));
      }
#  elif SUBCLASS_LEVEL==ALTER_SUBCLASS
      CHECK_CALL (e, viewUpdate (base->rvh, base->view));
#  endif
   }
# endif

   return e;
}

#endif



#if defined(DO_DELETEBODY)

VIEWBASE DeleteBody (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, DeleteBodyBase (lpv));
   return e;
}

#endif



#if defined(DO_DELETEDETAILSBODY)

VIEWBASE DeleteDetailsBody (LPV lpv, INT c)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, DeleteDetailsBodyBase (lpv, c));
   return e;
}

#endif



#ifdef DO_DELETEVALID
/*--------------------------------------------------------------------
    This function is called as a first step by scOptDelete.  Allows
    the view to check any conditions specific to this view that must
    be met before the record may be deleted.  The ERRNUM is returned
    by scOptDelete.
*/
VIEWBASE DeleteValid (LPV  lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;

#if DTL_CMP_COUNT>0
   INT c;

   for ( c=HDR_CMP_COUNT; c<HDR_CMP_COUNT+DTL_CMP_COUNT; c++ )
      if ( FindCmp (lpv, c)->rvh==NULL ) {
         ReportError (lpv, SC_some_error_code, "arg1", MAKERSC(IDS_arg2), NULL);
         return ERRNUM_RECORD_INVALID;
      }
#endif
   return e;
}
#endif



#if defined DO_ENTRYSTATEPOP

void WINAPI EntryStatePop (LPV lpv, LPENTRYSTATE state)
{
   // Maintain your own entry state variables here
   EntryStatePopBase (lpv, state);
}

#endif



#if defined DO_ENTRYSTATEPUSH

LPENTRYSTATE WINAPI EntryStatePush (LPV lpv, LPROTOVIEW v, INT length, LPENTRYSTATE state)
{
   EntryStatePushBase (lpv, v, length, state);
   // Maintain your own entry state variables here
   return state;
}

#endif



#ifdef DO_FINDPRESENTSINFO
/*---------------------------------------------------------------------------
   Returns the presents info structure for a field.
*/
LPPRESENTATION WINAPI FindPresentsInfo (LPV lpv, LONG field)
{
   switch ( field ) {
      default:
         return FindFieldMapV (lpv, field)->presents;
   }
}
#endif



//--------------------------------------------------------------------
// This is called automatically when a batch or header key can
// be generated for you from scOptInit

#if defined(DO_GENERATEKEY) && !defined(DO_GENERATEKEYDELAYED)
VIEWBASE GenerateKey (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;

   return e;
}
#endif

#if defined(DO_GENERATEKEYDELAYED)
VIEWBASE GenerateKey (LPV lpv, INT what)
{
   ERRNUM e = ERRNUM_SUCCESS;

   if ( what & GENERATEKEY_RECORD ) {
   }
   if ( what & GENERATEKEY_KEY ) {
   }
   return e;
}
#endif



#ifdef DO_GETETC
/*--------------------------------------------------------------------
    This function is called by scOptGet after validating the field index,
    and before retrieving the data from the default buffer. Does any
    special processing of attributes, calculating fields, etc.
*/
VIEWBASE GetEtc (
   LPV lpv,
   LONG lField,
   LPSTR lpsBuffer,
   INT nSize)
{
   ERRNUM e = ERRNUM_SUCCESS;

   return e;
}
#endif



#ifdef DO_HEADERETC
/*-------------------------------------------------------------------------
   This function is called by scOptInsert, scOptUpdate, and scOptDelete.
   It updates any dependent fields in the header view. (eg - running totals)
*/
VIEWBASE HeaderEtc (
   LPV lpv,
   LONG field,
   INT op, // VIEW_OP_INSERT, VIEW_OP_UPDATE, VIEW_OP_DELETE
   LONG source,
   LPSTR take_out,
   LPSTR put_in)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, ApplyHeaderDelta (lpv, field, op, source,
                                    (LPDATUM) take_out, (LPDATUM) put_in, NULL));
   return e;
}
#endif



#ifdef DO_INITFIELDSTRUCTETC
/*-------------------------------------------------------------------------
   Called during scOptOpen, in order to initialize the structural definition
   of fields if any don't conform to the common structures. Called
   iteratively on each field.
*/

VIEWBASE InitFieldStructEtc (LPV lpv, LONG lField)
{
   ERRNUM e = ERRNUM_SUCCESS;

   return e;
}

#endif



#if defined(DO_INITBODYGEN)

VIEWBASE InitBodyGen (LPV lpv, INT fGenerate)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, InitBodyGenBase (lpv, fGenerate));
   return e;
}

#endif



#ifdef DO_INITNONBLANKFIELDS
/*--------------------------------------------------------------------
    This function is called by scOptInit after all fields have been
    initialized to blanks.  Sets initial values for all non-character
    data types and any strings that should not default to blanks.
*/

VIEWBASE InitNonBlankFields (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;

	LPRECORD		lpr = (LPRECORD)(FindRecord(lpv))[0];
	LPRECORD2	lpr2 = (LPRECORD2)(FindRecord(lpv))[1];

	blkSet(lpr->dummy, ' ', SCOPT_SIZ(DUMMY));

	lpr->jobTitle = 0;
	
	lpr->industry[0] = ' ';
	lpr->entityType = 0;

	lpr->fcPeriod1E = 30;
	lpr->fcPeriod2E = 60;
	lpr->fcPeriod3E = 90;
	lpr->fcPeriod4E = 120;
	lpr->fcPeriod5E = 150;
	lpr->pendingGL = TRUE;
	lpr->pendingAR = TRUE;
	lpr->pendingAP = TRUE;
	//
	lpr->cfeLength = SC_SIZEOF_DOCNUM;
	blkCopy(lpr->cfePrefix, (LPSTR)SCOPT_DOCNUM_PREFIX, SCOPT_SIZ(CFEPREFIX));
	bcdGrow(lpr->cfeNextNbr, (LONG)1, SCOPT_SIZ(CFENEXTNBR));
	LoadRsc(lpv->hpib, MAKERSC(IDS_SCOPT_DOCNUM_DEFAULT), SCOPT_SIZ(CFEDOCNUMD), lpr2->cfeDocNumD, TRUE);
	//
	lpr->emailAlert = TRUE;
	lpr->emailOffer = TRUE;
	lpr->emailPort = 25;
	blkSet(lpr->emailPswd, ' ' ^ 255, SCOPT_SIZ(EMAILPSWD));
	//
	blkCopy(lpr2->brn, lpv->CompanyInfo.sBrn, SIZEOF_COMP_BRN);
	blkCopy(lpr2->homeCur, lpv->CompanyInfo.sHomeCurrency, SIZEOF_CURRENCY_CODE);
	//
	lpr2->rateOper = RATE_OPERATOR_MULTIPLY;

   return e;
}

#endif



#ifdef DO_LIBMAINETC
/*--------------------------------------------------------------------
    This function is called by LibMain to allow you to do any
    special initialization.
*/
extern INT WINAPI LibMainEtc (
   HINSTANCE hInstance,
   WORD wDataSeg,
   WORD wHeapSize,
   LPSTR lpszCmdLine)
{
   return 1; // 1 for success, 0 for failure
}
#endif



#if defined(DO_MAPTODETAIL)

VIEWBASE MapToDetail (LPV lpv, INT op, INT cmp, va_list arguments)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, MapToDetailBase (lpv, op, cmp, va_list arguments));
   return e;
}

#endif



#if defined(DO_NOTIFYFIRE)

VIEWBASE NotifyFire (LPV lpv, LONG reason, LONG info, LPVOID extra)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, NotifyFireBase (lpv, reason, info, extra));
   return e;
}

#endif



#if DO_NOTIFYQUEUEFIELDVALUE

VIEWBASE NotifyQueueFieldValue (LPV lpv, LONG field, LPDBFIELD def)
{
   ERRNUM e = ERRNUM_SUCCESS;

   switch ( field ) {
      case SCOPT_IDX(trigger1):
         CHECK_CALL (e, NotifyQueueField (lpv, SCOPT_IDX(dependant1),
                                          INSTANCE_NOTIFY_FIELD_PRESENTATION));
         break;

      case SCOPT_IDX(trigger2):
      case SCOPT_IDX(trigger3):
      case SCOPT_IDX(trigger4):
         CHECK_CALL (e, NotifyQueueField (lpv, SCOPT_IDX(dependant2),
                                          INSTANCE_NOTIFY_FIELD_ATTRIBUTES));
         break;

      default:
         break;
   }
   return e;
}

#endif



#if defined(DO_OPENETC)
// Custom open logic. This should be used in preference to overriding
// scOptOpen and/or scOptInstanceOpen, since it will simplify maintenance,
// and more importantly will avoid bugs.
VIEWBASE OpenEtc (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;

   return e;
}

#endif



#ifdef DO_PREPOSTETC
/*---------------------------------------------------------------------------
   PrePostEtc: per-detail call-out for scOptPost(). As each change from the
   revision list is processed (by revExtractErr), this function is called
   prior to committing the new record to the database, giving the
   programmer the ability to do special per-detail processing. An example
   is updating item quantities during the posting of an order. The old record
   is in (FindRecordTemp (lpv)) [record], and the new record in
   (FindRecord (lpv)) [record]; the revision operation performed resulting in
   those records is in op. See the SDK documentation on revPostErr() for more
   information. POST_CONTINUE should be returned if processing was successful,
   and POST_ERROR should be returned if there was an error (which must be
   reported in the message stack).
*/
REV_ERRNUM WINAPI PrePostEtc (LPV lpv, INT op, INT record)
{
   switch ( op ) {
      case REV_INSERT:
      case REV_UPDATE:
         lpv->eRevision = rvMapViewErrorToDatabase (VIEW_OP_VERIFY,
                                                  xxxVerify (lpv, TRUE));
         if ( DB_ERRNUM_IS_FAILURE (lpv->eRevision) )
            return POST_ERROR;
         break;
      default:
         break;
   }
   return POST_CONTINUE;
}
#endif



#ifdef DO_PROCESSETC
VIEWBASE ProcessSendTestEmail(
	LPV lpv)
{
	ERRNUM e = ERRNUM_SUCCESS;

	LPRECORD lpr = (LPRECORD)FindRecord(lpv)[0];
	LPRECORD2 lpr2 = (LPRECORD2)FindRecord(lpv)[1];

	//
	// Generate Report
	//
	CHAR sPath[MAXLONGPATHLEN + 1];
	CHAR sPathReport[MAXLONGPATHLEN + 1];
	utlGetOrgPath(lpv->OrgID, sPath, MAXLONGPATHLEN);
	utlMakePath(sPathReport, sPath, "SCOPT.PDF");
	CHECK_CALL(e, CmdRptSelect(lpv->hpib, (LPSTR)"SCOPT", (LPSTR)"", FALSE));
	CHECK_CALL(e, CmdRptSetFormat(lpv->hpib, (WORD)1));
	CHECK_CALL(e, CmdRptPrint(lpv->hpib, (LPSTR)RPT_FILE_PDF, 1, sPathReport, 0, NULL));
	CHECK_CALL(e, CmdRptTerminate(lpv->hpib));

	CHAR sEmailHost[SCOPT_SIZ(EMAILHOST) + 1];
	CHAR sEmailUser[SCOPT_SIZ(EMAILUSER) + 1];
	CHAR sEmailPasswordRAW[SCOPT_SIZ(EMAILPSWD)];
	CHAR sEmailPassword[SCOPT_SIZ(EMAILPSWD) + 1];
	CHAR sEmailFrom[SCOPT_SIZ(EMAILADDR) + 1];
	CHAR sEmailTo[SCOPT_SIZ(EMAILTEST) + 1];

	CHAR sBuffer[RSC_MAX_MESSAGE + 1];
	CHAR sEmailSubject[RSC_MAX_MESSAGE + 1];
	CHAR sEmailBody[RSC_MAX_MESSAGE + 1];

	strCopyZB(sEmailHost, lpr->emailHost, SCOPT_SIZ(EMAILHOST));
	strCopyZB(sEmailUser, lpr->emailUser, SCOPT_SIZ(EMAILUSER));
	strEncrypt((LPBYTE)sEmailPasswordRAW, lpr->emailPswd, SCOPT_SIZ(EMAILPSWD));
	strCopyZB(sEmailPassword, sEmailPasswordRAW, SCOPT_SIZ(EMAILPSWD));
	strCopyZB(sEmailFrom, lpr->emailAddr, SCOPT_SIZ(EMAILADDR));
	strCopyZB(sEmailTo, lpr2->emailTest, SCOPT_SIZ(EMAILTEST));

	LoadRsc(lpv->hpib, MAKERSC(IDS_SCOPT_TESTEMAIL_SUBJECT), RSC_MAX_MESSAGE, sBuffer, TRUE);
	sprintf_s(sEmailSubject, sBuffer, lpv->CompanyInfo.sOrgID);
	LoadRsc(lpv->hpib, MAKERSC(IDS_SCOPT_TESTEMAIL_BODY), RSC_MAX_MESSAGE, sBuffer, TRUE);
	sprintf_s(sEmailBody, sBuffer, lpv->CompanyInfo.sName);

	e = (ERRNUM)(emailSend(
		sEmailHost,
		lpr->emailPort,
		lpr->emailSSL,
		sEmailUser,
		sEmailPassword,
		sEmailFrom,
		sEmailTo,
		(LPSTR)"Info.Asia@sage.com",
		sEmailSubject,
		sEmailBody,
		sPathReport
	));

	filDelete(sPathReport);

	if (!ERRNUM_IS_SUCCESS(e))
		ReportError(lpv, IDS_SCOPT_TESTEMAIL_FAILED, NULL, NULL, NULL);

	return e;
}

VIEWBASE ProcessCheckExchangeRate(
	LPV lpv)
{
	ERRNUM e = ERRNUM_SUCCESS;

	DBSINT country = *(LPDBSINT)FindFieldValue(lpv, SCOPT_IDX(COUNTRY));
	if (country == SC_COUNTRY_OTHERS)
		return e;

	CHECK_CALL(e, GetRateInfo(lpv));

	if (bcdCompareZero((PCBYTE)FindFieldValue(lpv, SCOPT_IDX(RATE)), SIZEOF_RATE) <= 0)
	{
		CHAR msgTemplate[RSC_MAX_MESSAGE];
		CHAR msg[RSC_MAX_MESSAGE];
		LoadRsc(lpv->hpib, MAKERSC(IDWARN_SCOPT_RATENOTFOUND), RSC_MAX_MESSAGE, msgTemplate, TRUE);
		sprintf(msg, msgTemplate,
			FindFieldValue(lpv, SCOPT_IDX(RPTCUR)), FindFieldValue(lpv, SCOPT_IDX(HOMECUR)),
			FindFieldValue(lpv, SCOPT_IDX(HOMECUR)), FindFieldValue(lpv, SCOPT_IDX(RPTCUR)));

		errPutString(lpv->hpib, msg, PRI_WARNING);
	}

	return e;
}

VIEWBASE ProcessEtc (
   LPV lpv) // view handle

// Callout invoked by scOptProcess().  Does all processing.

{
   ERRNUM e = ERRNUM_SUCCESS;

	switch ((WORD)*FindFieldValue(lpv, SCOPT_IDX(PROCESSCMD)))
	{
		case 1:
			CHECK_CALL(e, ProcessSendTestEmail(lpv));
		
		default:
			CHECK_CALL(e, ProcessCheckExchangeRate(lpv));
			break;
	}

	return e;
}
#endif



#if defined(DO_PUTCMPFIELD)

VIEWBASE PutCmpField (LPV lpv, LONG lField, LPSTR lpBuffer, INT nSize)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, PutCmpFieldAux (lpv, lField, lpBuffer, nSize,
                                  FALSE, HDR_CMP_COUNT, CMP_COUNT);
   return e;
}



VIEWBASE PutCmpFieldAux (LPV lpv, LONG lField, LPSTR lpBuffer, INT nSize, BOOL validate, INT from, INT to)
{
   ERRNUM e = ERRNUM_SUCCESS;
# if CMP_COUNT-HDR_CMP_COUNT>0
   INT c;
   LONG f;

   for ( c=from; c<to; c++ ) {
      LPVIEWDEF v = FindCmp (lpv, c);

#  if !defined(DO_LAZYPUT)
      CHECK_CALL (e, DemandOpen (lpv, c));
#  endif
      f = * FindCmpField (lpv, c, lField);
      if ( v->rvh && f )
#  if defined(DO_LAZYPUT) && DMND_CMP_COUNT+IMP_CMP_COUNT>0
         if ( c<EXP_CMP_COUNT-DMND_CMP_COUNT || ! * FindImpOpen (lpv, c) )
#  endif
         {
            CHECK_CALL (e, viewPut (v->rvh, v->view, f, lpBuffer, nSize, validate));
         }
   }
# endif
   return e;
}



VIEWBASE PutCmpFields (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;
# if CMP_COUNT>0
   INT nFld;
   LONG lField;

   for ( nFld=0; nFld<FLD_IDX_COUNT; ++nFld ) {
      lField = * FindFieldIndexV (lpv, nFld);
      CHECK_CALL (e, PutCmpField (lpv, lField, FindFieldValue (lpv, lField),
                                  FindFieldDefV (lpv, lField)->wLength));
   }
# endif
   return e;
}

#endif



#if defined(DO_PUTCMPKEY)

VIEWBASE PutCmpKey (LPV lpv, INT cmp, INT inst, BOOL validate)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, PutCmpKeyBase (lpv, cmp, inst, validate));
   return e;
}

#endif



#ifdef DO_PUTETC
/*--------------------------------------------------------------------
    This function is called by scOptPut as a last step.  Does any
    special processing of attributes, calculating related fields,
    transfering key values to key fields of other tables, etc.
*/
VIEWBASE PutEtc (
   LPV lpv,
   LONG lField,
   LPSTR lpsBuffer,
   INT nSize)
{
   ERRNUM e = ERRNUM_SUCCESS;

	LPRECORD		lpr = (LPRECORD)FindRecord(lpv)[0];
	LPRECORD2	lpr2 = (LPRECORD2)FindRecord(lpv)[1];

	LPDATUM fieldValue = (LPDATUM)lpsBuffer;

   if ( !lpv->bFieldChanged ) // It may be desireable to process a field
      return e;               // even if it has changed.....
   switch ( lField ) {
		case SCOPT_IDX(BRN):
			GetYearFromBRN(lpv);
			break;

		case SCOPT_IDX(COUNTRY):
			lpr->industry[0] = ' ';
			lpr2->industrySG[0] = ' ';
			lpr2->industryMY[0] = ' ';
			lpr2->industryHK[0] = ' ';
			lpr2->industryAU[0] = ' ';
			lpr2->industryNZ[0] = ' ';
			
			lpr->entityType = 0;
			lpr2->entTypeSG = 0;
			lpr2->entTypeMY = 0;
			lpr2->entTypeHK = 0;
			lpr2->entTypeAU = 0;
			lpr2->entTypeNZ = 0;

			switch (fieldValue->i)
			{
				case SCOPT_COUNTRY_SINGAPORE:
					blkCopy(lpr2->rptCur, SC_COUNTRY_CURR_SINGAPORE, SIZEOF_CURRENCY_CODE);
					GetYearFromBRN(lpv);
					break;

				case SCOPT_COUNTRY_MALAYSIA:
					blkCopy(lpr2->rptCur, SC_COUNTRY_CURR_MALAYSIA, SIZEOF_CURRENCY_CODE);
					break;

				case SCOPT_COUNTRY_HONGKONG:
					blkCopy(lpr2->rptCur, SC_COUNTRY_CURR_HONGKONG, SIZEOF_CURRENCY_CODE);
					break;

				case SCOPT_COUNTRY_AUSTRALIA:
					blkCopy(lpr2->rptCur, SC_COUNTRY_CURR_AUSTRALIA, SIZEOF_CURRENCY_CODE);
					break;

				case SCOPT_COUNTRY_NEWZEALAND:
					blkCopy(lpr2->rptCur, SC_COUNTRY_CURR_NEWZEALAND, SIZEOF_CURRENCY_CODE);
					break;

				default:
					break;
			}
			break;

		//
		//// Industry
		case SCOPT_IDX(INDUSTRYSG):
		case SCOPT_IDX(INDUSTRYMY):
		case SCOPT_IDX(INDUSTRYHK):
		case SCOPT_IDX(INDUSTRYAU):
		case SCOPT_IDX(INDUSTRYNZ):
			//CHECK_CALL(e, scOptPut(lpv, SCOPT_IDX(INDUSTRY), lpsBuffer, SCOPT_SIZ(INDUSTRY), FALSE));
			lpr->industry[0] = lpsBuffer[0];
			break;

		//
		//// Entity Type
		case SCOPT_IDX(ENTTYPESG):
		case SCOPT_IDX(ENTTYPEMY):
		case SCOPT_IDX(ENTTYPEHK):
		case SCOPT_IDX(ENTTYPEAU):
		case SCOPT_IDX(ENTTYPENZ):
			//CHECK_CALL(e, scOptPut(lpv, SCOPT_IDX(ENTITYTYPE), lpsBuffer, SCOPT_SIZ(ENTITYTYPE), FALSE));
			lpr->entityType = fieldValue->i;
			break;

		case SCOPT_IDX(EMAILPSWDS):
			strEncrypt(lpr->emailPswd, (LPBYTE)lpsBuffer, nSize);
			break;

		case SCOPT_IDX(EMAILTEST):
		case SCOPT_IDX(PROCESSCMD):
			lpv->bDirty = FALSE;
			break;

		case SCOPT_IDX(FCPERIOD1E):
			lpr2->fcPeriod2S = fieldValue->i + 1;
			break;

		case SCOPT_IDX(FCPERIOD2E):
			lpr2->fcPeriod3S = fieldValue->i + 1;
			break;

		case SCOPT_IDX(FCPERIOD3E):
			lpr2->fcPeriod4S = fieldValue->i + 1;
			break;

		case SCOPT_IDX(FCPERIOD4E):
			lpr2->fcPeriod5S = fieldValue->i + 1;
			break;

		case SCOPT_IDX(FCPERIOD5E):
			lpr2->fcPeriod6S = fieldValue->i + 1;
			break;
		
		default:
         break;
   }
   return e;
}
#endif



#if defined(DO_REKEYEDREVISION)

VIEWBASE RekeyedRevision (
   LPV lpv,    // view handle
   INT level,  // Revision nesting level [1...(HDR_HAS_REVISIONS+1)]
   LPSTR from, // old primary key value
   LPSTR to,   // new primary key value
   INT size)   // number of leading bytes

// This callout is invoked during scOptRevisionRekey(), after each record has
// been rekeyed.

{
   ERRNUM e = ERRNUM_SUCCESS;

   // Do something....
   return e;
}

#endif


#if defined(DO_REPORTERROR)

void WINAPI ReportError (LPV lpv, RSCID error, LPSTR a1, LPSTR a2, LPSTR a3)
{
   CHAR b1 [RSC_MAX_MESSAGE];
   CHAR b2 [RSC_MAX_MESSAGE];
   CHAR b3 [RSC_MAX_MESSAGE];

   a1 = LoadRsc (lpv->hpib, a1, sizeof (b1), b1, TRUE);
   a2 = LoadRsc (lpv->hpib, a2, sizeof (b2), b2, TRUE);
   a3 = LoadRsc (lpv->hpib, a3, sizeof (b3), b3, TRUE);

   errPut (lpv->hpib, APPL, error, PRI_ERROR, a1, a2, a3);
}

#endif



#if defined(DO_REPORTERRORVIAPIB)

void WINAPI ReportErrorViaPIB (HPIB pib, RSCID error, LPSTR a1, LPSTR a2, LPSTR a3)
{
   CHAR b1 [RSC_MAX_MESSAGE];
   CHAR b2 [RSC_MAX_MESSAGE];
   CHAR b3 [RSC_MAX_MESSAGE];

   a1 = LoadRsc (pib, a1, sizeof (b1), b1, TRUE);
   a2 = LoadRsc (pib, a2, sizeof (b2), b2, TRUE);
   a3 = LoadRsc (pib, a3, sizeof (b3), b3, TRUE);

   errPut (pib, APPL, error, PRI_ERROR, a1, a2, a3);
}

#endif



#if defined(DO_REPORTGENERICERROR)

void WINAPI ReportGenericError (LPV lpv, WORD area, WORD op, WORD error, LPVOID extra)
{
   errPutGeneric (lpv->hpib, APPL, MAKERSC (IDS_SCOPT_VIEW_NAME), NULL,
                  area, op, MAKERSC (ERRGEN_CAT_DEFAULT), error, extra);
}

#endif



#if defined(DO_REPORTGENERICERRORVIAPIB)

void WINAPI ReportGenericErrorViaPIB (HPIB pib, WORD area, WORD op, WORD error, LPVOID extra)
{
   CHAR noun [RSC_MAX_MESSAGE];

   errPutGeneric (pib, APPL, MAKERSC (IDS_SCOPT_VIEW_NAME), NULL,
                  area, op, MAKERSC (ERRGEN_CAT_DEFAULT), error, extra);
}

#endif



#if defined(DO_REVERSEHEADERFIELDS)

VIEWBASE ReverseHeaderFields (LPV lpv, INT op)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, ReverseHeaderFieldsBase (lpv, op));
   return e;
}

#endif



#if defined(DO_REVISIONINNERPOST)

VIEWBASE RevisionInnerPost (
   LPV lpv, // View handle
   INT level) // Revision nesting level [1...(HDR_HAS_REVISIONS+1)]

// Override of the template's RevisionInnerPost() function. Original
// functionality is in RevisionInnerPostBase(). This function is the
// common point of control from which revisions, nested included, are posted.
// Called within: scOptPost(), scOptRevisionPost()

{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, RevisionInnerPostBase (lpv, level));
   return e;
}

#endif



#ifdef DO_REVPOSTETC
/*---------------------------------------------------------------------------
   revPostEtc: per-detail call-out for scOptPost(). As each change from the
   revision list is processed (by revPostErr), this function is called, giving
   the programmer the ability to do special per-detail processing. An example
   is updating item quantities during the posting of an order.

   The old record is in (FindRecordTemp (lpv)) [record], and the new record in
   (FindRecord (lpv)) [record]; the revision operation performed resulting in
   those records is in op.

   See the SDK documentation on revPostErr() for more information.

   Note that revPostEtc is called in a different sequence when the primary
   table is sequenced versus when it is ordered. When Ordered, it is
   by record then by table. When sequenced it is by table then by record.
   When there is only one (physical) table, these degenerate to the same
   thing. It is when there are multiple tables it makes a difference.

   For instance, suppose there are 2 tables A & B, and # revision records
   in each (1, 2, . . . #). Then for ordered revisions revPostEtc is called
   with: A1, B1, A2, B2, . . . A#, B#. For sequenced revisions revPostEtc
   is called with A1, A2, . . . A#, B1, B2, . . . B#

   Regardless of the sequence in which records are passed in, you don't
   always have a complete set of records constituting the proper view record.
   When you have a single table, you do have a complete view record, regardless.
   Also, when your primary table is ordered, you will have a complete view
   record when the last table record is passed in. With multiple sequenced
   tables, you never have a complete view record, and would have to synthesize
   it yourself as necessary. In all cases, you also have to call
   CalculateFields() yourself.
*/
DB_ERRNUM WINAPI revPostEtc (LPV lpv, INT op, INT record)
{
   DB_ERRNUM d = DBS_SUCCESS;

   return d;
}
#endif



#if defined(DO_ROTOENTRY)
/*--------------------------------------------------------------------
   This supercedes rotoEntryEtc() as the preferred method for adding
   extension calls. Original behaviour is available by calling
   rotoEntryBase(). Hence, this function is a true override.
*/
VIEWCALL rotoEntry (LPROTOVIEW v, INT length)
{
   ERRNUM e = ERRNUM_SUCCESS;
   ENTRYSTATE state;
   LPV lpv = (LPV) v->view;

   // Save away state information; note that this requires a valid view handle
   switch ( v->op ) {
      case VIEW_OP_yours :
         EntryStatePush (lpv, v, length, &state);
         break;
      default:
         break;
   }

   switch ( v->op ) {
      case VIEW_OP_yours  :
         e = scOptYours  (v->view, v->field, v->p);
         break;
      default:
         e = rotoEntryBase (v, length);
         break;
   }

#if !defined(DO_EXTENDEDERRORS)
   e = rvMapExtendedErrorToOld (v->op, e);
#endif

   // Restore state information; note that this requires a valid view handle
   switch ( v->op ) {
      case VIEW_OP_yours :
         EntryStatePop (lpv, &state);
         break;
      default:
         break;
   }

   return e;
}
#endif



#ifdef DO_ROTOENTRYETC
/*-----------------------------------------------------------------------
   rotoEntryEtc is provided to allow non-standard view operation codes to
   be added. Only non-standard view operations are passed in, since standard
   ones are picked off prior.
*/
VIEWBASE rotoEntryEtc (LPROTOVIEW v, INT length)
{
   ERRNUM e = ERRNUM_SUCCESS;

   switch ( v->op ) {
      case VIEW_OP_yours  :
         e = scOptYours  (v->view, v->field, v->p);
         break;
      default:
         e = BaseRotoEntry (v, length);
         break;
   }

#if !defined(DO_EXTENDEDERRORS)
   e = rvMapExtendedErrorToOld (v->op, e);
#endif

   return e;
}
#endif



#if defined(DO_SAVEHEADERFIELDS)

void WINAPI SaveHeaderFields (LPV lpv)
{
   SaveHeaderFieldsBase (lpv);
}

#endif



#ifdef DO_VALIDATEFIELDDEPENDENCIES

extern WORD WINAPI ValidateFieldDependencies (
   LPV lpv) // View handle

// This function is called by scOptVerify after each field has been
// validated.  Checks any cross field dependencies.  Reports any
// errors found.  Returns the number of errors found.

{
   return 0;
}
#endif



#ifdef DO_VALIDATEKEYS

BOOL WINAPI ValidateKey (
   LPV lpv,  // view handle of this view
   INT view, // Composite view array index
   INT inst) // Keymap of source key fields

// Called by scOptVerify when a field is a key in a composite
// view and verification of its existence is needed. Composed view's key
// has been initialized upon entry.

{
   BOOL exists;
# if defined(BATCH_VIEW) && HDR_CMP_COUNT>0
   CHAR buffer [MAX_FIELD_LENGTH];
   LPDBFIELD f;
   INT seg;
   LONG field;
# endif
   LPKEYMAP keyMap = FindKeyMap (view) + inst;
   LPLONG keyFields = FindCmpKey (lpv, view)->indexes;
   LPVIEWDEF v = FindCmp (lpv, view);

// If any composite view keys DON'T need to validated, uncomment the
// following statement and include them.
//   if ( view==SOME_EXCLUSIONS )
//      return TRUE;

# if defined(BATCH_VIEW) && HDR_CMP_COUNT>0
   if ( view==0 ) {
      keyMap = FindKeyDef (0);
      for ( seg=keyMap->segments-DTL_SEG_COUNT; seg--; ) {
         field = keyMap->indexes[seg];
         f = FindFieldDefV (lpv, field);
         CHECK_CALL_BOOLEAN (lpv->eValidation,
            viewGet (v->rvh, v->view, keyFields[seg], buffer, f->wLength));
         if ( memcmp (FindFieldValue (lpv, field), buffer, f->wLength)!=0 ) {
            ; // ReportError (lpv, SC_some_error_code, "arg1", MAKERSC(IDS_arg2), NULL);
            return FALSE;
         }
      }
   }
   else
# endif
   {
      CHECK_CALL_BOOLEAN (lpv->eValidation, PutCmpKey (lpv, view, inst, FALSE));
   }

   CHECK_CALL_BOOLEAN (lpv->eValidation, viewExists (v->rvh, v->view, &exists));
   if ( !exists )
      ; // ReportError (lpv, SC_some_error_code, "arg1", MAKERSC(IDS_arg2), NULL);
   return exists;
}

#endif



#if defined(DO_XXXFETCHFILTER)

VIEWBASE xxxFetchFilter (LPV lpv, INT flags, LPFILTER filter, LPSHORT range, BOOL ascending)
{
   ERRNUM e = ERRNUM_SUCCESS;
   BOOL found = FALSE;

   CHECK_FETCH_UNROLL (e, found,
      xxxFetchFilterBase (lpv, flags, filter, range, ascending));
   if ( !found )
      return ERRNUM_RECORD_NO_MORE_DATA;
   return e;
}

#endif



#if defined(DO_XXXREAD)

VIEWBASE xxxRead (LPVOID lpView, BOOL bLock)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;
   BOOL found = FALSE;

   CHECK_FETCH_UNROLL (e, found, xxxReadBase (lpView, bLock));
   if ( !found )
      return ERRNUM_RECORD_NOT_FOUND;
   return e;
}

#endif



// ---



/////////////////////////////////////////////////////////////////////////////
// The following are the per-view-routine override functions. Note that the
// original view template behaviour for each entry point can be invoked
// by calling scOptBaseYYYY from within each respecive scOptYYYY here.
// These overrides allow you to process before, after, or instead of
// the original view template behaviour.

// +++



#ifdef DO_scOptAttribs
VIEWCALL scOptAttribs   (LPVOID lpView, LONG lField, LPLONG lpAttributes)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseAttribs   (lpView, lField, lpAttributes));
   return e;
}
#endif



#ifdef DO_scOptBlkGet
VIEWCALL scOptBlkGet    (LPVOID lpView, INT lFields, LPLONG lFieldList, LPSHORT lpnSizeList, LPSTR lpsBuffer)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseBlkGet    (lpView, lFields, lFieldList, lpnSizeList, lpsBuffer));
   return e;
}
#endif



#ifdef DO_scOptBlkPut
VIEWCALL scOptBlkPut    (LPVOID lpView, INT lFields, LPLONG lFieldList, LPSHORT lpnSizeList, LPSTR lpsBuffer, BOOL bVerify)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseBlkPut    (lpView, lFields, lFieldList, lpnSizeList, lpsBuffer, bVerify));
   return e;
}
#endif



#ifdef DO_scOptBrowse
VIEWCALL scOptBrowse    (LPVOID lpView, LPSTR lpsExpression, BOOL bAscending)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseBrowse    (lpView, lpsExpression, bAscending));
   return e;
}
#endif



#ifdef DO_scOptCancel
VIEWCALL scOptCancel    (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseCancel    (lpView));
   return e;
}
#endif



#ifdef DO_scOptClose
VIEWCALL scOptClose     (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseClose     (lpView));
   return e;
}
#endif



#ifdef DO_scOptCmpNames
VIEWCALL scOptCmpNames  (INT roto, LPSTR lpsCompositeNames, LPSHORT lpnCount)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseCmpNames  (roto, lpsCompositeNames, lpnCount));
   return e;
}
#endif



#ifdef DO_scOptCompose
VIEWCALL scOptCompose   (LPVOID lpView, LPVIEWDEF lpvdefComposites)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseCompose   (lpView, lpvdefComposites));
   return e;
}
#endif



#ifdef DO_scOptCreate
VIEWCALL scOptCreate    (HPIB hPIB, WORD wLinkNo)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseCreate    (hPIB, wLinkNo));
   return e;
}
#endif



#ifdef DO_scOptDelete
VIEWCALL scOptDelete    (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseDelete    (lpView));
   return e;
}
#endif



#ifdef DO_scOptDirty
VIEWCALL scOptDirty     (LPVOID lpView, LPBOOL bChanged)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseDirty     (lpView, bChanged));
   return e;
}
#endif



#ifdef DO_scOptDrop
VIEWCALL scOptDrop      (HPIB hPIB, WORD wLinkNo)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseDrop      (hPIB, wLinkNo));
   return e;
}
#endif



#ifdef DO_scOptExists
VIEWCALL scOptExists    (LPVOID lpView, LPBOOL bExists)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseExists    (lpView, bExists));
   return e;
}
#endif



#ifdef DO_scOptFetch
VIEWCALL scOptFetch     (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;
   BOOL found = FALSE;

   CHECK_FETCH_UNROLL (e, found, scOptBaseFetch     (lpView));
   if ( !found )
      return ERRNUM_RECORD_NO_MORE_DATA;
   return e;
}
#endif



#ifdef DO_scOptFetchLock
VIEWCALL scOptFetchLock (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;
   BOOL found = FALSE;

   CHECK_FETCH_UNROLL (e, found, scOptBaseFetchLock (lpView));
   if ( !found )
      return ERRNUM_RECORD_NO_MORE_DATA;
   return e;
}
#endif



#ifdef DO_scOptField
VIEWCALL scOptField     (LPVOID lpView, INT nFldNumber, LPSTR lpsFldName, LPLONG lField)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseField     (lpView, nFldNumber, lpsFldName, lField));
   return e;
}
#endif



#ifdef DO_scOptFieldExists
VIEWCALL scOptFieldExists (
   LPV view,
   LONG lField,
   LP_A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   MaxError (&e, scOptBaseFieldExists (view, lField, flags));
   return e;
}
#endif



#ifdef DO_scOptFieldName
VIEWCALL scOptFieldName (
   LPV view,
   LONG lField,
   LPSTR lpsName,
   LPSTR lpsDesc,
   A4W_SIZE size)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseFieldName (view, lField, lpsName, lpsDesc, size));
   return e;
}
#endif


#ifdef DO_scOptFields
VIEWCALL scOptFields    (LPVOID lpView, LPSHORT lFields)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseFields    (lpView, lFields));
   return e;
}
#endif



#if defined(DO_scOptFilterCount)
VIEWCALL scOptFilterCount (LPV view, LPSTR expression, A4W_FLAGS flags, LP_A4W_SIZE count)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseFilterCount (view, expression, flags, count));
   return e;
}
#endif



#if defined(DO_scOptFilterDelete)
VIEWCALL scOptFilterDelete (LPV view, LPSTR filter, A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseFilterDelete (view, filter, flags));
   return e;
}
#endif



#if defined(DO_scOptFilterFetch)
VIEWCALL scOptFilterFetch (LPV view, A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;
   BOOL found = FALSE;

   CHECK_FETCH_UNROLL (e, found, scOptBaseFilterFetch (view, flags));
   if ( !found )
      return ERRNUM_RECORD_NO_MORE_DATA;
   return e;
}
#endif



#if defined(DO_scOptFilterSelect)
VIEWCALL scOptFilterSelect (LPV view, INT key, LPSTR filter, A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseFilterSelect (view, key, filter, flags));
   return e;
}
#endif



#ifdef DO_scOptGet
VIEWCALL scOptGet       (LPVOID lpView, LONG lField, LPSTR buffer, INT nSize)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseGet       (lpView, lField, buffer, nSize));
   return e;
}
#endif



#ifdef DO_scOptInit
VIEWCALL scOptInit      (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseInit      (lpView));
   return e;
}
#endif



#ifdef DO_scOptInsert
VIEWCALL scOptInsert    (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseInsert    (lpView));
   return e;
}
#endif



#if defined(DO_scOptInstanceFieldList)
VIEWCALL scOptInstanceFieldList (LPV view, A4W_NOTIFY_PROC notify, LPVOID context, A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseInstanceFieldList (view, flags, count, fields));
   return e;
}
#endif



#if defined(DO_scOptInstanceNotify)
VIEWCALL scOptInstanceNotify (LPV view, A4W_NOTIFY_PROC notify, LPVOID context, A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseInstanceNotify (view, notify, context, flags));
   return e;
}
#endif



#if defined(DO_scOptInstanceOpen)
VIEWCALL scOptInstanceOpen (LPRVH rvh, HPIB PIB, WORD link, A4W_FLAGS flags, LPVOID extra, A4W_SIZE size, LPV FAR * lplpView)
{
   ERRNUM e = scOptBaseInstanceOpen (rvh, PIB, link, flags, extra, size, lplpView);
   LPV view = *lplpView;

   if ( ERRNUM_IS_FAILURE (e) )
      return e;

   // Your logic here . . .

   return e;
}
#endif



#if defined(DO_scOptInstanceProtocol)
VIEWCALL scOptInstanceProtocol (LPV view, A4W_FLAGS flags, LP_A4W_FLAGS protocols, LP_A4W_SIZE count)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseInstanceProtocol (view, flags, protocols, count));
   return e;
}
#endif



#if defined(DO_scOptInstanceSecurity)
VIEWCALL scOptInstanceSecurity (LPV view, LP_A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseInstanceSecurity (view, flags));
   return e;
}
#endif



#ifdef DO_scOptKey
VIEWCALL scOptKey       (LPVOID lpView, INT nKeyNo, LPSTR sName, LPSHORT lFields, LPLONG lplKeyFields)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseKey       (lpView, nKeyNo, sName, lFields, lplKeyFields));
   return e;
}
#endif



#ifdef DO_scOptKeys
VIEWCALL scOptKeys      (LPVOID lpView, LPSHORT lpnKeys)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseKeys      (lpView, lpnKeys));
   return e;
}
#endif



#ifdef DO_scOptName
VIEWCALL scOptName      (LPVOID lpView, LONG lField, LPSTR lpsName, LPSTR lpsDesc)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseName      (lpView, lField, lpsName, lpsDesc));
   return e;
}
#endif



#ifdef DO_scOptOpen
VIEWCALL scOptOpen      (HPIB hPIB, WORD wLinkNo, LPVOID FAR * lplpView)
{
   ERRNUM e = scOptBaseOpen      (hPIB, wLinkNo, lplpView);
   LPV view = (LPV) *lplpView;

   if ( ERRNUM_IS_FAILURE (e) )
      return e;

   // Your logic here . . .

   return e;
}
#endif



#ifdef DO_scOptOrder
VIEWCALL scOptOrder     (LPVOID lpView, INT nKey)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseOrder     (lpView, nKey));
   return e;
}
#endif



#ifdef DO_scOptPost
VIEWCALL scOptPost      (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBasePost      (lpView));
   return e;
}
#endif



#ifdef DO_scOptPresents
VIEWCALL scOptPresents  (LPVOID lpView, LONG lField, LPSTR lpsMask, LPSHORT lpnList, LPSHORT lpnCount, LPVOID lpBuffer, INT nSize)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBasePresents  (lpView, lField, lpsMask, lpnList, lpnCount, lpBuffer, nSize));
   return e;
}
#endif



#ifdef DO_scOptProcess
VIEWCALL scOptProcess   (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseProcess   (lpView));
   return e;
}
#endif



#ifdef DO_scOptPut
VIEWCALL scOptPut       (LPVOID lpView, LONG lField, LPSTR lpsBuffer, INT nSize, BOOL bVerify)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBasePut       (lpView, lField, lpsBuffer, nSize, bVerify));
   return e;
}
#endif



#ifdef DO_scOptRead
VIEWCALL scOptRead      (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;
   BOOL found = FALSE;

   CHECK_FETCH_UNROLL (e, found, scOptBaseRead      (lpView));
   if ( !found )
      return ERRNUM_RECORD_NOT_FOUND;
   return e;
}
#endif



#ifdef DO_scOptReadLock
VIEWCALL scOptReadLock  (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;
   BOOL found = FALSE;

   CHECK_FETCH_UNROLL (e, found, scOptBaseReadLock  (lpView));
   if ( !found )
      return ERRNUM_RECORD_NOT_FOUND;
   return e;
}
#endif



#if defined(DO_scOptRecordClear)
VIEWCALL scOptRecordClear (LPV view)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseRecordClear (view));
   return e;
}
#endif



#if defined(DO_scOptRecordGenerate)
VIEWCALL scOptRecordGenerate (LPV view, A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseRecordGenerate (view, flags));
   return e;
}
#endif



#if defined(DO_scOptRevisionCancel)
VIEWCALL scOptRevisionCancel (LPV view, INT level)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseRevisionCancel (view, level));
   return e;
}
#endif



#if defined(DO_scOptRevisionExists)
VIEWCALL scOptRevisionExists (LPV view, INT level, LP_A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseRevisionExists (view, level, flags));
   return e;
}
#endif



#if defined(DO_scOptRevisionPost)
VIEWCALL scOptRevisionPost (LPV view, INT level)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseRevisionPost (view, level));
   return e;
}
#endif



#if defined(DO_scOptRevisionRekey)
VIEWCALL scOptRevisionRekey (LPV view, LPVOID OldKey, LPVOID NewKey, INT size, A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseRevisionRekey (view, OldKey, NewKey, size, flags));
   return e;
}
#endif



#if defined(DO_scOptRevisionUnposted)
VIEWCALL scOptRevisionUnposted (LPV view, INT level, LP_A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseRevisionUnposted (view, level, flags));
   return e;
}
#endif



#ifdef DO_scOptSecurity
VIEWCALL scOptSecurity  (HPIB hPIB, WORD wLinkNo, LPLONG lplPermissions)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseSecurity  (hPIB, wLinkNo, lplPermissions));
   return e;
}
#endif



#if defined(DO_scOptTableEmpty)
VIEWCALL scOptTableEmpty (LPV view)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseTableEmpty (view));
   return e;
}
#endif



#ifdef DO_scOptType
VIEWCALL scOptType      (LPVOID lpView, LONG lField, LPTYPE lptype)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseType      (lpView, lField, lptype));
   return e;
}
#endif



#ifdef DO_scOptUnLock
VIEWCALL scOptUnLock    (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseUnLock    (lpView));
   return e;
}
#endif



#ifdef DO_scOptUpdate
VIEWCALL scOptUpdate    (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

	LPVIEWDEF CSCOM = FindCmp(lpv, CSCOM_CMP);

	if (secGlobalAccess(lpv->hpib, lpv->wLinkNo, lpv->rotoID))
	{
		CHECK_CALL(e, OpenOneView(lpv, CSCOM_CMP));

		CHECK_CALL(e, viewPut(CSCOM->rvh, CSCOM->view, CSCOM_IDX(ORGID), lpv->CompanyInfo.sOrgID, CSCOM_SIZ(ORGID), FALSE));
		if (ERRNUM_IS_SUCCESS(viewRead(CSCOM->rvh, CSCOM->view)))
		{
			CHECK_CALL(e, viewPut(CSCOM->rvh, CSCOM->view, CSCOM_IDX(BRN), FindFieldValue(lpv, SCOPT_IDX(BRN)), CSCOM_SIZ(BRN), FALSE));
			CHECK_CALL(e, viewUpdate(CSCOM->rvh, CSCOM->view));
		}

		CloseOneView(lpv, CSCOM_CMP);

		secNoGlobalAccess(lpv->hpib, lpv->wLinkNo);
	}
	else
	{
		// Should raise error here?
	}

   CHECK_CALL (e, scOptBaseUpdate    (lpView));
   return e;
}
#endif



#ifdef DO_scOptVerify
VIEWCALL scOptVerify    (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scOptBaseVerify    (lpView));
   return e;
}
#endif

// ---



/*--------------------------------------------------------------------------*
 * This section is activated for stub views. Since the intent of stub views *
 * is usually to perform file I/O to destinations other than the database,  *
 * you must enter code which goes to the appropriate destination. Typically *
 * this will be to export using the recioXXXX and xExportXXXX routines.     *
 * If you still need to perform database I/O, copy these corresponding      *
 * functions out of the scOpt.c file replacing the ones here. The semantics  *
 * of these functions must be maintained precisely. As well, each function  *
 * should report any errors on the message stack, though there are some     *
 * exceptions noted. The V structure is fully available and useful; there   *
 * is one change, though: you can #define the symbol TABLEHANDLE to be the  *
 * type appropriate to your stub. Usually it is WORD, and is used to define *
 * the ahTables array member of V.                                          *
 *--------------------------------------------------------------------------*/



#if defined(STUB_VIEW) || defined(DO_fileAdd)

/* Add (new, empty) tables to database */
DB_ERRNUM WINAPI fileAdd (WORD wLinkNo, HPIB hpib)
{
   DB_ERRNUM d = DBS_SUCCESS;

   return d;
}

#endif



#if defined(STUB_VIEW) || defined(DO_fileBegin)

/* Begin a transaction */
DB_ERRNUM WINAPI fileBegin (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;

   return d;
}

#endif



#if defined(STUB_VIEW) || defined(DO_fileCancel)

/* Cancel and discard revisions */
DB_ERRNUM WINAPI fileCancel (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;

   return d;
}

#endif



#if defined(STUB_VIEW) || defined(DO_fileClose)

/* Close tables */
DB_ERRNUM WINAPI fileClose (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;

   return d;
}

#endif



#if defined(STUB_VIEW) || defined(DO_fileCommit)

/* Commit a successful transaction */
DB_ERRNUM WINAPI fileCommit (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;

   return d;
}

#endif



#if defined(STUB_VIEW) || defined(DO_fileCreate)

/* Commence a new set of revisions -- uses V.rev[] */
DB_ERRNUM WINAPI fileCreate (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;

   return d;
}

#endif



#if defined(STUB_VIEW) || defined(DO_fileDelete)

/* Delete a record -- must be locked and in transaction */
DB_ERRNUM WINAPI fileDelete (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;

   return d;
}

#endif



#if defined(STUB_VIEW) || defined(DO_fileDirty)

/* Set *dirty to TRUE if there are pending uncommitted changes */
DB_ERRNUM WINAPI fileDirty (LPV lpv, LPBOOL dirty)
{
   DB_ERRNUM d = DBS_SUCCESS;

   *dirty = FALSE;
   return d;
}

#endif



#if defined(STUB_VIEW) || defined(DO_fileDriverInfo)

/* Fill in the table info for the given table as appropriate */
DB_ERRNUM WINAPI fileDriverInfo (WORD wLinkNo, HPIB hpib, LPDBDRVRINFO info)
{
   DB_ERRNUM d = DBS_SUCCESS;

   return d;
}

#endif



#if defined(STUB_VIEW) || defined(DO_fileDrop)

/* Drop the tables from the database */
DB_ERRNUM WINAPI fileDrop (WORD wLinkNo, HPIB hpib)
{
   DB_ERRNUM d = DBS_SUCCESS;

   return d;
}

#endif



#if defined(STUB_VIEW) || defined(DO_fileEmpty)

/* Remove all records from the table in the most efficient manner */
DB_ERRNUM WINAPI fileEmpty (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;

   return d;
}

#endif



#if defined(STUB_VIEW) || defined(DO_fileError)

/* It may be useful to have error reporting functions for any
   export or sequential file I/O you perform. */
DB_ERRNUM WINAPI fileError (WORD wLinkNo, HPIB hpib, ERRNUM e)
{
   return dbError (wLinkNo, hpib, e);
}

#endif



#if defined(STUB_VIEW) || defined(DO_fileFilterCount)

/* Count the records matching the given filter */
DB_ERRNUM WINAPI fileFilterCount (LPV lpv, LPSTR filter, A4W_FLAGS flags, LP_A4W_SIZE count)
{
   DB_ERRNUM d = DBS_SUCCESS;

   return d;
}

#endif



#if defined(STUB_VIEW) || defined(DO_fileFilterDelete)

/* Delete the records matching the given filter */
DB_ERRNUM WINAPI fileFilterDelete (LPV lpv, LPFILTER filter)
{
   DB_ERRNUM d = DBS_SUCCESS;

   return d;
}

#endif



#if defined(STUB_VIEW) || defined(DO_fileFilterSegs)

/* Set the number of leading segments of the key which will be fixed in searches */
DB_ERRNUM WINAPI fileFilterSegs (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;

   return d;
}

#endif



#if defined(STUB_VIEW) || defined(DO_fileFirst)

/* Locate the first record equal or beyond the current -- uses browse
   direction. Doesn't report DBS_NO_MORE_DATA on the message stack. */
DB_ERRNUM WINAPI fileFirst (LPV lpv, BOOL bLock)
{
   return DBS_NO_MORE_DATA;
}

#endif



#if defined(STUB_VIEW) || defined(DO_fileGet)

/* Locate the record equal to the current. Doesn't report DBS_NOT_FOUND
   on the message stack. */
DB_ERRNUM WINAPI fileGet (LPV lpv, BOOL bLock)
{
   return DBS_NOT_FOUND;
}

#endif



#if defined(STUB_VIEW) || defined(DO_fileInfo)

/* Fill in the table info for the given table as appropriate */
DB_ERRNUM WINAPI fileInfo (WORD wLinkNo, HPIB hpib, INT table, LPDBTABLE info)
{
   DB_ERRNUM d = DBS_SUCCESS;

   return d;
}

#endif



#if defined(STUB_VIEW) || defined(DO_fileInsert)

/* Insert a new record -- must be in transaction and record cannot exist */
DB_ERRNUM WINAPI fileInsert (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;

   return d;
}

#endif



#if defined(STUB_VIEW) || defined(DO_fileIsLocked)

/* Determine if the current record is locked. DBS_RECORD_NOT_LOCKED if not
   (doesn't report on message stack), DBS_SUCCESS if locked. */
DB_ERRNUM WINAPI fileIsLocked (LPV lpv)
{
   return DBS_RECORD_NOT_LOCKED;
}

#endif



#if defined(STUB_VIEW) || defined(DO_fileLinkFlags)

/* Retrieve the flags used to open the link (via dbLinkEx() et al.) */
DB_ERRNUM WINAPI fileLinkFlags (WORD wLinkNo, HPIB hpib, LPWORD flags)
{
   DB_ERRNUM d = DBS_SUCCESS;
   *flags = 0;

   return d;
}

#endif



#if defined(STUB_VIEW) || defined(DO_fileLocate)

/* Determine if the current record exists in the database. Doesn't report
   DBS_NOT_FOUND on the message stack. */
DB_ERRNUM WINAPI fileLocate (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;

   return d;
}

#endif



#if defined(STUB_VIEW) || defined(DO_fileLock)

/* Lock the current record */
DB_ERRNUM WINAPI fileLock (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;

   CHECK_DBCALL (d, fileOptLock (lpv, FALSE));
   return d;
}

#endif



#if defined(STUB_VIEW) || defined(DO_fileNext)

/* Locate the next record beyond the current -- uses browse direction.
   Doesn't report DBS_NO_MORE_DATA on the message stack. */
DB_ERRNUM WINAPI fileNext (LPV lpv, BOOL bLock)
{
   return DBS_NO_MORE_DATA;
}

#endif



#if defined(STUB_VIEW) || defined(DO_fileOpen)

/* Open database tables, preparing them for access */
DB_ERRNUM WINAPI fileOpen (WORD wLinkNo, HPIB hpib, LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;

   return d;
}

#endif



#if defined(STUB_VIEW) || defined(DO_fileOptLock)

/* Lock the current record */
DB_ERRNUM WINAPI fileOptLock (LPV lpv, BOOL optimistic)
{
   DB_ERRNUM d = DBS_SUCCESS;

   return d;
}

#endif



#if defined(STUB_VIEW) || defined(DO_filePrePost)

/* Called by filePost to retrieve the next record to be posted, and let
   PrePostEtc have a crack at it, then actually write it to the database.
   Not of use unless DO_PREPOSTETC is used. Note that return codes must
   be POST_CONTINUE, POST_DONE and POST_ERROR, not DB errors */
REV_ERRNUM WINAPI filePrePost (LPV lpv, LPWORD op, INT r)
{
   return POST_DONE;
}

#endif



#if defined(STUB_VIEW) || defined(DO_filePost)

/* Post the next pending record revision to the database. Note that return
   codes must be POST_CONTINUE, POST_DONE and POST_ERROR, not DB errors */
REV_ERRNUM WINAPI filePost (LPV lpv)
{
   return POST_DONE;
}

#endif



#if defined(STUB_VIEW) || defined(DO_fileReverses)

/* Return DBS_SUCCESS if reverse traversal supported. Doesn't report errors
   on message stack */
DB_ERRNUM WINAPI fileReverses (WORD wLinkNo)
{
   DB_ERRNUM d = DBS_SUCCESS;

   return d;
}

#endif



#if defined(STUB_VIEW) || defined(DO_fileRollback)

/* Abort an unsuccessful transaction */
DB_ERRNUM WINAPI fileRollback (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;

   return d;
}

#endif



#if defined(STUB_VIEW) || defined(DO_fileSelectFields)

/* Define the set of fields to be selected */
DB_ERRNUM WINAPI fileSelectFields (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;

   return d;
}

#endif



#if defined(STUB_VIEW) || defined(DO_fileTransBegin)

/* Begin a transaction */
DB_ERRNUM WINAPI fileTransBegin (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;

   return d;
}

#endif



#if defined(STUB_VIEW) || defined(DO_fileTransCommit)

/* Commit a successful transaction */
DB_ERRNUM WINAPI fileTransCommit (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;

   return d;
}

#endif



#if defined(STUB_VIEW) || defined(DO_fileTransRollback)

/* Abort an unsuccessful transaction */
DB_ERRNUM WINAPI fileTransRollback (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;

   return d;
}

#endif



#if defined(STUB_VIEW) || defined(DO_fileUnLock)

/* Unlock the current record */
DB_ERRNUM WINAPI fileUnLock (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;

   return d;
}

#endif



#if defined(STUB_VIEW) || defined(DO_fileUpdate)

/* Update the database with current record. Must be in transaction and locked */
DB_ERRNUM WINAPI fileUpdate (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;

   return d;
}

#endif



// ---



#if defined(__cplusplus)
}
#endif
