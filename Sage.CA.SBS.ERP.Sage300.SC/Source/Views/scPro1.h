/*--------------------------------------------------------------------

    File        :   scPro1.h
    Purpose     :   Constant definitions for this view.

    Copyright � 2019 Sage Software Asia Pte Ltd. All rights reserved.

--------------------------------------------------------------------*/


#ifndef __scPro1_h
// Ensures header is only included once.
#define __scPro1_h        1


#ifdef __cplusplus
extern "C" {
#endif


///////////////////////////////////////////////////////////////////////
// Definitions of view protocol and general behaviour.

// +++

// Uncomment one of the *_VIEW defines in order to select the
// appropriate view protocol. Note that there are other *_VIEW protocol
// switches following these; they are used to augment the basic behaviour
// of the following five general protocols.
//#define FLAT_VIEW 1
//#define HEADER_VIEW 1
//#define DETAIL_VIEW 1
#define SUPER_VIEW 1
//#define BATCH_VIEW 1

// If this is a header or detail with batch behaviour, namely that the
// header part of the view's key must exist to enter records, uncomment
// BATCH_VIEW below too. Note that it can be both a general protocol,
// as well as a behaviour modifier on another protocol. The most common
// use is to modify HEADER_VIEW with it in a batch/header/detail view set.
//#define BATCH_VIEW 1

// If this is a subclass view uncomment the following too. SUBCLASS_VIEW
// may then be defined to one of OVERRIDE_SUBCLASS, ALTER_SUBCLASS or
// JOIN_SUBCLASS. Note that you can code knowledge of the base view's
// composites. If you do so you must keep the same ordering and not drop
// any out, though you may omit the last ones; the degenerate case of
// course is 0 (explicit) composites.
//#define SUBCLASS_VIEW ALTER_SUBCLASS

// Uncomment the following if this view is to act as a stub for full view.
// If possible you should base the stub view on the same set of source as
// the full view. This can be done by filling in the STUB_VIEW conditional
// section in scPro1.c, and using -DSTUB_VIEW on the compiler command line
// instead of uncommenting this line.
//#define STUB_VIEW 1



// Indicate if the view uses revision lists. HAS_REVISIONS must be set to
// one of NO_REVISIONS, SEQUENCE_REVISIONS or ORDER_REVISIONS. Most detail
// views should use revisions.
#define HAS_REVISIONS    NO_REVISIONS

// Uncomment the following if the Header view uses revisions.  It is only
// possible to use this flag if HAS_REVISIONS != NO_REVISIONS
// and HDR_CMP_COUNT > 0
//#define HDR_HAS_REVISIONS 1

// ---


/////////////////////////////////////////////////////////////////////////////
// Define the view's compositional relations. Broken down by protocol
// in which they are accessed/defined.

// +++

// Set to the number of Header views required. It is only meaningful for
// there to be 1 header view at most. The header view's primary key comprises
// the first portion of a detail view's primary key.
#define HDR_CMP_COUNT    0

// Set to the number of Detail views required. The detail views share the
// first portion of their primary keys with the header view's. It is
// meaningful for a header view to have >=1 detail view(s).
#define DTL_CMP_COUNT    0

// The remaining compositions are characterized by their primary keys
// being specified as foreign keys in the view. That is, they are comprised
// of fields which are data fields or are not part of the header key.

// Set to the number of Hierarchical views required.
#define HCHY_CMP_COUNT   0

// Set to the number of Hierarchical views required. The caller might not
// pass them explicitly via scProCompose, in which case they will be loaded
// on demand and be treated subsequently as implicit compositions.
#define DMND_CMP_COUNT   0

// Set to the number of Implicit (Hierarchical) views with which this view
// is composed.
#define IMP_CMP_COUNT    0

// Set to the number of manually composed views. These are not maintained
// except to close them upon the view being closed. The programmer must
// manually maintain them.
#define MAN_CMP_COUNT    5

// ---



/////////////////////////////////////////////////////////////////////////////
// Definitions for view fields and keys, and for database table fields
// and keys.

// +++

// Uncomment the following #define if you want indexes to be prefixed with
// the application name. Must be uncommented for subclass views
//#define FLD_IDX_PFX 'SC'

// Number of keys of the primary table
// (Secondary tables only need primary key from primary table)
#define SCPRO_KEY_COUNT   0
// This is currently reserved for future use
#define FAKE_KEY_COUNT   0
// Total number of keys published by the view
#define KEY_COUNT        (SCPRO_KEY_COUNT-JOIN_KEY_COUNT+FAKE_KEY_COUNT)

// If view is detail protocol, set this to the number of segments being added
// to the header's base key.
#define DTL_SEG_COUNT    0


// Number of tables, both physical and calculated
#define BASE_TBL_COUNT   0  /* Subclass views adding in to base view's table */
#define TBL_COUNT        0  /* Multiple tables are allowed */
#define CALC_TBL_COUNT   1


// First field of audit stamp (0-based). For superviews, subclass views
// or calculated records this should be set to 0. If view has multiple
// tables, define *_FLD_AUDIT for them too.
#define SCPRO_FLD_AUDIT        0//SCPRO_FLD(AUDTDATE)
//#define SCPRO2_FLD_AUDIT       SCPRO2_FLD(AUDTDATE)


// Number of field indexes published from the view
#define FLD_IDX_COUNT    (SCPRO_IDX_COUNT)
// if multiple tables are used uncomment the following define in place of the above
//#define FLD_IDX_COUNT    (SCPRO_IDX_COUNT + SCPRO2_IDX_COUNT)

// Highest-valued field index + 1 for C-style array dimensioning
#define FLD_IDX_LIMIT    (1+SCPRO_IDX(PROCESSCMD))

// ---



/////////////////////////////////////////////////////////////////////////////
// Miscellaneous constants

// +++

// Number of security resources relevant to this view.
#define RSC_COUNT 1


// Default skip value for sequenced revision list views
#define REV_SEQ_SKIP 1000L


// Application prefix string -- No edit needed
#define APPL            "SC"


// Table handle type definition. If not table based (eg-as in a stub view)
// define to the appropriate type.
//#define TABLEHANDLE WORD

// ---



/////////////////////////////////////////////////////////////////////////////
// Conditionally include supplemental supporting routines for view calls.
// Remove comment as required. See scPro1.c file for comments on usage of each

// +++

//#define A4W_API_VERSION              0x53A /* Defaults to lastest template version */
//#define DO_APPLYHEADERFIELDS         1
//#define DO_ATTRIBETC                 1
//#define DO_AUTOCANCELBODY            1
//#define DO_BASENOTIFY                1
//#define DO_CALCULATEFIELDS           1
//#define DO_CANCELBODY                1
//#define DO_CASCADEPOST               CASCADEPOST_DEFAULT /* or CASCADEPOST_FIRST or CASCADEPOST_AFTERHEADER */
//#define DO_CLEARAUDIT                1
#define DO_CMPNAMESTRUCT             1
//#define DO_COMPOSEETC                1
//#define DO_COMPOSITENOTIFY           1
//#define DO_CONCURRENCYETC            1
//#define DO_CREATEETC                 1
//#define DO_DELETEBODY                1
//#define DO_DELETEDETAILSBODY         1
#define DO_DELETEFILTERDELETE        1
//#define DO_DELETEVALID               1
//#define DO_ENTRYSTATEEXTRA           1
//#define DO_ENTRYSTATEPOP             1
//#define DO_ENTRYSTATEPUSH            1
#define DO_EXTENDEDERRORS            PROCESS_EXTENDEDERRORS /* or NO_EXTENDEDERRORS or RETURN_EXTENDEDERRORS */
//#define DO_FETCHCOUNT                8 /* number of records to dbFetch() at once */
//#define DO_FINDPRESENTSINFO          1
//#define DO_GENERATEKEY               1
//#define DO_GENERATEKEYDELAYED        1
//#define DO_GETETC                    1
//#define DO_HEADERETC                 1  /* Number of fields mapped to header */
//#define DO_INITBODYGEN               1
//#define DO_INITFIELDSTRUCTETC        1
#define DO_INITNONBLANKFIELDS        1
//#define DO_INSTANCE_FIELDLIST        1
//#define DO_HELPERSOUTOFLINE          1
#define DO_LAZYPUT                   1
#define DO_LAZYVERIFY                1
//#define DO_LIBMAINETC                1
#define DO_LOADCOMPANYINFO           1
//#define DO_MAPTODETAIL               1
//#define DO_NOTIFYFIRE                1
//#define DO_NOTIFYQUEUEFIELDVALUE     1
//#define DO_OLDFILEERROR              1
//#define DO_OLDIMPORTVALIDATION       1
//#define DO_OLDINITBODYCASCADE        1
//#define DO_OLDOPENETC                1
//#define DO_OLDSUBCLASSFIELDBLK       1
//#define DO_OLDVERIFYDIRTY            1
#define DO_OPENETC                   1
//#define DO_PREPOSTETC                1
#define DO_PROCESSETC                1
//#define DO_PUTCMPFIELD               1
//#define DO_PUTCMPKEY                 1
//#define DO_PUTETC                    1
//#define DO_PUTSAVECURRENT            1
//#define DO_RECORDREAD                1
//#define DO_REKEYEDREVISION           1
//#define DO_REPORTERROR               1
//#define DO_REPORTERRORVIAPIB         1
//#define DO_REPORTGENERICERROR        1
//#define DO_REPORTGENERICERRORVIAPIB  1
//#define DO_REVERSEHEADERFIELDS       1
//#define DO_REVISIONINNERPOST         1
//#define DO_REVPOSTETC                1
//#define DO_ROTOENTRY                 1
//#define DO_ROTOENTRYETC              1
//#define DO_SAFEPUTETC                1
//#define DO_SAVEHEADERFIELDS          1
//#define DO_SCRATCHSTACK              4096  /* LIFO temporary storage */
//#define DO_SUPPRESSDUPLICATE         1
//#define TEMPLATE_WARNING_LEVEL       0 /* the higher the number the less verbose */
//#define DO_TRANSACTIONSTACK          10 /* limit of the */
//#define DO_TRANSLEVELCHECK           1
//#define VALIDATE_BUFFER              VALIDATE_FIXED_BUFFER /* or VALIDATE_NO_BUFFER or VALIDATE_BCD_BUFFER or VALIDATE_ANY_BUFFER */
//#define VALIDATE_DATA                VALIDATE_BCD_DATA /* or VALIDATE_NO_DATA or VALIDATE_DATETIME_DATA */
//#define DO_VALIDATEFIELDDEPENDENCIES 1
//#define DO_VALIDATEKEYS              1
//#define DO_VIEWHANDLE                1
//#define DO_XXXFETCHFILTER            1
//#define DO_XXXREAD                   1

// The following defines let you selectively override a view routine.
// The original semantics are available by calling scProBaseYYYY()
//#define DO_scProAttribs             1
//#define DO_scProBlkGet              1
//#define DO_scProBlkPut              1
//#define DO_scProBrowse              1
//#define DO_scProCancel              1
#define DO_scProClose               1
//#define DO_scProCmpNames            1
//#define DO_scProCompose             1
//#define DO_scProCreate              1
//#define DO_scProDelete              1
//#define DO_scProDirty               1
//#define DO_scProDrop                1
//#define DO_scProExists              1
//#define DO_scProFetch               1
//#define DO_scProFetchLock           1
//#define DO_scProField               1
//#define DO_scProFieldExists         1
//#define DO_scProFieldName           1
//#define DO_scProFields              1
//#define DO_scProFilterDelete        1
//#define DO_scProFilterFetch         1
//#define DO_scProFilterSelect        1
//#define DO_scProGet                 1
//#define DO_scProInit                1
//#define DO_scProInsert              1
//#define DO_scProInstanceFieldList   1
//#define DO_scProInstanceNotify      1
//#define DO_scProInstanceOpen        1
//#define DO_scProInstanceProtocol    1
//#define DO_scProInstanceSecurity    1
//#define DO_scProKey                 1
//#define DO_scProKeys                1
//#define DO_scProName                1
//#define DO_scProOpen                1
//#define DO_scProOrder               1
//#define DO_scProPost                1
//#define DO_scProPresents            1
//#define DO_scProProcess             1
//#define DO_scProPut                 1
//#define DO_scProRead                1
//#define DO_scProReadLock            1
//#define DO_scProRecordClear         1
//#define DO_scProRecordGenerate      1
//#define DO_scProRevisionCancel      1
//#define DO_scProRevisionExists      1
//#define DO_scProRevisionPost        1
//#define DO_scProRevisionRekey       1
//#define DO_scProRevisionUnposted    1
//#define DO_scProSecurity            1
//#define DO_scProTableEmpty          1
//#define DO_scProType                1
//#define DO_scProUnLock              1
//#define DO_scProUpdate              1
//#define DO_scProVerify              1

// The following let you redefine the semantics of the inline helper functions.
// Normally they default to calling InlineXXXX(), but you can redefine them to
// whatever is appropriate. Each DoXXXX() is called in turn by XXXX()
//#define DoFindCmp(_v_,_c_)              InlineFindCmp((_v_),(_c_))
//#define DoFindCmpDef(_c_)               InlineFindCmpDef((_c_))
//#define DoFindCmpField(_v_,_c_,_f_)     InlineFindCmpField((_v_),(_c_),(_f_))
//#define DoFindCmpForeign(_v_,_f_)       InlineFindCmpForeign((_v_),(_f_))
//#define DoFindCmpKey(_v_,_c_)           InlineFindCmpKey((_v_),(_c_))
//#define DoFindCmpName(_c_)              InlineFindCmpName((_c_))
//#define DoFindCmpNotify(_v_,_c_)        InlineFindCmpNotify((_v_),(_c_))
//#define DoFindDetailMap()               InlineFindDetailMap()
//#define DoFindFieldIndexV(_v_,_f_)      InlineFindFieldIndex((_f_))
//#define DoFindFieldMapV(_v_,_f_)        InlineFindFieldMap((_f_))
//#define DoFindFieldValue(_v_,_f_)       InlineFindFieldValue((_v_),(_f_))
//#define DoFindGenStub(_v_,_c_)          InlineFindGenStub((_v_),(_c_))
//#define DoFindImpOpen(_v_,_c_)          InlineFindImpOpen((_v_),(_c_))
//#define DoFindImpRead(_v_,_c_)          InlineFindImpRead((_v_),(_c_))
//#define DoFindKeyDef(_k_)               InlineFindKeyDef((_k_))
//#define DoFindPermissionMap()           InlineFindPermissionMap()
//#define DoFindRecord(_v_)               InlineFindRecord((_v_))
//#define DoFindRecordNotify(_v_)         InlineFindRecordNotify((_v_))
//#define DoFindRecordRead(_v_)           InlineFindRecordRead((_v_))
//#define DoFindRecordTemp(_v_)           InlineFindRecordTemp((_v_))
//#define DoFindRevCache(_v_)             InlineFindRevCache((_v_))
//#define DoFindRevLevel(_v_,_l_)         InlineFindRevLevel((_v_),(_l_))
//#define DoFindRevRekey(_v_,_l_)         InlineFindRevRekey((_v_),(_l_))
//#define DoFindTableHandle(_v_)          InlineFindTableHandle((_v_))
//#define DoFindTableInfo(_v_,_t_)        InlineFindTableInfo((_v_),(_t_))
//#define DoFindTableMap(_t_)             InlineFindTableMap((_t_))
//#define DoFindTableMapV(_v_,_t_)        InlineFindTableMap((_t_))
//#define DoFindTableRev(_v_)             InlineFindTableRev((_v_))
//#define DoFindTableSelection(_v_,_t_)   InlineFindTableSelection((_v_),(_t_))
//#define DoFindTableWidth(_v_,_t_)       InlineFindTableWidth((_v_),(_t_))
//#define DoMapStubToTableHandle(_v_,_h_) InlineMapStubToTableHandle((_v_),(_h_))
//#define DoMapToInternalComposite(_c_)   InlineMapToInternalComposite((_c_))
//#define DoMapToNewFieldIndex(_f_)       InlineMapToNewFieldIndex((_f_))
//#define DoMaxDatabaseError(_p_,_x_)     { ERRNUM _d_ = (_x_); InlineMaxDatabaseError ((_p_),_d_); }
//#define DoMaxError(_p_,_x_)             { ERRNUM _e_ = (_x_); InlineMaxError ((_p_),_e_); }
//#define DoValidIndexV(_v_,_f_)          InlineValidIndexV((_v_),(_f_))

//#define DO_fileAdd             1
//#define DO_fileBegin           1
//#define DO_fileCancel          1
//#define DO_fileClose           1
//#define DO_fileCommit          1
//#define DO_fileCreate          1
//#define DO_fileDelete          1
//#define DO_fileDirty           1
//#define DO_fileDriverInfo      1
//#define DO_fileDrop            1
//#define DO_fileEmpty           1
//#define DO_fileError           1
//#define DO_fileFilterCount     1
//#define DO_fileFilterDelete    1
//#define DO_fileFilterSegs      1
//#define DO_fileFirst           1
//#define DO_fileGet             1
//#define DO_fileInfo            1
//#define DO_fileInsert          1
//#define DO_fileIsLocked        1
//#define DO_fileLinkFlags       1
//#define DO_fileLocate          1
//#define DO_fileLock            1
//#define DO_fileNext            1
//#define DO_fileOpen            1
//#define DO_fileOptLock         1
//#define DO_filePrePost         1
//#define DO_filePost            1
//#define DO_fileReverses        1
//#define DO_fileRollback        1
//#define DO_fileSelectFields    1
//#define DO_fileTransBegin      1
//#define DO_fileTransCommit     1
//#define DO_fileTransRollback   1
//#define DO_fileUnLock          1
//#define DO_fileUpdate          1

// ---



//////////////////////////////////////////////////////////////////////////
// Database table field number definitions, record layouts, etc.

// +++

// Field numbers; define as required. Note that audit fields don't need
// to be included, unless they are to be published from the view.
#include "SCPRON.GEN"
//#include "SCPRO2N.GEN"

// Field offsets; define as required. Note that audit fields need to
// be included.
#include "SCPROO.GEN"
//#include "SCPRO2O.GEN"



#if BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT>0

// The database record layout. This must be defined to precisely match
// The sequence and size of fields defined above.
typedef struct tagRECORD {
#include "SCPROR.GEN"
} RECORD, FAR * LPRECORD;

//typedef struct tagRECORD2 {
//#include "SCPRO2R.GEN"
//} RECORD2, FAR * LPRECORD2;

#endif

// ---



/////////////////////////////////////////////////////////////////////////////
// Miscellaneous structures

// +++

#ifdef DO_VIEWHANDLE
// Additional programmer-defined fields to be incorporated into the
// view handle. Though the space for it is allocated automatically,
// it must be maintained carefully; at present the most consistent
// hooks to use for this purpose are the view routine overrides.
typedef struct tagVEXTRA {
   INT ExtraInt;
} VEXTRA;
#endif

#ifdef DO_ENTRYSTATEEXTRA
// Additional programmer-defined fields to be incorporated into the
// entry state. You should maintain it via the EntryStatePush()
// and EntryStatePop() overrides.
typedef struct tagENTRYSTATEEXTRA {
   INT ExtraInt;
} ENTRYSTATEEXTRA, FAR * LPENTRYSTATEEXTRA;
#endif

// ---


#ifdef __cplusplus
}
#endif


#endif
