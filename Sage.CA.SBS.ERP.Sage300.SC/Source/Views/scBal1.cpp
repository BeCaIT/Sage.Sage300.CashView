/*--------------------------------------------------------------------

    File        :   scBal1.c
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

#if defined(__cplusplus)
namespace A4WAPI {
#endif

#include "sc.h"
#include "sc.i"

/////////////////////////////////////////////////////////////////////////////


#include "scBal.h"
#include "scBal.i"
#include "scBal1.h"
#include "scBal2.h"



//////////////////////////////////////////////////////////////////////
// +++

// #include "composite .H file(s)"
#include "scOpt.h"



#if BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT>0

// Database table definition -- used by dbOpenTable and dbCreateTable.
// All views must have at least one. Subclass views do not need to
// specify the wFlags or wFirstAuditField members. Views with calculated
// fields should define a separate DBTABLE used to buffer those values;
// only the wRecordLength and wNoOfFields members are then used. Views with
// multiple tables must define one complete DBTABLE for each physical table.
// This structure is passed directly to dbCreateTable.
DBTABLE dbtableDef = {
   {'S','C','B','A','L',' ',' ',' '},
   sizeof (RECORD),
   SCBAL_FLD_COUNT,
   SCBAL_KEY_COUNT,
   FLG_MP_RECORD,
   SCBAL_FLD_AUDIT
};

DBTABLE dbtable2Def = {
	{' ',' ',' ',' ',' ',' ',' ',' '},
	sizeof (RECORD2),
   SCBAL2_FLD_COUNT,
   0,
   0,
   0
};

#endif



#if SCBAL_FLD_COUNT>0

// Database table field definitions. Modify and add fields as required.
// Note that there must be a primary key and audit stamp fields. Exceptions
// to this are for calculated field tables and subclass view tables.
// There must be one DBFIELD array for each DBTABLE structure defined above.
// This structure is passed directly to dbCreateTable.
DBFIELD dbfieldDefs [SCBAL_FLD_COUNT] = {
#include "SCBALF.GEN"
};

DBFIELD dbfield2Defs [SCBAL2_FLD_COUNT] = {
#include "SCBAL2F.GEN"
};

#endif



#if SCBAL_KEY_COUNT>0

// Database table key definitions. This is a variable-length array of WORDs.
// The format consists of a sequence of key definitions, where each key
// definition has three parts: 1) flags, 2) number of segments,
// 3) variable-length list of database field numbers comprising key.
// For each physical database table needed, a ****KeyDef must be defined.
// This structure is passed directly to dbCreateTable.
WORD SCBALKeyDef [] = {
   0, // flags - no special attributes
   3, // one segments
   SCBAL_FLD_RECTYPE, SCBAL_FLD_GRPCOD, SCBAL_FLD_FSCYEAR, // field number (0-origin)
};

//WORD SCBAL2KeyDef [] = {
//   0, // flags - no special attributes
//   1, // one segments
//   SCBAL2_FLD_yourkey, // field number (0-origin)
//};

#endif



#if BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT>0

// List of database table definitions. This array is indexed by the tblNo
// member of the fldIdxMap structure in order to determine a view field's
// table, field and key structure. The prior three structures are
// aggregated into each entry below.
extern TBLMAP tables [BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT] = {
   // DBTABLE     DBFIELD       LPWORD
   {&dbtableDef,  dbfieldDefs,  SCBALKeyDef}, // make one entry for each table
	{&dbtable2Def, dbfield2Defs, NULL      }, // make one entry for each table
};

#endif



#if KEY_COUNT>0

// View key definitions. Used to map from key number to corresponding view
// field information.
extern KEYMAP keyNumMap [KEY_COUNT] = {
   // name rsc ID     segs  array of view field indexes
   {IDS_SCBAL_KEY_NAME, 3,   {SCBAL_IDX(RECTYPE), SCBAL_IDX(GRPCOD), SCBAL_IDX(FSCYEAR)}}, // make one entry for each key
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
   {0,       1,    {SCBAL_IDX(yourkey)}}
};

#endif



#if FLD_IDX_COUNT>0

// Mapping from a view field number to a view field index.
// The ordering of this array is not important. Note that field number 0
// is actually at index 0 in this array.
extern LONG fldNumToIdx [FLD_IDX_COUNT] = {
#include "SCBALX.GEN"
#include "SCBAL2X.GEN"
};

#endif



// Presentation info: For each field having presentation information
// create a set of initialized structures which will be referenced
// in fldIdxMap.
DECLARE_LIST_NUMS(RecType) {
	SC_RECTYPE_NORMAL,
	SC_RECTYPE_PENDING,
};
DECLARE_LIST_STRS(RecType) {
	IDS_SC_RECTYPE_NORMAL,
	IDS_SC_RECTYPE_PENDING,
};
DECLARE_LIST(RecType);


// Field validation function declarations. Those declared here are done as
// examples. Remove, add or edit them as needed.
#include "SCBALV.GEN"
#include "SCBAL2V.GEN"

// Mapping from view field index to view field definition, storage and
// presentation. This array is indexed directly by view field index,
// therefore you must ensure that view field index N is at subscript N here.
// If there are any gaps in the assignment of view field indexes, they
// must be marked in here with a tblNo entry of -1.
extern IDXMAP fldIdxMap [IDXIDX(FLD_IDX_LIMIT)] = {
   {0                  , -1}, // view field index 0 reserved by template
#include "SCBALM.GEN"
#include "SCBAL2M.GEN"
};


#if CMP_COUNT+MAN_CMP_COUNT>0
// Composite names: all composite names must be listed here, including
// implicit and manual compositions. Their ordering is important:
// header, detail, hierarchy, demand, implicit, then manual composites.
#define	SCOPT_CMP	0
#define	GLACGRP_CMP	1

extern CMPNAME cmpNameList [CMP_COUNT+MAN_CMP_COUNT] = {
	{SCOPT_ROTOID, INSTANCE_OPEN_READONLY},
	{GLACGRP_VIEW, INSTANCE_OPEN_READONLY},
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
   {SC_RSC_SCINQUIRY, (SEC_INQUIRE)},
	{SC_RSC_SCPROCESS, (SEC_ADD | SEC_MODIFY | SEC_DELETE | SEC_INQUIRE | SEC_POST)},
};
#endif


#ifdef DO_HEADERETC
// Mapping from detail fields to dependent header fields.
// NOTE: It is assumed the type information of each view field index pair
// matches exactly!
extern DETAILMAP headerFields [DO_HEADERETC] = {
   {SCBAL_IDX(yours), header_IDX(headers)}, // make an entry for each dependent pair
};
#endif



////////////////////////////////////////////////////////////////////////////
// Field validation function declarations. Those defined here are done as
// examples. Remove, add or edit them as needed.



BOOL WINAPI LimitValid (
   LPV lpv,
   LONG lField,
   LPMONEY lpmoneyLimit)
{
   //if ( ..... ) {
   //   ReportError (lpv, SC_some_error_code, "arg1", MAKERSC(IDS_arg2), NULL);
   //   return FALSE;
   //}
   return TRUE;
}



BOOL WINAPI TypeValid (
   LPV lpv,
   LONG lField,
   LPDBSINT lpnType)
{
   //if ( ..... ) {
   //   ReportError (lpv, SC_some_error_code, "arg1", MAKERSC(IDS_arg2), NULL);
   //   return FALSE;
   //}
   return TRUE;
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
   supplied in the scBal.c file needs to be augmented. An example is when
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
    This function is called by scBalInit, scBalRead and scBalFetch.  All
    other field values have been set.  Sets the values for any calculated
    fields.
*/

VIEWBASE CalculateFields (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;


	LPRECORD		lpr = (LPRECORD)FindRecord(lpv)[0];
	LPRECORD2	lpr2 = (LPRECORD2)FindRecord(lpv)[1];

	//
	// Current Period
	//blkCopy(lpr2->curYear, lpv->curYear, SIZEOF_YEAR);
	//lpr2->curPeriod = lpv->curPeriod;
	//
	// Balance Period 1
	moneyAssign(lpr2->balPerd1, lpr->balOpen);
	moneyAdd(lpr2->balPerd1, lpr->netPerd1);
	// Balance Period 2
	moneyAssign(lpr2->balPerd2, lpr2->balPerd1);
	moneyAdd(lpr2->balPerd2, lpr->netPerd2);
	// Balance Period 3
	moneyAssign(lpr2->balPerd3, lpr2->balPerd2);
	moneyAdd(lpr2->balPerd3, lpr->netPerd3);
	// Balance Period 4
	moneyAssign(lpr2->balPerd4, lpr2->balPerd3);
	moneyAdd(lpr2->balPerd4, lpr->netPerd4);
	// Balance Period 5
	moneyAssign(lpr2->balPerd5, lpr2->balPerd4);
	moneyAdd(lpr2->balPerd5, lpr->netPerd5);
	// Balance Period 6
	moneyAssign(lpr2->balPerd6, lpr2->balPerd5);
	moneyAdd(lpr2->balPerd6, lpr->netPerd6);
	// Balance Period 7
	moneyAssign(lpr2->balPerd7, lpr2->balPerd6);
	moneyAdd(lpr2->balPerd7, lpr->netPerd7);
	// Balance Period 8
	moneyAssign(lpr2->balPerd8, lpr2->balPerd7);
	moneyAdd(lpr2->balPerd8, lpr->netPerd8);
	// Balance Period 9
	moneyAssign(lpr2->balPerd9, lpr2->balPerd8);
	moneyAdd(lpr2->balPerd9, lpr->netPerd9);
	// Balance Period 10
	moneyAssign(lpr2->balPerd10, lpr2->balPerd9);
	moneyAdd(lpr2->balPerd10, lpr->netPerd10);
	// Balance Period 11
	moneyAssign(lpr2->balPerd11, lpr2->balPerd10);
	moneyAdd(lpr2->balPerd11, lpr->netPerd11);
	// Balance Period 12
	moneyAssign(lpr2->balPerd12, lpr2->balPerd11);
	moneyAdd(lpr2->balPerd12, lpr->netPerd12);
	// Balance Period 13
	moneyAssign(lpr2->balPerd13, lpr2->balPerd12);
	moneyAdd(lpr2->balPerd13, lpr->netPerd13);
	// Balance Period 14
	moneyAssign(lpr2->balPerd14, lpr2->balPerd13);
	moneyAdd(lpr2->balPerd14, lpr->netPerd14);
	// Balance Period 15
	moneyAssign(lpr2->balPerd15, lpr2->balPerd14);
	moneyAdd(lpr2->balPerd15, lpr->netPerd15);
	//
	// Net Year
	moneyAssign(lpr2->netYear, lpr2->balPerd13);
	moneySub(lpr2->netYear, lpr->balOpen);
	//
	// Net Year-To-Day
	if (lpv->curPeriod > 0)
		moneyAssign(lpr2->netYtd, lpr->netPerd1);
	if (lpv->curPeriod > 1)
		moneyAdd(lpr2->netYtd, lpr->netPerd2);
	if (lpv->curPeriod > 2)
		moneyAdd(lpr2->netYtd, lpr->netPerd3);
	if (lpv->curPeriod > 3)
		moneyAdd(lpr2->netYtd, lpr->netPerd4);
	if (lpv->curPeriod > 4)
		moneyAdd(lpr2->netYtd, lpr->netPerd5);
	if (lpv->curPeriod > 5)
		moneyAdd(lpr2->netYtd, lpr->netPerd6);
	if (lpv->curPeriod > 6)
		moneyAdd(lpr2->netYtd, lpr->netPerd7);
	if (lpv->curPeriod > 7)
		moneyAdd(lpr2->netYtd, lpr->netPerd8);
	if (lpv->curPeriod > 8)
		moneyAdd(lpr2->netYtd, lpr->netPerd9);
	if (lpv->curPeriod > 9)
		moneyAdd(lpr2->netYtd, lpr->netPerd10);
	if (lpv->curPeriod > 10)
		moneyAdd(lpr2->netYtd, lpr->netPerd11);
	if (lpv->curPeriod > 11)
		moneyAdd(lpr2->netYtd, lpr->netPerd12);
	if (lpv->curPeriod > 12)
		moneyAdd(lpr2->netYtd, lpr->netPerd13);

	//
	//// Balance Year-to-day
	moneyAssign(lpr2->balYtd, (PCMONEY)FindFieldValue(lpv, SCBAL_IDX(BALPERD1) - 1 + lpv->curPeriod));
	//if (lpr2->curPeriod > 0)
	//	moneyAssign(lpr2->balYtd, lpr2->balPerd1);
	//else if (lpr2->curPeriod > 1)
	//	moneyAssign(lpr2->balYtd, lpr2->balPerd2);
	//else if (lpr2->curPeriod > 2)
	//	moneyAssign(lpr2->balYtd, lpr2->balPerd3);
	//else if (lpr2->curPeriod > 3)
	//	moneyAssign(lpr2->balYtd, lpr2->balPerd4);
	//else if (lpr2->curPeriod > 4)
	//	moneyAssign(lpr2->balYtd, lpr2->balPerd5);
	//else if (lpr2->curPeriod > 5)
	//	moneyAssign(lpr2->balYtd, lpr2->balPerd6);
	//else if (lpr2->curPeriod > 6)
	//	moneyAssign(lpr2->balYtd, lpr2->balPerd7);
	//else if (lpr2->curPeriod > 7)
	//	moneyAssign(lpr2->balYtd, lpr2->balPerd8);
	//else if (lpr2->curPeriod > 8)
	//	moneyAssign(lpr2->balYtd, lpr2->balPerd9);
	//else if (lpr2->curPeriod > 9)
	//	moneyAssign(lpr2->balYtd, lpr2->balPerd10);
	//else if (lpr2->curPeriod > 10)
	//	moneyAssign(lpr2->balYtd, lpr2->balPerd11);
	//else if (lpr2->curPeriod > 11)
	//	moneyAssign(lpr2->balYtd, lpr2->balPerd12);
	//else if (lpr2->curPeriod > 12)
	//	moneyAssign(lpr2->balYtd, lpr2->balPerd13);

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
// Called within: scBalCancel(), scBalRevisionCancel()

{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, CancelBodyBase (lpv, level));
   return e;
}

#endif



#ifdef DO_COMPOSEETC
/*--------------------------------------------------------------------
    This function is called by scBalCompose.
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
// function during scBalCompose() when the composite's cmpNameList[] entry
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
   ConcurrencyEtc: called when scBalUpdate is done and there is a concurrency
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
         case SCBAL_IDX(yours):
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
// callout takes a view handle, even though scBalCreate() does not. Effectively,
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
    This function is called as a first step by scBalDelete.  Allows
    the view to check any conditions specific to this view that must
    be met before the record may be deleted.  The ERRNUM is returned
    by scBalDelete.
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
// be generated for you from scBalInit

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
    This function is called by scBalGet after validating the field index,
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
   This function is called by scBalInsert, scBalUpdate, and scBalDelete.
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
   Called during scBalOpen, in order to initialize the structural definition
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
    This function is called by scBalInit after all fields have been
    initialized to blanks.  Sets initial values for all non-character
    data types and any strings that should not default to blanks.
*/

VIEWBASE InitNonBlankFields (LPV lpv)
{
   LPRECORD lpr = (LPRECORD) (FindRecord (lpv)) [0];
   ERRNUM e = ERRNUM_SUCCESS;

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
      case SCBAL_IDX(trigger1):
         CHECK_CALL (e, NotifyQueueField (lpv, SCBAL_IDX(dependant1),
                                          INSTANCE_NOTIFY_FIELD_PRESENTATION));
         break;

      case SCBAL_IDX(trigger2):
      case SCBAL_IDX(trigger3):
      case SCBAL_IDX(trigger4):
         CHECK_CALL (e, NotifyQueueField (lpv, SCBAL_IDX(dependant2),
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
// scBalOpen and/or scBalInstanceOpen, since it will simplify maintenance,
// and more importantly will avoid bugs.
VIEWBASE OpenEtc (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;

	//DBDATE dbDate;
	//BCDDATE bcdDate;
	//BOOL bStatus = FALSE;
	//dtGetDate(&dbDate);
	//dtDateToBCD(&dbDate, bcdDate);
	//fscPeriod(lpv->hpib, lpv->wLinkNo, bcdDate, (LPWORD)&lpv->curPeriod, lpv->curYear, &bStatus);

	CHECK_CALL(e, OpenOneView(lpv, GLACGRP_CMP));

	LPVIEWDEF	SCOPT = FindCmp(lpv, SCOPT_CMP);

	CHECK_CALL(e, OpenOneView(lpv, SCOPT_CMP));
	CHECK_CALL(e, viewRead(SCOPT->rvh, SCOPT->view));
	CHECK_CALL(e, viewGet(SCOPT->rvh, SCOPT->view, SCOPT_IDX(CURYEAR), lpv->curYear, SCOPT_SIZ(CURYEAR)));
	CHECK_CALL(e, viewGet(SCOPT->rvh, SCOPT->view, SCOPT_IDX(CURPERIOD), &lpv->curPeriod, SCOPT_SIZ(CURPERIOD)));
	CloseOneView(lpv, SCOPT_CMP);

   return e;
}

#endif



#ifdef DO_PREPOSTETC
/*---------------------------------------------------------------------------
   PrePostEtc: per-detail call-out for scBalPost(). As each change from the
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

VIEWBASE ProcessEtc (
   LPV lpv) // view handle

// Callout invoked by scBalProcess().  Does all processing.

{
   ERRNUM e = ERRNUM_SUCCESS;

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
    This function is called by scBalPut as a last step.  Does any
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

   if ( !lpv->bFieldChanged ) // It may be desireable to process a field
      return e;               // even if it has changed.....
   switch ( lField ) {
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

// This callout is invoked during scBalRevisionRekey(), after each record has
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
   errPutGeneric (lpv->hpib, APPL, MAKERSC (IDS_SCBAL_VIEW_NAME), NULL,
                  area, op, MAKERSC (ERRGEN_CAT_DEFAULT), error, extra);
}

#endif



#if defined(DO_REPORTGENERICERRORVIAPIB)

void WINAPI ReportGenericErrorViaPIB (HPIB pib, WORD area, WORD op, WORD error, LPVOID extra)
{
   CHAR noun [RSC_MAX_MESSAGE];

   errPutGeneric (pib, APPL, MAKERSC (IDS_SCBAL_VIEW_NAME), NULL,
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
// Called within: scBalPost(), scBalRevisionPost()

{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, RevisionInnerPostBase (lpv, level));
   return e;
}

#endif



#ifdef DO_REVPOSTETC
/*---------------------------------------------------------------------------
   revPostEtc: per-detail call-out for scBalPost(). As each change from the
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
         e = scBalYours  (v->view, v->field, v->p);
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
         e = scBalYours  (v->view, v->field, v->p);
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

// This function is called by scBalVerify after each field has been
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

// Called by scBalVerify when a field is a key in a composite
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
// by calling scBalBaseYYYY from within each respecive scBalYYYY here.
// These overrides allow you to process before, after, or instead of
// the original view template behaviour.

// +++



#ifdef DO_scBalAttribs
VIEWCALL scBalAttribs   (LPVOID lpView, LONG lField, LPLONG lpAttributes)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseAttribs   (lpView, lField, lpAttributes));
   return e;
}
#endif



#ifdef DO_scBalBlkGet
VIEWCALL scBalBlkGet    (LPVOID lpView, INT lFields, LPLONG lFieldList, LPSHORT lpnSizeList, LPSTR lpsBuffer)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseBlkGet    (lpView, lFields, lFieldList, lpnSizeList, lpsBuffer));
   return e;
}
#endif



#ifdef DO_scBalBlkPut
VIEWCALL scBalBlkPut    (LPVOID lpView, INT lFields, LPLONG lFieldList, LPSHORT lpnSizeList, LPSTR lpsBuffer, BOOL bVerify)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseBlkPut    (lpView, lFields, lFieldList, lpnSizeList, lpsBuffer, bVerify));
   return e;
}
#endif



#ifdef DO_scBalBrowse
VIEWCALL scBalBrowse    (LPVOID lpView, LPSTR lpsExpression, BOOL bAscending)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseBrowse    (lpView, lpsExpression, bAscending));
   return e;
}
#endif



#ifdef DO_scBalCancel
VIEWCALL scBalCancel    (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseCancel    (lpView));
   return e;
}
#endif



#ifdef DO_scBalClose
VIEWCALL scBalClose     (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

	//CloseOneView(lpv, GLAMF_CMP);
	CloseOneView(lpv, GLACGRP_CMP);

   CHECK_CALL (e, scBalBaseClose     (lpView));
   return e;
}
#endif



#ifdef DO_scBalCmpNames
VIEWCALL scBalCmpNames  (INT roto, LPSTR lpsCompositeNames, LPSHORT lpnCount)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseCmpNames  (roto, lpsCompositeNames, lpnCount));
   return e;
}
#endif



#ifdef DO_scBalCompose
VIEWCALL scBalCompose   (LPVOID lpView, LPVIEWDEF lpvdefComposites)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseCompose   (lpView, lpvdefComposites));
   return e;
}
#endif



#ifdef DO_scBalCreate
VIEWCALL scBalCreate    (HPIB hPIB, WORD wLinkNo)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseCreate    (hPIB, wLinkNo));
   return e;
}
#endif



#ifdef DO_scBalDelete
VIEWCALL scBalDelete    (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseDelete    (lpView));
   return e;
}
#endif



#ifdef DO_scBalDirty
VIEWCALL scBalDirty     (LPVOID lpView, LPBOOL bChanged)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseDirty     (lpView, bChanged));
   return e;
}
#endif



#ifdef DO_scBalDrop
VIEWCALL scBalDrop      (HPIB hPIB, WORD wLinkNo)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseDrop      (hPIB, wLinkNo));
   return e;
}
#endif



#ifdef DO_scBalExists
VIEWCALL scBalExists    (LPVOID lpView, LPBOOL bExists)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseExists    (lpView, bExists));
   return e;
}
#endif



#ifdef DO_scBalFetch
VIEWCALL scBalFetch     (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;
   BOOL found = FALSE;

   CHECK_FETCH_UNROLL (e, found, scBalBaseFetch     (lpView));
   if ( !found )
      return ERRNUM_RECORD_NO_MORE_DATA;
   return e;
}
#endif



#ifdef DO_scBalFetchLock
VIEWCALL scBalFetchLock (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;
   BOOL found = FALSE;

   CHECK_FETCH_UNROLL (e, found, scBalBaseFetchLock (lpView));
   if ( !found )
      return ERRNUM_RECORD_NO_MORE_DATA;
   return e;
}
#endif



#ifdef DO_scBalField
VIEWCALL scBalField     (LPVOID lpView, INT nFldNumber, LPSTR lpsFldName, LPLONG lField)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseField     (lpView, nFldNumber, lpsFldName, lField));
   return e;
}
#endif



#ifdef DO_scBalFieldExists
VIEWCALL scBalFieldExists (
   LPV view,
   LONG lField,
   LP_A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   MaxError (&e, scBalBaseFieldExists (view, lField, flags));
   return e;
}
#endif



#ifdef DO_scBalFieldName
VIEWCALL scBalFieldName (
   LPV view,
   LONG lField,
   LPSTR lpsName,
   LPSTR lpsDesc,
   A4W_SIZE size)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseFieldName (view, lField, lpsName, lpsDesc, size));
   return e;
}
#endif


#ifdef DO_scBalFields
VIEWCALL scBalFields    (LPVOID lpView, LPSHORT lFields)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseFields    (lpView, lFields));
   return e;
}
#endif



#if defined(DO_scBalFilterCount)
VIEWCALL scBalFilterCount (LPV view, LPSTR expression, A4W_FLAGS flags, LP_A4W_SIZE count)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseFilterCount (view, expression, flags, count));
   return e;
}
#endif



#if defined(DO_scBalFilterDelete)
VIEWCALL scBalFilterDelete (LPV view, LPSTR filter, A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseFilterDelete (view, filter, flags));
   return e;
}
#endif



#if defined(DO_scBalFilterFetch)
VIEWCALL scBalFilterFetch (LPV view, A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;
   BOOL found = FALSE;

   CHECK_FETCH_UNROLL (e, found, scBalBaseFilterFetch (view, flags));
   if ( !found )
      return ERRNUM_RECORD_NO_MORE_DATA;
   return e;
}
#endif



#if defined(DO_scBalFilterSelect)
VIEWCALL scBalFilterSelect (LPV view, INT key, LPSTR filter, A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseFilterSelect (view, key, filter, flags));
   return e;
}
#endif



#ifdef DO_scBalGet
VIEWCALL scBalGet       (LPVOID lpView, LONG lField, LPSTR buffer, INT nSize)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseGet       (lpView, lField, buffer, nSize));
   return e;
}
#endif



#ifdef DO_scBalInit
VIEWCALL scBalInit      (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseInit      (lpView));
   return e;
}
#endif



#ifdef DO_scBalInsert
VIEWCALL scBalInsert    (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseInsert    (lpView));
   return e;
}
#endif



#if defined(DO_scBalInstanceFieldList)
VIEWCALL scBalInstanceFieldList (LPV view, A4W_NOTIFY_PROC notify, LPVOID context, A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseInstanceFieldList (view, flags, count, fields));
   return e;
}
#endif



#if defined(DO_scBalInstanceNotify)
VIEWCALL scBalInstanceNotify (LPV view, A4W_NOTIFY_PROC notify, LPVOID context, A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseInstanceNotify (view, notify, context, flags));
   return e;
}
#endif



#if defined(DO_scBalInstanceOpen)
VIEWCALL scBalInstanceOpen (LPRVH rvh, HPIB PIB, WORD link, A4W_FLAGS flags, LPVOID extra, A4W_SIZE size, LPV FAR * lplpView)
{
   ERRNUM e = scBalBaseInstanceOpen (rvh, PIB, link, flags, extra, size, lplpView);
   LPV view = *lplpView;

   if ( ERRNUM_IS_FAILURE (e) )
      return e;

   // Your logic here . . .

   return e;
}
#endif



#if defined(DO_scBalInstanceProtocol)
VIEWCALL scBalInstanceProtocol (LPV view, A4W_FLAGS flags, LP_A4W_FLAGS protocols, LP_A4W_SIZE count)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseInstanceProtocol (view, flags, protocols, count));
   return e;
}
#endif



#if defined(DO_scBalInstanceSecurity)
VIEWCALL scBalInstanceSecurity (LPV view, LP_A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseInstanceSecurity (view, flags));
   return e;
}
#endif



#ifdef DO_scBalKey
VIEWCALL scBalKey       (LPVOID lpView, INT nKeyNo, LPSTR sName, LPSHORT lFields, LPLONG lplKeyFields)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseKey       (lpView, nKeyNo, sName, lFields, lplKeyFields));
   return e;
}
#endif



#ifdef DO_scBalKeys
VIEWCALL scBalKeys      (LPVOID lpView, LPSHORT lpnKeys)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseKeys      (lpView, lpnKeys));
   return e;
}
#endif



#ifdef DO_scBalName
VIEWCALL scBalName      (LPVOID lpView, LONG lField, LPSTR lpsName, LPSTR lpsDesc)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseName      (lpView, lField, lpsName, lpsDesc));
   return e;
}
#endif



#ifdef DO_scBalOpen
VIEWCALL scBalOpen      (HPIB hPIB, WORD wLinkNo, LPVOID FAR * lplpView)
{
   ERRNUM e = scBalBaseOpen      (hPIB, wLinkNo, lplpView);
   LPV view = (LPV) *lplpView;

   if ( ERRNUM_IS_FAILURE (e) )
      return e;

   // Your logic here . . .

   return e;
}
#endif



#ifdef DO_scBalOrder
VIEWCALL scBalOrder     (LPVOID lpView, INT nKey)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseOrder     (lpView, nKey));
   return e;
}
#endif



#ifdef DO_scBalPost
VIEWCALL scBalPost      (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBasePost      (lpView));
   return e;
}
#endif



#ifdef DO_scBalPresents
VIEWCALL scBalPresents  (LPVOID lpView, LONG lField, LPSTR lpsMask, LPSHORT lpnList, LPSHORT lpnCount, LPVOID lpBuffer, INT nSize)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

	//LPVIEWDEF	GLAMF = FindCmp(lpv, GLAMF_CMP);
	LPVIEWDEF	GLACGRP = FindCmp(lpv, GLACGRP_CMP);

	switch (lField)
	{
		//case SCBAL_IDX(ACCTID):
		//	CHECK_CALL(e, viewPresents(GLAMF->rvh, GLAMF->view, GLAMF_IDX(ACCTID), lpsMask, lpnList, lpnCount, (LPSTR)lpBuffer, nSize));
		//	break;

		//case SCBAL_IDX(ACCTFMTTD):
		//	CHECK_CALL(e, viewPresents(GLAMF->rvh, GLAMF->view, GLAMF_IDX(ACCTFMTTD), lpsMask, lpnList, lpnCount, (LPSTR)lpBuffer, nSize));
		//	break;

		case SCBAL_IDX(GRPCOD):
			CHECK_CALL(e, viewPresents(GLACGRP->rvh, GLACGRP->view, GLACGRP_IDX(GRPCOD), lpsMask, lpnList, lpnCount, (LPSTR)lpBuffer, nSize));
			break;

		default:
			CHECK_CALL(e, scBalBasePresents(lpView, lField, lpsMask, lpnList, lpnCount, lpBuffer, nSize));
			break;
	}

   return e;
}
#endif



#ifdef DO_scBalProcess
VIEWCALL scBalProcess   (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseProcess   (lpView));
   return e;
}
#endif



#ifdef DO_scBalPut
VIEWCALL scBalPut       (LPVOID lpView, LONG lField, LPSTR lpsBuffer, INT nSize, BOOL bVerify)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBasePut       (lpView, lField, lpsBuffer, nSize, bVerify));
   return e;
}
#endif



#ifdef DO_scBalRead
VIEWCALL scBalRead      (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;
   BOOL found = FALSE;

   CHECK_FETCH_UNROLL (e, found, scBalBaseRead      (lpView));
   if ( !found )
      return ERRNUM_RECORD_NOT_FOUND;
   return e;
}
#endif



#ifdef DO_scBalReadLock
VIEWCALL scBalReadLock  (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;
   BOOL found = FALSE;

   CHECK_FETCH_UNROLL (e, found, scBalBaseReadLock  (lpView));
   if ( !found )
      return ERRNUM_RECORD_NOT_FOUND;
   return e;
}
#endif



#if defined(DO_scBalRecordClear)
VIEWCALL scBalRecordClear (LPV view)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseRecordClear (view));
   return e;
}
#endif



#if defined(DO_scBalRecordGenerate)
VIEWCALL scBalRecordGenerate (LPV view, A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseRecordGenerate (view, flags));
   return e;
}
#endif



#if defined(DO_scBalRevisionCancel)
VIEWCALL scBalRevisionCancel (LPV view, INT level)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseRevisionCancel (view, level));
   return e;
}
#endif



#if defined(DO_scBalRevisionExists)
VIEWCALL scBalRevisionExists (LPV view, INT level, LP_A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseRevisionExists (view, level, flags));
   return e;
}
#endif



#if defined(DO_scBalRevisionPost)
VIEWCALL scBalRevisionPost (LPV view, INT level)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseRevisionPost (view, level));
   return e;
}
#endif



#if defined(DO_scBalRevisionRekey)
VIEWCALL scBalRevisionRekey (LPV view, LPVOID OldKey, LPVOID NewKey, INT size, A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseRevisionRekey (view, OldKey, NewKey, size, flags));
   return e;
}
#endif



#if defined(DO_scBalRevisionUnposted)
VIEWCALL scBalRevisionUnposted (LPV view, INT level, LP_A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseRevisionUnposted (view, level, flags));
   return e;
}
#endif



#ifdef DO_scBalSecurity
VIEWCALL scBalSecurity  (HPIB hPIB, WORD wLinkNo, LPLONG lplPermissions)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseSecurity  (hPIB, wLinkNo, lplPermissions));
   return e;
}
#endif



#if defined(DO_scBalTableEmpty)
VIEWCALL scBalTableEmpty (LPV view)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseTableEmpty (view));
   return e;
}
#endif



#ifdef DO_scBalType
VIEWCALL scBalType      (LPVOID lpView, LONG lField, LPTYPE lptype)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseType      (lpView, lField, lptype));
   return e;
}
#endif



#ifdef DO_scBalUnLock
VIEWCALL scBalUnLock    (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseUnLock    (lpView));
   return e;
}
#endif



#ifdef DO_scBalUpdate
VIEWCALL scBalUpdate    (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseUpdate    (lpView));
   return e;
}
#endif



#ifdef DO_scBalVerify
VIEWCALL scBalVerify    (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scBalBaseVerify    (lpView));
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
 * functions out of the scBal.c file replacing the ones here. The semantics  *
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
