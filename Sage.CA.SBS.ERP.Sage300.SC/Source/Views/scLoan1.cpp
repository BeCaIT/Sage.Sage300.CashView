/*--------------------------------------------------------------------

    File        :   scLoan1.c
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

#include "scEmail.h"
#include "scUtil.h"

#if defined(__cplusplus)
namespace A4WAPI {
#endif

#include "sc.h"
#include "sc.i"

/////////////////////////////////////////////////////////////////////////////


#include "scLoan.h"
#include "scLoan.i"
#include "scLoan1.h"
#include "scLoan2.h"



//////////////////////////////////////////////////////////////////////
// +++

#include "scValidation.h"
// #include "composite .H file(s)"
#include "a4wuser.h"
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
   {'S','C','L','O','A','N',' ',' '},
   sizeof (RECORD),
   SCLOAN_FLD_COUNT,
   SCLOAN_KEY_COUNT,
   FLG_MP_RECORD,
   SCLOAN_FLD_AUDIT
};

DBTABLE dbtable2Def = {
	{' ',' ',' ',' ',' ',' ',' ',' '},
   sizeof (RECORD2),
   SCLOAN2_FLD_COUNT,
   0,
   0,
   0
};

#endif



#if SCLOAN_FLD_COUNT>0

// Database table field definitions. Modify and add fields as required.
// Note that there must be a primary key and audit stamp fields. Exceptions
// to this are for calculated field tables and subclass view tables.
// There must be one DBFIELD array for each DBTABLE structure defined above.
// This structure is passed directly to dbCreateTable.
DBFIELD dbfieldDefs [SCLOAN_FLD_COUNT] = {
#include "SCLOANF.GEN"
};

DBFIELD dbfield2Defs [SCLOAN2_FLD_COUNT] = {
#include "SCLOAN2F.GEN"
};

#endif



#if SCLOAN_KEY_COUNT>0

// Database table key definitions. This is a variable-length array of WORDs.
// The format consists of a sequence of key definitions, where each key
// definition has three parts: 1) flags, 2) number of segments,
// 3) variable-length list of database field numbers comprising key.
// For each physical database table needed, a ****KeyDef must be defined.
// This structure is passed directly to dbCreateTable.
WORD SCLOANKeyDef [] = {
   0, // flags - no special attributes
   1, // one segments
   SCLOAN_FLD_LOANNUM, // field number (0-origin)
	FLG_KEY_DUPLICATES | FLG_KEY_MODIFIABLE,
	2,
	SCLOAN_FLD_STATUS, SCLOAN_FLD_LOANNUM,
};

//WORD SCLOAN2KeyDef [] = {
//   0, // flags - no special attributes
//   1, // one segments
//   SCLOAN2_FLD_yourkey, // field number (0-origin)
//};

#endif



#if BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT>0

// List of database table definitions. This array is indexed by the tblNo
// member of the fldIdxMap structure in order to determine a view field's
// table, field and key structure. The prior three structures are
// aggregated into each entry below.
extern TBLMAP tables [BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT] = {
   // DBTABLE     DBFIELD       LPWORD
   {&dbtableDef,  dbfieldDefs,  SCLOANKeyDef}, // make one entry for each table
	{&dbtable2Def, dbfield2Defs, NULL      }, // make one entry for each table
};

#endif



#if KEY_COUNT>0

// View key definitions. Used to map from key number to corresponding view
// field information.
extern KEYMAP keyNumMap [KEY_COUNT] = {
   // name rsc ID     segs  array of view field indexes
   {IDS_SCLOAN_KEY_NAME,	1,   {SCLOAN_IDX(LOANNUM)}}, // make one entry for each key
	{IDS_SCLOAN_KEY1_NAME,	2,   {SCLOAN_IDX(STATUS), SCLOAN_IDX(LOANNUM)}}, // make one entry for each key
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
   {0,       1,    {SCLOAN_IDX(yourkey)}}
};

#endif



#if FLD_IDX_COUNT>0

// Mapping from a view field number to a view field index.
// The ordering of this array is not important. Note that field number 0
// is actually at index 0 in this array.
extern LONG fldNumToIdx [FLD_IDX_COUNT] = {
#include "SCLOANX.GEN"
#include "SCLOAN2X.GEN"
};

#endif



// Presentation info: For each field having presentation information
// create a set of initialized structures which will be referenced
// in fldIdxMap.
DECLARE_LIST_NUMS(Status) {
	SCLOAN_STATUS_PENDING,
	SCLOAN_STATUS_SUBMITTED,
	SCLOAN_STATUS_CANCELLED,
	SCLOAN_STATUS_REJECTED,
	SCLOAN_STATUS_APPROVED,
};
DECLARE_LIST_STRS(Status) {
	IDS_SCLOAN_STATUS_PENDING,
	IDS_SCLOAN_STATUS_SUBMITTED,
	IDS_SCLOAN_STATUS_CANCELLED,
	IDS_SCLOAN_STATUS_REJECTED,
	IDS_SCLOAN_STATUS_APPROVED,
};
DECLARE_LIST(Status);


// Field validation function declarations. Those declared here are done as
// examples. Remove, add or edit them as needed.
#include "SCLOANV.GEN"
#include "SCLOAN2V.GEN"

// Mapping from view field index to view field definition, storage and
// presentation. This array is indexed directly by view field index,
// therefore you must ensure that view field index N is at subscript N here.
// If there are any gaps in the assignment of view field indexes, they
// must be marked in here with a tblNo entry of -1.
extern IDXMAP fldIdxMap [IDXIDX(FLD_IDX_LIMIT)] = {
   {0                  , -1}, // view field index 0 reserved by template
#include "SCLOANM.GEN"
#include "SCLOAN2M.GEN"
};


#if CMP_COUNT+MAN_CMP_COUNT>0
// Composite names: all composite names must be listed here, including
// implicit and manual compositions. Their ordering is important:
// header, detail, hierarchy, demand, implicit, then manual composites.
#define	SCOPT_CMP	0
#define	A4WUSER_CMP	1

extern CMPNAME cmpNameList [CMP_COUNT+MAN_CMP_COUNT] = {
   {SCOPT_ROTOID, INSTANCE_OPEN_READONLY},
	//{A4WUSER_VIEW, INSTANCE_OPEN_READONLY, 0, TRUE},
	{A4WUSER_VIEW, INSTANCE_OPEN_READONLY},
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
	{SC_RSC_SCLINQUIRY, (SEC_INQUIRE)},
	{SC_RSC_SCLENTRY	, (SEC_ADD | SEC_MODIFY | SEC_DELETE | SEC_INQUIRE | SEC_POST)},
};
#endif


#ifdef DO_HEADERETC
// Mapping from detail fields to dependent header fields.
// NOTE: It is assumed the type information of each view field index pair
// matches exactly!
extern DETAILMAP headerFields [DO_HEADERETC] = {
   {SCLOAN_IDX(yours), header_IDX(headers)}, // make an entry for each dependent pair
};
#endif



////////////////////////////////////////////////////////////////////////////
// Field validation function declarations. Those defined here are done as
// examples. Remove, add or edit them as needed.


BOOL WINAPI StatusValid(
	LPV lpv,
	LONG lField,
	LPDBSINT lpValue)
{
	LPRECORD lprCurrent = (LPRECORD)FindRecordRead(lpv)[0];

	if (lpv->bExists)
	{
		if ((lprCurrent->status >= SCLOAN_STATUS_CANCELLED)
			|| (*lpValue < lprCurrent->status))
		{
			ReportListError(lpv, lField);
			return FALSE;
		}
	}
	else
	{
		if (*lpValue != SCLOAN_STATUS_PENDING)
		{
			ReportListError(lpv, lField);
			return FALSE;
		}
	}

	return TRUE;
}


BOOL WINAPI AmtRequestValid(
	LPV lpv,
	LONG lField,
	LPMONEY lpAmount)
{
	if ((moneyCompareZero(lpAmount) <= 0)
		|| (moneyCompare((LPMONEY)FindFieldValue(lpv, SCLOAN_IDX(AMTOFFER)), lpAmount) < 0))
	{
		ReportError(lpv, IDERR_SCLOAN_AMOUNT_REQUEST, NULL, NULL, NULL);
		return FALSE;
	}

	return TRUE;
}


BOOL WINAPI EmailFromValid(
	LPV lpv,
	LONG lField,
	LPSTR lpValue)
{
	//if (*(LPWORD)FindFieldValue(lpv, SCLOAN_IDX(STATUS)) <= SCLOAN_STATUS_PENDING)
	//	return TRUE;
	if (lpv->sysAccess == SYSACCESS_POST)
		return TRUE;

	CHAR sEmail[MAX_FIELD_LENGTH + 1];
	strCopyZB(sEmail, lpValue, FindFieldDef(lField)->wLength);

	LPDATUM lpStatus = (LPDATUM)FindFieldValue(lpv, SCLOAN_IDX(STATUS));

	if (utlIsValidEmail(sEmail) || lpStatus->i == SCLOAN_STATUS_PENDING)
		return TRUE;

	ReportError(lpv, IDERR_SC_EMAIL_INVALID, MAKERSC(FindFieldMap(lField)->title), NULL, NULL);
	return FALSE;
}
//BOOL WINAPI LimitValid (
//   LPV lpv,
//   LONG lField,
//   LPMONEY lpmoneyLimit)
//{
//   //if ( ..... ) {
//   //   ReportError (lpv, SC_some_error_code, "arg1", MAKERSC(IDS_arg2), NULL);
//   //   return FALSE;
//   //}
//   return TRUE;
//}
//
//
//
//BOOL WINAPI TypeValid (
//   LPV lpv,
//   LONG lField,
//   LPDBSINT lpnType)
//{
//   //if ( ..... ) {
//   //   ReportError (lpv, SC_some_error_code, "arg1", MAKERSC(IDS_arg2), NULL);
//   //   return FALSE;
//   //}
//   return TRUE;
//}



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
   supplied in the scLoan.c file needs to be augmented. An example is when
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

	if (field != SCLOAN_IDX(LOANNUM))
	{
		WORD wStatus = *FindFieldValue(lpv, SCLOAN_IDX(STATUS));

		if ((field != SCLOAN_IDX(STATUS) && (wStatus > SCLOAN_STATUS_PENDING))
			|| ((field == SCLOAN_IDX(STATUS)) && (wStatus > SCLOAN_STATUS_CANCELLED)))
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
    This function is called by scLoanInit, scLoanRead and scLoanFetch.  All
    other field values have been set.  Sets the values for any calculated
    fields.
*/

VIEWBASE CalculateFields (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;
	
	LPRECORD2 lpr2 = (LPRECORD2)FindRecord(lpv)[1];

	blkCopy(lpr2->brn, lpv->CompanyInfo.sBrn, SIZEOF_COMP_BRN);

	//
	//// Reporting Currency
	switch (lpv->wCountry)
	{
		case SCOPT_COUNTRY_SINGAPORE:
			strCopyBZ(lpr2->rptCur, SIZEOF_CURRENCY_CODE, SC_COUNTRY_CURR_SINGAPORE);
			break;

		case SCOPT_COUNTRY_MALAYSIA:
			strCopyBZ(lpr2->rptCur, SIZEOF_CURRENCY_CODE, SC_COUNTRY_CURR_MALAYSIA);
			break;

		default:
			break;
	}

	//
	//// Email Subject
	//rscLoadText(lpv->hpib, APPL, IDS_SCLOAN_MESSAGE_SG_SUBJECT, lpr2->emailSubj, )
	LoadRsc(lpv->hpib, MAKERSC(IDS_SCLOAN_MESSAGE_SG_SUBJECT), SCLOAN_SIZ(EMAILSUBJ), lpr2->emailSubj, TRUE);

	//
	//// Email From:
	CHAR szEmailSubmit[SIZEOF_EMAIL + 1];
	strCopyZB(szEmailSubmit, FindFieldValue(lpv, SCLOAN_IDX(EMLSUBMIT)), SIZEOF_EMAIL);
	strTrim(szEmailSubmit);
	if (strLength(szEmailSubmit) > 0)
		strCopyBZ(lpr2->emailFrom, SCLOAN_SIZ(EMAILFROM), szEmailSubmit);
	else
		strCopyBZ(lpr2->emailFrom, SCLOAN_SIZ(EMAILFROM), lpv->sUserEmail);

	//
	//// Email To: Trying to load Debug Value before apply hardcoded
	CHAR sEmailTo[SCLOAN_SIZ(EMAILTO)];
	INT iSize = sizeof(sEmailTo);
	if (!GetIniFileKey(lpv->hpib, (LPSTR)APPL, (LPSTR)"Debug", (LPSTR)"EmailTo", sEmailTo, (LPINT)& iSize))
	{
		if (iSize > SCLOAN_SIZ(EMAILTO))
			iSize = SCLOAN_SIZ(EMAILTO);

		strCopyBZ(lpr2->emailTo, iSize, sEmailTo);
	}
	else
	{
		switch (lpv->wCountry)
		{
			case SCOPT_COUNTRY_SINGAPORE:
				strCopyBZ(lpr2->emailTo, SIZEOF_EMAIL, SC_COUNTRY_EMAIL_SINGAPORE);
				break;

			case SCOPT_COUNTRY_MALAYSIA:
				strCopyBZ(lpr2->emailTo, SIZEOF_EMAIL, SC_COUNTRY_EMAIL_MALAYSIA);
				break;

			default:
				break;
		}
	}

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
// Called within: scLoanCancel(), scLoanRevisionCancel()

{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, CancelBodyBase (lpv, level));
   return e;
}

#endif



#ifdef DO_COMPOSEETC
/*--------------------------------------------------------------------
    This function is called by scLoanCompose.
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
// function during scLoanCompose() when the composite's cmpNameList[] entry
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
   ConcurrencyEtc: called when scLoanUpdate is done and there is a concurrency
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
         case SCLOAN_IDX(yours):
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
// callout takes a view handle, even though scLoanCreate() does not. Effectively,
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
    This function is called as a first step by scLoanDelete.  Allows
    the view to check any conditions specific to this view that must
    be met before the record may be deleted.  The ERRNUM is returned
    by scLoanDelete.
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
// be generated for you from scLoanInit

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
    This function is called by scLoanGet after validating the field index,
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
   This function is called by scLoanInsert, scLoanUpdate, and scLoanDelete.
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
   Called during scLoanOpen, in order to initialize the structural definition
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
    This function is called by scLoanInit after all fields have been
    initialized to blanks.  Sets initial values for all non-character
    data types and any strings that should not default to blanks.
*/

VIEWBASE InitNonBlankFields (LPV lpv)
{
   LPRECORD lpr = (LPRECORD) (FindRecord (lpv)) [0];
	LPRECORD2 lpr2 = (LPRECORD2)(FindRecord(lpv)) [1];

	ERRNUM e = ERRNUM_SUCCESS;

	LPVIEWDEF SCOPT = FindCmp(lpv, SCOPT_CMP);

	DBDATE currentDate;
	dtGetDate(&currentDate);

	//
	//// Default status = Pending
	lpr->status = SCLOAN_STATUS_PENDING;

	//
	//// Set Offered date
	dtDateToBCD(&currentDate, lpr->dtOffer);

	//
	//// Convert Client ID
	blkSet(lpr->reference, ' ', SCLOAN_SIZ(REFERENCE));
	licGetClientId(lpv->hpib, lpr->reference);
	licConvertClientId(lpr->reference, SCLOAN_SIZ(REFERENCE));

	//
	//// Load Company Address
	blkCopy(lpr->compName, lpv->CompanyInfo.sName, SIZEOF_COMP_NAME);
	blkCopy(lpr->address1, lpv->CompanyInfo.sAddress1, SIZEOF_COMP_ADDRESS);
	blkCopy(lpr->address2, lpv->CompanyInfo.sAddress2, SIZEOF_COMP_ADDRESS);
	blkCopy(lpr->address3, lpv->CompanyInfo.sAddress3, SIZEOF_COMP_ADDRESS);
	blkCopy(lpr->address4, lpv->CompanyInfo.sAddress4, SIZEOF_COMP_ADDRESS);
	blkCopy(lpr->city, lpv->CompanyInfo.sCity, SIZEOF_COMP_CITY);
	blkCopy(lpr->state, lpv->CompanyInfo.sState, SIZEOF_COMP_STATE);
	blkCopy(lpr->country, lpv->CompanyInfo.sCountry, SIZEOF_COMP_COUNTRY);
	blkCopy(lpr->postal, lpv->CompanyInfo.sPostCode, SIZEOF_COMP_POSTCODE);

	//
	//// Copy default contact values from SCOPT
	if (ERRNUM_IS_SUCCESS(viewRead(SCOPT->rvh, SCOPT->view)))
	{
		CHECK_CALL(e, viewGet(SCOPT->view, SCOPT->view, SCOPT_IDX(CONTACT), lpr->contact, SCOPT_SIZ(CONTACT)));
		CHECK_CALL(e, viewGet(SCOPT->view, SCOPT->view, SCOPT_IDX(JOBTITLE), &lpr->jobTitle, SCOPT_SIZ(JOBTITLE)));
		CHECK_CALL(e, viewGet(SCOPT->view, SCOPT->view, SCOPT_IDX(EMAIL), lpr->email, SCOPT_SIZ(EMAIL)));
		CHECK_CALL(e, viewGet(SCOPT->view, SCOPT->view, SCOPT_IDX(PHONE), lpr->phone, SCOPT_SIZ(PHONE)));
		CHECK_CALL(e, viewGet(SCOPT->view, SCOPT->view, SCOPT_IDX(MOBILE), lpr->mobile, SCOPT_SIZ(MOBILE)));
		CHECK_CALL(e, viewGet(SCOPT->view, SCOPT->view, SCOPT_IDX(COUNTRY), &lpv->wCountry, SCOPT_SIZ(COUNTRY)));

		//
		//// Loan Cap Amount / Loan Request
		switch (lpv->wCountry)
		{
			case SC_COUNTRY_SINGAPORE:
				strToMoney(SC_COUNTRY_LCAP_SINGAPORE, lpr->amtOffer);
				strToMoney(SC_COUNTRY_LCAP_SINGAPORE, lpr->amtRequest);
				break;

			case SC_COUNTRY_MALAYSIA:
				strToMoney(SC_COUNTRY_LCAP_MALAYSIA, lpr->amtOffer);
				strToMoney(SC_COUNTRY_LCAP_MALAYSIA, lpr->amtRequest);
				break;

			case SC_COUNTRY_HONGKONG:
				strToMoney(SC_COUNTRY_LCAP_HONGKONG, lpr->amtOffer);
				strToMoney(SC_COUNTRY_LCAP_HONGKONG, lpr->amtRequest);
				break;

			case SC_COUNTRY_AUSTRALIA:
				strToMoney(SC_COUNTRY_LCAP_AUSTRALIA, lpr->amtOffer);
				strToMoney(SC_COUNTRY_LCAP_AUSTRALIA, lpr->amtRequest);
				break;

			case SC_COUNTRY_NEWZEALAND:
				strToMoney(SC_COUNTRY_LCAP_NEWZEALAND, lpr->amtOffer);
				strToMoney(SC_COUNTRY_LCAP_NEWZEALAND, lpr->amtRequest);
				break;

			default:
				break;
		}
		moneyAssign(lpr->amtRequest, lpr->amtOffer);
	}

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
      case SCLOAN_IDX(trigger1):
         CHECK_CALL (e, NotifyQueueField (lpv, SCLOAN_IDX(dependant1),
                                          INSTANCE_NOTIFY_FIELD_PRESENTATION));
         break;

      case SCLOAN_IDX(trigger2):
      case SCLOAN_IDX(trigger3):
      case SCLOAN_IDX(trigger4):
         CHECK_CALL (e, NotifyQueueField (lpv, SCLOAN_IDX(dependant2),
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
// scLoanOpen and/or scLoanInstanceOpen, since it will simplify maintenance,
// and more importantly will avoid bugs.
VIEWBASE OpenEtc (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;

	LPVIEWDEF A4WUSER = FindCmp(lpv, A4WUSER_CMP);

	blkSet(lpv->sUserEmail, 0, sizeof(lpv->sUserEmail));

	BYTE sUserID[SIZEOF_USERID];
	ibGetUserID(lpv->hpib, sUserID);

	CHECK_CALL(e, OpenOneView(lpv, A4WUSER_CMP));
	CHECK_CALL(e, viewPut(A4WUSER->rvh, A4WUSER->view, A4WUSER_IDX(USERID), sUserID, A4WUSER_SIZ(USERID), FALSE));
	if (ERRNUM_IS_SUCCESS(viewRead(A4WUSER->rvh, A4WUSER->view)))
	{
		CHECK_CALL(e, viewGet(A4WUSER->rvh, A4WUSER->view, A4WUSER_IDX(EMAIL1), lpv->sUserEmail, A4WUSER_SIZ(EMAIL1)));
		strRTrim(lpv->sUserEmail);
		if (strLength(lpv->sUserEmail) == 0)
		{
			CHECK_CALL(e, viewGet(A4WUSER->rvh, A4WUSER->view, A4WUSER_IDX(EMAIL2), lpv->sUserEmail, A4WUSER_SIZ(EMAIL2)));
			strRTrim(lpv->sUserEmail);
		}
	}
	CloseOneView(lpv, A4WUSER_CMP);

	CHECK_CALL(e, OpenOneView(lpv, SCOPT_CMP));

   return e;
}

#endif



#ifdef DO_PREPOSTETC
/*---------------------------------------------------------------------------
   PrePostEtc: per-detail call-out for scLoanPost(). As each change from the
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

// Callout invoked by scLoanProcess().  Does all processing.

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
    This function is called by scLoanPut as a last step.  Does any
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

// This callout is invoked during scLoanRevisionRekey(), after each record has
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
   errPutGeneric (lpv->hpib, APPL, MAKERSC (IDS_SCLOAN_VIEW_NAME), NULL,
                  area, op, MAKERSC (ERRGEN_CAT_DEFAULT), error, extra);
}

#endif



#if defined(DO_REPORTGENERICERRORVIAPIB)

void WINAPI ReportGenericErrorViaPIB (HPIB pib, WORD area, WORD op, WORD error, LPVOID extra)
{
   CHAR noun [RSC_MAX_MESSAGE];

   errPutGeneric (pib, APPL, MAKERSC (IDS_SCLOAN_VIEW_NAME), NULL,
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
// Called within: scLoanPost(), scLoanRevisionPost()

{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, RevisionInnerPostBase (lpv, level));
   return e;
}

#endif



#ifdef DO_REVPOSTETC
/*---------------------------------------------------------------------------
   revPostEtc: per-detail call-out for scLoanPost(). As each change from the
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
         e = scLoanYours  (v->view, v->field, v->p);
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
         e = scLoanYours  (v->view, v->field, v->p);
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

// This function is called by scLoanVerify after each field has been
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

// Called by scLoanVerify when a field is a key in a composite
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
// by calling scLoanBaseYYYY from within each respecive scLoanYYYY here.
// These overrides allow you to process before, after, or instead of
// the original view template behaviour.

// +++



#ifdef DO_scLoanAttribs
VIEWCALL scLoanAttribs   (LPVOID lpView, LONG lField, LPLONG lpAttributes)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseAttribs   (lpView, lField, lpAttributes));
   return e;
}
#endif



#ifdef DO_scLoanBlkGet
VIEWCALL scLoanBlkGet    (LPVOID lpView, INT lFields, LPLONG lFieldList, LPSHORT lpnSizeList, LPSTR lpsBuffer)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseBlkGet    (lpView, lFields, lFieldList, lpnSizeList, lpsBuffer));
   return e;
}
#endif



#ifdef DO_scLoanBlkPut
VIEWCALL scLoanBlkPut    (LPVOID lpView, INT lFields, LPLONG lFieldList, LPSHORT lpnSizeList, LPSTR lpsBuffer, BOOL bVerify)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseBlkPut    (lpView, lFields, lFieldList, lpnSizeList, lpsBuffer, bVerify));
   return e;
}
#endif



#ifdef DO_scLoanBrowse
VIEWCALL scLoanBrowse    (LPVOID lpView, LPSTR lpsExpression, BOOL bAscending)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseBrowse    (lpView, lpsExpression, bAscending));
   return e;
}
#endif



#ifdef DO_scLoanCancel
VIEWCALL scLoanCancel    (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseCancel    (lpView));
   return e;
}
#endif



#ifdef DO_scLoanClose
VIEWCALL scLoanClose     (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

	CloseOneView(lpv, SCOPT_CMP);

   CHECK_CALL (e, scLoanBaseClose     (lpView));
   return e;
}
#endif



#ifdef DO_scLoanCmpNames
VIEWCALL scLoanCmpNames  (INT roto, LPSTR lpsCompositeNames, LPSHORT lpnCount)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseCmpNames  (roto, lpsCompositeNames, lpnCount));
   return e;
}
#endif



#ifdef DO_scLoanCompose
VIEWCALL scLoanCompose   (LPVOID lpView, LPVIEWDEF lpvdefComposites)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseCompose   (lpView, lpvdefComposites));
   return e;
}
#endif



#ifdef DO_scLoanCreate
VIEWCALL scLoanCreate    (HPIB hPIB, WORD wLinkNo)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseCreate    (hPIB, wLinkNo));
   return e;
}
#endif



#ifdef DO_scLoanDelete
VIEWCALL scLoanDelete    (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseDelete    (lpView));
   return e;
}
#endif



#ifdef DO_scLoanDirty
VIEWCALL scLoanDirty     (LPVOID lpView, LPBOOL bChanged)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseDirty     (lpView, bChanged));
   return e;
}
#endif



#ifdef DO_scLoanDrop
VIEWCALL scLoanDrop      (HPIB hPIB, WORD wLinkNo)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseDrop      (hPIB, wLinkNo));
   return e;
}
#endif



#ifdef DO_scLoanExists
VIEWCALL scLoanExists    (LPVOID lpView, LPBOOL bExists)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseExists    (lpView, bExists));
   return e;
}
#endif



#ifdef DO_scLoanFetch
VIEWCALL scLoanFetch     (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;
   BOOL found = FALSE;

   CHECK_FETCH_UNROLL (e, found, scLoanBaseFetch     (lpView));
   if ( !found )
      return ERRNUM_RECORD_NO_MORE_DATA;
   return e;
}
#endif



#ifdef DO_scLoanFetchLock
VIEWCALL scLoanFetchLock (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;
   BOOL found = FALSE;

   CHECK_FETCH_UNROLL (e, found, scLoanBaseFetchLock (lpView));
   if ( !found )
      return ERRNUM_RECORD_NO_MORE_DATA;
   return e;
}
#endif



#ifdef DO_scLoanField
VIEWCALL scLoanField     (LPVOID lpView, INT nFldNumber, LPSTR lpsFldName, LPLONG lField)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseField     (lpView, nFldNumber, lpsFldName, lField));
   return e;
}
#endif



#ifdef DO_scLoanFieldExists
VIEWCALL scLoanFieldExists (
   LPV view,
   LONG lField,
   LP_A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   MaxError (&e, scLoanBaseFieldExists (view, lField, flags));
   return e;
}
#endif



#ifdef DO_scLoanFieldName
VIEWCALL scLoanFieldName (
   LPV view,
   LONG lField,
   LPSTR lpsName,
   LPSTR lpsDesc,
   A4W_SIZE size)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseFieldName (view, lField, lpsName, lpsDesc, size));
   return e;
}
#endif


#ifdef DO_scLoanFields
VIEWCALL scLoanFields    (LPVOID lpView, LPSHORT lFields)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseFields    (lpView, lFields));
   return e;
}
#endif



#if defined(DO_scLoanFilterCount)
VIEWCALL scLoanFilterCount (LPV view, LPSTR expression, A4W_FLAGS flags, LP_A4W_SIZE count)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseFilterCount (view, expression, flags, count));
   return e;
}
#endif



#if defined(DO_scLoanFilterDelete)
VIEWCALL scLoanFilterDelete (LPV view, LPSTR filter, A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseFilterDelete (view, filter, flags));
   return e;
}
#endif



#if defined(DO_scLoanFilterFetch)
VIEWCALL scLoanFilterFetch (LPV view, A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;
   BOOL found = FALSE;

   CHECK_FETCH_UNROLL (e, found, scLoanBaseFilterFetch (view, flags));
   if ( !found )
      return ERRNUM_RECORD_NO_MORE_DATA;
   return e;
}
#endif



#if defined(DO_scLoanFilterSelect)
VIEWCALL scLoanFilterSelect (LPV view, INT key, LPSTR filter, A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseFilterSelect (view, key, filter, flags));
   return e;
}
#endif



#ifdef DO_scLoanGet
VIEWCALL scLoanGet       (LPVOID lpView, LONG lField, LPSTR buffer, INT nSize)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseGet       (lpView, lField, buffer, nSize));
   return e;
}
#endif



#ifdef DO_scLoanInit
VIEWCALL scLoanInit      (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseInit      (lpView));
   return e;
}
#endif



#ifdef DO_scLoanInsert
VIEWCALL scLoanInsert    (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

	//
	//// Set Loan Number
	CHAR szDate[9];
	bcdToZStr((PCBYTE)FindFieldValue(lpv, SCLOAN_IDX(DTOFFER)), SIZEOF_DATE, 0, szDate, 9, 0);
	CHAR szLOANNUM[SCLOAN_SIZ(LOANNUM) + 1];
	sprintf(szLOANNUM, "SGSCB%08s", szDate);
	strCopyBZ(FindFieldValue(lpv, SCLOAN_IDX(LOANNUM)), SCLOAN_SIZ(LOANNUM), szLOANNUM);


   CHECK_CALL (e, scLoanBaseInsert    (lpView));
   return e;
}
#endif



#if defined(DO_scLoanInstanceFieldList)
VIEWCALL scLoanInstanceFieldList (LPV view, A4W_NOTIFY_PROC notify, LPVOID context, A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseInstanceFieldList (view, flags, count, fields));
   return e;
}
#endif



#if defined(DO_scLoanInstanceNotify)
VIEWCALL scLoanInstanceNotify (LPV view, A4W_NOTIFY_PROC notify, LPVOID context, A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseInstanceNotify (view, notify, context, flags));
   return e;
}
#endif



#if defined(DO_scLoanInstanceOpen)
VIEWCALL scLoanInstanceOpen (LPRVH rvh, HPIB PIB, WORD link, A4W_FLAGS flags, LPVOID extra, A4W_SIZE size, LPV FAR * lplpView)
{
   ERRNUM e = scLoanBaseInstanceOpen (rvh, PIB, link, flags, extra, size, lplpView);
   LPV view = *lplpView;

   if ( ERRNUM_IS_FAILURE (e) )
      return e;

   // Your logic here . . .

   return e;
}
#endif



#if defined(DO_scLoanInstanceProtocol)
VIEWCALL scLoanInstanceProtocol (LPV view, A4W_FLAGS flags, LP_A4W_FLAGS protocols, LP_A4W_SIZE count)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseInstanceProtocol (view, flags, protocols, count));
   return e;
}
#endif



#if defined(DO_scLoanInstanceSecurity)
VIEWCALL scLoanInstanceSecurity (LPV view, LP_A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseInstanceSecurity (view, flags));
   return e;
}
#endif



#ifdef DO_scLoanKey
VIEWCALL scLoanKey       (LPVOID lpView, INT nKeyNo, LPSTR sName, LPSHORT lFields, LPLONG lplKeyFields)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseKey       (lpView, nKeyNo, sName, lFields, lplKeyFields));
   return e;
}
#endif



#ifdef DO_scLoanKeys
VIEWCALL scLoanKeys      (LPVOID lpView, LPSHORT lpnKeys)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseKeys      (lpView, lpnKeys));
   return e;
}
#endif



#ifdef DO_scLoanName
VIEWCALL scLoanName      (LPVOID lpView, LONG lField, LPSTR lpsName, LPSTR lpsDesc)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseName      (lpView, lField, lpsName, lpsDesc));
   return e;
}
#endif



#ifdef DO_scLoanOpen
VIEWCALL scLoanOpen      (HPIB hPIB, WORD wLinkNo, LPVOID FAR * lplpView)
{
   ERRNUM e = scLoanBaseOpen      (hPIB, wLinkNo, lplpView);
   LPV view = (LPV) *lplpView;

   if ( ERRNUM_IS_FAILURE (e) )
      return e;

   // Your logic here . . .

   return e;
}
#endif



#ifdef DO_scLoanOrder
VIEWCALL scLoanOrder     (LPVOID lpView, INT nKey)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseOrder     (lpView, nKey));
   return e;
}
#endif



#ifdef DO_scLoanPost
VIEWCALL scLoanPost      (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBasePost      (lpView));
   return e;
}
#endif



#ifdef DO_scLoanPresents
VIEWCALL scLoanPresents  (LPVOID lpView, LONG lField, LPSTR lpsMask, LPSHORT lpnList, LPSHORT lpnCount, LPVOID lpBuffer, INT nSize)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

	LPVIEWDEF SCOPT = FindCmp(lpv, SCOPT_CMP);

	switch (lField)
	{
		case SCLOAN_IDX(JOBTITLE):
			CHECK_CALL(e, viewPresents(SCOPT->rvh, SCOPT->view, SCOPT_IDX(JOBTITLE), lpsMask, lpnList, lpnCount, (LPSTR)lpBuffer, nSize));
			break;

		default:
			CHECK_CALL(e, scLoanBasePresents(lpView, lField, lpsMask, lpnList, lpnCount, lpBuffer, nSize));
			break;
	}

   return e;
}
#endif



#ifdef DO_scLoanProcess
VIEWCALL scLoanProcess   (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseProcess   (lpView));
   return e;
}
#endif



#ifdef DO_scLoanPut
VIEWCALL scLoanPut       (LPVOID lpView, LONG lField, LPSTR lpsBuffer, INT nSize, BOOL bVerify)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBasePut       (lpView, lField, lpsBuffer, nSize, bVerify));
   return e;
}
#endif



#ifdef DO_scLoanRead
VIEWCALL scLoanRead      (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;
   BOOL found = FALSE;

   CHECK_FETCH_UNROLL (e, found, scLoanBaseRead      (lpView));
   if ( !found )
      return ERRNUM_RECORD_NOT_FOUND;
   return e;
}
#endif



#ifdef DO_scLoanReadLock
VIEWCALL scLoanReadLock  (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;
   BOOL found = FALSE;

   CHECK_FETCH_UNROLL (e, found, scLoanBaseReadLock  (lpView));
   if ( !found )
      return ERRNUM_RECORD_NOT_FOUND;
   return e;
}
#endif



#if defined(DO_scLoanRecordClear)
VIEWCALL scLoanRecordClear (LPV view)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseRecordClear (view));
   return e;
}
#endif



#if defined(DO_scLoanRecordGenerate)
VIEWCALL scLoanRecordGenerate (LPV view, A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseRecordGenerate (view, flags));
   return e;
}
#endif



#if defined(DO_scLoanRevisionCancel)
VIEWCALL scLoanRevisionCancel (LPV view, INT level)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseRevisionCancel (view, level));
   return e;
}
#endif



#if defined(DO_scLoanRevisionExists)
VIEWCALL scLoanRevisionExists (LPV view, INT level, LP_A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseRevisionExists (view, level, flags));
   return e;
}
#endif



#if defined(DO_scLoanRevisionPost)
VIEWCALL scLoanRevisionPost (LPV view, INT level)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseRevisionPost (view, level));
   return e;
}
#endif



#if defined(DO_scLoanRevisionRekey)
VIEWCALL scLoanRevisionRekey (LPV view, LPVOID OldKey, LPVOID NewKey, INT size, A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseRevisionRekey (view, OldKey, NewKey, size, flags));
   return e;
}
#endif



#if defined(DO_scLoanRevisionUnposted)
VIEWCALL scLoanRevisionUnposted (LPV view, INT level, LP_A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseRevisionUnposted (view, level, flags));
   return e;
}
#endif



#ifdef DO_scLoanSecurity
VIEWCALL scLoanSecurity  (HPIB hPIB, WORD wLinkNo, LPLONG lplPermissions)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseSecurity  (hPIB, wLinkNo, lplPermissions));
   return e;
}
#endif



#if defined(DO_scLoanTableEmpty)
VIEWCALL scLoanTableEmpty (LPV view)
{
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseTableEmpty (view));
   return e;
}
#endif



#ifdef DO_scLoanType
VIEWCALL scLoanType      (LPVOID lpView, LONG lField, LPTYPE lptype)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseType      (lpView, lField, lptype));
   return e;
}
#endif



#ifdef DO_scLoanUnLock
VIEWCALL scLoanUnLock    (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseUnLock    (lpView));
   return e;
}
#endif



#ifdef DO_scLoanUpdate
VIEWCALL scLoanSubmit(
	LPV lpv,
	BOOL bFirstSubmit)
{
	ERRNUM e = ERRNUM_SUCCESS;

	LPRECORD lpr = (LPRECORD)FindRecord(lpv)[0];
	LPRECORD2 lpr2 = (LPRECORD2)FindRecord(lpv)[1];

	LPVIEWDEF SCOPT = FindCmp(lpv, SCOPT_CMP);
	
	CHAR szEmailHost[SCOPT_SIZ(EMAILHOST) + 1];
	CHAR szEmailUser[SCOPT_SIZ(EMAILUSER) + 1];
	BYTE abEmailPassword[SCOPT_SIZ(EMAILPSWD)];
	CHAR szEmailPassword[SCOPT_SIZ(EMAILPSWD) + 1];
	CHAR szEmailFrom[SIZEOF_EMAIL + 1];
	CHAR szEmailTo[SIZEOF_EMAIL + 1];
	CHAR szEmailCC[SIZEOF_EMAIL + 1];
	CHAR szEmailCCFull[MAX_RECORD_LENGTH + 1];
	WORD wEmailPort;
	DBSBOOL bEmailSSL;
	CHAR szEmailSubjectTemplate[SCLOAN_SIZ(EMAILSUBJ) + 1];
	CHAR szEmailSubject[SCLOAN_SIZ(EMAILSUBJ) + 1];
	CHAR szEmailSubjectResend[SCLOAN_SIZ(EMAILSUBJ) + 1];
	//
	CHAR szEmailBodyTemplate[MAX_RECORD_LENGTH + 1];
	CHAR szEmailBody[MAX_RECORD_LENGTH + MAX_RECORD_LENGTH + 1];
	CHAR szEmailTC[MAX_RECORD_LENGTH + 1];
	CHAR szEmailFull[MAX_RECORD_LENGTH + MAX_RECORD_LENGTH + 1];

	strInit(szEmailHost);
	strInit(szEmailUser);
	strInit(szEmailPassword);
	strInit(szEmailFrom);
	strInit(szEmailTo);
	strInit(szEmailCC);
	strInit(szEmailCCFull);
	strInit(szEmailSubject);
	strInit(szEmailBodyTemplate);
	strInit(szEmailBody);
	strInit(szEmailTC);
	strInit(szEmailFull);

	CHECK_CALL(e, viewRead(SCOPT->rvh, SCOPT->view));

	CHECK_CALL(e, viewGet(SCOPT->rvh, SCOPT->view, SCOPT_IDX(EMAILHOST), szEmailHost, SCOPT_SIZ(EMAILHOST)));
	CHECK_CALL(e, viewGet(SCOPT->rvh, SCOPT->view, SCOPT_IDX(EMAILUSER), szEmailUser, SCOPT_SIZ(EMAILUSER)));
	CHECK_CALL(e, viewGet(SCOPT->rvh, SCOPT->view, SCOPT_IDX(EMAILPSWD), abEmailPassword, SCOPT_SIZ(EMAILPSWD)));
	CHECK_CALL(e, viewGet(SCOPT->rvh, SCOPT->view, SCOPT_IDX(EMAILPORT), &wEmailPort, SCOPT_SIZ(EMAILPORT)));
	CHECK_CALL(e, viewGet(SCOPT->rvh, SCOPT->view, SCOPT_IDX(EMAILSSL), &bEmailSSL, SCOPT_SIZ(EMAILSSL)));

	strTrim(szEmailHost);
	strTrim(szEmailUser);
	strEncrypt((LPBYTE)szEmailPassword, abEmailPassword, SCOPT_SIZ(EMAILPSWD));
	strTrim(szEmailPassword);
	strCopyZB(szEmailFrom, lpr2->emailFrom, SCLOAN_SIZ(EMAILFROM));
	strCopyZB(szEmailTo, lpr2->emailTo, SCLOAN_SIZ(EMAILTO));
	//
	strCopyZB(szEmailCC, lpr->emailCC, SCLOAN_SIZ(EMAILCC));
	strCopyZB(szEmailCCFull, lpr->email, SCLOAN_SIZ(EMAIL));
	strAppend(szEmailCCFull, ";");
	strAppend(szEmailCCFull, szEmailCC);
	strAppend(szEmailCCFull, ";");
	strAppend(szEmailCCFull, szEmailFrom);
	//
	strCopyZB(szEmailSubjectTemplate, lpr2->emailSubj, SCLOAN_SIZ(EMAILSUBJ));
	strTrim(szEmailSubjectTemplate);
	if (bFirstSubmit)
	{
		strCopy(szEmailSubject, szEmailSubjectTemplate);
	}
	else
	{
		LoadRsc(lpv->hpib, MAKERSC(IDS_SCLOAN_MESSAGE_RESEND), sizeof(szEmailSubjectResend), szEmailSubjectResend, TRUE);
		sprintf(szEmailSubject, szEmailSubjectResend, szEmailSubjectTemplate);
	}


	//
	//// Format email Message
	CHAR	szDate[SIZEOF_STD_DESC + 1];
	dtBCDDateToZStr(lpr->dtSubmit, sizeof(szDate), szDate);
	CHAR	szAmountOffer[SIZEOF_BCDSTR + 1];
	CHAR	szAmountOfferFmt[SIZEOF_BCDSTR + 1];
	CHAR	szAmountRequest[SIZEOF_BCDSTR + 1];
	CHAR	szAmountRequestFmt[SIZEOF_BCDSTR + 1];
	strInit(szAmountOffer);
	strInit(szAmountOfferFmt);
	strInit(szAmountRequest);
	strInit(szAmountRequestFmt);
	moneyToStr(lpr->amtOffer, szAmountOffer, SIZEOF_BCDSTR, MONEY_DECIMALS);
	moneyToStr(lpr->amtRequest, szAmountRequest, SIZEOF_BCDSTR, MONEY_DECIMALS);
	strTrim(szAmountOffer);
	strTrim(szAmountRequest);
	GetNumberFormat(LOCALE_SYSTEM_DEFAULT, LOCALE_NOUSEROVERRIDE, szAmountOffer, NULL, szAmountOfferFmt, SIZEOF_BCDSTR + 1);
	GetNumberFormat(LOCALE_SYSTEM_DEFAULT, LOCALE_NOUSEROVERRIDE, szAmountRequest, NULL, szAmountRequestFmt, SIZEOF_BCDSTR + 1);
	rscLoadHTML(lpv->hpib, APPL, 27021, szEmailBodyTemplate, sizeof(szEmailBodyTemplate));
	sprintf(szEmailBody, szEmailBodyTemplate,
		szDate, // Date
		lpr->reference,
		szAmountOfferFmt,
		szAmountRequestFmt,
		lpr->contact,
		lpr->compName,
		lpr->address1,
		lpr->address2,
		lpr->address3,
		lpr->address4,
		lpr->city,
		lpr->state,
		lpr->country,
		lpr->postal,
		lpr->phone,
		lpr->mobile,
		lpr->email,
		lpr->message);
	//
	//// Adding T&C to email message
	switch (lpv->wCountry)
	{
	case SCOPT_COUNTRY_SINGAPORE:
		rscLoadHTML(lpv->hpib, APPL, 27022, szEmailTC, sizeof(szEmailTC));
		break;

	case SCOPT_COUNTRY_MALAYSIA:
		rscLoadHTML(lpv->hpib, APPL, 24582, szEmailTC, sizeof(szEmailTC));
		break;

	default:
		break;
	}
	sprintf(szEmailFull, "%s<br />%s", szEmailBody, szEmailTC);

	if (!emailSend(
		szEmailHost,
		wEmailPort,
		bEmailSSL,
		szEmailUser,
		szEmailPassword,
		szEmailFrom,
		szEmailTo,
		szEmailCCFull,
		szEmailSubject,
		szEmailFull,
		NULL))
	{
		return ERRNUM_SUCCESS;
	}

	ReportError(lpv, IDERR_SCLOAN_SUBMIT_FAILED, NULL, NULL, NULL);
	return SCLOAN_ERROR_SUBMIT_FAILED;
}

VIEWCALL scLoanUpdate    (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

	LPRECORD lpr = (LPRECORD)FindRecord(lpv)[0];

	CHECK_CALL(e, scLoanVerify(lpv));
	if (!ERRNUM_IS_SUCCESS(e))
		return e;

	//
	//// Check if status == Submit
	if (lpr->status == SCLOAN_STATUS_SUBMITTED)
	{
		BOOL bFirstSubmit = (bcdCompareZero(lpr->dtSubmit, SIZEOF_DATE) == 0);

		if (bFirstSubmit)
		{
			//
			//// Update Submit Date & User
			DBDATE currentDate;
			dtGetDate(&currentDate);
			dtDateToBCD(&currentDate, lpr->dtSubmit);
			ibGetUserID(lpv->hpib, (LPBYTE)lpr->usrSubmit);

			blkCopy(lpr->emlSubmit, FindFieldValue(lpv, SCLOAN_IDX(EMAILFROM)), SIZEOF_EMAIL);
		}

		//
		//// Submit Loan Request
		CHECK_CALL(e, scLoanSubmit(lpv, bFirstSubmit));
	}

	CHECK_CALL(e, scLoanBaseUpdate(lpView));

	return e;
}
#endif



#ifdef DO_scLoanVerify
VIEWCALL scLoanVerify    (LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   CHECK_CALL (e, scLoanBaseVerify    (lpView));
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
 * functions out of the scLoan.c file replacing the ones here. The semantics  *
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
