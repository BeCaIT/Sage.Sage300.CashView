/*--------------------------------------------------------------------

    File        :   scInit.c
    Purpose     :   Standard view code that does not require any
                    changes (once instantiated by MKINST.EXE)

    Copyright (c) 1993-2014 Sage Software, Inc.  All rights reserved.

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

#define __scInit_c

#include "scInit.h"
#include "scInit.i"
#include "scInit1.h"
#include "scInit2.h"



#if ! defined LINUX_VER
#pragma warning (disable: 4101 4102)
#endif /* LINUX_VER */



TYPEOPERATIONS BCDOperations       = {isZeroDeltaBCD,     AddDeltaBCD,     SubtractDeltaBCD     };
TYPEOPERATIONS ByteOperations      = {isZeroDeltaByte,    AddDeltaByte,    SubtractDeltaByte    };
TYPEOPERATIONS IntegerOperations   = {isZeroDeltaInteger, AddDeltaInteger, SubtractDeltaInteger };
TYPEOPERATIONS LongOperations      = {isZeroDeltaLong,    AddDeltaLong,    SubtractDeltaLong    };
TYPEOPERATIONS StringOperations    = {isZeroDeltaString,  AddDeltaString,  SubtractDeltaString  };
TYPEOPERATIONS RealOperations      = {isZeroDeltaReal,    AddDeltaReal,    SubtractDeltaReal    };

LPTYPEOPERATIONS aTypeOperations [FT_BOOL+1] = {
/*       */ NULL,
/*FT_CHAR*/ &StringOperations,
/*FT_BYTE*/ &ByteOperations,
/*FT_DATE*/ NULL,
/*FT_TIME*/ NULL,
/*FT_REAL*/ &RealOperations,
/*FT_BCD */ &BCDOperations,
/*FT_INT */ &IntegerOperations,
/*FT_LONG*/ &LongOperations,
/*FT_BOOL*/ NULL,
};

FIELDCOMPARATOR aTypeComparators [FT_BOOL+1] = {
/*       */ NULL,
/*FT_CHAR*/ StringComparator,
/*FT_BYTE*/ BinaryComparator,
/*FT_DATE*/ DecimalComparator,
/*FT_TIME*/ DecimalComparator,
/*FT_REAL*/ RealComparator,
/*FT_BCD */ DecimalComparator,
/*FT_INT */ IntegerComparator,
/*FT_LONG*/ LongComparator,
/*FT_BOOL*/ IntegerComparator,
};



/////////////////////////////////////////////////////////////////////////////
// Helper function overrides, when not overridden

#if !defined(DO_APPLYHEADERFIELDS)
 #define ApplyHeaderFieldsBase   ApplyHeaderFields
#endif

#if !defined(DO_BASENOTIFY)
 #define BaseNotifyBase          BaseNotify
#endif

#if !defined(DO_CANCELBODY)
 #define CancelBodyBase          CancelBody
#endif

#if !defined(DO_COMPOSITENOTIFY)
 #define CompositeNotifyBase     CompositeNotify
 #define CompositeNotifyEntry    CompositeNotify
#endif

#if !defined(DO_DELETEBODY)
 #define DeleteBodyBase          DeleteBody
#endif

#if !defined(DO_DELETEDETAILSBODY)
 #define DeleteDetailsBodyBase   DeleteDetailsBody
#endif

#if !defined(DO_ENTRYSTATEPUSH)
 #define EntryStatePushBase      EntryStatePush
#endif

#if !defined(DO_ENTRYSTATEPOP)
 #define EntryStatePopBase       EntryStatePop
#endif

#if !defined(DO_INITBODYGEN)
 #define InitBodyGenBase         InitBodyGen
#endif

#if !defined(DO_MAPTODETAIL)
 #define MapToDetailBase         MapToDetail
#endif

#if !defined(DO_NOTIFYFIRE)
 #define NotifyFireBase          NotifyFire
#endif

#if !defined(DO_PUTCMPKEY)
 #define PutCmpKeyBase           PutCmpKey
#endif

#if !defined(DO_REVERSEHEADERFIELDS)
 #define ReverseHeaderFieldsBase ReverseHeaderFields
#endif

#if !defined(DO_REVISIONINNERPOST)
 #define RevisionInnerPostBase   RevisionInnerPost
#endif

#if !defined(DO_ROTOENTRY)
 #define rotoEntryBase           rotoEntry
#endif

#if !defined(DO_SAVEHEADERFIELDS)
 #define SaveHeaderFieldsBase    SaveHeaderFields
#endif

#if !defined(DO_XXXFETCHFILTER)
 #define xxxFetchFilterBase      xxxFetchFilter
#endif

#if !defined(DO_XXXREAD)
 #define xxxReadBase             xxxRead
#endif



/////////////////////////////////////////////////////////////////////////////
// Entrypoint overrides, when not overridden

#if !defined(DO_scInitAttribs)
 #define scInitBaseAttribs         scInitAttribs
#endif

#if !defined(DO_scInitBlkGet)
 #define scInitBaseBlkGet          scInitBlkGet
#endif

#if !defined(DO_scInitBlkPut)
 #define scInitBaseBlkPut          scInitBlkPut
#endif

#if !defined(DO_scInitBrowse)
 #define scInitBaseBrowse          scInitBrowse
#endif

#if !defined(DO_scInitCancel)
 #define scInitBaseCancel          scInitCancel
#endif

#if !defined(DO_scInitClose)
 #define scInitBaseClose           scInitClose
#endif

#if !defined(DO_scInitCmpNames)
 #define scInitBaseCmpNames        scInitCmpNames
#endif

#if !defined(DO_scInitCompose)
 #define scInitBaseCompose         scInitCompose
#endif

#if !defined(DO_scInitCreate)
 #define scInitBaseCreate          scInitCreate
#endif

#if !defined(DO_scInitDelete)
 #define scInitBaseDelete          scInitDelete
#endif

#if !defined(DO_scInitDirty)
 #define scInitBaseDirty           scInitDirty
#endif

#if !defined(DO_scInitDrop)
 #define scInitBaseDrop            scInitDrop
#endif

#if !defined(DO_scInitExists)
 #define scInitBaseExists          scInitExists
#endif

#if !defined(DO_scInitFetch)
 #define scInitBaseFetch           scInitFetch
#endif

#if !defined(DO_scInitFetchLock)
 #define scInitBaseFetchLock       scInitFetchLock
#endif

#if !defined(DO_scInitField)
 #define scInitBaseField           scInitField
#endif

#if !defined(DO_scInitFieldExists)
 #define scInitBaseFieldExists     scInitFieldExists
#endif

#if !defined(DO_scInitFieldName)
 #define scInitBaseFieldName       scInitFieldName
#endif

#if !defined(DO_scInitFields)
 #define scInitBaseFields          scInitFields
#endif

#if !defined(DO_scInitFilterCount)
 #define scInitBaseFilterCount     scInitFilterCount
#endif

#if !defined(DO_scInitFilterDelete)
 #define scInitBaseFilterDelete    scInitFilterDelete
#endif

#if !defined(DO_scInitFilterFetch)
 #define scInitBaseFilterFetch     scInitFilterFetch
#endif

#if !defined(DO_scInitFilterSelect)
 #define scInitBaseFilterSelect    scInitFilterSelect
#endif

#if !defined(DO_scInitGet)
 #define scInitBaseGet             scInitGet
#endif

#if !defined(DO_scInitInit)
 #define scInitBaseInit            scInitInit
#endif

#if !defined(DO_scInitInsert)
 #define scInitBaseInsert          scInitInsert
#endif

#if !defined(DO_scInitInstanceFieldList)
 #define scInitBaseInstanceFieldList  scInitInstanceFieldList
#endif

#if !defined(DO_scInitInstanceNotify)
 #define scInitBaseInstanceNotify  scInitInstanceNotify
#endif

#if !defined(DO_scInitInstanceOpen)
 #define scInitBaseInstanceOpen    scInitInstanceOpen
#endif

#if !defined(DO_scInitInstanceProtocol)
 #define scInitBaseInstanceProtocol scInitInstanceProtocol
#endif

#if !defined(DO_scInitInstanceSecurity)
 #define scInitBaseInstanceSecurity scInitInstanceSecurity
#endif

#if !defined(DO_scInitKey)
 #define scInitBaseKey             scInitKey
#endif

#if !defined(DO_scInitKeys)
 #define scInitBaseKeys            scInitKeys
#endif

#if !defined(DO_scInitName)
 #define scInitBaseName            scInitName
#endif

#if !defined(DO_scInitOpen)
 #define scInitBaseOpen            scInitOpen
#endif

#if !defined(DO_scInitOrder)
 #define scInitBaseOrder           scInitOrder
#endif

#if !defined(DO_scInitPost)
 #define scInitBasePost            scInitPost
#endif

#if !defined(DO_scInitPresents)
 #define scInitBasePresents        scInitPresents
#endif

#if !defined(DO_scInitProcess)
 #define scInitBaseProcess         scInitProcess
#endif

#if !defined(DO_scInitPut)
 #define scInitBasePut             scInitPut
#endif

#if !defined(DO_scInitRead)
 #define scInitBaseRead            scInitRead
#endif

#if !defined(DO_scInitReadLock)
 #define scInitBaseReadLock        scInitReadLock
#endif

#if !defined(DO_scInitRecordClear)
  #define scInitBaseRecordClear    scInitRecordClear
#endif

#if !defined(DO_scInitRecordGenerate)
  #define scInitBaseRecordGenerate scInitRecordGenerate
#endif

#if !defined(DO_scInitRevisionCancel)
 #define scInitBaseRevisionCancel  scInitRevisionCancel
#endif

#if !defined(DO_scInitRevisionExists)
 #define scInitBaseRevisionExists  scInitRevisionExists
#endif

#if !defined(DO_scInitRevisionPost)
 #define scInitBaseRevisionPost    scInitRevisionPost
#endif

#if !defined(DO_scInitRevisionRekey)
 #define scInitBaseRevisionRekey   scInitRevisionRekey
#endif

#if !defined(DO_scInitRevisionUnposted)
 #define scInitBaseRevisionUnposted scInitRevisionUnposted
#endif

#if !defined(DO_scInitSecurity)
 #define scInitBaseSecurity        scInitSecurity
#endif

#if !defined(DO_scInitTableEmpty)
 #define scInitBaseTableEmpty      scInitTableEmpty
#endif

#if !defined(DO_scInitType)
 #define scInitBaseType            scInitType
#endif

#if !defined(DO_scInitUnLock)
 #define scInitBaseUnLock          scInitUnLock
#endif

#if !defined(DO_scInitUpdate)
 #define scInitBaseUpdate          scInitUpdate
#endif

#if !defined(DO_scInitVerify)
 #define scInitBaseVerify          scInitVerify
#endif



//////////////////////////////////////////////////////////////////////////////
// Entrypoint remapping for extended error code mapping



#if DO_EXTENDEDERRORS>=PROCESS_EXTENDEDERRORS

#define scInitExtendedBaseAttribs           scInitBaseAttribs
#define scInitExtendedBaseBlkGet            scInitBaseBlkGet
#define scInitExtendedBaseBlkPut            scInitBaseBlkPut
#define scInitExtendedBaseBrowse            scInitBaseBrowse
#define scInitExtendedBaseCancel            scInitBaseCancel
#define scInitExtendedBaseClose             scInitBaseClose
#define scInitExtendedBaseCmpNames          scInitBaseCmpNames
#define scInitExtendedBaseCompose           scInitBaseCompose
#define scInitExtendedBaseCreate            scInitBaseCreate
#define scInitExtendedBaseDelete            scInitBaseDelete
#define scInitExtendedBaseDirty             scInitBaseDirty
#define scInitExtendedBaseDrop              scInitBaseDrop
#define scInitExtendedBaseExists            scInitBaseExists
#define scInitExtendedBaseFetch             scInitBaseFetch
#define scInitExtendedBaseFetchLock         scInitBaseFetchLock
#define scInitExtendedBaseField             scInitBaseField
#define scInitExtendedBaseFieldExists       scInitBaseFieldExists
#define scInitExtendedBaseFieldName         scInitBaseFieldName
#define scInitExtendedBaseFields            scInitBaseFields
#define scInitExtendedBaseFilterCount       scInitBaseFilterCount
#define scInitExtendedBaseFilterDelete      scInitBaseFilterDelete
#define scInitExtendedBaseFilterFetch       scInitBaseFilterFetch
#define scInitExtendedBaseFilterSelect      scInitBaseFilterSelect
#define scInitExtendedBaseGet               scInitBaseGet
#define scInitExtendedBaseInit              scInitBaseInit
#define scInitExtendedBaseInsert            scInitBaseInsert
#define scInitExtendedBaseInstanceFieldList scInitBaseInstanceFieldList
#define scInitExtendedBaseInstanceNotify    scInitBaseInstanceNotify
#define scInitExtendedBaseInstanceOpen      scInitBaseInstanceOpen
#define scInitExtendedBaseInstanceProtocol  scInitBaseInstanceProtocol
#define scInitExtendedBaseInstanceSecurity  scInitBaseInstanceSecurity
#define scInitExtendedBaseKey               scInitBaseKey
#define scInitExtendedBaseKeys              scInitBaseKeys
#define scInitExtendedBaseName              scInitBaseName
#define scInitExtendedBaseOpen              scInitBaseOpen
#define scInitExtendedBaseOrder             scInitBaseOrder
#define scInitExtendedBasePost              scInitBasePost
#define scInitExtendedBasePresents          scInitBasePresents
#define scInitExtendedBaseProcess           scInitBaseProcess
#define scInitExtendedBasePut               scInitBasePut
#define scInitExtendedBaseRead              scInitBaseRead
#define scInitExtendedBaseReadLock          scInitBaseReadLock
#define scInitExtendedBaseRecordClear       scInitBaseRecordClear
#define scInitExtendedBaseRecordGenerate    scInitBaseRecordGenerate
#define scInitExtendedBaseRevisionCancel    scInitBaseRevisionCancel
#define scInitExtendedBaseRevisionExists    scInitBaseRevisionExists
#define scInitExtendedBaseRevisionPost      scInitBaseRevisionPost
#define scInitExtendedBaseRevisionRekey     scInitBaseRevisionRekey
#define scInitExtendedBaseRevisionUnposted  scInitBaseRevisionUnposted
#define scInitExtendedBaseSecurity          scInitBaseSecurity
#define scInitExtendedBaseTableEmpty        scInitBaseTableEmpty
#define scInitExtendedBaseType              scInitBaseType
#define scInitExtendedBaseUnLock            scInitBaseUnLock
#define scInitExtendedBaseUpdate            scInitBaseUpdate
#define scInitExtendedBaseVerify            scInitBaseVerify

#else

VIEWCALL scInitBaseAttribs (LPVOID lpView, LONG lField, LPLONG lpAttributes)
{
   ERRNUM e = scInitExtendedBaseAttribs (lpView, lField, lpAttributes);

   return ErrorMapExtendedToOld (VIEW_OP_ATTRIBUTES, e);
}



VIEWCALL scInitBaseBlkGet (LPVOID lpView, INT lFields, LPLONG lFieldList, LPSHORT lpnSizeList, LPSTR lpsBuffer)
{
   ERRNUM e = scInitExtendedBaseBlkGet (lpView, lFields, lFieldList, lpnSizeList, lpsBuffer);

   return ErrorMapExtendedToOld (VIEW_OP_BLKGET, e);
}



VIEWCALL scInitBaseBlkPut (LPVOID lpView, INT lFields, LPLONG lFieldList, LPSHORT lpnSizeList, LPSTR lpsBuffer, BOOL bVerify)
{
   ERRNUM e = scInitExtendedBaseBlkPut (lpView, lFields, lFieldList, lpnSizeList, lpsBuffer, bVerify);

   return ErrorMapExtendedToOld (VIEW_OP_BLKPUT, e);
}



VIEWCALL scInitBaseBrowse (LPVOID lpView, LPSTR lpsExpression, BOOL bAscending)
{
   ERRNUM e = scInitExtendedBaseBrowse (lpView, lpsExpression, bAscending);

   return ErrorMapExtendedToOld (VIEW_OP_BROWSE, e);
}



VIEWCALL scInitBaseCancel (LPVOID lpView)
{
   ERRNUM e = scInitExtendedBaseCancel (lpView);

   return ErrorMapExtendedToOld (VIEW_OP_CANCEL, e);
}



VIEWCALL scInitBaseClose (LPVOID lpView)
{
   ERRNUM e = scInitExtendedBaseClose (lpView);

   return ErrorMapExtendedToOld (VIEW_OP_CLOSE, e);
}



VIEWCALL scInitBaseCmpNames (INT roto, LPSTR lpsCompositeNames, LPSHORT lpnCount)
{
   ERRNUM e = scInitExtendedBaseCmpNames (roto, lpsCompositeNames, lpnCount);

   return ErrorMapExtendedToOld (VIEW_OP_COMPOSE, e);
}



VIEWCALL scInitBaseCompose (LPVOID lpView, LPVIEWDEF lpvdefComposites)
{
   ERRNUM e = scInitExtendedBaseCompose (lpView, lpvdefComposites);

   return ErrorMapExtendedToOld (VIEW_OP_COMPOSITES, e);
}



VIEWCALL scInitBaseCreate (HPIB hPIB, WORD wLinkNo)
{
   ERRNUM e = scInitExtendedBaseCreate (hPIB, wLinkNo);

   return ErrorMapExtendedToOld (VIEW_OP_CREATE, e);
}



VIEWCALL scInitBaseDelete (LPVOID lpView)
{
   ERRNUM e = scInitExtendedBaseDelete (lpView);

   return ErrorMapExtendedToOld (VIEW_OP_DELETE, e);
}



VIEWCALL scInitBaseDirty (LPVOID lpView, LPBOOL bChanged)
{
   ERRNUM e = scInitExtendedBaseDirty (lpView, bChanged);

   return ErrorMapExtendedToOld (VIEW_OP_DIRTY, e);
}



VIEWCALL scInitBaseDrop (HPIB hPIB, WORD wLinkNo)
{
   ERRNUM e = scInitExtendedBaseDrop (hPIB, wLinkNo);

   return ErrorMapExtendedToOld (VIEW_OP_DROP, e);
}



VIEWCALL scInitBaseExists (LPVOID lpView, LPBOOL bExists)
{
   ERRNUM e = scInitExtendedBaseExists (lpView, bExists);

   return ErrorMapExtendedToOld (VIEW_OP_EXISTS, e);
}



VIEWCALL scInitBaseFetch (LPVOID lpView)
{
   ERRNUM e = scInitExtendedBaseFetch (lpView);

   return ErrorMapExtendedToOld (VIEW_OP_FETCH, e);
}



VIEWCALL scInitBaseFetchLock (LPVOID lpView)
{
   ERRNUM e = scInitExtendedBaseFetchLock (lpView);

   return ErrorMapExtendedToOld (VIEW_OP_FETCH_LOCK, e);
}



VIEWCALL scInitBaseField (LPVOID lpView, INT nFldNumber, LPSTR lpsFldName, LPLONG lField)
{
   ERRNUM e = scInitExtendedBaseField (lpView, nFldNumber, lpsFldName, lField);

   return ErrorMapExtendedToOld (VIEW_OP_FIELD, e);
}



VIEWCALL scInitBaseFieldExists (LPV view, LONG lField, LP_A4W_FLAGS flags)
{
   ERRNUM e = scInitExtendedBaseFieldExists (view, lField, flags);

   return ErrorMapExtendedToOld (VIEW_OP_FIELD_EXISTS, e);
}



VIEWCALL scInitBaseFieldName (LPV view, LONG lField, LPSTR lpsName, LPSTR lpsDesc, A4W_SIZE size)
{
   ERRNUM e = scInitExtendedBaseFieldName (view, lField, lpsName, lpsDesc, size);

   return ErrorMapExtendedToOld (VIEW_OP_FIELD_NAME, e);
}



VIEWCALL scInitBaseFields (LPVOID lpView, LPSHORT lFields)
{
   ERRNUM e = scInitExtendedBaseFields (lpView, lFields);

   return ErrorMapExtendedToOld (VIEW_OP_FIELDS, e);
}



VIEWCALL scInitBaseFilterCount (LPV view, LPSTR filter, A4W_FLAGS flags, LP_A4W_SIZE count)
{
   ERRNUM e = scInitExtendedBaseFilterCount (view, filter, flags, count);

   return ErrorMapExtendedToOld (VIEW_OP_FILTER_COUNT, e);
}



VIEWCALL scInitBaseFilterDelete (LPV view, LPSTR filter, A4W_FLAGS flags)
{
   ERRNUM e = scInitExtendedBaseFilterDelete (view, filter, flags);

   return ErrorMapExtendedToOld (VIEW_OP_FILTER_DELETE, e);
}



VIEWCALL scInitBaseFilterFetch (LPV view, A4W_FLAGS flags)
{
   ERRNUM e = scInitExtendedBaseFilterFetch (view, flags);

   return ErrorMapExtendedToOld (VIEW_OP_FILTER_FETCH, e);
}



VIEWCALL scInitBaseFilterSelect (LPV view, INT key, LPSTR filter, A4W_FLAGS flags)
{
   ERRNUM e = scInitExtendedBaseFilterSelect (view, key, filter, flags);

   return ErrorMapExtendedToOld (VIEW_OP_FILTER_SELECT, e);
}



VIEWCALL scInitBaseGet (LPVOID lpView, LONG lField, LPSTR buffer, INT nSize)
{
   ERRNUM e = scInitExtendedBaseGet (lpView, lField, buffer, nSize);

   return ErrorMapExtendedToOld (VIEW_OP_GET, e);
}



VIEWCALL scInitBaseInit (LPVOID lpView)
{
   ERRNUM e = scInitExtendedBaseInit (lpView);

   return ErrorMapExtendedToOld (VIEW_OP_INITIALIZE, e);
}



VIEWCALL scInitBaseInsert (LPVOID lpView)
{
   ERRNUM e = scInitExtendedBaseInsert (lpView);

   return ErrorMapExtendedToOld (VIEW_OP_INSERT, e);
}



VIEWCALL scInitBaseInstanceFieldList (LPV view, A4W_FLAGS flags, A4W_SIZE count, PLONG fields)
{
   ERRNUM e = scInitExtendedBaseInstanceFieldList (view, flags, count, fields);

   return ErrorMapExtendedToOld (VIEW_OP_INSTANCE_FIELDLIST, e);
}



VIEWCALL scInitBaseInstanceNotify (LPV view, A4W_NOTIFY_PROC notify, LPVOID context, A4W_FLAGS flags)
{
   ERRNUM e = scInitExtendedBaseInstanceNotify (view, notify, context, flags);

   return ErrorMapExtendedToOld (VIEW_OP_INSTANCE_NOTIFY, e);
}



VIEWCALL scInitBaseInstanceOpen (LPRVH rvh, HPIB PIB, WORD link, A4W_FLAGS flags, LPVOID extra, A4W_SIZE size, LPV FAR * view)
{
   ERRNUM e = scInitExtendedBaseInstanceOpen (rvh, PIB, link, flags, extra, size, view);

   return ErrorMapExtendedToOld (VIEW_OP_INSTANCE_OPEN, e);
}



VIEWCALL scInitBaseInstanceProtocol (LPV view, A4W_FLAGS flags, LP_A4W_FLAGS protocols, LP_A4W_SIZE count)
{
   ERRNUM e = scInitExtendedBaseInstanceProtocol (view, flags, protocols, count);

   return ErrorMapExtendedToOld (VIEW_OP_INSTANCE_PROTOCOL, e);
}



VIEWCALL scInitBaseInstanceSecurity (LPV view, LP_A4W_FLAGS flags)
{
   ERRNUM e = scInitExtendedBaseInstanceSecurity (view, flags);

   return ErrorMapExtendedToOld (VIEW_OP_INSTANCE_SECURITY, e);
}



VIEWCALL scInitBaseKey (LPVOID lpView, INT nKeyNo, LPSTR sName, LPSHORT lFields, LPLONG lplKeyFields)
{
   ERRNUM e = scInitExtendedBaseKey (lpView, nKeyNo, sName, lFields, lplKeyFields);

   return ErrorMapExtendedToOld (VIEW_OP_KEY, e);
}



VIEWCALL scInitBaseKeys (LPVOID lpView, LPSHORT lpnKeys)
{
   ERRNUM e = scInitExtendedBaseKeys (lpView, lpnKeys);

   return ErrorMapExtendedToOld (VIEW_OP_KEYS, e);
}



VIEWCALL scInitBaseName (LPVOID lpView, LONG lField, LPSTR lpsName, LPSTR lpsDesc)
{
   ERRNUM e = scInitExtendedBaseName (lpView, lField, lpsName, lpsDesc);

   return ErrorMapExtendedToOld (VIEW_OP_NAME, e);
}



VIEWCALL scInitBaseOpen (HPIB hPIB, WORD wLinkNo, LPVOID FAR * lpView)
{
   ERRNUM e = scInitExtendedBaseOpen (hPIB, wLinkNo, lpView);

   return ErrorMapExtendedToOld (VIEW_OP_OPEN, e);
}



VIEWCALL scInitBaseOrder (LPVOID lpView, INT nKey)
{
   ERRNUM e = scInitExtendedBaseOrder (lpView, nKey);

   return ErrorMapExtendedToOld (VIEW_OP_ORDER, e);
}



VIEWCALL scInitBasePost (LPVOID lpView)
{
   ERRNUM e = scInitExtendedBasePost (lpView);

   return ErrorMapExtendedToOld (VIEW_OP_POST, e);
}



VIEWCALL scInitBasePresents (LPVOID lpView, LONG lField, LPSTR lpsMask, LPSHORT lpnList, LPSHORT lpnCount, LPVOID lpBuffer, INT nSize)
{
   ERRNUM e = scInitExtendedBasePresents (lpView, lField, lpsMask, lpnList, lpnCount, lpBuffer, nSize);

   return ErrorMapExtendedToOld (VIEW_OP_PRESENTATION, e);
}



VIEWCALL scInitBaseProcess (LPVOID lpView)
{
   ERRNUM e = scInitExtendedBaseProcess (lpView);

   return ErrorMapExtendedToOld (VIEW_OP_PROCESS, e);
}



VIEWCALL scInitBasePut (LPVOID lpView, LONG lField, LPSTR lpsBuffer, INT nSize, BOOL bVerify)
{
   ERRNUM e = scInitExtendedBasePut (lpView, lField, lpsBuffer, nSize, bVerify);

   return ErrorMapExtendedToOld (VIEW_OP_PUT, e);
}



VIEWCALL scInitBaseRead (LPVOID lpView)
{
   ERRNUM e = scInitExtendedBaseRead (lpView);

   return ErrorMapExtendedToOld (VIEW_OP_READ, e);
}



VIEWCALL scInitBaseReadLock (LPVOID lpView)
{
   ERRNUM e = scInitExtendedBaseReadLock (lpView);

   return ErrorMapExtendedToOld (VIEW_OP_READ_LOCK, e);
}



VIEWCALL scInitBaseRecordClear (LPV view)
{
   ERRNUM e = scInitExtendedBaseRecordClear (view);

   return ErrorMapExtendedToOld (VIEW_OP_RECORD_CLEAR, e);
}



VIEWCALL scInitBaseRecordGenerate (LPV view, A4W_FLAGS flags)
{
   ERRNUM e = scInitExtendedBaseRecordGenerate (view, flags);

   return ErrorMapExtendedToOld (VIEW_OP_RECORD_GENERATE, e);
}



VIEWCALL scInitBaseRevisionCancel (LPV view, INT level)
{
   ERRNUM e = scInitExtendedBaseRevisionCancel (view, level);

   return ErrorMapExtendedToOld (VIEW_OP_REVISION_CANCEL, e);
}



VIEWCALL scInitBaseRevisionExists (LPV view, INT level, LP_A4W_FLAGS flags)
{
   ERRNUM e = scInitExtendedBaseRevisionExists (view, level, flags);

   return ErrorMapExtendedToOld (VIEW_OP_REVISION_EXISTS, e);
}



VIEWCALL scInitBaseRevisionPost (LPV view, INT level)
{
   ERRNUM e = scInitExtendedBaseRevisionPost (view, level);

   return ErrorMapExtendedToOld (VIEW_OP_REVISION_POST, e);
}



VIEWCALL scInitBaseRevisionRekey (LPV view, LPVOID OldKey, LPVOID NewKey, INT size, A4W_FLAGS flags)
{
   ERRNUM e = scInitExtendedBaseRevisionRekey (view, OldKey, NewKey, size, flags);

   return ErrorMapExtendedToOld (VIEW_OP_REVISION_REKEY, e);
}



VIEWCALL scInitBaseRevisionUnposted (LPV view, INT level, LP_A4W_FLAGS flags)
{
   ERRNUM e = scInitExtendedBaseRevisionUnposted (view, level, flags);

   return ErrorMapExtendedToOld (VIEW_OP_REVISION_UNPOSTED, e);
}



VIEWCALL scInitBaseSecurity (HPIB hPIB, WORD wLinkNo, LPLONG lplPermissions)
{
   ERRNUM e = scInitExtendedBaseSecurity (hPIB, wLinkNo, lplPermissions);

   return ErrorMapExtendedToOld (VIEW_OP_SECURITY, e);
}



VIEWCALL scInitBaseTableEmpty (LPV view)
{
   ERRNUM e = scInitExtendedBaseTableEmpty (view);

   return ErrorMapExtendedToOld (VIEW_OP_TABLE_EMPTY, e);
}



VIEWCALL scInitBaseType (LPVOID lpView, LONG lField, LPTYPE lptype)
{
   ERRNUM e = scInitExtendedBaseType (lpView, lField, lptype);

   return ErrorMapExtendedToOld (VIEW_OP_TYPE, e);
}



VIEWCALL scInitBaseUnLock (LPVOID lpView)
{
   ERRNUM e = scInitExtendedBaseUnLock (lpView);

   return ErrorMapExtendedToOld (VIEW_OP_UNLOCK, e);
}



VIEWCALL scInitBaseUpdate (LPVOID lpView)
{
   ERRNUM e = scInitExtendedBaseUpdate (lpView);

   return ErrorMapExtendedToOld (VIEW_OP_UPDATE, e);
}



VIEWCALL scInitBaseVerify (LPVOID lpView)
{
   ERRNUM e = scInitExtendedBaseVerify (lpView);

   return ErrorMapExtendedToOld (VIEW_OP_VERIFY, e);
}

#endif



/////////////////////////////////////////////////////////////////////////////
// Officially published entrypoints (per ROTO & ROTOVIEW requirements)



VIEWCALL rotoEntryBase (LPROTOVIEW v, INT length)
{
   ERRNUM e = ERRNUM_SUCCESS;
   ENTRYSTATE state;
   LPV lpv = NULL;
   LPVOID notifications = NULL;
   INT EntryPath = ENTRY_PATH_INACTIVE;

   // Save reentrancy state of caller's LPV
   switch ( v->op ) {
      case VIEW_OP_COMPOSITES :
      case VIEW_OP_CREATE :
      case VIEW_OP_DROP :
      case VIEW_OP_OPEN :
      case VIEW_OP_INSTANCE_OPEN :
      case VIEW_OP_SECURITY :
         // There is no state to save for these
         break;

      default:
         lpv = (LPV) v->view;
         EntryStatePush (lpv, v, length, &state);
         EntryPath = state.EntryPath;
         break;
   }

   if ( NULL!=lpv && ENTRY_PATH_INACTIVE==EntryPath )
      notifications = lpv->NotifyList;
   // Save information for field value & attribute notifications later
   if ( notifications!=NULL ) {
      switch ( v->op ) {
         // These potentially change field values
         case VIEW_OP_BLKPUT :
         case VIEW_OP_INSERT :
         case VIEW_OP_PROCESS :
         case VIEW_OP_PUT :
         case VIEW_OP_UPDATE :
            CopyRecords (lpv, FindRecordNotify (lpv), FindRecord (lpv));
            blkCopy (lpv->attributesNotify, lpv->alAttributes, sizeof (lpv->attributesNotify));
            blkSet (lpv->QueuedNotifyField, 0, sizeof (lpv->QueuedNotifyField));
            lpv->FieldsWereQueued = FALSE;
            break;

         // These potentially change field attributes and presentation
         case VIEW_OP_CANCEL :
         case VIEW_OP_FETCH :
         case VIEW_OP_FETCH_LOCK :
         case VIEW_OP_FILTER_FETCH :
         case VIEW_OP_FILTER_SELECT :
         case VIEW_OP_INITIALIZE :
         case VIEW_OP_INSTANCE_FIELDLIST :
         case VIEW_OP_ORDER :
         case VIEW_OP_READ :
         case VIEW_OP_READ_LOCK :
         case VIEW_OP_RECORD_CLEAR :
         case VIEW_OP_RECORD_GENERATE :
         case VIEW_OP_REVISION_CANCEL :
            if ( DO_NOTIFYQUEUEFIELDVALUE )
               CopyRecords (lpv, FindRecordNotify (lpv), FindRecord (lpv));
            blkCopy (lpv->attributesNotify, lpv->alAttributes, sizeof (lpv->attributesNotify));
            blkSet (lpv->QueuedNotifyField, 0, sizeof (lpv->QueuedNotifyField));
            lpv->FieldsWereQueued = FALSE;
            break;

         default:
            break;

         // NOTIFICATIONS NOT POSSIBLE
         // case VIEW_OP_COMPOSITES
         // case VIEW_OP_CREATE
         // case VIEW_OP_DROP
         // case VIEW_OP_INSTANCE_OPEN
         // case VIEW_OP_OPEN
         // case VIEW_OP_SECURITY

         // RECORD OPERATIONS LEAVING STATE UNDEFINED, IOW NO RELEVANT NOTIFICATIONS
         // case VIEW_OP_CLOSE
         // case VIEW_OP_DELETE
         // case VIEW_OP_FILTER_COUNT
         // case VIEW_OP_FILTER_DELETE
         // case VIEW_OP_POST
         // case VIEW_OP_REVISION_POST
         // case VIEW_OP_REVISION_REKEY
         // case VIEW_OP_TABLE_EMPTY
         // case VIEW_OP_UNLOCK

         // SET STATE W/O FIELD SIDE-EFFECTS
         // case VIEW_OP_BROWSE
         // case VIEW_OP_COMPOSE
         // case VIEW_OP_INSTANCE_NOTIFY

         // QUERY STATE
         // case VIEW_OP_ATTRIBUTES
         // case VIEW_OP_BLKGET
         // case VIEW_OP_DIRTY
         // case VIEW_OP_EXISTS
         // case VIEW_OP_GET
         // case VIEW_OP_INSTANCE_PROTOCOL
         // case VIEW_OP_INSTANCE_SECURITY
         // case VIEW_OP_REVISION_EXISTS
         // case VIEW_OP_REVISION_UNPOSTED
         // case VIEW_OP_VERIFY

         // QUERY METADATA
         // case VIEW_OP_FIELD
         // case VIEW_OP_FIELDS
         // case VIEW_OP_FIELD_EXISTS
         // case VIEW_OP_FIELD_NAME
         // case VIEW_OP_KEY
         // case VIEW_OP_KEYS
         // case VIEW_OP_NAME
         // case VIEW_OP_PRESENTATION
         // case VIEW_OP_TYPE

      }
   }

   // Unmarshal the parameters and call the service routine
   switch ( v->op ) {
      case VIEW_OP_ATTRIBUTES :
         e = scInitAttribs (v->view, MapToNewFieldIndex (v->field), (LPLONG) v->p);
         break;
      case VIEW_OP_BLKGET :
         e = scInitBlkGet (v->view, v->i, (LPLONG) v->p, (LPSHORT) v->q, (LPSTR) v->r);
         break;
      case VIEW_OP_BLKPUT :
         e = scInitBlkPut (v->view, v->i, (LPLONG) v->p, (LPSHORT) v->q, (LPSTR) v->r, v->flag);
         break;
      case VIEW_OP_BROWSE :
         e = scInitBrowse (v->view, (LPSTR) v->p, v->flag);
         break;
      case VIEW_OP_CANCEL :
         e = scInitCancel (v->view);
         break;
      case VIEW_OP_CLOSE :
         e = scInitClose (v->view);
         break;
      case VIEW_OP_COMPOSE :
         e = scInitCompose (v->view, (LPVIEWDEF) v->p);
         break;
      case VIEW_OP_COMPOSITES :
         e = scInitCmpNames (v->i, (LPSTR) v->p, (LPSHORT) v->q);
         break;
      case VIEW_OP_CREATE :
         e = scInitCreate (v->i, v->x);
         break;
      case VIEW_OP_DELETE :
         e = scInitDelete (v->view);
         break;
      case VIEW_OP_DIRTY :
         e = scInitDirty (v->view, (LPBOOL) v->p);
         break;
      case VIEW_OP_DROP :
         e = scInitDrop (v->i, v->x);
         break;
      case VIEW_OP_EXISTS :
         e = scInitExists (v->view, (LPBOOL) v->p);
         break;
      case VIEW_OP_FETCH :
         e = scInitFetch (v->view);
         break;
      case VIEW_OP_FETCH_LOCK :
         e = scInitFetchLock (v->view);
         break;
      case VIEW_OP_FIELD :
         e = scInitField (v->view, v->i, (LPSTR) v->p, (LPLONG) v->q);
         break;
      case VIEW_OP_FIELD_EXISTS :
         e = scInitFieldExists ((LPV) v->view, v->field, (LP_A4W_FLAGS) v->p);
         break;
      case VIEW_OP_FIELD_NAME :
         e = scInitFieldName ((LPV) v->view, v->field, (LPSTR) v->p, (LPSTR) v->q, v->i);
         break;
      case VIEW_OP_FIELDS :
         e = scInitFields (v->view, (LPSHORT) v->p);
         break;
      case VIEW_OP_FILTER_COUNT :
         e = scInitFilterCount ((LPV) v->view, (LPSTR) v->p, v->dw, (LP_A4W_SIZE) v->q);
         break;
      case VIEW_OP_FILTER_DELETE :
         e = scInitFilterDelete ((LPV) v->view, (LPSTR) v->p, v->dw);
         break;
      case VIEW_OP_FILTER_FETCH :
         e = scInitFilterFetch ((LPV) v->view, v->dw);
         break;
      case VIEW_OP_FILTER_SELECT :
         e = scInitFilterSelect ((LPV) v->view, v->i, (LPSTR) v->p, v->dw);
         break;
      case VIEW_OP_GET :
         e = scInitGet (v->view, MapToNewFieldIndex (v->field), (LPSTR) v->p, v->i);
         break;
      case VIEW_OP_INITIALIZE :
         e = scInitInit (v->view);
         break;
      case VIEW_OP_INSERT :
         e = scInitInsert (v->view);
         break;
      case VIEW_OP_INSTANCE_FIELDLIST :
         e = scInitInstanceFieldList ((LPV) v->view, v->dw, v->i, (PLONG) v->p);
         break;
      case VIEW_OP_INSTANCE_NOTIFY :
         e = scInitInstanceNotify ((LPV) v->view, (A4W_NOTIFY_PROC) v->p, v->q, v->dw);
         break;
      case VIEW_OP_INSTANCE_OPEN :
#if defined(DO_OPENETC) || !defined(DO_scInitOpen) || defined(DO_scInitInstanceOpen)
         e = scInitInstanceOpen ((LPRVH) v->p, v->i, v->x, v->dw,
                               v+1, length-sizeof (ROTOVIEW), (LPV *) &v->view);
#else
         e = scInitOpen (v->i, v->x, &v->view);
 #if defined LINUX_VER
  #warning ("WARNING: scInitInstanceOpen() is redirected to scInitOpen() because scInitOpen() is")
  #warning ("overridden, scInitInstanceOpen() isn't, and OpenEtc() isn't used. To avoid this")
  #warning ("loss of functionality move the override code into OpenEtc()")
 #else
  #pragma message ("WARNING: scInitInstanceOpen() is redirected to scInitOpen() because scInitOpen() is")
  #pragma message ("overridden, scInitInstanceOpen() isn't, and OpenEtc() isn't used. To avoid this")
  #pragma message ("loss of functionality move the override code into OpenEtc()")
 #endif
#endif
         break;
      case VIEW_OP_INSTANCE_PROTOCOL :
         e = scInitInstanceProtocol ((LPV) v->view, v->dw, (LP_A4W_FLAGS) v->p, (LP_A4W_SIZE) v->q);
         break;
      case VIEW_OP_INSTANCE_SECURITY :
         e = scInitInstanceSecurity ((LPV) v->view, (LP_A4W_FLAGS) v->p);
         break;
      case VIEW_OP_KEY :
         e = scInitKey (v->view, v->i, (LPSTR) v->p, (LPSHORT) v->q, (LPLONG) v->r);
         break;
      case VIEW_OP_KEYS :
         e = scInitKeys (v->view, (LPSHORT) v->p);
         break;
      case VIEW_OP_NAME :
         e = scInitName (v->view, MapToNewFieldIndex (v->field), (LPSTR) v->p, (LPSTR) v->q);
         break;
      case VIEW_OP_OPEN :
#if defined(DO_OPENETC) || defined(DO_scInitOpen) || !defined(DO_scInitInstanceOpen)
         e = scInitOpen (v->i, v->x, &v->view);
#else
         e = scInitInstanceOpen (NULL, v->i, v->x, 0L, NULL, 0, (LPV *) &v->view);
 #if defined LINUX_VER
  #warning ("WARNING: scInitOpen() is redirected to scInitInstanceOpen() because")
  #warning ("scInitInstanceOpen() is overridden, scInitOpen() isn't, and OpenEtc() isn't used.")
  #warning ("To avoid this loss of functionality move the override code into OpenEtc()")
 #else
  #pragma message ("WARNING: scInitOpen() is redirected to scInitInstanceOpen() because")
  #pragma message ("scInitInstanceOpen() is overridden, scInitOpen() isn't, and OpenEtc() isn't used.")
  #pragma message ("To avoid this loss of functionality move the override code into OpenEtc()")
 #endif
#endif
         break;
      case VIEW_OP_ORDER :
         e = scInitOrder (v->view, v->i);
         break;
      case VIEW_OP_POST :
         e = scInitPost (v->view);
         break;
      case VIEW_OP_PRESENTATION :
         e = scInitPresents (v->view, MapToNewFieldIndex (v->field),
                           (LPSTR) v->p, (LPSHORT) v->q, (LPSHORT) v->r, v->s, v->i);
         break;
      case VIEW_OP_PROCESS :
         e = scInitProcess (v->view);
         break;
      case VIEW_OP_PUT :
         e = scInitPut (v->view, MapToNewFieldIndex (v->field), (LPSTR) v->p, v->i, v->flag);
         break;
      case VIEW_OP_READ :
         e = scInitRead (v->view);
         break;
      case VIEW_OP_READ_LOCK :
         e = scInitReadLock (v->view);
         break;
      case VIEW_OP_RECORD_CLEAR :
         e = scInitRecordClear ((LPV) v->view);
         break;
      case VIEW_OP_RECORD_GENERATE :
         e = scInitRecordGenerate ((LPV) v->view, v->dw);
         break;
      case VIEW_OP_REVISION_CANCEL :
         e = scInitRevisionCancel ((LPV) v->view, v->i);
         break;
      case VIEW_OP_REVISION_EXISTS :
         e = scInitRevisionExists ((LPV) v->view, v->i, (LP_A4W_FLAGS) v->p);
         break;
      case VIEW_OP_REVISION_POST :
         e = scInitRevisionPost ((LPV) v->view, v->i);
         break;
      case VIEW_OP_REVISION_REKEY :
         e = scInitRevisionRekey ((LPV) v->view, v->p, v->q, v->i, v->dw);
         break;
      case VIEW_OP_REVISION_UNPOSTED :
         e = scInitRevisionUnposted ((LPV) v->view, v->i, (LP_A4W_FLAGS) v->p);
         break;
      case VIEW_OP_SECURITY :
         e = scInitSecurity (v->i, v->x, (LPLONG) v->p);
         break;
      case VIEW_OP_TABLE_EMPTY :
         e = scInitTableEmpty ((LPV) v->view);
         break;
//////////////////////////////////////////////////////////////////////////////
// Experimental stuff
      case VIEW_OP_TABLE_HANDLES :
         e = scInitTableHandles ((LPV) v->view, v->i, (LPWORD) v->p);
         break;
//////////////////////////////////////////////////////////////////////////////
      case VIEW_OP_TYPE :
         e = scInitType (v->view, MapToNewFieldIndex (v->field), (LPTYPE) v->p);
         break;
      case VIEW_OP_UNLOCK :
         e = scInitUnLock (v->view);
         break;
      case VIEW_OP_UPDATE :
         e = scInitUpdate (v->view);
         break;
      case VIEW_OP_VERIFY :
         e = scInitVerify (v->view);
         break;
      default :
#if defined(DO_ROTOENTRYETC)
         e = ErrorMapViewToExtended (v->op, rotoEntryEtc (v, length));
#else
         e = BaseRotoEntry (v, length);
#endif
         break;
   }

   // Fire field value & attribute notifications
   if ( notifications!=NULL ) {
      switch ( v->op ) {
         case VIEW_OP_BLKPUT :
         case VIEW_OP_INSERT :
         case VIEW_OP_PROCESS :
         case VIEW_OP_PUT :
         case VIEW_OP_UPDATE :
            MaxError (&e, NotifyFieldValues (lpv));
            MaxError (&e, NotifyFieldAttributes (lpv));
            MaxError (&e, NotifyQueuedFields (lpv));
            break;

         case VIEW_OP_CANCEL :
         case VIEW_OP_FETCH :
         case VIEW_OP_FETCH_LOCK :
         case VIEW_OP_FILTER_FETCH :
         case VIEW_OP_FILTER_SELECT :
         case VIEW_OP_INITIALIZE :
         case VIEW_OP_INSTANCE_FIELDLIST :
         case VIEW_OP_ORDER :
         case VIEW_OP_READ :
         case VIEW_OP_READ_LOCK :
         case VIEW_OP_RECORD_CLEAR :
         case VIEW_OP_RECORD_GENERATE :
         case VIEW_OP_REVISION_CANCEL :
            MaxError (&e, NotifyQueueFieldValues (lpv));
            MaxError (&e, NotifyFieldAttributes (lpv));
            MaxError (&e, NotifyQueuedFields (lpv));
            break;

         default:
            break;
      }
   }

   if ( DO_EXTENDEDERRORS<RETURN_EXTENDEDERRORS )
      e = ErrorMapExtendedToOld (v->op, e);

   // restore caller's LPV reentrancy state
   switch ( v->op ) {
      case VIEW_OP_CLOSE :
      case VIEW_OP_COMPOSITES :
      case VIEW_OP_CREATE :
      case VIEW_OP_DROP :
      case VIEW_OP_INSTANCE_OPEN :
      case VIEW_OP_OPEN :
      case VIEW_OP_SECURITY :
         // There is no state to restore for these
         break;

      default:
         EntryStatePop (lpv, &state);
         break;
   }

   return e;
}



VIEWCALL identifyEntry (LPIDENTIFYVIEW identify, INT length)
{
   switch ( identify->op ) {
      case IDENTIFY_OP_VERSION_TEMPLATE:
         return scInitVersionTemplate (identify->pib, identify->TextDatum, (LPBCDDATE) identify->BinaryDatum);
      case IDENTIFY_OP_VERSION_API:
         return scInitVersionAPI (identify->pib, identify->TextDatum);
      case IDENTIFY_OP_VIEW_NAME:
         return scInitViewName (identify->pib, identify->TextDatum, identify->TextLength);
      case IDENTIFY_OP_VIEW_TABLE_COUNT:
         return scInitViewTableCount (identify->pib, (LPSHORT) identify->BinaryDatum);
      case IDENTIFY_OP_VIEW_TABLES:
         return scInitViewTables (identify->pib, identify->TextDatum, identify->TextLength);
      default:
         return ERRNUM_ROTOENTRY_FAILED;
   }
}



//////////////////////////////////////////////////////////////////////////////
// Entrypoint implementations



/*--------------------------------------------------------------------
   Returns a bitset of status indicators and attributes of the
   current state of a field including whether the field has changed,
   is enabled, is editable, is a key, is a calculated field, whether
   the type can change, whether the presentation can change, whether
   the field is required for insertion, or whether the editable status
   can change.
*/
VIEWCALL scInitExtendedBaseAttribs (
   LPVOID lpView,
   LONG nField,
   LPLONG lplAttributes)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   if ( ValidIndexV (lpv, nField) ) {
      *lplAttributes = AttribGet (lpv, nField);
      CHECK_CALL (e, lpv->eValidation);
   } else if ( SUBCLASS_LEVEL==NOT_SUBCLASS ) {
      ReportIndexError (lpv, nField);
      e = ERRNUM_FIELD_INDEX;
   } else {
      CHECK_CALL (e, viewAttribs (lpv->subCmp.rvh, lpv->subCmp.view, nField, lplAttributes));
      if ( KEY_COUNT>0 &&
           (INT) lpv->wKey>=lpv->subKeys &&
           (INT) lpv->wKey<lpv->subKeys+KEY_COUNT ) {
         INT i;
         LPKEYMAP k = FindKeyDef (lpv->wKey-lpv->subKeys);

         for ( i=0; i<k->segments; ++i )
            if ( k->indexes[i]==nField ) {
               *lplAttributes |= ATTR_KEY;
               break;
            }
      }
   }

   if ( *lplAttributes & ATTR_KEY )
      *lplAttributes |= ATTR_ENABLED|ATTR_EDITABLE;

   return e;
}



/*--------------------------------------------------------------------
   Takes an array of field IDS and an array of field sizes and returns
   the contents of the fields appended together in the buffer. This
   can be used in place of several scInitGet calls to minimize the
   number of view calls.
*/
VIEWCALL scInitExtendedBaseBlkGet (
   LPVOID lpView,
   INT nFields,
   LPLONG lplFieldList,
   LPSHORT lpnSizeList,
   LPSTR lpsBuffer)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;
   INT nFld = 0;
   INT nPos = 0;
#if SUBCLASS_LEVEL==NOT_SUBCLASS || defined(DO_OLDSUBCLASSFIELDBLK)
 #define BASE_BLK_GET()
#else
   INT nFldSub = 0;
   INT nPosSub = 0;
   LPVIEWDEF base = &lpv->subCmp;

 #define BASE_BLK_GET() \
   if ( nFld>nFldSub ) { \
      CHECK_CALL (e, viewBlkGet (base->rvh, base->view, \
                                 nFld-nFldSub, \
                                 &lplFieldList[nFldSub], \
                                 &lpnSizeList[nFldSub], \
                                 &lpsBuffer[nPosSub])); \
   }
#endif

   while ( nFld < nFields ) {
      LONG field = MapToNewFieldIndex (lplFieldList[nFld]);
      INT size = lpnSizeList[nFld];

#if SUBCLASS_LEVEL==NOT_SUBCLASS || defined(DO_OLDSUBCLASSFIELDBLK)
      CHECK_CALL (e, scInitGet (lpView, field, &lpsBuffer[nPos], size));
#else
      if ( ValidIndexV (lpv, field) ) {
         BASE_BLK_GET();
         nPosSub = nPos + size;
         nFldSub = nFld + 1;
         CHECK_CALL (e, scInitGet (lpView, field, &lpsBuffer[nPos], size));
      }
#endif
      nPos += size;
      ++nFld;
   }

   BASE_BLK_GET();
   return e;

#undef BASE_BLK_GET
}



/*--------------------------------------------------------------------
   Takes an array of field IDS and an array of field sizes and stores
   the values of the fields into the view. This can be used in place
   of several scInitPut calls to minimize the number of view calls.
*/
VIEWCALL scInitExtendedBaseBlkPut (
   LPVOID lpView,
   INT nFields,
   LPLONG lplFieldList,
   LPSHORT lpnSizeList,
   LPSTR lpsBuffer,
   BOOL bVerify)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;
   INT nFld = 0;
   INT nPos = 0;
   INT nFldSub = 0;
   INT nPosSub = 0;
#if SUBCLASS_LEVEL==NOT_SUBCLASS || defined(DO_OLDSUBCLASSFIELDBLK)
 #define BASE_BLK_PUT()
#else
 #define BASE_BLK_PUT()                                  \
   if ( nFld>nFldSub ) {                                 \
      CHECK_CALL (e, viewBlkPut (lpv->subCmp.rvh,        \
                                 lpv->subCmp.view,       \
                                 nFld-nFldSub,           \
                                 &lplFieldList[nFldSub], \
                                 &lpnSizeList[nFldSub],  \
                                 &lpsBuffer[nPosSub],    \
                                 bVerify));              \
   }
#endif

   while ( nFld < nFields ) {
      LONG field = MapToNewFieldIndex (lplFieldList[nFld]);
      INT size = lpnSizeList[nFld];

#if SUBCLASS_LEVEL==NOT_SUBCLASS || defined(DO_OLDSUBCLASSFIELDBLK)
      CHECK_CALL (e, scInitPut (lpView, field, &lpsBuffer[nPos], size, bVerify));
#else
      if ( ValidIndexV (lpv, field) ) {
         BASE_BLK_PUT();
         nPosSub = nPos + size;
         nFldSub = nFld + 1;
         CHECK_CALL (e, scInitPut (lpView, field, &lpsBuffer[nPos], size, bVerify));
      }
#endif
      nPos += size;
      ++nFld;
   }

   BASE_BLK_PUT();

   if ( SUBCLASS_LEVEL==JOIN_SUBCLASS ) {
      LPCMPKEY x = &lpv->subCmpKey;

      for ( nFld=0; nFld<x->segments; ++nFld ) {
         if ( MapToNewFieldIndex (lplFieldList[nFld])==x->indexes[nFld] ) {
            CHECK_CALL (e, BaseGetKey (lpv));
            break;
         }
      }
   }

   return e;

#undef BASE_BLK_PUT
}



#define FILTER_EXPR_FREE(__f__,__c__) \
   if ( (__f__) && (!(__c__) || !(__f__)[0]) ) { \
      filterExprFree ((__f__)); \
      (__f__) = NULL; \
   }

/*--------------------------------------------------------------------
   Starts a query so that the caller can scan through a stream of
   logical records. The routine sets the record filtering criteria
   and direction for subsequent scInitRead and scInitFetch calls. The
   key to start from is specified by the current contents of the
   logical record.
*/
VIEWCALL scInitExtendedBaseBrowse (
   LPVOID lpView,
   LPSTR lpsExpression,
   BOOL bAscending)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;
   FL_ERRNUM f = FL_SUCCESS;
   LONG flags = 0L;
   WORD op;
   FILTER filter;
   INT i, fields;

   if ( SUBCLASS_LEVEL==NOT_SUBCLASS ) {
      if ( bAscending )
         flags |= FILTER_SELECT_ASCENDING;
      if ( VIEW_OP_BROWSE==VIEW_OP (lpv, BROWSE) || !lpv->bSelectFromStart )
         flags |= FILTER_SELECT_FROMHERE;
      CHECK_CALL (e, BaseNotifyFire (
         lpv, INSTANCE_NOTIFY_INSTANCE_FILTER, flags, lpsExpression));
   }

   if ( lpv->bReadOnly ) {
      FILTER_EXPR_FREE (lpv->dbFilter, FALSE);
      FILTER_EXPR_FREE (lpv->rangeFilter, FALSE);
   }

   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
      FILTER_EXPR_FREE (lpv->subFilter, FALSE);
   }

   filterFree (&lpv->filter);
   CHECK_CALL (e, BrowseBody (lpv, lpsExpression, bAscending));
   if ( VIEW_OP_BROWSE==VIEW_OP (lpv, BROWSE) )
      lpv->bSelectFromStart = FALSE;

   if ( lpv->bReadOnly ) {
      LONG physical[FLD_IDX_COUNT+1]; // +1 is superfluous, but needed in case there are no fields

      fields = 0;
      for ( i=0; i<FLD_IDX_COUNT; ++i ) {
         LONG f = * FindFieldIndexV (lpv, i);

         if ( FindFieldMapV (lpv, f)->tblNo==BASE_TBL_COUNT )
            physical [fields++] = f;
      }

      op = FILTER_OP_COPY;
      f = filterCopy (&filter, &lpv->filter);
      CHECK_CALL (e, ErrorMapFilterToExtended (op, filterErrorV (lpv, op, f)));

      filterReduce (&filter, physical, fields, TRUE, FALSE);
      op = FILTER_OP_EXPRESSION;
      f = filterExpression (lpv, &filter, (FILTERNAME) xxxNameOnly, &lpv->dbFilter);
      RVSPYTRACE (lpv->dbFilter);
      filterFree (&filter);
      CHECK_CALL (e, ErrorMapFilterToExtended (op, filterErrorV (lpv, op, f)));

      op = FILTER_OP_EXPR_RANGES;
      f = filterExprRanges (lpv, &lpv->filter, (FILTERNAME) xxxNameOnly, &lpv->rangeFilter);
      RVSPYTRACE (lpv->rangeFilter);
      CHECK_CALL (e, ErrorMapFilterToExtended (op, filterErrorV (lpv, op, f)));
      // Throw away the ranges since we will be using dbSelect/dbFetch
      filterFreeRanges (&lpv->filter);

      // CONDITIONALLY free only those filters that were constructed as ""
      FILTER_EXPR_FREE (lpv->dbFilter, TRUE);
      FILTER_EXPR_FREE (lpv->rangeFilter, TRUE);
   }

   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
      op = FILTER_OP_COPY;
      f = filterCopy (&filter, &lpv->filter);
      CHECK_CALL (e, ErrorMapFilterToExtended (op, filterErrorV (lpv, op, f)));

      filterReduce (&filter, FindFieldIndexV (lpv, 0), FLD_IDX_COUNT, FALSE, FALSE);
      op = FILTER_OP_EXPRESSION;
      f = filterExpression (lpv, &filter, (FILTERNAME) xxxNameOnly, &lpv->subFilter);
      RVSPYTRACE (lpv->subFilter);
      filterFree (&filter);
      CHECK_CALL (e, ErrorMapFilterToExtended (op, filterErrorV (lpv, op, f)));
      CHECK_CALL (e, BaseBrowse (lpv, lpv->bSelectFromStart));
   }

   return e;
}


/*--------------------------------------------------------------------
   Rolls back any pending changes to the database. It is used in
   conjunction with scInitPost.
*/
VIEWCALL scInitExtendedBaseCancel (
   LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   RevisionSpyLevels (lpv);
   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
      CHECK_CALL (e, viewCancel (lpv->subCmp.rvh, lpv->subCmp.view));
   }
   CHECK_CALL (e, CancelBody (lpv, 1));
   RevisionSpyLevels (lpv);
   return e;
}



/*--------------------------------------------------------------------
   Closes an open view.
*/
VIEWCALL scInitExtendedBaseClose (
   LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   INT nTbl;

   // We are tending to ignore errors, because closing usually happens
   // (or ought to) everyone all at once.

   NotifyFire (lpv, INSTANCE_NOTIFY_INSTANCE_CLOSING, 0L, NULL);
   NotifyClose (lpv);
   SelectionCancel (lpv);
   RevisionSpyLevels (lpv);
   RevisionOuterCancel (lpv);
   RevisionCancel (lpv, FindRevCache (lpv));
   if ( lpv->fetchedRecords!=NULL )
      memFree (lpv->fetchedRecords);
#if defined(DO_HEADERETC)
   if ( lpv->detailSave )
      memFree (lpv->detailSave);
#endif
   filterFree (&lpv->filter);
   if ( lpv->bReadOnly ) {
      FILTER_EXPR_FREE (lpv->dbFilter, FALSE);
      FILTER_EXPR_FREE (lpv->rangeFilter, FALSE);
   }
   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
      FILTER_EXPR_FREE (lpv->subFilter, FALSE);
   }
   CloseImpViews (lpv);
   for ( nTbl=0; nTbl<BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT; nTbl++ ) {
      memFree ((FindRecord (lpv)) [nTbl]);
      memFree ((FindRecordTemp (lpv)) [nTbl]);
      memFree ((FindRecordNotify (lpv)) [nTbl]);
#if defined(DO_RECORDREAD) || defined(DO_CONCURRENCYETC)
      memFree ((FindRecordRead (lpv)) [nTbl]);
#endif
   }
   fileClose (lpv);
   if ( lpv->OpenExtra!=NULL )
      memFree (lpv->OpenExtra);
   DEALLOCATE_STRUCT (lpv);
   return ERRNUM_SUCCESS;
}


/*--------------------------------------------------------------------
   Returns a list of view rotoIDs that the caller must explicitly
   compose. If lpsCompositeNames is a null address, scInitCmpNames will
   not return the list of view rotoIDS. Instead, scInitCmpNames will
   return the size of the buffer required to hold the sequence of
   character strings in *lpnCount.
*/
VIEWCALL scInitExtendedBaseCmpNames (
   INT roto,
   LPSTR lpsCompositeNames,
   LPSHORT lpnCount)

{
   ERRNUM e = ERRNUM_SUCCESS;

   if ( SUBCLASS_LEVEL==NOT_SUBCLASS ) {
      INT c;

      if (lpsCompositeNames == NULL)
         *lpnCount = (SIZEOF_ROTOIDSTR + 1) * EXP_CMP_COUNT;
      else {
         *lpnCount = EXP_CMP_COUNT;
         for ( c=0; c<EXP_CMP_COUNT; ++c ) {
            INT i = MapToInternalComposite (c);

            blkCopy (lpsCompositeNames, FindCmpName (i), SIZEOF_ROTOIDSTR + 1);
            lpsCompositeNames += SIZEOF_ROTOIDSTR + 1;
         }
      }
   } else {
      VIEWDEF base;

      if ( (base.rvh = BaseLoad (roto))==NULL ) {
         //// !!!!!!!!!!! ReportBaseLoadError (hPIB, subCmpName);
         return ERRNUM_LOAD_FAILED;
      }
      e = viewCmpNames (base.rvh, lpsCompositeNames, lpnCount);
      BaseUnload (&base);
   }

   return e;
}



/*--------------------------------------------------------------------
   Defines the composite subviews of the view. The caller must know
   the composite views and their order.
*/
VIEWCALL scInitExtendedBaseCompose (
   LPVOID lpView,
   LPVIEWDEF composites)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;
   INT c;

   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
      LPVIEWDEF v;
      SHORT count;
      LPSTR views = NULL;

      v = &lpv->subCmp;
      CHECK_CALL (e, viewCmpNames (v->rvh, NULL, &count));
      views = (LPSTR) _alloca(count);
      if ( views==NULL ) {
         ReportMemoryError (lpv, MAKE_OP_RSC (VIEW_OP (lpv, OPEN)));
         return ERRNUM_COMPOSE_FAILED;
      }
      MaxError (&e, viewCmpNames (v->rvh, views, &count));
      if ( ERRNUM_IS_FAILURE (e) ) {
         return e;
      }
      MaxError (&e, viewCompCnt (v->rvh, v->view, count));
      if ( ERRNUM_IS_FAILURE (e) ) {
         return e;
      }
      MaxError (&e, viewCompose (v->rvh, v->view, composites));
      if ( ERRNUM_IS_FAILURE (e) ) {
         return e;
      }
      if ( count<EXP_CMP_COUNT ) {
         ReportSubclassComposeError (lpv);
         return ERRNUM_COMPOSE_FAILED;
      }
      for ( c=EXP_CMP_COUNT; c--; ) {
         INT i = MapToInternalComposite (c);

         if ( blkCompare (views + c*(SIZEOF_ROTOIDSTR + 1),
                          FindCmpName (i), SIZEOF_ROTOIDSTR + 1)!=0 ) {
            ReportSubclassComposeError (lpv);
            return ERRNUM_COMPOSE_FAILED;
         }
      }
   }

   for ( c=0; c<EXP_CMP_COUNT; ++c ) {
      INT i = MapToInternalComposite (c);

      switch ( CompositeCategory (lpv, i) ) {
         case HEADER_COMPOSITE:
            CHECK_CALL (e, ComposeHeader (lpv, & composites [c]));
            break;
         case DETAIL_COMPOSITE:
            CHECK_CALL (e, ComposeDetail (lpv, i, & composites [c]));
            break;
         case HIERARCHICAL_COMPOSITE:
            CHECK_CALL (e, ComposeHierarchical (lpv, i, & composites [c]));
            break;
         case DEMAND_COMPOSITE:
            CHECK_CALL (e, ComposeDemand (lpv, i, & composites [c]));
            break;
      }
   }

   CHECK_CALL (e, ErrorMapViewToExtended (VIEW_OP_COMPOSE, ComposeEtc (lpv)));
   return e;
}


/*--------------------------------------------------------------------
   Creates the tables maintained and needed by the view. They are
   created in the database denoted by wLinkNo. You should not
   currently be in a transaction when calling this function.
*/
VIEWCALL scInitExtendedBaseCreate (
   HPIB hPIB,
   WORD wLinkNo)
{
   ERRNUM e = ERRNUM_SUCCESS;

   e = ErrorMapDatabaseToExtended (wLinkNo, fileAdd (wLinkNo, hPIB));
   return e;
}


/*--------------------------------------------------------------------
   Removes the logical record from the database.
*/
VIEWCALL scInitExtendedBaseDelete (
   LPVOID lpView)
{
   ERRNUM e = ERRNUM_SUCCESS;
   LPV lpv = (LPV) lpView;

   if (! (GetPermissions (lpv) & SEC_DELETE)) {
      ReportSecurityError (lpv, MAKE_OP_RSC(VIEW_OP_DELETE));
      return ERRNUM_PERMISSION_NONE;
   }

   if ( lpv->pViewSelection!=NULL ) {
      ReportGenericError (lpv, ERRGEN_AREA_DATABASE, DBS_OP_DELETE, DBS_NOT_ALLOWED, NULL);
      return ERRNUM_RECORD_PROTOCOL;
   }

   CHECK_CALL (e, ErrorMapViewToExtended (VIEW_OP_DELETE, DeleteValid (lpv)));
   CHECK_CALL (e, ErrorMapDatabaseToExtended (lpv->wLinkNo, fileBegin (lpv)));

   MaxError (&e, BaseNotifyFire (
      lpv, INSTANCE_NOTIFY_RECORD_DELETING, VIEW_OP_DELETE, NULL));
   if ( ERRNUM_IS_SUCCESS (e) ) {
      MaxError (&e, DeleteBody (lpv));
      if ( ERRNUM_IS_SUCCESS (e) ) {
         lpv->bUnpostedRevisions = TRUE;
         MaxError (&e, ApplyHeaderFields (lpv, VIEW_OP_DELETE));
         if ( ERRNUM_IS_SUCCESS (e) ) {
            MaxError (&e, BaseNotifyFire (
               lpv, INSTANCE_NOTIFY_RECORD_DELETED, VIEW_OP_DELETE, NULL));
            if ( ERRNUM_IS_SUCCESS (e) ) {
               MaxError (&e, ErrorMapDatabaseToExtended (lpv->wLinkNo, fileCommit (lpv)));
               if ( ERRNUM_IS_SUCCESS (e) ) {
                  lpv->bExists = FALSE;
                  lpv->bVerified = FALSE;
                  lpv->bKeyGenerated = GENERATEKEY_NONE;
                  MaxError (&e, ClearChange (lpv));
                  return e;
               }
            }
            MaxError (&e, ReverseHeaderFields (lpv, VIEW_OP_INSERT));
         }
      }
   }

   fileRollback (lpv);
   return e;
}



/*--------------------------------------------------------------------
   Reports whether fields have been altered with scInitPut calls.
*/
VIEWCALL scInitExtendedBaseDirty (
   LPVOID lpView,
   LPBOOL lpbChanged)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   *lpbChanged = lpv->bDirty;
   if ( !*lpbChanged ) {
      CHECK_CALL (e, UnpostedDetails (lpv, 2+HDR_HAS_REVISIONS, lpbChanged));
   }

   if ( !*lpbChanged && SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
      LPVIEWDEF base = &lpv->subCmp;

      CHECK_CALL (e, viewDirty (base->rvh, base->view, lpbChanged));
   }

   return e;
}


/*--------------------------------------------------------------------
   Deletes tables created by scInitCreate from the database denoted by
   wLinkNo. You should not currently be in a transaction when
   calling this function.
*/
VIEWCALL scInitExtendedBaseDrop (
   HPIB hPIB,
   WORD wLinkNo)
{
   return ErrorMapDatabaseToExtended (wLinkNo, fileDrop (wLinkNo, hPIB));
}


/*--------------------------------------------------------------------
   Reports whether the current logical record exists in the database.
*/
VIEWCALL scInitExtendedBaseExists (
   LPVOID lpView,
   LPBOOL lpbExists)
{
   ERRNUM e = ERRNUM_SUCCESS;
   DB_ERRNUM d = DBS_SUCCESS;
   LPV lpv = (LPV) lpView;

   d = fileLocate (lpv);
   switch ( d ) {
      case DBS_SUCCESS:
         *lpbExists = TRUE;
         e = ERRNUM_SUCCESS;
         break;
      case DBS_NOT_FOUND:
         *lpbExists = FALSE;
         e = ERRNUM_SUCCESS;
         break;
      default:
         *lpbExists = FALSE;
         e = ErrorMapDatabaseToExtended (lpv->wLinkNo, d);
         break;
   }
   lpv->bBrowsing = FALSE;
   lpv->bBrowseEnded = TRUE;
   lpv->bExists = *lpbExists;
   return e;
}


/*--------------------------------------------------------------------
   Retrieves the next logical record according to the direction and
   filter set in the last scInitBrowse call.
*/
VIEWCALL scInitExtendedBaseFetch (
   LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   INT flags = FETCHFILTER_UNLOCKED | FETCHFILTER_NEXTMAYBE;

   if (! (GetPermissions (lpv) & SEC_INQUIRE)) {
      ReportSecurityError (lpv, MAKE_OP_RSC(VIEW_OP_FETCH));
      return ERRNUM_PERMISSION_NONE;
   }
   if ( lpv->bSelectFromStart )
      flags |= FETCHFILTER_FROMSTART;
   return xxxFetch (lpView, flags);
}


/*--------------------------------------------------------------------
   Retrieves the next logical record according to the direction and
   filter set in the last scInitBrowse call. scInitFetchLock is the
   same as scInitFetch except that the record is locked.
*/
VIEWCALL scInitExtendedBaseFetchLock (
   LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   INT flags = FETCHFILTER_LOCKED | FETCHFILTER_NEXTMAYBE;

   if (! (GetPermissions (lpv) & SEC_INQUIRE)) {
      ReportSecurityError (lpv, MAKE_OP_RSC(VIEW_OP_FETCH_LOCK));
      return ERRNUM_PERMISSION_NONE;
   }
   if ( lpv->bSelectFromStart )
      flags |= FETCHFILTER_FROMSTART;
   return xxxFetch (lpView, flags);
}


/*--------------------------------------------------------------------
   Returns the name and field index of a field.
*/
VIEWCALL scInitExtendedBaseField (
   LPVOID lpView,
   INT nFldNumber,
   LPSTR lpsFldName,
   LPLONG lplField)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   if ( SUBCLASS_LEVEL==NOT_SUBCLASS ) {
      if (nFldNumber < 1 || nFldNumber > FLD_IDX_COUNT) {
         ReportFieldError (lpv, nFldNumber);
         return ERRNUM_FIELD_NUMBER;
      }
   } else {
      if ( nFldNumber<=lpv->subFields || nFldNumber>FLD_IDX_COUNT+lpv->subFields ) {
         MaxError (&e, viewField (lpv->subCmp.rvh, lpv->subCmp.view,
                                  nFldNumber, lpsFldName, lplField));
         return e;
      }
      nFldNumber -= lpv->subFields;
   }

   *lplField = * FindFieldIndexV (lpv, nFldNumber - 1);
   blkCopy (lpsFldName, FindFieldDefV (lpv, *lplField)->sName, SIZEOF_FIELDNAME);
   return e;
}



/*----------------------------------------------------------------------------
   Returns whether the given field index is valid. No error message is reported.
*/
VIEWCALL scInitExtendedBaseFieldExists (
   LPV view,
   LONG lField,
   LP_A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   if ( ValidIndexV (view, lField) ) {
      *flags = FIELD_EXISTS_YES;
   } else if ( SUBCLASS_LEVEL==NOT_SUBCLASS ) {
      *flags = FIELD_EXISTS_NO;
   } else {
      LPVIEWDEF base = &view->subCmp;

      // There is no graceful way to emulate this entrypoint, so let the
      // base view's rotoEntry() sort it out.
      MaxError (&e, viewFieldExists ((LPRVH) base->rvh, base->view, lField, flags));
   }
   return e;
}



/*--------------------------------------------------------------------
   Returns the symbolic name and full description of a field.
*/
VIEWCALL scInitExtendedBaseFieldName (
   LPV view,
   LONG lField,
   LPSTR lpsName,
   LPSTR lpsDesc,
   A4W_SIZE size)
{
   ERRNUM e = ERRNUM_SUCCESS;

   if ( ValidIndexV (view, lField) ) {
      strCopyBZ (lpsName, SIZEOF_FIELDNAME, FindFieldDefV (view, lField)->sName);
      if ( lpsDesc!=NULL ) {
         switch ( size ) {
         case 0:
               break;
            case 1:
               *lpsDesc = 0;
               break;
            default:
               rscLoadText (view->hpib, APPL, FindFieldMapV (view, lField)->title, lpsDesc, size);
               break;
         }
      }
   } else if ( SUBCLASS_LEVEL==NOT_SUBCLASS ) {
      ReportIndexError (view, lField);
      e = ERRNUM_FIELD_INDEX;
   } else {
      if ( blkCompare (view->subVersionTemplate, "55A", SIZEOF_VERSION)>=0 ) {
         CHECK_CALL (e, viewFieldName ((LPRVH) view->subCmp.rvh, view->subCmp.view,
                                       lField, lpsName, lpsDesc, size));
      } else {
         // If this entrypoint isn't supported by the base view, emulate it
         // at the expense of a (possibly) truncated description
         CHAR desc [SIZEOF_FLDDESC];
         LPVIEWDEF base = &view->subCmp;

         CHECK_CALL (e, viewName (base->rvh, base->view, lField, lpsName, desc));
         if ( lpsDesc!=NULL ) {
            switch ( size ) {
               case 0:
                  break;
               case 1:
                  *lpsDesc = 0;
                  break;
               default:
                  strCopyZB (lpsDesc, desc, min (size-1, sizeof (desc)));
                  break;
            }
         }
      }
   }
   return e;
}



/*--------------------------------------------------------------------
   Returns the number of fields available in the view.
*/
VIEWCALL scInitExtendedBaseFields (
   LPVOID lpView,
   LPSHORT lpnFields)
{
   if ( SUBCLASS_LEVEL==NOT_SUBCLASS ) {
      *lpnFields = FLD_IDX_COUNT;
   } else {
      LPV lpv = (LPV) lpView;

      *lpnFields = lpv->subFields + FLD_IDX_COUNT;
   }
   return ERRNUM_SUCCESS;
}



VIEWCALL scInitExtendedBaseFilterCount (
   LPV lpv,
   LPSTR expression,
   A4W_FLAGS flags,
   LP_A4W_SIZE count)
{
   ERRNUM e = ERRNUM_SUCCESS;
   DB_ERRNUM d = DBS_SUCCESS;
   FL_ERRNUM f = FL_SUCCESS;
   FILTER filter;
   WORD op;
   LPSTR range = expression;
   LPSTR reduced = expression;
   LPLONG indexes = NULL;
   SHORT segments = 0;
   LONG physical [FLD_IDX_COUNT+1]; // +1 is superfluous, but needed in case there are no fields
   INT i = 0;
   BOOL contains;

   blkSet (&filter, 0, sizeof (filter));
   if ( expression==NULL ) {
      op = FILTER_OP_EXPR_SEGMENTS;
      f = filterExprSegments (lpv, &lpv->filter, lpv->wDetailFilterSegments,
                              (FILTERNAME) xxxNameOnly, (FILTERGET) scInitGet, &range);
      RVSPYTRACE (range);
      CHECK_CALL_GOTO (e, cleanup,
                       ErrorMapFilterToExtended (op, filterErrorV (lpv, op, f)));
   }
   reduced = range;

   op = FILTER_OP_PARSE;
   f = filterParse (lpv, range, &filter, (FILTERFIELD) scInitField, (FILTERFIELDS) scInitFields, (FILTERTYPE) scInitType);
   CHECK_CALL_GOTO (e, cleanup, ErrorMapFilterToExtended (op, filterErrorV (lpv, op, f)));

   if ( SUBCLASS_LEVEL==NOT_SUBCLASS ) {
      indexes = physical;
      segments = 0;
      for ( i=0; i<FLD_IDX_COUNT; ++i ) {
         LONG f = * FindFieldIndexV (lpv, i);

         if ( FindFieldMapV (lpv, f)->tblNo==BASE_TBL_COUNT )
            physical [segments++] = f;
      }
      contains = TRUE;
   } else {
      indexes = FindFieldIndexV (lpv, 0);
      segments = FLD_IDX_COUNT;
      contains = FALSE;
   }

   if ( filterReduce (&filter, indexes, segments, contains, FALSE) ) {
      op = FILTER_OP_EXPRESSION;
      f = filterExpression (lpv, &filter, (FILTERNAME) xxxNameOnly, &reduced);
      RVSPYTRACE (reduced);
      CHECK_CALL (e, ErrorMapFilterToExtended (op, filterErrorV (lpv, op, f)));
      // return a warning since reduced filter will select more records
      MaxError (&e, WARNING_FILTERCOUNT_APPROXIMATE);
   }

   CHECK_CALL_GOTO (e, cleanup,
      ErrorMapDatabaseToExtended (lpv->wLinkNo,
                                  fileFilterCount (lpv, reduced, 0L, count)));

   lpv->bBrowsing = FALSE;
   lpv->bBrowseEnded = TRUE;
   lpv->bBrowseInSync = FALSE;

cleanup:
   filterFree (&filter);
   if ( range!=reduced )
      filterExprFree (reduced);
   if ( expression!=range )
      filterExprFree (range);

   return e;
}



/*--------------------------------------------------------------------
   Deletes all records matching the specified filter
*/
VIEWCALL scInitExtendedBaseFilterDelete (
   LPV lpv,
   LPSTR expression,
   A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;
   DB_ERRNUM d = DBS_SUCCESS;
   FL_ERRNUM f = FL_SUCCESS;
   FILTER filter, reduced;
   WORD op;
   LPSTR range = expression;
   LPLONG indexes = NULL;
   SHORT segments = 0;
   LONG physical [FLD_IDX_COUNT+1]; // +1 is superfluous, but needed in case there are no fields
   INT i = 0;
   BOOL contains, OnlyPrimaryTableFields, OnlyKeyFields;
   A4W_FLAGS strictness = flags & MASK_FILTER_DELETE_STRICTNESS;
   A4W_FLAGS cascade = flags & MASK_FILTER_DELETE_CASCADE;
   INT tables = TBL_COUNT;

   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS )
      ++tables;

   if (! (GetPermissions (lpv) & SEC_DELETE)) {
      ReportSecurityError (lpv, MAKE_OP_RSC(VIEW_OP_FILTER_DELETE));
      return ERRNUM_PERMISSION_NONE;
   }

   blkSet (&filter, 0, sizeof (filter));
   blkSet (&reduced, 0, sizeof (reduced));
   if ( lpv->wKey!=0 && strictness==FILTER_DELETE_STRICT &&
        (tables>=2 || (DTL_CMP_COUNT>0 && cascade==FILTER_DELETE_CASCADE)) ) {
      ReportError (lpv, (RSCID)IDERR_SC_FILTER_DELETE_MSG,
                   MAKERSC(IDS_SCINIT_VIEW_NOUN),
                   MAKERSC(MAKE_OP_RSC(VIEW_OP_FILTER_DELETE)),
                   NULL);
      CHECK_CALL_GOTO (e, cleanup, ERRNUM_GENERAL);
   }
   if ( expression==NULL ) {
      op = FILTER_OP_EXPR_SEGMENTS;
      f = filterExprSegments (lpv, &lpv->filter, lpv->wDetailFilterSegments,
                              (FILTERNAME) xxxNameOnly, (FILTERGET) scInitGet, &range);
      RVSPYTRACE (range);
      CHECK_CALL_GOTO (e, cleanup,
         ErrorMapFilterToExtended (op, filterErrorV (lpv, op, f)));
   }

   op = FILTER_OP_PARSE;
   f = filterParse (lpv, range, &filter, (FILTERFIELD) scInitField, (FILTERFIELDS) scInitFields, (FILTERTYPE) scInitType);
   CHECK_CALL_GOTO (e, cleanup,
      ErrorMapFilterToExtended (op, filterErrorV (lpv, op, f)));

   if ( SUBCLASS_LEVEL==NOT_SUBCLASS ) {
      indexes = physical;
      segments = 0;
      for ( i=0; i<FLD_IDX_COUNT; ++i ) {
         LONG f = * FindFieldIndexV (lpv, i);

         if ( FindFieldMapV (lpv, f)->tblNo==BASE_TBL_COUNT )
            physical [segments++] = f;
      }
      contains = TRUE;
   } else {
      indexes = FindFieldIndexV (lpv, 0);
      segments = FLD_IDX_COUNT;
      contains = FALSE;
   }
   OnlyPrimaryTableFields = !filterReduce (&filter, indexes, segments, contains, TRUE);

   if ( !OnlyPrimaryTableFields )
      OnlyKeyFields = FALSE;
   else {
      op = FILTER_OP_COPY;
      f = filterCopy (&reduced, &filter);
      CHECK_CALL_GOTO (e, cleanup,
         ErrorMapFilterToExtended (op, filterErrorV (lpv, op, f)));
      if ( SUBCLASS_LEVEL==NOT_SUBCLASS ) {
         indexes = FindKeyDef (lpv->wKey)->indexes;
         segments = FindKeyDef (lpv->wKey)->segments;
      } else {
         indexes = lpv->subCmpKey.indexes;
         segments = lpv->subCmpKey.segments;
      }
      OnlyKeyFields = !filterReduce (&reduced, indexes, segments, TRUE, TRUE);
   }

   if ( (!OnlyPrimaryTableFields && strictness!=FILTER_DELETE_SIMULATE) ||
        (!OnlyKeyFields && strictness==FILTER_DELETE_STRICT &&
         (tables>=2 || (DTL_CMP_COUNT>0 && cascade==FILTER_DELETE_CASCADE))) ) {
      op = FILTER_OP_REDUCE;
      f = filterErrorV (lpv, op, FL_FIELD_NOT_FOUND);
      MaxError (&e, ErrorMapFilterToExtended (op, f));
      goto cleanup;
   }

   RevisionSpyLevels (lpv);
   CHECK_CALL_GOTO (e, cleanup,
      ErrorMapDatabaseToExtended (lpv->wLinkNo, RevisionOuterCancel (lpv)));
   d = fileTransBegin (lpv);
   MaxError (&e, ErrorMapDatabaseToExtended (lpv->wLinkNo, d));
   if ( ERRNUM_IS_SUCCESS (e) ) {
      MaxError (&e, BaseNotifyFire (
         lpv, INSTANCE_NOTIFY_RECORD_DELETING, VIEW_OP_FILTER_DELETE, NULL));
      if ( ERRNUM_IS_SUCCESS (e) ) {
         // Use fileFilterDelete if TRY or STRICT, or if SIMULATE and no orphans will be left
         if ( strictness!=FILTER_DELETE_SIMULATE ||
              (OnlyKeyFields ||
               (OnlyPrimaryTableFields && tables<2 &&
                (DTL_CMP_COUNT==0 || cascade!=FILTER_DELETE_CASCADE))) ) {
            // return a warning if orphans may be left
            if ( strictness!=FILTER_DELETE_SIMULATE &&
                 (!OnlyPrimaryTableFields || !OnlyKeyFields) &&
                 (tables>=2 || DTL_CMP_COUNT>0) ) {
               // Not entirely sure about the above test....
               MaxError (&e, WARNING_FILTERDELETE_ORPHANS);
            }
            if ( OnlyKeyFields && cascade==FILTER_DELETE_CASCADE ) {
               MaxError (&e, MapToDetails (lpv, VIEW_OP_FILTER_DELETE, &filter, flags));
            }
            if ( ERRNUM_IS_SUCCESS (e) )
               MaxError (&e, ErrorMapDatabaseToExtended (lpv->wLinkNo, fileFilterDelete (lpv, &filter)));
         } else { // Simulate using a good ol' init then a fetch-delete loop
            MaxError (&e, InitFields (lpv));
            if ( ERRNUM_IS_SUCCESS (e) ) {
               MaxError (&e, ErrorMapDatabaseToExtended (lpv->wLinkNo,
                                                         RevisionCreate (lpv)));
               if ( ERRNUM_IS_SUCCESS (e) ) {
                  ERRNUM result = ERRNUM_SUCCESS;
                  SHORT currentRange = 0;
                  REV_ERRNUM r = POST_DONE;

                  RevisionSpyLevels (lpv);
                  // This is an extreme subset of what the template does when
                  // init, fetch and delete are called externally
                  op = FILTER_OP_GET_RANGES;
                  f = filterGetRanges (lpv, &filter, lpv->wKey, xxxKey);
                  MaxError (&e, ErrorMapFilterToExtended (op, filterErrorV (lpv, op, f)));
                  while ( ERRNUM_IS_SUCCESS (e) && ERRNUM_IS_SUCCESS (result) ) {
                     result = xxxFetchFilter (lpv, FETCHFILTER_UNLOCKED |
                                                   FETCHFILTER_FROMHERE |
                                                   FETCHFILTER_NEXTREALLY,
                                              &filter, &currentRange, TRUE);
                     switch ( result ) {
                        case ERRNUM_RECORD_NO_MORE_DATA:
                           break;
                        case ERRNUM_SUCCESS:
                           MaxError (&e, DeleteBody (lpv));
                           break;
                        default:
                           MaxError (&e, result);
                     }
                  }
                  RevisionSpyLevels (lpv);
                  while ( (r = filePost (lpv))==POST_CONTINUE )
                     ;
                  if ( r==POST_ERROR ) {
                     MaxError (&e, ErrorMapDatabaseToExtended (lpv->wLinkNo, lpv->eRevision));
                     fileCancel (lpv);
                  }
               }
            }
         }
         MaxError (&e, BaseNotifyFire (
            lpv, INSTANCE_NOTIFY_RECORD_DELETED, VIEW_OP_FILTER_DELETE, NULL));
      }
      if ( ERRNUM_IS_FAILURE (e) )
         d = fileTransRollback (lpv);
      else
         d = fileTransCommit (lpv);
      MaxError (&e, ErrorMapDatabaseToExtended (lpv->wLinkNo, d));
   }

   // Recreate the revisions unconditionally
   MaxError (&e, ErrorMapDatabaseToExtended (lpv->wLinkNo, RevisionCreate (lpv)));
   RevisionSpyLevels (lpv);
   lpv->bBrowsing = FALSE;
   lpv->bBrowseEnded = TRUE;
   lpv->bBrowseInSync = FALSE;
   lpv->bExists = FALSE;
   MaxError (&e, ClearChange (lpv));
   lpv->bVerified = FALSE;
   lpv->bKeyGenerated = GENERATEKEY_NONE;
   lpv->bUnpostedRevisions = FALSE;

cleanup:
   filterFree (&reduced);
   filterFree (&filter);
   if ( expression!=range )
      filterExprFree (range);

   return e;
}



VIEWCALL scInitExtendedBaseFilterFetch       (LPV lpv, A4W_FLAGS flags)
{
   INT mapped_flags = FETCHFILTER_NEXTREALLY;

   if (! (GetPermissions (lpv) & SEC_INQUIRE)) {
      ReportSecurityError (lpv, MAKE_OP_RSC(VIEW_OP_FILTER_FETCH));
      return ERRNUM_PERMISSION_NONE;
   }
   if ( lpv->bSelectFromStart )
      mapped_flags |= FETCHFILTER_FROMSTART;
   if ( flags & FILTER_FETCH_LOCK )
      mapped_flags |= FETCHFILTER_LOCKED;
   return xxxFetch (lpv, mapped_flags);
}



VIEWCALL scInitExtendedBaseFilterSelect     (LPV view, INT key, LPSTR filter, A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;
   BOOL ascending = (flags & MASK_FILTER_SELECT_DIRECTION)==FILTER_SELECT_ASCENDING;

   view->bSelectFromStart = ((flags & MASK_FILTER_SELECT_FROM)==FILTER_SELECT_FROMSTART);
   CHECK_CALL (e, scInitOrder (view, key));
   CHECK_CALL (e, scInitBrowse (view, filter, ascending));
   return e;
}



/*--------------------------------------------------------------------
   Retrieves a value from a field.
*/
VIEWCALL scInitExtendedBaseGet (
   LPVOID lpView,
   LONG lField,
   LPSTR lpsBuffer,
   INT nSize)
{
   LPV lpv = (LPV) lpView;
   LPDBFIELD lpdbf;
   ERRNUM e = ERRNUM_SUCCESS;
   LPSTR from;
   LONG attribs;

   if ( lField==FILLER_IDX && (SUBCLASS_LEVEL==NOT_SUBCLASS || BASE_TBL_COUNT>0) ) {
      WORD length = FindTableMapV (lpv, 0)->table->wRecordLength;

      blkCopy (lpsBuffer, (FindRecord (lpv)) [0] + length,
               FindTableWidth (lpv, 0) - length);
      return ERRNUM_SUCCESS;
   }

   if ( lField==DIRTY_IDX ) {
      A4W_FLAGS flags;

      CHECK_CALL (e, scInitRevisionUnposted (lpv, 1+HDR_HAS_REVISIONS, &flags));
      if ( (flags & MASK_REVISION_UNPOSTED)==REVISION_UNPOSTED_YES )
         * (LPDBSBOOL) lpsBuffer = TRUE;
      else
         * (LPDBSBOOL) lpsBuffer = FALSE;
      return e;
   }
   if ( lField==ROTOTYPE_IDX ) {
#if SUBCLASS_LEVEL!=NOT_SUBCLASS
      * (LPDBSINT) lpsBuffer = VIEW_ROTO_SUBCLASS;
#elif defined(STUB_VIEW)
      * (LPDBSINT) lpsBuffer = VIEW_ROTO_STUB;
#else
      * (LPDBSINT) lpsBuffer = VIEW_ROTO_VIEW;
#endif
      return ERRNUM_SUCCESS;
   }
   if ( lField==SYSACCESS_IDX ) {
      if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
         CHECK_CALL (e, viewGetInteger (lpv->subCmp.rvh, lpv->subCmp.view,
                                        lField, &lpv->sysAccess));
      }
      * (LPDBSINT) lpsBuffer = lpv->sysAccess;
      return ERRNUM_SUCCESS;
   }
   if ( lField==REFINT_IDX ) {
      if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
         CHECK_CALL (e, viewGetLong (lpv->subCmp.rvh, lpv->subCmp.view,
                                     lField, &lpv->refIntegrity));
      }
      * (LPDBSLONG) lpsBuffer = lpv->refIntegrity;
      return ERRNUM_SUCCESS;
   }
   if ( lField==DUPKEYCHECK_IDX ) {
      if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
         CHECK_CALL (e, viewGetBoolean (lpv->subCmp.rvh, lpv->subCmp.view,
                                        lField, &lpv->bCheckDuplicates));
      }
      * (LPDBSBOOL) lpsBuffer = lpv->bCheckDuplicates;
      return ERRNUM_SUCCESS;
   }
   if ( lField==ETAG_IDX ) {
      CHECK_CALL (e, GetETAG (lpv, lpsBuffer, nSize));
      return e;
   }

   if (!ValidIndexV (lpv, lField)) {
      if ( SUBCLASS_LEVEL==NOT_SUBCLASS ) {
         ReportIndexError (lpv, lField);
         return ERRNUM_GENERAL;
      } else {
         MaxError (&e, viewGet (lpv->subCmp.rvh, lpv->subCmp.view,
                                lField, lpsBuffer, nSize));
         return e;
      }
   }
   CHECK_CALL (e, ErrorMapViewToExtended (VIEW_OP_GET,
                                          GetEtc (lpv, lField, lpsBuffer, nSize)));
   attribs = AttribGet (lpv, lField);
   CHECK_CALL (e, lpv->eValidation);
   if ( !(attribs & ATTR_ENABLED) || (attribs & ATTR_NULL) ) {
      ReportDisabledError (lpv, lField);
      return ERRNUM_FIELD_DISABLED;
   }
   lpdbf = FindFieldDefV (lpv, lField);
   from = FindFieldValue (lpv, lField);

   // Check whether there are difficulties with the target buffer
   if ( !ValidateBuffer (lpv, lField, nSize) )
      return ERRNUM_MEMORY_BUFFER_LIMIT;

   // Assign the value
   switch ( lpdbf->wType ) {
      case FT_BCD:
         bcdAssign ((LPDBSNUMBER) lpsBuffer, min (nSize, (INT) lpdbf->wLength), lpdbf->wDecimals,
                    (LPDBSNUMBER) from, lpdbf->wLength, lpdbf->wDecimals, FALSE);
         break;
      default:
         InitFieldBuffer (lpsBuffer, lpdbf->wType, nSize);
         blkCopy (lpsBuffer, from, min (nSize, (INT) lpdbf->wLength));
         break;
   }
   return e;
}


/*--------------------------------------------------------------------
   Blanks, zeroes, or defaults (as appropriate) the contents of each
   field in a view.
*/
VIEWCALL scInitExtendedBaseInit (
   LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
      CHECK_CALL (e, viewInit (lpv->subCmp.rvh, lpv->subCmp.view));
   }
   CHECK_CALL (e, InitBody (lpv));
   return e;
}



/*--------------------------------------------------------------------
   Creates a new logical record in the database from the contents of
   the current logical record. The key must not currently exist in
   the database. If the integrity of the record has not been
   verified, it is automatically done; if the integrity fails, the
   record is not added.
*/
VIEWCALL scInitExtendedBaseInsert (
   LPVOID lpView)
{
   ERRNUM e = ERRNUM_SUCCESS;
   LPV lpv = (LPV) lpView;
   DB_ERRNUM d = DBS_SUCCESS;

   if (! (GetPermissions (lpv) & SEC_ADD)) {
      ReportSecurityError (lpv, MAKE_OP_RSC(VIEW_OP_INSERT));
      return ERRNUM_PERMISSION_NONE;
   }

   if ( HAS_REVISIONS==SEQUENCE_REVISIONS && GENERATEKEY_NONE==lpv->bKeyGenerated ) {
      // If the view uses a sequenced revision list, and is composed with any
      // of its details, the key must have been generated via scInitRecordGenerate()
      int c;

      for ( c=HDR_CMP_COUNT; c<HDR_CMP_COUNT+DTL_CMP_COUNT; ++c ) {
         if ( NULL!=FindCmp (lpv, c)->rvh ) {
            ReportGenericError (lpv, ERRGEN_AREA_DATABASE, REV_OP_INSERT_AFTER,
                                DBS_NOT_ALLOWED, NULL);
            return ERRNUM_REVISION_PROTOCOL;
         }
      }
   }

   if ( lpv->pViewSelection!=NULL ) {
      ReportGenericError (lpv, ERRGEN_AREA_DATABASE, DBS_OP_INSERT, DBS_NOT_ALLOWED, NULL);
      return ERRNUM_RECORD_PROTOCOL;
   }

   CHECK_CALL (e, xxxVerify (lpView, TRUE));
   CHECK_CALL (e, ErrorMapDatabaseToExtended (lpv->wLinkNo, fileBegin (lpv)));
   MaxError (&e, GenerateKeyReally (lpv));
   if ( ERRNUM_IS_SUCCESS (e) ) {
      lpv->bBrowsing = FALSE;
      lpv->bBrowseEnded = TRUE;
      lpv->bSelectFromStart = FALSE;
      if ( DETAILS_ARE_REVISIONED && DO_CASCADEPOST!=CASCADEPOST_AFTERHEADER ) {
         MaxError (&e, MapToNestedDetails (lpv, VIEW_OP_POST));
      }
      if ( ERRNUM_IS_SUCCESS (e) ) {
         MaxDatabaseError (&d, fileInsert (lpv));
         if ( DB_ERRNUM_IS_SUCCESS (d) ) {
            if ( DETAILS_ARE_REVISIONED && DO_CASCADEPOST==CASCADEPOST_AFTERHEADER ) {
               CopyRecords (lpv, FindRecordTemp (lpv), FindRecord (lpv));
            }
            lpv->bUnpostedRevisions = TRUE;
            MaxError (&e, ApplyHeaderFields (lpv, VIEW_OP_INSERT));
            if ( ERRNUM_IS_SUCCESS (e) ) {
               MaxError (&e, PutCmpDetailSequence (lpv));
               if ( ERRNUM_IS_SUCCESS (e) ) {
                  MaxError (&e, RewriteRecord (lpv));
                  if ( ERRNUM_IS_SUCCESS (e) ) {
                     MaxError (&e, BaseNotifyFire (
                        lpv, INSTANCE_NOTIFY_RECORD_WRITTEN, VIEW_OP_INSERT, NULL));
                     if ( ERRNUM_IS_SUCCESS (e) ) {
                        MaxDatabaseError (&d, fileCommit (lpv));
                        if ( DB_ERRNUM_IS_SUCCESS (d) ) {
                           lpv->bBrowseInSync = TRUE;
                           lpv->bExists = TRUE;
                           SaveHeaderFields (lpv);
#if defined(DO_RECORDREAD) || defined(DO_CONCURRENCYETC)
                           CopyRecords (lpv, FindRecordRead (lpv), FindRecord (lpv));
#endif
                           MaxError (&e, ClearChange (lpv));
                           lpv->bKeyGenerated = GENERATEKEY_NONE;
                           return e;
                        }
                     }
                  }
               }
               MaxError (&e, ReverseHeaderFields (lpv, VIEW_OP_DELETE));
            }
         }
      }
   }

   fileRollback (lpv);
   CHECK_CALL (e, ErrorMapDatabaseToExtended (lpv->wLinkNo, d));

   return e;
}



VIEWCALL scInitExtendedBaseInstanceFieldList (LPV view, A4W_FLAGS flags, A4W_SIZE count, PLONG fields)
{
   ERRNUM e = ERRNUM_SUCCESS;
#if defined DO_INSTANCE_FIELDLIST
   A4W_FLAGS what;

   switch ( flags & MASK_INSTANCE_FIELDLIST_SELECTION ) {
      case INSTANCE_FIELDLIST_SELECT_ALL:
         CHECK_CALL (e, SelectionCancel (view));
         break;

      case INSTANCE_FIELDLIST_SELECT:
         CHECK_CALL (e, SelectionValid (view, count, fields));
         CHECK_CALL (e, SelectionCancel (view));
         CHECK_CALL (e, SetAttribs (view, ATTR_NULL));
         what = SELECTION_PRIMARY_KEY | SELECTION_SUBCLASS_FIELDS;
         if ( !view->bReadOnly &&
              (flags & MASK_INSTANCE_FIELDLIST_ACCESS)!=INSTANCE_FIELDLIST_READONLY )
            what |= SELECTION_AUDIT_STAMP;
         CHECK_CALL (e, SelectionIncrease (view, what, count, fields));
         break;

      case INSTANCE_FIELDLIST_SELECT_INCREASE:
         if ( NULL==view->pViewSelection )
            break; // Everything is already selected!
         CHECK_CALL (e, SelectionValid (view, count, fields));
         CHECK_CALL (e, SelectionIncrease (view, 0, count, fields));
         break;

      default: // REVIEW: Shouldn't we really report some sort of error?
         break;
   }
#endif
   return e;
}



VIEWCALL scInitExtendedBaseInstanceNotify   (LPV view, A4W_NOTIFY_PROC notify, LPVOID context, A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;
   LPNOTIFYCONTEXT NotifyList = view->NotifyList;

   switch ( flags & MASK_INSTANCE_NOTIFY_OPERATION ) {
      case INSTANCE_NOTIFY_ADD:
         MaxError (&e, NotifyAdd (view, notify, context, flags));
         break;

      case INSTANCE_NOTIFY_REMOVE:
         MaxError (&e, NotifyRemove (view, notify, context));
         break;

      default: // Shouldn't we really report some sort of error?
         break;
   }
   return e;
}



VIEWCALL scInitExtendedBaseInstanceOpen (LPRVH rvh, HPIB PIB, WORD link, A4W_FLAGS flags, LPVOID extra, A4W_SIZE size, LPV FAR * view)
{
   return OpenBody (rvh, PIB, link, flags, extra, size, view);
}



VIEWCALL scInitExtendedBaseInstanceProtocol (LPV lpv, A4W_FLAGS flags, LP_A4W_FLAGS protocols, LP_A4W_SIZE count)
{
   ERRNUM e = ERRNUM_SUCCESS;

   if ( SUBCLASS_LEVEL==NOT_SUBCLASS ) {
      LPVIEWDEF header = FindCmp (lpv, 0);
      LPKEYMAP k = FindKeyDef (0);

      if ( (flags & INSTANCE_PROTOCOL_HEADERS_TOO)==0 ||
           (HDR_CMP_COUNT==0 || header==NULL || header->rvh==NULL) ) {
         *count = 1;
      } else {
         CHECK_CALL (e, viewInstanceProtocol ((LPRVH) header->rvh, header->view,
                                              flags, protocols+1, count));
         *count += 1;
      }

      // Basic protocol
    #if defined(FLAT_VIEW)
      *protocols = INSTANCE_PROTOCOL_BASIC_FLAT;
    #elif defined(HEADER_VIEW)
      *protocols = INSTANCE_PROTOCOL_BASIC_HEADER;
    #elif defined(DETAIL_VIEW)
      *protocols = INSTANCE_PROTOCOL_BASIC_DETAIL;
    #elif defined(BATCH_VIEW)
      *protocols = INSTANCE_PROTOCOL_BASIC_BATCH;
    #elif defined(SUPER_VIEW)
      *protocols = INSTANCE_PROTOCOL_BASIC_SUPER;
    #endif

      // Revision protocol modifiers
      if ( HAS_REVISIONS==NO_REVISIONS )
         *protocols |= INSTANCE_PROTOCOL_REVISION_NONE;
      else if ( HAS_REVISIONS==SEQUENCE_REVISIONS )
         *protocols |= INSTANCE_PROTOCOL_REVISION_SEQUENCED;
      else if ( HAS_REVISIONS==ORDER_REVISIONS )
         *protocols |= INSTANCE_PROTOCOL_REVISION_ORDERED;

      // Automatic key generation protocol modifier
    #if defined(DO_GENERATEKEY) || HAS_REVISIONS==SEQUENCE_REVISIONS || defined(DO_GENERATEKEYDELAYED)
      *protocols |= INSTANCE_PROTOCOL_GENERATE_KEY;
    #endif

      // Header existence protocol modifier
    #if defined(BATCH_VIEW) && HDR_CMP_COUNT>0
      *protocols |= INSTANCE_PROTOCOL_HEADER_MUST_EXIST;
    #endif

      // Subclass protocol modifiers
      *protocols |= INSTANCE_PROTOCOL_SUBCLASS_NONE;

      // Detail key segments added to header's key
      if ( HDR_CMP_COUNT>0 )
         *protocols |= DTL_SEG_COUNT;
      else if ( k!=NULL )
         *protocols |= k->segments;

   } else {
      LPVIEWDEF base = &lpv->subCmp;

      CHECK_CALL (e, viewInstanceProtocol ((LPRVH) base->rvh, base->view,
                                           flags, protocols, count));

      // Subclass protocol modifiers
      if ( SUBCLASS_LEVEL==OVERRIDE_SUBCLASS )
         *protocols |= INSTANCE_PROTOCOL_SUBCLASS_OVERRIDE;
      else if ( SUBCLASS_LEVEL==ALTER_SUBCLASS )
         *protocols |= INSTANCE_PROTOCOL_SUBCLASS_ALTER;
      else if ( SUBCLASS_LEVEL==JOIN_SUBCLASS )
         *protocols |= INSTANCE_PROTOCOL_SUBCLASS_JOIN;
   }

   return e;
}



VIEWCALL scInitExtendedBaseInstanceSecurity (LPV lpv, LP_A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   if ( !lpv->bSecEnabled ) {
      // QUESTION: SHOULD WE BE USING: ~0L ??????????
      *flags = (SEC_ADD | SEC_MODIFY | SEC_DELETE | SEC_INQUIRE | SEC_POST);
   } else if ( SUBCLASS_LEVEL==NOT_SUBCLASS ) {
      if ( RSC_COUNT==0 ) {
         // QUESTION: SHOULD WE BE USING: ~0L ??????????
         *flags = (SEC_ADD | SEC_MODIFY | SEC_DELETE | SEC_INQUIRE | SEC_POST);
      } else {
         CHECK_CALL (e, SecurityPermissions (lpv->hpib, lpv->wLinkNo,
                                             FindPermissionMap (), RSC_COUNT, flags));
      }
   } else {
      if ( blkCompare (lpv->subVersionTemplate, "50A", SIZEOF_VERSION)<0 ) {
         CHECK_CALL (e, viewSecurity (lpv->subCmp.rvh, lpv->hpib, lpv->wLinkNo, (LPLONG) flags));
      } else {
         CHECK_CALL (e, viewInstanceSecurity ((LPRVH) lpv->subCmp.rvh, lpv->subCmp.view, flags));
      }
   }
   return e;
}



/*--------------------------------------------------------------------
   Returns the definition of a key. In general, use this routine
   only for application functions that need symbolic access to key
   information
*/
VIEWCALL scInitExtendedBaseKey (
   LPVOID lpView,
   INT nKeyNo,
   LPSTR lpsName,
   LPSHORT lpnFields,
   LPLONG lplKeyFields)
{
   ERRNUM e = ERRNUM_SUCCESS;
   LPV lpv = (LPV) lpView;
   SHORT keys = 0;
   LPKEYMAP lpkmap;
   INT nSeg;
   CHAR name [SIZEOF_FLDDESC+1];

   if ( SUBCLASS_LEVEL==NOT_SUBCLASS ) {
      if (nKeyNo < 0 || nKeyNo >= KEY_COUNT) {
         ReportKeyError (lpv, nKeyNo);
         return ERRNUM_KEY_NUMBER;
      }
   } else {
      keys = lpv->subKeys;
      if ( nKeyNo < keys || nKeyNo >= keys+KEY_COUNT )
         return viewKey (lpv->subCmp.rvh, lpv->subCmp.view,
                         nKeyNo, lpsName, lpnFields, lplKeyFields);
   }
   if ( KEY_COUNT==0 )
      return e;
   lpkmap = FindKeyDef (nKeyNo-keys);
   rscLoadText (lpv->hpib, APPL, (RSCID) lpkmap->name, name, sizeof (name));
   strCopyBZ (lpsName, SIZEOF_FLDDESC, name);
   *lpnFields = lpkmap->segments;
   for (nSeg = 0; nSeg < lpkmap->segments; nSeg++)
      *lplKeyFields++ = lpkmap->indexes [nSeg];
   return e;
}



/*--------------------------------------------------------------------
   Returns the number of keys available in the view. It is used in
   conjunction with scInitKey to retrieve information about key
   structure.
*/
VIEWCALL scInitExtendedBaseKeys (
   LPVOID lpView,
   LPSHORT lpnKeys)
{
   LPV lpv = (LPV) lpView;

   *lpnKeys = KEY_COUNT;
   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS )
      *lpnKeys += lpv->subKeys;
   return ERRNUM_SUCCESS;
}


/*--------------------------------------------------------------------
   Returns the symbolic name and description of a field.
*/
VIEWCALL scInitExtendedBaseName (
   LPVOID lpView,
   LONG lField,
   LPSTR lpsName,
   LPSTR lpsDesc)
{
   LPV lpv = (LPV) lpView;
   CHAR desc [SIZEOF_FLDDESC+1];
   WORD rscID;
   ERRNUM e = ERRNUM_SUCCESS;

   if ( lField==TITLE_IDX ) {
      blkSet (lpsName, ' ', SIZEOF_FIELDNAME);
      rscID = IDS_SCINIT_VIEW_NAME;
   } else if ( !ValidIndexV (lpv, lField) ) {
      if ( SUBCLASS_LEVEL==NOT_SUBCLASS ) {
         ReportIndexError (lpv, lField);
         return ERRNUM_FIELD_INDEX;
      } else {
         // should it also bypass the title index?
         return viewName (lpv->subCmp.rvh, lpv->subCmp.view, lField, lpsName, lpsDesc);
      }
   } else {
      strCopyBZ (lpsName, SIZEOF_FIELDNAME, FindFieldDefV (lpv, lField)->sName);
      rscID = FindFieldMapV (lpv, lField)->title;
   }
   rscLoadText (lpv->hpib, APPL, rscID, desc, sizeof (desc));
   strCopyBZ (lpsDesc, SIZEOF_FLDDESC, desc);
   return e;
}



/*--------------------------------------------------------------------
   Opens a view. The caller must specify the calling application
   function's program information block and handle for the database
   connection where the desired data is located. A view handle is
   returned when an instance of the view has been opened.
*/
VIEWCALL scInitExtendedBaseOpen (
   HPIB hPIB,
   WORD wLinkNo,
   LPVOID FAR * lplpView)
{
   return OpenBody (NULL, hPIB, wLinkNo,
                    INSTANCE_OPEN_READWRITE|INSTANCE_OPEN_VALIDATED|INSTANCE_OPEN_REVISIONED,
                    NULL, 0, (LPV FAR *) lplpView);
}



/*--------------------------------------------------------------------
   Sets the order in which a view is accessed.
*/
VIEWCALL scInitExtendedBaseOrder (
   LPVOID lpView,
   INT nKeyNo)
{
   ERRNUM e = ERRNUM_SUCCESS;
   LPV lpv = (LPV) lpView;
   WORD keys = 0;

   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS )
      keys = lpv->subKeys;
   if ( lpv->wKey==(WORD) nKeyNo )
      return ERRNUM_SUCCESS;
   if (nKeyNo < 0) {
      ReportKeyError (lpv, nKeyNo);
      return ERRNUM_KEY_NUMBER;
   } else if ( (WORD) nKeyNo>=keys+KEY_COUNT &&
               (WORD) nKeyNo-FAKE_KEY_COUNT>=lpv->wNoOfKeys ) {
      ReportKeyError (lpv, nKeyNo);
      return ERRNUM_KEY_NUMBER;
   }

   CHECK_CALL (e, OrderBody (lpv, keys, nKeyNo));
   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS &&
        (lpv->wKey<keys+KEY_COUNT-FAKE_KEY_COUNT || lpv->wKey>=keys+KEY_COUNT) ) {
      CHECK_CALL (e, viewOrder (lpv->subCmp.rvh, lpv->subCmp.view, lpv->wActualKey));
   }
   if ( (SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS) &&
        HAS_REVISIONS!=NO_REVISIONS && lpv->bRevisioned ) {
      if ( lpv->wNoOfKeys>1 ) {
         RevisionSpyLevels (lpv);
         CHECK_CALL (e, ErrorMapDatabaseToExtended (
                           lpv->wLinkNo, RevisionOuterCancel (lpv)));
         CHECK_CALL (e, ErrorMapDatabaseToExtended (
                           lpv->wLinkNo, RevisionCancel (lpv, FindRevCache (lpv))));
         CHECK_CALL (e, ErrorMapDatabaseToExtended (
                           lpv->wLinkNo,
                           RevisionGenerate (lpv, FindRevCache (lpv), (LPREVISION) NULL)));
         CHECK_CALL (e, ErrorMapDatabaseToExtended (
                           lpv->wLinkNo, RevisionCreate (lpv)));
         lpv->bUnpostedRevisions = FALSE;
         RevisionSpyLevels (lpv);
      }
   }
   return e;
}



/*--------------------------------------------------------------------
   Commits any pending changes to the database.
*/
VIEWCALL scInitExtendedBasePost (
   LPVOID lpView)
{
   ERRNUM e = ERRNUM_SUCCESS;
   LPV lpv = (LPV) lpView;

#if !(defined(DETAIL_VIEW) || defined(SUPER_VIEW))
   if ( HAS_REVISIONS==NO_REVISIONS ) {
      rvspyTrace ("WARNING: scInitPost is no longer supported on non-revisioned views.");
   }
#endif

   RevisionSpyLevels (lpv);
   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
      LPVIEWDEF base = &lpv->subCmp;

      CHECK_CALL (e, BasePutData (lpv));
      CHECK_CALL (e, viewPost (base->rvh, base->view));
   }

   if ( SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS ) {
      CHECK_CALL (e, BaseNotifyFire (lpv, INSTANCE_NOTIFY_REVISION_POSTING, 1, NULL));
      MaxError (&e, RevisionInnerPost (lpv, 1));
      lpv->bUnpostedRevisions = FALSE;
      lpv->bKeyGenerated = GENERATEKEY_NONE;
      if ( ERRNUM_IS_FAILURE (e) ) {
         MaxError (&e, BaseNotifyFire (
            lpv, INSTANCE_NOTIFY_REVISION_CANCELLED, 1, (LPVOID) TRUE));
      } else {
         MaxError (&e, BaseNotifyFire (lpv, INSTANCE_NOTIFY_REVISION_POSTED, 1, NULL));
      }
   }
   RevisionSpyLevels (lpv);
   return e;
}



/*--------------------------------------------------------------------
   Returns the field's external presentation definition. If both
   the mask and list addresses are NULL, the routine's purpose is to
   fill an LPRESENTSINFO information structure whose address is
   passed in lpBuffer. This information structure allows a caller
   to determine which presentation attributes a field has, as well as
   how much space is required for subsequent calls.
*/
VIEWCALL scInitExtendedBasePresents (
   LPVOID lpView,
   LONG lField,
   LPSTR lpsMask,
   LPSHORT lpnList,
   LPSHORT lpnCount,
   LPVOID lpBuffer,
   INT size)
{
   LPV lpv = (LPV) lpView;
   LPPRESENTATION lppres;
   ERRNUM e = ERRNUM_SUCCESS;
   LONG attribs;

   if ( !ValidIndexV (lpv, lField) ) {
      if ( SUBCLASS_LEVEL==NOT_SUBCLASS ) {
         ReportIndexError (lpv, lField);
         return ERRNUM_FIELD_INDEX;
      } else {
         return viewPresents (lpv->subCmp.rvh, lpv->subCmp.view, lField,
                              lpsMask, lpnList, lpnCount, (LPSTR) lpBuffer, size);
      }
   }

   attribs = AttribGet (lpv, lField);
   CHECK_CALL (e, lpv->eValidation);
   if ( !(attribs & ATTR_ENABLED) || (attribs & ATTR_NULL) ) {
      ReportDisabledError (lpv, lField);
      return ERRNUM_FIELD_DISABLED;
   }

   lppres = FindPresentsInfo (lpv, lField);
   CHECK_CALL (e, lpv->eValidation);
   if (lpsMask == NULL && lpnList == NULL) {
      LPPRESENTSINFO lppresInfo = (LPPRESENTSINFO) lpBuffer;
      CHAR buffer [MAX_FIELD_LENGTH];
      INT i, l;
      LPSTR data;

      if (lppres==NULL)
         lppresInfo->type = PRESENTS_NONE;
      else {
         switch ( lppresInfo->type = lppres->type ) {
            case PRESENTS_LIST:
               i = lppresInfo->presents.list.elements = (SHORT) lppres->elements;
               lppresInfo->presents.list.size = 0;
               while ( i-- )
                  lppresInfo->presents.list.size += (SHORT)
                     rscLoadText (lpv->hpib, APPL, lppres->listStrs[i],
                                  buffer, MAX_FIELD_LENGTH) + 1;
               break;
            case PRESENTS_LIST_INLINE:
               lppresInfo->type = PRESENTS_LIST;
               i = lppresInfo->presents.list.elements = (SHORT) lppres->elements;
               lppresInfo->presents.list.size = 0;
               data = lppres->mask;
               while ( i-- ) {
                  l = 1+strLength (data);
                  lppresInfo->presents.list.size += (SHORT) l;
                  data += l;
               }
               break;
            case PRESENTS_MASK:
               lppresInfo->presents.mask.segments = (SHORT) lppres->elements;
               LoadMask (lpv->hpib, lppres->mask, MAX_FIELD_LENGTH, buffer);
               lppresInfo->presents.mask.size = 1+strLength (buffer);
               break;
            default:
               break;
         }
      }
      return ERRNUM_SUCCESS;
   }

   if (lppres == NULL)
      return ERRNUM_SUCCESS;
   if ( lppres->type==PRESENTS_MASK && lpsMask!=NULL && lppres->mask!=NULL ) {
      LoadMask (lpv->hpib, lppres->mask, size, lpsMask);
      return ERRNUM_SUCCESS;
   }
   if ( lppres->type==PRESENTS_LIST && lpnList!=NULL && lppres->listNums!=NULL ) {
      INT i, l;

      l = 0;
      *lpnCount = 0;
      for ( i=0; i<lppres->elements && l<size; i++ ) {
         lpnList[i] = lppres->listNums[i];
         l += rscLoadText (lpv->hpib, APPL, lppres->listStrs[i],
                             &((LPSTR)lpBuffer)[l], size - l) + 1;
         *lpnCount += 1;
      }
      return ERRNUM_SUCCESS;
   }
   if ( lppres->type==PRESENTS_LIST_INLINE && lpnList!=NULL && lppres->listNums!=NULL ) {
      INT i, d, l;
      LPSTR data;

      data = lppres->mask;
      l = 0;
      *lpnCount = 0;
      for ( i=0; i<lppres->elements && l<size; i++ ) {
         lpnList[i] = lppres->listNums[i];
         strCopy (&((LPSTR)lpBuffer)[l], data);
         d = 1+strLength (data);
         l += d;
         data += d;
         *lpnCount += 1;
      }
      return ERRNUM_SUCCESS;
   }
   return ERRNUM_GENERAL;
}



/*--------------------------------------------------------------------
   Used by special types of views as signals to perform the operations
   such as Year-end processing.
*/
VIEWCALL scInitExtendedBaseProcess (
   LPVOID lpView)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
      CHECK_CALL (e, BasePutData (lpv));
      CHECK_CALL (e, viewProcess (lpv->subCmp.rvh, lpv->subCmp.view));
   }
   CHECK_CALL (e, ErrorMapViewToExtended (VIEW_OP (lpv, OPEN), ProcessEtc (lpv)));
   return e;
}



/*--------------------------------------------------------------------
   Stores a value in a field, optionally verifying its integrity. If
   the buffer fails verification, it is not stored.
*/
VIEWCALL scInitExtendedBasePut (
   LPVOID lpView,
   LONG lField,
   LPSTR lpsBuffer,
   INT nSize,
   BOOL bVerify)
{
   LPV lpv = (LPV) lpView;
   LPSTR normalized, target;
   ERRNUM e = ERRNUM_SUCCESS;
   LPDBFIELD f = NULL;
   BOOL mask_error = FALSE;
   LPPRESENTATION p = NULL;
   FIELDCOMPARATOR comparator = NULL;
   CHAR normalizedFieldValue [MAX_FIELD_LENGTH + 1];
   LONG attribs;

   lpv->bFieldChanged = FALSE;
   if ( lField==FILLER_IDX &&
        (SUBCLASS_LEVEL==NOT_SUBCLASS || BASE_TBL_COUNT>0) ) {
      WORD length = FindTableMapV (lpv, 0)->table->wRecordLength;

      blkCopy ((FindRecord (lpv)) [0] + length, lpsBuffer,
                FindTableWidth (lpv, 0) - length);
      return e;
   }
   if ( lField==SYSACCESS_IDX ) {
      if ( lpv->sysAccess==SYSACCESS_IMPORT &&
           * (LPDBSINT) lpsBuffer!=SYSACCESS_IMPORT )
         RevisionCheckDuplicates (lpv, lpv->bCheckDuplicates, NULL);
      lpv->sysAccess = * (LPDBSINT) lpsBuffer;
      if ( lpv->sysAccess==SYSACCESS_IMPORT )
         RevisionCheckDuplicates (lpv, FALSE, NULL);
      if ( SUBCLASS_LEVEL==NOT_SUBCLASS )
         return e;
   }
   if ( lField==REFINT_IDX ) {
      lpv->refIntegrity = * (LPDBSLONG) lpsBuffer;
      if ( SUBCLASS_LEVEL==NOT_SUBCLASS )
         return e;
   }
   if ( lField==DUPKEYCHECK_IDX ) {
      lpv->bCheckDuplicates = * (LPDBSBOOL) lpsBuffer;
      RevisionCheckDuplicates (lpv,
         lpv->bCheckDuplicates && lpv->sysAccess!=SYSACCESS_IMPORT, NULL);
      if ( SUBCLASS_LEVEL==NOT_SUBCLASS )
         return e;
   }
   if ( lField==ETAG_IDX ) {
      CHECK_CALL (e, PutETAG (lpv, lpsBuffer, nSize));
      if ( SUBCLASS_LEVEL==NOT_SUBCLASS )
         return e;
   }

   if ( !ValidIndexV (lpv, lField) ) {
      if ( SUBCLASS_LEVEL==NOT_SUBCLASS ) {
         ReportIndexError (lpv, lField);
         e = ERRNUM_FIELD_INDEX;
      } else {
         LPCMPKEY x = &lpv->subCmpKey;
         LPVIEWDEF base = &lpv->subCmp;
         BOOL CheckForRebrowse = FALSE;
         LPVOID before = NULL, after = NULL;
         SHORT size = 0;

         if ( SUBCLASS_LEVEL==JOIN_SUBCLASS ) {
            INT i;

            for ( i=0; i<x->segments; ++i )
               if ( lField==x->indexes[i] ) {
                  size = x->types[i].size;
                  before = _alloca (size);
                  after = _alloca (size);
                  if ( NULL==before || NULL==after ) {
                     ReportMemoryError (lpv, MAKE_OP_RSC (VIEW_OP (lpv, OPEN)));
                     return ERRNUM_MEMORY_NO_MORE;
                  }
                  CHECK_CALL (e, viewGet (base->rvh, base->view, lField, before, size));
                  CheckForRebrowse = TRUE;
                  break;
               }
         }
         CHECK_CALL (e, viewPut (base->rvh, base->view, lField, lpsBuffer, nSize, bVerify));
         if ( CheckForRebrowse ) {
            CHECK_CALL (e, viewGet (base->rvh, base->view, lField, after, size));
            if ( blkCompare (before, after, size)!=0 ) {
               CHECK_CALL (e, BaseGetKey (lpv));
               CHECK_CALL (e, BaseBrowse (lpv, FALSE));
            }
         }
      }
      return e;
   }

#if defined(DO_OLDIMPORTVALIDATION)
   if ( lpv->sysAccess==SYSACCESS_IMPORT )
      bVerify = FALSE;
   else
#endif
      bVerify = bVerify || (FindFieldMapV (lpv, lField)->flags & FLD_VALIDATE);
   attribs = AttribGet (lpv, lField);
   CHECK_CALL (e, lpv->eValidation);
   if ( !(attribs & ATTR_ENABLED) || (attribs & ATTR_NULL) ) {
      ReportDisabledError (lpv, lField);
      return ERRNUM_FIELD_DISABLED;
   }
   if ( !(attribs & ATTR_EDITABLE) ) {
      ReportReadonlyError (lpv, lField);
      return ERRNUM_FIELD_READONLY;
   }

   f = FindFieldDefV (lpv, lField);

   //allocate a buffer to hold the normalized field value IF the standard
   //buffer [normalizedFieldValue] is not large enough
   if ((f->wLength+1) > (sizeof(normalizedFieldValue))) {
      normalized = (LPSTR) _alloca (f->wLength + 1);
      if ( !normalized ) {
         ReportMemoryError (lpv, MAKE_OP_RSC (VIEW_OP (lpv, OPEN)));
         return ERRNUM_MEMORY_NO_MORE;
      }
   } else {
      normalized = normalizedFieldValue;
   }

   CHECK_CALL (e, NormalizeFieldBuffer (lpv, lField, lpsBuffer, nSize,
                                        normalized, &mask_error));
   if ( mask_error && !lpv->bUnvalidated && bVerify ) {
      ReportMaskError (lpv, lField);
      return ERRNUM_FIELD_INVALID;
   }

   p = FindPresentsInfo (lpv, lField);
   CHECK_CALL (e, lpv->eValidation);

   if ( bVerify && p!=NULL &&
        (p->type==PRESENTS_LIST || p->type==PRESENTS_LIST_INLINE) &&
        !FindFieldMapV (lpv, lField)->validate ) {
      if ( !ValidateList (lpv, p, lField, normalized) ) {
         return ERRNUM_FIELD_INVALID;
      }
   } else if ( bVerify ) {
      if ( !ValidateData (lpv, lField, normalized) ) {
         return ERRNUM_FIELD_INVALID;
      }
   }

   comparator = aTypeComparators [f->wType];
   VIEWASSERT (comparator!=NULL);
#if defined(DO_PUTSAVECURRENT) || (defined(DO_SAFEPUTETC) && defined(DO_PUTETC))
   // Done prior to any user code getting called, and as late as possible
   CopyRecords (lpv, FindRecordTemp (lpv), FindRecord (lpv));
#endif

   // Perform any remaining requested validations
   if ( bVerify ) {
      BOOL bValid = ValidateField (lpv, lField, normalized);

      CHECK_CALL (e, lpv->eValidation);
      if ( !bValid ) {
         return ERRNUM_FIELD_INVALID;
      }
      if ( HCHY_CMP_COUNT+DMND_CMP_COUNT+IMP_CMP_COUNT>0 &&
           * FindCmpForeign (lpv, lField) ) {
 #if !defined(DO_LAZYPUT)
         CHECK_CALL (e, ErrorMapViewToExtended (VIEW_OP_PUT,
               PutCmpFieldAux (lpv, lField, normalized, f->wLength,
                               TRUE, HDR_CMP_COUNT, CMP_COUNT)));
         bValid = ValidateKeyField (lpv, lField);
 #else
         bValid = ValidateKeyField (lpv, lField, normalized, f->wLength);
 #endif
         CHECK_CALL (e, lpv->eValidation);
         if ( !bValid ) {
            return ERRNUM_KEY_INVALID;
         }
      }
   }

   target = FindFieldValue (lpv, lField);
   if ( (* comparator) (f, (LPDATUM) target, (LPDATUM) normalized)!=0 ) {
      lpv->bFieldChanged = TRUE;
      InitFieldBuffer (target, f->wType, f->wLength);
      blkCopy (target, normalized, f->wLength);
      CHECK_CALL (e, AutoCancel (lpv, lField));
      AttribSet (lpv, lField, ATTR_CHANGED);
      CHECK_CALL (e, lpv->eValidation);
      lpv->bDirty = TRUE;
      lpv->bVerified = FALSE;
      if ( attribs & ATTR_KEY ) {
         lpv->bBrowsing = FALSE;
         lpv->bBrowseEnded = TRUE;
         lpv->bSelectFromStart = FALSE;
         lpv->bBrowseInSync = FALSE;
         lpv->bExists = FALSE;
#if defined(DO_CLEARAUDIT)
         // Explicitly assumes MP3 record
         blkSet ((FindRecord (lpv)) [BASE_TBL_COUNT] +
                  FindTableMapV (lpv, BASE_TBL_COUNT)->fields[SCINIT_FLD_AUDIT].wOffset,
                 ' ', sizeof (AUDITSTAMP));
#endif
         if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
            CHECK_CALL (e, BaseBrowse (lpv, FALSE));
         }
      }
      PropagatePrimaryField (lpv, lField);
#if defined(DO_PUTETC) && !defined(DO_SAFEPUTETC)
      // Do any view specific processing such as calculating related fields...
      CHECK_CALL (e, ErrorMapViewToExtended (VIEW_OP_PUT,
         PutEtc (lpv, lField, normalized, f->wLength)));
#endif
      if ( HCHY_CMP_COUNT+DMND_CMP_COUNT+IMP_CMP_COUNT>0 &&
           bVerify && * FindCmpForeign (lpv, lField) )
      {
 #if defined(DO_LAZYPUT)
         CHECK_CALL (e, ErrorMapViewToExtended (VIEW_OP_PUT,
            PutCmpFieldAux (lpv, lField, normalized, f->wLength, FALSE,
                            HDR_CMP_COUNT, HDR_CMP_COUNT+DTL_CMP_COUNT)));
 #endif
      }
      else
      {
         CHECK_CALL (e, ErrorMapViewToExtended (VIEW_OP_PUT,
            PutCmpField (lpv, lField, normalized, f->wLength)));
      }
   }
#if defined(DO_PUTETC)
 #if !defined(DO_SAFEPUTETC)
   else
 #endif
   {
      // Do any view specific processing such as calculating related fields...
      MaxError (&e, ErrorMapViewToExtended (VIEW_OP_PUT,
                                            PutEtc (lpv, lField, normalized, f->wLength)));
      if ( ERRNUM_IS_FAILURE (e) ) {
 #if defined(DO_SAFEPUTETC)
         SwapRecords (FindRecordTemp (lpv), FindRecord (lpv));
 #endif
         return e;
      }
   }
#endif

   return e;
}



/*--------------------------------------------------------------------
   Fetches the logical record index by the current contents of the
   view's key fields. If there are composite views, the caller is
   responsible for reading them in as well.
*/
VIEWCALL scInitExtendedBaseRead (
   LPVOID lpView)
{
   return xxxRead (lpView, FALSE);
}


/*--------------------------------------------------------------------
   Fetches the logical record index by the current contents of the
   view's key fields. If there are composite views, the caller is
   responsible for reading them in as well. scInitReadLock is the
   same as scInitRead except that the record is locked.
*/
VIEWCALL scInitExtendedBaseReadLock (
   LPVOID lpView)
{
   return xxxRead (lpView, TRUE);
}



VIEWCALL scInitExtendedBaseRecordClear (LPV view)
{
   ERRNUM e = ERRNUM_SUCCESS;

   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
      CHECK_CALL (e, viewRecordClear ((LPRVH) view->subCmp.rvh, view->subCmp.view));
   }
   CHECK_CALL (e, InitBodyGen (view, INITBODYGEN_NOINSERT |
                                     INITBODYGEN_NOGENERATE |
                                     INITBODYGEN_NOTOPEN));
   return e;
}



VIEWCALL scInitExtendedBaseRecordGenerate (LPV view, A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;
   INT gen = INITBODYGEN_NOTOPEN;

   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
      CHECK_CALL (e, viewRecordGenerate ((LPRVH) view->subCmp.rvh, view->subCmp.view, flags));
   }
   switch ( flags & MASK_RECORD_GENERATE_INSERT ) {
      case RECORD_GENERATE_INSERT:
         gen |= INITBODYGEN_FORCEINSERT | INITBODYGEN_FORCEGENERATE;
         break;
      case RECORD_GENERATE_NOINSERT:
         gen |= INITBODYGEN_NOINSERT    | INITBODYGEN_FORCEGENERATE;
         break;
      case RECORD_GENERATE_DELAYKEY:
         gen |= INITBODYGEN_NOINSERT    | INITBODYGEN_DELAYGENERATE;
         break;
      default:
         gen |= INITBODYGEN_AUTOINSERT  | INITBODYGEN_FORCEGENERATE;
         break;
   }
   CHECK_CALL (e, InitBodyGen (view, gen));
   return e;
}



VIEWCALL scInitExtendedBaseRevisionCancel   (LPV lpv, INT level)
{
   ERRNUM e = ERRNUM_SUCCESS;

   RevisionSpyLevels (lpv);
   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
      CHECK_CALL (e, viewRevisionCancel ((LPRVH) lpv->subCmp.rvh, lpv->subCmp.view, level));
   }
   CHECK_CALL (e, CancelBody (lpv, level));
   RevisionSpyLevels (lpv);
   return e;
}



VIEWCALL scInitExtendedBaseRevisionExists   (LPV lpv, INT level, LP_A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_ROTOENTRY_FAILED;

   return e;
}



VIEWCALL scInitExtendedBaseRevisionPost     (LPV lpv, INT level)
{
   ERRNUM e = ERRNUM_SUCCESS;
   DB_ERRNUM d = DBS_SUCCESS;
   REV_ERRNUM r = POST_DONE;

#if !(defined(DETAIL_VIEW) || defined(SUPER_VIEW))
   if ( HAS_REVISIONS==NO_REVISIONS ) {
      rvspyTrace ("WARNING: scInitRevisionPost is no longer supported on non-revisioned views.");
   }
#endif

   RevisionSpyLevels (lpv);
   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
      LPVIEWDEF base = &lpv->subCmp;

      CHECK_CALL (e, BasePutData (lpv));
      CHECK_CALL (e, viewRevisionPost ((LPRVH) base->rvh, base->view, level));
   }

   if ( SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS ) {
      CHECK_CALL (e, BaseNotifyFire (
         lpv, INSTANCE_NOTIFY_REVISION_POSTING, level, NULL));
      MaxError (&e, RevisionInnerPost (lpv, level));
      lpv->bKeyGenerated = GENERATEKEY_NONE;
      lpv->bUnpostedRevisions = FALSE;
      if ( ERRNUM_IS_FAILURE (e) ) {
         MaxError (&e, BaseNotifyFire (
            lpv, INSTANCE_NOTIFY_REVISION_CANCELLED, level, (LPVOID) TRUE));
      } else {
         MaxError (&e, BaseNotifyFire (
            lpv, INSTANCE_NOTIFY_REVISION_POSTED, level, NULL));
      }
   }

   RevisionSpyLevels (lpv);
   return e;
}



VIEWCALL scInitExtendedBaseRevisionRekey (LPV lpv, LPVOID OldKey, LPVOID NewKey, INT size, A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;

   RevisionSpyLevels (lpv);
   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
      CHECK_CALL (e, viewRevisionRekey ((LPRVH) lpv->subCmp.rvh, lpv->subCmp.view,
                                        OldKey, NewKey, size, flags));
   }

   CHECK_CALL (e, ErrorMapDatabaseToExtended (
      lpv->wLinkNo, RevisionRekey (lpv, OldKey, NewKey, size, flags)));
   lpv->bKeyGenerated = GENERATEKEY_NONE;
   RevisionSpyLevels (lpv);
   return e;
}



VIEWCALL scInitExtendedBaseRevisionUnposted (LPV lpv, INT level, LP_A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;
   BOOL dirty = FALSE;

   *flags = 0L;
   CHECK_CALL (e, ErrorMapDatabaseToExtended (
                     lpv->wLinkNo, RevisionInnerDirty (lpv, level, &dirty)));

   if ( !dirty && SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
      LPVIEWDEF base = &lpv->subCmp;

      CHECK_CALL (e, viewRevisionUnposted ((LPRVH) base->rvh, base->view,
                                           level, flags));
      if ( (*flags & MASK_REVISION_UNPOSTED)==REVISION_UNPOSTED_YES )
         dirty = TRUE;
   }

   if ( dirty )
      *flags |= REVISION_UNPOSTED_YES;
   return e;
}



/*--------------------------------------------------------------------
   Returns the functionality the user is permitted to access in the
   given database link.
*/
VIEWCALL scInitExtendedBaseSecurity (
   HPIB hPIB,
   WORD wLinkNo,
   LPLONG lplPermissions)
{
   ERRNUM e = ERRNUM_SUCCESS;

   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
      CHECK_CALL (e, BaseGetPermissions (hPIB, wLinkNo, lplPermissions));
   } else if ( RSC_COUNT==0 ) {
      // QUESTION: SHOULD WE BE USING: ~0L ??????????
      *lplPermissions = (SEC_ADD | SEC_MODIFY | SEC_DELETE | SEC_INQUIRE | SEC_POST);
   } else {
      BOOL enabled;
      DB_ERRNUM d = lnkIsSecEnabled (wLinkNo, &enabled);

      if ( DB_ERRNUM_IS_FAILURE (d) ) {
         MaxError (&e, ErrorMapDatabaseToExtended (wLinkNo, dbError (wLinkNo, hPIB, d)));
      } else if ( enabled ) {
         CHECK_CALL (e, SecurityPermissions (hPIB, wLinkNo, FindPermissionMap (),
                                             RSC_COUNT, (LP_A4W_FLAGS) lplPermissions));
      } else {
         // QUESTION: SHOULD WE BE USING: ~0L ??????????
         *lplPermissions = (SEC_ADD | SEC_MODIFY | SEC_DELETE | SEC_INQUIRE | SEC_POST);
      }
   }
   return e;
}



/*--------------------------------------------------------------------
   Deletes all records unconditionally
*/
VIEWCALL scInitExtendedBaseTableEmpty (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;
   DB_ERRNUM d = DBS_SUCCESS;

   if (! (GetPermissions (lpv) & SEC_DELETE)) {
      ReportSecurityError (lpv, MAKE_OP_RSC(VIEW_OP_FILTER_DELETE));
      return ERRNUM_PERMISSION_NONE;
   }

   RevisionSpyLevels (lpv);
   CHECK_CALL (e, ErrorMapDatabaseToExtended (lpv->wLinkNo,
                                              RevisionOuterCancel (lpv))); // OUTER

   d = fileTransBegin (lpv);
   CHECK_CALL (e, ErrorMapDatabaseToExtended (lpv->wLinkNo, d));

   MaxError (&e, BaseNotifyFire (
      lpv, INSTANCE_NOTIFY_RECORD_DELETING, VIEW_OP_TABLE_EMPTY, NULL));
   if ( ERRNUM_IS_SUCCESS (e) ) {
      MaxError (&e, MapToDetails (lpv, VIEW_OP_TABLE_EMPTY));
      if ( ERRNUM_IS_SUCCESS (e) ) {
         MaxError (&e, ErrorMapDatabaseToExtended (lpv->wLinkNo, fileEmpty (lpv)));
         if ( ERRNUM_IS_SUCCESS (e) ) {
            MaxError (&e, BaseNotifyFire (
               lpv, INSTANCE_NOTIFY_RECORD_DELETED, VIEW_OP_TABLE_EMPTY, NULL));
         }
      }
   }

   if ( ERRNUM_IS_FAILURE (e) )
      d = fileTransRollback (lpv);
   else
      d = fileTransCommit (lpv);
   MaxError (&e, ErrorMapDatabaseToExtended (lpv->wLinkNo, d));
   // Recreate the revisions unconditionally
   MaxError (&e, ErrorMapDatabaseToExtended (lpv->wLinkNo,
                                             RevisionCreate (lpv)));
   lpv->bKeyGenerated = GENERATEKEY_NONE;
   lpv->bUnpostedRevisions = FALSE;
   RevisionSpyLevels (lpv);
   return e;
}



/*--------------------------------------------------------------------
   Returns a field's type information. The style attached to a type
   varies by type.
*/
VIEWCALL scInitExtendedBaseType (
   LPVOID lpView,
   LONG nField,
   LPTYPE lptype)
{
   LPDBFIELD lpdbf;
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   if ( !ValidIndexV (lpv, nField) ) {
      if ( SUBCLASS_LEVEL==NOT_SUBCLASS ) {
         ReportIndexError (lpv, nField);
         return ERRNUM_FIELD_INDEX;
      } else {
         return viewType (lpv->subCmp.rvh, lpv->subCmp.view, nField, lptype);
      }
   }
   lpdbf = FindFieldDefV (lpv, nField);
   lptype->type = lpdbf->wType;
   lptype->size = lpdbf->wLength;
   lptype->precision = lpdbf->wDecimals;
   lptype->styles = 0;
   return e;
}


/*--------------------------------------------------------------------
   Unlocks the logical record locked by the scInitFetchLock or the
   scInitReadLock calls.
*/
VIEWCALL scInitExtendedBaseUnLock (
   LPVOID lpView)
{
   LPV lpv = (LPV) lpView;

   return ErrorMapDatabaseToExtended (lpv->wLinkNo, fileUnLock (lpv));
}



/*--------------------------------------------------------------------
   Writes the contents of the existing logical record back to the
   database using the current key. The key fields should not have
   been altered; if they are use the scInitInsert routine instead.
*/
VIEWCALL scInitExtendedBaseUpdate (
   LPVOID lpView)
{
   ERRNUM e = ERRNUM_SUCCESS;
   LPV lpv = (LPV) lpView;
   DB_ERRNUM d = DBS_SUCCESS;

   if ( !(GetPermissions (lpv) & SEC_MODIFY) ) {
      ReportSecurityError (lpv, MAKE_OP_RSC(VIEW_OP_UPDATE));
      return ERRNUM_PERMISSION_NONE;
   }

   CHECK_CALL (e, xxxVerify (lpView, FALSE));
   CHECK_CALL (e, ErrorMapDatabaseToExtended (lpv->wLinkNo, fileBegin (lpv)));

   if ( !(lpv->bExists && lpv->bBrowseInSync) ) {
      DB_ERRNUM l = fileIsLocked (lpv);

      if ( DB_ERRNUM_IS_FAILURE (l) ) {
         MaxDatabaseError (&d, fileOptLock (lpv, TRUE));
      }
   }
   if ( DB_ERRNUM_IS_SUCCESS (d) ) {
      if ( DETAILS_ARE_REVISIONED && DO_CASCADEPOST!=CASCADEPOST_AFTERHEADER ) {
         MaxError (&e, MapToNestedDetails (lpv, VIEW_OP_POST));
      }
      if ( ERRNUM_IS_SUCCESS (e) ) {
         MaxDatabaseError (&d, fileUpdate (lpv));
         if ( DB_ERRNUM_IS_SUCCESS (d) ) {
            if ( DETAILS_ARE_REVISIONED && DO_CASCADEPOST==CASCADEPOST_AFTERHEADER ) {
               CopyRecords (lpv, FindRecordTemp (lpv), FindRecord (lpv));
            }
            lpv->bUnpostedRevisions = TRUE;
            MaxError (&e, ApplyHeaderFields (lpv, VIEW_OP_UPDATE));
            if ( ERRNUM_IS_SUCCESS (e) ) {
               if ( DETAILS_ARE_REVISIONED && DO_CASCADEPOST==CASCADEPOST_AFTERHEADER ) {
                  MaxError (&e, MapToNestedDetails (lpv, VIEW_OP_POST));
               }
               if ( ERRNUM_IS_SUCCESS (e) ) {
                  MaxError (&e, RewriteRecord (lpv));
                  if ( ERRNUM_IS_SUCCESS (e) ) {
                     MaxError (&e, BaseNotifyFire (
                        lpv, INSTANCE_NOTIFY_RECORD_WRITTEN, VIEW_OP_UPDATE, NULL));
                     if ( ERRNUM_IS_SUCCESS (e) ) {
                        MaxDatabaseError (&d, fileCommit (lpv));
                        if ( DB_ERRNUM_IS_SUCCESS (d) ) {
                           SaveHeaderFields (lpv);
#if defined(DO_RECORDREAD) || defined(DO_CONCURRENCYETC)
                           CopyRecords (lpv, FindRecordRead (lpv), FindRecord (lpv));
#endif
                           MaxError (&e, ClearChange (lpv));
                           return e;
                        }
                     }
                  }
               }
               MaxError (&e, ReverseHeaderFields (lpv, VIEW_OP_UPDATE));
            }
         }
      }
   }

   fileRollback (lpv);
   CHECK_CALL (e, ErrorMapDatabaseToExtended (lpv->wLinkNo, d));
   return e;
}



/*--------------------------------------------------------------------
   Checks the referential integrity of the current record of the view.
*/
VIEWCALL scInitExtendedBaseVerify (
   LPVOID lpView)
{
   return xxxVerify (lpView, TRUE);
}



//====================================================================



VIEWBASE xxxFetch (LPVOID lpView, INT flags)
{
   LPV lpv = (LPV) lpView;

   return xxxFetchFilter (lpv, flags, &lpv->filter, &lpv->nCurrentRange, lpv->bAhead);
}



VIEWBASE xxxFetchFilterBase (LPV lpv, INT flags, LPFILTER filter, LPSHORT range, BOOL ascending)
{
   ERRNUM e = ERRNUM_SUCCESS;
   DB_ERRNUM d = DBS_SUCCESS;
   FL_ERRNUM f = FL_SUCCESS;
   BOOL started = lpv->bBrowsing;
   WORD filterOp;
   BOOL bLock = (flags & MASK_FETCHFILTER_LOCKED)==FETCHFILTER_LOCKED;
   BOOL bNextReally = (flags & MASK_FETCHFILTER_NEXT)==FETCHFILTER_NEXTREALLY;

   CopyRecords (lpv, FindRecordTemp (lpv), FindRecord (lpv));
   if ( !started ) {
      CHECK_CALL (e, PullHeaderKey (lpv));
      filterOp = FILTER_OP_INIT_RANGE;
      f = filterInitRange (lpv, filter, ascending, range,
                           (FILTERGET) scInitGet, (FILTERPUT) scInitPut);
      if ( FL_ERRNUM_IS_FAILURE (f) )
         goto ReturnFilterError;
   }

   for (;;) {
      if ( started ) {
         MaxDatabaseError (&d, fileNext (lpv, bLock));
      } else {
         MaxDatabaseError (&d, fileFirst (lpv, flags));
         started = TRUE;
      }
      switch ( d ) {
         case DBS_SUCCESS:
         case DBS_CVIEW_WARNING:
            if ( KEY_COUNT>0 && bNextReally && lpv->bBrowseInSync ) {
               if ( ComparePrimary (lpv, FindRecordTemp (lpv))==0 )
                  continue;
            }
            CHECK_CALL_GOTO (e, ReturnError,
               ErrorMapViewToExtended (VIEW_OP (lpv, OPEN),
                                       ERROR_FROM_CALLOUT (CalculateFields (lpv))));
            filterOp = FILTER_OP_EVAL;
            f = filterEval (lpv, (FILTERGET) scInitGet, filter, ascending, *range);
            switch ( f ) {
               case FL_SUCCESS:
                  goto RecordFound;
               case FL_FAIL:
               case FL_END_OF_RANGE:
                  break;
               default:
                  goto ReturnFilterError;
            }
            break;
         case DBS_NO_MORE_DATA:
            break;
         default:
            goto ReturnFileError;
      }
      if ( f==FL_END_OF_RANGE || d==DBS_NO_MORE_DATA ) {
         filterOp = FILTER_OP_NEXT_RANGE;
         f = filterNextRange (filter, ascending, range);
         if ( FL_ERRNUM_IS_FAILURE (f) )
            goto ReturnFilterError;
         filterOp = FILTER_OP_PUT_RANGE;
         f = filterPutRange (lpv, filter, ascending, *range, (FILTERPUT) scInitPut);
         if ( FL_ERRNUM_IS_FAILURE (f) )
            goto ReturnFilterError;
         if ( DB_ERRNUM_IS_FAILURE (d) )
            d = DBS_SUCCESS;
         started = FALSE;
      }
   }

RecordFound:
   lpv->bBrowsing = TRUE;
   lpv->bBrowseEnded = FALSE;
   if ( DETAILS_ARE_REVISIONED ) {
      CHECK_CALL_GOTO (e, ReturnError, MapToNestedDetails (lpv, VIEW_OP_CANCEL));
   }
#if defined(DO_RECORDREAD) || defined(DO_CONCURRENCYETC)
   CopyRecords (lpv, FindRecordRead (lpv), FindRecord (lpv));
#endif
   CHECK_CALL_GOTO (e, ReturnError,
      ErrorMapViewToExtended (VIEW_OP_PUT, ERROR_FROM_CALLOUT (PutCmpFields (lpv))));
   SaveHeaderFields (lpv);
   CHECK_CALL_GOTO (e, ReturnError, BaseNotifyFire (
      lpv, INSTANCE_NOTIFY_RECORD_RETRIEVED, VIEW_OP (lpv, OPEN), NULL));
   CHECK_CALL_GOTO (e, ReturnError, ClearChange (lpv));
   lpv->bVerified = FALSE;
   lpv->bExists = TRUE;
   lpv->bBrowseInSync = TRUE;
   lpv->bKeyGenerated = GENERATEKEY_NONE;
   // ??????????? Should this be getting reset in ReturnError too?
   lpv->bSelectFromStart = FALSE;
   return e;

ReturnError:
   MaxError (&e, ClearChange (lpv));
   SwapRecords (FindRecordTemp (lpv), FindRecord (lpv));
   if ( e==ERRNUM_RECORD_NO_MORE_DATA )
      lpv->bBrowseEnded = TRUE;
   if ( SUBCLASS_LEVEL==JOIN_SUBCLASS && !BasePutKey (lpv) ) {
      LPVIEWDEF base = &lpv->subCmp;

      if ( lpv->bExists )
         viewRead (base->rvh, base->view);
   }
   return e;

ReturnFilterError:
   if ( f!=FL_END_OF_ALL_RANGES )
      filterErrorV (lpv, filterOp, f);
   e = ErrorMapFilterToExtended (filterOp, f);
   goto ReturnError;

ReturnFileError:
   e = ErrorMapDatabaseToExtended (lpv->wLinkNo, d);
   goto ReturnError;
}



VIEWCALL xxxKey (
   LPVOID lpView,
   INT nKeyNo,
   LPSTR lpsName,
   LPSHORT lpnFields,
   LPLONG lplKeyFields)
// Call gate for scInitKey, intended for use by the filter* routines.
// It Suppresses reporting of boundary errors, though others may be reported.
{
   ERRNUM e = ERRNUM_SUCCESS;
   LPV lpv = (LPV) lpView;
   SHORT keys = 0;

   *lpnFields = 0;
   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS )
      keys = lpv->subKeys;

   if ( nKeyNo<keys || nKeyNo>=keys+KEY_COUNT ) {
      if ( SUBCLASS_LEVEL!=NOT_SUBCLASS && nKeyNo<keys ) {
         MaxError (&e, viewKey (lpv->subCmp.rvh, lpv->subCmp.view,
                                nKeyNo, lpsName, lpnFields, lplKeyFields));
      }
      return e;
   }
   MaxError (&e, scInitKey (lpView, nKeyNo, lpsName, lpnFields, lplKeyFields));
   return e;
}



VIEWCALL xxxNameOnly (
   LPVOID lpView,
   LONG lField,
   LPSTR lpsName,
   LPSTR lpsDesc)

// Callback function for any filter routines needing to retrieve the names of
// fields, but not needing the language-specific description. Note that
// TITLE_IDX is essentially ignored, since filter routines don't care.

{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;

   if ( ValidIndexV (lpv, lField) ) {
      strCopyBZ (lpsName, SIZEOF_FIELDNAME, FindFieldDefV (lpv, lField)->sName);
   } else if ( SUBCLASS_LEVEL==NOT_SUBCLASS ) {
      ReportIndexError (lpv, lField);
      return ERRNUM_FIELD_INDEX;
   } else {
      return viewName (lpv->subCmp.rvh, lpv->subCmp.view, lField, lpsName, lpsDesc);
   }
   return e;
}



VIEWBASE xxxReadBase (LPVOID lpView, BOOL bLock)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;
   DB_ERRNUM d = DBS_SUCCESS;

   if ( !(GetPermissions (lpv) & SEC_INQUIRE) ) {
      ReportSecurityError (lpv, MAKE_OP_RSC(VIEW_OP_READ));
      return ERRNUM_PERMISSION_NONE;
   }

   MaxDatabaseError (&d, fileGet (lpv, bLock));
   if ( DB_ERRNUM_IS_FAILURE (d) )
      lpv->bExists = FALSE;
   else {
      lpv->bExists = TRUE;
      MaxError (&e,
                ErrorMapViewToExtended (VIEW_OP (lpv, OPEN),
                                        ERROR_FROM_CALLOUT (CalculateFields (lpv))));
      if ( ERRNUM_IS_SUCCESS (e) ) {
         if ( DETAILS_ARE_REVISIONED ) {
            MaxError (&e, MapToNestedDetails (lpv, VIEW_OP_CANCEL));
         }
         if ( ERRNUM_IS_SUCCESS (e) ) {
#if defined(DO_RECORDREAD) || defined(DO_CONCURRENCYETC)
            CopyRecords (lpv, FindRecordRead (lpv), FindRecord (lpv));
#endif
            MaxError (&e,
                      ErrorMapViewToExtended (VIEW_OP_PUT,
                                              ERROR_FROM_CALLOUT (PutCmpFields (lpv))));
            if ( ERRNUM_IS_SUCCESS (e) ) {
               lpv->bKeyGenerated = GENERATEKEY_NONE;
               SaveHeaderFields (lpv);
               MaxError (&e, BaseNotifyFire (
                  lpv, INSTANCE_NOTIFY_RECORD_RETRIEVED, VIEW_OP (lpv, OPEN), NULL));
            }
         }
      }
      // ?????? Should the following only be done if no errors AT ALL were encountered?
      MaxError (&e, ClearChange (lpv));
      lpv->bVerified = FALSE;
      lpv->bBrowseInSync = TRUE;
      // ??????????? Does the following make sense to be reset only when record read?
      lpv->bSelectFromStart = FALSE;
   }
   lpv->bBrowsing = FALSE;
   lpv->bBrowseEnded = TRUE;
   MaxError (&e, ErrorMapDatabaseToExtended (lpv->wLinkNo, d));
   return e;
}



VIEWBASE xxxVerify (LPVOID lpView, BOOL verifying)
{
   LPV lpv = (LPV) lpView;
   INT nFld;
   BOOL errors = FALSE;
   LONG lField;
   LPPRESENTATION p;
   LPSTR data, temp;
   LPDBFIELD f = NULL;
   WORD result;
   ERRNUM e = ERRNUM_SUCCESS;
   LONG attribs;

#define LOG_INVALID_FIELD(FLD) { \
   if ( (FLD)!=NULL ) \
      RVSPYPRINT(("Invalid field %10.10s", (FLD)->sName)); \
}

#define VALIDATE(__expr__) {          \
   BOOL __valid__ = (__expr__);       \
   MaxError (&e, lpv->eValidation);   \
   if ( !__valid__ ) {                \
      errors = TRUE;                  \
      LOG_INVALID_FIELD(f);           \
      if ( ERRNUM_IS_FAILURE (e) )    \
         goto protocol_error;         \
   }                                  \
   lpv->eValidation = ERRNUM_SUCCESS; \
}

   if ( lpv->bVerified ) {
      BOOL dirty = FALSE;

#if defined(DO_OLDVERIFYDIRTY)
      // Even if we have previously verified successfully,
      // if the view is still in a dirty state we must verify
      CHECK_CALL_GOTO (e, protocol_error, scInitDirty (lpView, &dirty));
#endif
      if ( !dirty )
          return ERRNUM_SUCCESS;
   }

   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS && verifying && VIEW_OP (lpv, OPEN)==VIEW_OP_VERIFY ) {
      // Only propagate verification if scInitVerify really was called
      MaxError (&e, viewVerify (lpv->subCmp.rvh, lpv->subCmp.view));
      if ( ERRNUM_IS_FAILURE (e) )
         errors = TRUE;
   }

   if ( lpv->bUnvalidated )
      return ERRNUM_SUCCESS;
   lpv->bVerifying = TRUE; // Done this way in spite of verifying parameter,
                           // in order to retain compatibility with old stuff
   for (nFld = 0; nFld < FLD_IDX_COUNT; nFld++) {
      lField = * FindFieldIndexV (lpv, nFld);
      f = FindFieldDefV (lpv, lField);
      attribs = AttribGet (lpv, lField);
      VALIDATE (ERRNUM_IS_SUCCESS (lpv->eValidation));
      if ( !(attribs & ATTR_ENABLED) || (attribs & ATTR_NULL) )
         continue;
#if defined(DO_LAZYVERIFY)
      if ( !(verifying || (attribs & ATTR_CHANGED)) )
         continue;
#endif
      data = FindFieldValue (lpv, lField);
      p = FindPresentsInfo (lpv, lField);
      VALIDATE (ERRNUM_IS_SUCCESS (lpv->eValidation));
      if ( p!=NULL )
         switch ( p->type ) {
            case PRESENTS_MASK:
               if ( !ApplyMask(lpv, lField, p, data, f->wLength) ) {
                  LOG_INVALID_FIELD(f);
                  ReportMaskError (lpv, lField);
                  errors = TRUE;
               }
               break;
            case PRESENTS_LIST:
            case PRESENTS_LIST_INLINE:
               if ( !FindFieldMapV (lpv, lField)->validate ) {
                  VALIDATE (ValidateList (lpv, p, lField, data));
               }
               break;
            default:
               break;
         }
      if ( attribs & ATTR_CHANGED ) {
         VALIDATE (ValidateData (lpv, lField, data));
      }
      VALIDATE (ValidateField (lpv, lField, data));
   }

   f = NULL;
   VALIDATE (ValidateKeys (lpv, verifying));
   VALIDATE (ValidateFieldDependencies (lpv)==0);

protocol_error:
   lpv->bVerifying = FALSE;
   if ( errors ) {
      MaxError (&e, ERRNUM_RECORD_INVALID);
   } else {
      lpv->bVerified = TRUE;
   }
   return e;

#undef VALIDATE
}



//////////////////////////////////////////////////////////////////////////////
// Various helper functions



VIEWBASE AcquireOneView (LPV lpv, INT c)
{
   LPKEYMAP k = NULL;
   LPVIEWDEF v = NULL;
   ERRNUM e = ERRNUM_SUCCESS;
   WORD link;
   LPCMPNAME d = FindCmpDef (c);
   A4W_FLAGS flags = 0L;
   LPSTR rotoID = FindCmpName (c);
   CHAR version [SIZEOF_VERSION];
   BCDDATE date;
   VIEWLOADSTRUCT vls;

   if ( DMND_CMP_COUNT+IMP_CMP_COUNT+MAN_CMP_COUNT==0 )
      return e;
   if ( NULL==d ) // Means DO_CMPNAMESTRUCT is not defined,
      return e;   // hence acquire won't ever be requested

   VIEWASSERT(c>=HDR_CMP_COUNT+DTL_CMP_COUNT+HCHY_CMP_COUNT);
   if ( c<HDR_CMP_COUNT+DTL_CMP_COUNT+HCHY_CMP_COUNT )
      return e;
   VIEWASSERT(c<CMP_COUNT+MAN_CMP_COUNT);
   if ( c>=CMP_COUNT+MAN_CMP_COUNT )
      return e;

   v = FindCmp (lpv, c);
   if ( v->view!=NULL )
      return e;

   ibGetRoto (lpv->hpib, &vls.iRotoInstance);
   vls.iTag = 1;
   strCopyBZ (vls.sPgmID, sizeof (vls.sPgmID), APPL);
   utlObjStrToID (FindCmpName (c), &vls.lViewID);

   // Collect parameters
   link = lpv->wLinkNo;
   if ( DMND_CMP_COUNT+IMP_CMP_COUNT>0 )
      k = FindKeyMap (c);
   if ( lpv->bInherits ) {
      flags = lpv->OpenFlags;
      flags &= ~MASK_INSTANCE_OPEN_INHERIT;
      flags &= ~MASK_INSTANCE_OPEN_PREFETCH;
   }
   flags |= d->flags;
   if ( (d!=NULL && d->system) || (k!=NULL && k->system) )
   {
      if ( ORG_TYPE_COMBINED == lpv->wOrgType )
         link = ibGetCmpLinkNo(lpv->hpib);
      else
         link = ibGetSysLinkNo(lpv->hpib);
   }

   MaxError (&e, viewAcquire (&vls, lpv->hpib, link, flags, &v->rvh, &v->view));
   if ( ERRNUM_IS_FAILURE (e) ) {
      v->rvh  = NULL;
      v->view = NULL;
   }
   *FindImpOpen (lpv, c) = TRUE;
   if ( d->options & CMPNAME_OPTION_NOTIFY ) {
      CHECK_CALL (e, viewInstanceNotify ((LPRVH) v->rvh, v->view, CompositeNotifyEntry,
                                         FindCmpNotify (lpv, c), INSTANCE_NOTIFY_ADD));
   }
   return e;
}



void WINAPI AddDeltaBCD (LPDBFIELD field, LPDATUM to, LPDATUM by)
{
   bcdAdd (to->n, field->wLength, field->wDecimals,
           by->n, field->wLength, field->wDecimals);
}

void WINAPI AddDeltaByte (LPDBFIELD field, LPDATUM to, LPDATUM by)
{
   if ( field->wLength==1 )
      to->b[0] += by->b[0];
   else
      AddDeltaString (field, to, by);
}

void WINAPI AddDeltaInteger (LPDBFIELD field, LPDATUM to, LPDATUM by)
{
   to->i += by->i;
}

void WINAPI AddDeltaLong (LPDBFIELD field, LPDATUM to, LPDATUM by)
{
   to->l += by->l;
}

void WINAPI AddDeltaReal (LPDBFIELD field, LPDATUM to, LPDATUM by)
{
   to->r += by->r;
}

void WINAPI AddDeltaString (LPDBFIELD field, LPDATUM to, LPDATUM by)
{
   INT i, carry = 0;

   for ( i=field->wLength; i--; ) {
      INT sum = carry + (to->s[i]-'0') + (by->s[i]-'0');

      if ( sum<10 )
         carry = 0;
      else {
         carry = 1;
         sum -= 10;
      }
      to->s[i] = (CHAR) (sum+'0');
   }
}



#if defined(DO_HEADERETC)

VIEWBASE ApplyHeaderDelta (LPV lpv, LONG target, INT op, LONG source,
                           LPDATUM old, LPDATUM New, LPTYPEOPERATIONS operation)
{
   LPDBFIELD field = FindFieldDefV (lpv, source);
   LPDATUM delta;
   LPVIEWDEF v = FindCmp (lpv, 0);
   ERRNUM e = 0;

   delta = (LPDATUM) _alloca (field->wLength);
   if ( delta==NULL ) {
      ReportMemoryError (lpv, MAKE_OP_RSC (VIEW_OP (lpv, OPEN)));
      return ERRNUM_MEMORY_NO_MORE;
   }
   if ( !operation )
      operation = aTypeOperations [field->wType];
   VIEWASSERT (operation!=NULL);
   InitFieldBuffer (delta, field->wType, field->wLength);
   if ( op==VIEW_OP_DELETE || op==VIEW_OP_UPDATE )
      (* operation->subtract) (field, delta, old);
   if ( op==VIEW_OP_INSERT || op==VIEW_OP_UPDATE )
      (* operation->add) (field, delta, New);
   // Alter the header's field, only if it needs to change
   if ( !(* operation->iszero) (field, delta) ) {
      LPDATUM result;

      result = (LPDATUM) _alloca (field->wLength);
      if ( result==NULL ) {
         ReportMemoryError (lpv, MAKE_OP_RSC (VIEW_OP (lpv, OPEN)));
         return ERRNUM_MEMORY_NO_MORE;
      }
      MaxError (&e, viewGet (v->rvh, v->view, target, result, field->wLength));
      if ( ERRNUM_IS_SUCCESS (e) ) {
         (* operation->add) (field, result, delta);
         MaxError (&e, viewPut (v->rvh, v->view, target, result, field->wLength, TRUE));
      }
   }
   return e;
}



VIEWBASE ApplyHeaderFieldsBase (LPV lpv, INT op)
{
   INT i;
   ERRNUM e = ERRNUM_SUCCESS;
   LPVIEWDEF v = FindCmp (lpv, 0);
   LPSTR save = lpv->detailSave;

   if ( save==NULL )
      return e;
   for ( i=0; i<DO_HEADERETC; i++ ) {
      LPDETAILMAP map = &(FindDetailMap ()) [i];
      LONG field = map->lDetail;

      if ( !(lpv->alAttributes[IDXIDX(field)] & ATTR_NULL) ) {
         RVSPYPRINT( ("Summating %10.10s", FindFieldDefV (lpv, field)->sName) );
         CHECK_CALL_GOTO (e, error,
            ErrorMapViewToExtended (op,
               HeaderEtc (lpv, map->lHeader, op, field, save,
                          FindFieldValue (lpv, field))));
      }
      save += FindFieldDefV (lpv, field)->wLength;
   }
 #if defined(BATCH_VIEW) && !defined(DETAIL_VIEW)
   MaxError (&e, viewUpdate (v->rvh, v->view));
 #endif
   return e;

error:
   switch ( op ) {
      case VIEW_OP_INSERT:
         op = VIEW_OP_DELETE;
         break;
      case VIEW_OP_DELETE:
         op = VIEW_OP_INSERT;
         break;
      default:
         break;
   }
   while ( i-- ) {
      LPDETAILMAP map = &(FindDetailMap ()) [i];
      LONG field = map->lDetail;
      LPDBFIELD f = FindFieldDefV (lpv, field);

      save -= f->wLength;
      if ( !(lpv->alAttributes[IDXIDX(field)] & ATTR_NULL) ) {
         RVSPYPRINT( ("Reversing summation of %10.10s", f->sName) );
         HeaderEtc (lpv, map->lHeader, op, field,
                    FindFieldValue (lpv, field), save);
      }
   }
   return e;
}

#endif



// Returns TRUE if able to apply the mask, FALSE otherwise
BOOL ApplyMask (LPV lpv, LONG lField, LPPRESENTATION p, LPSTR data, WORD wLength)
{
   CHAR mask [MAX_FIELD_LENGTH];
   LPSTR temp;
   WORD result;

   temp = (LPSTR) _alloca (wLength+1);
   if ( !temp ) {
      ReportMemoryError (lpv, MAKE_OP_RSC (VIEW_OP (lpv, OPEN)));
      MaxError (&lpv->eValidation, ERRNUM_MEMORY_NO_MORE);
      return FALSE;
   }
   LoadMask (lpv->hpib, p->mask, MAX_FIELD_LENGTH, mask);
   VIEWASSERT (mask[0]!=0);
   if ( 0==mask[0] )
      return TRUE;
   result = mskFormat (mask, data, temp, wLength);
   if ( result & MFF_BADCHAR )
      return FALSE;
   if ( result!=MFF_GOOD )
      blkCopy (data, temp, wLength);
   return TRUE;
}



VIEWBASE AutoCancel (LPV lpv, LONG field)
{
   ERRNUM e = ERRNUM_SUCCESS;
   BOOL set = FALSE;

   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS )
      return e;
   if ( HDR_CMP_COUNT==0 )
      return e;
   set = AttribTest (lpv, field, ATTR_KEY);
   CHECK_CALL (e, lpv->eValidation);
   if ( set && FindCmp (lpv, 0)->view && DetailKeyWithinHeader (lpv) ) {
      CHECK_CALL (e, ErrorMapViewToExtended (VIEW_OP (lpv, OPEN),
                                             AutoCancelBody (lpv, field)));
   }
   return e;
}



#if !defined(DO_AUTOCANCELBODY)

VIEWBASE AutoCancelBody (LPV lpv, LONG field)
{
   ERRNUM e = ERRNUM_SUCCESS;
   INT i;
   LPKEYMAP k;

   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS )
      return e;
   if ( HDR_CMP_COUNT==0 )
      return e;

   k = FindKeyDef (0);
   for ( i=k->segments-DTL_SEG_COUNT; i--; )
      if ( k->indexes[i]==field )
         goto cancel_revisions;
   return e;

cancel_revisions:
   if ( HAS_REVISIONS!=NO_REVISIONS && lpv->bRevisioned ) {
      RevisionSpyLevels (lpv);
      CHECK_CALL (e, ErrorMapDatabaseToExtended (
         lpv->wLinkNo, RevisionInnerCancel (lpv, 1+HDR_HAS_REVISIONS, NULL)));
      CHECK_CALL (e, ErrorMapDatabaseToExtended (
         lpv->wLinkNo, RevisionInnerCreate (lpv, 1+HDR_HAS_REVISIONS)));
      RevisionSpyLevels (lpv);
      lpv->bUnpostedRevisions = FALSE;
      if ( HDR_HAS_REVISIONS==0 ) {
         CHECK_CALL (e, MapToDetails (lpv, VIEW_OP_CANCEL));
      } else {
         CHECK_CALL (e, MapToDetails (lpv, VIEW_OP_REVISION_CANCEL, 1+HDR_HAS_REVISIONS));
      }
      CHECK_CALL (e, BaseNotifyFire (
         lpv, INSTANCE_NOTIFY_REVISION_CANCELLED, 1+HDR_HAS_REVISIONS, (LPVOID) TRUE));
   }

   CHECK_CALL (e, InitBodyGen (lpv, INITBODYGEN_NOINSERT |
                                    INITBODYGEN_NOGENERATE |
                                    INITBODYGEN_NOTOPEN));
   return e;
}

#endif



VIEWBASE BaseBrowse (LPV lpv, BOOL bSelectFromStart)
{
   ERRNUM e = ERRNUM_SUCCESS;
   LPVIEWDEF base;
   BOOL SupportsFilterSelect = FALSE;

   if ( SUBCLASS_LEVEL==NOT_SUBCLASS )
      return e;

   base = &lpv->subCmp;
   if ( blkCompare (lpv->subVersionTemplate, "50A", SIZEOF_VERSION)<0 ) {
      MaxError (&e, viewBrowse (base->rvh, base->view, lpv->subFilter, lpv->bAhead));
   } else {
      A4W_FLAGS flags = 0L;

      if ( lpv->bAhead )
         flags |= FILTER_SELECT_ASCENDING;
      if ( !bSelectFromStart )
         flags |= FILTER_SELECT_FROMHERE;
      MaxError (&e, viewFilterSelect ((LPRVH) base->rvh, base->view,
                                      lpv->wKey, lpv->subFilter, flags));
   }
   return e;
}



void WINAPI BaseClose (LPV lpv)
{
   if ( SUBCLASS_LEVEL==NOT_SUBCLASS )
      return;

   viewClose (lpv->subCmp.rvh, lpv->subCmp.view);
   lpv->subCmp.view = NULL;
   BaseUnload (&lpv->subCmp);
}



DB_ERRNUM WINAPI BaseFetch (LPV lpv, BOOL bLock, BOOL bSelectFromStart)
{
   ERRNUM e = ERRNUM_SUCCESS;
   LPVIEWDEF base;
   INT op = VIEW_OP_OPEN;

   if ( SUBCLASS_LEVEL==NOT_SUBCLASS )
      return e;

   base = &lpv->subCmp;
   if ( bSelectFromStart && blkCompare (lpv->subVersionTemplate, "50A", SIZEOF_VERSION)>=0 ) {
      A4W_FLAGS flags = 0L;

      if ( bLock )
         flags |= FILTER_FETCH_LOCK;
      op = VIEW_OP_FILTER_FETCH;
      MaxError (&e, viewFilterFetch ((LPRVH) base->rvh, base->view, flags));
   } else {
      if ( bSelectFromStart ) {
         // ???????????????????????????????????????????????????????????????????
         // Might the following code be a problem with views that auto-generate
         op = VIEW_OP_INITIALIZE;
         MaxError (&e, viewInit (base->rvh, base->view));
      }
      if ( ERRNUM_IS_SUCCESS (e) ) {
         if ( bLock ) {
            op = VIEW_OP_FETCH_LOCK;
            MaxError (&e, viewFetchLock (base->rvh, base->view));
         } else {
            op = VIEW_OP_FETCH;
            MaxError (&e, viewFetch (base->rvh, base->view));
         }
      }
   }

   if ( ERRNUM_IS_FAILURE (e) )
      return ErrorMapViewToDatabase (op, e);
   MaxError (&e, BaseGetData (lpv));
   return ErrorMapViewToDatabase (VIEW_OP_GET, e);
}



VIEWBASE BaseGetData (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;

   if ( SUBCLASS_LEVEL==NOT_SUBCLASS )
      return e;
   if ( BASE_TBL_COUNT==0 )
      return e;

   CHECK_CALL (e, viewGet (lpv->subCmp.rvh, lpv->subCmp.view, FILLER_IDX,
                           (FindRecord (lpv)) [0], FindTableWidth (lpv, 0)));
   return e;
}



VIEWBASE BaseGetKey (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;

   if ( SUBCLASS_LEVEL==JOIN_SUBCLASS ) {
      INT i, size;
      LPSTR record = (FindRecord (lpv)) [BASE_TBL_COUNT];
      LPDBFIELD f = FindTableMapV (lpv, BASE_TBL_COUNT)->fields;
      LPVIEWDEF base = &lpv->subCmp;
      LPCMPKEY x = &lpv->subCmpKey;
      INT length = 0;

      for ( i=0; i<x->segments; ++i ) {
         size = f[i].wLength;
         CHECK_CALL (e, viewGet (base->rvh, base->view,
                                 x->indexes[i], record+length, size));
         length += size;
      }
      for ( i=BASE_TBL_COUNT+1; i<BASE_TBL_COUNT+TBL_COUNT; ++i )
         blkCopy ((FindRecord (lpv)) [i], record, length);
   }
   return e;
}



VIEWBASE BaseGetPermissions (HPIB hpib, WORD wLinkNo, LPLONG permissions)
{
   ERRNUM e = ERRNUM_SUCCESS;
   VIEWDEF base;

   if ( SUBCLASS_LEVEL==NOT_SUBCLASS )
      return e;

   if ( (base.rvh = BaseLoad (BaseRoto (hpib)))==NULL ) {
      ReportBaseLoadError (hpib, subCmpName);
      return ERRNUM_LOAD_FAILED;
   }
   e = viewSecurity (base.rvh, hpib, wLinkNo, (LPLONG) permissions);
   BaseUnload (&base);
   return e;
}



LPVOID WINAPI BaseLoad (INT roto)
{
   VIEWLOADSTRUCT vls;

   if ( SUBCLASS_LEVEL==NOT_SUBCLASS )
      return NULL;

   vls.iTag = 1;
   vls.iRotoInstance = roto;
   strCopyBZ (vls.sPgmID, sizeof (vls.sPgmID), APPL);
   utlObjStrToID (subCmpName, &vls.lViewID);
   return viewLoadEx (&vls);
}



VIEWCALL BaseNotifyBase (
   LPVOID context,
   LONG reason,
   LONG rotoID,
   LONG info,
   LPVOID extra,
   LPRVH rvh,
   LPVOID view)
{
   ERRNUM e = ERRNUM_SUCCESS;

   switch ( reason ) {
      case INSTANCE_NOTIFY_INSTANCE_CLOSING:
         // Don't propagate this, because we don't know who our caller is,
         // or in what state
         break;

      default: {
         LPNOTIFYCONTEXT n = (LPNOTIFYCONTEXT) context;
         LPV lpv = n->lpv;

         MaxError (&e, (*n->notify) (n->context, reason, lpv->rotoID,
                                     info, extra, lpv->myself, lpv->myself));
         break;
      }
   }
   return e;
}



VIEWBASE BaseOpen (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;
   LPVIEWDEF base;
   BCDDATE date;

   if ( SUBCLASS_LEVEL==NOT_SUBCLASS )
      return e;

   base = &lpv->subCmp;
   if ( base->rvh = BaseLoad (BaseRoto (lpv->hpib)) ) {
      MaxError (&e, GetTemplateVersion (lpv, subCmpName, base, lpv->subVersionTemplate, date));
      lpv->subDateTemplate = bcdToINT32 (date, sizeof (date), NULL);
      if ( ERRNUM_IS_SUCCESS (e) ) {
         if ( blkCompare (lpv->subVersionTemplate, "42A", SIZEOF_VERSION)<0 ) {
            MaxError (&e, viewOpen (base->rvh, lpv->hpib, lpv->wLinkNo, &base->view));
         } else {
            MaxError (&e, viewInstanceOpen ((LPRVH) base->rvh, lpv->hpib, lpv->wLinkNo, lpv->OpenFlags,
                                            lpv->OpenExtra, lpv->OpenExtraSize, &base->view));
         }
         if ( ERRNUM_IS_SUCCESS (e) )
            return e;
      }
      BaseUnload (base);
   } else {
      ReportBaseLoadError (lpv->hpib, subCmpName);
      e = ERRNUM_LOAD_FAILED;
   }
   return e;
}



VIEWBASE BasePutData (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;

   if ( SUBCLASS_LEVEL==NOT_SUBCLASS )
      return e;
   if ( BASE_TBL_COUNT==0 )
      return e;

   CHECK_CALL (e, viewPut (lpv->subCmp.rvh, lpv->subCmp.view, FILLER_IDX,
                           (FindRecord (lpv)) [0], FindTableWidth (lpv, 0), FALSE));
   return e;
}



VIEWBASE BasePutKey (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;

   if ( SUBCLASS_LEVEL==JOIN_SUBCLASS ) {
      INT i, size;
      LPSTR record = (FindRecord (lpv)) [BASE_TBL_COUNT];
      LPDBFIELD f = FindTableMapV (lpv, BASE_TBL_COUNT)->fields;
      LPVIEWDEF base = &lpv->subCmp;
      LPCMPKEY x = &lpv->subCmpKey;

      for ( i=0; i<x->segments; ++i ) {
         size = f[i].wLength;
         CHECK_CALL (e, viewPut (base->rvh, base->view,
                                 x->indexes[i], record, size, FALSE));
         record += size;
      }
   }
   return e;
}



INT WINAPI BaseRoto (HPIB hpib)
{
   INT roto;

   ibGetRoto (hpib, &roto);
   return roto;
}



VIEWBASE BaseRotoEntry (LPROTOVIEW v, INT length)
{
   if ( SUBCLASS_LEVEL==NOT_SUBCLASS ) {
      if ( v->view )
         ReportRotoError ((LPV) v->view, v->op);
      return ERRNUM_ROTOENTRY_FAILED;
   } else {
      LPVIEWDEF base = & ((LPV) v->view)->subCmp;

      return viewCallParam (base->rvh, v->op, base->view,
                            v->i, v->flag, v->field, v->p, v->q, v->r, v->s,
                            (length-sizeof (ROTOVIEW)), v+1);
   }
}



void WINAPI BaseUnload (LPVIEWDEF base)
{
   if ( SUBCLASS_LEVEL==NOT_SUBCLASS )
      return;

   viewUnload (base->rvh);
   base->rvh = NULL;
}



INT WINAPI BinaryComparator (LPDBFIELD field, LPDATUM d1, LPDATUM d2)
{
   return blkCompare (d1->b, d2->b, field->wLength);
}



BOOL BinarySearch (
   const void *key,
   const void * array,
   const INT count,
   const INT size,
   PINT insertion)
{
   BOOL found = FALSE;
   INT lo = 0;
   INT hi = count;
   INT mid = (lo + hi) / 2;

   while ( lo<hi ) {
      int result = blkCompare (key, (char *)array + size*mid, size);

      if ( result==0 ) {
         found = TRUE;
         break;
      }
      if ( result>0 )
         lo = mid+1;
      else
         hi = mid;
      mid = (lo + hi) / 2;
   }
   *insertion = mid;
   return found;
}



VIEWBASE BrowseBody (LPV lpv, LPSTR expression, BOOL ascending)
{
   ERRNUM e = ERRNUM_SUCCESS;
   FL_ERRNUM f = FL_SUCCESS;
   WORD op;

   lpv->bBrowsing = FALSE;
   lpv->bBrowseEnded = TRUE;
   lpv->bBrowseInSync = FALSE;
   lpv->bAhead = ascending;
   if ( expression==NULL )
      expression = "";

   op = FILTER_OP_PARSE;
   f = filterParse (lpv, expression, &lpv->filter, (FILTERFIELD) scInitField,
                    (FILTERFIELDS) scInitFields, (FILTERTYPE) scInitType);
   CHECK_CALL (e, ErrorMapFilterToExtended (op, filterErrorV (lpv, op, f)));

   op = FILTER_OP_GET_RANGES;
   f = filterGetRanges (lpv, &lpv->filter, lpv->wKey, xxxKey);
   CHECK_CALL (e, ErrorMapFilterToExtended (op, filterErrorV (lpv, op, f)));

   return ERRNUM_SUCCESS;
}



VIEWBASE CancelBodyBase (LPV lpv, INT level)
{
   ERRNUM e = ERRNUM_SUCCESS;

   if ( SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS ) {
      int l1 = level - 1;

      CHECK_CALL (e, ErrorMapDatabaseToExtended (lpv->wLinkNo,
                                                 RevisionInnerCancel (lpv, level, NULL)));
      CHECK_CALL (e, PullHeaderKey (lpv));
      if ( level>HDR_HAS_REVISIONS || l1<1 )
         l1 = level;
      CHECK_CALL (e, ErrorMapDatabaseToExtended (lpv->wLinkNo,
                                                 RevisionInnerCreate (lpv, l1)));
      lpv->bUnpostedRevisions = FALSE;
      if ( HDR_HAS_REVISIONS==0 || level==1 ) {
         CHECK_CALL (e, MapToDetails (lpv, VIEW_OP_CANCEL));
      } else {
         CHECK_CALL (e, MapToDetails (lpv, VIEW_OP_REVISION_CANCEL, level));
      }
      CHECK_CALL (e, BaseNotifyFire (
         lpv, INSTANCE_NOTIFY_REVISION_CANCELLED, level, (LPVOID) TRUE));
   }
   CHECK_CALL (e, InitBodyGen (lpv, INITBODYGEN_NOINSERT |
                                    INITBODYGEN_NOGENERATE |
                                    INITBODYGEN_NOTOPEN));
   return e;
}



ERRNUM ClearAttribs (LPV lpv, LONG attribs)
{
   INT field;
   ERRNUM e = ERRNUM_SUCCESS;

   for ( field=0; field<FLD_IDX_COUNT; ++field ) {
      AttribClear (lpv, * FindFieldIndexV (lpv, field), attribs);
      CHECK_CALL (e, lpv->eValidation);
   }
   return e;
}



VIEWBASE ClearChange (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;

   lpv->bDirty = FALSE;
   CHECK_CALL (e, ClearAttribs (lpv, ATTR_CHANGED));
   return e;
}



void WINAPI CloseImpViews (
   LPV lpv)
{
   INT nCmp;

   if ( DMND_CMP_COUNT+IMP_CMP_COUNT+MAN_CMP_COUNT>0 ) {
      for (nCmp = EXP_CMP_COUNT-DMND_CMP_COUNT; nCmp < CMP_COUNT+MAN_CMP_COUNT; nCmp++)
         CloseOneView (lpv, nCmp);
   }
}



void WINAPI CloseOneView (LPV lpv, INT c)
{
   LPVIEWDEF v = FindCmp (lpv, c);

   if ( DMND_CMP_COUNT+IMP_CMP_COUNT+MAN_CMP_COUNT==0 )
      return;

   VIEWASSERT(c>=EXP_CMP_COUNT-DMND_CMP_COUNT);
   if ( c<EXP_CMP_COUNT-DMND_CMP_COUNT )
      return;
   VIEWASSERT(c<CMP_COUNT+MAN_CMP_COUNT);
   if ( c>=CMP_COUNT+MAN_CMP_COUNT )
      return;

   if ( * FindImpOpen (lpv, c) ) {
      LPCMPNAME d = FindCmpDef (c);

      if ( d!=NULL ) {
         if ( d->options & CMPNAME_OPTION_VIEWPOOL ) {
            ReleaseOneView (lpv, c); // Will remove any notification
            return;
         }
         if ( d->options & CMPNAME_OPTION_NOTIFY ) {
            viewInstanceNotify ((LPRVH) v->rvh, v->view, CompositeNotifyEntry,
                                FindCmpNotify (lpv, c), INSTANCE_NOTIFY_REMOVE);
         }
      }
      viewClose (v->rvh, v->view);
      v->view = NULL;
      * FindImpOpen (lpv, c) = FALSE;
   }
   if ( v->rvh && !v->view )
      UnloadOneView (lpv, c);
}



INT WINAPI ComparePrimary (LPV lpv, LPSTR FAR * record)
{
   LPKEYMAP k = FindKeyDef (0);
   INT i;
   INT comparison = 0;

   if ( KEY_COUNT==0 || SUBCLASS_LEVEL!=NOT_SUBCLASS )
      return 1;

   for ( i=0; i<k->segments; ++i ) {
      LONG field = k->indexes [i];
      LPDBFIELD f = FindFieldDefV (lpv, field);
      LPDATUM left = (LPDATUM) FindFieldValue (lpv, field);
      LPDATUM right = (LPDATUM) FindFieldValueAux (lpv, field, record);
      FIELDCOMPARATOR comparator = aTypeComparators [f->wType];

      VIEWASSERT (comparator!=NULL);
      comparison = (* comparator) (f, left, right);
      if ( comparison!=0 )
         return comparison;
   }
   return 0;
}



VIEWBASE ComposeDemand (LPV lpv, INT c, LPVIEWDEF composite)
{
   ERRNUM e = ERRNUM_SUCCESS;

   if ( DMND_CMP_COUNT==0 )
      return e;
   VIEWASSERT (CompositeCategory (lpv, c)==DEMAND_COMPOSITE);
   if ( composite->rvh==NULL )
      return ERRNUM_SUCCESS;
   CloseOneView (lpv, c);
   CHECK_CALL (e, ComposeHierarchical (lpv, c, composite));
   return e;
}



VIEWBASE ComposeDetail (LPV lpv, INT c, LPVIEWDEF composite)
{
   ERRNUM e = ERRNUM_SUCCESS;
   LPVIEWDEF v;
   CHAR name [SIZEOF_FLDDESC];
   LPCMPKEY x;
   LPKEYMAP k;
   INT segment;
   LPCMPNAME d;

   VIEWASSERT (CompositeCategory (lpv, c)==DETAIL_COMPOSITE);
   if ( DTL_CMP_COUNT==0 )
      return e;

   v = FindCmp (lpv, c);
   x = FindCmpKey (lpv, c);
   k = FindKeyDef (0);
   d = FindCmpDef (c);

   // Remove the old notification if necessary
   if ( d && (d->options & CMPNAME_OPTION_NOTIFY) && v->view!=NULL ) {
      CHECK_CALL (e, viewInstanceNotify ((LPRVH) v->rvh, v->view, CompositeNotifyEntry,
                                         FindCmpNotify (lpv, c), INSTANCE_NOTIFY_REMOVE));
   }

   *v = *composite;
   if ( v->view==NULL )
      return ERRNUM_SUCCESS;

   if ( SUBCLASS_LEVEL==NOT_SUBCLASS ) {
      CHECK_CALL (e, GenericStub (lpv, c, FindGenStub (lpv, c)));
      if ( * FindGenStub (lpv, c) )
         return e;
      if ( k->segments==0 )
         return e;

      CHECK_CALL (e, viewKey (v->rvh, v->view, k->foreign,
                              name, &x->segments, x->indexes));
      if ( x->segments <= k->segments ) {
         ReportCompositeKeyError (lpv, MAKE_OP_RSC(VIEW_OP_COMPOSE), FindCmpName (c));
         return ERRNUM_COMPOSE_FAILED;
      }
      CHECK_CALL (e, QueryKeyTypes (v, x));
      for (segment = k->segments; segment--; )
         * FindCmpField (lpv, c, k->indexes[segment]) = x->indexes[segment];

      // Register a notification to the stock composite callback function
      if ( d && (d->options & CMPNAME_OPTION_NOTIFY) ) {
         CHECK_CALL (e, viewInstanceNotify ((LPRVH) v->rvh, v->view, CompositeNotifyEntry,
                                            FindCmpNotify (lpv, c), INSTANCE_NOTIFY_ADD));
      }
   }
   return e;
}



VIEWBASE ComposeHeader (LPV lpv, LPVIEWDEF composite)
{
   ERRNUM e = ERRNUM_SUCCESS;
   LPVIEWDEF v;
   CHAR name [SIZEOF_FLDDESC];
   LPCMPKEY x;
   INT i = 0;
   INT segment = 0;
#if defined(DO_HEADERETC)
   INT size;
#endif
   LPCMPNAME d;

   VIEWASSERT (CompositeCategory (lpv, 0)==HEADER_COMPOSITE);
   if ( HDR_CMP_COUNT==0 )
      return e;

   v = FindCmp (lpv, 0);
   d = FindCmpDef (0);

   // Remove the old notification if necessary
   if ( v->view!=NULL &&
        (HDR_HAS_REVISIONS>0 || (d && (d->options & CMPNAME_OPTION_NOTIFY))) ) {
      CHECK_CALL (e, viewInstanceNotify ((LPRVH) v->rvh, v->view, CompositeNotifyEntry,
                                         FindCmpNotify (lpv, 0), INSTANCE_NOTIFY_REMOVE));
   }

   *v = *composite;
   if ( !v->view || !DetailKeyWithinHeader (lpv) )
      return ERRNUM_SUCCESS;
   CHECK_CALL (e, ErrorMapDatabaseToExtended (
      lpv->wLinkNo, RevisionOuterSegments (lpv)));

   if ( SUBCLASS_LEVEL==NOT_SUBCLASS ) {
      LPKEYMAP k = FindKeyDef (0);

      x = FindCmpKey (lpv, 0);
      CHECK_CALL (e, viewKey (v->rvh, v->view, k->foreign,
                              name, &x->segments, x->indexes));

      if ( x->segments >= k->segments ) {
         ReportCompositeKeyError (lpv, MAKE_OP_RSC(VIEW_OP_COMPOSE), FindCmpName (0));
         return ERRNUM_COMPOSE_FAILED;
      }
      CHECK_CALL (e, QueryKeyTypes (v, x));

      if ( HDR_HAS_REVISIONS>0 || (d && (d->options & CMPNAME_OPTION_NOTIFY)) ) {
         // Register a notification to the stock composite callback function
         CHECK_CALL (e, viewInstanceNotify ((LPRVH) v->rvh, v->view, CompositeNotifyEntry,
                                            FindCmpNotify (lpv, 0), INSTANCE_NOTIFY_ADD));
      }

      if ( HDR_HAS_REVISIONS>=2 ) {
         A4W_SIZE count;
         A4W_FLAGS protocols[MAX_SEGMENTS_PER_KEY];
         LPREVLEVEL revLevel = FindRevLevel (lpv, HDR_HAS_REVISIONS);

         CHECK_CALL (e,
            viewInstanceProtocol ((LPRVH) v->rvh, v->view,
                                  INSTANCE_PROTOCOL_HEADERS_TOO, protocols, &count));
         // This loop assumes that the members at FindRevLevel (lpv, HDR_HAS_REVISIONS)
         // have all been setup in OpenBody()
         for ( i=1; i<=HDR_HAS_REVISIONS-1; ++i ) {
            --revLevel;
            revLevel->DetailKeySegments = protocols[count-i] & MASK_INSTANCE_PROTOCOL_SEGMENTS_ADDED;
            revLevel->HeaderKeySegments = revLevel[1].HeaderKeySegments - revLevel->DetailKeySegments;
         }

// Don't know what to do about this at present, since the protocol member
// won't get setup when HDR_HAS_REVISIONS==1
//         revLevel = FindRevLevel (lpv, 1);
//         for ( i=HDR_HAS_REVISIONS; i>=1; --i ) {
//            revLevel->protocol = protocols[count-i];
//            ++revLevel;
//         }

         revLevel = FindRevLevel (lpv, 1);
         revLevel->iHdrPKeySize = 0;
         segment = 0;
         for ( i=1; i<=HDR_HAS_REVISIONS; ++i ) {
            if ( segment>0 )
               revLevel->iHdrPKeySize = revLevel[-1].iHdrPKeySize;
            while ( segment<revLevel->HeaderKeySegments ) {
               revLevel->iHdrPKeySize += FindFieldDefV (lpv, k->indexes[segment])->wLength;
               ++segment;
            }
            ++revLevel;
         }
      }
   }

#if defined(DO_HEADERETC)
   for ( size=segment=0; segment<DO_HEADERETC; segment++ )
      size += FindFieldDefV (lpv, (FindDetailMap ()) [segment].lDetail)->wLength;
   if ( lpv->detailSave!=NULL )
      memFree (lpv->detailSave);
   lpv->detailSave = (LPSTR) memAlloc (size);
   if ( lpv->detailSave==NULL ) {
      ReportMemoryError (lpv, MAKE_OP_RSC(VIEW_OP_COMPOSE));
      return ERRNUM_MEMORY_NO_MORE;
   }
#endif
   return e;
}



VIEWBASE ComposeHierarchical (LPV lpv, INT c, LPVIEWDEF composite)
{
   ERRNUM e = ERRNUM_SUCCESS;
   LPVIEWDEF v;
   CHAR name [SIZEOF_FLDDESC];
   LPCMPKEY x;
   LPKEYMAP k;
   LPCMPNAME d;
   INT i, segment, key;

   VIEWASSERT (CompositeCategory (lpv, c)==HIERARCHICAL_COMPOSITE ||
               CompositeCategory (lpv, c)==DEMAND_COMPOSITE);
   if ( HCHY_CMP_COUNT+DMND_CMP_COUNT==0 )
      return e;

   v = FindCmp (lpv, c);
   x = FindCmpKey (lpv, c);
   k = FindKeyMap (c);
   d = FindCmpDef (c);

   // Remove the old notification if necessary
   if ( d && (d->options & CMPNAME_OPTION_NOTIFY) && v->view!=NULL ) {
      CHECK_CALL (e, viewInstanceNotify ((LPRVH) v->rvh, v->view, CompositeNotifyEntry,
                                         FindCmpNotify (lpv, c), INSTANCE_NOTIFY_REMOVE));
   }

   *v = *composite;
   if ( v->view==NULL )
      return ERRNUM_SUCCESS;
   CHECK_CALL (e, GenericStub (lpv, c, FindGenStub (lpv, c)));
   if ( * FindGenStub (lpv, c) )
      return ERRNUM_SUCCESS;

   // Register a notification to the stock composite callback function
   if ( d && (d->options & CMPNAME_OPTION_NOTIFY) ) {
      CHECK_CALL (e, viewInstanceNotify ((LPRVH) v->rvh, v->view, CompositeNotifyEntry,
                                         FindCmpNotify (lpv, c), INSTANCE_NOTIFY_ADD));
   }

   if ( k->segments==0 )
      return ERRNUM_SUCCESS;
   i = k->name;
   // extract the key from the newer CMPNAMESTRUCT, if used, else the older CMPKEY
   if ( d )
      key = d->foreign;
   else
      key = k->foreign;
   CHECK_CALL (e, viewKey (v->rvh, v->view, key, name, &x->segments, x->indexes));
   if ( x->segments!=k->segments ) {
      ReportCompositeKeyError (lpv, MAKE_OP_RSC(VIEW_OP_COMPOSE), FindCmpName (c));
      return ERRNUM_COMPOSE_FAILED;
   }

   CHECK_CALL (e, QueryKeyTypes (v, x));
   do {
      LONG field;

      for ( segment=x->segments; segment--; ) {
         field = k->indexes[segment];
         * FindCmpField (lpv, c, field) = x->indexes[segment];
         * FindCmpForeign (lpv, field) = 1;
      }
      k++;
   } while ( i-- );

   return e;
}



INT WINAPI CompositeCategory (LPV lpv, INT c)
{
   VIEWASSERT (c>=0);
   VIEWASSERT (c<CMP_COUNT+MAN_CMP_COUNT);
   if ( c<HDR_CMP_COUNT )
      return HEADER_COMPOSITE;
   if ( c<HDR_CMP_COUNT+DTL_CMP_COUNT )
      return DETAIL_COMPOSITE;
   if ( c<HDR_CMP_COUNT+DTL_CMP_COUNT+HCHY_CMP_COUNT )
      return HIERARCHICAL_COMPOSITE;
   if ( c<EXP_CMP_COUNT )
      return DEMAND_COMPOSITE;
   if ( c<CMP_COUNT )
      return IMPLICIT_COMPOSITE;
   if ( c<CMP_COUNT+MAN_CMP_COUNT )
      return MANUAL_COMPOSITE;
   return -1;
}



VIEWCALL CompositeNotifyBase (
   LPVOID context,
   LONG reason,
   LONG rotoID,
   LONG info,
   LPVOID extra,
   LPRVH rvh,
   LPVOID view)
{
#if !defined(DO_COMPOSITENOTIFY)
   RVSPYNOTIFY (((LPCMPNOTIFYCONTEXT) context)->lpv, "NOTIFIED", reason, info, extra, context);
#endif
   switch ( reason ) {
      //case INSTANCE_NOTIFY_REVISION_POSTED:
      case INSTANCE_NOTIFY_RECORD_WRITTEN:
      case INSTANCE_NOTIFY_RECORD_RETRIEVED:
         if ( HDR_HAS_REVISIONS>0 ) {
            LPCMPNOTIFYCONTEXT n = (LPCMPNOTIFYCONTEXT) context;
            ERRNUM e = ERRNUM_SUCCESS;

            if ( n->composite==0 ) {
               // Only attach if this came from the header
               RevisionSpyLevels (n->lpv);
               CHECK_CALL (e, ErrorMapDatabaseToExtended (n->lpv->wLinkNo,
                                                          RevisionAttach (n->lpv)));
            }
            return e;
         }
         break;

      case INSTANCE_NOTIFY_INSTANCE_CLOSING: {
         LPCMPNOTIFYCONTEXT n = (LPCMPNOTIFYCONTEXT) context;

         // Clear the view handles of any explicit composites reported as closing
         if ( n->composite<EXP_CMP_COUNT-DMND_CMP_COUNT ||
              ! * FindImpOpen (n->lpv, n->composite) ) {
            LPVIEWDEF v = FindCmp (n->lpv, n->composite);

            v->rvh = NULL;
            v->view = NULL;
         }
         break;
      }
   }
   return ERRNUM_SUCCESS;
}



#if defined(DO_COMPOSITENOTIFY)

VIEWCALL CompositeNotifyEntry (
   LPVOID context,
   LONG reason,
   LONG rotoID,
   LONG info,
   LPVOID extra,
   LPRVH rvh,
   LPVOID view)

// When the view author has overridden CompositeNotify(), this function gets
// substituted as notification handler. This is necessary since the override
// may well use or even affect the view's state in a way that assumes a full
// entrypoint invocation context. IOW, it needs to maintain the entry state,
// and it may generate notifications. NB that this present arrangement assumes
// the stock CompositeNotifyBase() does nothing requiring the entry state
// to be maintained.

{
   ERRNUM e = ERRNUM_SUCCESS;
   ENTRYSTATE state;
   LPV lpv = ((LPCMPNOTIFYCONTEXT) context)->lpv;
   LPVOID notifications = NULL;

   RVSPYNOTIFY (lpv, "NOTIFIED", reason, info, extra, context);
   if ( ENTRY_PATH_INACTIVE==lpv->EntryPath && lpv->NotifyList!=NULL ) {
      RVSPYTRACE ("Pushing ENTRYSTATE");
      EntryStatePush (lpv, NULL, 0, &state);
      notifications = lpv->NotifyList;
      // Save information for field value & attribute notifications later
      CopyRecords (lpv, FindRecordNotify (lpv), FindRecord (lpv));
      blkCopy (lpv->attributesNotify, lpv->alAttributes, sizeof (lpv->attributesNotify));
      blkSet (lpv->QueuedNotifyField, 0, sizeof (lpv->QueuedNotifyField));
      lpv->FieldsWereQueued = FALSE;
   }
   MaxError (&e, CompositeNotify (context, reason, rotoID, info, extra, rvh, view));
   if ( notifications!=NULL ) {
      MaxError (&e, NotifyFieldValues (lpv));
      MaxError (&e, NotifyFieldAttributes (lpv));
      MaxError (&e, NotifyQueuedFields (lpv));
      EntryStatePop (lpv, &state);
      RVSPYTRACE ("Popped ENTRYSTATE");
   }
   return e;
}

#endif



void WINAPI CopyRecords (LPV lpv, LPSTR FAR * to, LPSTR FAR * from)
{
   INT i;

   for ( i=0; i<BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT; i++ )
      blkCopy (to[i], from[i], FindTableWidth (lpv, i));
}



INT WINAPI DecimalComparator (LPDBFIELD field, LPDATUM d1, LPDATUM d2)
{
   return bcdCompare (d1->n, field->wLength, field->wDecimals,
                      d2->n, field->wLength, field->wDecimals);
}



VIEWBASE DeleteBodyBase (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;

   if ( !(lpv->bExists && lpv->bBrowseInSync) ) {
      DB_ERRNUM d = fileIsLocked (lpv);

      if ( DB_ERRNUM_IS_FAILURE (d) ) {
         CHECK_CALL (e, ErrorMapDatabaseToExtended (lpv->wLinkNo, fileLock (lpv)));
      }
   }
   if ( DO_CASCADEPOST==CASCADEPOST_AFTERHEADER ) {
      CHECK_CALL (e, ErrorMapDatabaseToExtended (lpv->wLinkNo, fileDelete (lpv)));
   }
 #if !defined(DO_DELETEFILTERDELETE) || HAS_REVISIONS!=NO_REVISIONS
   CHECK_CALL (e, MapToNestedDetails (lpv, VIEW_OP_POST));
 #else
   CHECK_CALL (e, MapToDetails (lpv, VIEW_OP_FILTER_DELETE, NULL,
                                FILTER_DELETE_TRY|FILTER_DELETE_CASCADE));
 #endif
   if ( DO_CASCADEPOST!=CASCADEPOST_AFTERHEADER ) {
      CHECK_CALL (e, ErrorMapDatabaseToExtended (lpv->wLinkNo, fileDelete (lpv)));
   }
   return e;
}



VIEWBASE DeleteDetails (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;
   INT c;

   if ( DTL_CMP_COUNT==0 )
      return e;
   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS )
      return e;

   for ( c=HDR_CMP_COUNT; c<HDR_CMP_COUNT+DTL_CMP_COUNT; c++ ) {
      LPVIEWDEF v = FindCmp (lpv, c);

      CHECK_CALL (e, DeleteDetailsBody (lpv, c));
      if ( DETAILS_ARE_REVISIONED ) {
         CHECK_CALL (e, viewPost (v->rvh, v->view));
      }
   }
   return e;
}



VIEWBASE DeleteDetailsBodyBase (LPV lpv, INT c)
{
   ERRNUM e = ERRNUM_SUCCESS;
   INT i;
   CHAR data [MAX_KEY_SIZE];
   LPVIEWDEF v;
   LPCMPKEY x;

   if ( DTL_CMP_COUNT==0 )
      return e;
   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS )
      return e;

   v = FindCmp (lpv, c);
   x = FindCmpKey (lpv, c);
   if ( v->view==NULL )
      return e;
   CHECK_CALL (e, viewBrowse (v->rvh, v->view, NULL, TRUE));
   for ( i=FindKeyDef (0)->segments; i<x->segments; i++ ) {
      InitFieldBuffer (data, x->types[i].type, x->types[i].size);
      CHECK_CALL (e, viewPut (v->rvh, v->view, x->indexes[i],
                              data, x->types[i].size, FALSE));
   }
   // Iteratively fetch and delete the details
   for (;;) {
      CHECK_FETCH (e, viewFetch (v->rvh, v->view));
      CHECK_CALL (e, viewDelete (v->rvh, v->view));
   }
   return e;
}



VIEWBASE DemandOpen (LPV lpv, INT c)
{
   ERRNUM e = ERRNUM_SUCCESS;

   if ( DMND_CMP_COUNT>0 &&
        c>=EXP_CMP_COUNT-DMND_CMP_COUNT && c<EXP_CMP_COUNT &&
        FindCmp (lpv, c)->view==NULL ) {
      CHECK_CALL (e, OpenOneView (lpv, c));
   }
   return e;
}



BOOL WINAPI DetailKeyWithinHeader (LPV lpv)
{
   if ( !(HDR_CMP_COUNT>0 && DTL_SEG_COUNT>0) )
      return FALSE;

   if ( lpv->wActualKey!=0 ) {
      if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
         return FALSE;
      } else {
         INT i;
         LPKEYMAP k = FindKeyDef (0);
         INT segments = k->segments - DTL_SEG_COUNT;
         LPLONG primary = k->indexes;
         LPLONG actual = FindKeyDef (lpv->wKey)->indexes;

         for ( i=0; i<segments; ++i )
            if ( primary[i]!=actual[i] )
               return FALSE;
      }
   }
   return TRUE;
}



// This function is tied intimately to the current implementation of
// scInitFilterDelete(), along with all its limitations. In particular,
// it only works with the fields of the primary key
VIEWCALL detailName (LPVOID lpView, LONG lField, LPSTR lpsName, LPSTR lpsDesc)
{
   LPV lpv = (LPV) lpView;
   INT number;
   LPKEYMAP k = FindKeyDef (0);
   LPVIEWDEF v = FindCmp (lpv, lpv->filterExpressionCast);

   for ( number=0; number<k->segments && k->indexes[number]!=lField; ++number )
      ;
   VIEWASSERT(number<k->segments);
   return viewName (v->rvh, v->view,
                    FindCmpKey (lpv, lpv->filterExpressionCast)->indexes[number],
                    lpsName, lpsDesc);
}



void WINAPI EntryStatePopBase (LPV lpv, LPENTRYSTATE state)
{
   int indents = RVSPYINDENT (0);

   lpv->bVerifying = state->bVerifying;
   lpv->bFieldChanged = state->bFieldChanged;
   lpv->ScratchAllocated = state->ScratchAllocated;
   lpv->eRevision = state->eRevision;
   lpv->eValidation = state->eValidation;
   lpv->RotoView = state->RotoView;
   lpv->RotoLength = state->RotoLength;
   lpv->filterExpressionCast = state->filterExpressionCast;
   lpv->transLevel = state->transLevel;
   RVSPYINDENT (state->rvspyIndents - indents);
   lpv->EntryPath = state->EntryPath;
}



LPENTRYSTATE WINAPI EntryStatePushBase (LPV lpv, LPROTOVIEW v, INT length, LPENTRYSTATE state)
{
   state->bVerifying = lpv->bVerifying;
   state->bFieldChanged = lpv->bFieldChanged;
   state->ScratchAllocated = lpv->ScratchAllocated;
   state->eRevision = lpv->eRevision;
   state->eValidation = lpv->eValidation;
   state->RotoView = lpv->RotoView;
   state->RotoLength = lpv->RotoLength;
   state->filterExpressionCast = lpv->filterExpressionCast;
   state->transLevel = lpv->transLevel;
   state->rvspyIndents = RVSPYINDENT (0);
   state->EntryPath = lpv->EntryPath;

   lpv->bFieldChanged = FALSE;
   lpv->eRevision = DBS_SUCCESS;
   lpv->eValidation = ERRNUM_SUCCESS;
   lpv->RotoView = v;
   lpv->RotoLength = length;
   if ( NULL==v )
      lpv->EntryPath = ENTRY_PATH_NOTIFY;
   else
      lpv->EntryPath = ENTRY_PATH_ROTO;

   return state;
}



VIEWBASE GetETAG (
   LPV lpv,
   LPSTR lpsBuffer,
   INT nSize)
{
   ERRNUM e = ERRNUM_SUCCESS;
   CHAR szDate [SIZEOF_ETAG_DATE + 1];
   CHAR szTime [SIZEOF_ETAG_TIME + 1];
   CHAR etag[SIZEOF_ETAG];
   LPCHAR p = etag;
   AUDITSTAMP adt;
   LPAUDITSTAMP lpadt = &adt;

   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS )
   {
      CHECK_CALL (e, viewGet (lpv->subCmp.rvh, lpv->subCmp.view, ETAG_IDX,
                              lpsBuffer, nSize));
      return e;
   }

   if ( nSize!=sizeof(etag) )
   {
      ReportError (lpv, (RSCID)IDERR_SC_BUFFER_MSG,
                   MAKERSC(IDS_SCINIT_VIEW_NOUN), "ETAG", NULL);
      return ERRNUM_MEMORY_BUFFER_LIMIT;
   }

   if ( HAS_DATABASE_TABLES )
   {
      // Explicitly assumes MP3 record
      lpadt = (LPAUDITSTAMP) (FindRecord (lpv) [BASE_TBL_COUNT] +
                              FindTableMap (BASE_TBL_COUNT)->fields[SCINIT_FLD_AUDIT].wOffset);
   }
   else
   {
      DBDATE dbDate;
      DBTIME dbTime;

      dtGetDate(&dbDate);
      dtGetTime(&dbTime);

      dtDateToBCD   (&dbDate,   (LPBCDDATE) lpadt->Date);
      dtTimeToBCD   (&dbTime,   (LPBCDTIME) lpadt->Time);
      ibGetUserID   (lpv->hpib, (LPBYTE)    lpadt->UserID);
      ibGetCmpOrgID (lpv->hpib, (LPBYTE)    lpadt->OrgID);
   }

   bcdToZStr ((PCBYTE) lpadt->Date, sizeof(lpadt->Date), 0,
              szDate,               sizeof(szDate),      0);
   bcdToZStr ((PCBYTE) lpadt->Time, sizeof(lpadt->Time), 0,
              szTime,               sizeof(szTime),      0);

   blkSet (etag, '0', SIZEOF_ETAG_DATE + SIZEOF_ETAG_TIME);

   p += SIZEOF_ETAG_DATE - strLength(szDate);
   blkCopy (p, szDate, strLength(szDate));
   p += strLength(szDate);

   p += SIZEOF_ETAG_TIME - strLength(szTime);
   blkCopy (p, szTime, strLength(szTime));
   p += strLength(szTime);

   blkCopy (p, lpadt->UserID, SIZEOF_USERID);
   p += SIZEOF_USERID;

   blkCopy (p, lpadt->OrgID, SIZEOF_ORGID);
   p += SIZEOF_ORGID;

   blkSet (lpsBuffer, ' ', nSize);
   blkCopy (lpsBuffer, etag, min (nSize, sizeof(etag)));

   return e;
}



#if defined(DO_HELPERSOUTOFLINE)

LPVIEWDEF WINAPI FindCmp (LPV lpv, INT cmp)
{
   VIEWASSERT(CMP_COUNT+MAN_CMP_COUNT>0);
   VIEWASSERT(cmp>=0);
   VIEWASSERT(cmp<CMP_COUNT+MAN_CMP_COUNT);
   return DoFindCmp (lpv, cmp);
}



LPCMPNAME WINAPI FindCmpDef (INT cmp)
{
   VIEWASSERT(CMP_COUNT+MAN_CMP_COUNT>0);
   VIEWASSERT(cmp>=0);
   VIEWASSERT(cmp<CMP_COUNT+MAN_CMP_COUNT);
   return DoFindCmpDef (cmp);
}



LPLONG WINAPI FindCmpField (LPV lpv, INT cmp, LONG field)
{
   VIEWASSERT(CMP_COUNT-HDR_CMP_COUNT>0);
   VIEWASSERT(cmp>=HDR_CMP_COUNT);
   VIEWASSERT(cmp<CMP_COUNT);
   return DoFindCmpField (lpv, cmp, field);
}



LPBOOL WINAPI FindCmpForeign (LPV lpv, LONG field)
{
   VIEWASSERT(HCHY_CMP_COUNT+DMND_CMP_COUNT+IMP_CMP_COUNT>0);
   return DoFindCmpForeign (lpv, field);
}



LPCMPKEY WINAPI FindCmpKey (LPV lpv, INT cmp)
{
   VIEWASSERT(CMP_COUNT+MAN_CMP_COUNT>0);
   VIEWASSERT(cmp>=0);
   VIEWASSERT(cmp<CMP_COUNT+MAN_CMP_COUNT);
   return DoFindCmpKey (lpv, cmp);
}



LPSTR WINAPI FindCmpName (INT cmp)
{
   VIEWASSERT(CMP_COUNT+MAN_CMP_COUNT>0);
   VIEWASSERT(cmp>=0);
   VIEWASSERT(cmp<CMP_COUNT+MAN_CMP_COUNT);
   return DoFindCmpName (cmp);
}



LPCMPNOTIFYCONTEXT WINAPI FindCmpNotify (LPV lpv, INT cmp)
{
   VIEWASSERT(CMP_COUNT+MAN_CMP_COUNT>0);
   VIEWASSERT(cmp>=0);
   VIEWASSERT(cmp<CMP_COUNT+MAN_CMP_COUNT);
   return DoFindCmpNotify (lpv, cmp);
}



LPDETAILMAP WINAPI FindDetailMap ()
{
   return DoFindDetailMap ();
}

#endif



LPDBFIELD WINAPI FindFieldDefV (LPV lpv, LONG field)
{
   LPIDXMAP f = FindFieldMapV (lpv, field);

   VIEWASSERT(ValidIndexV (lpv, field));
   return FindTableMapV (lpv, f->tblNo)->fields + f->tblFieldNo;
}



#if defined(DO_HELPERSOUTOFLINE)

LPLONG WINAPI FindFieldIndexV (LPV lpv, INT field)
{
   VIEWASSERT(FLD_IDX_COUNT>0);
   VIEWASSERT(field>=1);
   VIEWASSERT(field<=FLD_IDX_COUNT);
   return DoFindFieldIndexV (lpv, field);
}



LPIDXMAP WINAPI FindFieldMapV (LPV lpv, LONG field)
{
   VIEWASSERT(ValidIndexV (lpv, field));
   return DoFindFieldMapV (lpv, field);
}



LPSTR WINAPI FindFieldValue (LPV lpv, LONG field)
{
   VIEWASSERT(ValidIndexV (lpv, field));
   return DoFindFieldValue (lpv, field);
}

#endif



LPSTR WINAPI FindFieldValueAux (LPV lpv, LONG field, LPSTR FAR * records)
{
   LPIDXMAP f = FindFieldMapV (lpv, field);

   VIEWASSERT(f->tblNo>=0);
   return records[f->tblNo] + FindTableMapV (lpv, f->tblNo)->fields[f->tblFieldNo].wOffset;
}



#if defined(DO_HELPERSOUTOFLINE)

LPBOOL WINAPI FindGenStub (LPV lpv, INT cmp)
{
   VIEWASSERT(CMP_COUNT+MAN_CMP_COUNT>0);
   VIEWASSERT(cmp>=0);
   VIEWASSERT(cmp<CMP_COUNT+MAN_CMP_COUNT);
   return DoFindGenStub (lpv, cmp);
}



LPBOOL WINAPI FindImpOpen (LPV lpv, INT cmp)
{
   VIEWASSERT(DMND_CMP_COUNT+IMP_CMP_COUNT+MAN_CMP_COUNT>0);
   VIEWASSERT(cmp>=CMP_COUNT-DMND_CMP_COUNT);
   VIEWASSERT(cmp<CMP_COUNT+MAN_CMP_COUNT);
   return DoFindImpOpen (lpv, cmp);
}



LPBOOL WINAPI FindImpRead (LPV lpv, INT cmp)
{
   VIEWASSERT(DMND_CMP_COUNT+IMP_CMP_COUNT+MAN_CMP_COUNT>0);
   VIEWASSERT(cmp>=CMP_COUNT-DMND_CMP_COUNT);
   VIEWASSERT(cmp<CMP_COUNT+MAN_CMP_COUNT);
   return DoFindImpRead (lpv, cmp);
}



LPKEYMAP WINAPI FindKeyDef (INT key)
{
   VIEWASSERT(KEY_COUNT>0);
   VIEWASSERT(key<KEY_COUNT);
   return DoFindKeyDef (key);
}

#endif




LPKEYMAP WINAPI FindKeyMap (INT c)
{
   LPKEYMAP k = NULL;

   if ( HCHY_CMP_COUNT+DMND_CMP_COUNT+IMP_CMP_COUNT==0 )
      return k;

   VIEWASSERT(c>=HDR_CMP_COUNT+DTL_CMP_COUNT);
   if ( c<HDR_CMP_COUNT+DTL_CMP_COUNT )
      return k;
   VIEWASSERT(c<CMP_COUNT);
   if ( c>=CMP_COUNT )
      return k;

   k = hierarchyKeyMap;
   for ( c -= HDR_CMP_COUNT+DTL_CMP_COUNT; c>0; c--, k++ )
      k += k->name;
   return k;
}



#if defined(DO_HELPERSOUTOFLINE)

LPPERMISSIONMAP WINAPI FindPermissionMap ()
{
   VIEWASSERT(RSC_COUNT>0);
   return DoFindPermissionMap ();
}

#endif



#if !defined(DO_FINDPRESENTSINFO)

LPPRESENTATION WINAPI FindPresentsInfo (LPV lpv, LONG field)
{
   VIEWASSERT(ValidIndexV (lpv, field));
   return FindFieldMapV (lpv, field)->presents;
}

#endif



#if defined(DO_HELPERSOUTOFLINE)

LPSTR FAR * WINAPI FindRecord (LPV lpv)
{
   VIEWASSERT(BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT>0);
   return DoFindRecord (lpv);
}



LPSTR FAR * WINAPI FindRecordNotify (LPV lpv)
{
   VIEWASSERT(BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT>0);
   return DoFindRecordNotify (lpv);
}



LPSTR FAR * WINAPI FindRecordRead (LPV lpv)
{
   VIEWASSERT(BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT>0);
   return DoFindRecordRead (lpv);
}



LPSTR FAR * WINAPI FindRecordTemp (LPV lpv)
{
   VIEWASSERT(BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT>0);
   return DoFindRecordTemp (lpv);
}



LPREVISION WINAPI FindRevCache (LPV lpv)
{
   VIEWASSERT(TBL_COUNT>0 && HAS_REVISIONS!=NO_REVISIONS);
   return DoFindRevCache (lpv);
}



LPREVLEVEL WINAPI FindRevLevel (LPV lpv, INT level)
{
   VIEWASSERT(HDR_HAS_REVISIONS>0);
   VIEWASSERT(level>=1);
   VIEWASSERT(level<=HDR_HAS_REVISIONS);
   return DoFindRevLevel (lpv, level);
}



LPREVNODE ** WINAPI FindRevRekey (LPV lpv, INT level)
{
   VIEWASSERT(HDR_HAS_REVISIONS>0);
   VIEWASSERT(level>=1);
   VIEWASSERT(level<=HDR_HAS_REVISIONS);
   return DoFindRevRekey (lpv, level);
}



LPTABLEHANDLE WINAPI FindTableHandle (LPV lpv)
{
   VIEWASSERT(TBL_COUNT>0);
   return DoFindTableHandle (lpv);
}



LPDBTABLE WINAPI FindTableInfo (LPV lpv, INT t)
{
   VIEWASSERT(BASE_TBL_COUNT+TBL_COUNT>0);
   VIEWASSERT(t>=0);
   VIEWASSERT(t<BASE_TBL_COUNT+TBL_COUNT);
   return DoFindTableInfo (lpv, t);
}



LPTBLMAP WINAPI FindTableMap (INT t)
{
   VIEWASSERT(BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT>0);
   VIEWASSERT(t>=0);
   VIEWASSERT(t<BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT);
   return DoFindTableMap (t);
}



LPTBLMAP WINAPI FindTableMapV (LPV lpv, INT t)
{
   VIEWASSERT(t>=0);
   return DoFindTableMapV (lpv, t);
}



LPREVISION WINAPI FindTableRev (LPV lpv)
{
   VIEWASSERT(TBL_COUNT>0 && HAS_REVISIONS!=NO_REVISIONS);
   return DoFindTableRev (lpv);
}



PTABLESELECTION WINAPI FindTableSelection (const LPV lpv, const INT t)
{
   VIEWASSERT(TBL_COUNT>0);
   VIEWASSERT(t>=BASE_TBL_COUNT);
   VIEWASSERT(t<BASE_TBL_COUNT+TBL_COUNT);
   return DoFindTableSelection (lpv, t);
}



WORD FindTableWidth (LPV lpv, INT t)
{
   VIEWASSERT(BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT>0);
   VIEWASSERT(t>=0);
   VIEWASSERT(t<BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT);
   return DoFindTableWidth (lpv, t);
}

#endif



VIEWBASE FlagKey (LPV lpv, INT wKeyNo, BOOL bSet, LONG lMask)
{
   ERRNUM e = ERRNUM_SUCCESS;
   INT nSeg;
   LPKEYMAP lpkmap;

   if ( KEY_COUNT==0 )
      return e;
   lpkmap = FindKeyDef (wKeyNo);
   for ( nSeg=lpkmap->segments; nSeg--; ) {
      LONG field = lpkmap->indexes [nSeg];

      if ( !ValidIndexV (lpv, field) )
         continue;
      AttribClear (lpv, field, lMask);
      CHECK_CALL (e, lpv->eValidation);
      if (bSet) {
         AttribSet (lpv, field, lMask);
         CHECK_CALL (e, lpv->eValidation);
      }
   }
   return e;
}



VIEWBASE FlagKeyAux (LPV lpv, INT wKeyNo, INT keys, BOOL bSet, LONG lMask)
{
   ERRNUM e = ERRNUM_SUCCESS;

   if ( wKeyNo>=keys ) {
      CHECK_CALL (e, FlagKey (lpv, wKeyNo-keys, bSet, lMask));
   }
   return e;
}



VIEWBASE GenerateKeyReally (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;
#if defined(DO_GENERATEKEY) || defined(DO_GENERATEKEYDELAYED)
   ////////////// The following only works for MP3 records
   INT primary = FindTableMapV (lpv, BASE_TBL_COUNT)->fields[SCINIT_FLD_AUDIT].wOffset;

   blkCopy (lpv->abKeyBefore, (FindRecord (lpv)) [BASE_TBL_COUNT], primary);
   if ( GENERATEKEY_RECORD==lpv->bKeyGenerated ) {
      INT level = HAS_REVISIONS!=NO_REVISIONS ? (2+HDR_HAS_REVISIONS) : 1;

      CHECK_CALL (e, GenerateKeyDelayed (lpv, GENERATEKEY_KEY));
      lpv->bKeyGenerated |= GENERATEKEY_KEY;
      CHECK_CALL (e, MapToDetails (
         lpv, VIEW_OP_REVISION_REKEY,
         lpv->abKeyBefore, (FindRecord (lpv)) [BASE_TBL_COUNT],
         primary, level << SHIFT_REVISION_REKEY_LEVEL));
   }
#endif
   return e;
}



DB_ERRNUM WINAPI GenerateSequence (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;
   LPKEYMAP k;
   LONG field;
   LPDBFIELD f;
   LPTYPEOPERATIONS operations;
   LPDATUM increment;
   LPDATUM key;
   DWORD skip;
   INT digit;

   if ( HAS_REVISIONS!=SEQUENCE_REVISIONS )
      return d;
   if ( lpv->wActualKey!=0 )
      return d;

   k = FindKeyDef (0);
   field = k->indexes [k->segments - 1];
   f = FindFieldDefV (lpv, field);
   operations = aTypeOperations [f->wType];
   increment = (LPDATUM) _alloca (f->wLength);
   key = (LPDATUM) FindFieldValue (lpv, field);

   VIEWASSERT (operations!=NULL);
   VIEWASSERT (increment!=NULL);

   switch ( f->wType ) {
      case FT_BCD:
         bcdGrow (increment->n, REV_SEQ_SKIP, f->wLength);
         break;
      case FT_INT:
         increment->i = REV_SEQ_SKIP;
         break;
      case FT_LONG:
         increment->l = REV_SEQ_SKIP;
         break;
      case FT_BYTE:
         if ( f->wLength==1 ) {
            increment->b[0] = (DBSBINARY) REV_SEQ_SKIP;
            break;
         }
         // FALL THRU!
      case FT_CHAR:
         blkSet (increment->s, '0', f->wLength);
         skip = REV_SEQ_SKIP;
         digit = f->wLength - 1;
         while ( skip>0 && digit>=0 ) {
            increment->s[digit] += (DBSSTRING) (skip % 10);
            skip /= 10;
            --digit;
         }
         break;
      case FT_REAL:
         increment->r = REV_SEQ_SKIP;
         break;
      default:
         break;
   }
   (* operations->add) (f, key, increment);

   return d;
}



VIEWBASE GenericStub (LPV lpv, INT c, LPBOOL gen)
{
   ERRNUM e = ERRNUM_SUCCESS;

   *gen = FALSE;
   if ( CMP_COUNT+MAN_CMP_COUNT>0 ) {
      CHAR desc [SIZEOF_FLDDESC];
      CHAR name [SIZEOF_FIELDNAME];
      LPVIEWDEF v = FindCmp (lpv, c);

      CHECK_CALL (e, viewName (v->rvh, v->view, TITLE_IDX, name, desc));
      *gen = blkCompare (name, "CA-GENSTUB", sizeof (name))==0;
   }
   return e;
}



A4W_FLAGS WINAPI GetPermissions (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;
   A4W_FLAGS permissions;

   e = scInitInstanceSecurity (lpv, &permissions);
   if ( ERRNUM_IS_FAILURE (e) )
      permissions = 0;
   return permissions;
}



#if ! defined LINUX_VER
#pragma warning(push)
#pragma warning(disable : 4101)
#endif

VIEWBASE GetTemplateVersion (LPV lpv, LPSTR rotoID, LPVIEWDEF view, LPSTR supports, LPBCDDATE date)
{
   IDENTIFYVIEW id;
   ROTOMSG roto;
   CHAR appl [SIZEOF_PGMID];
   ERRNUM r = ERRNUM_SUCCESS;
   ERRNUM e = ERRNUM_SUCCESS;
   LONG permissions = 0L;

   VIEWASSERT (view->rvh!=NULL);
   if ( view->rvh==NULL )
      return e;

   blkCopy (supports, "41A", SIZEOF_VERSION);
   bcdInit (date, SIZEOF_DATE);
   r = identifyVersionTemplate ((LPRVH) view->rvh, supports, date);
   if ( ERRNUM_IS_FAILURE (r) && r!=ERRNUM_ROTOENTRY_FAILED ) {
      // Any errors other than the above are treated as protocol problems.
      MaxError (&e, r);
   }

   return e;
}

#if ! defined LINUX_VER
#pragma warning(pop)
#endif



/*--------------------------------------------------------------------
   Blanks, zeroes, or defaults (as appropriate) the contents of each
   field in a view.
*/
VIEWBASE InitBody (LPV lpv)
{
   return InitBodyGen (lpv, INITBODYGEN_AUTOINSERT | INITBODYGEN_AUTOGENERATE | INITBODYGEN_NOTOPEN);
}



/*--------------------------------------------------------------------
   Blanks, zeroes, or defaults (as appropriate) the contents of each
   field in a view.
*/
VIEWBASE InitBodyGenBase (LPV lpv, INT fGenerate)
{
   ERRNUM e = ERRNUM_SUCCESS;
   INT nTbl = 0;
   INT preserve = 0;
   INT i = 0;
   LPKEYMAP k = FindKeyDef (0);
   INT generate = GENERATEKEY_NONE;
   INT insert = FALSE;
   INT start = 0;
   LONG field = 0L;
   LPSTR data = NULL;
   LPDBFIELD f = NULL;
   CHAR LastSegment[MAX_FIELD_LENGTH];
#if !defined(DO_OPENETC) || defined(DO_OLDOPENETC)
   BOOL IsNewOpenEtc = FALSE;
#else
   BOOL IsNewOpenEtc = TRUE;
#endif

   switch ( fGenerate & MASK_INITBODYGEN_OPEN ) {
      case INITBODYGEN_OLDOPEN:
         if ( IsNewOpenEtc )
            return e;
         break;
      case INITBODYGEN_OPENETC:
         if ( !IsNewOpenEtc )
            return e;
         break;
      case INITBODYGEN_NOTOPEN:
      default:
         break;
   }

#if defined(DO_GENERATEKEY) || HAS_REVISIONS==SEQUENCE_REVISIONS || defined(DO_GENERATEKEYDELAYED)
   if ( lpv->wActualKey==0 ||
        (HAS_REVISIONS!=SEQUENCE_REVISIONS &&
         VIEW_OP(lpv,OPEN)==VIEW_OP_RECORD_GENERATE) ) {
      CHAR def = 0;

      field = k->indexes[k->segments-1];
      data = FindFieldValue (lpv, field);
      f = FindFieldDefV (lpv, field);

      switch ( fGenerate & MASK_INITBODYGEN_GENERATE ) {
         case INITBODYGEN_FORCEGENERATE:
            generate = GENERATEKEY_KEY | GENERATEKEY_RECORD;
            if ( HAS_REVISIONS==SEQUENCE_REVISIONS )
               blkCopy (LastSegment, data, f->wLength);
            break;

         case INITBODYGEN_DELAYGENERATE:
            generate = GENERATEKEY_RECORD;
            break;

         case INITBODYGEN_AUTOGENERATE:
            if ( HAS_REVISIONS==SEQUENCE_REVISIONS )
               // short-circuit this, since it gets done differently below
               break;

            switch ( f->wType ) {
               case FT_INT:
               case FT_BOOL:
                  if ( 0==*(LPDBSINT)data )
                     generate = GENERATEKEY_KEY | GENERATEKEY_RECORD;
                  break;

               case FT_LONG:
                  if ( 0L==*(LPDBSLONG)data )
                     generate = GENERATEKEY_KEY | GENERATEKEY_RECORD;
                  break;

               case FT_DATE:
               case FT_TIME:
               case FT_BCD:
                  if ( 0==bcdCompareZero ((LPDBSNUMBER) data, f->wLength) )
                     generate = GENERATEKEY_KEY | GENERATEKEY_RECORD;
                  break;

               case FT_CHAR:
                  def = '0';
                  // FALL-THROUGH!!!
               case FT_BYTE:
               case FT_REAL:
                  for ( i=0; i<f->wLength && data[i]==def; ++i )
                     ;
                  if ( i==f->wLength )
                     generate = GENERATEKEY_KEY | GENERATEKEY_RECORD;
                  break;
            }
            break;

         case INITBODYGEN_NOGENERATE:
         default:
            break;
      }
   }

   if ( generate!=GENERATEKEY_NONE ) {
      // QUESTION: should we have early denial when V.pViewSelection!=NULL?
      switch ( fGenerate & MASK_INITBODYGEN_INSERT ) {
         case INITBODYGEN_FORCEINSERT:
            insert = TRUE;
            break;
         case INITBODYGEN_AUTOINSERT:
 #if defined(BATCH_VIEW) && !(defined(DETAIL_VIEW) || defined(HEADER_VIEW))
            insert = TRUE;
 #endif
            break;
         case INITBODYGEN_NOINSERT:
         default:
            break;
      }
   }
#endif

   CHECK_CALL (e, InitFields (lpv));
   CHECK_CALL (e, ErrorMapViewToExtended (
      VIEW_OP (lpv, OPEN), ERROR_FROM_CALLOUT (InitNonBlankFields (lpv))));

   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
      CHECK_CALL (e, BaseGetKey (lpv));
   }

   lpv->bKeyGenerated = GENERATEKEY_NONE;
   if ( generate!=GENERATEKEY_NONE ) {
      if ( HAS_REVISIONS!=SEQUENCE_REVISIONS ) {
         CHECK_CALL (e, ErrorMapViewToExtended (
            VIEW_OP (lpv, OPEN),
            ERROR_FROM_CALLOUT (GenerateKeyDelayed (lpv, generate))));
      } else {
         blkCopy (data, LastSegment, f->wLength);
         if ( !lpv->bRevisioned ) {
            CHECK_CALL (e, ErrorMapDatabaseToExtended (
                              lpv->wLinkNo, GenerateSequence (lpv)));
         } else {
            CHECK_CALL (e, ErrorMapDatabaseToExtended (
                              lpv->wLinkNo, RevisionAllocateAfter (lpv, f, data)));
         }
      }
      lpv->bKeyGenerated = generate;
      PropagatePrimary (lpv);
   }

   CHECK_CALL (e, ErrorMapViewToExtended (
      VIEW_OP (lpv, OPEN), ERROR_FROM_CALLOUT (CalculateFields (lpv))));

#if defined(DO_RECORDREAD) || defined(DO_CONCURRENCYETC)
   CopyRecords (lpv, FindRecordRead (lpv), FindRecord (lpv));
#endif
   SaveHeaderFields (lpv);

   CHECK_CALL (e, BaseNotifyFire (
      lpv, INSTANCE_NOTIFY_RECORD_INITIALIZED, VIEW_OP (lpv, OPEN), (LPVOID) generate));

   if ( SUBCLASS_LEVEL==NOT_SUBCLASS ) {
#if defined(DO_GENERATEKEY) || DTL_CMP_COUNT>0 || defined(DO_GENERATEKEYDELAYED)
      if ( DTL_SEG_COUNT==0 )
         start = 0;
      else
         start = k->segments-DTL_SEG_COUNT;
 #if !defined(DO_OLDINITBODYCASCADE) && DETAILS_ARE_REVISIONED
      // Since interactions between headers and details are much more nuanced
      // these days, it is important to make sure details are really cleaned out
      CHECK_CALL (e, MapToNestedDetails (lpv, VIEW_OP_CANCEL));
 #endif
 #if !defined(DO_LAZYPUT)
      if ( generate )
         for ( i=k->segments; i-->start; ) {
            LONG field = k->indexes[i];

            CHECK_CALL (e, ErrorMapViewToExtended (
               VIEW_OP_PUT,
               PutCmpField (lpv, field, FindFieldValue (lpv, field),
                            FindFieldDefV (lpv, field)->wLength)));
         }
      else {
         for ( i=k->segments; i-->start; ) {
            LPSTR data = FindFieldValue (lpv, k->indexes[i]);
            INT c;

            for ( c=HDR_CMP_COUNT; c<HDR_CMP_COUNT+DTL_CMP_COUNT; c++ )
               if ( FindCmp (lpv, c)->view!=NULL ) {
                  LPVIEWDEF v = FindCmp (lpv, c);
                  LPCMPKEY x = FindCmpKey (lpv, c);

                  CHECK_CALL (e, viewPut (v->rvh, v->view, x->indexes[i],
                                          data, x->types[i].size, FALSE));
               }
         }
      }
 #else
      for ( i=k->segments; i-->start; ) {
         LONG field = k->indexes[i];

         CHECK_CALL (e, ErrorMapViewToExtended (
            VIEW_OP_PUT,
            PutCmpField (lpv, field, FindFieldValue (lpv, field),
                         FindFieldDefV (lpv, field)->wLength)));
      }
 #endif
#endif
   }

   CHECK_CALL (e, ClearChange (lpv));
   lpv->bBrowsing = FALSE;
   lpv->bBrowseEnded = TRUE;
   lpv->bBrowseInSync = FALSE;
   lpv->bVerified = FALSE;
   lpv->bExists = FALSE;

   if ( insert ) {
      CHECK_CALL (e, scInitInsert (lpv));
   }
   return e;
}



VIEWBASE InitField (LPV lpv, LONG field)
{
   ERRNUM e = ERRNUM_SUCCESS;
   LPDBFIELD f;

   if ( lpv->alAttributes[IDXIDX(field)] & ATTR_NULL )
      return e;

   f = FindFieldDefV (lpv, field);
   InitFieldBuffer (FindFieldValue (lpv, field), f->wType, f->wLength);
   CHECK_CALL (e, InitFieldList (lpv, field));
   return e;
}



void WINAPI InitFieldBuffer (LPVOID buffer, INT type, INT length)
{
   switch ( type ) {
      case FT_CHAR :
         blkSet (buffer, ' ', length);
         break;

      case FT_BYTE :
      case FT_REAL :
      case FT_INT  :
      case FT_LONG :
      case FT_BOOL :
         blkSet (buffer, 0, length);
         break;

      case FT_DATE :
      case FT_TIME :
      case FT_BCD :
         bcdInit ((LPDBSNUMBER) buffer, length);
         break;

      default:
         break;
   }
}



VIEWBASE InitFieldList (LPV lpv, LONG field)
{
   ERRNUM e = ERRNUM_SUCCESS;
   LPPRESENTATION p;

   if ( lpv->alAttributes[IDXIDX(field)] & ATTR_NULL )
      return e;

   p = FindPresentsInfo (lpv, field);
   CHECK_CALL (e, lpv->eValidation);
   if ( p!=NULL && (p->type==PRESENTS_LIST || p->type==PRESENTS_LIST_INLINE) ) {
      LPDATUM datum = (LPDATUM) FindFieldValue (lpv, field);
      LPDBFIELD f = FindFieldDefV (lpv, field);
      DBSINT value = p->listNums[0];

      switch ( f->wType ) {
         case FT_BYTE:
         case FT_CHAR:
            switch ( f->wLength ) {
               case 1:
                  datum->b[0] = (BYTE) value;
                  break;
               case SIZEOF_INT:
                  datum->i = value;
                  break;
               case SIZEOF_LONG:
                  datum->l = value;
                  break;
            }
            break;

         case FT_INT:
            datum->i = value;
            break;

         case FT_LONG:
            datum->l = value;
            break;

         case FT_BOOL:
            datum->f = value;
            break;
      }
   }

   return e;
}



VIEWBASE InitFields (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;
   INT i, t;
   LPLONG primary = NULL;

   if ( SUBCLASS_LEVEL==NOT_SUBCLASS )
      primary = FindKeyDef (0)->indexes;
   else
      primary = lpv->subCmpKey.indexes;

   // for each table, initialize ints, longs, bools, dates, times, and bcds
   // skipping all header-composite key fields
   for ( t=0; t<BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT; ++t ) {
      LPDBFIELD f;
      INT skip = lpv->wDetailFilterSegments;

      if ( t<BASE_TBL_COUNT || t>=BASE_TBL_COUNT+TBL_COUNT )
         skip = 0;
      f = FindTableMapV (lpv, t)->fields + skip;
      for ( i=FindTableMapV (lpv, t)->table->wNoOfFields-skip; i--; ++f )
         InitFieldBuffer ((FindRecord (lpv)) [t]+f->wOffset, f->wType, f->wLength);
   }

   // Initialize fields with presentation lists
   for ( i=0; i<FLD_IDX_COUNT; ++i ) {
      LONG f = * FindFieldIndexV (lpv, i);

      if ( lpv->wDetailFilterSegments>0 ) {
         for ( t=0; t<lpv->wDetailFilterSegments && f!=primary[t]; ++t )
            ;
         if ( t<lpv->wDetailFilterSegments )
            continue;
      }
      CHECK_CALL (e, InitFieldList (lpv, f));
   }

   return e;
}



VIEWBASE InitFieldStruct (LPV lpv)
{
   LONG nFld;
   INT field;
#if CMP_COUNT-HDR_CMP_COUNT>0
   INT nCmp;
#endif
#if DMND_CMP_COUNT>0 || (defined(DO_LAZYPUT) && DMND_CMP_COUNT+IMP_CMP_COUNT>0)
   LPKEYMAP k;
   INT i, seg;
#endif
   ERRNUM e = ERRNUM_SUCCESS;

   for ( field=0; field<FLD_IDX_COUNT; ++field ) {
      nFld = * FindFieldIndexV (lpv, field);
      AttribPut (lpv, nFld, (ATTR_ENABLED | ATTR_EDITABLE) ^
                            FindFieldMapV (lpv, nFld)->attributes);
      CHECK_CALL (e, lpv->eValidation);
#if CMP_COUNT-HDR_CMP_COUNT>0
 #if HCHY_CMP_COUNT+DMND_CMP_COUNT+IMP_CMP_COUNT>0
      * FindCmpForeign (lpv, nFld) = 0;
 #endif
      for (nCmp = HDR_CMP_COUNT; nCmp < CMP_COUNT; nCmp++)
         * FindCmpField (lpv, nCmp, nFld) = 0L;
#endif
      CHECK_CALL (e, ErrorMapViewToExtended (
         VIEW_OP_OPEN, ERROR_FROM_CALLOUT (InitFieldStructEtc (lpv, nFld))));
   }
#if DMND_CMP_COUNT>0 || (defined(DO_LAZYPUT) && DMND_CMP_COUNT+IMP_CMP_COUNT>0)
 #if defined(DO_LAZYPUT) && DMND_CMP_COUNT+IMP_CMP_COUNT>0
   for ( nCmp=EXP_CMP_COUNT-DMND_CMP_COUNT; nCmp<CMP_COUNT; nCmp++ )
 #else
   for ( nCmp=EXP_CMP_COUNT-DMND_CMP_COUNT; nCmp<EXP_CMP_COUNT; nCmp++ )
 #endif
   {
      k = FindKeyMap (nCmp);
      if ( k ) {
         i = k->name;
         do {
            for ( seg=k->segments; seg-->0; )
               * FindCmpForeign (lpv, k->indexes[seg]) = 1;
            k++;
         } while ( i-- );
      }
   }
#endif
   return e;
}



INT WINAPI IntegerComparator (LPDBFIELD field, LPDATUM d1, LPDATUM d2)
{
   if ( d1->i>d2->i )
      return 1;
   if ( d1->i<d2->i )
      return -1;
   return 0;
}



BOOL WINAPI isGenericStub (LPV lpv, INT c)
{
   BOOL gen;
   ERRNUM e = ERRNUM_SUCCESS;

   e = GenericStub (lpv, c, &gen);
   VIEWASSERT(ERRNUM_IS_SUCCESS (e));
   return gen;
}



BOOL WINAPI isZeroDeltaBCD (LPDBFIELD field, LPDATUM data)
{
   return bcdCompareZero (data->n, field->wLength)==0;
}

BOOL WINAPI isZeroDeltaByte (LPDBFIELD field, LPDATUM data)
{
   if ( field->wLength==1 )
      return data->b[0] == 0;
   else
      return isZeroDeltaString (field, data);
}

BOOL WINAPI isZeroDeltaInteger (LPDBFIELD field, LPDATUM data)
{
   return data->i == 0;
}

BOOL WINAPI isZeroDeltaLong (LPDBFIELD field, LPDATUM data)
{
   return data->l == 0L;
}

BOOL WINAPI isZeroDeltaReal (LPDBFIELD field, LPDATUM data)
{
   return data->r == 0.0;
}

BOOL WINAPI isZeroDeltaString (LPDBFIELD field, LPDATUM data)
{
   INT i;

   for ( i=field->wLength; i--; )
      if ( data->s[i]!='0' )
         return FALSE;
   return TRUE;
}



VIEWBASE LoadFieldMask (LPV lpv, LONG field, LPSTR mask)
{
   ERRNUM e = ERRNUM_SUCCESS;
   LPPRESENTATION p;

   mask[0] = '\0';
   p = FindPresentsInfo (lpv, field);
   CHECK_CALL (e, lpv->eValidation);
   if ( p==NULL || p->type!=PRESENTS_MASK )
      return e;
   LoadMask (lpv->hpib, p->mask, MAX_FIELD_LENGTH, mask);
   return e;
}



void WINAPI LoadMask (HPIB hpib, LPSTR maskID, INT maskSize, LPSTR mask)
{
   mask[0] = 0;
   LoadRsc (hpib, maskID, maskSize, mask, FALSE);
}




VIEWBASE LoadOneView (LPV lpv, INT c)
{
   LPVIEWDEF v;
   VIEWLOADSTRUCT vls;

   if ( DMND_CMP_COUNT+IMP_CMP_COUNT+MAN_CMP_COUNT==0 )
      return ERRNUM_SUCCESS;

   VIEWASSERT(c>=HDR_CMP_COUNT+DTL_CMP_COUNT+HCHY_CMP_COUNT);
   if ( c<HDR_CMP_COUNT+DTL_CMP_COUNT+HCHY_CMP_COUNT )
      return ERRNUM_SUCCESS;
   VIEWASSERT(c<CMP_COUNT+MAN_CMP_COUNT);
   if ( c>=CMP_COUNT+MAN_CMP_COUNT )
      return ERRNUM_SUCCESS;

   v = FindCmp (lpv, c);
   if ( v->rvh!=NULL )
      return ERRNUM_SUCCESS;
   ibGetRoto (lpv->hpib, &vls.iRotoInstance);
   vls.iTag = 1;
   strCopyBZ (vls.sPgmID, sizeof (vls.sPgmID), APPL);
   utlObjStrToID (FindCmpName (c), &vls.lViewID);
   if ( (v->rvh = viewLoadEx (&vls))==NULL ) {
      ReportLoadError (lpv, FindCmpName (c));
      return ERRNUM_LOAD_FAILED;
   }
   return ERRNUM_SUCCESS;
}



LPSTR WINAPI LoadRsc (HPIB hpib, LPSTR strID, INT buffersize, LPSTR buffer, BOOL trim)
{
   if ( strID==NULL )
      return NULL;
   if ( HIWORD(strID)==0 ) {
      rscLoadText (hpib, APPL, LOWORD(strID), buffer, buffersize);
   } else {
      if ( strID!=buffer )
         strCopyN (buffer, strID, buffersize);
      buffer[buffersize-1] = 0;
   }
   if ( trim ) {
      strLTrim (buffer);
      strRTrim (buffer);
   }
   return buffer;
}



INT WINAPI LongComparator (LPDBFIELD field, LPDATUM d1, LPDATUM d2)
{
   if ( d1->l>d2->l )
      return 1;
   if ( d1->l<d2->l )
      return -1;
   return 0;
}



#if defined(DO_HELPERSOUTOFLINE)

WORD WINAPI MapStubToTableHandle (LPV lpv, TABLEHANDLE handle)
{
   return DoMapStubToTableHandle (lpv, handle);
}

#endif



VIEWBASE MapToDetailBase (LPV lpv, INT op, INT cmp, va_list arguments)
{
   ERRNUM e = ERRNUM_SUCCESS;
   LPVIEWDEF v;
   LPCMPKEY x;
   ROTOVIEW comm;
   LPSTR range;
   LPFILTER filter;

   if ( DTL_CMP_COUNT==0 )
      return ERRNUM_SUCCESS;

   v = FindCmp (lpv, cmp);
   x = FindCmpKey (lpv, cmp);
   if ( v->view==NULL )
      return ERRNUM_SUCCESS;
   comm.view = v->view;
   comm.op = op;

   switch ( op ) {
      case VIEW_OP_CANCEL :
      case VIEW_OP_CLOSE :
      case VIEW_OP_DELETE :
      case VIEW_OP_FETCH :
      case VIEW_OP_FETCH_LOCK :
      case VIEW_OP_INITIALIZE :
      case VIEW_OP_INSERT :
      case VIEW_OP_PROCESS :
      case VIEW_OP_READ :
      case VIEW_OP_READ_LOCK :
      case VIEW_OP_TABLE_EMPTY :
      case VIEW_OP_UNLOCK :
      case VIEW_OP_UPDATE :
      case VIEW_OP_VERIFY :
         MaxError (&e, viewCall (v->rvh, &comm, sizeof (ROTOVIEW)));
         break;

      case VIEW_OP_POST:
      case VIEW_OP_REVISION_POST :
         if ( lpv->RotoView!=NULL && lpv->RotoView->op==VIEW_OP_DELETE ) {
            CHECK_CALL (e, DeleteDetailsBody (lpv, cmp));
         }
         if ( op==VIEW_OP_REVISION_POST ) {
            comm.i = va_arg (arguments, INT);
         }
         if ( DETAILS_ARE_REVISIONED ) {
            MaxError (&e, viewCall (v->rvh, &comm, sizeof (ROTOVIEW)));
         }
         break;

      case VIEW_OP_FILTER_DELETE:
         lpv->filterExpressionCast = cmp;
         filter = va_arg (arguments, LPFILTER);
         if ( filter==NULL )
            range = NULL;
         else {
            WORD opFilter = FILTER_OP_EXPRESSION;
            FL_ERRNUM f = filterExpression (lpv, filter, detailName, &range);

            RVSPYTRACE (range);
            filterErrorV (lpv, opFilter, f);
            MaxError (&e, ErrorMapFilterToExtended (opFilter, f));
            if ( ERRNUM_IS_FAILURE (e) )
               break;
         }
         comm.p = range;
         comm.dw = va_arg (arguments, A4W_FLAGS);
         MaxError (&e, viewCall (v->rvh, &comm, sizeof (ROTOVIEW)));
         filterExprFree (range);
         break;

      case VIEW_OP_ORDER :
      case VIEW_OP_REVISION_CANCEL :
         comm.i = va_arg (arguments, INT);
         MaxError (&e, viewCall (v->rvh, &comm, sizeof (ROTOVIEW)));
         break;

      case VIEW_OP_REVISION_REKEY  :
          comm.p = va_arg (arguments, LPVOID);
          comm.q = va_arg (arguments, LPVOID);
          comm.i = va_arg (arguments, INT);
          comm.dw = va_arg (arguments, A4W_FLAGS);
          MaxError (&e, viewCall (v->rvh, &comm, sizeof (ROTOVIEW)));
          break;

      //case VIEW_OP_ATTRIBUTES :
      //case VIEW_OP_BLKGET :
      //case VIEW_OP_BLKPUT :
      //case VIEW_OP_BROWSE :
      //case VIEW_OP_COMPOSE :
      //case VIEW_OP_COMPOSITES :
      //case VIEW_OP_CREATE :
      //case VIEW_OP_DIRTY :
      //case VIEW_OP_DROP :
      //case VIEW_OP_EXISTS :
      //case VIEW_OP_FETCH :
      //case VIEW_OP_FETCH_LOCK :
      //case VIEW_OP_FIELD :
      //case VIEW_OP_FIELDS :
      //case VIEW_OP_FILTER_COUNT :
      //case VIEW_OP_FILTER_FETCH :
      //case VIEW_OP_FILTER_SELECT :
      //case VIEW_OP_GET :
      //case VIEW_OP_INSTANCE_NOTIFY :
      //case VIEW_OP_INSTANCE_OPEN :
      //case VIEW_OP_INSTANCE_PROTOCOL :
      //case VIEW_OP_INSTANCE_SECURITY :
      //case VIEW_OP_KEY :
      //case VIEW_OP_KEYS :
      //case VIEW_OP_NAME :
      //case VIEW_OP_OPEN :
      //case VIEW_OP_PRESENTATION :
      //case VIEW_OP_PUT :
      //case VIEW_OP_READ :
      //case VIEW_OP_READ_LOCK :
      //case VIEW_OP_REVISION_EXISTS :
      //case VIEW_OP_REVISION_UNPOSTED :
      //case VIEW_OP_SECURITY :
      //case VIEW_OP_TYPE :
      default:
         // should an error be report here?
         // @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
         // e = 104;
         MaxError (&e, viewCall (v->rvh, &comm, sizeof (ROTOVIEW)));
         break;
   }
   return e;
}



ERRNUM MapToDetails (LPV lpv, INT op, ...)
{
   ERRNUM e = ERRNUM_SUCCESS;
   INT c;
   va_list arguments;

   if ( DTL_CMP_COUNT==0 )
      return ERRNUM_SUCCESS;

   va_start (arguments, op);
   for ( c=HDR_CMP_COUNT; ERRNUM_IS_SUCCESS (e) && c<HDR_CMP_COUNT+DTL_CMP_COUNT; c++ ) {
      MaxError (&e, ErrorMapViewToExtended (op, MapToDetail (lpv, op, c, arguments)));
   }
   va_end (arguments);
   return e;
}



// This function should NEVER be called from scInitPost or scInitCancel entrypoints
VIEWBASE MapToNestedDetails (LPV lpv, INT op)
{
   ERRNUM e = ERRNUM_SUCCESS;
   INT nested = op;

   if ( HAS_REVISIONS!=NO_REVISIONS ) {
      switch ( op ) {
         case VIEW_OP_POST:
            nested = VIEW_OP_REVISION_POST;
            break;
         case VIEW_OP_CANCEL:
            nested = VIEW_OP_REVISION_CANCEL;
            break;
      }
   }

   if ( op==nested ) {
      MaxError (&e, MapToDetails (lpv, op));
   } else {
      MaxError (&e, MapToDetails (lpv, nested, 2+HDR_HAS_REVISIONS));
   }
   return e;
}



#if defined(DO_HELPERSOUTOFLINE)

INT WINAPI MapToInternalComposite (INT c)
{
   return DoMapToInternalComposite (c);
}



LONG WINAPI MapToNewFieldIndex (LONG field)
{
   return DoMapToNewFieldIndex (field);
}



void WINAPI MaxDatabaseError (DB_ERRNUM *p, DB_ERRNUM d)
{
   DoMaxDatabaseError (p, d);
}



void WINAPI MaxError (LPERRNUM p, ERRNUM e)
{
   DoMaxError (p, e);
}

#endif



#if defined(DO_CONCURRENCYETC)

VIEWBASE MergeConflictedRecords (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;
   DB_ERRNUM d = DBS_SUCCESS;
   INT i, fields = 0;
   LPDATUM mine, old, New;
   BOOL I, You; // "...if I or You changed it..."
   LONG f;
   LPDBFIELD def;
   FIELDCOMPARATOR comparator;
   BOOL set;

   if ( !(SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS) )
      return e;

   for ( i=0; i<FLD_IDX_COUNT; i++ ) {
      f = * FindFieldIndexV (lpv, i);
      def = FindFieldDefV (lpv, f);
      comparator = aTypeComparators [def->wType];
      VIEWASSERT (comparator!=NULL);
      mine = (LPDATUM) FindFieldValueAux (lpv, f, FindRecord (lpv));
      New = (LPDATUM) FindFieldValueAux (lpv, f, FindRecordTemp (lpv));
      old = (LPDATUM) FindFieldValueAux (lpv, f, FindRecordRead (lpv));
      I = (* comparator) (def, old, mine) != 0;
      You = (* comparator) (def, old, New) != 0;
      if ( I && !You )
         blkCopy (New, mine, def->wLength);
      set = AttribTest (lpv, f, ATTR_CALCULATE);
      CHECK_CALL (e, lpv->eValidation);
      if ( !set ) {
#if defined(DO_OLDOPTIMISTIC)
         set = You && I;
#else
         set = You;
#endif
      }
      if ( set ) {
         lpv->conflicts[fields].field = f;
         lpv->conflicts[fields].conflict = (I && You);
         AttribSet (lpv, f, ATTR_CHANGED);
         fields++;
      }
   }
   d = ConcurrencyEtc (lpv, fields);
   if ( DB_ERRNUM_IS_FAILURE (d) )
      ReportGenericError (lpv, ERRGEN_AREA_DATABASE, 0, d, NULL);
   CHECK_CALL (e, ErrorMapDatabaseToExtended (lpv->wLinkNo, d));
   SwapRecords (FindRecordTemp (lpv), FindRecord (lpv));
   MaxError (&e, ErrorMapViewToExtended (VIEW_OP (lpv, OPEN),
                                         ERROR_FROM_CALLOUT (CalculateFields (lpv))));
   if ( ERRNUM_IS_FAILURE (e) ) {
      SwapRecords (FindRecordTemp (lpv), FindRecord (lpv));
      return e;
   }
   lpv->bVerified = FALSE; // Breaks convention being in a file function
   MaxError (&e, xxxVerify ((LPVOID) lpv, FALSE));
   if ( ERRNUM_IS_FAILURE (e) ) {
      SwapRecords (FindRecordTemp (lpv), FindRecord (lpv));
      return e;
   }

   return e;
}

#endif



VIEWBASE NormalizeFieldBuffer (LPV lpv, LONG field, LPSTR input, INT size, LPSTR output, LPBOOL mask_error)
{
   LPDBFIELD f = FindFieldDefV (lpv, field);
   LPPRESENTATION p = FindPresentsInfo (lpv, field);
   LPSTR intermediate;
   INT i;

   *mask_error = FALSE;

   intermediate = (LPSTR) _alloca (f->wLength + 1);
   if ( !intermediate ) {
      ReportMemoryError (lpv, MAKE_OP_RSC (VIEW_OP (lpv, OPEN)));
      return ERRNUM_MEMORY_NO_MORE;
   }

   // Check whether there are difficulties with the source buffer
   if ( !ValidateBuffer (lpv, field, size) )
      return ERRNUM_MEMORY_BUFFER_LIMIT;

   // Pad the data sent in to the appropriate field length
   switch ( f->wType ) {
      case FT_CHAR:
         InitFieldBuffer (intermediate, f->wType, f->wLength);
         for ( i=0; i<size && i<(INT)f->wLength && input[i]!=0; ++i )
            intermediate[i] = input[i];
         blkCopy (output, intermediate, f->wLength);
         break;

      case FT_BCD:
         if ( size<(INT) f->wLength ) {
            // handle a shorter value than field
            bcdAssign ((LPDBSNUMBER) intermediate, f->wLength, f->wDecimals,
                       (LPDBSNUMBER) input, size, f->wDecimals, FALSE);
         }
         else {
            // what happens if supplied value is longer than field - truncation!
            blkCopy (intermediate, input, f->wLength);
         }
         // convert unsigned bcd to signed bcd
         if ( bcdCompareZero ((LPDBSNUMBER) intermediate, f->wLength)>=0 ) {
            bcdAbsolute ((LPDBSNUMBER) intermediate, f->wLength);
         }
         blkCopy (output, intermediate, f->wLength);
         break;

      default:
         if ( size<(INT) f->wLength ) {
            // handle a shorter value than field
            InitFieldBuffer (output, f->wType, f->wLength);
            blkCopy (output, input, size);
         }
         else {
            // what happens if supplied value is longer than field - truncation!
            blkCopy (output, input, f->wLength);
         }
         break;
   }

   // Format data against any mask present for the field
   if ( p!=NULL && p->type==PRESENTS_MASK )
      *mask_error = !ApplyMask (lpv, field, p, output, f->wLength);

   return ERRNUM_SUCCESS;
}



// Need to decide what to do with failed nofications

VIEWBASE NotifyAdd (LPV lpv, A4W_NOTIFY_PROC notify, LPVOID context, A4W_FLAGS flags)
{
   ERRNUM e = ERRNUM_SUCCESS;
   LPNOTIFYCONTEXT n = (LPNOTIFYCONTEXT) memAlloc (sizeof (NOTIFYCONTEXT));

   if ( n==NULL ) {
      ReportMemoryError (lpv, MAKE_OP_RSC(VIEW_OP_INSTANCE_NOTIFY));
      return ERRNUM_MEMORY_NO_MORE;
   }
   n->notify = notify;
   n->context = context;
   n->flags = flags & ~MASK_INSTANCE_NOTIFY_OPERATION;
   n->lpv = lpv;
   n->next = NULL;
   *lpv->NextNotifyList = n; // strange behaviour on forward declaration
   lpv->NextNotifyList = &n->next;
   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
      MaxError (&e, viewInstanceNotify ((LPRVH) lpv->subCmp.rvh, lpv->subCmp.view,
                                        BaseNotify, n, flags));
   }
   return e;
}



VIEWBASE NotifyClose (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;
   int c;
   LPVIEWDEF v;
   LPCMPNAME d;

   // Free the list of outgoing notifications
   while ( lpv->NotifyList!=NULL ) {
      LPNOTIFYCONTEXT n = lpv->NotifyList;

      if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
         MaxError (&e, viewInstanceNotify ((LPRVH) lpv->subCmp.rvh, lpv->subCmp.view,
                                           BaseNotify, n, INSTANCE_NOTIFY_REMOVE));
      }
      lpv->NotifyList = n->next;
      memFree (n);
   }
   lpv->NotifyList = NULL;
   lpv->NextNotifyList = &lpv->NotifyList;

   // Free the incoming notifications
   for ( c=0; c<EXP_CMP_COUNT; ++c ) {
      if ( c>=EXP_CMP_COUNT-DMND_CMP_COUNT && * FindImpOpen (lpv, c) )
         continue;
      v = FindCmp (lpv, c);
      if ( v->view==NULL )
         continue;
      d = FindCmpDef (c);
      if ( (d && (d->options & CMPNAME_OPTION_NOTIFY)) ||
           (HDR_HAS_REVISIONS>0 && c==0) ) {
         MaxError (&e, viewInstanceNotify ((LPRVH) v->rvh, v->view, CompositeNotifyEntry,
                                           FindCmpNotify (lpv, c), INSTANCE_NOTIFY_REMOVE));
         // Don't return immediately if there is an error. We are inside of
         // scInitClose, so we have to try to clear away everything.
      }
   }

   return e;
}



VIEWBASE NotifyFieldAttributes (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;
   INT i;

   if ( NULL==lpv->NotifyList )
      return e;
   for ( i=0; i<FLD_IDX_COUNT; i++ ) {
      LONG idx = * FindFieldIndexV (lpv, i);

      if ( (~ATTR_CHANGED & lpv->alAttributes[IDXIDX(idx)]) !=
           (~ATTR_CHANGED & lpv->attributesNotify[IDXIDX(idx)]) ) {
         LONG attribs = AttribGet (lpv, idx);

         CHECK_CALL (e, lpv->eValidation);
         CHECK_CALL (e, NotifyFire (lpv, INSTANCE_NOTIFY_FIELD_ATTRIBUTES,
                                    idx, (LPVOID) attribs));
         lpv->QueuedNotifyField[IDXIDX(idx)] &= ~NOTIFY_QUEUE_FIELD_ATTRIBUTES;
      }
   }
   return e;
}



VIEWBASE NotifyFieldValues (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;
   INT i;
   LPIDXMAP f;
   LPSTR *after;
   LPSTR *before;

   if ( NULL==lpv->NotifyList )
      return e;
   f = FindFieldMapV (lpv, 0);
   after = FindRecord (lpv);
   before = FindRecordNotify (lpv);
   for ( i=0; i<IDXIDX(FLD_IDX_LIMIT); i++ ) {
      if ( f->tblNo>=0 ) {
         if ( !(lpv->alAttributes[i] & ATTR_NULL) ) {
            LPDBFIELD def = FindTableMapV (lpv, f->tblNo)->fields + f->tblFieldNo;

            if ( blkCompare (before[f->tblNo] + def->wOffset,
                             after[f->tblNo] + def->wOffset, def->wLength) != 0 ) {
               CHECK_CALL (e, NotifyQueueFieldValue (lpv, MAKEIDX(i), def));
               CHECK_CALL (e, NotifyFire (lpv, INSTANCE_NOTIFY_FIELD_VALUE,
                                          MAKEIDX(i), (LPVOID) def->wLength));
            }
         }
      }
      ++f;
   }
   return e;
}



VIEWBASE NotifyFireBase (LPV lpv, LONG reason, LONG info, LPVOID extra)
{
   ERRNUM e = ERRNUM_SUCCESS;
   LPNOTIFYCONTEXT n = lpv->NotifyList;

   while ( n!=NULL ) {
      ERRNUM f = ERRNUM_SUCCESS;

      RVSPYNOTIFY (lpv, "NOTIFICATION FROM", reason, info, extra, n->context);
      RVSPYINDENT (1);
      f = (* n->notify) (n->context, reason, lpv->rotoID,
                         info, extra, lpv->myself, lpv->myself);
      RVSPYINDENT (-1);
      MaxError (&e, ErrorMapViewToExtended (VIEW_OP (lpv, OPEN), f));
      n = n->next;
   }
   return e;
}



VIEWBASE NotifyQueuedFields (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;
   INT i;

   if ( NULL==lpv->NotifyList )
      return e;
   if ( !lpv->FieldsWereQueued )
      return e;

   for ( i=0; i<FLD_IDX_COUNT; i++ ) {
      LONG idx = * FindFieldIndexV (lpv, i);
      A4W_FLAGS flags = lpv->QueuedNotifyField[IDXIDX(idx)];

      if ( flags & NOTIFY_QUEUE_FIELD_ATTRIBUTES ) {
         LONG attribs = AttribGet (lpv, idx);

         CHECK_CALL (e, lpv->eValidation);
         CHECK_CALL (e, NotifyFire (lpv, INSTANCE_NOTIFY_FIELD_ATTRIBUTES,
                                    idx, (LPVOID) attribs));
      }
      if ( flags & NOTIFY_QUEUE_FIELD_PRESENTATION ) {
         CHECK_CALL (e, NotifyFire (lpv, INSTANCE_NOTIFY_FIELD_PRESENTATION,
                                    idx, NULL));
      }
   }
   return e;
}



VIEWBASE NotifyQueueField (LPV lpv, LONG field, LONG reason)
{
   ERRNUM e = ERRNUM_SUCCESS;

   if ( NULL==lpv->NotifyList )
      return e;
   switch ( reason ) {
      case INSTANCE_NOTIFY_FIELD_ATTRIBUTES:
         lpv->QueuedNotifyField[IDXIDX(field)] |= NOTIFY_QUEUE_FIELD_ATTRIBUTES;
         lpv->FieldsWereQueued = TRUE;
         break;
      case INSTANCE_NOTIFY_FIELD_PRESENTATION:
         lpv->QueuedNotifyField[IDXIDX(field)] |= NOTIFY_QUEUE_FIELD_PRESENTATION;
         lpv->FieldsWereQueued = TRUE;
         break;
      default:
         break;
   }
   return e;
}



VIEWBASE NotifyQueueFieldValues (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;
   INT i;
   LPIDXMAP f;
   LPSTR *after;
   LPSTR *before;

   if ( !DO_NOTIFYQUEUEFIELDVALUE )
      return e;
   if ( NULL==lpv->NotifyList )
      return e;

   f = FindFieldMapV (lpv, 0);
   after = FindRecord (lpv);
   before = FindRecordNotify (lpv);
   for ( i=0; i<IDXIDX(FLD_IDX_LIMIT); i++ ) {
      if ( f->tblNo>=0 ) {
         if ( !(lpv->alAttributes[i] & ATTR_NULL) ) {
            LPDBFIELD def = FindTableMapV (lpv, f->tblNo)->fields + f->tblFieldNo;

            if ( blkCompare (before[f->tblNo] + def->wOffset,
                             after[f->tblNo] + def->wOffset, def->wLength) != 0 ) {
               CHECK_CALL (e, NotifyQueueFieldValue (lpv, MAKEIDX(i), def));
            }
         }
      }
      ++f;
   }
   return e;
}



VIEWBASE NotifyRemove (LPV lpv, A4W_NOTIFY_PROC notify, LPVOID context)
{
   ERRNUM e = ERRNUM_SUCCESS;
   LPNOTIFYCONTEXT FAR *n = &lpv->NotifyList;

   while ( *n!=NULL && !((*n)->notify==notify && (*n)->context==context) )
      n = &(*n)->next;
   if ( *n!=NULL ) {
      LPNOTIFYCONTEXT removee = *n;

      if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
         MaxError (&e, viewInstanceNotify ((LPRVH) lpv->subCmp.rvh, lpv->subCmp.view,
                                           BaseNotify, removee, INSTANCE_NOTIFY_REMOVE));
      }
      *n = removee->next;
      if ( removee->next==NULL )
         lpv->NextNotifyList = n;
      memFree (removee);
   }
   return e;
}



VIEWBASE OpenBody (
   LPRVH myself,
   HPIB hPIB,
   WORD wLinkNo,
   A4W_FLAGS flags,
   LPVOID extra,
   A4W_SIZE size,
   LPV FAR * lplpv)
{
   LPV lpv;
   ERRNUM e = ERRNUM_SUCCESS;
   DB_ERRNUM d = DBS_SUCCESS;
   INT nLogTbl;
   WORD keys = 0;
   DBTABLE info;
   LPSTR p;
   WORD LinkFlags;
   INT i = 0;
   LPKEYMAP k = NULL;
   LPREVLEVEL revLevel = NULL;

   if ( extra==NULL || size==0 ) {
      extra = NULL;
      size = 0;
   }
   ALLOCATE_STRUCT (&lpv, V);
   if ( lpv==NULL ) {
      ReportMemoryError (lpv, MAKE_OP_RSC(VIEW_OP_OPEN));
      return ERRNUM_MEMORY_NO_MORE;
   }

   lpv->hpib = hPIB;
   lpv->wLinkNo = wLinkNo;
   lpv->myself = myself;
   lpv->bReadOnly = FALSE;
   lpv->bUnvalidated = FALSE;
   lpv->bRevisioned = FALSE;
   lpv->bRawData = FALSE;
   lpv->bCascades = TRUE;
   lpv->bInherits = TRUE;
   lpv->wFetchCount = (WORD) (flags & MASK_INSTANCE_OPEN_PREFETCH);
   if ( lpv->wFetchCount==0 )
      lpv->wFetchCount = DO_FETCHCOUNT;
   if ( (flags & MASK_INSTANCE_OPEN_RAW)==INSTANCE_OPEN_RAW )
      lpv->bRawData = TRUE;
   if ( (flags & MASK_INSTANCE_OPEN_CASCADE)==INSTANCE_OPEN_NOCASCADE )
      lpv->bCascades = FALSE;
   if ( (flags & MASK_INSTANCE_OPEN_INHERIT)==INSTANCE_OPEN_NOINHERIT )
      lpv->bInherits = FALSE;
   lpv->OpenFlags = flags;
   lpv->rotoID = 0L;
   lpv->NextNotifyList = &lpv->NotifyList;
   lpv->bCheckDuplicates = TRUE;
#if defined(SCINIT_ROTOID)
   utlObjStrToID (SCINIT_ROTOID, &lpv->rotoID);
#endif

   if ( HDR_HAS_REVISIONS>0 ) {
      k = FindKeyDef (0);
      revLevel = FindRevLevel (lpv, HDR_HAS_REVISIONS);
      revLevel->HeaderKeySegments = k->segments - DTL_SEG_COUNT;
      revLevel->DetailKeySegments = DTL_SEG_COUNT;
      for ( i=0; i<k->segments-DTL_SEG_COUNT; ++i )
         revLevel->iHdrPKeySize += FindFieldDefV (lpv, k->indexes[i])->wLength;
      for ( i=1; i<=HDR_HAS_REVISIONS-1; ++i ) {
         LPREVLEVEL parent = FindRevLevel (lpv, i);
         parent->HeaderKeySegments = revLevel->HeaderKeySegments;
         parent->DetailKeySegments = revLevel->DetailKeySegments;
         parent->iHdrPKeySize = revLevel->iHdrPKeySize;
      }
   }

   lpv->OpenExtraSize = size;
   if ( extra!=NULL && size!=0 ) {
      lpv->OpenExtra = memAlloc (size);
      if ( lpv->OpenExtra==NULL ) {
         ReportMemoryError (lpv, MAKE_OP_RSC(VIEW_OP_OPEN));
         e = ERRNUM_MEMORY_NO_MORE;
         DEALLOCATE_STRUCT (lpv);
         return e;
      }
      blkCopy (lpv->OpenExtra, extra, size);
   }

   for ( i=0; i<CMP_COUNT+MAN_CMP_COUNT; ++i ) {
      LPCMPNOTIFYCONTEXT n = FindCmpNotify (lpv, i);
      n->lpv = lpv;
      n->composite = i;
   }

   lpv->SeriesInfo.wSize = sizeof (lpv->SeriesInfo);
   smGetSeriesInfo (&lpv->SeriesInfo);
   MaxDatabaseError (&d, lnkGetOrgID (wLinkNo, lpv->OrgID));
   if ( DB_ERRNUM_IS_FAILURE (d) ) {
      dbError (wLinkNo, hPIB, d);
   } else {
      MaxDatabaseError (&d, lnkIsSecEnabled (wLinkNo, &lpv->bSecEnabled));
      if ( DB_ERRNUM_IS_FAILURE (d) ) {
         dbError (wLinkNo, hPIB, d);
      } else {
         MaxDatabaseError (&d, lnkGetOrgType (wLinkNo, &lpv->wOrgType));
         if ( DB_ERRNUM_IS_FAILURE (d) ) {
            dbError (wLinkNo, hPIB, d);
         } else {
#if defined(DO_LOADCOMPANYINFO)
            if ((ORG_TYPE_COMPANY == lpv->wOrgType) || (ORG_TYPE_COMBINED == lpv->wOrgType))
               cpGetCompanyInformation (hPIB, wLinkNo, &lpv->CompanyInfo, sizeof (lpv->CompanyInfo));
#endif
            MaxDatabaseError (&d, fileLinkFlags (wLinkNo, hPIB, &LinkFlags));
            if ( DB_ERRNUM_IS_SUCCESS (d) ) {
               if ( LinkFlags & FLG_READONLY )
                  lpv->bReadOnly = TRUE;
               else if ( (flags & MASK_INSTANCE_OPEN_READ)==INSTANCE_OPEN_READONLY )
                  lpv->bReadOnly = TRUE;
               if ( !lpv->bReadOnly ) {
                  if ( (flags & MASK_INSTANCE_OPEN_VALIDATED)==INSTANCE_OPEN_UNVALIDATED )
                     lpv->bUnvalidated = TRUE;
                  if ( HAS_REVISIONS!=NO_REVISIONS &&
                       (flags & MASK_INSTANCE_OPEN_REVISIONED)==INSTANCE_OPEN_REVISIONED )
                     lpv->bRevisioned = TRUE;
               }
               MaxDatabaseError (&d, fileOpen (wLinkNo, hPIB, lpv));
               if ( DB_ERRNUM_IS_SUCCESS (d) ) {
                  lpv->sysAccess = SYSACCESS_NORMAL;
                  lpv->refIntegrity = REFINT_CASCADE;
                  for ( nLogTbl=0; nLogTbl<BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT; nLogTbl++ ) {
                     WORD length = FindTableWidth (lpv, nLogTbl);

                     if ( ((FindRecord (lpv)) [nLogTbl] = (LPSTR) memAlloc (length))==NULL )
                        break;
                     if ( ((FindRecordTemp (lpv)) [nLogTbl] = (LPSTR) memAlloc (length))==NULL )
                        break;
                     if ( ((FindRecordNotify (lpv)) [nLogTbl] = (LPSTR) memAlloc (length))==NULL )
                        break;
#if defined(DO_RECORDREAD) || defined(DO_CONCURRENCYETC)
                     if ( ((FindRecordRead (lpv)) [nLogTbl] = (LPSTR) memAlloc (length))==NULL )
                        break;
#endif
                  }
                  if ( nLogTbl>=BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT ) {
                     MaxError (&e, InitFieldStruct (lpv));
                     if ( ERRNUM_IS_SUCCESS (e) ) {
#if !defined(DO_LAZYPUT)
                        MaxError (&e, OpenImpViews (lpv));
#endif
                        if ( ERRNUM_IS_SUCCESS (e) ) {
                           MaxDatabaseError (&d,
                              RevisionGenerate (lpv, FindRevCache (lpv), (LPREVISION) NULL));
                           if ( DB_ERRNUM_IS_SUCCESS (d) ) {
                              MaxDatabaseError (&d, RevisionCreate (lpv));
                              if ( DB_ERRNUM_IS_SUCCESS (d) ) {
                                 RevisionSpyLevels (lpv);
                                 lpv->bVerifying = FALSE;
                                 fileInfo (wLinkNo, hPIB, 0, &info);
                                 lpv->wNoOfKeys = info.wNoOfKeys;
                                 lpv->wPrimaryRecordLength = info.wRecordLength;
                                 MaxError (&e, ERROR_FROM_CALLOUT (InitBodyGen (lpv, INITBODYGEN_NOINSERT |
                                                                                     INITBODYGEN_NOGENERATE |
                                                                                     INITBODYGEN_OLDOPEN)));
                                 if ( ERRNUM_IS_SUCCESS (e) ) {
                                    if ( SUBCLASS_LEVEL!=NOT_SUBCLASS )
                                       keys = lpv->subKeys;
                                    MaxError (&e, OrderBody (lpv, keys, 0));
                                    if ( ERRNUM_IS_SUCCESS (e) ) {
                                       MaxError (&e, FlagKeyAux (lpv, 0, keys, TRUE, ATTR_REQUIRED));
                                       if ( ERRNUM_IS_SUCCESS (e) ) {
                                          MaxError (&e, BrowseBody (lpv, NULL, TRUE));
                                          if ( ERRNUM_IS_SUCCESS (e) ) {
                                             DBDRVRINFO DriverInfo;

                                             MaxDatabaseError (&d, fileDriverInfo (wLinkNo, hPIB, &DriverInfo));
                                             if ( DB_ERRNUM_IS_SUCCESS (d) ) {
                                                lpv->wDriverID = DriverInfo.driverID;
                                                lpv->fetchedRecords = (LPSTR) memAlloc (lpv->wFetchCount*lpv->wPrimaryRecordLength);
                                                if ( lpv->fetchedRecords!=NULL ) {
                                                   MaxError (&e, OpenEtc (lpv));
                                                   if ( ERRNUM_IS_SUCCESS (e) ) {
                                                      MaxError (&e, ERROR_FROM_CALLOUT (InitBodyGen (lpv, INITBODYGEN_NOINSERT |
                                                                                                          INITBODYGEN_NOGENERATE |
                                                                                                          INITBODYGEN_OPENETC)));
                                                      if ( ERRNUM_IS_SUCCESS (e) ) {
                                                         *lplpv = lpv;
                                                         return e;
                                                      }
                                                   }
                                                   memFree (lpv->fetchedRecords);
                                                } else {
                                                   ReportMemoryError (lpv, MAKE_OP_RSC(VIEW_OP_OPEN));
                                                   e = ERRNUM_MEMORY_NO_MORE;
                                                }
                                             }
                                          }
                                       }
                                    }
                                 }
                              }
                              RevisionCancel (lpv, FindRevCache (lpv));
                           }
                           CloseImpViews (lpv);
                        }
                     }
                  } else {
                     ReportMemoryError (lpv, MAKE_OP_RSC(VIEW_OP_OPEN));
                     e = ERRNUM_MEMORY_NO_MORE;
                     nLogTbl++; // Done so that following loop catches all allocations
                  }
                  while ( nLogTbl-- ) {
                     // NOTE THAT IT IS ASSUMED memAlloc() INITIALIZES THE BUFFER
                     if ( p = (FindRecord (lpv)) [nLogTbl] )
                        memFree (p);
                     if ( p = (FindRecordTemp (lpv)) [nLogTbl] )
                        memFree (p);
                     if ( p = (FindRecordNotify (lpv)) [nLogTbl] )
                        memFree (p);
#if defined(DO_RECORDREAD) || defined(DO_CONCURRENCYETC)
                     if ( p = (FindRecordRead (lpv)) [nLogTbl] )
                        memFree (p);
#endif
                  }
                  fileClose (lpv);
               }
            }
         }
      }
   }

   if ( lpv->OpenExtra!=NULL )
      memFree (lpv->OpenExtra);
   DEALLOCATE_STRUCT (lpv);
   MaxError (&e, ErrorMapDatabaseToExtended (wLinkNo, d));
   return e;
}



VIEWBASE OpenImpViews (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;
   INT nCmp;

   if ( IMP_CMP_COUNT==0 )
      return e;

   for ( nCmp = EXP_CMP_COUNT; nCmp < CMP_COUNT; nCmp++ ) {
      LPCMPNAME d = FindCmpDef (nCmp);

      if ( NULL==d || !(d->options & CMPNAME_OPTION_VIEWPOOL) ) {
          MaxError (&e, OpenOneView (lpv, nCmp));
          if ( ERRNUM_IS_FAILURE (e) ) {
             while ( nCmp-- > EXP_CMP_COUNT )
                CloseOneView (lpv, nCmp);
             return e;
          }
      }
   }
   return e;
}



VIEWBASE OpenOneView (LPV lpv, INT c)
{
   A4W_FLAGS flags;

   if ( !lpv->bInherits )
      flags = 0L;
   else {
      flags = lpv->OpenFlags;
      flags &= ~MASK_INSTANCE_OPEN_INHERIT;
      flags &= ~MASK_INSTANCE_OPEN_PREFETCH;
   }
   return OpenOneViewInstance (lpv, c, flags, NULL, 0);
}



VIEWBASE OpenOneViewInstance (
   LPV lpv,
   INT c,
   A4W_FLAGS flags,
   LPVOID extra,
   A4W_SIZE size)
{
   INT i, seg;
   CHAR sName [SIZEOF_FLDDESC];
   LPKEYMAP k = NULL;
   LPVIEWDEF v = NULL;
   ERRNUM e = ERRNUM_SUCCESS;
   WORD link;
   LPCMPNAME d = NULL;
   LPSTR rotoID = FindCmpName (c);
   CHAR version [SIZEOF_VERSION];
   BCDDATE date;

   if ( DMND_CMP_COUNT+IMP_CMP_COUNT+MAN_CMP_COUNT==0 )
      return e;

   VIEWASSERT(c>=HDR_CMP_COUNT+DTL_CMP_COUNT+HCHY_CMP_COUNT);
   if ( c<HDR_CMP_COUNT+DTL_CMP_COUNT+HCHY_CMP_COUNT )
      return e;
   VIEWASSERT(c<CMP_COUNT+MAN_CMP_COUNT);
   if ( c>=CMP_COUNT+MAN_CMP_COUNT )
      return e;

   // Collect parameters
   d = FindCmpDef (c);

   switch ( CompositeCategory (lpv, c) ) {
      case DEMAND_COMPOSITE :
      case IMPLICIT_COMPOSITE :
      case MANUAL_COMPOSITE :
         if ( d!=NULL && (d->options & CMPNAME_OPTION_VIEWPOOL) )
            return AcquireOneView (lpv, c);
         break;
      default:
         break;
   }

   v = FindCmp (lpv, c);
   if ( v->view!=NULL )
      return ERRNUM_SUCCESS;
   CHECK_CALL (e, LoadOneView (lpv, c));
   if ( DMND_CMP_COUNT+IMP_CMP_COUNT>0 &&
        c<EXP_CMP_COUNT+IMP_CMP_COUNT )
      // done only on DMND_CMP_COUNT and IMP_CMP_COUNT
      k = FindKeyMap (c);

   link = lpv->wLinkNo;
   if ( d!=NULL )
      flags |= d->flags;
   else if ( k )
      flags |= k->flags;
   if ( (d!=NULL && d->system) || (k && k->system) )
   {
      if ( ORG_TYPE_COMBINED == lpv->wOrgType )
         link = ibGetCmpLinkNo(lpv->hpib);
      else
         link = ibGetSysLinkNo(lpv->hpib);
   }

   // Check whether .InstanceOpen may, or must, be used
   CHECK_CALL (e, GetTemplateVersion (lpv, rotoID, v, version, date));
   if ( blkCompare (version, "42A", sizeof (version))<0 &&
        (NULL==extra || 0==size) ) {
      MaxError (&e, viewOpen (v->rvh, lpv->hpib, link, &v->view));
   } else {
      MaxError (&e, viewInstanceOpen ((LPRVH) v->rvh, lpv->hpib, link,
                                      flags, extra, size, &v->view));
   }
   if ( ERRNUM_IS_FAILURE (e) ) {
      UnloadOneView (lpv, c);
      return e;
   }
   * FindImpOpen (lpv, c) = TRUE;
   MaxError (&e, GenericStub (lpv, c, FindGenStub (lpv, c)));
   if ( ERRNUM_IS_FAILURE (e) ) {
      switch ( e ) {
         case ERRNUM_LOAD_FAILED:
            ReportLoadError (lpv, rotoID);
            break;
         case ERRNUM_OPEN_FAILED:
            ReportError (lpv, (RSCID)IDERR_SC_VIEWOPEN_MSG,
                         MAKERSC(IDS_SCINIT_VIEW_NOUN), NULL, NULL);
            break;
         case ERRNUM_COMPOSE_FAILED:
            ReportError (lpv, (RSCID)IDERR_SC_VIEWCOMP_MSG,
                         MAKERSC(IDS_SCINIT_VIEW_NOUN), NULL, NULL);
            break;
      }
      CloseOneView (lpv, c);
      return e;
   }

   if ( DMND_CMP_COUNT+IMP_CMP_COUNT>0 &&
        c<CMP_COUNT ) {
      LPCMPKEY x = FindCmpKey (lpv, c);
      INT key = 0;

      if ( * FindGenStub (lpv, c) )
         return ERRNUM_SUCCESS;
      if ( k->segments==0 )
         return ERRNUM_SUCCESS;
      if ( d )
         key = d->foreign;
      else
         key = k->foreign;
      MaxError (&e, viewOrder (v->rvh, v->view, key));
      if ( ERRNUM_IS_FAILURE (e) ) {
         CloseOneView (lpv, c);
         return e;
      }
      MaxError (&e, viewKey (v->rvh, v->view, key, sName,
                             &x->segments, x->indexes));
      if ( ERRNUM_IS_FAILURE (e) ) {
         CloseOneView (lpv, c);
         return e;
      }
      if ( x->segments!=k->segments ) {
         CloseOneView (lpv, c);
         ReportCompositeKeyError (lpv, MAKE_OP_RSC(VIEW_OP (lpv, OPEN)), rotoID);
         return ERRNUM_GENERAL;
      }
      MaxError (&e, QueryKeyTypes (v, x));
      if ( ERRNUM_IS_FAILURE (e) ) {
         CloseOneView (lpv, c);
         return e;
      }
      i = k->name;
      do {
         LONG field;

         for ( seg=x->segments; seg--; ) {
            field = k->indexes [seg];
            * FindCmpForeign (lpv, field) = 1;
            * FindCmpField (lpv, c, field) = x->indexes[seg];
         }
         k++;
      } while ( i-- );
   }

   if ( d && (d->options & CMPNAME_OPTION_NOTIFY) ) {
      CHECK_CALL (e, viewInstanceNotify ((LPRVH) v->rvh, v->view, CompositeNotifyEntry,
                                         FindCmpNotify (lpv, c), INSTANCE_NOTIFY_ADD));
   }

   return e;
}



VIEWBASE OrderBody (LPV lpv, WORD keys, INT nKeyNo)
{
   ERRNUM e = ERRNUM_SUCCESS;
   FL_ERRNUM f = FL_SUCCESS;

   if ( lpv->wKey>=keys && lpv->wKey<keys+KEY_COUNT ) {
      CHECK_CALL (e, FlagKeyAux (lpv, lpv->wKey, keys, FALSE, ATTR_KEY));
   }
   lpv->wActualKey = lpv->wKey = (WORD) nKeyNo;
   if ( lpv->wKey>=keys && lpv->wKey<keys+KEY_COUNT ) {
      CHECK_CALL (e, FlagKeyAux (lpv, lpv->wKey, keys, TRUE, ATTR_KEY));
   }
   if ( lpv->wKey>=keys+KEY_COUNT )
      lpv->wActualKey -= FAKE_KEY_COUNT;
   lpv->bBrowsing = FALSE;
   lpv->bBrowseEnded = TRUE;

   // re-optimize the filter, but only if not in open
   if ( lpv->RotoView!=NULL ) {
      WORD op;

      filterFreeRanges (&lpv->filter);
      op = FILTER_OP_GET_RANGES;
      f = filterGetRanges (lpv, &lpv->filter, lpv->wKey, xxxKey);
      CHECK_CALL (e, ErrorMapFilterToExtended (op, filterErrorV (lpv, op, f)));
   }

   CHECK_CALL (e, BaseNotifyFire (
      lpv, INSTANCE_NOTIFY_INSTANCE_ORDER, nKeyNo, NULL));

   return e;
}



BOOL WINAPI paramGetBoolean (HPIB pib, WORD linkNo, LPSTR rotoIDStr, LONG paramNo, LPDBSBOOL buffer)
{
   return paramGet (pib, linkNo, rotoIDStr, paramNo, buffer, sizeof (*buffer));
}



BOOL WINAPI paramGetInteger (HPIB pib, WORD linkNo, LPSTR rotoIDStr, LONG paramNo, LPDBSINT buffer)
{
   return paramGet (pib, linkNo, rotoIDStr, paramNo, buffer, sizeof (*buffer));
}



BOOL WINAPI paramGetLong (HPIB pib, WORD linkNo, LPSTR rotoIDStr, LONG paramNo, LPDBSLONG buffer)
{
   return paramGet (pib, linkNo, rotoIDStr, paramNo, buffer, sizeof (*buffer));
}



BOOL WINAPI paramGetReal (HPIB pib, WORD linkNo, LPSTR rotoIDStr, LONG paramNo, LPDBSREAL buffer)
{
   return paramGet (pib, linkNo, rotoIDStr, paramNo, buffer, sizeof (*buffer));
}



BOOL WINAPI paramGetString (HPIB pib, WORD linkNo, LPSTR rotoIDStr, LONG paramNo, LPSTR buffer, WORD size)
{
   BOOL success = paramGet (pib, linkNo, rotoIDStr, paramNo, buffer, size);

   if ( success )
      buffer[size] = 0;
   return success;
}



void WINAPI PropagatePrimary (LPV lpv)
{
   INT i, f, t, size;
   LPKEYMAP k;
   LPSTR key;
   LONG field;

   if ( !(KEY_COUNT>0 && TBL_COUNT>1 && SUBCLASS_LEVEL==NOT_SUBCLASS) )
      return;
   k = FindKeyDef (0);
   for ( i=k->segments; i--; ) {
      field = k->indexes[i];
      key = FindFieldValue (lpv, field);
      size = FindFieldDefV (lpv, field)->wLength;
      f = FindFieldMapV (lpv, field)->tblFieldNo;
      for ( t=BASE_TBL_COUNT+1; t<BASE_TBL_COUNT+TBL_COUNT; t++ )
         blkCopy ((FindRecord (lpv)) [t] + FindTableMapV (lpv, t)->fields[f].wOffset, key, size);
   }
}



void WINAPI PropagatePrimaryField (LPV lpv, LONG field)
{
   INT i, f, t, size;
   LPKEYMAP k;
   LPSTR key;

   if ( !(KEY_COUNT>0 && TBL_COUNT>1 && SUBCLASS_LEVEL==NOT_SUBCLASS) )
      return;
   k = FindKeyDef (0);
   for ( i=k->segments; i--; )
      if ( k->indexes[i]==field ) {
         key = FindFieldValue (lpv, field);
         size = FindFieldDefV (lpv, field)->wLength;
         f = FindFieldMapV (lpv, field)->tblFieldNo;
         for ( t=BASE_TBL_COUNT+1; t<BASE_TBL_COUNT+TBL_COUNT; t++ )
            blkCopy ((FindRecord (lpv)) [t] + FindTableMapV (lpv, t)->fields[f].wOffset, key, size);
         return;
      }
}



VIEWBASE PullHeaderKey (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;
   LPVIEWDEF v = FindCmp (lpv, 0);

   if ( HDR_CMP_COUNT==0 || SUBCLASS_LEVEL!=NOT_SUBCLASS || TBL_COUNT==0 )
      return e;

   if ( v->view!=NULL && DetailKeyWithinHeader (lpv) ) {
      INT i;
      LPKEYMAP k = FindKeyDef (0);
      LPCMPKEY h = FindCmpKey (lpv, 0);
      LPSTR record = (FindRecord (lpv)) [BASE_TBL_COUNT];

      for ( i=0; i<h->segments; i++ ) {
         INT size = FindFieldDefV (lpv, k->indexes[i])->wLength;

         CHECK_CALL (e, viewGet (v->rvh, v->view, h->indexes[i], record, size));
         record += size;
      }
   }
   return e;
}



VIEWBASE PutCmpDetailSequence (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;

   if ( !(DETAILS_ARE_REVISIONED && DO_CASCADEPOST==CASCADEPOST_AFTERHEADER) )
      return e;

   if ( HAS_REVISIONS!=SEQUENCE_REVISIONS || lpv->bKeyGenerated!=GENERATEKEY_NONE ) {
      CHECK_CALL (e, MapToNestedDetails (lpv, VIEW_OP_POST));
   } else {
      LPKEYMAP k = FindKeyDef (0);
      LONG field = k->indexes [k->segments - DTL_SEG_COUNT];
      LPDBFIELD f = FindFieldDefV (lpv, field);
      LPSTR value = FindFieldValue (lpv, field);
      ////////////// The following only works for MP3 records
      INT primary = FindTableMapV (lpv, BASE_TBL_COUNT)->fields[SCINIT_FLD_AUDIT].wOffset;

      CHECK_CALL (e, MapToDetails (
         lpv, VIEW_OP_REVISION_REKEY,
         lpv->abKeyBefore, (FindRecord (lpv)) [BASE_TBL_COUNT],
         primary, (2+HDR_HAS_REVISIONS) << SHIFT_REVISION_REKEY_LEVEL));
      CHECK_CALL (e, MapToNestedDetails (lpv, VIEW_OP_POST));
      CHECK_CALL (e, ErrorMapViewToExtended (
         VIEW_OP_PUT,
         PutCmpFieldAux (lpv, field, value, f->wLength, FALSE,
                         HDR_CMP_COUNT, HDR_CMP_COUNT+DTL_CMP_COUNT)));
   }

   return e;
}



#if !defined(DO_PUTCMPFIELD)

VIEWBASE PutCmpField (LPV lpv, LONG lField, LPSTR lpBuffer, INT nSize)
{
   return PutCmpFieldAux (lpv, lField, lpBuffer, nSize,
                          FALSE, HDR_CMP_COUNT, CMP_COUNT);
}



VIEWBASE PutCmpFieldAux (LPV lpv, LONG lField, LPSTR lpBuffer, INT nSize, BOOL validate, INT from, INT to)
{
   ERRNUM e = ERRNUM_SUCCESS;
   INT c;
   LONG f;

   if ( CMP_COUNT-HDR_CMP_COUNT==0 )
      return e;
   if ( lpv->alAttributes[IDXIDX(lField)] & ATTR_NULL )
      return e;

 #if defined(VIEWDEBUG)
   // REVIEW: What is the point of doing this only when VIEWDEBUG?
   if ( from<HDR_CMP_COUNT )
      from = HDR_CMP_COUNT;
   if ( to<CMP_COUNT )
      to = CMP_COUNT;
 #endif
   for ( c=from; c<to; c++ ) {
      LPVIEWDEF v = FindCmp (lpv, c);

 #if !defined(DO_LAZYPUT)
      CHECK_CALL (e, DemandOpen (lpv, c));
 #endif
      f = * FindCmpField (lpv, c, lField);
      if ( v->view && f )
 #if defined(DO_LAZYPUT) && DMND_CMP_COUNT+IMP_CMP_COUNT>0
         if ( c<EXP_CMP_COUNT-DMND_CMP_COUNT || ! * FindImpOpen (lpv, c) )
 #endif
         {
            CHECK_CALL (e, viewPut (v->rvh, v->view, f, lpBuffer, nSize, validate));
         }
   }
   return e;
}



CALLOUTERROR PutCmpFields (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;
   INT nFld;
   LONG lField;

   if ( CMP_COUNT==0 )
      return e;

   for ( nFld=0; nFld<FLD_IDX_COUNT; ++nFld ) {
      lField = * FindFieldIndexV (lpv, nFld);
      CHECK_CALL (e, ERROR_FROM_CALLOUT (
         PutCmpField (lpv, lField, FindFieldValue (lpv, lField),
                      FindFieldDefV (lpv, lField)->wLength)));
   }
   return ERROR_RETURN_CALLOUT (e);
}

#endif



VIEWBASE PutCmpKeyBase (LPV lpv, INT cmp, INT inst, BOOL validate)
{
   ERRNUM e = ERRNUM_SUCCESS;
   LPKEYMAP k = NULL;
   LPCMPKEY x;
   LPVIEWDEF v;
   INT i;

   if ( CMP_COUNT-HDR_CMP_COUNT==0 )
      return e;
   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS )
      return e;

   if ( DMND_CMP_COUNT+IMP_CMP_COUNT>0 &&
        (cmp>=HDR_CMP_COUNT+DTL_CMP_COUNT+HCHY_CMP_COUNT && cmp<CMP_COUNT) ) {
      CHECK_CALL (e, OpenOneView (lpv, cmp));
   }
   v = FindCmp (lpv, cmp);
   if ( !v->view )
      return ERRNUM_SUCCESS;
   if ( KEY_COUNT>0 && cmp<HDR_CMP_COUNT+DTL_CMP_COUNT )
      k = FindKeyDef (0);
   if ( HCHY_CMP_COUNT+DMND_CMP_COUNT+IMP_CMP_COUNT>0 &&
        cmp>=HDR_CMP_COUNT+DTL_CMP_COUNT && cmp<EXP_CMP_COUNT+IMP_CMP_COUNT )
      // done only on HCHY_CMP_COUNT, DMND_CMP_COUNT and IMP_CMP_COUNT
      k = FindKeyMap (cmp);
   if ( k==NULL )
      return ERRNUM_SUCCESS;
   k += inst;
   if ( k->segments==0 )
      return ERRNUM_SUCCESS;
   x = FindCmpKey (lpv, cmp);

   for ( i=0; i<k->segments; ++i ) {
      LONG field;

      field = k->indexes[i];
      if ( 0L==field )
         continue;
      if ( lpv->alAttributes[IDXIDX(field)] & ATTR_NULL )
         continue;

      CHECK_CALL (e, viewPut (v->rvh, v->view, x->indexes[i],
                              FindFieldValue (lpv, k->indexes[i]),
                              FindFieldDefV (lpv, k->indexes[i])->wLength, validate));
   }
   return e;
}



VIEWBASE PutETAG (
   LPV lpv,
   LPSTR lpsBuffer,
   INT nSize)
{
   ERRNUM e = ERRNUM_SUCCESS;
   CHAR szDate [SIZEOF_ETAG_DATE + 1];
   CHAR szTime [SIZEOF_ETAG_TIME + 1];
   LPCHAR p = lpsBuffer;
   AUDITSTAMP adt;
   LPAUDITSTAMP lpadt = NULL;

   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS )
      return e;
   if ( !HAS_DATABASE_TABLES )
      return e;

   if ( nSize!=SIZEOF_ETAG )
   {
      ReportError (lpv, (RSCID)IDERR_SC_BUFFER_MSG,
                   MAKERSC(IDS_SCINIT_VIEW_NOUN), "ETAG", NULL);
      return ERRNUM_MEMORY_BUFFER_LIMIT;
   }

   strCopyZB (szDate, p, SIZEOF_ETAG_DATE);
   strToBcd  (szDate, (LPBYTE) adt.Date, sizeof(adt.Date), 0);
   p += SIZEOF_ETAG_DATE;

   strCopyZB (szTime, p, SIZEOF_ETAG_TIME);
   strToBcd  (szTime, (LPBYTE) adt.Time, sizeof(adt.Time), 0);
   p += SIZEOF_ETAG_TIME;

   blkCopy (adt.UserID, p, SIZEOF_USERID);
   p += SIZEOF_USERID;

   blkCopy (adt.OrgID, p, SIZEOF_ORGID);
   p += SIZEOF_ORGID;

   // Explicitly assumes MP3 record
   lpadt = (LPAUDITSTAMP) (FindRecord (lpv) [BASE_TBL_COUNT] +
                           FindTableMap (BASE_TBL_COUNT)->fields[SCINIT_FLD_AUDIT].wOffset);
   if ( dtDateCompare ((LPBCDDATE) adt.Date, (LPBCDDATE) lpadt->Date)!=0 ||
        bcdCompare ((PBYTE) adt.Time   , sizeof (adt.Time)   , 0,
                    (PBYTE) lpadt->Time, sizeof (lpadt->Time), 0)!=0 ||
        blkCompare (adt.UserID, lpadt->UserID, sizeof (adt.UserID))!=0 ||
        blkCompare (adt.OrgID , lpadt->OrgID , sizeof (adt.OrgID ))!=0 )
   {
      // Put the audit stamp only when it is truly changed
      *lpadt = adt;
      lpv->bDirty = TRUE;
   }

   return e;
}



VIEWBASE QueryKeyTypes (LPVIEWDEF v, LPCMPKEY k)
{
   INT i;
   ERRNUM e = ERRNUM_SUCCESS;

   for ( i=k->segments; i--; ) {
      CHECK_CALL (e, viewType (v->rvh, v->view, k->indexes[i], &k->types[i]));
   }
   return e;
}



INT WINAPI RealComparator (LPDBFIELD field, LPDATUM d1, LPDATUM d2)
{
   if ( d1->r>d2->r )
      return 1;
   if ( d1->r<d2->r )
      return -1;
   return 0;
}



void WINAPI ReleaseOneView (LPV lpv, INT c)
{
   LPCMPNAME d = FindCmpDef (c);

   if ( DMND_CMP_COUNT+IMP_CMP_COUNT+MAN_CMP_COUNT==0 )
      return;
   if ( NULL==d ) // Means DO_CMPNAMESTRUCT is not defined,
      return;     // hence acquire won't ever be requested

   VIEWASSERT(c>=HDR_CMP_COUNT+DTL_CMP_COUNT+HCHY_CMP_COUNT);
   if ( c<HDR_CMP_COUNT+DTL_CMP_COUNT+HCHY_CMP_COUNT )
      return;
   VIEWASSERT(c<CMP_COUNT+MAN_CMP_COUNT);
   if ( c>=CMP_COUNT+MAN_CMP_COUNT )
      return;

   if ( *FindImpOpen (lpv, c) ) {
      LPVIEWDEF v = FindCmp (lpv, c);

      if ( d->options & CMPNAME_OPTION_NOTIFY ) {
         viewInstanceNotify ((LPRVH) v->rvh, v->view, CompositeNotifyEntry,
                             FindCmpNotify (lpv, c), INSTANCE_NOTIFY_REMOVE);
      }
      viewRelease (v->rvh, v->view, lpv->hpib);
      v->view = NULL;
      v->rvh  = NULL;
      *FindImpOpen (lpv, c) = FALSE;
   }
}



void WINAPI ReportAssertion (LPSTR file, INT line, LPSTR expr)
{
#if defined(VIEWDEBUG)
   LPINT null = NULL;

   rvspyPrint ("%s(%d): Assertion false: %s", file, line, expr);
   if ( VIEWDEBUG==VIEWDEBUG_ASSERT_DIES || VIEWDEBUG==VIEWDEBUG_ALL )
      *null = 0xdead;
#endif
}



#define REPORT_USE_ERROR(v,e,f) \
   ReportError ((v), (RSCID)(e), MAKERSC(IDS_SCINIT_VIEW_NOUN), \
                MAKERSC(FindFieldMapV ((v), (f))->title), NULL);



void WINAPI ReportBaseLoadError (HPIB hpib, LPSTR rotoID)
{
   ReportErrorViaPIB (hpib, (RSCID)IDERR_SC_VIEWLOAD_MSG,
                      MAKERSC(IDS_SCINIT_VIEW_NOUN), rotoID, NULL);
}



void WINAPI ReportBaseMemoryError (HPIB hpib, RSCID op)
{
   ReportErrorViaPIB (hpib, (RSCID)IDERR_SC_MEMORY_MSG,
                      MAKERSC(IDS_SCINIT_VIEW_NOUN), MAKERSC(op), NULL);
}



void WINAPI ReportBufferError (LPV lpv, LONG field)
{
   REPORT_USE_ERROR (lpv, IDERR_SC_BUFFER_MSG, field);
}



void WINAPI ReportCompositeKeyError (LPV lpv, RSCID op, LPSTR rotoID)
{
   ReportError (lpv, (RSCID)IDERR_SC_CMPKEY_MSG,
                MAKERSC(IDS_SCINIT_VIEW_NOUN), MAKERSC(op), rotoID);
}



void WINAPI ReportDatumError (LPV lpv, LONG field)
{
   REPORT_USE_ERROR (lpv, IDERR_SC_DATUM_MSG, field);
}



void WINAPI ReportDisabledError (LPV lpv, LONG field)
{
   REPORT_USE_ERROR (lpv, IDERR_SC_DISABLED_MSG, field);
}



#if !defined(DO_REPORTERROR)

void WINAPI ReportError (LPV lpv, RSCID error, LPSTR a1, LPSTR a2, LPSTR a3)
{
   ReportErrorViaPIB (lpv->hpib, error, a1, a2, a3);
}

#endif



#if !defined(DO_REPORTERRORVIAPIB)

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



void WINAPI ReportFieldError (LPV lpv, INT field)
{
   CHAR value [16];

   sprintf (value, "%d", field);
   ReportError (lpv, (RSCID)IDERR_SC_FLDNUM_MSG,
                MAKERSC(IDS_SCINIT_VIEW_NOUN), value, NULL);
}



#if !defined(DO_REPORTGENERICERROR)

void WINAPI ReportGenericError (LPV lpv, WORD area, WORD op, WORD error, LPVOID extra)
{
   errPutGeneric (lpv->hpib, APPL, MAKERSC (IDS_SCINIT_VIEW_NOUN), NULL,
                  area, op, MAKERSC (ERRGEN_CAT_DEFAULT), error, extra);
}

#endif



#if !defined(DO_REPORTGENERICERRORVIAPIB)

void WINAPI ReportGenericErrorViaPIB (HPIB pib, WORD area, WORD op, WORD error, LPVOID extra)
{
   errPutGeneric (pib, APPL, MAKERSC(IDS_SCINIT_VIEW_NOUN), NULL,
                  area, op, MAKERSC (ERRGEN_CAT_DEFAULT), error, extra);
}

#endif



void WINAPI ReportIndexError (LPV lpv, LONG field)
{
   CHAR value [16];

   sprintf (value, "%ld", field);
   ReportError (lpv, (RSCID)IDERR_SC_FLDIDX_MSG,
                MAKERSC(IDS_SCINIT_VIEW_NOUN), value, NULL);
}



void WINAPI ReportKeyError (LPV lpv, INT key)
{
   CHAR value [16];

   sprintf (value, "%d", key);
   ReportError (lpv, (RSCID)IDERR_SC_KEYNUM_MSG,
                MAKERSC(IDS_SCINIT_VIEW_NOUN), value, NULL);
}



void WINAPI ReportListError (LPV lpv, LONG field)
{
   REPORT_USE_ERROR (lpv, IDERR_SC_LIST_MSG, field);
}



void WINAPI ReportLoadError (LPV lpv, LPSTR rotoID)
{
   ReportError (lpv, (RSCID)IDERR_SC_VIEWLOAD_MSG,
                MAKERSC(IDS_SCINIT_VIEW_NOUN), rotoID, NULL);
}



void WINAPI ReportMaskError (LPV lpv, LONG field)
{
   REPORT_USE_ERROR (lpv, IDERR_SC_MASK_MSG, field);
}



void WINAPI ReportMemoryError (LPV lpv, RSCID op)
{
   ReportError (lpv, (RSCID)IDERR_SC_MEMORY_MSG,
                MAKERSC(IDS_SCINIT_VIEW_NOUN), MAKERSC(op), NULL);
}



void WINAPI ReportReadonlyError (LPV lpv, LONG field)
{
   REPORT_USE_ERROR (lpv, IDERR_SC_READONLY_MSG, field);
}



void WINAPI ReportReverseError (LPV lpv)
{
   ReportError (lpv, (RSCID)IDERR_SC_FWDONLY_MSG,
                MAKERSC(IDS_SCINIT_VIEW_NOUN), NULL, NULL);
}



void WINAPI ReportRotoError (LPV lpv, INT op)
{
   CHAR value [16];

   sprintf (value, "%d", op);
   ReportError (lpv, (RSCID)IDERR_SC_VIEWCALL_MSG,
                MAKERSC(IDS_SCINIT_VIEW_NOUN), value, NULL);
}



void WINAPI ReportSecurityError (LPV lpv, RSCID op)
{
   ReportError (lpv, (RSCID)IDERR_SC_SECURITY_MSG,
                MAKERSC(IDS_SCINIT_VIEW_NOUN), MAKERSC(op), NULL);
}



void WINAPI ReportString (LPSTR message)
{
   char buffer [2048];

   if ( !message || !message[0] )
      message = "<null>";
   buffer[0] = 0;
#if defined(SCINIT_ROTOID)
   strCopy (buffer, SCINIT_ROTOID);
   strAppend (buffer, ": ");
#endif
   strAppend (buffer, "<SCINIT> ");
   strAppend (buffer, message);
   rvspyTrace (buffer);
   OutputDebugString (buffer);
   OutputDebugString ("\n\r");
}



void WINAPI ReportSubclassComposeError (LPV lpv)
{
   ReportError (lpv, (RSCID)IDERR_SC_SUBCMP_MSG,
                MAKERSC(IDS_SCINIT_VIEW_NOUN), NULL, NULL);
}

#undef REPORT_USE_ERROR



#if defined(DO_HEADERETC)

VIEWBASE ReverseHeaderFieldsBase (LPV lpv, INT op)
{
   INT i;
   ERRNUM e = ERRNUM_SUCCESS;
   LPVIEWDEF v = FindCmp (lpv, 0);
   LPSTR save = lpv->detailSave;

   if ( save==NULL )
      return e;
   for ( i=0; i<DO_HEADERETC; i++ ) {
      LPDETAILMAP map = &(FindDetailMap ()) [i];
      LONG field = map->lDetail;
      LPDBFIELD f = FindFieldDefV (lpv, field);

      if ( !(lpv->alAttributes[IDXIDX(field)] & ATTR_NULL) ) {
         RVSPYPRINT( ("Reversing summation of %10.10s", f->sName) );
         CHECK_CALL (e, ErrorMapViewToExtended (op,
             HeaderEtc (lpv, map->lHeader, op, field,
                        FindFieldValue (lpv, field), save)));
      }
      save += f->wLength;
   }
 #if defined(BATCH_VIEW) && !defined(DETAIL_VIEW)
   MaxError (&e, viewUpdate (v->rvh, v->view));
 #endif
   return e;
}

#endif



VIEWBASE RewriteRecord (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;

   if ( DO_CASCADEPOST==CASCADEPOST_AFTERHEADER &&
        blkCompare (FindRecord (lpv) [BASE_TBL_COUNT],
                    FindRecordTemp (lpv) [BASE_TBL_COUNT],
                    lpv->wPrimaryRecordLength)!=0 ) {
      CHECK_CALL (e, ErrorMapDatabaseToExtended (lpv->wLinkNo, fileUpdate (lpv)));
   }
   return e;
}



void rvspyNotify (
   LPV lpv,
   char *verb,
   LONG reason,
   LONG info,
   void *extra,
   void *context)
{
   char *rotoID = "SCINIT";
   char *symbol = "?";

 #if defined(SCINIT_ROTOID)
   rotoID = SCINIT_ROTOID;
 #endif

   switch ( reason ) {
      #define  INSTANCE_NOTIFY_(token)  \
         case INSTANCE_NOTIFY_ ## token: \
            symbol = #token; \
            break;

      INSTANCE_NOTIFY_(FIELD_VALUE              )
      INSTANCE_NOTIFY_(FIELD_PRESENTATION       )
      INSTANCE_NOTIFY_(FIELD_ATTRIBUTES         )
      INSTANCE_NOTIFY_(INSTANCE_SECURITY        )
      INSTANCE_NOTIFY_(INSTANCE_ORDER           )
      INSTANCE_NOTIFY_(INSTANCE_FILTER          )
      INSTANCE_NOTIFY_(INSTANCE_CLOSING         )
      INSTANCE_NOTIFY_(REVISION_POSTED          )
      INSTANCE_NOTIFY_(REVISION_CANCELLED       )
      INSTANCE_NOTIFY_(REVISION_POSTING         )
      INSTANCE_NOTIFY_(REVISION_EXTRACTED_RECORD)
      INSTANCE_NOTIFY_(REVISION_COMMITTED_RECORD)
      INSTANCE_NOTIFY_(RECORD_INITIALIZED       )
      INSTANCE_NOTIFY_(RECORD_RETRIEVED         )
      INSTANCE_NOTIFY_(RECORD_WRITTEN           )
      INSTANCE_NOTIFY_(RECORD_DELETING          )
      INSTANCE_NOTIFY_(RECORD_DELETED           )
      INSTANCE_NOTIFY_(RECORD_VERIFYING         )
   }

   rvspyPrint ("%s %s: view=0x%08lx, reason=%s:%ld, info=%ld, extra=0x%08lx, context=0x%08lx",
               verb, rotoID, lpv->myself, symbol, reason, info, extra, context);
}



int rvspyPrint (const char *format, ...)
{
   va_list params;
   char output [2000];
   int len;

   va_start (params, format);
   len = vsnprintf (output, sizeof(output)-3, format, params); // leave room for CR/LF/NUL
   va_end (params);
   if ( len<0 ) {
      len = sizeof(output)-3;
      output[len] = 0;
   }
   rvspyTrace (output);
   output[len++] = '\r';
   output[len++] = '\n';
   output[len] = 0;
   OutputDebugString (output);
   return len;
}



#if defined(DO_HEADERETC)

void WINAPI SaveHeaderFieldsBase (LPV lpv)
{
   INT i;
   LPDBFIELD f;
   LPSTR save;

   save = lpv->detailSave;
   if ( save!=NULL )
      for ( i=0; i<DO_HEADERETC; i++ ) {
         LONG field = (FindDetailMap ()) [i].lDetail;

         if ( !(lpv->alAttributes[IDXIDX(field)] & ATTR_NULL) ) {
            f = FindFieldDefV (lpv, field);
            blkCopy (save, FindFieldValue (lpv, field), f->wLength);
         }
         save += f->wLength;
      }
}

#endif



void WINAPI ScratchError (LPV lpv)
{
   CHAR noun [SIZEOF_FLDDESC+1];

   if ( DO_SCRATCHSTACK==0 )
      return;

   rscLoadText (lpv->hpib, APPL, IDS_SCINIT_VIEW_NOUN, noun, sizeof (noun));
   noun[SIZEOF_FLDDESC] = '\0';
   errPut (lpv->hpib, APPL, (RSCID)IDERR_SC_MEMORY_MSG, PRI_ERROR,
           noun, "", NULL);
}



void WINAPI ScratchPop (LPV lpv, LPVOID buffer)
{
   if ( DO_SCRATCHSTACK==0 )
      return;

   lpv->ScratchAllocated = (WORD) ((LPBYTE)buffer - (LPBYTE)lpv->ScratchStack);
}



LPVOID WINAPI ScratchPush (LPV lpv, INT size)
{
   LPVOID buffer = NULL;

   if ( DO_SCRATCHSTACK==0 )
      return buffer;

   VIEWASSERT(lpv->ScratchAllocated+size<=DO_SCRATCHSTACK);
   if ( lpv->ScratchAllocated + size > DO_SCRATCHSTACK )
      ScratchError (lpv);
   else {
      buffer = (LPVOID) &lpv->ScratchStack[lpv->ScratchAllocated];
      lpv->ScratchAllocated += size;
   }
   return buffer;
}



VIEWBASE SecurityPermissions (
   HPIB hpib,
   WORD wLinkNo,
   LPPERMISSIONMAP resources,
   INT count,
   LP_A4W_FLAGS permissions)
//
{
   INT i;
   LONG permitted;
   LPPERMISSIONMAP resource;

   if ( count==0 || lnkIsGlobalAccess (wLinkNo) ) {
      // QUESTION: SHOULD WE BE USING: ~0L ??????????
      *permissions = (SEC_ADD | SEC_MODIFY | SEC_DELETE | SEC_INQUIRE | SEC_POST);
      return ERRNUM_SUCCESS;
   }
   *permissions = 0;
   for ( i=0; i<count; i++ ) {
      permitted = ~ 0L;
      for ( resource=&resources[i]; resource; resource=resource->AndResources )
         if ( resource->lpsResource==NULL ||
              secCheck (hpib, wLinkNo, (LPBYTE) resource->lpsResource) ) {
            permitted &= resource->lPermission;
         } else
            permitted = 0L;
      *permissions |= permitted;
   }
   return ERRNUM_SUCCESS;
}



ERRNUM SelectionCancel (LPV lpv)
{
   ERRNUM e = ERRNUM_SUCCESS;

   if ( NULL==lpv->pViewSelection )
      return e;
   ClearAttribs (lpv, ATTR_NULL);
   memFree (lpv->pViewSelection);
   lpv->pViewSelection = NULL;
   CHECK_CALL (e, ErrorMapDatabaseToExtended (lpv->wLinkNo,
      fileSelectFields (lpv)));
   return e;
}



ERRNUM SelectionIncrease (LPV lpv, A4W_FLAGS what, A4W_SIZE count, PLONG fields)
{
   ERRNUM e = ERRNUM_SUCCESS;
   LONG field;
   LPIDXMAP f;
   int i;

   if ( NULL==lpv->pViewSelection ) {
      lpv->pViewSelection = (PVIEWSELECTION) memAlloc (sizeof (VIEWSELECTION));
      if ( NULL==lpv->pViewSelection ) {
         ReportMemoryError (lpv, MAKE_OP_RSC (VIEW_OP (lpv, OPEN)));
         return ERRNUM_MEMORY_NO_MORE;
      }
      if ( what & SELECTION_AUDIT_STAMP )
         lpv->pViewSelection->flags = FLG_READWRITE;
      else
         lpv->pViewSelection->flags = FLG_READONLY;
      if ( BASE_TBL_COUNT>0 )
         lpv->pViewSelection->subclassor = &lpv->pViewSelection->tables[0];
      else
         lpv->pViewSelection->subclassor = &lpv->pViewSelection->tables[BASE_TBL_COUNT + TBL_COUNT];
   }

   if ( KEY_COUNT>0 && (what & SELECTION_PRIMARY_KEY) ) {
      LPKEYMAP k = FindKeyDef (0); // BUG: subclassing won't work with this.

      for ( i=0; i<k->segments; ++i ) {
         field = k->indexes[i];
         f = FindFieldMapV (lpv, field);
         AttribClear (lpv, field, ATTR_NULL);
         CHECK_CALL (e, lpv->eValidation);
         SelectionInsertName (lpv, FindFieldDefV (lpv, field)->sName, f->tblNo);
      }
   }

   if ( TBL_COUNT>0 && (what & SELECTION_AUDIT_STAMP) ) {
      LPDBFIELD def = FindTableMapV (lpv, BASE_TBL_COUNT)->fields;

      def += SCINIT_FLD_AUDIT; // AUDTDATE
      SelectionInsertName (lpv, def->sName, BASE_TBL_COUNT);
      def += 1;              // AUDTTIME
      SelectionInsertName (lpv, def->sName, BASE_TBL_COUNT);
      def += 1;              // AUDTUSER
      SelectionInsertName (lpv, def->sName, BASE_TBL_COUNT);
      def += 1;              // AUDTORG
      SelectionInsertName (lpv, def->sName, BASE_TBL_COUNT);
   }

   if ( what & SELECTION_SUBCLASS_FIELDS ) {
      PTABLESELECTION selection = lpv->pViewSelection->subclassor;

      for ( i=0; i<selection->count; ++i ) {
         SelectionInsertName (lpv, selection->fields[i], BASE_TBL_COUNT);
      }
   }

   for ( i=0; i<count; ++i ) {
      INT insertion;

      field = fields[i];
      f = FindFieldMapV (lpv, field);
      if ( BinarySearch (&field, lpv->pViewSelection->fields,
                         lpv->pViewSelection->count, sizeof (LONG), &insertion) )
         continue;
      for ( i=lpv->pViewSelection->count; i>insertion; --i )
         lpv->pViewSelection->fields[i] = lpv->pViewSelection->fields[i-1];
      lpv->pViewSelection->fields[insertion] = field;
      lpv->pViewSelection->count += 1;
      AttribClear (lpv, field, ATTR_NULL);
      CHECK_CALL (e, lpv->eValidation);
      if ( f->tblNo<BASE_TBL_COUNT+TBL_COUNT ) {
         SelectionInsertName (lpv, FindFieldDefV (lpv, field)->sName, f->tblNo);
      }
   }

   CHECK_CALL (e, ErrorMapDatabaseToExtended (lpv->wLinkNo,
      fileSelectFields (lpv)));
   return e;
}



BOOL SelectionInsertName (LPV lpv, const char *name, const INT table)
{
   PTABLESELECTION selection = FindTableSelection (lpv, table);
   INT insertion;
   INT j;

   if ( BinarySearch (name, selection->fields,
                      selection->count, SIZEOF_FIELDNAME, &insertion) )
      return TRUE;
   for ( j=selection->count; j>insertion; --j )
      blkCopy (selection->fields[j], selection->fields[j-1], SIZEOF_FIELDNAME);
   blkCopy (selection->fields[j], name, SIZEOF_FIELDNAME);
   selection->count += 1;
   return FALSE;
}



ERRNUM SelectionValid (LPV lpv, A4W_SIZE count, PLONG fields)
{
   int i;

   for ( i=0; i<count; ++i ) {
      if ( !ValidIndexV (lpv, fields[i]) ) {
         ReportIndexError (lpv, fields[i]);
         return ERRNUM_FIELD_INDEX;
      }
   }
   return ERRNUM_SUCCESS;
}



ERRNUM SetAttribs (LPV lpv, LONG attribs)
{
   INT field;
   ERRNUM e = ERRNUM_SUCCESS;

   for ( field=0; field<FLD_IDX_COUNT; ++field ) {
      AttribSet (lpv, * FindFieldIndexV (lpv, field), attribs);
      CHECK_CALL (e, lpv->eValidation);
   }
   return e;
}



INT WINAPI StringComparator (LPDBFIELD field, LPDATUM d1, LPDATUM d2)
{
   INT i;
   LPBYTE left, right;

   left = d1->b;
   right = d2->b;
   for ( i=0; i<field->wLength; ++i ) {
      if ( left[i]==right[i] ) {
         if ( left[i]==0 )
            return 0;
      } else {
         if ( left[i]!=0 && right[i]!=0 )
            return left[i]-right[i];
         if ( right[i]==0 ) {
            while ( i<field->wLength ) {
               if ( left[i]==0 )
                  break;
               if ( left[i]!=' ' )
                  return 1;
               ++i;
            }
            return 0;
         }
         if ( left[i]==0 ) {
            while ( i<field->wLength ) {
               if ( right[i]==0 )
                  break;
               if ( right[i]!=' ' )
                  return -1;
               ++i;
            }
            return 0;
         }
      }
   }
   return 0;
}



void WINAPI SubtractDeltaBCD (LPDBFIELD field, LPDATUM from, LPDATUM by)
{
   bcdSub (from->n, field->wLength, field->wDecimals,
           by->n,   field->wLength, field->wDecimals);
}

void WINAPI SubtractDeltaByte (LPDBFIELD field, LPDATUM from, LPDATUM by)
{
   if ( field->wLength==1 )
      from->b[0] -= by->b[0];
   else
      SubtractDeltaString (field, from, by);
}

void WINAPI SubtractDeltaInteger (LPDBFIELD field, LPDATUM from, LPDATUM by)
{
   from->i -= by->i;
}

void WINAPI SubtractDeltaLong (LPDBFIELD field, LPDATUM from, LPDATUM by)
{
   from->l -= by->l;
}

void WINAPI SubtractDeltaReal (LPDBFIELD field, LPDATUM from, LPDATUM by)
{
   from->r -= by->r;
}

void WINAPI SubtractDeltaString (LPDBFIELD field, LPDATUM from, LPDATUM by)
{
   INT i, borrow = 0;

   for ( i=field->wLength; i--; ) {
      INT difference = (from->s[i]-'0') - borrow - (by->s[i]-'0');

      if ( difference>=0 )
         borrow = 0;
      else {
         borrow = 1;
         difference += 10;
      }
      from->s[i] = (CHAR) (difference+'0');
   }
}



VIEWBASE SupportsAPIversion (LPV lpv, LPSTR rotoID, LPVIEWDEF view, LPSTR needs, LPBOOL supports)
{
   CHAR version [SIZEOF_VERSION];
   BCDDATE date;
   ERRNUM e = ERRNUM_SUCCESS;

   *supports = FALSE;
   VIEWASSERT (view->rvh!=NULL);
   if ( view->rvh==NULL )
      return e;
   CHECK_CALL (e, GetTemplateVersion (lpv, rotoID, view, version, date));
   if ( blkCompare (version, needs, sizeof (version))>=0 )
      *supports = TRUE;
   return e;
}



void WINAPI SwapRecords (LPSTR FAR * set1, LPSTR FAR * set2)
{
   INT i;
   LPSTR p;

   for ( i=BASE_TBL_COUNT; i<BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT; i++ ) {
      p = set1[i];
      set1[i] = set2[i];
      set2[i] = p;
   }
}



// This function is tied intimately to the current implementation of
// fileFilterDelete(), along with all its limitations. In particular,
// it only works for fields of the primary table. Also, when this is a
// subclass view it only works with the fields of the primary key, and
// requires the underlying table definitions to be as MP3.
VIEWCALL tableName (LPVOID lpView, LONG lField, LPSTR lpsName, LPSTR lpsDesc)
{
   LPV lpv = (LPV) lpView;
   ERRNUM e = ERRNUM_SUCCESS;
   INT number;
   LPTBLMAP t = FindTableMapV (lpv, lpv->filterExpressionCast);

   CHECK_CALL (e, xxxNameOnly (lpView, lField, lpsName, lpsDesc));

   if ( SUBCLASS_LEVEL==NOT_SUBCLASS )
      number = FindFieldMapV (lpv, lField)->tblFieldNo;
   else {
      LPCMPKEY x = &lpv->subCmpKey;

      // infer the database field number
      for ( number=0; number<x->segments && x->indexes[number]!=lField; ++number )
         ;
   }

   strCopyBZ (lpsName, SIZEOF_FIELDNAME, t->fields[number].sName);
   return e;
}



void WINAPI UnloadOneView (LPV lpv, INT c)

{
   LPVIEWDEF v;

   if ( DMND_CMP_COUNT+IMP_CMP_COUNT+MAN_CMP_COUNT==0 )
      return;

   VIEWASSERT(c>=HDR_CMP_COUNT+DTL_CMP_COUNT+HCHY_CMP_COUNT &&
              c<CMP_COUNT+MAN_CMP_COUNT);
   v = FindCmp (lpv, c);
   if ( v->rvh ) {
      viewUnload (v->rvh);
      v->rvh = NULL;
   }
}



ERRNUM WINAPI UnpostedDetail (LPV lpv, INT level, INT c, LPBOOL unposted)
{
   ERRNUM e = ERRNUM_SUCCESS;
   LPVIEWDEF view = FindCmp (lpv, c);

   if ( view->rvh==NULL )
      return e;

   if ( HAS_REVISIONS==NO_REVISIONS ) {
      DBSBOOL dirty;

      CHECK_CALL (e, viewGet (view->rvh, view->view,
                              DIRTY_IDX, &dirty, sizeof (dirty)));
      if ( dirty )
         *unposted = TRUE;
   } else {
      A4W_FLAGS flags;

      CHECK_CALL (e, viewRevisionUnposted ((LPRVH) view->rvh, view->view,
                                           level, &flags));
      if ( (flags & MASK_REVISION_UNPOSTED)==REVISION_UNPOSTED_YES )
         *unposted = TRUE;
   }

   return e;
}



ERRNUM WINAPI UnpostedDetails (LPV lpv, INT level, LPBOOL unposted)
{
   ERRNUM e = ERRNUM_SUCCESS;
   INT c = 0;

   *unposted = FALSE;
   if ( !DETAILS_ARE_REVISIONED )
      return e;
   for ( c=HDR_CMP_COUNT; !*unposted && c<HDR_CMP_COUNT+DTL_CMP_COUNT; ++c ) {
      CHECK_CALL (e, UnpostedDetail (lpv, level, c, unposted));
   }
   return e;
}



BOOL WINAPI ValidateBuffer (LPV lpv, LONG field, INT size)
{
   LPDBFIELD f = FindFieldDefV (lpv, field);

   switch ( f->wType ) {
      case FT_DATE:
      case FT_TIME:
      case FT_INT:
      case FT_LONG:
      case FT_BOOL:
      case FT_REAL:
         if ( VALIDATE_BUFFER<VALIDATE_FIXED_BUFFER )
            break;
         // FALL THROUGH

      case FT_BCD:
         if ( VALIDATE_BUFFER<VALIDATE_BCD_BUFFER )
            break;
         // FALL THROUGH

      case FT_BYTE:
      case FT_CHAR:
         if ( VALIDATE_BUFFER<VALIDATE_ANY_BUFFER )
            break;
         // Is the buffer big enough?
         if ( size<(INT) f->wLength ) {
            ReportBufferError (lpv, field);
            return FALSE;
         }
         break;

      default:
         // QUESTION: Should we be reporting an internal error?
         break;
   }
   return TRUE;
}



BOOL WINAPI ValidateData (LPV lpv, LONG field, LPVOID datum)
{
   BOOL valid = TRUE;

   if ( lpv->bUnvalidated )
      return valid;

   if ( VALIDATE_DATA>=VALIDATE_BCD_DATA ) {
      LPDBFIELD f = FindFieldDefV (lpv, field);

      switch ( f->wType ) {
         case FT_BCD:
         case FT_TIME:
         case FT_DATE:
            valid = bcdCheck ((LPDBSNUMBER) datum, f->wLength, FALSE);
            break;
      }
      if ( valid && VALIDATE_DATA>=VALIDATE_DATETIME_DATA ) {
         switch ( f->wType ) {
            case FT_TIME:
               valid = timeCheck ((LPDBSTIME) datum);
               break;
            case FT_DATE:
               if ( !dateNull ((LPDBSDATE) datum) )
                  valid = dateCheck ((LPDBSDATE) datum);
               break;
         }
      }
   }

   if ( !valid )
      ReportDatumError (lpv, field);
   return valid;
}



BOOL WINAPI ValidateField (LPV lpv, LONG field, LPVOID buffer)
{
   VALIDATION validate;

   if ( lpv->bUnvalidated )
      return TRUE;
   if ( lpv->alAttributes[IDXIDX(field)] & ATTR_NULL )
      return TRUE;

   validate = FindFieldMapV (lpv, field)->validate;
   if ( NULL==validate )
      return TRUE;
   return (* validate) (lpv, field, buffer);
}




#if !defined(DO_LAZYPUT)
BOOL WINAPI ValidateKeyField (LPV lpv, LONG field)
#else
BOOL WINAPI ValidateKeyField (LPV lpv, LONG field, LPVOID buffer, INT size)
#endif
{
 #if HCHY_CMP_COUNT+DMND_CMP_COUNT+IMP_CMP_COUNT>0 && defined(DO_VALIDATEKEYS)
   INT c, i, instances, seg;
   LPKEYMAP k;
  #if defined(DO_LAZYPUT)
   LPSTR New, old;
  #endif
   LPDBFIELD f = FindFieldDefV (lpv, field);

   if ( lpv->bUnvalidated )
      return TRUE;
   if ( lpv->alAttributes[IDXIDX(field)] & ATTR_NULL )
      return TRUE;

  #if defined(DO_LAZYPUT)
   old = (LPSTR) _alloca (size);
   if ( !old ) {
      ReportMemoryError (lpv, MAKE_OP_RSC (VIEW_OP (lpv, OPEN)));
      lpv->eValidation = ERRNUM_MEMORY_NO_MORE;
      return FALSE;
   }
   New = FindFieldValue (lpv, field);
   blkCopy (old, New, size);
   blkCopy (New, buffer, size);
  #endif

   for ( c = HDR_CMP_COUNT+DTL_CMP_COUNT; c < CMP_COUNT; c++ ) {
  #if !defined(DO_LAZYPUT)
      if ( FindCmp (lpv, c)->view==NULL || ! * FindCmpField (lpv, c, field) )
  #else
      if ( ! * FindCmpForeign (lpv, field) )
  #endif
         continue;
      k = FindKeyMap (c);
      if ( k ) {
         if ( lpv->sysAccess==SYSACCESS_IMPORT && k->segments>1 )
            continue;
         instances = k->name + 1;
         for ( i=0; i<instances; ++i ) {
            seg = k->segments;
            while ( --seg>=0 && k->indexes[seg]==0L )
               ;
            if ( seg>=0 && k->indexes[seg]==field ) {
  #if !defined(DO_LAZYPUT)
               if ( !ValidateKey (lpv, c, k, FindCmpKey (lpv, c)->indexes) ) {
                  RVSPYPRINT(("Invalid foreign key #%d (%6.6s) from %10.10s",
                              c, FindCmpName (c), f->sName));
                  return FALSE;
               }
  #else
               if ( !ValidateKey (lpv, c, i) ) {
                  RVSPYPRINT(("Invalid foreign key #%d (%6.6s) from %10.10s",
                              c, FindCmpName (c), f->sName));
                  blkCopy (New, old, size);
                  return FALSE;
               }
  #endif
            }
            ++k;
         }
      }
   }
  #if defined(DO_LAZYPUT)
   blkCopy (New, old, size);
  #endif
 #endif
   return TRUE;
}



#if defined(DO_VALIDATEKEYS)

BOOL WINAPI ValidateKeys (LPV lpv, BOOL verifying)
{
   BOOL errors = FALSE;
#if HCHY_CMP_COUNT+DMND_CMP_COUNT+IMP_CMP_COUNT>0 || (defined(BATCH_VIEW) && HDR_CMP_COUNT>0)
 #if HCHY_CMP_COUNT+DMND_CMP_COUNT+IMP_CMP_COUNT>0
   INT i, instances, nCmp;
   LPKEYMAP k;
 #endif
 #if defined(DO_LAZYVERIFY)
   INT f;
   BOOL verify;
   BOOL set;
 #endif

   if ( lpv->bUnvalidated )
      return TRUE;
 #if defined(BATCH_VIEW) && HDR_CMP_COUNT>0 && SUBCLASS_LEVEL==NOT_SUBCLASS
   if ( FindCmp (lpv, 0)->view!=NULL && DetailKeyWithinHeader (lpv) ) {
  #if defined(DO_LAZYPUT)
      if ( !ValidateKey (lpv, 0, 0) )
  #else
      if ( !ValidateKey (lpv, 0, FindKeyDef (0), FindCmpKey (lpv, 0)->indexes) )
  #endif
      {
         if ( ERRNUM_IS_FAILURE (lpv->eValidation) )
            return FALSE;
         errors = TRUE;
      }
   }
 #endif

 #if HCHY_CMP_COUNT+DMND_CMP_COUNT+IMP_CMP_COUNT>0
   for ( nCmp = HDR_CMP_COUNT+DTL_CMP_COUNT; nCmp < CMP_COUNT; nCmp++ ) {
  #if !defined(DO_LAZYPUT) && !defined(DO_LAZYVERIFY)
      CHECK_CALL_BOOLEAN (lpv->eValidation, DemandOpen (lpv, nCmp));
      if ( FindCmp (lpv, nCmp)->view==NULL )
         continue;
  #endif

      k = FindKeyMap (nCmp);
      if ( k ) {
         instances = k->name + 1;
         for ( i=0; i<instances; ++i ) {
            if ( k->segments>0 ) {
  #if !defined(DO_LAZYVERIFY)
   #if defined(DO_LAZYPUT)
               if ( !ValidateKey (lpv, nCmp, i) )
   #else
               if ( !ValidateKey (lpv, nCmp, k, FindCmpKey (lpv, nCmp)->indexes) )
   #endif
               {
                  RVSPYPRINT(("Invalid foreign key #%d (%6.6s)",
                              nCmp, FindCmpName (nCmp)));
                  if ( ERRNUM_IS_FAILURE (lpv->eValidation) )
                     return FALSE;
                  errors = TRUE;
               }
  #else
               verify = verifying;
               for ( f=k->segments; f-- && !verify; ) {
                  LONG attribs = AttribGet (lpv, k->indexes[f]);

                  if ( ERRNUM_IS_FAILURE (lpv->eValidation) )
                     return FALSE;
                  if ( (attribs & ATTR_NULL) ) {
                     verify = FALSE;
                     break;
                  }
                  if ( (attribs & ATTR_CHANGED) )
                     verify = TRUE;
               }
               if ( verify ) {
   #if !defined(DO_LAZYPUT)
                  CHECK_CALL_BOOLEAN (lpv->eValidation, DemandOpen (lpv, nCmp));
                  if ( !ValidateKey (lpv, nCmp, k, FindCmpKey (lpv, nCmp)->indexes) )
   #else
                  if ( !ValidateKey (lpv, nCmp, i) )
   #endif
                  {
                     RVSPYPRINT(("Invalid foreign key #%d (%6.6s)",
                                 nCmp, FindCmpName (nCmp)));
                     if ( ERRNUM_IS_FAILURE (lpv->eValidation) )
                        return FALSE;
                     errors = TRUE;
                  }
               }
  #endif
            }
            ++k;
         }
      }

      {
         switch ( CompositeCategory (lpv, nCmp) ) {
            case DEMAND_COMPOSITE :
               if ( !*FindImpOpen (lpv, nCmp) )
                  break;
               // FALL THROUGH !!!
            case IMPLICIT_COMPOSITE: {
               LPCMPNAME d = FindCmpDef (nCmp);

               if ( d!=NULL && (d->options & CMPNAME_OPTION_VIEWPOOL) )
                  ReleaseOneView (lpv, nCmp);
               break;
            }
            default:
               break;
         }
      }
   }
 #endif
#endif
   return !errors;
}

#endif



BOOL WINAPI ValidateList (LPV lpv, LPPRESENTATION p, LONG field, LPVOID data)
{
   INT i;
   DBSLONG v = PRESENTS_LIST_NOTFOUND;
   LPDBFIELD f = FindFieldDefV (lpv, field);
   LPDATUM datum = (LPDATUM) data;

   if ( lpv->bUnvalidated )
      return TRUE;
   switch ( f->wType ) {
      case FT_BYTE:
         switch ( f->wLength ) {
            case 1:
               v = datum->b[0];
               break;
            case SIZEOF_INT:
               v = * (LPUSHORT) data;
               break;
            case SIZEOF_LONG:
               v = * (LPULONG) data;
               break;
         }
         break;
      case FT_CHAR:
         switch ( f->wLength ) {
            case 1:
               v = datum->s[0];
               break;
            case SIZEOF_INT:
               v = * (LPSHORT) data;
               break;
            case SIZEOF_LONG:
               v = * (LPLONG) data;
               break;
         }
         break;
      case FT_INT:
         v = datum->i;
         break;
      case FT_BOOL:
         v = datum->f;
         break;
      case FT_LONG:
         v = datum->l;
         break;
   }
   if ( v==PRESENTS_LIST_NOTFOUND ) {
      ReportListError (lpv, field);
      return FALSE;
   }
   for ( i=0; i<p->elements; ++i )
      if ( p->listNums[i]==v )
         break;
   if ( i>=p->elements ) {
      ReportListError (lpv, field);
      return FALSE;
   }
   return TRUE;
}



#if defined(DO_HELPERSOUTOFLINE)

BOOL WINAPI ValidIndexV (LPV lpv, LONG field)
{
   return DoValidIndexV (lpv, field);
}

#endif



VIEWBASE viewGetBoolean (LPVOID rvh, LPVOID view, LONG field, LPDBSBOOL buffer)
{
   return viewGet (rvh, view, field, buffer, sizeof (*buffer));
}



VIEWBASE viewGetInteger (LPVOID rvh, LPVOID view, LONG field, LPDBSINT buffer)
{
   return viewGet (rvh, view, field, buffer, sizeof (*buffer));
}



VIEWBASE viewGetLong (LPVOID rvh, LPVOID view, LONG field, LPDBSLONG buffer)
{
   return viewGet (rvh, view, field, buffer, sizeof (*buffer));
}



VIEWBASE viewGetReal (LPVOID rvh, LPVOID view, LONG field, LPDBSREAL buffer)
{
   return viewGet (rvh, view, field, buffer, sizeof (*buffer));
}



VIEWBASE viewGetString (LPVOID rvh, LPVOID view, LONG field, LPSTR buffer, INT size)
{
   ERRNUM e = viewGet (rvh, view, field, buffer, size);

   if ( ERRNUM_IS_SUCCESS (e) )
      buffer[size] = 0;
   return e;
}



VIEWBASE viewPutBoolean (LPVOID rvh, LPVOID view, LONG field, DBSBOOL buffer, BOOL verify)
{
   return viewPut (rvh, view, field, &buffer, sizeof (buffer), verify);
}



VIEWBASE viewPutInteger (LPVOID rvh, LPVOID view, LONG field, DBSINT buffer, BOOL verify)
{
   return viewPut (rvh, view, field, &buffer, sizeof (buffer), verify);
}



VIEWBASE viewPutLong (LPVOID rvh, LPVOID view, LONG field, DBSLONG buffer, BOOL verify)
{
   return viewPut (rvh, view, field, &buffer, sizeof (buffer), verify);
}



VIEWBASE viewPutReal (LPVOID rvh, LPVOID view, LONG field, DBSREAL buffer, BOOL verify)
{
   return viewPut (rvh, view, field, &buffer, sizeof (buffer), verify);
}



/////////////////////////////////////////////////////////////////////////////
// Support routines for nested revisions
/////////////////////////////////////////////////////////////////////////////



LPREVNODE WINAPI RevisionAdd (LPV lpv, LPREVISION rev, LPVOID key)
{
   LPREVNODE node = NULL;
   REVNODE current;
   LPREVNODE adding = &current;

   if ( HAS_REVISIONS==NO_REVISIONS )
      return node;
   if ( !(SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS) )
      return node;
   if ( !lpv->bRevisioned )
      return node;

   RVSPYTRACE ("RevisionAdd");
   RVSPYINDENT (1);
   RevisionMove (adding->rev, rev, REVMOVE_CLEAR_SOURCE);
   node = RevisionInnerAdd (lpv, &adding, key, HDR_HAS_REVISIONS);
   RVSPYINDENT (-1);
   return node;
}



DB_ERRNUM RevisionAllocateAfter (LPV lpv, LPDBFIELD f, LPVOID sequence)
{
   REVISION rev;
   LPVOID record;
   DB_ERRNUM d = DBS_SUCCESS;

   if ( HAS_REVISIONS!=SEQUENCE_REVISIONS )
      return d;
   if ( !lpv->bRevisioned )
      return d;

   CHECK_DBCALL (d, RevisionRealize (lpv));

   rev = FindTableRev (lpv) [BASE_TBL_COUNT];
   record = FindRecord (lpv) [BASE_TBL_COUNT];
   revAllocateAfter (rev, record);
   d = revGetExtendedError (rev);
   if ( d==DBS_NOT_FOUND ) {
      // If the root key doesn't exist, allocate at start of revlist
      InitFieldBuffer (sequence, f->wType, f->wLength);
      revAllocateAfter (rev, record);
      d = revGetExtendedError (rev);
   }
   return revErrorV (lpv, rev, d);
}



DB_ERRNUM WINAPI RevisionAttach (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;

   if ( HDR_HAS_REVISIONS==0 )
      return d;
   if ( !lpv->bRevisioned )
      return d;

   lpv->bAttachRequested = TRUE;
   RVSPYTRACE ("RevisionAttach REQUESTED");
   return d;
}



DB_ERRNUM WINAPI RevisionCancel (LPV lpv, LPREVISION rev)
// UNDER
{
   DB_ERRNUM d = DBS_SUCCESS;
   INT i;

   if ( !(SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS) )
      return d;
   if ( HAS_REVISIONS==NO_REVISIONS )
      return d;
   if ( !lpv->bRevisioned )
      return d;
   if ( NULL==rev )
      return d;

   RVSPYTRACE ("RevisionCancel");
   for ( i=BASE_TBL_COUNT; i<BASE_TBL_COUNT+TBL_COUNT; ++i ) {
      if ( rev[i]!=NULL ) {
         revCancel (rev[i]);
         rev[i] = NULL;
      }
   }
   return DBS_SUCCESS;
}



BOOL RevisionCheckDuplicates (LPV lpv, BOOL checked, LPREVISION rev)
// This is meant to be called only on level 1+HDR_HAS_REVISIONS
{
   BOOL was = TRUE;
   INT i;

   if ( !(SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS) )
      return was;
   if ( HAS_REVISIONS==NO_REVISIONS )
      return was;
   if ( !lpv->bRevisioned )
      return was;

   if ( rev==NULL )
      rev = FindTableRev (lpv);
   if ( rev[BASE_TBL_COUNT]!=NULL )
      was = revCheckDuplicates (rev[BASE_TBL_COUNT], checked);
   for ( i=1+BASE_TBL_COUNT; i<BASE_TBL_COUNT+TBL_COUNT; i++ ) {
      if ( rev[i]!=NULL )
         revCheckDuplicates (rev[i], FALSE);
   }
   RVSPYPRINT (("RevisionCheckDuplicates was %s, and now is %s",
                (was ? "TRUE": "FALSE"), (checked ? "TRUE": "FALSE")));
   return was;
}



BOOL WINAPI RevisionConsume (LPV lpv)
{
   BOOL consumed;

   if ( !lpv->bRevisioned )
      return FALSE;
   RVSPYTRACE ("RevisionConsume");
   RVSPYINDENT (1);
   consumed = RevisionInnerConsume (lpv, 1, NULL);
   RVSPYINDENT (-1);
   return consumed;
}



DB_ERRNUM WINAPI RevisionCreate (LPV lpv)
// OVER
// This should've been RevisionOuterCreate, but it has become established
{
   DB_ERRNUM d = DBS_SUCCESS;

   if ( HAS_REVISIONS==NO_REVISIONS )
      return d;

   RVSPYTRACE ("RevisionCreate");
   RVSPYINDENT (1);
   if ( HDR_HAS_REVISIONS==0 ) {
      MaxDatabaseError (&d, fileCreate (lpv));
   } else {
      MaxDatabaseError (&d, RevisionAttach (lpv));
   }
   RVSPYINDENT (-1);
   if ( DB_ERRNUM_IS_SUCCESS (d) )
      RVSPYTRACE ("RevisionCreate SUCCEEDED");
   else
      RVSPYTRACE ("RevisionCreate FAILED");
   return d;
}



DB_ERRNUM WINAPI RevisionDirty (LPV lpv, LPREVISION rev, LPBOOL dirty)
// UNDER
{
   DB_ERRNUM d = DBS_SUCCESS;

   RVSPYTRACE ("RevisionDirty");
   RVSPYINDENT (1);
   if ( !lpv->bRevisioned ) {
      ERRNUM e = scInitDirty (lpv, dirty);

      MaxDatabaseError (&d, ErrorMapViewToDatabase (VIEW_OP_DIRTY, e));
   }

   if ( (SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS) &&
        HAS_REVISIONS!=NO_REVISIONS && lpv->bRevisioned ) {
      if ( rev[BASE_TBL_COUNT]==NULL )
         *dirty = FALSE;
      else
         *dirty = revDirty (rev[BASE_TBL_COUNT]);
   }

   RVSPYINDENT (-1);
   RVSPYPRINT (("RevisionDirty RESULT=%d", *dirty));
   return d;
}



DB_ERRNUM WINAPI RevisionDuplicate (LPV lpv, LPREVISION target, LPREVISION source)
{
   DB_ERRNUM d = DBS_SUCCESS;
   INT i;
   REVERROR error;

   if ( !(SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS) )
      return d;
   if ( HAS_REVISIONS==NO_REVISIONS )
      return d;
   if ( !lpv->bRevisioned )
      return d;

   RVSPYTRACE ("RevisionDuplicate");
   RVSPYINDENT (1);
   CHECK_DBCALL (d, RevisionCancel (lpv, target));
   error.size = sizeof (error);
   for ( i=BASE_TBL_COUNT; i<BASE_TBL_COUNT+TBL_COUNT; i++ ) {
      if ( source[i]==NULL )
         continue;
      target[i] = revDuplicateErr (source[i], &error);
      if ( !target[i] ) {
         ReportGenericError (lpv, ERRGEN_AREA_REVLIST, error.op, error.ec, &error);
         MaxDatabaseError (&d, error.ec);
         RVSPYINDENT (-1);
         RVSPYTRACE ("RevisionDuplicate ERROR");
         return d;
      }
   }

   RevisionCheckDuplicates (lpv,
      lpv->bCheckDuplicates && lpv->sysAccess!=SYSACCESS_IMPORT, target);
   RVSPYINDENT (-1);
   RVSPYTRACE ("RevisionDuplicate SUCCEEDED");
   return d;
}



DB_ERRNUM WINAPI RevisionGenerate (LPV lpv, LPREVISION lpRev, LPREVISION lpRevCache)
// UNDER
{
   INT i;
   LPVOID rev;
   DB_ERRNUM d = DBS_SUCCESS;
   REVERROR error;

   if ( !(SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS) )
      return d;
   if ( HAS_REVISIONS==NO_REVISIONS )
      return d;
   if ( !lpv->bRevisioned )
      return d;
   if ( NULL==lpRev )
      return d;

   error.size = sizeof (error);
   RVSPYTRACE ("RevisionGenerate");
   for ( i=BASE_TBL_COUNT; i<BASE_TBL_COUNT+TBL_COUNT; ++i ) {
      WORD handle = MapStubToTableHandle (lpv, (FindTableHandle (lpv)) [i]);
      PTABLESELECTION selection = FindTableSelection (lpv, i);

      if ( selection!=NULL && 0==selection->count )
         continue;
      if ( lpRevCache!=NULL && lpRevCache [i]!=NULL )
         rev = revCreateFromHandleErr (lpRevCache [i], &error);
      else if ( i>BASE_TBL_COUNT )
         rev = revCreateOrderedErr (lpv->wLinkNo, handle, 0, &error);
      else if ( HAS_REVISIONS==SEQUENCE_REVISIONS && lpv->wActualKey==0 )
         rev = revCreateSequenceErr (lpv->wLinkNo, handle, REV_SEQ_SKIP, &error);
      else
         rev = revCreateOrderedErr (lpv->wLinkNo, handle, lpv->wActualKey, &error);
      lpRev [i] = rev;
      if ( rev==NULL ) {
         d = error.ec;
         ReportGenericError (lpv, ERRGEN_AREA_REVLIST, error.op, d, &error);
         while ( i-- ) {
            revCancel (lpRev [i]);
            lpRev [i] = NULL;
         }
         RVSPYTRACE ("RevisionGenerate ERROR");
         return d;
      }
   }

   RVSPYINDENT (1);
   RevisionCheckDuplicates (lpv,
      lpv->bCheckDuplicates && lpv->sysAccess!=SYSACCESS_IMPORT, lpRev);
   RevisionSegments (lpv, lpRev);
   RVSPYINDENT (-1);
   RVSPYTRACE ("RevisionGenerate SUCCEEDED");
   return DBS_SUCCESS;
}



LPREVNODE WINAPI RevisionInnerAdd (LPV lpv, LPREVNODE FAR *adding, LPVOID key, INT level)
{
   LPREVNODE current = NULL;
   LPREVLEVEL revLevel = FindRevLevel (lpv, level);

   VIEWASSERT (HDR_HAS_REVISIONS>0);
   VIEWASSERT (level>=1);
   VIEWASSERT (level<=HDR_HAS_REVISIONS);
   VIEWASSERT (revLevel!=NULL);

   if ( HAS_REVISIONS==NO_REVISIONS )
      return current;
   if ( HDR_HAS_REVISIONS==0 )
      return current;
   if ( !lpv->bRevisioned )
      return current;

   RVSPYPRINT (("RevisionInnerAdd LEVEL=%d", level));
   current = (LPREVNODE) memAlloc (sizeof(REVNODE) + revLevel->iHdrPKeySize);
   if ( current==NULL ) {
      ReportMemoryError (lpv, MAKE_OP_RSC (VIEW_OP (lpv, OPEN)));
      RVSPYTRACE ("RevisionInnerAdd ERROR");
      return current;
   }
   RVSPYINDENT (1);
   current->key = current+1;
   blkCopy (current->key, key, revLevel->iHdrPKeySize);
   RevisionInnerMove (lpv, current, adding, level, REVMOVE_CLEAR_SOURCE);
   current->flags = 0;
   current->pNext = revLevel->revList;
   revLevel->revList = current;
   RVSPYINDENT (-1);
   RVSPYTRACE ("RevisionInnerAdd SUCCEEDED");
   return current;
}



DB_ERRNUM WINAPI RevisionInnerAttach (LPV lpv, INT level)
{
   DB_ERRNUM d = DBS_SUCCESS;
   LPVOID key = (FindRecord (lpv)) [BASE_TBL_COUNT];
   LPREVLEVEL revLevel = FindRevLevel (lpv, level);
   LPREVNODE attaching;

   if ( HAS_REVISIONS==NO_REVISIONS )
      return d;
   if ( HDR_HAS_REVISIONS==0 )
      return d;
   if ( !lpv->bRevisioned )
      return d;

   VIEWASSERT (level>=1);
   VIEWASSERT (level<=HDR_HAS_REVISIONS);
   VIEWASSERT (revLevel!=NULL);

   RVSPYPRINT (("RevisionInnerAttach LEVEL=%d", level));
   RVSPYINDENT (1);

   revLevel->AttachedRevision = RevisionInnerFind (lpv, key, level);
   if ( revLevel->AttachedRevision==NULL ) {
      if ( level==HDR_HAS_REVISIONS ) {
         attaching = RevisionAdd (lpv, FindTableRev (lpv), key);
      } else {
         attaching = RevisionInnerAdd (lpv, &FindRevLevel (lpv, level+1)->revList,
                                       key, level);
      }
      revLevel->AttachedRevision = attaching;
      if ( attaching==NULL )
         return DBS_MEMORY;
      CHECK_DBCALL (d, RevisionInnerDuplicate (lpv, attaching, level));
   }

   RVSPYINDENT (-1);
   return d;
}



DB_ERRNUM WINAPI RevisionInnerCancel (LPV lpv, INT level, LPREVISION rev)
{
   DB_ERRNUM d = DBS_SUCCESS;

   if ( HAS_REVISIONS==NO_REVISIONS )
      return d;
   if ( !lpv->bRevisioned )
      return d;

   VIEWASSERT (level>=0);
   if ( level<0 )
      return d;

   RVSPYPRINT (("RevisionInnerCancel LEVEL=%d", level));
   RVSPYINDENT (1);

   if ( rev==NULL )
      rev = FindTableRev (lpv);
   CHECK_DBCALL_GOTO (d, cleanup, RevisionCancel (lpv, rev));
   if ( HDR_HAS_REVISIONS==0 )
      goto cleanup;

   if ( lpv->levelSwitched>=level )
      lpv->levelSwitched = level-1;
   while ( level<=HDR_HAS_REVISIONS ) {
      LPREVLEVEL revLevel = FindRevLevel (lpv, level);

      lpv->bConsuming = TRUE;
      while ( RevisionInnerConsume (lpv, level, rev) ) {
         CHECK_DBCALL_GOTO (d, cleanup, RevisionCancel (lpv, rev));
      }
      while ( RevisionRecursiveConsume (lpv,
                 &revLevel->RekeyPending, level, rev) ) {
         CHECK_DBCALL_GOTO (d, cleanup, RevisionCancel (lpv, rev));
      }
      revLevel->dirty = FALSE;
      revLevel->AttachedRevision = NULL;
      ++level;
   }

cleanup:
   RVSPYINDENT (-1);
   if ( DB_ERRNUM_IS_SUCCESS (d) )
      RVSPYTRACE ("RevisionInnerCancel SUCCEEDED");
   else
      RVSPYTRACE ("RevisionInnerCancel FAILED");
   return d;
}



BOOL WINAPI RevisionInnerConsume (LPV lpv, INT level, LPREVISION rev)
{
   BOOL more = FALSE;

   if ( HAS_REVISIONS==NO_REVISIONS )
      return more;
   if ( !lpv->bRevisioned )
      return more;
   if ( !lpv->bConsuming )
      return more;

   RVSPYPRINT (("RevisionInnerConsume LEVEL=%d", level));
   RVSPYINDENT (1);
   if ( NULL==rev )
      rev = FindTableRev (lpv);

   if ( HDR_HAS_REVISIONS==0 ) {
      lpv->bConsuming = FALSE;
      if ( rev[BASE_TBL_COUNT]!=NULL )
         more = TRUE;
   } else {
      LPREVLEVEL revLevel = FindRevLevel (lpv, level);

      if ( lpv->bConsumingRekeys ) {
         more = RevisionRecursiveConsumeRekeys (lpv, &revLevel->revList, level, rev);
         if ( !more )
            lpv->bConsumingRekeys = FALSE;
      }
      if ( !more ) {
         more = RevisionRecursiveConsume (lpv, &revLevel->revList, level, rev);
         if ( !more )
            lpv->bConsuming = FALSE;
      }
   }

   RVSPYINDENT (-1);
   if ( more )
      RVSPYTRACE ("RevisionInnerConsume SUCCEEDED");
   return more;
}



DB_ERRNUM WINAPI RevisionInnerCreate (LPV lpv, INT level)
{
   DB_ERRNUM d = DBS_SUCCESS;

   VIEWASSERT (level>=1 && level<=1+HDR_HAS_REVISIONS);
   if ( HDR_HAS_REVISIONS==0 || level<=1 )
      return RevisionCreate (lpv);
   if ( !lpv->bRevisioned )
      return d;

   RVSPYPRINT (("RevisionInnerCreate LEVEL=%d", level));
   RVSPYINDENT (1);
   MaxDatabaseError (&d, RevisionAttach (lpv));
   RVSPYINDENT (-1);
   if ( DB_ERRNUM_IS_SUCCESS (d) )
      RVSPYTRACE ("RevisionInnerCreate SUCCEEDED");
   else
      RVSPYTRACE ("RevisionInnerCreate FAILED");
   return d;
}



DB_ERRNUM WINAPI RevisionInnerDirty (LPV lpv, INT level, LPBOOL dirty)
// OVER
{
   DB_ERRNUM d = DBS_SUCCESS;

   RVSPYPRINT (("RevisionInnerDirty LEVEL=%d", level));
   RVSPYINDENT (1);
   *dirty = FALSE;
   if ( HAS_REVISIONS!=NO_REVISIONS && lpv->bRevisioned ) {
      if ( HDR_HAS_REVISIONS==0 ) {
         CHECK_DBCALL (d, fileDirty (lpv, dirty));
      } else if ( level>HDR_HAS_REVISIONS ) {
         *dirty = lpv->bUnpostedRevisions;
      } else if ( level>lpv->levelSwitched ) {
         *dirty = FALSE;
      } else {
         LPREVLEVEL revLevel = FindRevLevel (lpv, level);

         *dirty = revLevel->dirty;
      }
   }
   RVSPYINDENT (-1);
   RVSPYPRINT (("RevisionInnerDirty RESULT=%d", *dirty));
   return d;
}



DB_ERRNUM WINAPI RevisionInnerDuplicate (LPV lpv, LPREVNODE source, INT level)
{
   DB_ERRNUM d = DBS_SUCCESS;

   if ( HAS_REVISIONS==NO_REVISIONS )
      return d;
   if ( HDR_HAS_REVISIONS==0 )
      return d;
   if ( !lpv->bRevisioned )
      return d;

   RVSPYPRINT (("RevisionInnerDuplicate LEVEL=%d", level));
   RVSPYINDENT (1);
   if ( level==HDR_HAS_REVISIONS ) {
      LPREVISION rev = FindTableRev (lpv);

      VIEWASSERT (source->revList==NULL);
      CHECK_DBCALL (d, RevisionDuplicate (lpv, rev, source->rev));
      RevisionSpy (lpv, NULL, HDR_HAS_REVISIONS+1);
   } else {
      VIEWASSERT (source->revList!=NULL);
      CHECK_DBCALL (d,
         RevisionRecursiveDuplicate (lpv, source->revList, level+1,
                                     &(FindRevLevel (lpv, level+1)->revList)));
   }
   RVSPYINDENT (-1);
   RVSPYTRACE ("RevisionInnerDuplicate SUCCEEDED");
   return d;
}



LPREVNODE WINAPI RevisionInnerFind (LPV lpv, LPVOID key, INT level)
{
   LPREVLEVEL revLevel = FindRevLevel (lpv, level);
   LPREVNODE current = NULL;

   if ( HAS_REVISIONS==NO_REVISIONS )
      return current;
   if ( HDR_HAS_REVISIONS==0 )
      return current;
   if ( !lpv->bRevisioned )
      return current;

   VIEWASSERT (level>=1 && level<=HDR_HAS_REVISIONS);
   if ( level<1 || level>HDR_HAS_REVISIONS )
      return current;

#if defined(VIEWDEBUG)
   if ( VIEWDEBUG==VIEWDEBUG_ALL || VIEWDEBUG==VIEWDEBUG_NESTED_DETAILS ) {
      RVSPYTRACE ("RevisionInnerFind DUMP");
      current = revLevel->revList;
      RVSPYINDENT (1);
      while ( current!=NULL ) {
         RevisionSpy (lpv, current, level);
         current = current->pNext;
      }
      VIEWASSERT (current==NULL);
      RVSPYINDENT (-1);
   }
#endif

   if ( (!lpv->bAttachRequested && level>1+lpv->levelSwitched) ||
        (lpv->bAttachRequested && level>lpv->levelSwitched) )
      return current; // By definition, there is nothing at this level

   RVSPYPRINT (("RevisionInnerFind LEVEL=%d", level));
   RVSPYINDENT (1);
   current = revLevel->revList;
   while ( current!=NULL ) {
      if ( blkCompare (current->key, key, revLevel->iHdrPKeySize)==0 ) {
         RevisionSpy (lpv, current, level);
         RVSPYINDENT (-1);
         RVSPYTRACE ("RevisionInnerFind SUCCEEDED");
         return current;
      }
      current=current->pNext;
   }
   RVSPYINDENT (-1);
   RVSPYTRACE ("RevisionInnerFind ERROR");

   return NULL;
}



DB_ERRNUM WINAPI RevisionInnerGraft (LPV lpv, PREVGRAFTPOINT graft, LPREVISION rev, A4W_FLAGS flags)
{
   DB_ERRNUM d = DBS_SUCCESS;
   LPREVLEVEL revLevel;
   LPREVNODE current;
   int level = graft->level;
   LPREVNODE *root;
   BOOL dirty;

   if ( HDR_HAS_REVISIONS==0 )
      return d;
   if ( !lpv->bRevisioned )
      return d;
   if ( level>HDR_HAS_REVISIONS )
      return d;

   if ( graft->found )
      return d;
   CHECK_DBCALL (d, RevisionDirty (lpv, rev, &dirty));
   if ( !dirty ) {
      MaxDatabaseError (&d, RevisionCancel (lpv, rev));
      return d;
   }
   revLevel = FindRevLevel (lpv, graft->level);
   current = NULL;
   root = graft->root;

   VIEWASSERT (level>=1);
   RVSPYPRINT (("RevisionInnerGraft LEVEL=%d", level));
   RVSPYINDENT (1);

   while ( level<=HDR_HAS_REVISIONS ) {
      current = *root;
      while ( current!=NULL &&
              blkCompare (current->key, graft->key, revLevel->iHdrPKeySize)!=0 )
         current = current->pNext;

      if ( current==NULL ) {
         current = (LPREVNODE) memAlloc (sizeof(REVNODE) + revLevel->iHdrPKeySize);
         if ( current==NULL ) {
            ReportMemoryError (lpv, MAKE_OP_RSC (VIEW_OP (lpv, OPEN)));
            RVSPYINDENT (-1);
            RVSPYTRACE ("RevisionInnerGraft ERROR");
            return ERRNUM_MEMORY_NO_MORE;
         }
         current->key = current+1;
         blkCopy (current->key, graft->key, revLevel->iHdrPKeySize);
         current->flags = 0;
         current->pNext = *root;
         *root = current;
         if ( level==HDR_HAS_REVISIONS ) {
            if ( flags & REVNODE_REKEY_TARGET )
               RevisionMove (current->rev, rev, REVMOVE_CLEAR_SOURCE);
            else
               RevisionMove (current->rekey, rev, REVMOVE_CLEAR_SOURCE);
            current->flags = flags;
         }
      }

      root = &current->revList;
      RevisionSpy (lpv, current, level);
      ++revLevel;
      ++level;
   }

   RVSPYINDENT (-1);
   RVSPYTRACE ("RevisionInnerGraft SUCCEEDED");
   return d;
}



DB_ERRNUM WINAPI RevisionInnerMove (LPV lpv, LPREVNODE target, LPREVNODE FAR *source, INT level, A4W_FLAGS flags)
{
   DB_ERRNUM d = DBS_SUCCESS;

   if ( HDR_HAS_REVISIONS==0 )
      return d;
   if ( !lpv->bRevisioned )
      return d;

   RVSPYPRINT (("RevisionInnerMove LEVEL=%d FLAGS=0x%08lx", level, flags));
   RVSPYINDENT (1);
   if ( level>=HDR_HAS_REVISIONS )
      RevisionMove (target->rev, (*source)->rev, flags);
   else {
      if ( flags & REVMOVE_CANCEL_TARGET ) {
         while ( RevisionRecursiveConsume (lpv, &target->revList, level+1, NULL) ) {
            CHECK_DBCALL (d, RevisionCancel (lpv, FindTableRev (lpv)));
         }
         CHECK_DBCALL (d, RevisionInnerCancel (lpv, level+2, NULL));
      }
      target->revList = *source;
      if ( flags & REVMOVE_CLEAR_SOURCE ) {
         *source = NULL;
      }
   }
   RevisionSpy (lpv, target, level);
   RVSPYINDENT (-1);
   RVSPYTRACE ("RevisionInnerMove SUCCEEDED");
   return d;
}



VIEWBASE RevisionInnerPostBase (LPV lpv, INT level)
{
   ERRNUM e = ERRNUM_SUCCESS;
   LPREVLEVEL revLevel = NULL;
   LPREVNODE parent = NULL;
   LPSTR key = NULL;
   REVNODE current;
   LPREVNODE posting = &current;
   LPREVNODE FAR *postingref = &posting;
   BOOL dirty;
   REVISION rev [BASE_TBL_COUNT+TBL_COUNT + 1]; // added 1 to avoid #ifdefs
   INT i;

   VIEWASSERT (level>=1);
   VIEWASSERT (level<=1+HDR_HAS_REVISIONS);
   if ( level<1 || level>1+HDR_HAS_REVISIONS )
      return e;

   if ( HAS_REVISIONS==NO_REVISIONS )
      return e;
   if ( HDR_HAS_REVISIONS==0 || level<=1 )
      return RevisionOuterPost (lpv);
   if ( !lpv->bRevisioned )
      return e;
   if ( (!lpv->bAttachRequested && level>1+lpv->levelSwitched) ||
        (lpv->bAttachRequested && level>lpv->levelSwitched) )
      return e; // there is nothing at that level to post

   RVSPYPRINT (("RevisionInnerPost LEVEL=%d", level));
   RVSPYINDENT (1);

   for ( i=0; i<BASE_TBL_COUNT+TBL_COUNT; ++i )
      rev[i] = NULL;
   if ( DO_CASCADEPOST==CASCADEPOST_FIRST ) {
      CHECK_CALL_GOTO (e, cleanup,
         MapToDetails (lpv, VIEW_OP_REVISION_POST, level));
   }

   CHECK_CALL_GOTO (e, cleanup, ErrorMapDatabaseToExtended (lpv->wLinkNo,
      RevisionInnerDirty (lpv, level, &dirty)));

   revLevel = FindRevLevel (lpv, level-1);
   parent = revLevel->AttachedRevision;
   key = (FindRecord (lpv)) [BASE_TBL_COUNT];
   if ( parent==NULL ||
        blkCompare (key, parent->key, revLevel->iHdrPKeySize)!=0 )
      parent = RevisionInnerFind (lpv, key, level-1);

   // Generalize the 1+HDR_HAS_REVISIONS level
   if ( level==1+HDR_HAS_REVISIONS )
      RevisionMove (current.rev, FindTableRev (lpv), REVMOVE_CLEAR_SOURCE);

   if ( level<=HDR_HAS_REVISIONS ) {
      if ( parent!=NULL )
         postingref = &revLevel[1].revList;
      else {
         posting = revLevel[1].revList;
         revLevel[1].revList = NULL;
      }
   }

   if ( parent ) {
      // If the parent node was found, move the revisions into it
      CHECK_CALL_GOTO (e, cleanup, ErrorMapDatabaseToExtended (lpv->wLinkNo,
         RevisionInnerMove (lpv, parent, postingref, level-1,
                            REVMOVE_CANCEL_TARGET | REVMOVE_CLEAR_SOURCE)));
   } else {
      // If no parent node was found add the revisions to a new node at the
      // start of the revList
      parent = RevisionInnerAdd (lpv, postingref, key, level-1);
      if ( !parent ) {
         e = ERRNUM_MEMORY_NO_MORE;
         goto cleanup;
      }
   }
   revLevel->AttachedRevision = parent;
   if ( dirty )
      revLevel->dirty = TRUE;

   // forcibly cleanup up the REVLEVELs nested from level; sets V.levelSwitched
   MaxError (&e, ErrorMapDatabaseToExtended (lpv->wLinkNo,
      RevisionInnerCancel (lpv, level, rev)));
   if ( DO_CASCADEPOST!=CASCADEPOST_FIRST ) {
      MaxError (&e, MapToDetails (lpv, VIEW_OP_REVISION_POST, level));
   }
   MaxError (&e, ErrorMapDatabaseToExtended (lpv->wLinkNo,
      RevisionInnerCreate (lpv, lpv->levelSwitched)));

cleanup:
   RVSPYINDENT (-1);
   if ( ERRNUM_IS_FAILURE (e) )
      RVSPYTRACE ("RevisionInnerPost FAILED");
   else
      RVSPYTRACE ("RevisionInnerPost SUCCEEDED");

   return e;
}



DB_ERRNUM WINAPI RevisionInnerSegments (LPV lpv, INT level)
{
   DB_ERRNUM d = DBS_SUCCESS;

   if ( HDR_HAS_REVISIONS==0 )
      return d;
   if ( !lpv->bRevisioned )
      return d;

   RVSPYPRINT (("RevisionInnerSegments LEVEL=%d", level));
   RVSPYINDENT (1);
   while ( level<=HDR_HAS_REVISIONS && level<=lpv->levelSwitched ) {
      CHECK_DBCALL (d,
         RevisionRecursiveSegments (lpv, FindRevLevel (lpv, level)->revList));
      ++level;
   }
   RVSPYINDENT (-1);
   RVSPYTRACE ("RevisionInnerSegments SUCCEEDED");
   return d;
}



DB_ERRNUM WINAPI RevisionInnerSwitch (LPV lpv, INT level, LPVOID key, LPREVNODE FAR *found)
{
   DB_ERRNUM d = DBS_SUCCESS;
   LPREVLEVEL revLevel = FindRevLevel (lpv, level);
   LPREVNODE current;
   LPREVISION rev = FindTableRev (lpv);

   VIEWASSERT (HDR_HAS_REVISIONS>0);
   VIEWASSERT (level>=1);
   VIEWASSERT (level<=HDR_HAS_REVISIONS);
   VIEWASSERT (revLevel!=NULL);
   if ( HDR_HAS_REVISIONS==0 )
      return d;
   if ( !lpv->bRevisioned )
      return d;

   RVSPYPRINT (("RevisionInnerSwitch LEVEL=%d", level));
   RVSPYINDENT (1);
   if ( key==NULL )
      key = (FindRecord (lpv)) [BASE_TBL_COUNT];
   revLevel->AttachedRevision = NULL;
   if ( level<HDR_HAS_REVISIONS )
      revLevel[1].dirty = FALSE;
   else
      lpv->bUnpostedRevisions = FALSE;
   current = RevisionInnerFind (lpv, key, level);
   if ( current==NULL ) {
      INT graftor;

      CHECK_DBCALL (d, RevisionInnerCancel (lpv, level+1, rev));
      CHECK_DBCALL (d, RevisionGenerate (lpv, rev, FindRevCache (lpv)));
      current = RevisionAdd (lpv, rev, key);
      for ( graftor=HDR_HAS_REVISIONS-1; graftor>=level; --graftor ) {
         current = RevisionInnerAdd (lpv, &FindRevLevel (lpv, graftor+1)->revList,
                                     key, graftor);
         if ( !current )
            return DBS_MEMORY;
      }
   }
   CHECK_DBCALL (d, RevisionInnerDuplicate (lpv, current, level));
   lpv->bAttachRequested = FALSE;
   lpv->levelSwitched = level;
   if ( found!=NULL )
      *found = current;
   RVSPYINDENT (-1);
   RVSPYTRACE ("RevisionInnerSwitch SUCCEEDED");

   return d;
}



void WINAPI RevisionMove (LPREVISION target, LPREVISION source, A4W_FLAGS flags)
{
   INT i;

   if ( !(SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS) )
      return;
   if ( HAS_REVISIONS==NO_REVISIONS )
      return;

   RVSPYPRINT (("RevisionMove FLAGS=0x%08lx", flags));
   for ( i=BASE_TBL_COUNT; i<BASE_TBL_COUNT+TBL_COUNT; ++i ) {
      if ( flags & REVMOVE_CANCEL_TARGET ) {
         if ( target[i] )
            revCancel (target[i]);
      }
      target[i] = source[i];
      if ( flags & REVMOVE_CLEAR_SOURCE )
         source[i] = NULL;
   }
}



DB_ERRNUM WINAPI RevisionOuterCancel (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;

   if ( HAS_REVISIONS==NO_REVISIONS )
      return d;
   if ( !lpv->bRevisioned )
      return d;

   RVSPYTRACE ("RevisionOuterCancel");
   RVSPYINDENT (1);
   CHECK_DBCALL (d, RevisionInnerCancel (lpv, 1, NULL));
   RVSPYINDENT (-1);
   RVSPYTRACE ("RevisionOuterCancel SUCCEEDED");
   return d;
}



DB_ERRNUM WINAPI RevisionOuterDirty (LPV lpv, LPBOOL dirty)
{
   DB_ERRNUM d = DBS_SUCCESS;

   RVSPYTRACE ("RevisionOuterDirty");
   RVSPYINDENT (1);
   CHECK_DBCALL (d, RevisionInnerDirty (lpv, 1, dirty));
   RVSPYINDENT (-1);
   RVSPYPRINT (("RevisionOuterDirty RESULT=%d", *dirty));
   return d;
}



VIEWBASE RevisionOuterPost (LPV lpv)
// OVER
{
   ERRNUM e = ERRNUM_SUCCESS;
   DB_ERRNUM d = DBS_SUCCESS;

   if ( !(SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS) )
      return d;
   if ( HAS_REVISIONS==NO_REVISIONS )
      return e;

   RVSPYTRACE ("RevisionOuterPost");
   RVSPYINDENT (1);
   d = fileTransBegin (lpv);
   CHECK_CALL_GOTO (e, cleanup, ErrorMapDatabaseToExtended (lpv->wLinkNo, d));

   // From here on errors get accumulated but otherwise ignored
   // so that the revision trees can get recreated

   if ( DO_CASCADEPOST==CASCADEPOST_FIRST ) {
      MaxError (&e, MapToDetails (lpv, VIEW_OP_POST));
   }

   lpv->bConsuming = TRUE;
   lpv->bConsumingRekeys = TRUE;
   if ( HDR_HAS_REVISIONS>0 )
      memset (FindRevRekey (lpv, 1), 0, HDR_HAS_REVISIONS*sizeof (LPREVNODE FAR *));
   while ( ERRNUM_IS_SUCCESS (e) && RevisionConsume (lpv) ) {
      MaxError (&e, RevisionPost (lpv));
   }

   if ( ERRNUM_IS_FAILURE (e) ) {
      MaxError (&e, ErrorMapDatabaseToExtended (
                       lpv->wLinkNo, RevisionOuterCancel (lpv)));
      MaxError (&e, ErrorMapDatabaseToExtended (
                       lpv->wLinkNo, RevisionCreate (lpv)));
   } else {
      LPREVLEVEL revLevel = FindRevLevel (lpv, 1);
      LPREVISION rev = FindTableRev (lpv);

      if ( HDR_HAS_REVISIONS>0 ) {
         MaxError (&e, ErrorMapDatabaseToExtended (
                          lpv->wLinkNo, RevisionInnerCancel (lpv, 2, NULL)));
         lpv->levelSwitched = 0; // since level 1 was successfully posted
      }
      MaxError (&e, ErrorMapDatabaseToExtended (
                       lpv->wLinkNo, RevisionCreate (lpv)));
      if ( HDR_HAS_REVISIONS>0 ) {
         revLevel->dirty = FALSE;
         // Clear away the tree of pending rekeys (won't have been used, but be safe)
         while ( RevisionRecursiveConsume (lpv, &revLevel->RekeyPending, 1, rev) ) {
            MaxError (&e, ErrorMapDatabaseToExtended (
                             lpv->wLinkNo, RevisionCancel (lpv, rev)));
         }
      }
      if ( DO_CASCADEPOST!=CASCADEPOST_FIRST ) {
         MaxError (&e, MapToDetails (lpv, VIEW_OP_POST));
      }
   }

   if ( ERRNUM_IS_FAILURE (e) ) {
      d = fileTransRollback (lpv);
   } else {
      d = fileTransCommit (lpv);
   }
   MaxError (&e, ErrorMapDatabaseToExtended (lpv->wLinkNo, d));

cleanup:
   RVSPYINDENT (-1);
   if ( ERRNUM_IS_FAILURE (e) )
      RVSPYTRACE ("RevisionOuterPost FAILED");
   else
      RVSPYTRACE ("RevisionOuterPost SUCCEEDED");
   return e;
}



DB_ERRNUM WINAPI RevisionOuterSegments (LPV lpv)
// OVER
{
   DB_ERRNUM d = DBS_SUCCESS;

   RVSPYTRACE ("RevisionOuterSegments");
   RVSPYINDENT (1);
   CHECK_DBCALL (d, fileFilterSegs (lpv));
   if ( HAS_REVISIONS!=NO_REVISIONS && lpv->bRevisioned ) {
      CHECK_DBCALL (d, RevisionInnerSegments (lpv, 1));
   }
   RVSPYINDENT (-1);
   RVSPYTRACE ("RevisionOuterSegments SUCCEEDED");
   return d;
}



VIEWBASE RevisionPost (LPV lpv)
// OVER
{
   ERRNUM e = ERRNUM_SUCCESS;
   REV_ERRNUM r = POST_DONE;

   RVSPYTRACE ("RevisionPost");
   if ( SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS ) {
      RVSPYINDENT (1);
      while ( (r = filePost (lpv))==POST_CONTINUE )
         RVSPYTRACE ("RevisionPost RECORD");
      if ( r==POST_ERROR ) {
         MaxError (&e, ErrorMapDatabaseToExtended (lpv->wLinkNo, lpv->eRevision));
         RevisionCancel (lpv, FindTableRev (lpv));
      }
      RVSPYINDENT (-1);
   }

   if ( ERRNUM_IS_FAILURE (e) )
      RVSPYTRACE ("RevisionPost FAILED");
   else
      RVSPYTRACE ("RevisionPost SUCCEEDED");
   return e;
}



DB_ERRNUM RevisionRealize (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;
   INT level, start;

   if ( HDR_HAS_REVISIONS==0 )
      return d;
   if ( !lpv->bRevisioned )
      return d;

   RVSPYTRACE ("RevisionRealize");
   RVSPYINDENT (1);

   start = lpv->levelSwitched;
   if ( lpv->bAttachRequested && start>0 )
      --start;

   level = start;
   if ( level<HDR_HAS_REVISIONS ) {
      // Do the switch that was postponed
      LPREVLEVEL revLevel = FindRevLevel (lpv, start);

      while ( level<HDR_HAS_REVISIONS ) {
         ++level;
         ++revLevel;
         CHECK_DBCALL_GOTO (d, cleanup,
            RevisionInnerSwitch (lpv, level, NULL, &revLevel->AttachedRevision));
      }
   }

   if ( level>start )
      RevisionSpyLevels (lpv);

   if ( lpv->bAttachRequested ) {
      // Do the postponed attaching . . . .
      for ( level=start; level>0; --level ) {
         CHECK_DBCALL_GOTO (d, cleanup, RevisionInnerAttach (lpv, level));
      }
      lpv->bAttachRequested = FALSE;
   }

cleanup:
   RVSPYINDENT (-1);
   if ( DB_ERRNUM_IS_SUCCESS (d) )
      RVSPYTRACE ("RevisionRealize SUCCEEDED");
   else
      RVSPYTRACE ("RevisionRealize FAILED");
   return d;
}



BOOL WINAPI RevisionRecursiveConsume (LPV lpv, LPREVNODE FAR *anchor, INT level, LPREVISION rev)
// In-order depth-first traversal of the given tree, consuming it
{
   BOOL more = FALSE;
   LPREVNODE current;

   if ( !(SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS) )
      return more;
   if ( HAS_REVISIONS==NO_REVISIONS )
      return more;
   if ( HDR_HAS_REVISIONS==0 )
      return more;
   if ( !lpv->bRevisioned )
      return more;

   RVSPYPRINT (("RevisionRecursiveConsume LEVEL=%d", level));
   current = *anchor;
   if ( !current )
      return FALSE;
   if ( rev==NULL )
      rev = FindTableRev (lpv);

   RVSPYINDENT (1);
   if ( !current->revList ) {
      // Termination condition: at the leaves, where only revision lists are
      RevisionSpy (lpv, current, HDR_HAS_REVISIONS+1);
      RevisionMove (rev, current->rev, REVMOVE_CANCEL_TARGET);
      *anchor = current->pNext;
      memFree (current);
      more = TRUE;
   } else {
      // node has branches underneath, so consume those first
      more = RevisionRecursiveConsume (lpv, &current->revList, level+1, rev);
      if ( !current->revList ) {
         *anchor = current->pNext;
         memFree (current);
      }
   }
   RVSPYINDENT (-1);
   RVSPYTRACE ("RevisionRecursiveConsume SUCCEEDED");

   return more;
}



BOOL WINAPI RevisionRecursiveConsumeRekeys (LPV lpv, LPREVNODE FAR *anchor, INT level, LPREVISION rev)
// In-order depth-first traversal of the given tree, consuming it
{
   BOOL more = FALSE;
   LPREVNODE current;
   LPREVNODE **stack;

   if ( !(SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS) )
      return more;
   if ( HAS_REVISIONS==NO_REVISIONS )
      return more;
   if ( HDR_HAS_REVISIONS==0 )
      return more;
   if ( !lpv->bRevisioned )
      return more;

   RVSPYPRINT (("RevisionRecursiveConsumeRekeys LEVEL=%d", level));
   stack = FindRevRekey (lpv, level);
   if ( NULL==*stack )
      *stack = anchor;
   current = **stack;
   if ( !current )
      return FALSE;
   if ( rev==NULL )
      rev = FindTableRev (lpv);

   RVSPYINDENT (1);
   if ( !current->revList ) {
      // Termination condition: at the leaves, where only revision lists are
      while ( current && !(current->flags & REVNODE_REKEY_SOURCE) ) {
         *stack = &current->pNext;
         current = current->pNext;
      }
      if ( current ) {
         RevisionSpy (lpv, current, HDR_HAS_REVISIONS+1);
         RevisionMove (rev, current->rekey, REVMOVE_CANCEL_TARGET | REVMOVE_CLEAR_SOURCE);
         current->flags &= ~REVNODE_REKEY_SOURCE;
         if ( !(current->flags & REVNODE_REKEY_TARGET) ) {
            **stack = current->pNext;
            memFree (current);
         }
         more = TRUE;
      }
   } else {
      // node has branches underneath, so consume those first
      do {
         more = RevisionRecursiveConsumeRekeys (lpv, &current->revList, level+1, rev);
         if ( !more ) {
            *stack = &current->pNext;
            memset (stack+1, 0, (HDR_HAS_REVISIONS - level)*sizeof (LPREVNODE *));
            current = current->pNext;
         }
      } while ( !more && current );
      if ( current && !current->revList ) {
         **stack = current->pNext;
         memFree (current);
      }
   }
   RVSPYINDENT (-1);
   RVSPYTRACE ("RevisionRecursiveConsumeRekeys SUCCEEDED");

   return more;
}



DB_ERRNUM WINAPI RevisionRecursiveDuplicate (LPV lpv, LPREVNODE source, INT level, LPREVNODE FAR *target)
{
   DB_ERRNUM d = DBS_SUCCESS;
   LPREVLEVEL revLevel = FindRevLevel (lpv, level);
   INT i;
 #if BASE_TBL_COUNT+TBL_COUNT==0
   LPREVISION rev = NULL;
 #else
   REVISION rev [BASE_TBL_COUNT+TBL_COUNT];

   for ( i=0; i<ELEMENTS_OF(rev); ++i )
      rev[i] = NULL;
 #endif

   if ( !(SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS) )
      return d;
   if ( HAS_REVISIONS==NO_REVISIONS )
      return d;
   if ( HDR_HAS_REVISIONS==0 )
      return d;
   if ( !lpv->bRevisioned )
      return d;

   RVSPYPRINT (("RevisionRecursiveDuplicate LEVEL=%d", level));
   RVSPYINDENT (1);

   while ( RevisionRecursiveConsume (lpv, target, level, rev) ) {
      CHECK_DBCALL (d, RevisionCancel (lpv, rev));
   }

   while ( source!=NULL ) {
      LPREVNODE current = (LPREVNODE) memAlloc (sizeof(REVNODE) + revLevel->iHdrPKeySize);

      if ( current==NULL ) {
         ReportMemoryError (lpv, MAKE_OP_RSC (VIEW_OP (lpv, OPEN)));
         RVSPYINDENT (-1);
         RVSPYTRACE ("RevisionRecursiveDuplicate ERROR");
         return DBS_MEMORY;
      }
      current->key = current+1;
      blkCopy (current->key, source->key, revLevel->iHdrPKeySize);
      current->flags = 0;
      *target = current;
      if ( level==HDR_HAS_REVISIONS ) {
         VIEWASSERT (source->revList==NULL);
         CHECK_DBCALL (d, RevisionDuplicate (lpv, current->rev, source->rev));
      } else {
         VIEWASSERT (source->revList!=NULL);
         CHECK_DBCALL (d,
            RevisionRecursiveDuplicate (lpv, source->revList, level+1, &current->revList));
      }
      RevisionSpy (lpv, current, level);
      source = source->pNext;
      target = &current->pNext;
   }
   RVSPYINDENT (-1);
   RVSPYTRACE ("RevisionRecursiveDuplicate SUCCEEDED");

   return d;

}



BOOL RevisionRecursiveFind (LPV lpv, INT level, LPVOID key, LPREVNODE FAR *root, PREVGRAFTPOINT graft)
{
   DB_ERRNUM d = DBS_SUCCESS;
   LPREVLEVEL revLevel = FindRevLevel (lpv, level);
   LPREVNODE current = NULL;

   if ( HDR_HAS_REVISIONS==0 )
      return d;
   if ( !lpv->bRevisioned )
      return d;
   if ( level>HDR_HAS_REVISIONS )
      return d;

   VIEWASSERT (level>=1);
   RVSPYPRINT (("RevisionRecursiveFind LEVEL=%d", level));
   RVSPYINDENT (1);

   while ( level<=HDR_HAS_REVISIONS ) {
      current = *root;
      while ( current!=NULL &&
              blkCompare (current->key, key, revLevel->iHdrPKeySize)!=0 )
         current = current->pNext;

      if ( current==NULL )
         break;

      root = &current->revList;
      RevisionSpy (lpv, current, level);
      ++revLevel;
      ++level;
   }

   graft->root = root;
   graft->level = level;
   graft->found = current;
   graft->key = key;

   RVSPYINDENT (-1);
   if ( current!=NULL ) {
      RVSPYTRACE ("RevisionRecursiveFind SUCCEEDED");
      return TRUE;
   } else {
      RVSPYTRACE ("RevisionRecursiveFind FAILED");
      return FALSE;
   }
}



DB_ERRNUM WINAPI RevisionRecursiveSegments (LPV lpv, LPREVNODE current)
// Depth-first in-order traversal of a given tree, setting the filter segments
{
   DB_ERRNUM d = DBS_SUCCESS;

   if ( !(SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS) )
      return d;
   if ( HAS_REVISIONS==NO_REVISIONS )
      return d;
   if ( HDR_HAS_REVISIONS==0 )
      return d;
   if ( !lpv->bRevisioned )
      return d;

   RVSPYTRACE ("RevisionRecursiveSegments");
   RVSPYINDENT (1);
   while ( current!=NULL ) {
      if ( !current->revList ) {
         CHECK_DBCALL (d, RevisionSegments (lpv, current->rev));
      } else {
         CHECK_DBCALL (d, RevisionRecursiveSegments (lpv, current->revList));
      }
      current = current->pNext;
   }
   RVSPYINDENT (-1);
   RVSPYTRACE ("RevisionRecursiveSegments SUCCEEDED");

   return d;
}



DB_ERRNUM WINAPI RevisionRekey (LPV lpv, LPVOID OldKey, LPVOID NewKey, INT size, A4W_FLAGS flags)
{
   DB_ERRNUM d = DBS_SUCCESS;
#if HAS_REVISIONS!=NO_REVISIONS && (SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS)
   DB_ERRNUM f = DBS_SUCCESS;
   LPSTR key = (FindRecord (lpv)) [BASE_TBL_COUNT];
   CHAR record [MAX_RECORD_LENGTH];
   BYTE inserted [MAX_KEY_SIZE];
   BYTE found [MAX_KEY_SIZE];
   BYTE from [MAX_KEY_SIZE];
   REVISION OldHandles [BASE_TBL_COUNT+TBL_COUNT];
   LPREVISION OldRev = FindTableRev (lpv);
   REVISION NewHandles [BASE_TBL_COUNT+TBL_COUNT];
   LPREVISION NewRev = NewHandles;
   INT i = BASE_TBL_COUNT;
   INT primary;
   ERRNUM e = ERRNUM_SUCCESS;
   LPREVLEVEL revLevel = FindRevLevel (lpv, HDR_HAS_REVISIONS);
   INT level = (flags & MASK_REVISION_REKEY_LEVEL) >> SHIFT_REVISION_REKEY_LEVEL;
   INT switchfrom = level;
   INT switchto = level;
   BOOL TemporarySource = FALSE;
   BOOL checked;
   INT iHdrPKeySize;
   REVGRAFTPOINT source;
   REVGRAFTPOINT target;

   if ( !lpv->bRevisioned )
      return d;

   primary = FindTableMapV (lpv, i)->fields[SCINIT_FLD_AUDIT].wOffset;
   if ( HDR_HAS_REVISIONS==0 )
      // Note: this only works for MP3 records
      iHdrPKeySize = (INT) FindTableMapV (lpv, i)->fields[SCINIT_FLD_AUDIT - DTL_SEG_COUNT].wOffset;
   else
      iHdrPKeySize = revLevel->iHdrPKeySize;
   VIEWASSERT (primary>=iHdrPKeySize);
   VIEWASSERT (size==iHdrPKeySize);
   if ( size!=iHdrPKeySize ) {
      ReportGenericError (lpv, ERRGEN_AREA_DATABASE, 0, DBS_BUFFER_SIZE, NULL);
      return DBS_BUFFER_SIZE;
   }

   if ( HDR_HAS_REVISIONS==0 ) {
      VIEWASSERT (level==1);
      if ( level!=1 )
         return DBS_SUCCESS;

      RVSPYTRACE ("RevisionRekey");
      RVSPYINDENT (1);

      TemporarySource = TRUE;
      CHECK_DBCALL_GOTO (d, cleanup,
         RevisionGenerate (lpv, NewRev, FindRevCache (lpv)));

   } else {
      VIEWASSERT (level>=1 && level<=HDR_HAS_REVISIONS+1);
      if ( level<1 || level>HDR_HAS_REVISIONS+1 )
         return DBS_SUCCESS;

      if ( level<=HDR_HAS_REVISIONS && FindRevLevel (lpv, level)->RekeyPending==NULL ) {
         // determine the level from which we need to switch to the level being rekeyed
         revLevel = FindRevLevel (lpv, 0); // before start of array because level is 1-based
         for ( i=switchfrom=switchto=1; i<level; ++i ) {
            if ( blkCompare (key, OldKey, revLevel[i].iHdrPKeySize)==0 )
               ++switchfrom;
            if ( blkCompare (key, NewKey, revLevel[i].iHdrPKeySize)==0 &&
                 blkCompare (OldKey, NewKey, revLevel[i].iHdrPKeySize)==0 )
               ++switchto;
         }
         if ( switchto>switchfrom )
            switchto = switchfrom;

         i = lpv->levelSwitched;
         if ( 0==i || !lpv->bAttachRequested )
            ++i;
         revLevel = FindRevLevel (lpv, i);
         while ( i<switchto ) {
            CHECK_DBCALL_GOTO (d, cleanup,
               RevisionInnerSwitch (lpv, i, NULL, &revLevel->AttachedRevision));
            ++i;
            ++revLevel;
         }
      }

      RVSPYPRINT (("RevisionRekey LEVEL=%d SWITCHFROM=%d SWITCHTO=%d", level, switchfrom, switchto));
      RVSPYINDENT (1);

      if ( level>HDR_HAS_REVISIONS ) {
         // If innermost, then just deal with raw REVISION handles
         // Other variables are initialized for this when declared above
         TemporarySource = TRUE;
         CHECK_DBCALL_GOTO (d, cleanup,
            RevisionGenerate (lpv, NewRev, FindRevCache (lpv)));

      } else {
         LPREVNODE FAR *root;
         LPREVNODE pending;

         revLevel = FindRevLevel (lpv, level);

         // Setup source revision context
         if ( revLevel->RekeyPending==NULL ) {
            for ( i=switchfrom; i<=level-1; ++i ) {
               CHECK_DBCALL_GOTO (d, cleanup,
                  RevisionInnerSwitch (lpv, i, OldKey, NULL));
            }
            if ( switchto<switchfrom || switchto<level ) {
               CHECK_DBCALL_GOTO (d, cleanup, RevisionRecursiveDuplicate (
                  lpv, revLevel->revList, level, &revLevel->RekeyPending));
            }
         }
         if ( revLevel->RekeyPending==NULL )
            root = &revLevel->revList;
         else {
            root = &revLevel->RekeyPending;
            TemporarySource = TRUE;
         }
         if ( RevisionRecursiveFind (lpv, switchto, OldKey, root, &source) ) {
            OldRev = source.found->rekey;
            RevisionMove (OldRev, source.found->rev,
                          REVMOVE_CANCEL_TARGET | REVMOVE_CLEAR_SOURCE);
            source.found->flags |=  REVNODE_REKEY_SOURCE;
            source.found->flags &= ~REVNODE_REKEY_TARGET;
         } else {
            OldRev = OldHandles;
            CHECK_DBCALL_GOTO (d, cleanup,
               RevisionGenerate (lpv, OldRev, FindRevCache (lpv)));
         }

         // Setup target revision context
         if ( TemporarySource ) {
            // Squirrel away the pending rekeys so they don't get hammered by the switch
            pending = *root;
            *root = NULL;
         }
         revLevel = FindRevLevel (lpv, switchto);
         for ( i=switchto; i<=level-1; ++i ) {
            CHECK_DBCALL_GOTO (d, cleanup,
               RevisionInnerSwitch (lpv, i, NewKey, &revLevel->AttachedRevision));
            ++revLevel;
         }
         if ( RevisionRecursiveFind (lpv, switchto, NewKey, root, &target) ) {
            NewRev = target.found->rev;
            if ( (target.found->flags & REVNODE_REKEY_SOURCE) &&
                !(target.found->flags & REVNODE_REKEY_TARGET) ) {
               // There are no revision handles, so generate 'em
               CHECK_DBCALL (d, RevisionGenerate (lpv, NewRev, FindRevCache (lpv)));
            }
            target.found->flags |= REVNODE_REKEY_TARGET;
         } else {
            CHECK_DBCALL_GOTO (d, cleanup,
               RevisionGenerate (lpv, NewRev, FindRevCache (lpv)));
         }
         if ( TemporarySource )
            *root = pending; // Restore the pending rekeys
      }

      if ( TemporarySource )
         RVSPYTRACE ("SOURCE NODE WILL BE DISCARDED");
      revLevel = FindRevLevel (lpv, HDR_HAS_REVISIONS);
   }

   i = BASE_TBL_COUNT;
   CHECK_DBCALL_GOTO (d, cleanup,
      ErrorMapViewToDatabase (VIEW_OP_REVISION_REKEY, InitFields (lpv)));
   blkCopy (record, key, FindTableWidth (lpv, i));
   blkCopy (record, NewKey, size);
   blkCopy (inserted, record, primary);
   blkCopy (record, OldKey, size);
   blkCopy (from, record, primary);
   checked = RevisionCheckDuplicates (lpv, FALSE, NewRev);
   revBrowse (OldRev[i], record, 1);
   CHECK_DBCALL_GOTO (d, cleanup,
      revErrorV (lpv, OldRev[i], revGetExtendedError (OldRev[i])));

   for (;;) {
      revFetch (OldRev[i], record);
      f = revGetExtendedError (OldRev[i]);
      // CHECK_DBFETCH is NOT being used because there is no way to selective report an error
      if ( DB_ERRNUM_IS_FAILURE (f) ) {
         if ( f==DBS_NO_MORE_DATA )
            break;
         d = revErrorV (lpv, OldRev[i], f);
         goto cleanup;
      }
      RVSPYTRACE ("RevisionRekey RECORD");

      blkCopy (found, record, primary);
      if ( !TemporarySource ) {
         revDelete (OldRev[i], record);
         CHECK_DBCALL_GOTO (d, cleanup,
            revErrorV (lpv, OldRev[i], revGetExtendedError (OldRev[i])));
      }

      if ( HAS_REVISIONS==ORDER_REVISIONS ) {
         blkCopy (record, NewKey, size);
         revInsert (NewRev[i], record);
      } else {
         blkCopy (record, inserted, primary);
         revInsertAfter (NewRev[i], record);
      }
      CHECK_DBCALL_GOTO (d, cleanup,
         revErrorV (lpv, NewRev[i], revGetExtendedError (NewRev[i])));

      blkCopy (inserted, record, primary);
      for ( i=BASE_TBL_COUNT+1; i<BASE_TBL_COUNT+TBL_COUNT; ++i ) {
         blkCopy (record, found, primary);
         if ( revRead (OldRev[i], record) ) {
            if ( !TemporarySource ) {
               revDelete (OldRev[i], record);
               CHECK_DBCALL_GOTO (d, cleanup,
                  revErrorV (lpv, OldRev[i], revGetExtendedError (OldRev[i])));
            }

            blkCopy (record, inserted, primary);
            revInsert (NewRev[i], record);
            CHECK_DBCALL_GOTO (d, cleanup,
               revErrorV (lpv, NewRev[i], revGetExtendedError (NewRev[i])));
         }
      }
      e = MapToDetails (lpv, VIEW_OP_REVISION_REKEY, found, inserted,
                        primary, flags);
      CHECK_DBCALL_GOTO (d, cleanup,
         ErrorMapViewToDatabase (VIEW_OP_REVISION_REKEY, e));

      if ( HAS_REVISIONS==ORDER_REVISIONS )
         e = RekeyedRevision (lpv, level, found, inserted, size);
      else
         e = RekeyedRevision (lpv, level, found, inserted, primary);
      CHECK_DBCALL_GOTO (d, cleanup,
         ErrorMapViewToDatabase (VIEW_OP_REVISION_REKEY, e));
      i = BASE_TBL_COUNT;
   }

   RevisionCheckDuplicates (lpv, checked, NewRev);
   blkCopy (key, from, primary);
   blkCopy (key, NewKey, size);

   if ( level>HDR_HAS_REVISIONS || HDR_HAS_REVISIONS==0 ) {
      RevisionMove (FindTableRev (lpv), NewRev, REVMOVE_CANCEL_TARGET);
   } else {
      CHECK_DBCALL_GOTO (d, cleanup, RevisionInnerGraft (lpv, &source, OldRev, REVNODE_REKEY_SOURCE));
      CHECK_DBCALL_GOTO (d, cleanup, RevisionInnerGraft (lpv, &target, NewRev, REVNODE_REKEY_TARGET));
   }

cleanup:
   RVSPYINDENT (-1);
   if ( DB_ERRNUM_IS_SUCCESS (d) )
      RVSPYTRACE ("RevisionRekey SUCCEEDED");
   else
      RVSPYTRACE ("RevisionRekey FAILED");
#endif
   return d;
}



DB_ERRNUM WINAPI RevisionSegments (LPV lpv, LPREVISION rev)
// UNDER
// RevisionRealize() not needed. If the revision doesn't exist yet, if and when
// it gets created then the segments will get set at that time.
{
   DB_ERRNUM d = DBS_SUCCESS;

   lpv->wDetailFilterSegments = 0;
   if ( !(HDR_CMP_COUNT>0 && DTL_SEG_COUNT!=0 && TBL_COUNT>0) ||
        !(SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS) )
      return d;

   if ( FindCmp (lpv, 0)->view!=NULL && DetailKeyWithinHeader (lpv) ) {
      if ( SUBCLASS_LEVEL==NOT_SUBCLASS )
         lpv->wDetailFilterSegments = FindKeyDef (0)->segments;
      else
         lpv->wDetailFilterSegments = lpv->subCmpKey.segments;
      lpv->wDetailFilterSegments -= DTL_SEG_COUNT;
      if ( HAS_REVISIONS!=NO_REVISIONS && lpv->bRevisioned && rev[BASE_TBL_COUNT]!=NULL ) {
         revFilterSegs (rev[BASE_TBL_COUNT],
                        (WORD) lpv->wDetailFilterSegments);
         d = revGetExtendedError (rev[BASE_TBL_COUNT]);
         revErrorV (lpv, rev[BASE_TBL_COUNT], d);
      }
   }
   RVSPYPRINT (("RevisionSegments SEGMENTS=%d", lpv->wDetailFilterSegments));
   return d;
}



void RevisionSpy (LPV lpv, LPREVNODE node, INT level)
{
#if defined(VIEWDEBUG)
   CHAR message [4*MAX_KEY_SIZE];
   INT i, end;
   LPSTR delim = "";
   LPBYTE key;
   LPREVLEVEL revLevel = FindRevLevel (lpv, HDR_HAS_REVISIONS);
   LPREVISION rev;

   if ( HAS_REVISIONS==NO_REVISIONS )
      return;
   if ( HDR_HAS_REVISIONS==0 )
      return;
   if ( !lpv->bRevisioned )
      return;

   if ( node==NULL ) {
      rev = FindTableRev (lpv);
      key = (LPBYTE) FindRecord (lpv) [BASE_TBL_COUNT];
      level = HDR_HAS_REVISIONS+1;
   } else {
      rev = node->rev;
      key = (LPBYTE) node->key;
   }
   if ( level<HDR_HAS_REVISIONS )
      revLevel = FindRevLevel (lpv, level);

   end = sprintf (message, "REVNODE: LEVEL=%d [", level);
   if ( level>=HDR_HAS_REVISIONS ) {
      for ( i=BASE_TBL_COUNT; i<BASE_TBL_COUNT+TBL_COUNT; ++i ) {
         end += sprintf (message+end, "%s0x%08lx", delim, (long) rev[i]);
         delim = ", ";
      }
   } else {
      end += sprintf (message+end, "0x%08lx", (long) node->revList);
   }
   end += sprintf (message+end, "] ");
   for ( i=0; i<revLevel->iHdrPKeySize; ++i )
      end += sprintf (message+end, "\\%02x", key[i]);

   if ( VIEWDEBUG==VIEWDEBUG_ALL || VIEWDEBUG==VIEWDEBUG_NESTED_DETAILS ) {
      if ( level<HDR_HAS_REVISIONS ) {
         int r = 0;
         LPREVNODE scan;

         for ( scan=node->revList; scan; scan=scan->pNext )
            ++r;
         end += sprintf (message+end, " ## %d", r);
      } else {
         int r = 0;
         char rec[MAX_RECORD_LENGTH];

         if ( rev[BASE_TBL_COUNT]!=NULL ) {
            blkSet (rec, 0, sizeof(rec));
            blkCopy (rec, key, revLevel->iHdrPKeySize);
            revBrowse (rev[BASE_TBL_COUNT], rec, 1);
            while ( revFetch (rev[BASE_TBL_COUNT], rec) )
               ++r;
         }
         end += sprintf (message+end, " # %d", r);
      }
   }

   if ( revLevel->AttachedRevision!=NULL && node==revLevel->AttachedRevision ) {
      end += sprintf (message+end, " ***");
   }
   if ( level>=HDR_HAS_REVISIONS &&
        (rev[BASE_TBL_COUNT]!=NULL && revDirty (rev[BASE_TBL_COUNT])) ) {
      end += sprintf (message+end, " & DIRTY");
   }
   if ( level==HDR_HAS_REVISIONS &&
        (node->flags & (REVNODE_REKEY_SOURCE | REVNODE_REKEY_TARGET))!=0 ) {
      end += sprintf (message+end, " & REKEY");
      if ( node->flags & REVNODE_REKEY_SOURCE )
         end += sprintf (message+end, "+SOURCE");
      if ( node->flags & REVNODE_REKEY_TARGET )
         end += sprintf (message+end, "+TARGET");
   }

   RVSPYTRACE (message);
#endif
}



void RevisionSpyLevels (LPV lpv)
{
#if defined(VIEWDEBUG)
   INT level;

   if ( HAS_REVISIONS==NO_REVISIONS )
      return;
   if ( HDR_HAS_REVISIONS==0 )
      return;
   if ( !lpv->bRevisioned )
      return;

   RVSPYPRINT (("FOREST DUMP, V.levelSwitched = %d, %s", lpv->levelSwitched,
                (lpv->bAttachRequested ? "ATTACH REQUESTED" : "ATTACHED")));
   RVSPYINDENT (1);
   for ( level=1; level<=HDR_HAS_REVISIONS; ++level ) {
      LPREVLEVEL revLevel = FindRevLevel (lpv, level);

      RVSPYPRINT (("REVLEVEL = %d, ATTACHED [0x%08lx]", level, revLevel->AttachedRevision));
      RevisionSpyTree (lpv, revLevel->revList, level);
      if ( revLevel->RekeyPending!=NULL ) {
         RVSPYPRINT (("REKEYPENDING = %d", level));
         RevisionSpyTree (lpv, revLevel->RekeyPending, level);
      }
   }
   RVSPYPRINT (("REVLEVEL = %d", level));
   RVSPYINDENT (1);
   RevisionSpy (lpv, NULL, level);
   RVSPYINDENT (-2);
#endif
}



void RevisionSpyTree (LPV lpv, LPREVNODE node, INT level)
{
#if defined(VIEWDEBUG)
   if ( HAS_REVISIONS==NO_REVISIONS )
      return;
   if ( HDR_HAS_REVISIONS==0 )
      return;
   if ( !lpv->bRevisioned )
      return;

   RVSPYINDENT (1);
   while ( node!=NULL ) {
      RevisionSpy (lpv, node, level);
      RevisionSpyTree (lpv, node->revList, level+1);
      node = node->pNext;
   }
   RVSPYINDENT (-1);
#endif
}



DB_ERRNUM RevisionWasRealized (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;

   if ( HAS_REVISIONS==NO_REVISIONS )
      return d;
   if ( HDR_HAS_REVISIONS==0 )
      return d;
   if ( !lpv->bRevisioned )
      return d;

   VIEWASSERT (lpv->levelSwitched>=HDR_HAS_REVISIONS && !lpv->bAttachRequested);
   if ( lpv->levelSwitched<HDR_HAS_REVISIONS || lpv->bAttachRequested ) {
      // This is an internal protocol error (AKA template bug).
      d = DBS_NOT_ALLOWED;
      ReportGenericError (lpv, ERRGEN_AREA_REVLIST, 0, d, NULL);
      RVSPYTRACE ("RevisionWasRealized FAILED");
      return d;
   }
   RVSPYTRACE ("RevisionWasRealized SUCCEEDED");
   return d;
}



/*--------------------------------------------------------------------------*
 * This section is activated for non-stub and non-super views. Since the    *
 * intent of stub views is usually to perform file I/O to destinations      *
 * other than the database, you must enter code which goes to the           *
 * appropriate destination. Typically this will be to export using the      *
 * recioXXXX and xExportXXXX routines. If you still need to perform database*
 * I/O, copy these corresponding functions out of the scInit.C file replacing *
 * the ones here. The semantics of these functions must be maintained       *
 * precisely. As well, each function should report any errors on the message*
 * stack, though there are some exceptions noted. The V structure is fully  *
 * available and useful; there is one change, though: you can #define the   *
 * symbol TABLEHANDLE to be the type appropriate to your stub. Usually it is*
 * WORD, and is used to define the ahTables array member of V.              *
 *--------------------------------------------------------------------------*/



#if !defined(DO_fileAdd)
#define fileAddBase  fileAdd
#endif

#if !defined(DO_fileBegin)
#define fileBeginBase   fileBegin
#endif

#if !defined(DO_fileCancel)
#define fileCancelBase  fileCancel
#endif

#if !defined(DO_fileClose)
#define fileCloseBase   fileClose
#endif

#if !defined(DO_fileCommit)
#define fileCommitBase  fileCommit
#endif

#if !defined(DO_fileCreate)
#define fileCreateBase  fileCreate
#endif

#if !defined(DO_fileDelete)
#define fileDeleteBase  fileDelete
#endif

#if !defined(DO_fileDirty)
#define fileDirtyBase   fileDirty
#endif

#if !defined(DO_fileDriverInfo)
#define fileDriverInfoBase fileDriverInfo
#endif

#if !defined(DO_fileDrop)
#define fileDropBase fileDrop
#endif

#if !defined(DO_fileEmpty)
#define fileEmptyBase   fileEmpty
#endif

#if !defined(DO_fileError)
#define fileErrorBase   fileError
#endif

#if !defined(DO_fileFilterCount)
#define fileFilterCountBase fileFilterCount
#endif

#if !defined(DO_fileFilterDelete)
#define fileFilterDeleteBase fileFilterDelete
#endif

#if !defined(DO_fileFilterSegs)
#define fileFilterSegsBase fileFilterSegs
#endif

#if !defined(DO_fileFirst)
#define fileFirstBase   fileFirst
#endif

#if !defined(DO_fileGet)
#define fileGetBase  fileGet
#endif

#if !defined(DO_fileInfo)
#define fileInfoBase fileInfo
#endif

#if !defined(DO_fileInsert)
#define fileInsertBase  fileInsert
#endif

#if !defined(DO_fileIsLocked)
#define fileIsLockedBase   fileIsLocked
#endif

#if !defined(DO_fileLinkFlags)
#define fileLinkFlagsBase  fileLinkFlags
#endif

#if !defined(DO_fileLocate)
#define fileLocateBase  fileLocate
#endif

#if !defined(DO_fileLock)
#define fileLockBase fileLock
#endif

#if !defined(DO_fileNext)
#define fileNextBase fileNext
#endif

#if !defined(DO_fileOpen)
#define fileOpenBase fileOpen
#endif

#if !defined(DO_fileOptLock)
#define fileOptLockBase fileOptLock
#endif

#if !defined(DO_filePrePost)
#define filePrePostBase filePrePost
#endif

#if !defined(DO_filePost)
#define filePostBase filePost
#endif

#if !defined(DO_fileReverses)
#define fileReversesBase   fileReverses
#endif

#if !defined(DO_fileRollback)
#define fileRollbackBase   fileRollback
#endif

#if !defined(DO_fileSelectFields)
#define fileSelectFieldsBase fileSelectFields
#endif

#if !defined(DO_fileTransBegin)
#define fileTransBeginBase fileTransBegin
#endif

#if !defined(DO_fileTransCommit)
#define fileTransCommitBase fileTransCommit
#endif

#if !defined(DO_fileTransRollback)
#define fileTransRollbackBase fileTransRollback
#endif

#if !defined(DO_fileUnLock)
#define fileUnLockBase  fileUnLock
#endif

#if !defined(DO_fileUpdate)
#define fileUpdateBase  fileUpdate
#endif



#if !defined(STUB_VIEW)

DB_ERRNUM WINAPI fileAddBase (WORD wLinkNo, HPIB hpib)
{
   DB_ERRNUM d = DBS_SUCCESS;
   WORD t = 0, i = 0, j = 0;
   LPV lpv = NULL;
   LPWORD k = NULL;
   LPSTR fields = NULL;
   DBTABLE table;
   LPTBLMAP tab = NULL;

   if ( TBL_COUNT>0 ) {
      for ( t=BASE_TBL_COUNT; t<BASE_TBL_COUNT+TBL_COUNT; ++t ) {
         tab = FindTableMap (t);
         CHECK_DBCALL_GOTO (d, error,
            fileError (wLinkNo, hpib,
                       dbCreateTable (wLinkNo, tab->table, tab->fields, tab->keys)));
      }
   }

   if ( BASE_TBL_COUNT>0 ) {
      CHECK_DBCALL_GOTO (d, error, fileInfo (wLinkNo, hpib, 0, &table));
      fields = (LPSTR) _alloca (table.wNoOfFields * SIZEOF_FIELDNAME);
      if ( fields==NULL ) {
         ReportBaseMemoryError (hpib, MAKE_OP_RSC(VIEW_OP_CREATE));
         CHECK_DBCALL_GOTO (d, error, DBS_CVIEW_GENERAL);
      }
      tab = FindTableMap (0);
      CHECK_DBCALL_GOTO (d, error,
         fileError (wLinkNo, hpib,
                    dbGetFieldNames (wLinkNo, tab->table->sName,
                                     FLG_FIELD_ORDER, fields,
                                     (WORD) (table.wNoOfFields * SIZEOF_FIELDNAME), &i)));
      CHECK_DBCALL_GOTO (d, error,
         fileError (wLinkNo, hpib,
                    dbAddFields (wLinkNo,
                                 tab->table->sName,
                                 tab->table->wNoOfFields,
                                 tab->fields,
                                 fields + (table.wNoOfFields-1)*SIZEOF_FIELDNAME)));
   }

#if defined(DO_CREATEETC)
   MaxDatabaseError (&d, ErrorMapViewToDatabase (VIEW_OP_OPEN,
                                                 scInitOpen (hpib, wLinkNo, (LPVOID *) &lpv)));
   if ( DB_ERRNUM_IS_SUCCESS (d) ) {
      MaxDatabaseError (&d, fileBegin (lpv));
      fileError (wLinkNo, hpib, d);
      if ( DB_ERRNUM_IS_SUCCESS (d) ) {
         MaxDatabaseError (&d, ErrorMapViewToDatabase (VIEW_OP_CREATE,
                                                       CreateEtc (lpv)));
         if ( DB_ERRNUM_IS_SUCCESS (d) ) {
            MaxDatabaseError (&d, fileCommit (lpv));
         } else {
            MaxDatabaseError (&d, fileRollback (lpv));
         }
      }
      scInitClose (lpv);
   }
   if ( DB_ERRNUM_IS_FAILURE (d) )
      goto error;
#endif

   if ( BASE_TBL_COUNT>0 && KEY_COUNT>0 ) {
      // Having successfully added fields, add any keys too.
      tab = FindTableMap (0);
      k = tab->keys;
      for ( i=0; i<tab->table->wNoOfKeys; ++i ) {
         DBKEY key;

         key.wKeyNo = i + table.wNoOfKeys;
         key.wFlags = *k++;
         key.wNoOfSegments = *k++;
         for ( j=0; j<key.wNoOfSegments; ++j )
            blkCopy (key.sFieldNames + j*SIZEOF_FIELDNAME,
                     ((k[j] & KEY_FROMBASE) ?
                      fields + SIZEOF_FIELDNAME * (k[j] & ~KEY_FROMBASE) :
                      tab->fields[k[j]].sName),
                     SIZEOF_FIELDNAME);
         k += key.wNoOfSegments;
         CHECK_DBCALL_GOTO (d, error,
            fileError (wLinkNo, hpib,
                       dbAddKey (wLinkNo, tab->table->sName, &key)));
      }
   }

   goto cleanup;

error:
   if ( TBL_COUNT>0 ) {
      while ( t-->BASE_TBL_COUNT )
         dbDropTable (wLinkNo, FindTableMap (t)->table->sName);
   }

cleanup:
   return d;
}



DB_ERRNUM WINAPI fileBeginBase (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;

#if !defined(DETAIL_VIEW)
   if ( !(SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS) )
      return d;
   if ( HAS_REVISIONS!=NO_REVISIONS )
      return d;
   CHECK_DBCALL (d, fileTransBegin (lpv));
#endif
   return d;
}



DB_ERRNUM WINAPI fileCancelBase (LPV lpv)
{
   return RevisionCancel (lpv, FindTableRev (lpv));
}



DB_ERRNUM WINAPI fileCloseBase (LPV lpv)
{
   INT i = 0;
   DB_ERRNUM d = DBS_SUCCESS;

   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS )
      BaseClose (lpv);
   if ( SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS ) {
      for ( i=BASE_TBL_COUNT; i<BASE_TBL_COUNT+TBL_COUNT; i++ ) {
         MaxDatabaseError (&d, fileErrorV (lpv,
            dbCloseTable (lpv->wLinkNo, (FindTableHandle (lpv)) [i])));
      }
   }
   return d;
}



DB_ERRNUM WINAPI fileCommitBase (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;

#if !defined(DETAIL_VIEW)
   if ( !(SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS) )
      return d;
   if ( HAS_REVISIONS!=NO_REVISIONS )
      return d;
   CHECK_DBCALL (d, fileTransCommit (lpv));
#endif
   return d;
}



DB_ERRNUM WINAPI fileCreateBase (LPV lpv)
{
   return RevisionGenerate (lpv, FindTableRev (lpv), FindRevCache (lpv));
}



DB_ERRNUM WINAPI fileDeleteBase (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;
   INT i = 0;
   LPREVISION rev = FindTableRev (lpv);
   WORD key = lpv->wActualKey;

   CHECK_DBCALL (d, RevisionWasRealized (lpv));

   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
      LPVIEWDEF base = &lpv->subCmp;

      CHECK_DBCALL (d, ErrorMapViewToDatabase (VIEW_OP_PUT, BasePutData (lpv)));
      CHECK_DBCALL (d, ErrorMapViewToDatabase (VIEW_OP_DELETE,
                                               viewDelete (base->rvh, base->view)));
      key = 0;
   }

   if ( SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS ) {
      for ( i=BASE_TBL_COUNT; i<BASE_TBL_COUNT+TBL_COUNT; ++i ) {
         WORD handle = (FindTableHandle (lpv)) [i];
         LPSTR record = (FindRecord (lpv)) [i];

         if ( !lpv->bRevisioned ) {
            MaxDatabaseError (&d, dbDelete (lpv->wLinkNo, handle, record));
            if ( d==DBS_INVALID_POSITION ) {
               d = dbLock (lpv->wLinkNo, handle, key, record);
               if ( DB_ERRNUM_IS_SUCCESS (d) )
                  MaxDatabaseError (&d, dbDelete (lpv->wLinkNo, handle, record));
            }
         }
         if ( HAS_REVISIONS!=NO_REVISIONS && lpv->bRevisioned ) {
            revDelete (rev[i], record);
            MaxDatabaseError (&d, revGetExtendedError (rev[i]));
         }
         if ( DB_ERRNUM_IS_FAILURE (d) )
            break;
         key = 0;
      }
      if ( !lpv->bRevisioned ) {
         fileErrorV (lpv, d);
      }
      if ( HAS_REVISIONS==ORDER_REVISIONS && lpv->bRevisioned ) {
         // Note: attempts to restore the current record, but only works for ORDERED
         revErrorV (lpv, rev[i], d);
         if ( DB_ERRNUM_IS_FAILURE (d) ) {
            while ( --i>=BASE_TBL_COUNT )
               revInsert (rev[i], (FindRecord (lpv)) [i]);
         }
      }
   }

   return d;
}



DB_ERRNUM WINAPI fileDirtyBase (LPV lpv, LPBOOL dirty)
{
   DB_ERRNUM d = DBS_SUCCESS;

   if ( SUBCLASS_LEVEL==NOT_SUBCLASS ) {
      CHECK_DBCALL (d, RevisionDirty (lpv, FindTableRev (lpv), dirty));
   } else {
      DBSBOOL result;
      LPVIEWDEF base = &lpv->subCmp;
      ERRNUM e = viewGet (base->rvh, base->view, DIRTY_IDX, &result, sizeof (result));

      CHECK_DBCALL (d, ErrorMapViewToDatabase (VIEW_OP_GET, e));
      *dirty = result;
   }
   return d;
}



DB_ERRNUM WINAPI fileDriverInfoBase (WORD wLinkNo, HPIB hpib, LPDBDRVRINFO info)
{
   DB_ERRNUM d = DBS_SUCCESS;

   info->size = sizeof (*info);
   MaxDatabaseError (&d, dbGetDriverInfo (wLinkNo, info));
   fileError (wLinkNo, hpib, d);
   return d;
}



DB_ERRNUM WINAPI fileDropBase (WORD wLinkNo, HPIB hpib)
{
   DB_ERRNUM d = DBS_SUCCESS;
   INT i = 0;
   LPDBALTERFIELD fields = NULL;
   LPTBLMAP t = FindTableMap (0);

   if ( BASE_TBL_COUNT>0 && KEY_COUNT>0 ) {
      // Drop keys
      DBTABLE table;

      MaxDatabaseError (&d, fileInfo (wLinkNo, hpib, 0, &table));
      if ( DB_ERRNUM_IS_SUCCESS (d) ) {
         for ( i=0; i<SCINIT_KEY_COUNT; ++i ) {
            MaxDatabaseError (&d, fileError (wLinkNo, hpib,
                                             dbDropKey (wLinkNo, table.sName,
                                                        (WORD) (table.wNoOfKeys-i-1))));
         }
      }
   }

   if ( BASE_TBL_COUNT>0 ) {
      // Drop fields
      fields = (LPDBALTERFIELD) _alloca (t->table->wNoOfFields * sizeof (DBALTERFIELD));
      if ( fields==NULL ) {
         ReportBaseMemoryError (hpib, MAKE_OP_RSC(VIEW_OP_DROP));
         MaxDatabaseError (&d, DBS_CVIEW_GENERAL);
      } else {
         for ( i=0; i<t->table->wNoOfFields; ++i ) {
            LPDBALTERFIELD f = &fields[i];

            f->size = sizeof (DBALTERFIELD);
            f->field = t->fields[i];
            f->wOperation = DBS_ALTERTABLE_DROPFIELD;
            f->pValue = NULL;
            f->psInsertPoint = NULL;
            f->fRightJustified = FALSE;
         }
         MaxDatabaseError (&d, dbAlterTable (wLinkNo, t->table->sName,
                                             t->table->wNoOfFields, fields,
                                             0, NULL));
      }
   }

   if ( SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS ) {
      // Drop tables
      for ( i=BASE_TBL_COUNT; i<BASE_TBL_COUNT+TBL_COUNT; ++i ) {
         t = FindTableMap (i);
         MaxDatabaseError (&d, fileError (wLinkNo, hpib,
                                          dbDropTable (wLinkNo, t->table->sName)));
      }
   }

cleanup:
   return d;
}



DB_ERRNUM WINAPI fileEmptyBase (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;

   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
      LPVIEWDEF base = &lpv->subCmp;

      CHECK_DBCALL (d, ErrorMapViewToDatabase (VIEW_OP_TABLE_EMPTY,
         viewTableEmpty ((LPRVH) base->rvh, base->view)));
   }

   if ( SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS ) {
      INT i;

      for ( i=BASE_TBL_COUNT; i<BASE_TBL_COUNT+TBL_COUNT; ++i ) {
         CHECK_DBCALL (d, fileErrorV (lpv,
            dbEmptyTable (lpv->wLinkNo, NULL, (FindTableHandle (lpv)) [i])));
      }
   }

   return d;
}



DB_ERRNUM WINAPI fileErrorBase (WORD wLinkNo, HPIB hpib, DB_ERRNUM e)
{
   return dbError (wLinkNo, hpib, e);
}



DB_ERRNUM WINAPI fileFilterCountBase (LPV lpv, LPSTR filter, A4W_FLAGS flags, LP_A4W_SIZE count)
{
   DB_ERRNUM d = DBS_SUCCESS;

   if ( SUBCLASS_LEVEL==NOT_SUBCLASS )
   {
      if ( TBL_COUNT<=0 )
      {
         *count = 0;
         return d;
      }

      CHECK_DBCALL (d, fileErrorV (lpv,
         dbGetRecordCount (lpv->wLinkNo, (FindTableHandle (lpv)) [BASE_TBL_COUNT],
                           filter, count)));
   }
   else
   {
      LPVIEWDEF base = &lpv->subCmp;
      ERRNUM e = viewFilterCount ((LPRVH) base->rvh, base->view, filter, 0L, count);

      CHECK_DBCALL (d, ErrorMapViewToDatabase (VIEW_OP_FILTER_COUNT, e));
   }
   return d;
}



DB_ERRNUM WINAPI fileFilterDeleteBase (LPV lpv, LPFILTER filter)
{
   DB_ERRNUM d = DBS_SUCCESS;
   FL_ERRNUM f = FL_SUCCESS;
   ERRNUM e = ERRNUM_SUCCESS;
   INT i = BASE_TBL_COUNT;
   WORD op;
   LPSTR range = NULL;
   FILTER reduced;
   LPLONG indexes;
   SHORT segments;
   BOOL unreduced = TRUE;

   if ( !(SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS) )
      return d;

   blkSet (&reduced, 0, sizeof (reduced));
   op = FILTER_OP_COPY;
   f = filterCopy (&reduced, filter);
   CHECK_DBCALL_GOTO (d, cleanup,
      ErrorMapFilterToDatabase (op, filterErrorV (lpv, op, f)));
   filter = &reduced;

   if ( SUBCLASS_LEVEL==NOT_SUBCLASS ) {
      indexes = FindKeyDef (lpv->wKey)->indexes;
      segments = FindKeyDef (lpv->wKey)->segments;
   } else {
      LPVIEWDEF base = &lpv->subCmp;

      indexes = lpv->subCmpKey.indexes;
      segments = lpv->subCmpKey.segments;
      op = FILTER_OP_EXPRESSION;
      f = filterExpression (lpv, filter, (FILTERNAME) xxxNameOnly, &range);
      RVSPYTRACE (range);
      CHECK_DBCALL_GOTO (d, cleanup,
         ErrorMapFilterToDatabase (op, filterErrorV (lpv, op, f)));
      e = viewFilterDelete ((LPRVH) base->rvh, base->view, range, lpv->RotoView->dw);
      filterExprFree (range);
      CHECK_DBCALL_GOTO (d, cleanup,
         ErrorMapViewToDatabase (VIEW_OP_FILTER_DELETE, e));
      unreduced = !filterReduce (filter, indexes, segments, TRUE, TRUE);
   }

   for ( i=BASE_TBL_COUNT; unreduced && i<BASE_TBL_COUNT+TBL_COUNT; ++i ) {
      lpv->filterExpressionCast = i;
      op = FILTER_OP_EXPRESSION;
      f = filterExpression (lpv, filter, tableName, &range);
      RVSPYTRACE (range);
      CHECK_DBCALL_GOTO (d, cleanup,
         ErrorMapFilterToDatabase (op, filterErrorV (lpv, op, f)));
      MaxDatabaseError (&d,
         fileErrorV (lpv, dbRemove (lpv->wLinkNo, (FindTableHandle (lpv)) [i],
                                    range, lpv->wActualKey)));
      filterExprFree (range);
      if ( DB_ERRNUM_IS_FAILURE (d) )
         goto cleanup;
      unreduced = !filterReduce (filter, indexes, segments, TRUE, TRUE);
   }

cleanup:
   filterFree (&reduced);
   return d;
}



DB_ERRNUM WINAPI fileFilterSegsBase (LPV lpv)
{
   return RevisionSegments (lpv, FindTableRev (lpv));
}



#define EMPTY(__s__) (!(__s__) || !(__s__)[0])
#define LENGTH(__s__) (EMPTY(__s__) ? 0 : strLength ((__s__)))
#define FILTER_AND(__f__,__t__)   \
   if ( !EMPTY(__t__) ) {         \
      if ( !EMPTY(__f__) )        \
         strAppend (__f__, " AND "); \
      strAppend (__f__, "(");        \
      strAppend (__f__, __t__);      \
      strAppend (__f__, ")");        \
   }



DB_ERRNUM WINAPI fileFirstBase (LPV lpv, INT flags)
{
   DB_ERRNUM d = DBS_SUCCESS;
   SHORT nSegs = 0;
   INT i = BASE_TBL_COUNT;
   BOOL bLock = (flags & MASK_FETCHFILTER_LOCKED)==FETCHFILTER_LOCKED;
   BOOL bSelectFromStart = (flags & MASK_FETCHFILTER_FROM)==FETCHFILTER_FROMSTART;
   LPREVISION rev = FindTableRev (lpv);

   CHECK_DBCALL (d, RevisionRealize (lpv));
   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
      CHECK_DBCALL (d, ErrorMapViewToDatabase (VIEW_OP_PUT, BasePutData (lpv)));
      CHECK_DBCALL (d, BaseFetch (lpv, bLock, bSelectFromStart));
   }

   if ( SUBCLASS_LEVEL==JOIN_SUBCLASS ) {
      WORD handle = (FindTableHandle (lpv)) [BASE_TBL_COUNT];
      LPSTR record = (FindRecord (lpv)) [BASE_TBL_COUNT];
      PTABLESELECTION selection = FindTableSelection (lpv, BASE_TBL_COUNT);

      CHECK_DBCALL (d, ErrorMapViewToDatabase (VIEW_OP_GET, BaseGetKey (lpv)));
      if ( !(selection!=NULL && 0==selection->count) ) {
         if ( !lpv->bRevisioned ) {
            if ( bLock ) {
               MaxDatabaseError (&d, dbGetLock (lpv->wLinkNo, handle, 0, record, FALSE));
            } else {
               MaxDatabaseError (&d, dbGet (lpv->wLinkNo, handle, 0, record));
            }
         }
         if ( HAS_REVISIONS!=NO_REVISIONS && lpv->bRevisioned ) {
            revRead (rev[BASE_TBL_COUNT], record);
            MaxDatabaseError (&d, revGetExtendedError (rev[BASE_TBL_COUNT]));
         }
         if ( d==DBS_NO_MORE_DATA )
            return d;
      }
   }

   if ( SUBCLASS_LEVEL==NOT_SUBCLASS && TBL_COUNT>0 &&
        DB_ERRNUM_IS_SUCCESS (d) ) {
      WORD handle = (FindTableHandle (lpv)) [BASE_TBL_COUNT];
      LPSTR record = (FindRecord (lpv)) [BASE_TBL_COUNT];

      if ( !lpv->bRevisioned ) {
         if ( !lpv->bReadOnly ) {
            filterSegments (&lpv->filter, lpv->nCurrentRange, &nSegs);
            if ( (WORD)nSegs < lpv->wDetailFilterSegments )
               nSegs = lpv->wDetailFilterSegments;
            if ( bSelectFromStart ) {
               if ( lpv->bAhead ) {
                  MaxDatabaseError (&d,
                     dbGetFirst (lpv->wLinkNo, handle, lpv->wActualKey, record, nSegs, bLock));
               } else {
                  MaxDatabaseError (&d,
                     dbGetLast (lpv->wLinkNo, handle, lpv->wActualKey, record, nSegs, bLock));
               }
            } else if ( bLock ) {
               if ( lpv->bAhead ) {
                  MaxDatabaseError (&d,
                     dbGetGELock (lpv->wLinkNo, handle, lpv->wActualKey, record, nSegs, 0));
               } else {
                  MaxDatabaseError (&d,
                     dbGetLELock (lpv->wLinkNo, handle, lpv->wActualKey, record, nSegs, 0));
               }
            } else {
               if ( lpv->bAhead ) {
                  MaxDatabaseError (&d,
                     dbGetGE (lpv->wLinkNo, handle, lpv->wActualKey, record, nSegs, 0));
               } else {
                  MaxDatabaseError (&d,
                     dbGetLE (lpv->wLinkNo, handle, lpv->wActualKey, record, nSegs, 0));
               }
            }
         }

         if ( lpv->bReadOnly ) {
            LPSTR first = NULL;
            WORD op = FILTER_OP_EXPR_FIRST;
            FL_ERRNUM f = filterExprFirst (lpv, &lpv->filter,
               (FILTERNAME) xxxNameOnly, (FILTERGET) scInitGet, lpv->bAhead, &first);

            RVSPYTRACE (first);
            filterErrorV (lpv, op, f);
            MaxDatabaseError (&d, ErrorMapFilterToDatabase (op, f));
            if ( DB_ERRNUM_IS_SUCCESS (d) ) {
               LPSTR detail = NULL;

               filterSegments (&lpv->filter, lpv->nCurrentRange, &nSegs);
               if ( (WORD)nSegs < lpv->wDetailFilterSegments )
                  nSegs = lpv->wDetailFilterSegments;
               op = FILTER_OP_EXPR_SEGMENTS;
               f = filterExprSegments (lpv, &lpv->filter, nSegs,
                  (FILTERNAME) xxxNameOnly, (FILTERGET) scInitGet, &detail);
               RVSPYTRACE (detail);
               filterErrorV (lpv, op, f);
               MaxDatabaseError (&d, ErrorMapFilterToDatabase (op, f));
               if ( DB_ERRNUM_IS_SUCCESS (d) ) {
                  LPSTR filter = (LPSTR) _alloca (24 + LENGTH(lpv->dbFilter)
                                                     + LENGTH(lpv->rangeFilter)
                                                     + LENGTH(first)
                                                     + LENGTH(detail));

                  if ( filter==NULL ) {
                     ReportMemoryError (lpv, MAKE_OP_RSC (VIEW_OP (lpv, OPEN)));
                     d = DBS_MEMORY;
                  } else {
                     filter[0] = 0;
                     FILTER_AND (filter, detail);
                     FILTER_AND (filter, lpv->rangeFilter);
                     if ( !bSelectFromStart ) {
                        FILTER_AND (filter, first);
                     }
                     FILTER_AND (filter, lpv->dbFilter);
                     RVSPYTRACE (filter);
                     lpv->fetchedRecordCount = lpv->currentFetchedRecord = lpv->wFetchCount;
                     MaxDatabaseError (&d, dbSelect (lpv->wLinkNo, handle,
                                                     filter, lpv->wActualKey, lpv->bAhead));
                     if ( DB_ERRNUM_IS_SUCCESS (d) ) {
                        MaxDatabaseError (&d, BufferedFetch (lpv));
                     }
                  }
                  filterExprFree (detail);
               }
               filterExprFree (first);
            }
         }
      }

      if ( HAS_REVISIONS!=NO_REVISIONS && lpv->bRevisioned ) {
         if ( bSelectFromStart ) {
            CHECK_DBCALL (d,
               ErrorMapViewToDatabase (VIEW_OP (lpv, OPEN), InitFields (lpv)));
         }
         VIEWASSERT (BASE_TBL_COUNT==i);
         revBrowse (rev[BASE_TBL_COUNT], record, (lpv->bAhead ? 1 : -1));
         CHECK_DBCALL (d, revErrorV (lpv, rev[BASE_TBL_COUNT],
                                     revGetExtendedError (rev[BASE_TBL_COUNT])));
         revFetch (rev[BASE_TBL_COUNT], record);
         MaxDatabaseError (&d, revGetExtendedError (rev[BASE_TBL_COUNT]));
      }
      if ( d==DBS_NO_MORE_DATA )
         return d;
   }

   if ( (SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS) &&
        TBL_COUNT>1 && DB_ERRNUM_IS_SUCCESS (d) ) {
      PropagatePrimary (lpv);
      for ( i=BASE_TBL_COUNT+1; i<BASE_TBL_COUNT+TBL_COUNT; i++ ) {
         WORD handle = (FindTableHandle (lpv)) [i];
         LPSTR record = (FindRecord (lpv)) [i];
         PTABLESELECTION selection = FindTableSelection (lpv, i);

         if ( selection!=NULL && 0==selection->count )
            continue;
         if ( !lpv->bRevisioned ) {
            if (bLock) {
               MaxDatabaseError (&d, dbGetLock (lpv->wLinkNo, handle, 0, record, FALSE));
            } else {
               MaxDatabaseError (&d, dbGet (lpv->wLinkNo, handle, 0, record));
            }
         }
         if ( HAS_REVISIONS!=NO_REVISIONS && lpv->bRevisioned ) {
            revRead (rev[i], record);
            MaxDatabaseError (&d, revGetExtendedError (rev[i]));
         }
         if ( DB_ERRNUM_IS_FAILURE (d) )
            break;
      }
   }

   if ( !lpv->bRevisioned ) {
      fileErrorV (lpv, d);
   }
   if ( HAS_REVISIONS!=NO_REVISIONS && lpv->bRevisioned ) {
      revErrorV (lpv, rev[i], d);
   }
   return d;
}

#undef   GET_FIRST_5_PARAMS



DB_ERRNUM WINAPI fileGetBase (LPV lpv, BOOL bLock)
{
   INT i = BASE_TBL_COUNT;
   DB_ERRNUM d = DBS_SUCCESS;
   WORD key = lpv->wActualKey;
   LPREVISION rev = FindTableRev (lpv);

   CHECK_DBCALL (d, RevisionRealize (lpv));

   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
      LPVIEWDEF base = &lpv->subCmp;

      CHECK_DBCALL (d, ErrorMapViewToDatabase (VIEW_OP_PUT, BasePutData (lpv)));
      if ( bLock ) {
         CHECK_DBCALL (d,
            ErrorMapViewToDatabase (VIEW_OP_READ, viewReadLock (base->rvh, base->view)));
      } else {
         CHECK_DBCALL (d,
            ErrorMapViewToDatabase (VIEW_OP_READ, viewRead (base->rvh, base->view)));
      }
      CHECK_DBCALL (d, ErrorMapViewToDatabase (VIEW_OP_GET, BaseGetData (lpv)));
   }

   if ( SUBCLASS_LEVEL==JOIN_SUBCLASS ) {
      CHECK_DBCALL (d, ErrorMapViewToDatabase (VIEW_OP_GET, BaseGetKey (lpv)));
      key = 0;
   }

   if ( (SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS) && TBL_COUNT>0 ) {
      WORD handle = (FindTableHandle (lpv)) [BASE_TBL_COUNT];
      LPSTR record = (FindRecord (lpv)) [BASE_TBL_COUNT];
      PTABLESELECTION selection = FindTableSelection (lpv, BASE_TBL_COUNT);

      if ( !(selection!=NULL && 0==selection->count) ) {
         if ( !lpv->bRevisioned ) {
            if (bLock) {
               MaxDatabaseError (&d, dbGetLock (lpv->wLinkNo, handle, key, record, FALSE));
            } else {
               MaxDatabaseError (&d, dbGet (lpv->wLinkNo, handle, key, record));
            }
         }
         if ( HAS_REVISIONS!=NO_REVISIONS && lpv->bRevisioned ) {
            revRead (rev[BASE_TBL_COUNT], record);
            MaxDatabaseError (&d, revGetExtendedError (rev[BASE_TBL_COUNT]));
         }
         if ( d==DBS_NOT_FOUND )
            return d;
      }
   }

   if ( (SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS) &&
        TBL_COUNT>1 && DB_ERRNUM_IS_SUCCESS (d) ) {
      PropagatePrimary (lpv);
      for ( i=BASE_TBL_COUNT+1; i<BASE_TBL_COUNT+TBL_COUNT; i++ ) {
         WORD handle = (FindTableHandle (lpv)) [i];
         LPSTR record = (FindRecord (lpv)) [i];
         PTABLESELECTION selection = FindTableSelection (lpv, i);

         if ( selection!=NULL && 0==selection->count )
            continue;
         if ( !lpv->bRevisioned ) {
            if (bLock) {
               MaxDatabaseError (&d, dbGetLock (lpv->wLinkNo, handle, 0, record, FALSE));
            } else {
               MaxDatabaseError (&d, dbGet (lpv->wLinkNo, handle, 0, record));
            }
         }
         if ( HAS_REVISIONS!=NO_REVISIONS && lpv->bRevisioned ) {
            revRead (rev[i], record);
            MaxDatabaseError (&d, revGetExtendedError (rev[i]));
         }
         if ( DB_ERRNUM_IS_FAILURE (d) )
            break;
      }
   }

   if ( !lpv->bRevisioned ) {
      fileErrorV (lpv, d);
   }
   if ( HAS_REVISIONS!=NO_REVISIONS && lpv->bRevisioned ) {
      revErrorV (lpv, rev[i], d);
   }

   return d;
}



DB_ERRNUM WINAPI fileInfoBase (WORD wLinkNo, HPIB hpib, INT table, LPDBTABLE info)
{
   DB_ERRNUM d = DBS_SUCCESS;
   CHAR array[SIZEOF_TABLENAME] = {'S','C','I','N','I','T',' ',' '};
   LPSTR name = array;

   blkSet (info->sName, ' ', SIZEOF_TABLENAME);
   info->wRecordLength = 0;
   info->wNoOfFields = 0;
   info->wNoOfKeys = 0;
   info->wFlags = 0;
   info->wFirstAuditField = 0;
   if ( BASE_TBL_COUNT+TBL_COUNT>0 ) {
      name = FindTableMap (table)->table->sName;
      MaxDatabaseError (&d, dbGetTableInfo (wLinkNo, name, info));
   }
   fileError (wLinkNo, hpib, d);
   return d;
}



DB_ERRNUM WINAPI fileInsertBase (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;
   INT i = 0;
   LPREVISION rev = FindTableRev (lpv);

   CHECK_DBCALL (d, RevisionRealize (lpv));

   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
      LPVIEWDEF base = &lpv->subCmp;

      CHECK_DBCALL (d, ErrorMapViewToDatabase (VIEW_OP_PUT, BasePutData (lpv)));
      CHECK_DBCALL (d, ErrorMapViewToDatabase (VIEW_OP_INSERT,
                                               viewInsert (base->rvh, base->view)));
      CHECK_DBCALL (d, ErrorMapViewToDatabase (VIEW_OP_GET, BaseGetKey (lpv)));
   }

   if ( SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS ) {
      if ( !lpv->bRevisioned ) {
         GenerateSequence (lpv);
         PropagatePrimary (lpv);
      }
      for ( i=BASE_TBL_COUNT; i<BASE_TBL_COUNT+TBL_COUNT; i++ ) {
         if ( !lpv->bRevisioned ) {
            MaxDatabaseError (&d, dbInsert (lpv->wLinkNo, (FindTableHandle (lpv)) [i],
                                            (FindRecord (lpv)) [i]));
         }
         if ( HAS_REVISIONS!=NO_REVISIONS && lpv->bRevisioned ) {
            if ( HAS_REVISIONS==ORDER_REVISIONS || i>BASE_TBL_COUNT )
               revInsert (rev[i], (FindRecord (lpv)) [i]);
            else {
               /* we are explicitly ignoring lpv->wActualKey!=0, thereby forcing */
               /* an error to be generated. This is because alternate keys cause */
               /* the revision list to be ordered, in spite of HAS_REVISIONS */
               revInsertAfter (rev[i], (FindRecord (lpv)) [i]);
               PropagatePrimary (lpv);
            }
            MaxDatabaseError (&d, revGetExtendedError (rev[i]));
         }
         if ( DB_ERRNUM_IS_FAILURE (d) )
            break;
      }
      if ( DB_ERRNUM_IS_FAILURE (d) ) {
#if defined(DO_SUPPRESSDUPLICATE)
         if ( d!=DBS_DUPLICATE_KEY )
#endif
         {
            if ( !lpv->bRevisioned ) {
               fileErrorV (lpv, d);
            }
            if ( HAS_REVISIONS!=NO_REVISIONS && lpv->bRevisioned ) {
               revErrorV (lpv, rev[i], d);
            }
         }
         if ( HAS_REVISIONS!=NO_REVISIONS && lpv->bRevisioned ) {
            while ( --i>=BASE_TBL_COUNT )
               revDelete (rev[i], (FindRecord (lpv)) [i]);
         }
      }
   }

   return d;
}



DB_ERRNUM WINAPI fileIsLockedBase (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;

   if ( !(SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS) )
      return d;
   if ( TBL_COUNT==0 )
      return d;

   if ( !lpv->bRevisioned ) {
      d = dbIsRecLocked (lpv->wLinkNo, (FindTableHandle (lpv)) [BASE_TBL_COUNT]);
      if ( DB_ERRNUM_IS_SUCCESS (d) || d==DBS_RECORD_NOT_LOCKED )
         return d;
      else
         return fileErrorV (lpv, d);
   }
   return d;
}



DB_ERRNUM WINAPI fileLinkFlagsBase (WORD wLinkNo, HPIB hpib, LPWORD flags)
{
   DB_ERRNUM d = DBS_SUCCESS;

   MaxDatabaseError (&d, dbLinkGetFlags (wLinkNo, flags));
   fileError (wLinkNo, hpib, d);
   return d;
}



DB_ERRNUM WINAPI fileLocateBase (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;
   LPREVISION rev = FindTableRev (lpv);

   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
      LPVIEWDEF base = &lpv->subCmp;
      INT exists;

      CHECK_DBCALL (d, ErrorMapViewToDatabase (VIEW_OP_PUT, BasePutData (lpv)));
      CHECK_DBCALL (d, ErrorMapViewToDatabase (VIEW_OP_EXISTS,
                                               viewExists (base->rvh, base->view, &exists)));
      if ( exists )
         return DBS_SUCCESS;
      else
         return DBS_NOT_FOUND;

   } else if ( TBL_COUNT>0 ) {
      CHECK_DBCALL (d, RevisionRealize (lpv));
      if ( !lpv->bRevisioned ) {
         d = dbLocate (lpv->wLinkNo, (FindTableHandle (lpv)) [BASE_TBL_COUNT],
                       lpv->wActualKey, (FindRecord (lpv)) [BASE_TBL_COUNT]);
      }
      if ( HAS_REVISIONS!=NO_REVISIONS && lpv->bRevisioned ) {
         revLocate (rev[BASE_TBL_COUNT], (FindRecord (lpv)) [BASE_TBL_COUNT]);
         d = revGetExtendedError (rev[BASE_TBL_COUNT]);
      }
      if ( DB_ERRNUM_IS_SUCCESS (d) || d==DBS_NOT_FOUND )
         return d;

      if ( !lpv->bRevisioned ) {
         fileErrorV (lpv, d);
      }
      if ( HAS_REVISIONS!=NO_REVISIONS && lpv->bRevisioned ) {
         revErrorV (lpv, rev[BASE_TBL_COUNT], d);
      }
   }
   return d;
}



DB_ERRNUM WINAPI fileLockBase (LPV lpv)
{
   return fileOptLock (lpv, FALSE);
}



DB_ERRNUM WINAPI fileNextBase (LPV lpv, BOOL bLock)
{
   DB_ERRNUM d = DBS_SUCCESS;
   INT i = 0;
   LPREVISION rev = FindTableRev (lpv);

   CHECK_DBCALL (d, RevisionWasRealized (lpv));

   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
      CHECK_DBCALL (d, BaseFetch (lpv, bLock, FALSE));

      if ( SUBCLASS_LEVEL==JOIN_SUBCLASS && TBL_COUNT>0 ) {
         WORD handle = (FindTableHandle (lpv)) [BASE_TBL_COUNT];
         LPSTR record = (FindRecord (lpv)) [BASE_TBL_COUNT];
         PTABLESELECTION selection = FindTableSelection (lpv, BASE_TBL_COUNT);

         if ( !(selection!=NULL && 0==selection->count) ) {
            CHECK_DBCALL (d, ErrorMapViewToDatabase (VIEW_OP_GET, BaseGetKey (lpv)));
            if ( !lpv->bRevisioned ) {
               if (bLock) {
                  MaxDatabaseError (&d, dbGetLock (lpv->wLinkNo, handle, 0, record, FALSE));
               } else {
                  MaxDatabaseError (&d, dbGet (lpv->wLinkNo, handle, 0, record));
               }
            }
            if ( HAS_REVISIONS!=NO_REVISIONS && lpv->bRevisioned ) {
               revRead (rev[BASE_TBL_COUNT], record);
               MaxDatabaseError (&d, revGetExtendedError (rev[BASE_TBL_COUNT]));
            }
            if ( d==DBS_NO_MORE_DATA )
               return d;
         }
      }
   }

   if ( (SUBCLASS_LEVEL==NOT_SUBCLASS && TBL_COUNT>0) && DB_ERRNUM_IS_SUCCESS (d) ) {
      if ( !lpv->bRevisioned ) {
         if ( lpv->bReadOnly ) {
            MaxDatabaseError (&d, BufferedFetch (lpv));
         }
         if ( !lpv->bReadOnly ) {
            WORD (WINAPI * GetNext) (WORD link, WORD table, LPVOID record);

            if (bLock)
               if (lpv->bAhead)
                  GetNext = dbGetNextLock;
               else
                  GetNext = dbGetPrevLock;
            else
               if (lpv->bAhead)
                  GetNext = dbGetNext;
               else
                  GetNext = dbGetPrev;
            MaxDatabaseError (&d, (* GetNext) (lpv->wLinkNo, (FindTableHandle (lpv)) [BASE_TBL_COUNT],
                                               (FindRecord (lpv)) [BASE_TBL_COUNT]));
         }
      }
      if ( HAS_REVISIONS!=NO_REVISIONS && lpv->bRevisioned ) {
         revFetch (rev[BASE_TBL_COUNT], (FindRecord (lpv)) [BASE_TBL_COUNT]);
         MaxDatabaseError (&d, revGetExtendedError (rev[BASE_TBL_COUNT]));
      }
      if ( d==DBS_NO_MORE_DATA )
         return d;
   }

   if ( (SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS) &&
        TBL_COUNT>1 && DB_ERRNUM_IS_SUCCESS (d) ) {
      PropagatePrimary (lpv);
      for ( i=BASE_TBL_COUNT+1; i<BASE_TBL_COUNT+TBL_COUNT; i++ ) {
         WORD handle = (FindTableHandle (lpv)) [i];
         LPSTR record = (FindRecord (lpv)) [i];
         PTABLESELECTION selection = FindTableSelection (lpv, i);

         if ( selection!=NULL && 0==selection->count )
            continue;
         if ( !lpv->bRevisioned ) {
            if (bLock) {
               MaxDatabaseError (&d, dbGetLock (lpv->wLinkNo, handle, 0, record, FALSE));
            } else {
               MaxDatabaseError (&d, dbGet (lpv->wLinkNo, handle, 0, record));
            }
         }
         if ( HAS_REVISIONS!=NO_REVISIONS && lpv->bRevisioned ) {
            revRead (rev[i], record);
            MaxDatabaseError (&d, revGetExtendedError (rev[i]));
         }
         if ( DB_ERRNUM_IS_FAILURE (d) )
            break;
      }
   }

   if ( !lpv->bRevisioned ) {
      fileErrorV (lpv, d);
   }
   if ( HAS_REVISIONS!=NO_REVISIONS && lpv->bRevisioned ) {
      revErrorV (lpv, rev[i], d);
   }

   return d;
}



DB_ERRNUM WINAPI fileOpenBase (WORD wLinkNo, HPIB hpib, LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;
   INT i = 0;

   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
      LPVIEWDEF base = &lpv->subCmp;
      LPCMPKEY x = &lpv->subCmpKey;
      CHAR sName [SIZEOF_FLDDESC];

      MaxDatabaseError (&d, ErrorMapViewToDatabase (VIEW_OP_OPEN, BaseOpen (lpv)));
      if ( DB_ERRNUM_IS_SUCCESS (d) ) {
         MaxDatabaseError (&d, ErrorMapViewToDatabase (VIEW_OP_OPEN,
            viewKeys (base->rvh, base->view, &lpv->subKeys)));
         if ( DB_ERRNUM_IS_SUCCESS (d) ) {
            MaxDatabaseError (&d, ErrorMapViewToDatabase (VIEW_OP_OPEN,
               viewFields (base->rvh, base->view, &lpv->subFields)));
            if ( DB_ERRNUM_IS_SUCCESS (d) && lpv->subKeys>0 ) {
               MaxDatabaseError (&d, ErrorMapViewToDatabase (VIEW_OP_OPEN,
                  viewKey (base->rvh, base->view, 0, sName, &x->segments, x->indexes)));
               if ( DB_ERRNUM_IS_SUCCESS (d) ) {
                  MaxDatabaseError (&d, ErrorMapViewToDatabase (VIEW_OP_OPEN,
                     QueryKeyTypes (base, x)));
                  if ( BASE_TBL_COUNT>0 && DB_ERRNUM_IS_SUCCESS (d) ) {
                     MaxDatabaseError (&d,
                        fileInfo (wLinkNo, hpib, 0, FindTableInfo (lpv, 0)));
                  }
               }
            }
         }
         if ( DB_ERRNUM_IS_FAILURE (d) ) {
            BaseClose (lpv);
            return d;
         }
      }
   }

   if ( SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS ) {
      for ( i=BASE_TBL_COUNT; i<BASE_TBL_COUNT+TBL_COUNT; i++ ) {
         LPTBLMAP t = FindTableMap (i);

         MaxDatabaseError (&d, fileError (wLinkNo, hpib,
                                          dbOpenTable (wLinkNo, t->table->sName,
                                                       (WORD) (lpv->bReadOnly ? FLG_READONLY : FLG_READWRITE),
                                                       & (FindTableHandle (lpv)) [i])));
         if ( DB_ERRNUM_IS_SUCCESS (d) ) {
            MaxDatabaseError (&d, fileInfo (wLinkNo, hpib, i, FindTableInfo (lpv, i)));
         }
         if ( DB_ERRNUM_IS_SUCCESS (d) ) {
            LPDBTABLE reported = FindTableInfo (lpv, i);
            LPDBTABLE declared = t->table;

            if ( i==BASE_TBL_COUNT ) {
               if ( reported->wRecordLength < declared->wRecordLength ||
                      reported->wNoOfFields < declared->wNoOfFields ||
                        reported->wNoOfKeys < declared->wNoOfKeys )
                  d = DBS_DD_INCONSISTENT;
            } else if ( i>BASE_TBL_COUNT ) {
               if ( reported->wRecordLength != declared->wRecordLength ||
                      reported->wNoOfFields != declared->wNoOfFields ||
                        reported->wNoOfKeys != declared->wNoOfKeys )
                  d = DBS_DD_INCONSISTENT;
            }
            if ( DBS_DD_INCONSISTENT==d ||
                 blkCompare (reported->sName, declared->sName, SIZEOF_TABLENAME)!=0 ||
                 reported->wFirstAuditField != declared->wFirstAuditField ) {
               d = DBS_DD_INCONSISTENT; // Set again because the if has new tests
               ReportGenericError (lpv, ERRGEN_AREA_DATABASE, 0, d, NULL);
            } else {
               // Retrieve list of subclassor field names, for implicit inclusion
               // in all subsequent scInitInstanceFieldList() calls
            }
         }
         if ( DB_ERRNUM_IS_FAILURE (d) ) {
            while ( --i>=BASE_TBL_COUNT )
               dbCloseTable (wLinkNo, (FindTableHandle (lpv)) [i]);
            if ( SUBCLASS_LEVEL!=NOT_SUBCLASS )
               BaseClose (lpv);
            return d;
         }
      }
   }

   return d;
}



DB_ERRNUM WINAPI fileOptLockBase (LPV lpv, BOOL optimistic)
{
   DB_ERRNUM d = DBS_SUCCESS;
   WORD key = (WORD) -1;
   LPSTR FAR * records = FindRecord (lpv);
   INT r = BASE_TBL_COUNT;

   if ( !(SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS) )
      return d;
   if ( TBL_COUNT==0 )
      return d;
   if ( lpv->bRevisioned )
      return d;

   if ( !lpv->bBrowsing || lpv->bBrowseEnded ) {
      if ( SUBCLASS_LEVEL==NOT_SUBCLASS )
         key = lpv->wActualKey;
      else
         key = 0;
   }
   MaxDatabaseError (&d, dbLock (lpv->wLinkNo, (FindTableHandle (lpv)) [r],
                                 key, records[r]));
   switch ( d ) {
      case DBS_SUCCESS:
      case DBS_CVIEW_WARNING:
         if ( TBL_COUNT>1 ) {
            for ( r=BASE_TBL_COUNT+1; r<BASE_TBL_COUNT+TBL_COUNT; r++ ) {
               PTABLESELECTION selection = FindTableSelection (lpv, r);

               if ( selection!=NULL && 0==selection->count )
                  continue;
               MaxDatabaseError (&d, fileErrorV (lpv, dbLock (lpv->wLinkNo,
                                                              (FindTableHandle (lpv)) [r],
                                                              0, records[r])));
               if ( DB_ERRNUM_IS_FAILURE (d) )
                  break;
            }
         }
         break;

#if defined(DO_CONCURRENCYETC)
      case DBS_CONFLICT:
         if ( !optimistic || lpv->pViewSelection!=NULL )
            return fileErrorV (lpv, d);
         d = DBS_SUCCESS;
         CopyRecords (lpv, FindRecordTemp (lpv), FindRecord (lpv));
         key = lpv->wActualKey;
         records = FindRecordTemp (lpv);
         for ( r=BASE_TBL_COUNT; r<BASE_TBL_COUNT+TBL_COUNT; r++ ) {
            MaxDatabaseError (&d, fileErrorV (lpv, dbGetLock (lpv->wLinkNo,
                                                              (FindTableHandle (lpv)) [r],
                                                              key, records[r], FALSE)));
            if ( DB_ERRNUM_IS_FAILURE (d) )
               break;
            key = 0;
         }
         lpv->bBrowsing = FALSE; // Breaks convention being in a file function
         lpv->bBrowseEnded = TRUE;
         if ( DB_ERRNUM_IS_SUCCESS (d) ) {
            MaxDatabaseError (&d, ErrorMapViewToDatabase (VIEW_OP_UPDATE,
                                                          MergeConflictedRecords (lpv)));
         }
         break;
#endif

      default:
         return fileErrorV (lpv, d);
   }

   if ( DB_ERRNUM_IS_FAILURE (d) ) {
      while ( --r>=BASE_TBL_COUNT )
         dbUnLock (lpv->wLinkNo, (FindTableHandle (lpv)) [r], records[r]);
   }
   return d;
}



REV_ERRNUM WINAPI filePostBase (LPV lpv)
{
   if ( !(SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS) )
      return POST_DONE;
   if ( TBL_COUNT==0 )
      return POST_DONE;

   if ( HAS_REVISIONS==ORDER_REVISIONS ) {
      INT i;
      WORD op;
      ERRNUM f = ERRNUM_SUCCESS;
      LPREVISION rev = FindTableRev (lpv);

      if ( !lpv->bRevisioned )
         return POST_DONE;

      for ( i=BASE_TBL_COUNT; i<BASE_TBL_COUNT+TBL_COUNT; i++ )
         if ( rev[i]!=NULL )
            switch ( filePrePost (lpv, &op, i) ) {
               case POST_ERROR:
                  rev[i] = NULL;
                  return POST_ERROR;

               case POST_DONE:
                  rev[i] = NULL;
                  break;

               case POST_CONTINUE:
                  f = BaseNotifyFire (lpv, INSTANCE_NOTIFY_REVISION_COMMITTED_RECORD,
                                      1, (LPVOID) MAKELONG (op, (SHORT) i));
                  MaxDatabaseError (&lpv->eRevision,
                                    ErrorMapViewToDatabase (VIEW_OP (lpv, OPEN), f));
                  if ( DB_ERRNUM_IS_FAILURE (lpv->eRevision) ) {
                     rev[i] = NULL;
                     return POST_ERROR;
                  }

                  // revPostEtc() is called by record, then by table, which is
                  // different than for sequenced revisions below
                  MaxDatabaseError (&lpv->eRevision, revPostEtc (lpv, op, i));
                  if ( DB_ERRNUM_IS_FAILURE (lpv->eRevision) ) {
                     rev[i] = NULL;
                     return POST_ERROR;
                  }
                  break;
            }

      for ( i=BASE_TBL_COUNT; i<BASE_TBL_COUNT+TBL_COUNT; i++ )
         if ( rev[i]!=NULL )
            return POST_CONTINUE;

   } else if ( HAS_REVISIONS==SEQUENCE_REVISIONS ) {
      INT i = BASE_TBL_COUNT;
      ERRNUM f = ERRNUM_SUCCESS;
      WORD op;
      LPREVISION rev = FindTableRev (lpv);

      if ( !lpv->bRevisioned )
         return POST_DONE;

      switch ( filePrePost (lpv, &op, BASE_TBL_COUNT) ) {
         case POST_ERROR:
            rev[BASE_TBL_COUNT] = NULL;
            return POST_ERROR;

         case POST_CONTINUE:
            f = BaseNotifyFire (lpv, INSTANCE_NOTIFY_REVISION_COMMITTED_RECORD,
                                1, (LPVOID) MAKELONG (op, BASE_TBL_COUNT));
            MaxDatabaseError (&lpv->eRevision,
                              ErrorMapViewToDatabase (VIEW_OP (lpv, OPEN), f));
            if ( DB_ERRNUM_IS_FAILURE (lpv->eRevision) ) {
               rev[BASE_TBL_COUNT] = NULL;
               return POST_ERROR;
            }

            if ( op==REV_INSERT || op==REV_MOVE ) {
               LPSTR record = (FindRecord (lpv)) [BASE_TBL_COUNT];
               LPSTR recordTemp = (FindRecordTemp (lpv)) [BASE_TBL_COUNT];
               ////////////// This only works for MP3 records
               INT primary = FindTableMapV (lpv, BASE_TBL_COUNT)->fields[SCINIT_FLD_AUDIT].wOffset;

               //Must propagate changes to primary key down to details
               if ( blkCompare (record, recordTemp, primary)!=0 ) {
                  CHAR oldKey [MAX_KEY_SIZE];
                  CHAR newKey [MAX_KEY_SIZE];
                  ERRNUM e;

                  blkCopy (newKey, record, primary);
                  blkCopy (oldKey, recordTemp, primary);
                  e = MapToDetails (lpv, VIEW_OP_REVISION_REKEY, oldKey, newKey,
                                    primary, 1 << SHIFT_REVISION_REKEY_LEVEL);
                  if ( ERRNUM_IS_FAILURE (e) ) {
                     MaxDatabaseError (&lpv->eRevision,
                                       ErrorMapViewToDatabase (VIEW_OP (lpv, OPEN), e));
                     rev[BASE_TBL_COUNT] = NULL;
                     return POST_ERROR;
                  }
               }
            }

            // revPostEtc() is called by table, then by record, which is
            // different than for ordered revisions above
            MaxDatabaseError (&lpv->eRevision, revPostEtc (lpv, op, BASE_TBL_COUNT));
            if ( DB_ERRNUM_IS_FAILURE (lpv->eRevision) ) {
               rev[BASE_TBL_COUNT] = NULL;
               return POST_ERROR;
            }
            if ( TBL_COUNT>1 ) {
               // if primary table record successfully posted update the parallel
               // tables to use the new sequence number.
               if ( op==REV_INSERT || op==REV_MOVE ) {
                  LPSTR *record = FindRecord (lpv);
                  LPSTR *recordTemp = FindRecordTemp (lpv);
                  ////////////// This only works for MP3 records
                  INT primary = FindTableMapV (lpv, BASE_TBL_COUNT)->fields[SCINIT_FLD_AUDIT].wOffset;

                  for ( i=BASE_TBL_COUNT+1; i<BASE_TBL_COUNT+TBL_COUNT; i++ ) {
                     blkCopy (record[i], recordTemp[BASE_TBL_COUNT], primary);
                     revRead (rev[i], record[i]);
                     MaxDatabaseError (&lpv->eRevision,
                                       revErrorV (lpv, rev[i],
                                                 revGetExtendedError (rev[i])));
                     if ( DB_ERRNUM_IS_FAILURE (lpv->eRevision) ) {
                        rev[BASE_TBL_COUNT] = NULL;
                        return POST_ERROR;
                     }
                     revDelete (rev[i], record[i]);
                     MaxDatabaseError (&lpv->eRevision,
                                       revErrorV (lpv, rev[i],
                                                 revGetExtendedError (rev[i])));
                     if ( DB_ERRNUM_IS_FAILURE (lpv->eRevision) ) {
                        rev[BASE_TBL_COUNT] = NULL;
                        return POST_ERROR;
                     }
                     blkCopy (record[i], record[BASE_TBL_COUNT], primary);
                     revInsert (rev[i], record[i]);
                     MaxDatabaseError (&lpv->eRevision,
                                       revErrorV (lpv, rev[i],
                                                 revGetExtendedError (rev[i])));
                     if ( DB_ERRNUM_IS_FAILURE (lpv->eRevision) ) {
                        rev[BASE_TBL_COUNT] = NULL;
                        return POST_ERROR;
                     }
                  }
               }
            }
            return POST_CONTINUE;

         case POST_DONE:
            rev[BASE_TBL_COUNT] = NULL;
            if ( TBL_COUNT>1 ) {
               // When primary table is finished, post remaining tables completely
               for ( i=BASE_TBL_COUNT+1; i<BASE_TBL_COUNT+TBL_COUNT; i++ ) {
                  REV_ERRNUM r = POST_DONE;

                  do {
                     r = filePrePost (lpv, &op, i);
                     switch ( r ) {
                        case POST_DONE:
                           rev[i] = NULL;
                           break;
                        case POST_ERROR:
                           rev[i] = NULL;
                           return POST_ERROR;
                        case POST_CONTINUE:
                           f = BaseNotifyFire (lpv, INSTANCE_NOTIFY_REVISION_COMMITTED_RECORD,
                                               1, (LPVOID) MAKELONG (op, BASE_TBL_COUNT));
                           MaxDatabaseError (&lpv->eRevision,
                                             ErrorMapViewToDatabase (VIEW_OP (lpv, OPEN), f));
                           if ( DB_ERRNUM_IS_FAILURE (lpv->eRevision) ) {
                              rev[BASE_TBL_COUNT] = NULL;
                              return POST_ERROR;
                           }

                           // revPostEtc() is called by table, then by record, which is
                           // different than for ordered revisions above
                           MaxDatabaseError (&lpv->eRevision, revPostEtc (lpv, op, i));
                           if ( DB_ERRNUM_IS_FAILURE (lpv->eRevision) ) {
                              rev[i] = NULL;
                              return POST_ERROR;
                           }
                           break;
                     }
                  } while ( r==POST_CONTINUE );
               }
            }
            break;
      }
   }

   return POST_DONE;
}



REV_ERRNUM WINAPI filePrePostBase (LPV lpv, LPWORD op, INT r)
{
   REV_ERRNUM e = POST_DONE; // revision error
   ERRNUM f = ERRNUM_SUCCESS;
   LPSTR *records;
   LPSTR *tempRecords;
#if defined(DO_PREPOSTETC)
   LPTABLEHANDLE handles = FindTableHandle (lpv);
#endif
   REVERROR error;

   if ( !(SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS) )
      return e;
   if ( HAS_REVISIONS==NO_REVISIONS )
      return e;
   if ( TBL_COUNT==0 )
      return e;
   if ( !lpv->bRevisioned )
      return e;

   records = FindRecord (lpv);
   tempRecords = FindRecordTemp (lpv);
   error.size = sizeof (error);
#if !defined(DO_PREPOSTETC)
   e = revPostErr ((FindTableRev (lpv)) [r], tempRecords[r], records[r], op, &error);
#else
   e = revExtractErr ((FindTableRev (lpv)) [r], tempRecords[r], records[r], op, &error);
#endif
   switch ( e ) {
      case POST_DONE:
         return e;
      case POST_ERROR:
         ReportGenericError (lpv, ERRGEN_AREA_REVLIST, error.op, error.ec, &error);
         MaxDatabaseError (&lpv->eRevision, error.ec);
         return e;
   }

#if defined(DO_PREPOSTETC)
   if ( (e = PrePostEtc (lpv, *op, r))==POST_ERROR ) {
      MaxDatabaseError (&lpv->eRevision, DBS_CVIEW_GENERAL);
      return e;
   }

   f = BaseNotifyFire (lpv, INSTANCE_NOTIFY_REVISION_EXTRACTED_RECORD,
                       1, (LPVOID) MAKELONG (*op, (SHORT) r));
   MaxError (&lpv->eRevision, ErrorMapViewToExtended (VIEW_OP (lpv, OPEN), f));
   if ( DB_ERRNUM_IS_FAILURE (lpv->eRevision) )
      return POST_ERROR;

   if ( *op!=REV_INSERT ) {
      WORD key = 0;
      LPSTR record;

      if ( r==0 && SUBCLASS_LEVEL==NOT_SUBCLASS )
         key = lpv->wActualKey;
      if ( REV_UPDATE==*op )
         record = records[r];
      else
         record = tempRecords[r];
      MaxDatabaseError (&lpv->eRevision, fileErrorV (lpv,
                        dbLock (lpv->wLinkNo, handles[r], key, record)));
      if ( DB_ERRNUM_IS_SUCCESS (lpv->eRevision) ) {
         if ( REV_UPDATE==*op ) {
            MaxDatabaseError (&lpv->eRevision, fileErrorV (lpv,
                              dbUpdate (lpv->wLinkNo, handles[r], record)));
         } else {
            MaxDatabaseError (&lpv->eRevision, fileErrorV (lpv,
                              dbDelete (lpv->wLinkNo, handles[r], record)));
         }
         if ( DB_ERRNUM_IS_FAILURE (lpv->eRevision) )
            dbUnLock (lpv->wLinkNo, handles[r], record);
      }
   }
   if ( DB_ERRNUM_IS_SUCCESS (lpv->eRevision) && (*op==REV_INSERT || *op==REV_MOVE) ) {
      MaxDatabaseError (&lpv->eRevision, fileErrorV (lpv,
                        dbInsert (lpv->wLinkNo, handles[r], records[r])));
   }
   if ( DB_ERRNUM_IS_FAILURE (lpv->eRevision) )
      e = POST_ERROR;
   else
      e = POST_CONTINUE;
#endif

   return e;
}



DB_ERRNUM WINAPI fileReversesBase (WORD wLinkNo)
{
   return dbIsSupported (wLinkNo, "dbGetLE");
}



DB_ERRNUM WINAPI fileRollbackBase (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;

#if !defined(DETAIL_VIEW)
   if ( !(SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS) )
      return d;
   if ( HAS_REVISIONS!=NO_REVISIONS )
      return d;
   CHECK_DBCALL (d, fileTransRollback (lpv));
#endif
   return d;
}



DB_ERRNUM WINAPI fileSelectFieldsBase (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;
   INT i;

   for ( i=BASE_TBL_COUNT; i<BASE_TBL_COUNT+TBL_COUNT; ++i ) {
      PTABLESELECTION selection = FindTableSelection (lpv, i);
      WORD handle = (FindTableHandle (lpv)) [i];

      if ( NULL==selection || 0==selection->count ) {
         CHECK_DBCALL (d, fileErrorV (lpv,
            dbSetFieldList (lpv->wLinkNo, handle, NULL, 0)));
      } else {
         CHECK_DBCALL (d, fileErrorV (lpv,
            dbSetFieldList (lpv->wLinkNo, handle, selection->fields[0],
                            lpv->pViewSelection->flags)));
      }
   }
   return d;
}



DB_ERRNUM WINAPI fileTransBeginBase (LPV lpv)
{
   WORD wLevel;
   DB_ERRNUM d = DBS_SUCCESS;

   CHECK_DBCALL (d, fileErrorV (lpv,
      lnkGetTransLevel (lpv->wLinkNo, &lpv->transLevel)));
#if defined(DO_TRANSLEVELCHECK) || defined(DO_SUPPRESSDUPLICATE)
   if ( lpv->transLevel>0 )
      return DBS_SUCCESS;
#endif

   if ( lpv->transIDs>=DO_TRANSACTIONSTACK ) {
      ReportGenericError (lpv, ERRGEN_AREA_DATABASE, 0, DBS_BUFFER_SIZE, NULL);
      return DBS_BUFFER_SIZE;
   }
   CHECK_DBCALL (d, fileErrorV (lpv,
      lnkBeginTrans (lpv->wLinkNo, &wLevel, &lpv->transIDstack[lpv->transIDs])));
   lpv->transIDs += 1;
   VIEWASSERT(wLevel>0 && lpv->transIDs>0);
   return d;
}



DB_ERRNUM WINAPI fileTransCommitBase (LPV lpv)
{
   WORD wLevel;
   DB_ERRNUM d = DBS_SUCCESS;

#if defined(DO_TRANSLEVELCHECK) || defined(DO_SUPPRESSDUPLICATE)
   if ( lpv->transLevel>0 )
      return DBS_SUCCESS;
#endif

   if ( lpv->transIDs<=0 ) {
      lpv->transIDs = 0;
      ReportGenericError (lpv, ERRGEN_AREA_DATABASE, 0, DBS_MISMATCHED_TRANS, NULL);
      return DBS_MISMATCHED_TRANS;
   }
   lpv->transIDs -= 1;
   MaxDatabaseError (&d, fileErrorV (lpv,
      lnkCommitTrans (lpv->wLinkNo, &wLevel, lpv->transIDstack[lpv->transIDs])));
   if ( DB_ERRNUM_IS_FAILURE(d) )
      lpv->transIDs = 0;
   VIEWASSERT((wLevel==0 && lpv->transIDs==0) || (wLevel>0 && lpv->transIDs>0));
   return d;
}



DB_ERRNUM WINAPI fileTransRollbackBase (LPV lpv)
{
   WORD wLevel;
   DB_ERRNUM d = DBS_SUCCESS;

#if defined(DO_TRANSLEVELCHECK) || defined(DO_SUPPRESSDUPLICATE)
   if ( lpv->transLevel>0 )
      return DBS_SUCCESS;
#endif

   if ( lpv->transIDs<=0 ) {
      lpv->transIDs = 0;
      ReportGenericError (lpv, ERRGEN_AREA_DATABASE, 0, DBS_MISMATCHED_TRANS, NULL);
      return DBS_MISMATCHED_TRANS;
   }
   lpv->transIDs -= 1;
   MaxDatabaseError (&d, fileErrorV (lpv,
      lnkAbortTrans (lpv->wLinkNo, &wLevel, lpv->transIDstack[lpv->transIDs])));
   if ( DB_ERRNUM_IS_FAILURE(d) )
      lpv->transIDs = 0;
   VIEWASSERT((wLevel==0 && lpv->transIDs==0) || (wLevel>0 && lpv->transIDs>0));
   return d;
}



DB_ERRNUM WINAPI fileUnLockBase (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;
   INT i = 0;

   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
      CHECK_DBCALL (d, ErrorMapViewToDatabase (VIEW_OP_UNLOCK,
         viewUnLock (lpv->subCmp.rvh, lpv->subCmp.view)));
   }
   if ( (SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS) &&
        !lpv->bRevisioned ) {
      for ( i=BASE_TBL_COUNT; i<BASE_TBL_COUNT+TBL_COUNT; i++ ) {
         CHECK_DBCALL (d, fileErrorV (lpv, dbUnLock (lpv->wLinkNo,
                                                     (FindTableHandle (lpv)) [i],
                                                     (FindRecord (lpv)) [i])));
      }
   }
   return d;
}



DB_ERRNUM WINAPI fileUpdateBase (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;
   INT i = 0;
   LPREVISION rev = FindTableRev (lpv);
   WORD key = lpv->wActualKey;

   CHECK_DBCALL (d, RevisionWasRealized (lpv));

   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
      LPVIEWDEF base = &lpv->subCmp;

      CHECK_DBCALL (d, ErrorMapViewToDatabase (VIEW_OP_PUT, BasePutData (lpv)));
      CHECK_DBCALL (d, ErrorMapViewToDatabase (VIEW_OP_UPDATE,
                                               viewUpdate (base->rvh, base->view)));
      key = 0;
   }

   if ( SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS ) {
      for ( i=BASE_TBL_COUNT; i<BASE_TBL_COUNT+TBL_COUNT; i++ ) {
         WORD handle = (FindTableHandle (lpv)) [i];
         LPSTR record = (FindRecord (lpv)) [i];
         PTABLESELECTION selection = FindTableSelection (lpv, i);

         if ( selection!=NULL && 0==selection->count )
            continue;
         if ( HAS_REVISIONS!=NO_REVISIONS && lpv->bRevisioned ) {
            revUpdate (rev[i], record);
            MaxDatabaseError (&d, revGetExtendedError (rev[i]));
         }
         if ( !lpv->bRevisioned ) {
            MaxDatabaseError (&d, dbUpdate (lpv->wLinkNo, handle, record));
            if ( DB_ERRNUM_IS_FAILURE (d) ) {
               if ( d==DBS_INVALID_POSITION )
                  d = dbLock (lpv->wLinkNo, handle, key, record);
#if defined(DO_CONCURRENCYETC)
               if ( d==DBS_CONFLICT && i==BASE_TBL_COUNT && NULL==lpv->pViewSelection ) {
                  INT r;
                  LPSTR FAR * records = FindRecordTemp (lpv);

                  d = DBS_SUCCESS;
                  lpv->bBrowsing = FALSE; // Breaks convention being in a file function
                  lpv->bBrowseEnded = TRUE;
                  CopyRecords (lpv, records, FindRecord (lpv));
                  for ( r=BASE_TBL_COUNT; r<BASE_TBL_COUNT+TBL_COUNT; r++ ) {
                     CHECK_DBCALL (d, fileErrorV (lpv,
                        dbGetLock (lpv->wLinkNo, (FindTableHandle (lpv)) [r],
                                   key, records[r], FALSE)));
                     key = 0;
                  }
                  CHECK_DBCALL (d,
                     ErrorMapViewToDatabase (VIEW_OP_UPDATE, MergeConflictedRecords (lpv)));
                  record = (FindRecord (lpv)) [i]; // was made stale by last call
               }
#endif
               if ( DB_ERRNUM_IS_SUCCESS (d) ) {
                  MaxDatabaseError (&d, dbUpdate (lpv->wLinkNo, handle, record));
               }
            }
         }
         if ( DB_ERRNUM_IS_FAILURE (d) )
            break;
         key = 0;
      }
#if defined(DO_SUPPRESSDUPLICATE)
      if ( d!=DBS_DUPLICATE_KEY )
#endif
      {
         if ( !lpv->bRevisioned ) {
            fileErrorV (lpv, d);
         }
         if ( HAS_REVISIONS!=NO_REVISIONS && lpv->bRevisioned ) {
            revErrorV (lpv, rev[i], d);
         }
      }
   }

   return d;
}



DB_ERRNUM WINAPI BufferedFetch (LPV lpv)
{
   DB_ERRNUM d = DBS_SUCCESS;

   if ( lpv->currentFetchedRecord>=lpv->fetchedRecordCount ) {
      // We have exhausted the buffer, so fetch some more
      if ( lpv->fetchedRecordCount<lpv->wFetchCount )
         // Since we fetched less than the full complement last time, we hit EOF
         return DBS_NO_MORE_DATA;
      lpv->currentFetchedRecord = 0;
      MaxDatabaseError (&d, dbFetch (lpv->wLinkNo,
                                     (FindTableHandle (lpv)) [BASE_TBL_COUNT],
                                     lpv->fetchedRecords,
                                     lpv->wFetchCount, &lpv->fetchedRecordCount));
      switch ( d ) {
         case DBS_SUCCESS:
            break;
         case DBS_NO_MORE_DATA:
            if ( lpv->fetchedRecordCount!=0 ) {
               d = DBS_SUCCESS;
               break;
            }
            // Fall thru when 0 fetched
         default:
            lpv->fetchedRecordCount = 0;
            return d;
      }
   }
   blkCopy ((FindRecord (lpv)) [BASE_TBL_COUNT],
             & lpv->fetchedRecords [lpv->currentFetchedRecord*lpv->wPrimaryRecordLength],
             lpv->wPrimaryRecordLength);
   lpv->currentFetchedRecord += 1;
   return d;
}

#endif



//////////////////////////////////////////////////////////////////////////////
// Error reporting functions



DB_ERRNUM WINAPI dbError (WORD wLinkNo, HPIB hpib, DB_ERRNUM d)
{
   if ( DB_ERRNUM_IS_FAILURE (d) ) {
      DBERROR error;

      error.size = sizeof (error);
      dbGetLastError (wLinkNo, &error);
      ReportGenericErrorViaPIB (hpib, ERRGEN_AREA_DATABASE, error.op, (WORD) d, &error);
   }
   return d;
}



DB_ERRNUM WINAPI dbErrorV (LPV lpv, DB_ERRNUM d)
{
   if ( DB_ERRNUM_IS_FAILURE (d) ) {
      DBERROR error;

      error.size = sizeof (error);
      dbGetLastError (lpv->wLinkNo, &error);
      ReportGenericError (lpv, ERRGEN_AREA_DATABASE, error.op, (WORD) d, &error);
   }
   return d;
}



FL_ERRNUM WINAPI filterError (HPIB hpib, WORD op, FL_ERRNUM f)

{
   if ( FL_ERRNUM_IS_FAILURE (f) )
      ReportGenericErrorViaPIB (hpib, ERRGEN_AREA_FILTER, op, (WORD) f, NULL);
   return f;
}



FL_ERRNUM WINAPI filterErrorV (LPV lpv, WORD op, FL_ERRNUM f)

{
   if ( FL_ERRNUM_IS_FAILURE (f) )
      ReportGenericError (lpv, ERRGEN_AREA_FILTER, op, (WORD) f, NULL);
   return f;
}



DB_ERRNUM WINAPI revError (HPIB hpib, LPVOID rev, DB_ERRNUM d)

{
   if ( DB_ERRNUM_IS_FAILURE (d) ) {
      REVERROR error;

      error.size = sizeof (error);
      revGetLastError (rev, &error);
      ReportGenericErrorViaPIB (hpib, ERRGEN_AREA_REVLIST, error.op, (WORD) d, &error);
   }
   return d;
}



DB_ERRNUM WINAPI revErrorV (LPV lpv, LPVOID rev, DB_ERRNUM d)

{
   if ( DB_ERRNUM_IS_FAILURE (d) ) {
      REVERROR error;

      error.size = sizeof (error);
      revGetLastError (rev, &error);
      ReportGenericError (lpv, ERRGEN_AREA_REVLIST, error.op, (WORD) d, &error);
   }
   return d;
}



//////////////////////////////////////////////////////////////////////////////
// Experimental stuff



VIEWCALL viewTableHandles (LPVOID rvh, LPVOID view, INT count, LPWORD handles)
{
   ROTOVIEW comm;

   comm.op = VIEW_OP_TABLE_HANDLES;
   comm.view = view;
   comm.i = count;
   comm.p = handles;
   return viewCall (rvh, &comm, sizeof (comm));
}



/*--------------------------------------------------------------------
   Retrieve the handles to tables managed by the view
*/
VIEWCALL scInitTableHandles (LPV lpv, INT count, LPWORD handles)
{
   ERRNUM e = ERRNUM_SUCCESS;
   INT i;
   SHORT baseTables = 0;

   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
      LPVIEWDEF base = &lpv->subCmp;

      CHECK_CALL (e, identifyViewTableCount ((LPRVH) base->rvh, &baseTables));
      CHECK_CALL (e, viewTableHandles (base->rvh, base->view, count, handles));
   }

   for ( i=baseTables; i<count && i-baseTables<TBL_COUNT; ++i ) {
      handles[i] = MapStubToTableHandle (lpv,
                      (FindTableHandle (lpv)) [i-baseTables+BASE_TBL_COUNT]);
   }
   return ERRNUM_SUCCESS;
}



//////////////////////////////////////////////////////////////////////////////
// Entrypoint remapping for extended error code mapping



#if DO_EXTENDEDERRORS<UNIVERSAL_EXTENDEDERRORS

#undef viewAttribs
#undef viewBlkGet
#undef viewBlkPut
#undef viewBrowse
#undef viewCall
#undef viewCallParam
#undef viewCancel
#undef viewClose
#undef viewCmpNames
#undef viewCompose
#undef viewCreate
#undef viewDelete
#undef viewDirty
#undef viewDrop
#undef viewExists
#undef viewFetch
#undef viewFetchLock
#undef viewField
#undef viewFieldExists
#undef viewFieldName
#undef viewFields
#undef viewFilterCount
#undef viewFilterDelete
#undef viewFilterFetch
#undef viewFilterSelect
#undef viewGet
#undef viewInit
#undef viewInsert
#undef viewInstanceFieldList
#undef viewInstanceNotify
#undef viewInstanceOpen
#undef viewInstanceProtocol
#undef viewInstanceSecurity
#undef viewKey
#undef viewKeys
#undef viewName
#undef viewOpen
#undef viewOrder
#undef viewPost
#undef viewPresents
#undef viewProcess
#undef viewPut
#undef viewRead
#undef viewReadLock
#undef viewRecordClear
#undef viewRecordGenerate
#undef viewRevisionCancel
#undef viewRevisionExists
#undef viewRevisionPost
#undef viewRevisionRekey
#undef viewRevisionUnposted
#undef viewSecurity
#undef viewTableEmpty
#undef viewType
#undef viewUnLock
#undef viewUpdate
#undef viewVerify



VIEWCALL viewExtendedAttribs (LPVOID rvh, LPVOID view, LONG field, LPLONG attributes)
{
   ERRNUM e = viewAttribs (rvh, view, field, attributes);

   return ErrorMapViewToExtended (VIEW_OP_ATTRIBUTES, e);
}



VIEWCALL viewExtendedBlkGet (LPVOID rvh, LPVOID view, INT fields, LPLONG fieldList, LPSHORT sizeList, LPVOID buffer)
{
   ERRNUM e = viewBlkGet (rvh, view, fields, fieldList, sizeList, buffer);

   return ErrorMapViewToExtended (VIEW_OP_BLKGET, e);
}



VIEWCALL viewExtendedBlkPut (LPVOID rvh, LPVOID view, INT fields, LPLONG fieldList, LPSHORT sizeList, LPVOID buffer, BOOL verify)
{
   ERRNUM e = viewBlkPut (rvh, view, fields, fieldList, sizeList, buffer, verify);

   return ErrorMapViewToExtended (VIEW_OP_BLKPUT, e);
}



VIEWCALL viewExtendedBrowse (LPVOID rvh, LPVOID view, LPSTR filter, BOOL ascending)
{
   ERRNUM e = viewBrowse (rvh, view, filter, ascending);

   return ErrorMapViewToExtended (VIEW_OP_BROWSE, e);
}



VIEWCALL viewExtendedCall (LPVOID rvh, LPROTOVIEW comm, INT length)
{
   ERRNUM e = viewCall (rvh, comm, length);

   return ErrorMapViewToExtended (comm->op, e);
}



VIEWCALL viewExtendedCallParam (LPVOID rvh, INT op, LPVOID view, INT i, BOOL flag, LONG field, LPVOID p, LPVOID q, LPVOID r, LPVOID s, INT length, LPVOID extra)
{
   ERRNUM e = viewCallParam (rvh, op, view, i, flag, field, p, q, r, s, length, extra);

   return ErrorMapViewToExtended (op, e);
}



VIEWCALL viewExtendedCancel (LPVOID rvh, LPVOID view)
{
   ERRNUM e = viewCancel (rvh, view);

   return ErrorMapViewToExtended (VIEW_OP_CANCEL, e);
}



VIEWCALL viewExtendedClose (LPVOID rvh, LPVOID view)
{
   ERRNUM e = viewClose (rvh, view);

   return ErrorMapViewToExtended (VIEW_OP_CLOSE, e);
}



VIEWCALL viewExtendedCmpNames (LPVOID rvh, LPSTR compositeNames, LPSHORT count)
{
   ERRNUM e = viewCmpNames (rvh, compositeNames, count);

   return ErrorMapViewToExtended (VIEW_OP_COMPOSITES, e);
}



VIEWCALL viewExtendedCompose (LPVOID rvh, LPVOID view, LPVIEWDEF composites)
{
   ERRNUM e = viewCompose (rvh, view, composites);

   return ErrorMapViewToExtended (VIEW_OP_COMPOSE, e);
}



VIEWCALL viewExtendedCreate (LPVOID rvh, HPIB PIB, WORD link)
{
   ERRNUM e = viewCreate (rvh, PIB, link);

   return ErrorMapViewToExtended (VIEW_OP_CREATE, e);
}



VIEWCALL viewExtendedDelete (LPVOID rvh, LPVOID view)
{
   ERRNUM e = viewDelete (rvh, view);

   return ErrorMapViewToExtended (VIEW_OP_DELETE, e);
}



VIEWCALL viewExtendedDirty (LPVOID rvh, LPVOID view, LPBOOL changed)
{
   ERRNUM e = viewDirty (rvh, view, changed);

   return ErrorMapViewToExtended (VIEW_OP_DIRTY, e);
}



VIEWCALL viewExtendedDrop (LPVOID rvh, HPIB PIB, WORD link)
{
   ERRNUM e = viewDrop (rvh, PIB, link);

   return ErrorMapViewToExtended (VIEW_OP_DROP, e);
}



VIEWCALL viewExtendedExists (LPVOID rvh, LPVOID view, LPBOOL exists)
{
   ERRNUM e = viewExists (rvh, view, exists);

   return ErrorMapViewToExtended (VIEW_OP_EXISTS, e);
}



VIEWCALL viewExtendedFetch (LPVOID rvh, LPVOID view)
{
   ERRNUM e = viewFetch (rvh, view);

   return ErrorMapViewToExtended (VIEW_OP_FETCH, e);
}



VIEWCALL viewExtendedFetchLock (LPVOID rvh, LPVOID view)
{
   ERRNUM e = viewFetchLock (rvh, view);

   return ErrorMapViewToExtended (VIEW_OP_FETCH_LOCK, e);
}



VIEWCALL viewExtendedField (LPVOID rvh, LPVOID view, INT number, LPSTR name, LPLONG field)
{
   ERRNUM e = viewField (rvh, view, number, name, field);

   return ErrorMapViewToExtended (VIEW_OP_FIELD, e);
}



VIEWCALL viewExtendedFieldExists (LPRVH rvh, LPVOID view, LONG field, LP_A4W_FLAGS flags)
{
   ERRNUM e = viewFieldExists (rvh, view, field, flags);

   return ErrorMapViewToExtended (VIEW_OP_FIELD_EXISTS, e);
}



VIEWCALL viewExtendedFieldName (LPRVH rvh, LPVOID view, LONG field, LPSTR name, LPSTR desc, A4W_SIZE size)
{
   ERRNUM e = viewFieldName (rvh, view, field, name, desc, size);

   return ErrorMapViewToExtended (VIEW_OP_FIELD_NAME, e);
}



VIEWCALL viewExtendedFields (LPVOID rvh, LPVOID view, LPSHORT fields)
{
   ERRNUM e = viewFields (rvh, view, fields);

   return ErrorMapViewToExtended (VIEW_OP_FIELDS, e);
}



VIEWCALL viewExtendedFilterCount (LPRVH rvh, LPVOID view, LPSTR filter, A4W_FLAGS flags, LP_A4W_SIZE count)
{
   ERRNUM e = viewFilterCount (rvh, view, filter, flags, count);

   return ErrorMapViewToExtended (VIEW_OP_FILTER_COUNT, e);
}



VIEWCALL viewExtendedFilterDelete (LPRVH rvh, LPVOID view, LPSTR filter, A4W_FLAGS flags)
{
   ERRNUM e = viewFilterDelete (rvh, view, filter, flags);

   return ErrorMapViewToExtended (VIEW_OP_FILTER_DELETE, e);
}



VIEWCALL viewExtendedFilterFetch (LPRVH rvh, LPVOID view, A4W_FLAGS flags)
{
   ERRNUM e = viewFilterFetch (rvh, view, flags);

   return ErrorMapViewToExtended (VIEW_OP_FILTER_FETCH, e);
}



VIEWCALL viewExtendedFilterSelect (LPRVH rvh, LPVOID view, INT key, LPSTR filter, A4W_FLAGS flags)
{
   ERRNUM e = viewFilterSelect (rvh, view, key, filter, flags);

   return ErrorMapViewToExtended (VIEW_OP_FILTER_SELECT, e);
}



VIEWCALL viewExtendedGet (LPVOID rvh, LPVOID view, LONG field, LPVOID buffer, INT size)
{
   ERRNUM e = viewGet (rvh, view, field, buffer, size);

   return ErrorMapViewToExtended (VIEW_OP_GET, e);
}



VIEWCALL viewExtendedInit (LPVOID rvh, LPVOID view)
{
   ERRNUM e = viewInit (rvh, view);

   return ErrorMapViewToExtended (VIEW_OP_INITIALIZE, e);
}



VIEWCALL viewExtendedInsert (LPVOID rvh, LPVOID view)
{
   ERRNUM e = viewInsert (rvh, view);

   return ErrorMapViewToExtended (VIEW_OP_INSERT, e);
}



VIEWCALL viewExtendedInstanceFieldList (LPRVH rvh, LPVOID view, A4W_FLAGS flags, A4W_SIZE count, PLONG fields)
{
   ERRNUM e = viewInstanceFieldList (rvh, view, flags, count, fields);

   return ErrorMapViewToExtended (VIEW_OP_INSTANCE_FIELDLIST, e);
}



VIEWCALL viewExtendedInstanceNotify (LPRVH rvh, LPVOID view, A4W_NOTIFY_PROC notify, LPVOID context, A4W_FLAGS flags)
{
   ERRNUM e = viewInstanceNotify (rvh, view, notify, context, flags);

   return ErrorMapViewToExtended (VIEW_OP_INSTANCE_NOTIFY, e);
}



VIEWCALL viewExtendedInstanceOpen (LPRVH rvh, HPIB PIB, WORD link, A4W_FLAGS flags, LPVOID extra, A4W_SIZE size, LPVOID FAR * view)
{
   ERRNUM e = viewInstanceOpen (rvh, PIB, link, flags, extra, size, view);

   return ErrorMapViewToExtended (VIEW_OP_INSTANCE_OPEN, e);
}



VIEWCALL viewExtendedInstanceProtocol (LPRVH rvh, LPVOID view, A4W_FLAGS flags, LP_A4W_FLAGS protocols, LP_A4W_SIZE count)
{
   ERRNUM e = viewInstanceProtocol (rvh, view, flags, protocols, count);

   return ErrorMapViewToExtended (VIEW_OP_INSTANCE_PROTOCOL, e);
}



VIEWCALL viewExtendedInstanceSecurity (LPRVH rvh, LPVOID view, LP_A4W_FLAGS flags)
{
   ERRNUM e = viewInstanceSecurity (rvh, view, flags);

   return ErrorMapViewToExtended (VIEW_OP_INSTANCE_SECURITY, e);
}



VIEWCALL viewExtendedKey (LPVOID rvh, LPVOID view, INT number, LPSTR name, LPSHORT fields, LPLONG keyFields)
{
   ERRNUM e = viewKey (rvh, view, number, name, fields, keyFields);

   return ErrorMapViewToExtended (VIEW_OP_KEY, e);
}



VIEWCALL viewExtendedKeys (LPVOID rvh, LPVOID view, LPSHORT keys)
{
   ERRNUM e = viewKeys (rvh, view, keys);

   return ErrorMapViewToExtended (VIEW_OP_KEYS, e);
}



VIEWCALL viewExtendedName (LPVOID rvh, LPVOID view, LONG field, LPSTR name, LPSTR desc)
{
   ERRNUM e = viewName (rvh, view, field, name, desc);

   return ErrorMapViewToExtended (VIEW_OP_NAME, e);
}



VIEWCALL viewExtendedOpen (LPVOID rvh, HPIB PIB, WORD link, LPVOID FAR * view)
{
   ERRNUM e = viewOpen (rvh, PIB, link, view);

   return ErrorMapViewToExtended (VIEW_OP_OPEN, e);
}



VIEWCALL viewExtendedOrder (LPVOID rvh, LPVOID view, INT key)
{
   ERRNUM e = viewOrder (rvh, view, key);

   return ErrorMapViewToExtended (VIEW_OP_ORDER, e);
}



VIEWCALL viewExtendedPost (LPVOID rvh, LPVOID view)
{
   ERRNUM e = viewPost (rvh, view);

   return ErrorMapViewToExtended (VIEW_OP_POST, e);
}



VIEWCALL viewExtendedPresents (LPVOID rvh, LPVOID view, LONG field, LPSTR mask, LPSHORT list, LPSHORT count, LPSTR strings, INT size)
{
   ERRNUM e = viewPresents (rvh, view, field, mask, list, count, strings, size);

   return ErrorMapViewToExtended (VIEW_OP_PRESENTATION, e);
}



VIEWCALL viewExtendedProcess (LPVOID rvh, LPVOID view)
{
   ERRNUM e = viewProcess (rvh, view);

   return ErrorMapViewToExtended (VIEW_OP_PROCESS, e);
}



VIEWCALL viewExtendedPut (LPVOID rvh, LPVOID view, LONG field, LPVOID buffer, INT size, BOOL verify)
{
   ERRNUM e = viewPut (rvh, view, field, buffer, size, verify);

   return ErrorMapViewToExtended (VIEW_OP_PUT, e);
}



VIEWCALL viewExtendedRead (LPVOID rvh, LPVOID view)
{
   ERRNUM e = viewRead (rvh, view);

   return ErrorMapViewToExtended (VIEW_OP_READ, e);
}



VIEWCALL viewExtendedReadLock (LPVOID rvh, LPVOID view)
{
   ERRNUM e = viewReadLock (rvh, view);

   return ErrorMapViewToExtended (VIEW_OP_READ_LOCK, e);
}



VIEWCALL viewExtendedRecordClear (LPRVH rvh, LPVOID view)
{
   ERRNUM e = viewRecordClear (rvh, view);

   return ErrorMapViewToExtended (VIEW_OP_RECORD_CLEAR, e);
}



VIEWCALL viewExtendedRecordGenerate (LPRVH rvh, LPVOID view, A4W_FLAGS flags)
{
   ERRNUM e = viewRecordGenerate (rvh, view, flags);

   return ErrorMapViewToExtended (VIEW_OP_RECORD_GENERATE, e);
}



VIEWCALL viewExtendedRevisionCancel (LPRVH rvh, LPVOID view, INT level)
{
   ERRNUM e = viewRevisionCancel (rvh, view, level);

   return ErrorMapViewToExtended (VIEW_OP_REVISION_CANCEL, e);
}



VIEWCALL viewExtendedRevisionExists (LPRVH rvh, LPVOID view, INT level, LP_A4W_FLAGS flags)
{
   ERRNUM e = viewRevisionExists (rvh, view, level, flags);

   return ErrorMapViewToExtended (VIEW_OP_REVISION_EXISTS, e);
}



VIEWCALL viewExtendedRevisionPost (LPRVH rvh, LPVOID view, INT level)
{
   ERRNUM e = viewRevisionPost (rvh, view, level);

   return ErrorMapViewToExtended (VIEW_OP_REVISION_POST, e);
}



VIEWCALL viewExtendedRevisionRekey (LPRVH rvh, LPVOID view, LPVOID OldKey, LPVOID NewKey, INT size, A4W_FLAGS flags)
{
   ERRNUM e = viewRevisionRekey (rvh, view, OldKey, NewKey, size, flags);

   return ErrorMapViewToExtended (VIEW_OP_REVISION_REKEY, e);
}



VIEWCALL viewExtendedRevisionUnposted (LPRVH rvh, LPVOID view, INT level, LP_A4W_FLAGS flags)
{
   ERRNUM e = viewRevisionUnposted (rvh, view, level, flags);

   return ErrorMapViewToExtended (VIEW_OP_REVISION_UNPOSTED, e);
}



VIEWCALL viewExtendedSecurity (LPVOID rvh, HPIB PIB, WORD link, LPLONG permissions)
{
   ERRNUM e = viewSecurity (rvh, PIB, link, permissions);

   return ErrorMapViewToExtended (VIEW_OP_SECURITY, e);
}



VIEWCALL viewExtendedTableEmpty (LPRVH rvh, LPVOID view)
{
   ERRNUM e = viewTableEmpty (rvh, view);

   return ErrorMapViewToExtended (VIEW_OP_TABLE_EMPTY, e);
}



VIEWCALL viewExtendedType (LPVOID rvh, LPVOID view, LONG field, LPTYPE type)
{
   ERRNUM e = viewType (rvh, view, field, type);

   return ErrorMapViewToExtended (VIEW_OP_TYPE, e);
}



VIEWCALL viewExtendedUnLock (LPVOID rvh, LPVOID view)
{
   ERRNUM e = viewUnLock (rvh, view);

   return ErrorMapViewToExtended (VIEW_OP_UNLOCK, e);
}



VIEWCALL viewExtendedUpdate (LPVOID rvh, LPVOID view)
{
   ERRNUM e = viewUpdate (rvh, view);

   return ErrorMapViewToExtended (VIEW_OP_UPDATE, e);
}



VIEWCALL viewExtendedVerify (LPVOID rvh, LPVOID view)
{
   ERRNUM e = viewVerify (rvh, view);

   return ErrorMapViewToExtended (VIEW_OP_VERIFY, e);
}



#if DO_EXTENDEDERRORS==NO_EXTENDEDERRORS

VIEWCALL viewOldAttribs (LPVOID rvh, LPVOID view, LONG field, LPLONG attributes)
{
   ERRNUM e = viewAttribs (rvh, view, field, attributes);

   return ErrorMapExtendedToOld (VIEW_OP_ATTRIBUTES, e);
}



VIEWCALL viewOldBlkGet (LPVOID rvh, LPVOID view, INT fields, LPLONG fieldList, LPSHORT sizeList, LPVOID buffer)
{
   ERRNUM e = viewBlkGet (rvh, view, fields, fieldList, sizeList, buffer);

   return ErrorMapExtendedToOld (VIEW_OP_BLKGET, e);
}



VIEWCALL viewOldBlkPut (LPVOID rvh, LPVOID view, INT fields, LPLONG fieldList, LPSHORT sizeList, LPVOID buffer, BOOL verify)
{
   ERRNUM e = viewBlkPut (rvh, view, fields, fieldList, sizeList, buffer, verify);

   return ErrorMapExtendedToOld (VIEW_OP_BLKPUT, e);
}



VIEWCALL viewOldBrowse (LPVOID rvh, LPVOID view, LPSTR filter, BOOL ascending)
{
   ERRNUM e = viewBrowse (rvh, view, filter, ascending);

   return ErrorMapExtendedToOld (VIEW_OP_BROWSE, e);
}



VIEWCALL viewOldCall (LPVOID rvh, LPROTOVIEW comm, INT length)
{
   ERRNUM e = viewCall (rvh, comm, length);

   return ErrorMapExtendedToOld (comm->op, e);
}



VIEWCALL viewOldCallParam (LPVOID rvh, INT op, LPVOID view, INT i, BOOL flag, LONG field, LPVOID p, LPVOID q, LPVOID r, LPVOID s, INT length, LPVOID extra)
{
   ERRNUM e = viewCallParam (rvh, op, view, i, flag, field, p, q, r, s, length, extra);

   return ErrorMapExtendedToOld (op, e);
}



VIEWCALL viewOldCancel (LPVOID rvh, LPVOID view)
{
   ERRNUM e = viewCancel (rvh, view);

   return ErrorMapExtendedToOld (VIEW_OP_CANCEL, e);
}



VIEWCALL viewOldClose (LPVOID rvh, LPVOID view)
{
   ERRNUM e = viewClose (rvh, view);

   return ErrorMapExtendedToOld (VIEW_OP_CLOSE, e);
}



VIEWCALL viewOldCmpNames (LPVOID rvh, LPSTR compositeNames, LPSHORT count)
{
   ERRNUM e = viewCmpNames (rvh, compositeNames, count);

   return ErrorMapExtendedToOld (VIEW_OP_COMPOSITES, e);
}



VIEWCALL viewOldCompose (LPVOID rvh, LPVOID view, LPVIEWDEF composites)
{
   ERRNUM e = viewCompose (rvh, view, composites);

   return ErrorMapExtendedToOld (VIEW_OP_COMPOSE, e);
}



VIEWCALL viewOldCreate (LPVOID rvh, HPIB PIB, WORD link)
{
   ERRNUM e = viewCreate (rvh, PIB, link);

   return ErrorMapExtendedToOld (VIEW_OP_CREATE, e);
}



VIEWCALL viewOldDelete (LPVOID rvh, LPVOID view)
{
   ERRNUM e = viewDelete (rvh, view);

   return ErrorMapExtendedToOld (VIEW_OP_DELETE, e);
}



VIEWCALL viewOldDirty (LPVOID rvh, LPVOID view, LPBOOL changed)
{
   ERRNUM e = viewDirty (rvh, view, changed);

   return ErrorMapExtendedToOld (VIEW_OP_DIRTY, e);
}



VIEWCALL viewOldDrop (LPVOID rvh, HPIB PIB, WORD link)
{
   ERRNUM e = viewDrop (rvh, PIB, link);

   return ErrorMapExtendedToOld (VIEW_OP_DROP, e);
}



VIEWCALL viewOldExists (LPVOID rvh, LPVOID view, LPBOOL exists)
{
   ERRNUM e = viewExists (rvh, view, exists);

   return ErrorMapExtendedToOld (VIEW_OP_EXISTS, e);
}



VIEWCALL viewOldFetch (LPVOID rvh, LPVOID view)
{
   ERRNUM e = viewFetch (rvh, view);

   return ErrorMapExtendedToOld (VIEW_OP_FETCH, e);
}



VIEWCALL viewOldFetchLock (LPVOID rvh, LPVOID view)
{
   ERRNUM e = viewFetchLock (rvh, view);

   return ErrorMapExtendedToOld (VIEW_OP_FETCH_LOCK, e);
}



VIEWCALL viewOldField (LPVOID rvh, LPVOID view, INT number, LPSTR name, LPLONG field)
{
   ERRNUM e = viewField (rvh, view, number, name, field);

   return ErrorMapExtendedToOld (VIEW_OP_FIELD, e);
}



VIEWCALL viewOldFieldExists (LPRVH rvh, LPVOID view, LONG field, LP_A4W_FLAGS flags)
{
   ERRNUM e = viewFieldExists (rvh, view, field, flags);

   return ErrorMapExtendedToOld (VIEW_OP_FIELD_EXISTS, e);
}



VIEWCALL viewOldFieldName (LPRVH rvh, LPVOID view, LONG field, LPSTR name, LPSTR desc, A4W_SIZE size)
{
   ERRNUM e = viewFieldName (rvh, view, field, name, desc, size);

   return ErrorMapExtendedToOld (VIEW_OP_FIELD_NAME, e);
}



VIEWCALL viewOldFields (LPVOID rvh, LPVOID view, LPSHORT fields)
{
   ERRNUM e = viewFields (rvh, view, fields);

   return ErrorMapExtendedToOld (VIEW_OP_FIELDS, e);
}



VIEWCALL viewOldFilterCount (LPRVH rvh, LPVOID view, LPSTR filter, A4W_FLAGS flags, LP_A4W_SIZE count)
{
   ERRNUM e = viewFilterCount (rvh, view, filter, flags, count);

   return ErrorMapExtendedToOld (VIEW_OP_FILTER_COUNT, e);
}



VIEWCALL viewOldFilterDelete (LPRVH rvh, LPVOID view, LPSTR filter, A4W_FLAGS flags)
{
   ERRNUM e = viewFilterDelete (rvh, view, filter, flags);

   return ErrorMapExtendedToOld (VIEW_OP_FILTER_DELETE, e);
}



VIEWCALL viewOldFilterFetch (LPRVH rvh, LPVOID view, A4W_FLAGS flags)
{
   ERRNUM e = viewFilterFetch (rvh, view, flags);

   return ErrorMapExtendedToOld (VIEW_OP_FILTER_FETCH, e);
}



VIEWCALL viewOldFilterSelect (LPRVH rvh, LPVOID view, INT key, LPSTR filter, A4W_FLAGS flags)
{
   ERRNUM e = viewFilterSelect (rvh, view, key, filter, flags);

   return ErrorMapExtendedToOld (VIEW_OP_FILTER_SELECT, e);
}



VIEWCALL viewOldGet (LPVOID rvh, LPVOID view, LONG field, LPVOID buffer, INT size)
{
   ERRNUM e = viewGet (rvh, view, field, buffer, size);

   return ErrorMapExtendedToOld (VIEW_OP_GET, e);
}



VIEWCALL viewOldInit (LPVOID rvh, LPVOID view)
{
   ERRNUM e = viewInit (rvh, view);

   return ErrorMapExtendedToOld (VIEW_OP_INITIALIZE, e);
}



VIEWCALL viewOldInsert (LPVOID rvh, LPVOID view)
{
   ERRNUM e = viewInsert (rvh, view);

   return ErrorMapExtendedToOld (VIEW_OP_INSERT, e);
}



VIEWCALL viewOldInstanceFieldList (LPRVH rvh, LPVOID view, A4W_FLAGS flags, A4W_SIZE count, PLONG fields)
{
   ERRNUM e = viewInstanceFieldList (rvh, view, flags, count, fields);

   return ErrorMapExtendedToOld (VIEW_OP_INSTANCE_FIELDLIST, e);
}



VIEWCALL viewOldInstanceNotify (LPRVH rvh, LPVOID view, A4W_NOTIFY_PROC notify, LPVOID context, A4W_FLAGS flags)
{
   ERRNUM e = viewInstanceNotify (rvh, view, notify, context, flags);

   return ErrorMapExtendedToOld (VIEW_OP_INSTANCE_NOTIFY, e);
}



VIEWCALL viewOldInstanceOpen (LPRVH rvh, HPIB PIB, WORD link, A4W_FLAGS flags, LPVOID extra, A4W_SIZE size, LPVOID FAR * view)
{
   ERRNUM e = viewInstanceOpen (rvh, PIB, link, flags, extra, size, view);

   return ErrorMapExtendedToOld (VIEW_OP_INSTANCE_OPEN, e);
}



VIEWCALL viewOldInstanceProtocol (LPRVH rvh, LPVOID view, A4W_FLAGS flags, LP_A4W_FLAGS protocols, LP_A4W_SIZE count)
{
   ERRNUM e = viewInstanceProtocol (rvh, view, flags, protocols, count);

   return ErrorMapExtendedToOld (VIEW_OP_INSTANCE_PROTOCOL, e);
}



VIEWCALL viewOldInstanceSecurity (LPRVH rvh, LPVOID view, LP_A4W_FLAGS flags)
{
   ERRNUM e = viewInstanceSecurity (rvh, view, flags);

   return ErrorMapExtendedToOld (VIEW_OP_INSTANCE_SECURITY, e);
}



VIEWCALL viewOldKey (LPVOID rvh, LPVOID view, INT number, LPSTR name, LPSHORT fields, LPLONG keyFields)
{
   ERRNUM e = viewKey (rvh, view, number, name, fields, keyFields);

   return ErrorMapExtendedToOld (VIEW_OP_KEY, e);
}



VIEWCALL viewOldKeys (LPVOID rvh, LPVOID view, LPSHORT keys)
{
   ERRNUM e = viewKeys (rvh, view, keys);

   return ErrorMapExtendedToOld (VIEW_OP_KEYS, e);
}



VIEWCALL viewOldName (LPVOID rvh, LPVOID view, LONG field, LPSTR name, LPSTR desc)
{
   ERRNUM e = viewName (rvh, view, field, name, desc);

   return ErrorMapExtendedToOld (VIEW_OP_NAME, e);
}



VIEWCALL viewOldOpen (LPVOID rvh, HPIB PIB, WORD link, LPVOID FAR * view)
{
   ERRNUM e = viewOpen (rvh, PIB, link, view);

   return ErrorMapExtendedToOld (VIEW_OP_OPEN, e);
}



VIEWCALL viewOldOrder (LPVOID rvh, LPVOID view, INT key)
{
   ERRNUM e = viewOrder (rvh, view, key);

   return ErrorMapExtendedToOld (VIEW_OP_ORDER, e);
}



VIEWCALL viewOldPost (LPVOID rvh, LPVOID view)
{
   ERRNUM e = viewPost (rvh, view);

   return ErrorMapExtendedToOld (VIEW_OP_POST, e);
}



VIEWCALL viewOldPresents (LPVOID rvh, LPVOID view, LONG field, LPSTR mask, LPSHORT list, LPSHORT count, LPSTR strings, INT size)
{
   ERRNUM e = viewPresents (rvh, view, field, mask, list, count, strings, size);

   return ErrorMapExtendedToOld (VIEW_OP_PRESENTATION, e);
}



VIEWCALL viewOldProcess (LPVOID rvh, LPVOID view)
{
   ERRNUM e = viewProcess (rvh, view);

   return ErrorMapExtendedToOld (VIEW_OP_PROCESS, e);
}



VIEWCALL viewOldPut (LPVOID rvh, LPVOID view, LONG field, LPVOID buffer, INT size, BOOL verify)
{
   ERRNUM e = viewPut (rvh, view, field, buffer, size, verify);

   return ErrorMapExtendedToOld (VIEW_OP_PUT, e);
}



VIEWCALL viewOldRead (LPVOID rvh, LPVOID view)
{
   ERRNUM e = viewRead (rvh, view);

   return ErrorMapExtendedToOld (VIEW_OP_READ, e);
}



VIEWCALL viewOldReadLock (LPVOID rvh, LPVOID view)
{
   ERRNUM e = viewReadLock (rvh, view);

   return ErrorMapExtendedToOld (VIEW_OP_READ_LOCK, e);
}



VIEWCALL viewOldRecordClear (LPRVH rvh, LPVOID view)
{
   ERRNUM e = viewRecordClear (rvh, view);

   return ErrorMapExtendedToOld (VIEW_OP_RECORD_CLEAR, e);
}



VIEWCALL viewOldRecordGenerate (LPRVH rvh, LPVOID view, A4W_FLAGS flags)
{
   ERRNUM e = viewRecordGenerate (rvh, view, flags);

   return ErrorMapExtendedToOld (VIEW_OP_RECORD_GENERATE, e);
}



VIEWCALL viewOldRevisionCancel (LPRVH rvh, LPVOID view, INT level)
{
   ERRNUM e = viewRevisionCancel (rvh, view, level);

   return ErrorMapExtendedToOld (VIEW_OP_REVISION_CANCEL, e);
}



VIEWCALL viewOldRevisionExists (LPRVH rvh, LPVOID view, INT level, LP_A4W_FLAGS flags)
{
   ERRNUM e = viewRevisionExists (rvh, view, level, flags);

   return ErrorMapExtendedToOld (VIEW_OP_REVISION_EXISTS, e);
}



VIEWCALL viewOldRevisionPost (LPRVH rvh, LPVOID view, INT level)
{
   ERRNUM e = viewRevisionPost (rvh, view, level);

   return ErrorMapExtendedToOld (VIEW_OP_REVISION_POST, e);
}



VIEWCALL viewOldRevisionRekey (LPRVH rvh, LPVOID view, LPVOID OldKey, LPVOID NewKey, INT size, A4W_FLAGS flags)
{
   ERRNUM e = viewRevisionRekey (rvh, view, OldKey, NewKey, size, flags);

   return ErrorMapExtendedToOld (VIEW_OP_REVISION_REKEY, e);
}



VIEWCALL viewOldRevisionUnposted (LPRVH rvh, LPVOID view, INT level, LP_A4W_FLAGS flags)
{
   ERRNUM e = viewRevisionUnposted (rvh, view, level, flags);

   return ErrorMapExtendedToOld (VIEW_OP_REVISION_UNPOSTED, e);
}



VIEWCALL viewOldSecurity (LPVOID rvh, HPIB PIB, WORD link, LPLONG permissions)
{
   ERRNUM e = viewSecurity (rvh, PIB, link, permissions);

   return ErrorMapExtendedToOld (VIEW_OP_SECURITY, e);
}



VIEWCALL viewOldTableEmpty (LPRVH rvh, LPVOID view)
{
   ERRNUM e = viewTableEmpty (rvh, view);

   return ErrorMapExtendedToOld (VIEW_OP_TABLE_EMPTY, e);
}



VIEWCALL viewOldType (LPVOID rvh, LPVOID view, LONG field, LPTYPE type)
{
   ERRNUM e = viewType (rvh, view, field, type);

   return ErrorMapExtendedToOld (VIEW_OP_TYPE, e);
}



VIEWCALL viewOldUnLock (LPVOID rvh, LPVOID view)
{
   ERRNUM e = viewUnLock (rvh, view);

   return ErrorMapExtendedToOld (VIEW_OP_UNLOCK, e);
}



VIEWCALL viewOldUpdate (LPVOID rvh, LPVOID view)
{
   ERRNUM e = viewUpdate (rvh, view);

   return ErrorMapExtendedToOld (VIEW_OP_UPDATE, e);
}



VIEWCALL viewOldVerify (LPVOID rvh, LPVOID view)
{
   ERRNUM e = viewVerify (rvh, view);

   return ErrorMapExtendedToOld (VIEW_OP_VERIFY, e);
}

#endif

#endif



/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

// This section implements the identify entrypoints



static void VersionNumericToString (INT numeric, LPSTR string)
{
   string[2] = (CHAR) ('A' + ((numeric & 0xf) - 10));
   numeric >>= 4;
   string[1] = (CHAR) ('0' + (numeric & 0xf));
   numeric >>= 4;
   string[0] = (CHAR) ('0' + (numeric & 0xf));
}



VIEWCALL scInitVersionTemplate (INT roto, LPSTR version, LPBCDDATE date)
{
   ERRNUM e = ERRNUM_SUCCESS;

   VersionNumericToString (TEMPLATE_VERSION, version);
   bcdGrow (date, TEMPLATE_DATE, SIZEOF_DATE);

   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
      char subVersion [SIZEOF_VERSION];
      BCDDATE subDate;
      VIEWDEF base;

      if ( (base.rvh = BaseLoad (roto))==NULL ) {
         //// !!!!!!!!!!! ReportBaseLoadError (hPIB, subCmpName);
         return ERRNUM_LOAD_FAILED;
      }
      MaxError (&e, identifyVersionTemplate ((LPRVH) base.rvh, subVersion, subDate));
      BaseUnload (&base);
      if ( ERRNUM_IS_SUCCESS (e) ) {
         int compare = blkCompare (version, subVersion, SIZEOF_VERSION);

         if ( compare<0 || (compare==0 &&
                            bcdCompare (date, SIZEOF_DATE, 0,
                                        subDate, sizeof (subDate), 0)<0) ) {
            blkCopy (version, subVersion, sizeof (subVersion));
            blkCopy (date, subDate, sizeof (subDate));
         }
      }
   }

   return e;
}



VIEWCALL scInitVersionAPI (INT roto, LPSTR version)
{
   ERRNUM e = ERRNUM_SUCCESS;

   VersionNumericToString (A4W_API_VERSION, version);

   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
      char subVersion [SIZEOF_VERSION];
      VIEWDEF base;

      if ( (base.rvh = BaseLoad (roto))==NULL ) {
         //// !!!!!!!!!!! ReportBaseLoadError (hPIB, subCmpName);
         return ERRNUM_LOAD_FAILED;
      }
      MaxError (&e, identifyVersionAPI ((LPRVH) base.rvh, subVersion));
      BaseUnload (&base);
      if ( ERRNUM_IS_SUCCESS (e) &&
           blkCompare (version, subVersion, SIZEOF_VERSION)<0 )
         blkCopy (version, subVersion, SIZEOF_VERSION);
   }

   return e;
}



VIEWCALL scInitViewName (HPIB pib, LPSTR name, INT size)
{
   rscLoadText (pib, APPL, IDS_SCINIT_VIEW_NAME, name, size);
   return ERRNUM_SUCCESS;
}



VIEWCALL scInitViewTableCount (INT roto, LPSHORT tableCount)
{
   ERRNUM e = ERRNUM_SUCCESS;

   if ( SUBCLASS_LEVEL==NOT_SUBCLASS )
      *tableCount = TBL_COUNT;
   else {
      VIEWDEF base;

      if ( (base.rvh = BaseLoad (roto))==NULL ) {
         //// !!!!!!!!!!! ReportBaseLoadError (hPIB, subCmpName);
         return ERRNUM_LOAD_FAILED;
      }
      MaxError (&e, identifyViewTableCount ((LPRVH) base.rvh, tableCount));
      if ( ERRNUM_IS_SUCCESS (e) )
         *tableCount += TBL_COUNT;
      BaseUnload (&base);
   }
   return e;
}



VIEWCALL scInitViewTables (INT roto, LPSTR tableNames, INT size)
{
   INT i;
   SHORT baseTables = 0;
   ERRNUM e = ERRNUM_SUCCESS;

   if ( SUBCLASS_LEVEL!=NOT_SUBCLASS ) {
      VIEWDEF base;

      if ( (base.rvh = BaseLoad (roto))==NULL ) {
         //// !!!!!!!!!!! ReportBaseLoadError (hPIB, subCmpName);
         return ERRNUM_LOAD_FAILED;
      }
      MaxError (&e, identifyViewTableCount ((LPRVH) base.rvh, &baseTables));
      if ( ERRNUM_IS_SUCCESS (e) ) {
         MaxError (&e, identifyViewTables ((LPRVH) base.rvh, tableNames, size));
      }
      BaseUnload (&base);
   }

   for ( i=baseTables; i-baseTables<TBL_COUNT && (i+1)*SIZEOF_TABLENAME<=size; ++i )
      blkCopy (&tableNames[i*SIZEOF_TABLENAME],
               (FindTableMap (i-baseTables+BASE_TBL_COUNT))->table->sName,
               SIZEOF_TABLENAME);
   if ( (TBL_COUNT+baseTables)*SIZEOF_TABLENAME>size ) {
      MaxError (&e, ERRNUM_MEMORY_BUFFER_LIMIT);
   }
   return e;
}



/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////



#if defined(__cplusplus)

tagV::tagV()
{
   // This is absolutely gross, as far as C++ is concerned. However, we need
   // mimic the memAlloc behaviour of zeroing the allocated block. It requires
   // that tagV NOT have virtual member functions. tagV is preserved as a
   // good old fashioned C structure
   blkSet (this, 0, sizeof (*this));
}



VBASE::~VBASE()
{
   // Virtual destructor to anchor the "OO" view handle
}

#endif



/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////


#if defined LINUX_VER

static void scInit_init (void)
{
    if (!LibMainEtc (0, 0, 0, 0)) exit (1);
}

static void (*const __CTOR_ENTRY__[1]) (void)
    __attribute__ ((section (".ctors")))
    = { scInit_init };

#elif defined WIN32

BOOL WINAPI DllMain( HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved )
{
   BOOL result = TRUE;

   switch( dwReason ) {
      case DLL_PROCESS_ATTACH:
         result = LibMainEtc (hInstance, 0, 0, NULL) != 0;
         break;
      default:
         break;
   }
   return result;
}

#else
    #error Unrecognised build
#endif


#if defined(__cplusplus)
}
#endif
