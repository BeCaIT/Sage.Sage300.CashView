/*--------------------------------------------------------------------

    File        :   scPro1.c
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

#include <pwprint.h>
#include <repcmd.h>

#include <meter.h>

#include <list>

#include <scEmail.h>
#include <scUtil.h>

#if defined(__cplusplus)
namespace A4WAPI {
#endif

#include "sc.h"
#include "sc.i"

/////////////////////////////////////////////////////////////////////////////


#include "scPro.h"
#include "scPro.i"
#include "scPro1.h"
#include "scPro2.h"



//////////////////////////////////////////////////////////////////////
// +++

// #include "composite .H file(s)"
#include	"scOpt.h"
#include "scAcct.h"
#include	"scBal.h"
#include	"scTran.h"
#include "scLoan.h"


#if BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT>0

// Database table definition -- used by dbOpenTable and dbCreateTable.
// All views must have at least one. Subclass views do not need to
// specify the wFlags or wFirstAuditField members. Views with calculated
// fields should define a separate DBTABLE used to buffer those values;
// only the wRecordLength and wNoOfFields members are then used. Views with
// multiple tables must define one complete DBTABLE for each physical table.
// This structure is passed directly to dbCreateTable.
DBTABLE dbtableDef = {
   {' ',' ',' ',' ',' ',' ',' ',' '},
   sizeof (RECORD),
   SCPRO_FLD_COUNT,
   SCPRO_KEY_COUNT,
   FLG_MP_RECORD,
   SCPRO_FLD_AUDIT
};

//DBTABLE dbtable2Def = {
//   "        ",
//   sizeof (RECORD2),
//   SCPRO2_FLD_COUNT,
//   0,
//   0,
//   0
//};

#endif



#if SCPRO_FLD_COUNT>0

// Database table field definitions. Modify and add fields as required.
// Note that there must be a primary key and audit stamp fields. Exceptions
// to this are for calculated field tables and subclass view tables.
// There must be one DBFIELD array for each DBTABLE structure defined above.
// This structure is passed directly to dbCreateTable.
DBFIELD dbfieldDefs [SCPRO_FLD_COUNT] = {
#include "SCPROF.GEN"
};

//DBFIELD dbfield2Defs [SCPRO2_FLD_COUNT] = {
//#include "SCPRO2F.GEN"
//};

#endif



#if SCPRO_KEY_COUNT>0

// Database table key definitions. This is a variable-length array of WORDs.
// The format consists of a sequence of key definitions, where each key
// definition has three parts: 1) flags, 2) number of segments,
// 3) variable-length list of database field numbers comprising key.
// For each physical database table needed, a ****KeyDef must be defined.
// This structure is passed directly to dbCreateTable.
WORD SCPROKeyDef [] = {
   0, // flags - no special attributes
   1, // one segments
   SCPRO_FLD_yourkey, // field number (0-origin)
};

//WORD SCPRO2KeyDef [] = {
//   0, // flags - no special attributes
//   1, // one segments
//   SCPRO2_FLD_yourkey, // field number (0-origin)
//};

#endif



#if BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT>0

// List of database table definitions. This array is indexed by the tblNo
// member of the fldIdxMap structure in order to determine a view field's
// table, field and key structure. The prior three structures are
// aggregated into each entry below.
extern TBLMAP tables [BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT] = {
   // DBTABLE     DBFIELD       LPWORD
   {&dbtableDef,  dbfieldDefs,  NULL		}, // make one entry for each table
// {&dbtable2Def, dbfield2Defs, NULL      }, // make one entry for each table
};

#endif



#if KEY_COUNT>0

// View key definitions. Used to map from key number to corresponding view
// field information.
extern KEYMAP keyNumMap [KEY_COUNT] = {
   // name rsc ID     segs  array of view field indexes
   {IDS_SCPRO_KEY_NAME, 1,   {SCPRO_IDX(yourkey)}}, // make one entry for each key
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
   {0,       1,    {SCPRO_IDX(yourkey)}}
};

#endif



#if FLD_IDX_COUNT>0

// Mapping from a view field number to a view field index.
// The ordering of this array is not important. Note that field number 0
// is actually at index 0 in this array.
extern LONG fldNumToIdx [FLD_IDX_COUNT] = {
#include "SCPROX.GEN"
//#include "SCPRO2X.GEN"
};

#endif



// Presentation info: For each field having presentation information
// create a set of initialized structures which will be referenced
// in fldIdxMap.
//DECLARE_MASK(Name, IDS_SCPRO_NAME_MASK);
//
//DECLARE_LIST_NUMS(Type) {
//   SCPRO_TYPE_PERSONAL,
//   SCPRO_TYPE_BUSINESS,
//};
//DECLARE_LIST_STRS(Type) {
//   IDS_SCPRO_TYPE_PERSONAL,
//   IDS_SCPRO_TYPE_BUSINESS,
//};
//DECLARE_LIST(Type);


// Field validation function declarations. Those declared here are done as
// examples. Remove, add or edit them as needed.
#include "SCPROV.GEN"
//#include "SCPRO2V.GEN"

// Mapping from view field index to view field definition, storage and
// presentation. This array is indexed directly by view field index,
// therefore you must ensure that view field index N is at subscript N here.
// If there are any gaps in the assignment of view field indexes, they
// must be marked in here with a tblNo entry of -1.
extern IDXMAP fldIdxMap [IDXIDX(FLD_IDX_LIMIT)] = {
   {0                  , -1}, // view field index 0 reserved by template
#include "SCPROM.GEN"
//#include "SCPRO2M.GEN"
};


#if CMP_COUNT+MAN_CMP_COUNT>0
// Composite names: all composite names must be listed here, including
// implicit and manual compositions. Their ordering is important:
// header, detail, hierarchy, demand, implicit, then manual composites.
#define	SCOPT_CMP	0
#define	SCACCT_CMP	1
#define	SCBAL_CMP	2
#define	SCTRAN_CMP	3
#define	SCLOAN_CMP	4

extern CMPNAME cmpNameList [CMP_COUNT+MAN_CMP_COUNT] = {
   {SCOPT_ROTOID},
	{SCACCT_ROTOID, INSTANCE_OPEN_READONLY},
	{SCBAL_ROTOID},
	{SCTRAN_ROTOID},
	{SCLOAN_ROTOID},
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
	{SC_RSC_SCPROCESS	, (SEC_ADD | SEC_MODIFY | SEC_DELETE | SEC_INQUIRE | SEC_POST)},
};
#endif


#ifdef DO_HEADERETC
// Mapping from detail fields to dependent header fields.
// NOTE: It is assumed the type information of each view field index pair
// matches exactly!
extern DETAILMAP headerFields [DO_HEADERETC] = {
   {SCPRO_IDX(yours), header_IDX(headers)}, // make an entry for each dependent pair
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
   supplied in the scPro.c file needs to be augmented. An example is when
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
    This function is called by scProInit, scProRead and scProFetch.  All
    other field values have been set.  Sets the values for any calculated
    fields.
*/

VIEWBASE CalculateFields (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;

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
// Called within: scProCancel(), scProRevisionCancel()

{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, CancelBodyBase (lpv, level));
   return e;
}

#endif



#ifdef DO_COMPOSEETC
/*--------------------------------------------------------------------
    This function is called by scProCompose.
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
// function during scProCompose() when the composite's cmpNameList[] entry
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
   ConcurrencyEtc: called when scProUpdate is done and there is a concurrency
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
         case SCPRO_IDX(yours):
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
// callout takes a view handle, even though scProCreate() does not. Effectively,
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
    This function is called as a first step by scProDelete.  Allows
    the view to check any conditions specific to this view that must
    be met before the record may be deleted.  The ERRNUM is returned
    by scProDelete.
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
// be generated for you from scProInit

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
    This function is called by scProGet after validating the field index,
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
   This function is called by scProInsert, scProUpdate, and scProDelete.
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
   Called during scProOpen, in order to initialize the structural definition
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
    This function is called by scProInit after all fields have been
    initialized to blanks.  Sets initial values for all non-character
    data types and any strings that should not default to blanks.
*/

VIEWBASE InitNonBlankFields (LPV lpv)
{
   LPRECORD lpr = (LPRECORD) (FindRecord (lpv)) [0];
   ERRNUM e = ERRNUM_SUCCESS;

	DBDATE dbDate;
	dtGetDate(&dbDate);

	dtDateToBCD(&dbDate, lpr->processDt);

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
      case SCPRO_IDX(trigger1):
         CHECK_CALL (e, NotifyQueueField (lpv, SCPRO_IDX(dependant1),
                                          INSTANCE_NOTIFY_FIELD_PRESENTATION));
         break;

      case SCPRO_IDX(trigger2):
      case SCPRO_IDX(trigger3):
      case SCPRO_IDX(trigger4):
         CHECK_CALL (e, NotifyQueueField (lpv, SCPRO_IDX(dependant2),
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
// scProOpen and/or scProInstanceOpen, since it will simplify maintenance,
// and more importantly will avoid bugs.
VIEWBASE OpenEtc (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;

	//LPVIEWDEF SCOPT = FindCmp(lpv, SCOPT_CMP);
	LPVIEWDEF SCBAL = FindCmp(lpv, SCBAL_CMP);
	LPVIEWDEF SCTRAN = FindCmp(lpv, SCTRAN_CMP);
	LPVIEWDEF SCLOAN = FindCmp(lpv, SCLOAN_CMP);

	INT sysAccess = SYSACCESS_POST;

	CHECK_CALL(e, OpenOneView(lpv, SCOPT_CMP));
	CHECK_CALL(e, OpenOneView(lpv, SCACCT_CMP));
	CHECK_CALL(e, OpenOneView(lpv, SCBAL_CMP));
	CHECK_CALL(e, viewPut(SCBAL->rvh, SCBAL->view, SYSACCESS_IDX, &sysAccess, SIZEOF_SYSACCESS, FALSE));
	CHECK_CALL(e, OpenOneView(lpv, SCTRAN_CMP));
	CHECK_CALL(e, viewPut(SCTRAN->rvh, SCTRAN->view, SYSACCESS_IDX, &sysAccess, SIZEOF_SYSACCESS, FALSE));
	CHECK_CALL(e, OpenOneView(lpv, SCLOAN_CMP));
	CHECK_CALL(e, viewPut(SCLOAN->rvh, SCLOAN->view, SYSACCESS_IDX, &sysAccess, SIZEOF_SYSACCESS, FALSE));

   return e;
}

#endif



#ifdef DO_PREPOSTETC
/*---------------------------------------------------------------------------
   PrePostEtc: per-detail call-out for scProPost(). As each change from the
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

VIEWBASE ProcessSCBAL(
	LPV lpv,
	WORD wYear,
	LPMETER meter)
{
	ERRNUM e = ERRNUM_SUCCESS;

	LPVIEWDEF SCBAL = FindCmp(lpv, SCBAL_CMP);

	LONG	idxSCBALData[19] = { SCBAL_IDX(RECTYPE), SCBAL_IDX(GRPCOD), SCBAL_IDX(FSCYEAR), SCBAL_IDX(BALOPEN),
										SCBAL_IDX(NETPERD1), SCBAL_IDX(NETPERD2), SCBAL_IDX(NETPERD3), SCBAL_IDX(NETPERD4), SCBAL_IDX(NETPERD5), 
										SCBAL_IDX(NETPERD6), SCBAL_IDX(NETPERD7), SCBAL_IDX(NETPERD8), SCBAL_IDX(NETPERD9), SCBAL_IDX(NETPERD10),
										SCBAL_IDX(NETPERD11), SCBAL_IDX(NETPERD12), SCBAL_IDX(NETPERD13), SCBAL_IDX(NETPERD14), SCBAL_IDX(NETPERD15), };
	SHORT	sizSCBALData[19] = { SCBAL_SIZ(RECTYPE), SCBAL_SIZ(GRPCOD), SCBAL_SIZ(FSCYEAR), SCBAL_SIZ(BALOPEN),
										SCBAL_SIZ(NETPERD1), SCBAL_SIZ(NETPERD2), SCBAL_SIZ(NETPERD3), SCBAL_SIZ(NETPERD4), SCBAL_SIZ(NETPERD5),
										SCBAL_SIZ(NETPERD6), SCBAL_SIZ(NETPERD7), SCBAL_SIZ(NETPERD8), SCBAL_SIZ(NETPERD9), SCBAL_SIZ(NETPERD10),
										SCBAL_SIZ(NETPERD11), SCBAL_SIZ(NETPERD12), SCBAL_SIZ(NETPERD13), SCBAL_SIZ(NETPERD14), SCBAL_SIZ(NETPERD15), };
	BYTE	bufSCBALData[SCBAL_SIZ(RECTYPE) + SCBAL_SIZ(GRPCOD) + SCBAL_SIZ(FSCYEAR) + SCBAL_SIZ(BALOPEN) +
							 SCBAL_SIZ(NETPERD1) + SCBAL_SIZ(NETPERD2) + SCBAL_SIZ(NETPERD3) + SCBAL_SIZ(NETPERD4) + SCBAL_SIZ(NETPERD5) +
							 SCBAL_SIZ(NETPERD6) + SCBAL_SIZ(NETPERD7) + SCBAL_SIZ(NETPERD8) + SCBAL_SIZ(NETPERD9) + SCBAL_SIZ(NETPERD10) +
							 SCBAL_SIZ(NETPERD11) + SCBAL_SIZ(NETPERD12) + SCBAL_SIZ(NETPERD13) + SCBAL_SIZ(NETPERD14) + SCBAL_SIZ(NETPERD15)];

	CHAR sMeterLabelBuffer[METER_LABEL_SIZE + 1];
	CHAR sMeterLabel[METER_LABEL_SIZE + 1];

	CHAR sQuery[MAX_RECORD_LENGTH + 1];
	CHAR sQueryCount[MAX_RECORD_LENGTH + 1];

	sprintf_s(sQuery,
		"select\n"
		"	cast(0 as smallint) RECTYPE\n"
		"	,GLACGRP.GRPCOD\n"
		"	,GLAFS.FSCSYR FSCYEAR\n"
		"	,cast(isnull(sum(GLAFS.OPENBAL), 0) as decimal(19, 3)) BALOPEN\n"
		"	,cast(isnull(sum(GLAFS.NETPERD1), 0) as decimal(19, 3)) NETPERD1\n"
		"	,cast(isnull(sum(GLAFS.NETPERD2), 0) as decimal(19, 3)) NETPERD2\n"
		"	,cast(isnull(sum(GLAFS.NETPERD3), 0) as decimal(19, 3)) NETPERD3\n"
		"	,cast(isnull(sum(GLAFS.NETPERD4), 0) as decimal(19, 3)) NETPERD4\n"
		"	,cast(isnull(sum(GLAFS.NETPERD5), 0) as decimal(19, 3)) NETPERD5\n"
		"	,cast(isnull(sum(GLAFS.NETPERD6), 0) as decimal(19, 3)) NETPERD6\n"
		"	,cast(isnull(sum(GLAFS.NETPERD7), 0) as decimal(19, 3)) NETPERD7\n"
		"	,cast(isnull(sum(GLAFS.NETPERD8), 0) as decimal(19, 3)) NETPERD8\n"
		"	,cast(isnull(sum(GLAFS.NETPERD9), 0) as decimal(19, 3)) NETPERD9\n"
		"	,cast(isnull(sum(GLAFS.NETPERD10), 0) as decimal(19, 3)) NETPERD10\n"
		"	,cast(isnull(sum(GLAFS.NETPERD11), 0) as decimal(19, 3)) NETPERD11\n"
		"	,cast(isnull(sum(GLAFS.NETPERD12), 0) as decimal(19, 3)) NETPERD12\n"
		"	,cast(isnull(sum(GLAFS.NETPERD13), 0) as decimal(19, 3)) NETPERD13\n"
		"	,cast(isnull(sum(GLAFS.NETPERD14), 0) as decimal(19, 3)) NETPERD14\n"
		"	,cast(isnull(sum(GLAFS.NETPERD15), 0) as decimal(19, 3)) NETPERD15\n"
		"from\n"
		"	GLAMF\n"
		"	inner join GLACGRP on(GLAMF.ACCTGRPCOD = GLACGRP.ACCTGRPCOD)\n"
		"	inner join GLAFS on(GLAMF.ACCTID = GLAFS.ACCTID and GLAFS.FSCSDSG = 'A' and GLAFS.CURNTYPE = 'F')\n"
		"where\n"
		"	GLAFS.FSCSDSG = 'A' and GLAFS.CURNTYPE = 'F' and GLAFS.FSCSYR in(%d, %d)\n"
		"group by\n"
		"	GLACGRP.GRPCOD\n"
		"	,GLAFS.FSCSYR\n",
		wYear, wYear - 1);
	sprintf_s(sQueryCount,
		"select count(*) from (%s) as SCBAL", sQuery);

	CHECK_CALL(e, viewRecordClear((LPRVH)SCBAL->rvh, SCBAL->view));
	CHECK_CALL(e, viewTableEmpty((LPRVH)SCBAL->rvh, SCBAL->view));

	DBQHANDLE hQuery;
	WORD wFetched = 1;
	A4W_SIZE lCount = 0;
	A4W_SIZE lProcessed = 0;

	CHECK_CALL(e, ErrorMapDatabaseToExtended(lpv->wLinkNo, dbQueryRun(lpv->wLinkNo, sQueryCount, 0, &hQuery)));
	CHECK_CALL(e, ErrorMapDatabaseToExtended(lpv->wLinkNo, dbQueryResultFetch(lpv->wLinkNo, hQuery, &lCount, (WORD)1, &wFetched)));
	CHECK_CALL(e, ErrorMapDatabaseToExtended(lpv->wLinkNo, dbQueryResultFree(lpv->wLinkNo, hQuery)));

	if (lCount > 0)
	{
		LoadRsc(lpv->hpib, MAKERSC(IDS_SCPRO_METER_SCBAL_NORMAL_LABEL), METER_LABEL_SIZE, sMeterLabelBuffer, TRUE);

		CHECK_CALL(e, ErrorMapDatabaseToExtended(lpv->wLinkNo, dbQueryRun(lpv->wLinkNo, sQuery, 0, &hQuery)));
		while (DB_ERRNUM_IS_SUCCESS(dbQueryResultFetch(lpv->wLinkNo, hQuery, bufSCBALData, (WORD)1, &wFetched)))
		{
			sprintf_s(sMeterLabel, sMeterLabelBuffer, 
				(DBSINT)bufSCBALData[SCBAL_SIZ(RECTYPE)],
				&bufSCBALData[SCBAL_SIZ(RECTYPE) + SCBAL_SIZ(GRPCOD)]);
			meterSetLabel(meter, sMeterLabel);

			CHECK_CALL(e, viewRecordGenerate((LPRVH)SCBAL->rvh, SCBAL->view, RECORD_GENERATE_NOINSERT));
			CHECK_CALL(e, viewBlkPut(SCBAL->rvh, SCBAL->view, 19, idxSCBALData, sizSCBALData, bufSCBALData, FALSE));
			CHECK_CALL(e, viewInsert(SCBAL->rvh, SCBAL->view));

			lProcessed++;

			meterSetPercent(meter, (WORD)(lProcessed * 100 / lCount));
		}
		CHECK_CALL(e, ErrorMapDatabaseToExtended(lpv->wLinkNo, dbQueryResultFree(lpv->wLinkNo, hQuery)));
	}

	return e;
}


VIEWBASE ProcessSCTRAN(
	LPV lpv,
	LPSTR sDate,
	LPMETER meter)
{
	ERRNUM e = ERRNUM_SUCCESS;

	LPVIEWDEF SCTRAN = FindCmp(lpv, SCTRAN_CMP);

	LONG	idxSCTRANData[11] = { SCTRAN_IDX(RECTYPE), SCTRAN_IDX(SOURCE), SCTRAN_IDX(CUSTVEND), SCTRAN_IDX(DOCNUM), SCTRAN_IDX(PAYMENTNBR),
										 SCTRAN_IDX(TRANSTYPE), SCTRAN_IDX(DOCDATE), SCTRAN_IDX(DOCDESC), SCTRAN_IDX(DATEDUE),
										 SCTRAN_IDX(AMTDUEHC), SCTRAN_IDX(AMTPAIDHC) };
	SHORT	sizSCTRANData[11] = { SCTRAN_SIZ(RECTYPE), SCTRAN_SIZ(SOURCE), SCTRAN_SIZ(CUSTVEND), SCTRAN_SIZ(DOCNUM), SCTRAN_SIZ(PAYMENTNBR),
										 SCTRAN_SIZ(TRANSTYPE), SCTRAN_SIZ(DOCDATE), SCTRAN_SIZ(DOCDESC), SCTRAN_SIZ(DATEDUE),
										 SCTRAN_SIZ(AMTDUEHC), SCTRAN_SIZ(AMTPAIDHC) };
	BYTE	bufSCTRANDATA[SCTRAN_SIZ(RECTYPE) + SCTRAN_SIZ(SOURCE) + SCTRAN_SIZ(CUSTVEND) + SCTRAN_SIZ(DOCNUM) + SCTRAN_SIZ(PAYMENTNBR)
							+ SCTRAN_SIZ(TRANSTYPE) + SCTRAN_SIZ(DOCDATE) + SCTRAN_SIZ(DOCDESC) + SCTRAN_SIZ(DATEDUE)
							+ SCTRAN_SIZ(AMTDUEHC) + SCTRAN_SIZ(AMTPAIDHC)];

	CHAR sMeterLabelBuffer[METER_LABEL_SIZE + 1];
	CHAR sMeterLabel[METER_LABEL_SIZE + 1];

	CHAR sQuery[MAX_RECORD_LENGTH + 1];
	CHAR sQueryCount[MAX_RECORD_LENGTH + 1];

	sprintf_s(sQuery,
		"select\r\n"
		"	cast(0 as smallint) RECTYPE, 'AR' SOURCE, AROBS.IDCUST, AROBS.IDINVC, AROBS.CNTPAYM, AROBS.TXTTRXTYPE, AROBS.DATEINVC, AROBL.DESCINVC DOCDESC, AROBS.DATEDUE\r\n"
		"	,cast(AROBS.AMTDUEHC as decimal(19, 3)) AMTDUEHC, cast(coalesce(sum(AROBP.AMTPAYMHC), 0) as decimal(19, 3)) AMTPAIDHC\r\n"
		"from\r\n"
		"	AROBS\r\n"
		"	inner join AROBL on (AROBS.IDCUST = AROBL.IDCUST and AROBS.IDINVC = AROBL.IDINVC)\r\n"
		"	left join AROBP on(AROBS.IDCUST = AROBP.IDCUST and AROBS.IDINVC = AROBP.IDINVC and AROBS.CNTPAYM = AROBP.CNTPAYMNBR and ((AROBP.DATERMIT = 0 and AROBP.DATEBUS <= %s) or (AROBP.DATERMIT <= %s)))\r\n"
		"group by AROBS.IDCUST, AROBS.IDINVC, AROBS.CNTPAYM, AROBS.DATEDUE, AROBS.TXTTRXTYPE, AROBS.DATEINVC, AROBL.DESCINVC, AROBS.AMTDUEHC\r\n"
		"having (AROBS.AMTDUEHC + coalesce(sum(AROBP.AMTPAYMHC), 0)) <> 0\r\n"
		"union all\r\n"
		"select\r\n"
		"	cast(0 as smallint) RECTYPE, 'AP' SOURCE, APOBS.IDVEND, APOBS.IDINVC, APOBS.CNTPAYM, APOBS.TXTTRXTYPE, APOBS.DATEINVC, APOBL.DESCINVC DOCDESC, APOBS.DATEDUE\r\n"
		"	,cast(-APOBS.AMTDUEHC as decimal(19, 3)) AMTDUEHC, -cast(coalesce(sum(APOBP.AMTPAYMHC), 0) as decimal(19, 3)) AMTPAIDHC\r\n"
		"from\r\n"
		"	APOBS\r\n"
		"	inner join APOBL on (APOBS.IDVEND = APOBL.IDVEND and APOBS.IDINVC = APOBL.IDINVC)\r\n"
		"	left join APOBP on(APOBS.IDVEND = APOBP.IDVEND and APOBS.IDINVC = APOBP.IDINVC and APOBS.CNTPAYM = APOBP.CNTPAYMNBR and ((APOBP.DATERMIT = 0 and APOBP.DATEBUS <= %s) or (APOBP.DATERMIT <= %s)))\r\n"
		"group by APOBS.IDVEND, APOBS.IDINVC, APOBS.CNTPAYM, APOBS.DATEDUE, APOBS.TXTTRXTYPE, APOBS.DATEINVC, APOBL.DESCINVC, APOBS.AMTDUEHC\r\n"
		"having (APOBS.AMTDUEHC + coalesce(sum(APOBP.AMTPAYMHC), 0)) <> 0",
		sDate, sDate, sDate, sDate);
	sprintf_s(sQueryCount,
		"select count(*) from (%s) as SCTRAN", sQuery);

	CHECK_CALL(e, viewRecordClear((LPRVH)SCTRAN->rvh, SCTRAN->view));
	CHECK_CALL(e, viewFilterDelete((LPRVH)SCTRAN->rvh, SCTRAN->view, (LPSTR)"(SOURCE != \"SC\")", FILTER_DELETE_SIMULATE));

	DBQHANDLE hQuery;
	WORD wFetched = 1;
	A4W_SIZE lCount = 0;
	A4W_SIZE lProcessed = 0;

	CHECK_CALL(e, ErrorMapDatabaseToExtended(lpv->wLinkNo, dbQueryRun(lpv->wLinkNo, sQueryCount, 0, &hQuery)));
	CHECK_CALL(e, ErrorMapDatabaseToExtended(lpv->wLinkNo, dbQueryResultFetch(lpv->wLinkNo, hQuery, &lCount, (WORD)1, &wFetched)));
	CHECK_CALL(e, ErrorMapDatabaseToExtended(lpv->wLinkNo, dbQueryResultFree(lpv->wLinkNo, hQuery)));

	if (lCount > 0)
	{
		LoadRsc(lpv->hpib, MAKERSC(IDS_SCPRO_METER_SCTRAN_NORMAL_LABEL), METER_LABEL_SIZE, sMeterLabelBuffer, TRUE);

		CHECK_CALL(e, ErrorMapDatabaseToExtended(lpv->wLinkNo, dbQueryRun(lpv->wLinkNo, sQuery, 0, &hQuery)));
		while (DB_ERRNUM_IS_SUCCESS(dbQueryResultFetch(lpv->wLinkNo, hQuery, bufSCTRANDATA, (WORD)1, &wFetched)))
		{
			sprintf_s(sMeterLabel, sMeterLabelBuffer,
				&bufSCTRANDATA[SCTRAN_SIZ(RECTYPE)],
				&bufSCTRANDATA[SCTRAN_SIZ(RECTYPE) + SCTRAN_SIZ(SOURCE)],
				&bufSCTRANDATA[SCTRAN_SIZ(RECTYPE) + SCTRAN_SIZ(SOURCE) + SCTRAN_SIZ(CUSTVEND)]);
			meterSetLabel(meter, sMeterLabel);

			CHECK_CALL(e, viewRecordGenerate((LPRVH)SCTRAN->rvh, SCTRAN->view, RECORD_GENERATE_NOINSERT));
			CHECK_CALL(e, viewBlkPut(SCTRAN->rvh, SCTRAN->view, 11, idxSCTRANData, sizSCTRANData, bufSCTRANDATA, FALSE));
			CHECK_CALL(e, viewInsert(SCTRAN->rvh, SCTRAN->view));

			lProcessed++;

			meterSetPercent(meter, (WORD)(lProcessed * 100 / lCount));
		}
		CHECK_CALL(e, ErrorMapDatabaseToExtended(lpv->wLinkNo, dbQueryResultFree(lpv->wLinkNo, hQuery)));
	}

	return e;
}


BOOL WINAPI CheckThreshold (
	LPV lpv)
{
	ERRNUM e = ERRNUM_SUCCESS;

	LPVIEWDEF SCOPT = FindCmp(lpv, SCOPT_CMP);
	LPVIEWDEF SCACCT = FindCmp(lpv, SCACCT_CMP);
	LPVIEWDEF SCBAL = FindCmp(lpv, SCBAL_CMP);
	LPVIEWDEF SCTRAN = FindCmp(lpv, SCTRAN_CMP);

	MONEY mnyThreshold;
	CHECK_CALL(e, viewGet(SCOPT->rvh, SCOPT->view, SCOPT_IDX(CBALTHRHD), mnyThreshold, SCOPT_SIZ(CBALTHRHD)));

	//
	/// Check current balance
	MONEY mnyCurrentBalance;
	moneyInit(mnyCurrentBalance);
	CHECK_CALL(e, viewRecordClear((LPRVH)SCACCT->rvh, SCACCT->view));
	CHECK_CALL(e, viewBrowse(SCACCT->rvh, SCACCT->view, (LPSTR)"", TRUE));
	while (ERRNUM_IS_SUCCESS(viewFetch(SCACCT->rvh, SCACCT->view)))
	{
		DBSINT wInclude = 0;
		MONEY mnyAccountBalance;

		CHECK_CALL(e, viewGet(SCACCT->rvh, SCACCT->view, SCACCT_IDX(INCLUDE), &wInclude, SCACCT_SIZ(INCLUDE)));
		if (wInclude == SC_YES)
		{
			CHECK_CALL(e, viewGet(SCACCT->rvh, SCACCT->view, SCACCT_IDX(AMTBALHC), mnyAccountBalance, SCACCT_SIZ(AMTBALHC)));
			moneyAdd(mnyCurrentBalance, mnyAccountBalance);
		}
	}

	//
	////
	MONEY mnyPeriod0Net;
	MONEY mnyPeriod1Net;
	MONEY mnyPeriod2Net;
	MONEY mnyPeriod3Net;
	MONEY mnyPeriod4Net;
	MONEY mnyPeriod5Net;
	MONEY mnyPeriod6Net;
	MONEY mnyPeriod0Balance;
	MONEY mnyPeriod1Balance;
	MONEY mnyPeriod2Balance;
	MONEY mnyPeriod3Balance;
	MONEY mnyPeriod4Balance;
	MONEY mnyPeriod5Balance;
	MONEY mnyPeriod6Balance;

	moneyInit(mnyPeriod0Net);
	moneyInit(mnyPeriod1Net);
	moneyInit(mnyPeriod2Net);
	moneyInit(mnyPeriod3Net);
	moneyInit(mnyPeriod4Net);
	moneyInit(mnyPeriod5Net);
	moneyInit(mnyPeriod6Net);
	moneyInit(mnyPeriod0Balance);
	moneyInit(mnyPeriod1Balance);
	moneyInit(mnyPeriod2Balance);
	moneyInit(mnyPeriod3Balance);
	moneyInit(mnyPeriod4Balance);
	moneyInit(mnyPeriod5Balance);
	moneyInit(mnyPeriod6Balance);

	CHECK_CALL(e, viewRecordClear((LPRVH)SCTRAN->rvh, SCTRAN->view));
	//CHECK_CALL(e, viewInit((LPRVH)SCTRAN->rvh, SCTRAN->view));
	CHECK_CALL(e, viewFilterSelect((LPRVH)SCTRAN->rvh, SCTRAN->view, 0, (LPSTR)"", FILTER_SELECT_FROMSTART | FILTER_SELECT_ASCENDING));
	while (ERRNUM_IS_SUCCESS(viewFetch(SCTRAN->rvh, SCTRAN->view)))
	{
		MONEY mnyPeriod0;
		MONEY mnyPeriod1;
		MONEY mnyPeriod2;
		MONEY mnyPeriod3;
		MONEY mnyPeriod4;
		MONEY mnyPeriod5;
		MONEY mnyPeriod6;

		moneyInit(mnyPeriod0);
		moneyInit(mnyPeriod1);
		moneyInit(mnyPeriod2);
		moneyInit(mnyPeriod3);
		moneyInit(mnyPeriod4);
		moneyInit(mnyPeriod5);
		moneyInit(mnyPeriod6);

		CHECK_CALL(e, viewGet(SCTRAN->rvh, SCTRAN->view, SCTRAN_IDX(AMTPRD0HC), mnyPeriod0, SCTRAN_SIZ(AMTPRD0HC)));
		CHECK_CALL(e, viewGet(SCTRAN->rvh, SCTRAN->view, SCTRAN_IDX(AMTPRD1HC), mnyPeriod1, SCTRAN_SIZ(AMTPRD1HC)));
		CHECK_CALL(e, viewGet(SCTRAN->rvh, SCTRAN->view, SCTRAN_IDX(AMTPRD2HC), mnyPeriod2, SCTRAN_SIZ(AMTPRD2HC)));
		CHECK_CALL(e, viewGet(SCTRAN->rvh, SCTRAN->view, SCTRAN_IDX(AMTPRD3HC), mnyPeriod3, SCTRAN_SIZ(AMTPRD3HC)));
		CHECK_CALL(e, viewGet(SCTRAN->rvh, SCTRAN->view, SCTRAN_IDX(AMTPRD4HC), mnyPeriod4, SCTRAN_SIZ(AMTPRD4HC)));
		CHECK_CALL(e, viewGet(SCTRAN->rvh, SCTRAN->view, SCTRAN_IDX(AMTPRD5HC), mnyPeriod5, SCTRAN_SIZ(AMTPRD5HC)));
		CHECK_CALL(e, viewGet(SCTRAN->rvh, SCTRAN->view, SCTRAN_IDX(AMTPRD6HC), mnyPeriod6, SCTRAN_SIZ(AMTPRD6HC)));

		moneyAdd(mnyPeriod0Net, mnyPeriod0);
		moneyAdd(mnyPeriod1Net, mnyPeriod1);
		moneyAdd(mnyPeriod2Net, mnyPeriod2);
		moneyAdd(mnyPeriod3Net, mnyPeriod3);
		moneyAdd(mnyPeriod4Net, mnyPeriod4);
		moneyAdd(mnyPeriod5Net, mnyPeriod5);
		moneyAdd(mnyPeriod6Net, mnyPeriod6);
	}

	moneyAssign(mnyPeriod0Balance, mnyCurrentBalance);
	moneyAdd(mnyPeriod0Balance, mnyPeriod0Net);
	//
	moneyAssign(mnyPeriod1Balance, mnyPeriod0Balance);
	moneyAdd(mnyPeriod1Balance, mnyPeriod1Net);
	//
	moneyAssign(mnyPeriod2Balance, mnyPeriod1Balance);
	moneyAdd(mnyPeriod2Balance, mnyPeriod2Net);
	//
	moneyAssign(mnyPeriod3Balance, mnyPeriod2Balance);
	moneyAdd(mnyPeriod3Balance, mnyPeriod3Net);
	//
	moneyAssign(mnyPeriod4Balance, mnyPeriod3Balance);
	moneyAdd(mnyPeriod4Balance, mnyPeriod4Net);
	//
	moneyAssign(mnyPeriod5Balance, mnyPeriod4Balance);
	moneyAdd(mnyPeriod5Balance, mnyPeriod5Net);
	//
	moneyAssign(mnyPeriod6Balance, mnyPeriod5Balance);
	moneyAdd(mnyPeriod6Balance, mnyPeriod6Net);


	CHAR sMoney[SIZEOF_BCDSTR + 1];
	//
	////
	moneyToStr(mnyThreshold, sMoney, SIZEOF_BCDSTR, 3);
	rvspyPrint("[Threshold Check] - Threshold = %.22s", sMoney);
	//
	moneyToStr(mnyCurrentBalance, sMoney, SIZEOF_BCDSTR, 3);
	rvspyPrint("[Threshold Check] - Opening Balance = %.22s", sMoney);
	//
	moneyToStr(mnyPeriod0Net, sMoney, SIZEOF_BCDSTR, 3);
	rvspyPrint("[Threshold Check] - Current net = %.22s", sMoney);
	//
	moneyToStr(mnyPeriod0Balance, sMoney, SIZEOF_BCDSTR, 3);
	rvspyPrint("[Threshold Check] - Current balance = %.22s", sMoney);
	//
	moneyToStr(mnyPeriod1Net, sMoney, SIZEOF_BCDSTR, 3);
	rvspyPrint("[Threshold Check] - Period 1 net = %.22s", sMoney);
	//
	moneyToStr(mnyPeriod1Balance, sMoney, SIZEOF_BCDSTR, 3);
	rvspyPrint("[Threshold Check] - Period 1 balance = %.22s", sMoney);
	//
	moneyToStr(mnyPeriod2Net, sMoney, SIZEOF_BCDSTR, 3);
	rvspyPrint("[Threshold Check] - Period 2 net = %.22s", sMoney);
	//
	moneyToStr(mnyPeriod2Balance, sMoney, SIZEOF_BCDSTR, 3);
	rvspyPrint("[Threshold Check] - Period 2 balance = %.22s", sMoney);
	//
	moneyToStr(mnyPeriod3Net, sMoney, SIZEOF_BCDSTR, 3);
	rvspyPrint("[Threshold Check] - Period 3 net = %.22s", sMoney);
	//
	moneyToStr(mnyPeriod3Balance, sMoney, SIZEOF_BCDSTR, 3);
	rvspyPrint("[Threshold Check] - Period 3 balance = %.22s", sMoney);
	//
	moneyToStr(mnyPeriod4Net, sMoney, SIZEOF_BCDSTR, 3);
	rvspyPrint("[Threshold Check] - Period 4 net = %.22s", sMoney);
	//
	moneyToStr(mnyPeriod4Balance, sMoney, SIZEOF_BCDSTR, 3);
	rvspyPrint("[Threshold Check] - Period 4 balance = %.22s", sMoney);
	//
	moneyToStr(mnyPeriod5Net, sMoney, SIZEOF_BCDSTR, 3);
	rvspyPrint("[Threshold Check] - Period 5 net = %.22s", sMoney);
	//
	moneyToStr(mnyPeriod5Balance, sMoney, SIZEOF_BCDSTR, 3);
	rvspyPrint("[Threshold Check] - Period 5 balance = %.22s", sMoney);
	//
	moneyToStr(mnyPeriod6Net, sMoney, SIZEOF_BCDSTR, 3);
	rvspyPrint("[Threshold Check] - Period 6 net = %.22s", sMoney);
	//
	moneyToStr(mnyPeriod6Balance, sMoney, SIZEOF_BCDSTR, 3);
	rvspyPrint("[Threshold Check] - Period 6 balance = %.22s", sMoney);

	if ((moneyCompare(mnyThreshold, mnyCurrentBalance) > 0)
		|| (moneyCompare(mnyThreshold, mnyPeriod0Balance) > 0)
		|| (moneyCompare(mnyThreshold, mnyPeriod1Balance) > 0)
		|| (moneyCompare(mnyThreshold, mnyPeriod2Balance) > 0)
		|| (moneyCompare(mnyThreshold, mnyPeriod3Balance) > 0)
		|| (moneyCompare(mnyThreshold, mnyPeriod4Balance) > 0)
		|| (moneyCompare(mnyThreshold, mnyPeriod5Balance) > 0)
		|| (moneyCompare(mnyThreshold, mnyPeriod6Balance) > 0))
	{
		rvspyPrint("[Threshold Check] - RESULT: THRESHOLD BREACHED");

		return TRUE;
	}
	
	rvspyPrint("[Threshold Check] - RESULT: THRESHOLD NOT BREACHED");

	return FALSE;
}


typedef struct tagGROUPAMOUNT
{
	DBSINT groupCode;
	CHAR year[SIZEOF_YEAR];
	MONEY amtNetYear;
	MONEY amtBalYTD;
} GROUPAMOUNT, FAR* LPGROUPAMOUNT;

#define	fldSCBALData	4
LONG		idxSCBALData[fldSCBALData] = { SCBAL_IDX(GRPCOD), SCBAL_IDX(FSCYEAR), SCBAL_IDX(NETYEAR), SCBAL_IDX(BALYTD) };
SHORT		sizSCBALData[fldSCBALData] = { SCBAL_SIZ(GRPCOD), SCBAL_SIZ(FSCYEAR), SCBAL_SIZ(NETYEAR), SCBAL_SIZ(BALYTD) };


BOOL WINAPI CheckLoanConditionsSG(
	LPV lpv,
	LPCHAR sYear)
{
	ERRNUM e = ERRNUM_SUCCESS;

	LPVIEWDEF SCOPT = FindCmp(lpv, SCOPT_CMP);
	LPVIEWDEF SCBAL = FindCmp(lpv, SCBAL_CMP);

	CHAR sBRYear[SIZEOF_YEAR];
	WORD wBRYear;
	WORD wCurYear;

	CHECK_CALL(e, viewGet(SCOPT->rvh, SCOPT->view, SCOPT_IDX(BRYEAR), sBRYear, SCOPT_SIZ(BRYEAR)));
	strToWord(sBRYear, &wBRYear, SIZEOF_YEAR);
	strToWord(sYear, &wCurYear, SIZEOF_YEAR);
	if ((wCurYear - wBRYear + 1) < 3)
	{
		rvspyPrint("[Loan conditions check - SG] - Number of Years: %d", wCurYear - wBRYear + 1);
		return FALSE;
	}

	//
	//// Check currency rate
	BCD	rate[SIZEOF_RATE];
	WORD	rateOper;
	CHECK_CALL(e, viewGet(SCOPT->rvh, SCOPT->view, SCOPT_IDX(RATE), rate, SCOPT_SIZ(RATE)));
	CHECK_CALL(e, viewGet(SCOPT->rvh, SCOPT->view, SCOPT_IDX(RATEOPER), &rateOper, SCOPT_SIZ(RATEOPER)));
	if (bcdCompareZero(rate, SIZEOF_RATE) <= 0)
	{
		rvspyPrint("[Loan conditions check - SG] - Unable to get rate from %.3s to SGD", lpv->CompanyInfo.sHomeCurrency);
		return FALSE;
	}

	//
	//// Calculate figures
	std::list<GROUPAMOUNT> data;
	std::list<GROUPAMOUNT>::iterator it;

	CHECK_CALL(e, viewRecordClear((LPRVH)SCBAL->rvh, SCBAL->view));
	CHECK_CALL(e, viewBrowse(SCBAL->rvh, SCBAL->view, (LPSTR)"", TRUE));
	while (ERRNUM_IS_SUCCESS(viewFetch(SCBAL->rvh, SCBAL->view)))
	{
		GROUPAMOUNT groupAmount;
		CHECK_CALL(e, viewBlkGet(SCBAL->rvh, SCBAL->view, fldSCBALData, idxSCBALData, sizSCBALData, &groupAmount));
		data.push_back(groupAmount);
	}

	MONEY mnySales;
	MONEY mnySalesSGD;
	MONEY mnySalesFrom;
	MONEY mnySalesTo;
	MONEY mnyEBITDA;
	MONEY mnyNetWorth;
	MONEY mnySharedHoldersEquity;
	MONEY mnyDebtToEquity;
	MONEY mnyDebtToEquityMax;

	//
	/// Calculate Sales
	moneyInit(mnySales);
	for (it = data.begin(); it != data.end(); ++it)
		if ((it->groupCode == 140) 
			&& (blkCompare(sYear, it->year, SIZEOF_YEAR) > 0))
		{
			moneyAdd(mnySales, it->amtNetYear);
			break;
		}
	moneyNegate(mnySales);
	moneyInit(mnySalesSGD);

	if (blkCompare(lpv->CompanyInfo.sHomeCurrency, SC_COUNTRY_CURR_SINGAPORE, SIZEOF_CURRENCY_CODE) != 0)
	{
		if (rateOper == RATE_OPERATOR_MULTIPLY)
			bcdDiv(mnySalesSGD, SIZEOF_MONEY, MONEY_DECIMALS, rate, SIZEOF_RATE, RATE_DECIMALS);
		else
			bcdMul(mnySalesSGD, SIZEOF_MONEY, MONEY_DECIMALS, rate, SIZEOF_RATE, RATE_DECIMALS);
	}
	else
		moneyAssign(mnySalesSGD, mnySales);

	strToMoney("650000", mnySalesFrom);
	strToMoney("27000000", mnySalesTo);

	//
	//// Calculate EBITDA
	moneyInit(mnyEBITDA);
	for (it = data.begin(); it != data.end(); ++it)
		if ((it->groupCode == 140 || it->groupCode == 150 || it->groupCode == 160 || it->groupCode == 170 || it->groupCode == 190)
			&& (blkCompare(sYear, it->year, SIZEOF_YEAR) > 0))
		{
			moneyAdd(mnyEBITDA, it->amtNetYear);
		}
	moneyNegate(mnyEBITDA);

	//
	//// Calculate Net Worth
	moneyInit(mnyNetWorth);
	for (it = data.begin(); it != data.end(); ++it)
		if ((it->groupCode >= 10 && it->groupCode <= 110)
			&& (blkCompare(sYear, it->year, SIZEOF_YEAR) == 0))
		{
			moneyAdd(mnyNetWorth, it->amtBalYTD);
		}

	//
	//// Calculate Debt to Equity
	moneyInit(mnyDebtToEquity);
	for (it = data.begin(); it != data.end(); ++it)
		if ((it->groupCode >= 80 && it->groupCode <= 110)
			&& (blkCompare(sYear, it->year, SIZEOF_YEAR) == 0))
		{
			moneyAdd(mnyDebtToEquity, it->amtBalYTD);
		}
	moneyInit(mnySharedHoldersEquity);
	for (it = data.begin(); it != data.end(); ++it)
		if ((it->groupCode >= 120)
			&& (blkCompare(sYear, it->year, SIZEOF_YEAR) == 0))
		{
			moneyAdd(mnySharedHoldersEquity, it->amtBalYTD);
		}
	moneyDiv(mnyDebtToEquity, mnySharedHoldersEquity);
	strToMoney("3.5", mnyDebtToEquityMax);

	data.clear();

	CHAR sMoney[SIZEOF_BCDSTR + 1];
	//
	////
	rvspyPrint("[Loan conditions check - SG] - Number of Years: %d", wCurYear - wBRYear + 1);
	//
	if (blkCompare(lpv->CompanyInfo.sHomeCurrency, SC_COUNTRY_CURR_SINGAPORE, SIZEOF_CURRENCY_CODE) != 0)
	{
		moneyToStr(mnySales, sMoney, SIZEOF_BCDSTR, 3);
		rvspyPrint("[Loan conditions check - SG] - Annual Sales: %.22s", sMoney);
		bcdToZStr(rate, SIZEOF_RATE, RATE_DECIMALS, sMoney, SIZEOF_BCDSTR, RATE_DECIMALS);
		rvspyPrint("[Loan conditions check - SG] - SGD Rate: %.22s - Operator: %d", sMoney, rateOper);
	}
	moneyToStr(mnySalesSGD, sMoney, SIZEOF_BCDSTR, 3);
	rvspyPrint("[Loan conditions check - SG] - Annual Sales SGD: %.22s", sMoney);
	//
	moneyToStr(mnyEBITDA, sMoney, SIZEOF_BCDSTR, 3);
	rvspyPrint("[Loan conditions check - SG] - EBIDTA: %.22s", sMoney);
	//
	moneyToStr(mnyNetWorth, sMoney, SIZEOF_BCDSTR, 3);
	rvspyPrint("[Loan conditions check - SG] - Net Worth: %.22s", sMoney);
	//
	moneyToStr(mnyDebtToEquity, sMoney, SIZEOF_BCDSTR, 3);
	rvspyPrint("[Loan conditions check - SG] - Debt to Equity: %.22s", sMoney);	

	if (((moneyCompare(mnySalesFrom, mnySales) <= 0) && (moneyCompare(mnySalesTo, mnySales) >= 0)) // Sales from 0.5M to 20M
		&& (moneyCompareZero(mnyEBITDA) > 0) // EBIDTA > 0
		&& (moneyCompareZero(mnyNetWorth) > 0) // NetWorth > 0
		&& (moneyCompare(mnyDebtToEquity, mnyDebtToEquityMax) < 0)) // Debt to Equity < 3.5
	{
		rvspyPrint("[Loan conditions check - SG] - RESULT: ELIGIBLE FOR LOAN");		
		return TRUE;
	}

	rvspyPrint("[Loan conditions check - SG] - RESULT: NOT ELIGIBLE FOR LOAN");
	return FALSE;
}

BOOL WINAPI CheckLoanConditionsMY(
	LPV lpv,
	LPCHAR sYear)
{
	ERRNUM e = ERRNUM_SUCCESS;

	LPVIEWDEF SCOPT = FindCmp(lpv, SCOPT_CMP);
	LPVIEWDEF SCBAL = FindCmp(lpv, SCBAL_CMP);

	//
	//// Check BRYear
	CHAR sBRYear[SIZEOF_YEAR];
	WORD wBRYear;
	WORD wCurYear;

	CHECK_CALL(e, viewGet(SCOPT->rvh, SCOPT->view, SCOPT_IDX(BRYEAR), sBRYear, SCOPT_SIZ(BRYEAR)));
	strToWord(sBRYear, &wBRYear, SIZEOF_YEAR);
	strToWord(sYear, &wCurYear, SIZEOF_YEAR);
	if ((wCurYear - wBRYear + 1) < 3)
	{
		rvspyPrint("[Loan conditions check - MY] - Number of Years: %d", wCurYear - wBRYear + 1);
		return FALSE;
	}

	//
	//// Check currency rate
	BCD	rate[SIZEOF_RATE];
	WORD	rateOper;
	CHECK_CALL(e, viewGet(SCOPT->rvh, SCOPT->view, SCOPT_IDX(RATE), rate, SCOPT_SIZ(RATE)));
	CHECK_CALL(e, viewGet(SCOPT->rvh, SCOPT->view, SCOPT_IDX(RATEOPER), &rateOper, SCOPT_SIZ(RATEOPER)));
	if (bcdCompareZero(rate, SIZEOF_RATE) <= 0)
	{
		rvspyPrint("[Loan conditions check - MY] - Unable to get rate from %.3s to MYR", lpv->CompanyInfo.sHomeCurrency);
		return FALSE;
	}

	//
	//// Check Entity Type
	DBSINT entityType;
	CHECK_CALL(e, viewGet(SCOPT->rvh, SCOPT->view, SCOPT_IDX(ENTITYTYPE), &entityType, SCOPT_SIZ(ENTITYTYPE)));
	if (entityType != 2)
	{
		rvspyPrint("[Loan conditions check - MY] - Entity Type not qualified: %d", entityType);
		return FALSE;
	}

	//
	//// Calculate figures
	std::list<GROUPAMOUNT> data;
	std::list<GROUPAMOUNT>::iterator it;

	CHECK_CALL(e, viewRecordClear((LPRVH)SCBAL->rvh, SCBAL->view));
	CHECK_CALL(e, viewBrowse(SCBAL->rvh, SCBAL->view, (LPSTR)"", TRUE));
	while (ERRNUM_IS_SUCCESS(viewFetch(SCBAL->rvh, SCBAL->view)))
	{
		GROUPAMOUNT groupAmount;
		CHECK_CALL(e, viewBlkGet(SCBAL->rvh, SCBAL->view, fldSCBALData, idxSCBALData, sizSCBALData, &groupAmount));
		data.push_back(groupAmount);
	}

	MONEY mnySales;
	MONEY mnySalesMYR;
	MONEY mnySalesFrom;
	MONEY mnySalesTo;
	MONEY mnyEBITDA;
	MONEY mnyNetWorth;
	MONEY mnySharedHoldersEquity;
	MONEY mnyDebtToEquity;
	MONEY mnyDebtToEquityMax;

	//
	/// Calculate Sales
	moneyInit(mnySales);
	for (it = data.begin(); it != data.end(); ++it)
		if ((it->groupCode == 140)
			&& (blkCompare(sYear, it->year, SIZEOF_YEAR) > 0))
		{
			moneyAdd(mnySales, it->amtNetYear);
			break;
		}
	moneyNegate(mnySales);
	moneyInit(mnySalesMYR);

	if (blkCompare(lpv->CompanyInfo.sHomeCurrency, SC_COUNTRY_CURR_MALAYSIA, SIZEOF_CURRENCY_CODE) != 0)
	{
		if (rateOper == RATE_OPERATOR_MULTIPLY)
			bcdDiv(mnySalesMYR, SIZEOF_MONEY, MONEY_DECIMALS, rate, SIZEOF_RATE, RATE_DECIMALS);
		else
			bcdMul(mnySalesMYR, SIZEOF_MONEY, MONEY_DECIMALS, rate, SIZEOF_RATE, RATE_DECIMALS);
	}
	else
		moneyAssign(mnySalesMYR, mnySales);

	strToMoney("2000000", mnySalesFrom);
	strToMoney("40000000", mnySalesTo);

	//
	//// Calculate EBITDA
	moneyInit(mnyEBITDA);
	for (it = data.begin(); it != data.end(); ++it)
		if ((it->groupCode == 140 || it->groupCode == 150 || it->groupCode == 160 || it->groupCode == 170 || it->groupCode == 190)
			&& (blkCompare(sYear, it->year, SIZEOF_YEAR) > 0))
		{
			moneyAdd(mnyEBITDA, it->amtNetYear);
		}
	moneyNegate(mnyEBITDA);

	//
	//// Calculate Net Worth
	moneyInit(mnyNetWorth);
	for (it = data.begin(); it != data.end(); ++it)
		if ((it->groupCode >= 10 && it->groupCode <= 110)
			&& (blkCompare(sYear, it->year, SIZEOF_YEAR) == 0))
		{
			moneyAdd(mnyNetWorth, it->amtBalYTD);
		}

	//
	//// Calculate Debt to Equity (Gearing Ratio)
	moneyInit(mnyDebtToEquity);
	for (it = data.begin(); it != data.end(); ++it)
		if ((it->groupCode >= 80 && it->groupCode <= 110)
			&& (blkCompare(sYear, it->year, SIZEOF_YEAR) == 0))
		{
			moneyAdd(mnyDebtToEquity, it->amtBalYTD);
		}
	moneyInit(mnySharedHoldersEquity);
	for (it = data.begin(); it != data.end(); ++it)
		if ((it->groupCode >= 120)
			&& (blkCompare(sYear, it->year, SIZEOF_YEAR) == 0))
		{
			moneyAdd(mnySharedHoldersEquity, it->amtBalYTD);
		}
	moneyDiv(mnyDebtToEquity, mnySharedHoldersEquity);
	strToMoney("5.0", mnyDebtToEquityMax);

	data.clear();

	CHAR sMoney[SIZEOF_BCDSTR + 1];
	//
	////
	rvspyPrint("[Loan conditions check - MY] - Number of Years: %d", wCurYear - wBRYear + 1);
	//
	if (blkCompare(lpv->CompanyInfo.sHomeCurrency, SC_COUNTRY_CURR_MALAYSIA, SIZEOF_CURRENCY_CODE) != 0)
	{
		moneyToStr(mnySales, sMoney, SIZEOF_BCDSTR, 3);
		rvspyPrint("[Loan conditions check - MY] - Annual Sales: %.22s", sMoney);
		bcdToZStr(rate, SIZEOF_RATE, RATE_DECIMALS, sMoney, SIZEOF_BCDSTR, RATE_DECIMALS);
		rvspyPrint("[Loan conditions check - MY] - MYR Rate: %.22s - Operator: %d", sMoney, rateOper);
	}
	moneyToStr(mnySalesMYR, sMoney, SIZEOF_BCDSTR, 3);
	rvspyPrint("[Loan conditions check - MY] - Annual Sales MYR: %.22s", sMoney);
	//
	moneyToStr(mnyEBITDA, sMoney, SIZEOF_BCDSTR, 3);
	rvspyPrint("[Loan conditions check - MY] - EBIDTA: %.22s", sMoney);
	//
	moneyToStr(mnyNetWorth, sMoney, SIZEOF_BCDSTR, 3);
	rvspyPrint("[Loan conditions check - MY] - Net Worth: %.22s", sMoney);
	//
	moneyToStr(mnyDebtToEquity, sMoney, SIZEOF_BCDSTR, 3);
	rvspyPrint("[Loan conditions check - MY] - Debt to Equity: %.22s", sMoney);

	if (((moneyCompare(mnySalesFrom, mnySales) <= 0) && (moneyCompare(mnySalesTo, mnySales) >= 0)) // Sales from 0.5M to 20M
		&& (moneyCompareZero(mnyEBITDA) > 0) // EBIDTA > 0
		&& (moneyCompareZero(mnyNetWorth) > 0) // NetWorth > 0
		&& (moneyCompare(mnyDebtToEquity, mnyDebtToEquityMax) < 0)) // Debt to Equity < 5.0
	{
		rvspyPrint("[Loan conditions check - MY] - RESULT: ELIGIBLE FOR LOAN");
		return TRUE;
	}

	rvspyPrint("[Loan conditions check - MY] - RESULT: NOT ELIGIBLE FOR LOAN");
	return FALSE;
}


BOOL WINAPI CheckLoanRecordExists(
	LPV lpv) 
{
	LPVIEWDEF SCLOAN = FindCmp(lpv, SCLOAN_CMP);

	A4W_SIZE iCount = 0;
	if (ERRNUM_IS_SUCCESS(viewFilterCount((LPRVH)SCLOAN->rvh, SCLOAN->view, (LPSTR)"(STATUS = 0) OR (STATUS = 1)", 0, &iCount)))
		return iCount > 0;

	return TRUE;
}


BOOL WINAPI CheckLoanConditions(
	LPV lpv,
	LPSTR sYear)
{
	if (CheckLoanRecordExists(lpv))
		return FALSE;

	BOOL bResult = FALSE;

	ERRNUM e = ERRNUM_SUCCESS;
	LPVIEWDEF SCOPT = FindCmp(lpv, SCOPT_CMP);
	LPVIEWDEF SCLOAN = FindCmp(lpv, SCLOAN_CMP);

	//
	//// Debug: Check if there is force loan eligible
	CHAR sLoanCondition[SIZEOF_STD_DESC + 1];
	INT iSize = sizeof(sLoanCondition);
	if (!GetIniFileKey(lpv->hpib, (LPSTR)APPL, (LPSTR)"Debug", (LPSTR)"LoanCondition", sLoanCondition, (LPINT)& iSize))
		if (iSize > 0)
		{
			rvspyPrint("[Loan conditions check] - Debug: TRUE");
			bResult = TRUE;
		}

	if (!bResult)
	{
		WORD wCountry = 0;
		CHECK_CALL(e, viewGet(SCOPT->rvh, SCOPT->view, SCOPT_IDX(COUNTRY), &wCountry, SCOPT_SIZ(COUNTRY)));

		switch (wCountry)
		{
			case SC_COUNTRY_SINGAPORE:
				rvspyPrint("[Loan conditions check] - Country: Singapore");
				bResult = CheckLoanConditionsSG(lpv, sYear);
				break;

			case SC_COUNTRY_MALAYSIA:
				rvspyPrint("[Loan conditions check] - Country: Malaysia");
				bResult = CheckLoanConditionsMY(lpv, sYear);
				break;

			default:
				break;
		}

	}

	if (bResult)
	{
		CHECK_CALL(e, viewInit(SCLOAN->rvh, SCLOAN->view));
		CHECK_CALL(e, viewInsert(SCLOAN->rvh, SCLOAN->view));
	}

	return bResult;
}


VIEWBASE ProcessEtc (
   LPV lpv) // view handle

// Callout invoked by scProProcess().  Does all processing.

{
   ERRNUM e = ERRNUM_SUCCESS;

	LPVIEWDEF SCOPT = FindCmp(lpv, SCOPT_CMP);

	if (!ERRNUM_IS_SUCCESS(viewRead(SCOPT->rvh, SCOPT->view)))
	{
		//
		// Only report error for FORCED processing
		//
		if (((DBSINT)*FindFieldValue(lpv, SCPRO_IDX(PROCESSCMD)) == SCPRO_PROCESSCMD_FORCE))
		{
			if (ibGetHWND(lpv->hpib) != NULL)
				ReportError(lpv, IDERR_SC_OPTIONS_NOT_SET, NULL, NULL, NULL);

			return SC_ERROR_OPTIONS_NOT_SET;
		}
		//
		// For unattended process, we have to return ERRNUM_SUCCESS
		//
		return e;
	}

	BCDDATE lastProcessDate;
	CHECK_CALL(e, viewGet(SCOPT->rvh, SCOPT->view, SCOPT_IDX(LPROCDATE), lastProcessDate, SCOPT_SIZ(LPROCDATE)));

	BCDDATE processDate;
	blkCopy(processDate, FindFieldValue(lpv, SCPRO_IDX(PROCESSDT)), SIZEOF_DATE);

	//
	//// For normal processing, do not process more than once a day.
	if (!blkCompare(lastProcessDate, processDate, SIZEOF_DATE)
		&& (*FindFieldValue(lpv, SCPRO_IDX(PROCESSCMD)) == SCPRO_PROCESSCMD_NORMAL))
		return e;

	CHAR sMeterCaption[METER_CAPTION_SIZE + 1];
	LoadRsc(lpv->hpib, MAKERSC(IDS_SCPRO_METER_CAPTION), METER_CAPTION_SIZE, sMeterCaption, TRUE);

	LPMETER meter = meterCreate(lpv->hpib, sMeterCaption, FALSE, TRUE);

	CHAR sYear[SIZEOF_YEAR + 1];
	WORD wYear;
	WORD wPeriod;
	BOOL bPeriodStatus;
	fscPeriod(lpv->hpib, lpv->wLinkNo, processDate, &wPeriod, sYear, &bPeriodStatus);
	strToWord(sYear, &wYear, SIZEOF_YEAR);
	CHECK_CALL(e, ProcessSCBAL(lpv, wYear, meter));

	CHAR sDate[9];
	bcdToZStr(processDate, SIZEOF_DATE, 0, sDate, 9, 0);
	CHECK_CALL(e, ProcessSCTRAN(lpv, sDate, meter));

	meterDestroy(meter);
	//
	// Update last process date
	//
	if (secGlobalAccess(lpv->hpib, lpv->wLinkNo, lpv->rotoID))
	{
		DBTIME dbTime;
		BCDTIME bcdTime;
		dtGetTime(&dbTime);
		dtTimeToBCD(&dbTime, bcdTime);

		CHECK_CALL(e, viewPut(SCOPT->rvh, SCOPT->view, SCOPT_IDX(LPROCDATE), processDate, SCOPT_SIZ(LPROCDATE), FALSE));
		CHECK_CALL(e, viewPut(SCOPT->rvh, SCOPT->view, SCOPT_IDX(LPROCTIME), bcdTime, SCOPT_SIZ(LPROCTIME), FALSE));
		CHECK_CALL(e, viewUpdate(SCOPT->rvh, SCOPT->view));

		secNoGlobalAccess(lpv->hpib, lpv->wLinkNo);
	}

	//
	// Only report error for normal processing
	//
	if (((DBSINT)* FindFieldValue(lpv, SCPRO_IDX(PROCESSCMD)) == SCPRO_PROCESSCMD_NORMAL))
	{

		BOOL bThresholdBreached = CheckThreshold(lpv);
		BOOL bLoanConditionsMet = CheckLoanConditions(lpv, sYear);

		if (bThresholdBreached || bLoanConditionsMet)
		{
			DBSBOOL bEmailAlert = TRUE;			
			CHECK_CALL(e, viewGet(SCOPT->rvh, SCOPT->view, SCOPT_IDX(EMAILALERT), &bEmailAlert, SCOPT_SIZ(EMAILALERT)));
			if (!bEmailAlert)
				return e;

			BCDDATE dSnoozeUntil;
			CHECK_CALL(e, viewGet(SCOPT->rvh, SCOPT->view, SCOPT_IDX(EMAILSNUTL), dSnoozeUntil, SCOPT_SIZ(EMAILSNUTL)));
			bThresholdBreached &= !(bcdCompare(processDate, SIZEOF_DATE, 0, dSnoozeUntil, SIZEOF_DATE, 0) <= 0);

			DBSBOOL bEmailOffer = TRUE;
			CHECK_CALL(e, viewGet(SCOPT->rvh, SCOPT->view, SCOPT_IDX(EMAILOFFER), &bEmailOffer, SCOPT_SIZ(EMAILOFFER)));
			bLoanConditionsMet &= bEmailOffer;

			//
			//
			//
			CHAR szEmailHost[SCOPT_SIZ(EMAILHOST) + 1];
			WORD wEmailPort = 25;
			DBSBOOL bEmailSSL = FALSE;
			CHAR szEmailUser[SCOPT_SIZ(EMAILUSER) + 1];
			BYTE aEmailPassword[SCOPT_SIZ(EMAILPSWD) + 1];
			CHAR szEmailPassword[SCOPT_SIZ(EMAILPSWD) + 1];
			CHAR szEmailFrom[SCOPT_SIZ(EMAILADDR) + 1];
			CHAR szEmailTo[SCOPT_SIZ(EMAILTO) + 1];
			CHAR szEmailSubjectTemplate[RSC_MAX_MESSAGE + 1];
			CHAR szEmailSubject[RSC_MAX_MESSAGE + 1];
			//CHAR szEmailBody[SCPRO_EMAIL_MAX_MESSAGE + 1];
			LPCHAR szEmailBody = (LPCHAR)memAlloc(SCPRO_EMAIL_MAX_MESSAGE);
			LPCHAR szEmailOffer = (LPCHAR)memAlloc(SCPRO_EMAIL_MAX_MESSAGE);

			strInit(szEmailHost);
			strInit(szEmailUser);
			strInit(szEmailPassword);
			strInit(szEmailFrom);
			strInit(szEmailTo);
			strInit(szEmailSubjectTemplate);
			strInit(szEmailSubject);
			//strInit(szEmailBody);
			//strInit(szEmailOffer);
			blkSet(szEmailBody, 0, SCPRO_EMAIL_MAX_MESSAGE);
			blkSet(szEmailOffer, 0, SCPRO_EMAIL_MAX_MESSAGE);

			CHECK_CALL(e, viewGet(SCOPT->rvh, SCOPT->view, SCOPT_IDX(EMAILHOST), szEmailHost, SCOPT_SIZ(EMAILHOST)));
			CHECK_CALL(e, viewGet(SCOPT->rvh, SCOPT->view, SCOPT_IDX(EMAILPORT), &wEmailPort, SCOPT_SIZ(EMAILPORT)));
			CHECK_CALL(e, viewGet(SCOPT->rvh, SCOPT->view, SCOPT_IDX(EMAILSSL), &bEmailSSL, SCOPT_SIZ(EMAILSSL)));
			CHECK_CALL(e, viewGet(SCOPT->rvh, SCOPT->view, SCOPT_IDX(EMAILUSER), szEmailUser, SCOPT_SIZ(EMAILUSER)));
			CHECK_CALL(e, viewGet(SCOPT->rvh, SCOPT->view, SCOPT_IDX(EMAILPSWD), aEmailPassword, SCOPT_SIZ(EMAILPSWD)));
			CHECK_CALL(e, viewGet(SCOPT->rvh, SCOPT->view, SCOPT_IDX(EMAILADDR), szEmailFrom, SCOPT_SIZ(EMAILADDR)));
			CHECK_CALL(e, viewGet(SCOPT->rvh, SCOPT->view, SCOPT_IDX(EMAILTO), szEmailTo, SCOPT_SIZ(EMAILTO)));
			strTrim(szEmailHost);
			strTrim(szEmailUser);
			strEncrypt((LPBYTE)szEmailPassword, aEmailPassword, SCOPT_SIZ(EMAILPSWD));
			strTrim(szEmailPassword);
			strTrim(szEmailFrom);
			strTrim(szEmailTo);

			//
			//// Alert processing
			if (bThresholdBreached && bLoanConditionsMet)
			{
				//
				//// Send email Alert & Loan offer
				LoadRsc(lpv->hpib, MAKERSC(IDS_SCPRO_EMAIL_SUBJECT_ALERTLOAN), RSC_MAX_MESSAGE, szEmailSubjectTemplate, TRUE);
				sprintf_s(szEmailSubject, szEmailSubjectTemplate, lpv->CompanyInfo.sName);
				//CHAR szEmailOffer[SCPRO_EMAIL_MAX_MESSAGE + 1];
				//strInit(szEmailOffer);
				//rscLoadHTML(lpv->hpib, APPL, 80001, szEmailBody, SCPRO_EMAIL_MAX_MESSAGE);
				//rscLoadHTML(lpv->hpib, APPL, 87021, szEmailOffer, SCPRO_EMAIL_MAX_MESSAGE);

				rscLoadHTML(lpv->hpib, APPL, 87022, szEmailBody, SCPRO_EMAIL_MAX_MESSAGE);

				//strAppend(szEmailBody, szEmailOffer);
				emailSendRaw(
					szEmailHost,
					wEmailPort,
					bEmailSSL,
					szEmailUser,
					szEmailPassword,
					szEmailFrom,
					szEmailTo,
					NULL,
					szEmailSubject,
					szEmailBody,
					NULL);
			}
			else if (bThresholdBreached)
			{
				//
				//// Send email Alert Only
				LoadRsc(lpv->hpib, MAKERSC(IDS_SCPRO_EMAIL_SUBJECT_ALERT), RSC_MAX_MESSAGE, szEmailSubjectTemplate, TRUE);
				sprintf_s(szEmailSubject, szEmailSubjectTemplate, lpv->CompanyInfo.sName);
				rscLoadHTML(lpv->hpib, APPL, 80001, szEmailBody, SCPRO_EMAIL_MAX_MESSAGE);
				emailSendRaw(
					szEmailHost,
					wEmailPort,
					bEmailSSL,
					szEmailUser,
					szEmailPassword,
					szEmailFrom,
					szEmailTo,
					NULL,
					szEmailSubject,
					szEmailBody,
					NULL);
			}
			else if (bLoanConditionsMet)
			{
				//
				//// Send email Offer Only
				LoadRsc(lpv->hpib, MAKERSC(IDS_SCPRO_EMAIL_SUBJECT_LOAN), RSC_MAX_MESSAGE, szEmailSubjectTemplate, TRUE);
				sprintf_s(szEmailSubject, szEmailSubjectTemplate, lpv->CompanyInfo.sName);
				rscLoadHTML(lpv->hpib, APPL, 87021, szEmailBody, SCPRO_EMAIL_MAX_MESSAGE);
				emailSendRaw(
					szEmailHost,
					wEmailPort,
					bEmailSSL,
					szEmailUser,
					szEmailPassword,
					szEmailFrom,
					szEmailTo,
					NULL,
					szEmailSubject,
					szEmailBody,
					NULL);
			}

			if (szEmailOffer != NULL)
				memFree(szEmailOffer);
			if (szEmailBody != NULL)
				memFree(szEmailBody);
		}
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
    This function is called by scProPut as a last step.  Does any
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

// This callout is invoked during scProRevisionRekey(), after each record has
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
   errPutGeneric (lpv->hpib, APPL, MAKERSC (IDS_SCPRO_VIEW_NAME), NULL,
                  area, op, MAKERSC (ERRGEN_CAT_DEFAULT), error, extra);
}

#endif



#if defined(DO_REPORTGENERICERRORVIAPIB)

void WINAPI ReportGenericErrorViaPIB (HPIB pib, WORD area, WORD op, WORD error, LPVOID extra)
{
   CHAR noun [RSC_MAX_MESSAGE];

   errPutGeneric (pib, APPL, MAKERSC (IDS_SCPRO_VIEW_NAME), NULL,
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
// Called within: scProPost(), scProRevisionPost()

{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, RevisionInnerPostBase (lpv, level));
   return e;
}

#endif



#ifdef DO_REVPOSTETC
/*---------------------------------------------------------------------------
   revPostEtc: per-detail call-out for scProPost(). As each change from the
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
         e = scProYours  (v->view, v->field, v->p);
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
         e = scProYours  (v->view, v->field, v->p);
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

// This function is called by scProVerify after each field has been
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

// Called by scProVerify when a field is a key in a composite
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
// by calling scProBaseYYYY from within each respecive scProYYYY here.
// These overrides allow you to process before, after, or instead of
// the original view template behaviour.

// +++



#ifdef DO_scProAttribs
VIEWCALL scProAttribs   (LPVOID lpView, LONG lField, LPLONG lpAttributes)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseAttribs   (lpView, lField, lpAttributes));
   return e;
}
#endif



#ifdef DO_scProBlkGet
VIEWCALL scProBlkGet    (LPVOID lpView, INT lFields, LPLONG lFieldList, LPSHORT lpnSizeList, LPSTR lpsBuffer)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseBlkGet    (lpView, lFields, lFieldList, lpnSizeList, lpsBuffer));
   return e;
}
#endif



#ifdef DO_scProBlkPut
VIEWCALL scProBlkPut    (LPVOID lpView, INT lFields, LPLONG lFieldList, LPSHORT lpnSizeList, LPSTR lpsBuffer, BOOL bVerify)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseBlkPut    (lpView, lFields, lFieldList, lpnSizeList, lpsBuffer, bVerify));
   return e;
}
#endif



#ifdef DO_scProBrowse
VIEWCALL scProBrowse    (LPVOID lpView, LPSTR lpsExpression, BOOL bAscending)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseBrowse    (lpView, lpsExpression, bAscending));
   return e;
}
#endif



#ifdef DO_scProCancel
VIEWCALL scProCancel    (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseCancel    (lpView));
   return e;
}
#endif



#ifdef DO_scProClose
VIEWCALL scProClose     (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

	CloseOneView(lpv, SCLOAN_CMP);
	CloseOneView(lpv, SCTRAN_CMP);
	CloseOneView(lpv, SCBAL_CMP);
	CloseOneView(lpv, SCACCT_CMP);
	CloseOneView(lpv, SCOPT_CMP);

   CHECK_CALL (e, scProBaseClose     (lpView));
   return e;
}
#endif



#ifdef DO_scProCmpNames
VIEWCALL scProCmpNames  (INT roto, LPSTR lpsCompositeNames, LPSHORT lpnCount)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseCmpNames  (roto, lpsCompositeNames, lpnCount));
   return e;
}
#endif



#ifdef DO_scProCompose
VIEWCALL scProCompose   (LPVOID lpView, LPVIEWDEF lpvdefComposites)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseCompose   (lpView, lpvdefComposites));
   return e;
}
#endif



#ifdef DO_scProCreate
VIEWCALL scProCreate    (HPIB hPIB, WORD wLinkNo)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseCreate    (hPIB, wLinkNo));
   return e;
}
#endif



#ifdef DO_scProDelete
VIEWCALL scProDelete    (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseDelete    (lpView));
   return e;
}
#endif



#ifdef DO_scProDirty
VIEWCALL scProDirty     (LPVOID lpView, LPBOOL bChanged)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseDirty     (lpView, bChanged));
   return e;
}
#endif



#ifdef DO_scProDrop
VIEWCALL scProDrop      (HPIB hPIB, WORD wLinkNo)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseDrop      (hPIB, wLinkNo));
   return e;
}
#endif



#ifdef DO_scProExists
VIEWCALL scProExists    (LPVOID lpView, LPBOOL bExists)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseExists    (lpView, bExists));
   return e;
}
#endif



#ifdef DO_scProFetch
VIEWCALL scProFetch     (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;
   BOOL found = FALSE;

   CHECK_FETCH_UNROLL (e, found, scProBaseFetch     (lpView));
   if ( !found )
      return ERRNUM_RECORD_NO_MORE_DATA;
   return e;
}
#endif



#ifdef DO_scProFetchLock
VIEWCALL scProFetchLock (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;
   BOOL found = FALSE;

   CHECK_FETCH_UNROLL (e, found, scProBaseFetchLock (lpView));
   if ( !found )
      return ERRNUM_RECORD_NO_MORE_DATA;
   return e;
}
#endif



#ifdef DO_scProField
VIEWCALL scProField     (LPVOID lpView, INT nFldNumber, LPSTR lpsFldName, LPLONG lField)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseField     (lpView, nFldNumber, lpsFldName, lField));
   return e;
}
#endif



#ifdef DO_scProFieldExists
VIEWCALL scProFieldExists (
   LPV view,
   LONG lField,
   LP_A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   MaxError (&e, scProBaseFieldExists (view, lField, flags));
   return e;
}
#endif



#ifdef DO_scProFieldName
VIEWCALL scProFieldName (
   LPV view,
   LONG lField,
   LPSTR lpsName,
   LPSTR lpsDesc,
   A4W_SIZE size)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseFieldName (view, lField, lpsName, lpsDesc, size));
   return e;
}
#endif


#ifdef DO_scProFields
VIEWCALL scProFields    (LPVOID lpView, LPSHORT lFields)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseFields    (lpView, lFields));
   return e;
}
#endif



#if defined(DO_scProFilterCount)
VIEWCALL scProFilterCount (LPV view, LPSTR expression, A4W_FLAGS flags, LP_A4W_SIZE count)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseFilterCount (view, expression, flags, count));
   return e;
}
#endif



#if defined(DO_scProFilterDelete)
VIEWCALL scProFilterDelete (LPV view, LPSTR filter, A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseFilterDelete (view, filter, flags));
   return e;
}
#endif



#if defined(DO_scProFilterFetch)
VIEWCALL scProFilterFetch (LPV view, A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;
   BOOL found = FALSE;

   CHECK_FETCH_UNROLL (e, found, scProBaseFilterFetch (view, flags));
   if ( !found )
      return ERRNUM_RECORD_NO_MORE_DATA;
   return e;
}
#endif



#if defined(DO_scProFilterSelect)
VIEWCALL scProFilterSelect (LPV view, INT key, LPSTR filter, A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseFilterSelect (view, key, filter, flags));
   return e;
}
#endif



#ifdef DO_scProGet
VIEWCALL scProGet       (LPVOID lpView, LONG lField, LPSTR buffer, INT nSize)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseGet       (lpView, lField, buffer, nSize));
   return e;
}
#endif



#ifdef DO_scProInit
VIEWCALL scProInit      (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseInit      (lpView));
   return e;
}
#endif



#ifdef DO_scProInsert
VIEWCALL scProInsert    (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseInsert    (lpView));
   return e;
}
#endif



#if defined(DO_scProInstanceFieldList)
VIEWCALL scProInstanceFieldList (LPV view, A4W_NOTIFY_PROC notify, LPVOID context, A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseInstanceFieldList (view, flags, count, fields));
   return e;
}
#endif



#if defined(DO_scProInstanceNotify)
VIEWCALL scProInstanceNotify (LPV view, A4W_NOTIFY_PROC notify, LPVOID context, A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseInstanceNotify (view, notify, context, flags));
   return e;
}
#endif



#if defined(DO_scProInstanceOpen)
VIEWCALL scProInstanceOpen (LPRVH rvh, HPIB PIB, WORD link, A4W_FLAGS flags, LPVOID extra, A4W_SIZE size, LPV FAR * lplpView)
{
   ERRNUM e = scProBaseInstanceOpen (rvh, PIB, link, flags, extra, size, lplpView);
   LPV view = *lplpView;

   if ( ERRNUM_IS_FAILURE (e) )
      return e;

   // Your logic here . . .

   return e;
}
#endif



#if defined(DO_scProInstanceProtocol)
VIEWCALL scProInstanceProtocol (LPV view, A4W_FLAGS flags, LP_A4W_FLAGS protocols, LP_A4W_SIZE count)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseInstanceProtocol (view, flags, protocols, count));
   return e;
}
#endif



#if defined(DO_scProInstanceSecurity)
VIEWCALL scProInstanceSecurity (LPV view, LP_A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseInstanceSecurity (view, flags));
   return e;
}
#endif



#ifdef DO_scProKey
VIEWCALL scProKey       (LPVOID lpView, INT nKeyNo, LPSTR sName, LPSHORT lFields, LPLONG lplKeyFields)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseKey       (lpView, nKeyNo, sName, lFields, lplKeyFields));
   return e;
}
#endif



#ifdef DO_scProKeys
VIEWCALL scProKeys      (LPVOID lpView, LPSHORT lpnKeys)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseKeys      (lpView, lpnKeys));
   return e;
}
#endif



#ifdef DO_scProName
VIEWCALL scProName      (LPVOID lpView, LONG lField, LPSTR lpsName, LPSTR lpsDesc)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseName      (lpView, lField, lpsName, lpsDesc));
   return e;
}
#endif



#ifdef DO_scProOpen
VIEWCALL scProOpen      (HPIB hPIB, WORD wLinkNo, LPVOID FAR * lplpView)
{
   ERRNUM e = scProBaseOpen      (hPIB, wLinkNo, lplpView);
   LPV view = (LPV) *lplpView;

   if ( ERRNUM_IS_FAILURE (e) )
      return e;

   // Your logic here . . .

   return e;
}
#endif



#ifdef DO_scProOrder
VIEWCALL scProOrder     (LPVOID lpView, INT nKey)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseOrder     (lpView, nKey));
   return e;
}
#endif



#ifdef DO_scProPost
VIEWCALL scProPost      (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBasePost      (lpView));
   return e;
}
#endif



#ifdef DO_scProPresents
VIEWCALL scProPresents  (LPVOID lpView, LONG lField, LPSTR lpsMask, LPSHORT lpnList, LPSHORT lpnCount, LPVOID lpBuffer, INT nSize)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBasePresents  (lpView, lField, lpsMask, lpnList, lpnCount, lpBuffer, nSize));
   return e;
}
#endif



#ifdef DO_scProProcess
VIEWCALL scProProcess   (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseProcess   (lpView));
   return e;
}
#endif



#ifdef DO_scProPut
VIEWCALL scProPut       (LPVOID lpView, LONG lField, LPSTR lpsBuffer, INT nSize, BOOL bVerify)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBasePut       (lpView, lField, lpsBuffer, nSize, bVerify));
   return e;
}
#endif



#ifdef DO_scProRead
VIEWCALL scProRead      (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;
   BOOL found = FALSE;

   CHECK_FETCH_UNROLL (e, found, scProBaseRead      (lpView));
   if ( !found )
      return ERRNUM_RECORD_NOT_FOUND;
   return e;
}
#endif



#ifdef DO_scProReadLock
VIEWCALL scProReadLock  (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;
   BOOL found = FALSE;

   CHECK_FETCH_UNROLL (e, found, scProBaseReadLock  (lpView));
   if ( !found )
      return ERRNUM_RECORD_NOT_FOUND;
   return e;
}
#endif



#if defined(DO_scProRecordClear)
VIEWCALL scProRecordClear (LPV view)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseRecordClear (view));
   return e;
}
#endif



#if defined(DO_scProRecordGenerate)
VIEWCALL scProRecordGenerate (LPV view, A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseRecordGenerate (view, flags));
   return e;
}
#endif



#if defined(DO_scProRevisionCancel)
VIEWCALL scProRevisionCancel (LPV view, INT level)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseRevisionCancel (view, level));
   return e;
}
#endif



#if defined(DO_scProRevisionExists)
VIEWCALL scProRevisionExists (LPV view, INT level, LP_A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseRevisionExists (view, level, flags));
   return e;
}
#endif



#if defined(DO_scProRevisionPost)
VIEWCALL scProRevisionPost (LPV view, INT level)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseRevisionPost (view, level));
   return e;
}
#endif



#if defined(DO_scProRevisionRekey)
VIEWCALL scProRevisionRekey (LPV view, LPVOID OldKey, LPVOID NewKey, INT size, A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseRevisionRekey (view, OldKey, NewKey, size, flags));
   return e;
}
#endif



#if defined(DO_scProRevisionUnposted)
VIEWCALL scProRevisionUnposted (LPV view, INT level, LP_A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseRevisionUnposted (view, level, flags));
   return e;
}
#endif



#ifdef DO_scProSecurity
VIEWCALL scProSecurity  (HPIB hPIB, WORD wLinkNo, LPLONG lplPermissions)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseSecurity  (hPIB, wLinkNo, lplPermissions));
   return e;
}
#endif



#if defined(DO_scProTableEmpty)
VIEWCALL scProTableEmpty (LPV view)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseTableEmpty (view));
   return e;
}
#endif



#ifdef DO_scProType
VIEWCALL scProType      (LPVOID lpView, LONG lField, LPTYPE lptype)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseType      (lpView, lField, lptype));
   return e;
}
#endif



#ifdef DO_scProUnLock
VIEWCALL scProUnLock    (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseUnLock    (lpView));
   return e;
}
#endif



#ifdef DO_scProUpdate
VIEWCALL scProUpdate    (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseUpdate    (lpView));
   return e;
}
#endif



#ifdef DO_scProVerify
VIEWCALL scProVerify    (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scProBaseVerify    (lpView));
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
 * functions out of the scPro.c file replacing the ones here. The semantics  *
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
