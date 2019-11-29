/*--------------------------------------------------------------------

    File        :   scLoan2.h
    Purpose     :   Constants and data structures that do not require
                    any changes (once instantiated by MKINST.EXE)

    Copyright (c) 1993-2014 Sage Software, Inc.  All rights reserved.

--------------------------------------------------------------------*/


#include <stdarg.h>


#if !defined(__scLoan2_h)
// Ensures header is only included once.
#define __scLoan2_h        1



#if defined(__cplusplus)
extern "C" {
#endif



// The following can change with new releases of the template
#define TEMPLATE_VERSION         0x63A
#define TEMPLATE_DATE            20140815



/////////////////////////////////////////////////////////////////////////////
// Macros for conditional features

// Constants for SUBCLASS_VIEW
#define NOT_SUBCLASS             -1
#define OVERRIDE_SUBCLASS        0
#define ALTER_SUBCLASS           1
#define JOIN_SUBCLASS            2

// Constants for HAS_REVISIONS
#define NO_REVISIONS             0
#define SEQUENCE_REVISIONS       1
#define ORDER_REVISIONS          2

// Constants for VALIDATE_DATA
#define VALIDATE_NO_DATA         0
#define VALIDATE_BCD_DATA        1
#define VALIDATE_DATETIME_DATA   2

// Constants for DO_EXTENDEDERRORS
#define NO_EXTENDEDERRORS        0
#define PROCESS_EXTENDEDERRORS   1
#define RETURN_EXTENDEDERRORS    2
#define UNIVERSAL_EXTENDEDERRORS 3

// Constants for VALIDATE_BUFFER
#define VALIDATE_NO_BUFFER       0
#define VALIDATE_FIXED_BUFFER    1
#define VALIDATE_BCD_BUFFER      2
#define VALIDATE_ANY_BUFFER      3

// Choices for VIEWDEBUG; defining it to anything OTHER than these choices
// activates simply basic debugging diagnostics
#define VIEWDEBUG_ALL            0xbeef
#define VIEWDEBUG_NESTED_DETAILS 0xfeed
#define VIEWDEBUG_ASSERT_DIES    0xdead

// Choices for DO_CASCADEPOST
#define CASCADEPOST_DEFAULT      0
#define CASCADEPOST_FIRST        1
#define CASCADEPOST_AFTERHEADER  2



/////////////////////////////////////////////////////////////////////////////
// Macros for helper functions

#define HEADER_COMPOSITE            0
#define DETAIL_COMPOSITE            1
#define HIERARCHICAL_COMPOSITE      2
#define DEMAND_COMPOSITE            3
#define IMPLICIT_COMPOSITE          4
#define MANUAL_COMPOSITE            5

// CONSTANTS FOR InitBodyGen()
// Behaviour on how to call GenerateKey
#define  MASK_INITBODYGEN_GENERATE  0x0003
#define  INITBODYGEN_NOGENERATE     0x0000
#define  INITBODYGEN_AUTOGENERATE   0x0001
#define  INITBODYGEN_FORCEGENERATE  0x0002
#define  INITBODYGEN_DELAYGENERATE  0x0003
// Behaviour on how to insert a generated key
#define  MASK_INITBODYGEN_INSERT    0x000C
#define  INITBODYGEN_AUTOINSERT     0x0000
#define  INITBODYGEN_FORCEINSERT    0x0004
#define  INITBODYGEN_NOINSERT       0x0008
// Behaviour on open
#define  MASK_INITBODYGEN_OPEN      0x0030
#define  INITBODYGEN_NOTOPEN        0x0000
#define  INITBODYGEN_OLDOPEN        0x0010
#define  INITBODYGEN_OPENETC        0x0020

// CONSTANTS FOR xxxFetchFilter()
// Record locking
#define  MASK_FETCHFILTER_LOCKED    0x0001
#define  FETCHFILTER_UNLOCKED       0x0000
#define  FETCHFILTER_LOCKED         0x0001
// Filter selection origin
#define  MASK_FETCHFILTER_FROM      0x0002
#define  FETCHFILTER_FROMHERE       0x0000
#define  FETCHFILTER_FROMSTART      0x0002
// Filter selection origin
#define  MASK_FETCHFILTER_NEXT      0x0004
#define  FETCHFILTER_NEXTMAYBE      0x0000
#define  FETCHFILTER_NEXTREALLY     0x0004

// CONSTANTS FOR RevisionMove
#define  REVMOVE_CANCEL_TARGET      0x0001
#define  REVMOVE_CLEAR_SOURCE       0x0002

// CONSTANTS FOR GenerateKey()
#define  GENERATEKEY_NONE           0x0000
#define  GENERATEKEY_RECORD         0x0001
#define  GENERATEKEY_KEY            0x0002

// CONSTANTS for SelectionIncrease()
#define  SELECTION_PRIMARY_KEY      0x0001
#define  SELECTION_SUBCLASS_FIELDS  0x0002
#define  SELECTION_AUDIT_STAMP      0x0004

// Enumeration for NotifyQueueField() and V.QueuedNotifyField[]
#define  NOTIFY_QUEUE_FIELD_ATTRIBUTES      0x0001
#define  NOTIFY_QUEUE_FIELD_PRESENTATION    0x0002

// Enumeration for V.EntryPath
#define  ENTRY_PATH_INACTIVE        0
#define  ENTRY_PATH_ROTO            1
#define  ENTRY_PATH_NOTIFY          2



/////////////////////////////////////////////////////////////////////////////
// Make default definitions for macros not defined by the user but
// otherwise needed.

// Miscellaneous composite counts
#define EXP_CMP_COUNT    (HDR_CMP_COUNT+DTL_CMP_COUNT+HCHY_CMP_COUNT+DMND_CMP_COUNT)
#define CMP_COUNT        (HDR_CMP_COUNT+DTL_CMP_COUNT+HCHY_CMP_COUNT+DMND_CMP_COUNT+IMP_CMP_COUNT)

// Allow SUB_VIEW and SUBCLASS_VIEW to be used interchangeably
#if defined(SUB_VIEW) && !defined(SUBCLASS_VIEW)
 #define SUBCLASS_VIEW SUB_VIEW
#elif !defined(SUB_VIEW) && defined(SUBCLASS_VIEW)
 #define SUB_VIEW SUBCLASS_VIEW
#endif

#if !defined(SUBCLASS_VIEW)
 // If no subclassing in effect, define SUBCLASS_LEVEL to reflect it
 #define SUBCLASS_LEVEL NOT_SUBCLASS
#else
 // else define SUBCLASS_LEVEL to be SUBCLASS_VIEW
 #define SUBCLASS_LEVEL SUBCLASS_VIEW
#endif

// Define VIEWDEBUG if ACCPAC_DEBUG is defined
#if defined (ACCPAC_DEBUG) && !defined(VIEWDEBUG)
 #define VIEWDEBUG               1
#endif

#if !defined (TEMPLATE_WARNING_LEVEL)
 #define TEMPLATE_WARNING_LEVEL  1
#endif

#if defined(SUPER_VIEW) && !defined(DO_PROCESSETC)
 #if TEMPLATE_WARNING_LEVEL<1
  #if defined LINUX_VER
   #warning ("If you implement ProcessEtc() make sure to define DO_PROCESSETC.")
  #else
   #pragma message ("If you implement ProcessEtc() make sure to define DO_PROCESSETC.")
  #endif
 #endif
 #define DO_PROCESSETC 1
#endif

#if TEMPLATE_WARNING_LEVEL<=0 && !defined(SCLOAN_ROTOID)
 #if defined LINUX_VER
  #warning ("The template disables some features when SCLOAN_ROTOID has been removed")
  #warning ("from scLoan.h. Please define it to activate these features")
 #else
  #pragma message ("The template disables some features when SCLOAN_ROTOID has been removed")
  #pragma message ("from scLoan.h. Please define it to activate these features")
 #endif
#endif

#if TEMPLATE_WARNING_LEVEL<=1 && !defined(DO_XXXFETCHFILTER) && (defined(DO_scLoanFetch) || defined(DO_scLoanFetchLock) || defined(DO_scLoanFilterFetch))
 #if defined LINUX_VER
  #warning ("Consider overriding xxxFetchFilter if you have previously overridden any of")
  #warning ("scLoanFetch, scLoanFetchLock or scLoanFilterFetch")
 #else
  #pragma message ("Consider overriding xxxFetchFilter if you have previously overridden any of")
  #pragma message ("scLoanFetch, scLoanFetchLock or scLoanFilterFetch")
 #endif
#endif

#if TEMPLATE_WARNING_LEVEL<=1 && !defined(DO_XXXREAD) && (defined(DO_scLoanRead) || defined(DO_scLoanReadLock))
 #if defined LINUX_VER
  #warning ("Consider overriding xxxRead if you have previously overridden any of")
  #warning ("scLoanRead or scLoanReadLock")
 #else
  #pragma message ("Consider overriding xxxRead if you have previously overridden any of")
  #pragma message ("scLoanRead or scLoanReadLock")
 #endif
#endif

#if TEMPLATE_WARNING_LEVEL<=1 && !defined(DO_INITBODYGEN) && (defined(DO_scLoanInit) || defined(DO_scLoanRecordClear) || defined(DO_scLoanRecordGenerate))
 #if defined LINUX_VER
  #warning ("Consider overriding InitBodyGen if you have previously overridden any of")
  #warning ("scLoanInit, scLoanRecordClear or scLoanRecordGenerate")
 #else
  #pragma message ("Consider overriding InitBodyGen if you have previously overridden any of")
  #pragma message ("scLoanInit, scLoanRecordClear or scLoanRecordGenerate")
 #endif
#endif

#if TEMPLATE_WARNING_LEVEL<=1 && (!defined(DO_DELETEBODY) && !defined(DO_DELETEDETAILSBODY)) && (defined(DO_scLoanDelete) || defined(DO_scLoanFilterDelete))
 #if defined LINUX_VER
  #warning ("Consider overriding either DeleteBody or DeleteDetailsBody if you have previously")
  #warning ("overridden any of scLoanDelete or scLoanFilterDelete")
 #else
  #pragma message ("Consider overriding either DeleteBody or DeleteDetailsBody if you have previously")
  #pragma message ("overridden any of scLoanDelete or scLoanFilterDelete")
 #endif
#endif

#if TEMPLATE_WARNING_LEVEL<=0 && ((defined(DO_scLoanSecurity) && !defined(DO_scLoanInstanceSecurity)) || (!defined(DO_scLoanSecurity) && defined(DO_scLoanInstanceSecurity)))
 #if defined LINUX_VER
  #warning ("If either of scLoanSecurity or scLoanInstanceSecurity is overridden")
  #warning ("you should override the other")
 #else
  #pragma message ("If either of scLoanSecurity or scLoanInstanceSecurity is overridden")
  #pragma message ("you should override the other")
 #endif
#endif



#define VIEW_OP(_v_,_op_) ((_v_)->RotoView ? (_v_)->RotoView->op : VIEW_OP_ ## _op_)

#if !defined(ERRNUM_MACROS_DEFINED)
 #define ERRNUM_MACROS_DEFINED
 #define ERRNUM_IS_FAILURE(__E__)      ((__E__)>ERRNUM_SUCCESS && (__E__)!=OLD_ERRNUM_WARNING)
 #define ERRNUM_IS_FAULTLESS(__E__)    ((__E__)==ERRNUM_SUCCESS)
 #define ERRNUM_IS_WARNING(__E__)      ((__E__)<ERRNUM_SUCCESS || (__E__)==OLD_ERRNUM_WARNING)
 #define ERRNUM_IS_SUCCESS(__E__)      (ERRNUM_IS_FAULTLESS (__E__) || ERRNUM_IS_WARNING (__E__))
#endif

#define  DB_ERRNUM_IS_FAILURE(__E__)   ((__E__)!=DBS_SUCCESS && !DB_ERRNUM_IS_WARNING (__E__))
#define  DB_ERRNUM_IS_FAULTLESS(__E__) ((__E__)==DBS_SUCCESS)
#define  DB_ERRNUM_IS_SUCCESS(__E__)   (DB_ERRNUM_IS_FAULTLESS (__E__) || DB_ERRNUM_IS_WARNING (__E__))
#define  DB_ERRNUM_IS_WARNING(__E__)   ((__E__)==DBS_CVIEW_WARNING)

#define  FL_ERRNUM_IS_FAULTLESS(__E__) ((__E__)==FL_SUCCESS)
#define  FL_ERRNUM_IS_FAILURE(__E__)   ((__E__)!=FL_SUCCESS && !FL_ERRNUM_IS_WARNING (__E__))
#define  FL_ERRNUM_IS_SUCCESS(__E__)   (FL_ERRNUM_IS_FAULTLESS (__E__) || FL_ERRNUM_IS_WARNING (__E__))
#define  FL_ERRNUM_IS_WARNING(__E__)   ((__E__)==FL_CVIEW_WARNING)

#if !defined(APPL)
 #define APPL "SC"
#endif

#if !defined (MAN_CMP_COUNT)
 #define MAN_CMP_COUNT 0
#endif

#if !defined(TABLEHANDLE)
 #define TABLEHANDLE WORD
#endif

#if !defined(REV_SEQ_SKIP)
 #define REV_SEQ_SKIP 1000L
#endif

#if !defined(VIEWBASE)
 #define VIEWBASE  ERRNUM WINAPI
#endif

#if !defined(VIEWCALL)
 #define VIEWCALL  ERRNUM WINAPI
#endif

#if !defined(DO_SCRATCHSTACK)
 #define DO_SCRATCHSTACK 0
#endif

#if !defined(MAKEIDX)
 #if !defined(FLD_IDX_PFX)
  #define MAKEIDX(o) (o)
 #else
  #define MAKEIDX(o) MAKELONG(o,FLD_IDX_PFX)
 #endif
#endif

#if !defined (BASE_TBL_COUNT)
 #define BASE_TBL_COUNT 0
#endif

#if !defined (VALIDATE_DATA)
 #define VALIDATE_DATA VALIDATE_BCD_DATA
#endif

#if !defined (VALIDATE_BUFFER)
 #define VALIDATE_BUFFER VALIDATE_FIXED_BUFFER
#endif

#if !defined (DO_EXTENDEDERRORS)
 #define DO_EXTENDEDERRORS NO_EXTENDEDERRORS
#endif

#if SUBCLASS_LEVEL==JOIN_SUBCLASS
 #define JOIN_KEY_COUNT 1
#else
 #define JOIN_KEY_COUNT 0
#endif

#if defined(DO_HELPERSOUTOFLINE)
 #undef DO_INLINEHELPERS
#elif defined(DO_INLINEHELPERS)
 #undef DO_HELPERSOUTOFLINE
#else
 #define DO_INLINEHELPERS 1
#endif

#if !defined(FLD_IDX_PFX)
 #define IDXIDX(idx)        (idx)
 #define IDX_IN_DOMAIN(idx) ((idx)>0 && (idx)<FLD_IDX_LIMIT)
#else
 #define IDXIDX(idx)        LOWORD(0x0000ffffL & (idx))
 #define IDX_IN_DOMAIN(idx) (HIWORD((idx))==FLD_IDX_PFX && \
                             IDXIDX((idx))>0 && IDXIDX((idx))<IDXIDX(FLD_IDX_LIMIT))
#endif

#if !defined(VIEWDEBUG)
 #define VIEWASSERT(expr)  ((void)0)
 #define RVSPYTRACE(s)     ((void)0)
 #define RVSPYPRINT(plist) ((void)0)
 #define RVSPYINDENT(I_I)  (0)
 #define RVSPYNOTIFY(V_V,S_S,R_R,I_I,E_E,C_C) ((void)0)
#else
 #define VIEWASSERT(expr)  ((expr) ? (void)0 : ReportAssertion (__FILE__, __LINE__, #expr))
 #define RVSPYTRACE(s)     ReportString ((s))
 #define RVSPYPRINT(plist) rvspyPrint plist
 #define RVSPYINDENT(I_I)  rvspyIndentation ((I_I))
 #define RVSPYNOTIFY(V_V,S_S,R_R,I_I,E_E,C_C) \
    rvspyNotify ((V_V),(S_S),(R_R),(I_I),(E_E),(C_C))
 #if VIEWDEBUG==VIEWDEBUG_ALL
  #define DO_HELPERSOUTOFLINE
 #endif
#endif

#if !defined(DO_FETCHCOUNT)
 #define DO_FETCHCOUNT 8
#endif

#if !defined(A4W_API_VERSION)
 #define A4W_API_VERSION 0x56A
#endif

#if !defined(HDR_HAS_REVISIONS)
 #define HDR_HAS_REVISIONS 0
#endif

#if !defined(DO_TRANSACTIONSTACK)
 #define DO_TRANSACTIONSTACK    10
#endif

#if !defined(DO_CASCADEPOST) && defined(DO_CASCADEPOSTFIRST)
 #define DO_CASCADEPOST DO_CASCADEPOSTFIRST
#elif defined(DO_CASCADEPOST) && !defined(DO_CASCADEPOSTFIRST)
 #define DO_CASCADEPOSTFIRST DO_CASCADEPOST
#else
 #define DO_CASCADEPOST CASCADEPOST_DEFAULT
#endif

#if DTL_CMP_COUNT>0 && (!defined(BATCH_VIEW) || defined(HEADER_VIEW) || defined(DETAIL_VIEW))
 #define DETAILS_ARE_REVISIONED  1
#else
 #define DETAILS_ARE_REVISIONED  0
#endif

#if TBL_COUNT>0 && SUBCLASS_LEVEL==NOT_SUBCLASS && (!defined(STUB_VIEW) || !defined(DoMapStubToTableHandle))
 #define HAS_DATABASE_TABLES    1
#else
 #define HAS_DATABASE_TABLES    0
#endif

// REVIEW: This is supposed to be temporary, until such time as there is a
// 6.0 SDK available that has the modified view.h.
#if !defined(ETAG_IDX)
 #define ETAG_IDX           999999992L
 #define SIZEOF_ETAG        30
#endif

// REVIEW: These are supposed to remain internal
#define SIZEOF_ETAG_DATE 8
#define SIZEOF_ETAG_TIME 8



//////////////////////////////////////////////////////////////////////////////
// Force the following features to always be on/off.
// These used to be optional, now are required.

#if !defined(DO_INITBYFIELD)
 #define DO_INITBYFIELD
#endif

#if !defined(DO_STANDARDERRORS)
 #define DO_STANDARDERRORS
#endif

#if !defined(DO_CALLOUTERRORS)
 #define DO_CALLOUTERRORS
#endif

#if !defined(DO_REALSUPPORT)
 #define DO_REALSUPPORT
#endif

#if !defined(DO_PASSIVECONCURRENCY)
 #define DO_PASSIVECONCURRENCY
#endif

#if defined(DO_OLDMAPTODETAILS)
 #undef DO_OLDMAPTODETAILS
 #if defined LINUX_VER
  #warning ("Warning: DO_OLDMAPTODETAILS is no longer supported, and will be ignored.")
 #else
  #pragma message ("Warning: DO_OLDMAPTODETAILS is no longer supported, and will be ignored.")
 #endif
#endif

#if defined(DO_NOREADOPTIMIZING)
 #undef DO_NOREADOPTIMIZING
 #if defined LINUX_VER
  #warning ("Warning: DO_NOREADOPTIMIZING is no longer supported, and will be ignored.")
 #else
  #pragma message ("Warning: DO_NOREADOPTIMIZING is no longer supported, and will be ignored.")
 #endif
#endif

#if defined(DO_NOREVISIONOPTIMIZING)
 #undef DO_NOREVISIONOPTIMIZING
 #if defined LINUX_VER
  #warning ("Warning: DO_NOREVISIONOPTIMIZING is no longer supported, and will be ignored.")
 #else
  #pragma message ("Warning: DO_NOREVISIONOPTIMIZING is no longer supported, and will be ignored.")
 #endif
#endif

#if defined(DO_SELECTFETCH)
 #undef DO_SELECTFETCH
 #if defined LINUX_VER
  #warning ("Warning: DO_SELECTFETCH is no longer supported, and will be ignored.")
 #else
  #pragma message ("Warning: DO_SELECTFETCH is no longer supported, and will be ignored.")
 #endif
#endif

#if defined(DO_OLDPERMISSION)
 #undef DO_OLDPERMISSION
 #if defined LINUX_VER
  #warning ("Warning: DO_OLDPERMISSION is no longer supported, and will be ignored.")
 #else
  #pragma message ("Warning: DO_OLDPERMISSION is no longer supported, and will be ignored.")
 #endif
#endif

#if defined(DO_OLDPOST)
 #error DO_OLDPOST is no longer supported for non-revisioned views, and results in scLoanBasePost doing nothing. You need to remove it, plus change any callers that depended on this behaviour.
#endif

#if defined(DO_SCRATCHHEAP)
 #error DO_SCRATCHHEAP is no longer supported. Use memAlloc/memFree instead.
#endif

#if defined(DO_GETPERMISSIONS)
 #error DO_GETPERMISSIONS is no longer supported. You must override scLoanInstanceSecurity instead.
#endif



///////////////////////////////////////////////////////////////////////////
// The following provide simple error checking by view protocol

#if !defined(DO_STANDARDERRORS)
 #error DO_STANDARDERRORS must be defined, in order use the template error messages
#endif

#if !(defined(HEADER_VIEW) || defined(DETAIL_VIEW) || defined(FLAT_VIEW) || defined(BATCH_VIEW) || defined(SUPER_VIEW))
 #error View protocol not explicitly selected
#endif

#if A4W_API_VERSION<0x56A
 #error This version of the template requires at least version 5.6A of the API
#endif

#if TBL_COUNT==0 && defined(DO_CLEARAUDIT)
 #error Must have physical tables for the clear audit stamp feature
#endif



#if defined(SUPER_VIEW)

 #if defined(BATCH_VIEW)
  #error Batch view/behaviour must be exclusive of Super view protocol
 #elif defined(HEADER_VIEW) || defined(DETAIL_VIEW) || defined(FLAT_VIEW)
  #error Super view must be exclusive of all other view protocols
 #elif BASE_TBL_COUNT+TBL_COUNT>0
  #error Super view cannot define any database tables
 #elif KEY_COUNT-FAKE_KEY_COUNT>0
  #error Super view cannot define any database keys
 #elif defined(DO_CONCURRENCYETC)
  #error Super view cannot make use of ConcurrencyEtc()
 #elif HAS_REVISIONS
  #error Super view cannot have revisions
 #elif HDR_CMP_COUNT>0 || DTL_CMP_COUNT>0
  #error Super view cannot have header or detail compositions
 #endif

#elif defined(HEADER_VIEW)

 #if defined(SUPER_VIEW) || defined(FLAT_VIEW) || defined(DETAIL_VIEW)
  #error Header view must be exclusive of Super, Detail and Flat view protocols
 #elif SUBCLASS_LEVEL==NOT_SUBCLASS && DTL_CMP_COUNT==0 && HDR_CMP_COUNT==0
  #error Header view must have detail compositions
 #elif SUBCLASS_LEVEL==NOT_SUBCLASS && HDR_CMP_COUNT==0 && defined(BATCH_VIEW)
  #error Header view with Batch behaviour must have 1 header composition
 #elif HAS_REVISIONS
  #error Header view cannot have revisions
 #elif defined(DO_HEADERETC) && DO_HEADERETC<1
  #error DO_HEADERETC must be greater than 0
 #elif HDR_CMP_COUNT!=0 && DTL_SEG_COUNT==0
  #error Batch/Header view must define DTL_SEG_COUNT to be >= 1
 #endif

#elif defined(DETAIL_VIEW)

 #if defined(SUPER_VIEW) || defined(FLAT_VIEW) || defined(HEADER_VIEW)
  #error Detail view must be exclusive of Super, Header and Flat view protocols
 #elif SUBCLASS_LEVEL==NOT_SUBCLASS && HDR_CMP_COUNT<1
  #error Detail view must have 1 header composition
 #elif defined(DO_HEADERETC) && DO_HEADERETC<1
  #error DO_HEADERETC must be greater than 0
 #elif DTL_SEG_COUNT==0 && (SUBCLASS_LEVEL==NOT_SUBCLASS || SUBCLASS_LEVEL==JOIN_SUBCLASS)
  #error Detail view must define DTL_SEG_COUNT to be >= 1
 #elif defined(DO_CONCURRENCYETC)
  #error Detail view cannot make use of ConcurrencyEtc()
 #endif

#elif defined(FLAT_VIEW)

 #if defined(SUPER_VIEW) || defined(HEADER_VIEW) || defined(DETAIL_VIEW)
  #error Flat view must be exclusive of Super, Header and Detail view protocols
 #elif HDR_CMP_COUNT>0 || DTL_CMP_COUNT>0
  #error Flat view cannot have header or detail compositions
 #elif defined(DO_CONCURRENCYETC) && HAS_REVISIONS
  #error Flat view cannot make use of ConcurrencyEtc() with revisions
 #endif

#elif defined(BATCH_VIEW)

 #if !defined(DO_GENERATEKEY) && defined(FLAT_VIEW)
  #error Flat view must define DO_GENERATEKEY when using Batch behaviour
 #elif SUBCLASS_LEVEL==NOT_SUBCLASS && DTL_CMP_COUNT==0 && !(defined(HEADER_VIEW) || defined(DETAIL_VIEW) || defined(FLAT_VIEW))
  #error Batch view must have detail compositions
 #elif HAS_REVISIONS && !(defined(HEADER_VIEW) || defined(DETAIL_VIEW) || defined(FLAT_VIEW))
  #error Batch view cannot have revisions
 #endif

#else

 #error View protocol must be explicitly selected

#endif



#if SUBCLASS_LEVEL==NOT_SUBCLASS

 #if BASE_TBL_COUNT>0
  #error Base table cannot be specified for non-subclass view
 #endif

#else

 #if SUBCLASS_LEVEL==ALTER_SUBCLASS

  #if HAS_REVISIONS
   #error Altered-Subclass view cannot specify revisions
  #elif BASE_TBL_COUNT!=1
   #error Altered-Subclass view must have exactly one base table
  #elif TBL_COUNT>0
   #error Altered-Subclass view cannot have physical tables
  #endif

 #elif SUBCLASS_LEVEL==JOIN_SUBCLASS

  #if TBL_COUNT<1
   #error Joined-Subclass view must have at least one physical table
  #elif !defined(DO_CREATEETC)
   #error CreateEtc() must be defined for a joined-style subclass
  #elif HAS_REVISIONS==SEQUENCE_REVISIONS
   #error Sequenced revision base views can be subclassed only with the altered-style
  #elif KEY_COUNT!=(SCLOAN_KEY_COUNT-JOIN_KEY_COUNT+FAKE_KEY_COUNT)
   #error KEY_COUNT must be defined as (SCLOAN_KEY_COUNT-JOIN_KEY_COUNT+FAKE_KEY_COUNT)
  #endif

 #elif SUBCLASS_LEVEL==OVERRIDE_SUBCLASS

  #if BASE_TBL_COUNT>0 || TBL_COUNT>0
   #error Override-Subclass view cannot have physical tables or a base table
  #endif

 #endif

 #if defined(SUB_VIEW) && SUB_VIEW!=SUBCLASS_VIEW
  #error If SUBCLASS_VIEW and SUB_VIEW are both defined they must be identical
 #endif

 #if !defined(FLD_IDX_PFX)
  #error You must define FLD_IDX_PFX for subclass views
 #endif

 #if defined(DO_GENERATEKEY)
  #error You cannot define DO_GENERATEKEY for subclass views
 #endif

#endif



#if HDR_HAS_REVISIONS

 #if !defined(DETAIL_VIEW)
  #error Nested details can only be defined with detail views
 #elif HAS_REVISIONS==NO_REVISIONS
  #error You cannot define HDR_HAS_REVISIONS unless the view uses revisions and has a header
 #endif

#endif



#if DO_CASCADEPOST==CASCADEPOST_FIRST

 #if HAS_REVISIONS!=ORDER_REVISIONS
  #error DO_CASCADEPOST==CASCADEPOST_FIRST can only be done with ordered revision lists
 #endif

#endif



#if defined(__cplusplus)

 #if defined(DO_VIEWHANDLE)
  #error Under C++ you must derive VEXTRA in scLoan3.h from VBASE
 #endif

#endif



// Superceded helper macro overrides

#if defined DoFindFieldIndex
 #error DoFindFieldIndex override has been superceded by DoFindFieldIndexV. Change your definition appropriately.
#endif

#if defined DoFindFieldMap
 #error DoFindFieldMap override has been superceded by DoFindFieldMapV. Change your definition appropriately.
#endif

#if defined DoValidIndex
 #error DoValidIndex override has been superceded by DoValidIndexV. Change your definition appropriately.
#endif

#if defined DoValidIndexBase
 #error DoValidIndexBase override has been superceded by DoValidIndexV. Change your definition appropriately.
#endif



// End of checking
////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////
// Structure and Type Definitions



// Various error code types
typedef WORD DB_ERRNUM;
typedef ERRNUM FL_ERRNUM;
typedef ERRNUM REV_ERRNUM;



// Generic field that is a union of possible types
typedef union tagDATUM {
   DBSBOOL f;       // boolean
   DBSINT i;        // integer
   DBSLONG l;       // long
   DBSREAL r;       // real
   DBSMONEY m;      // money
   DBSDATE d;       // date
   DBSTIME t;       // time
   DBSNUMBER n [1]; // number
   DBSBINARY b [1]; // binary
   DBSSTRING s [1]; // string
} DATUM, FAR * LPDATUM;

// Composite key information
typedef struct tagCMPKEY {
   SHORT segments; // # of segments in composite view
   LONG indexes [MAX_SEGMENTS_PER_KEY]; // composite view's field indexes of key
   TYPE types [MAX_SEGMENTS_PER_KEY]; // data types of above indexes
} CMPKEY, FAR * LPCMPKEY;

// Conflicted field structure
typedef struct tagIDXCONFLICT {
   LONG field;    // view field index
   BOOL conflict; // is value truly conflicted, or just maybe?
} IDXCONFLICT;

typedef LPVOID REVISION, FAR * LPREVISION;

typedef TABLEHANDLE FAR * LPTABLEHANDLE;



// Nested detail support

#define  REVNODE_REKEY_SOURCE    0x00000001
#define  REVNODE_REKEY_TARGET    0x00000002

typedef struct tagREVNODE {
   struct tagREVNODE FAR *pNext;
   LPVOID key;
   struct tagREVNODE FAR *revList; // tree of REVNODEs rooted under this one
   REVISION rev [HAS_REVISIONS!=NO_REVISIONS ? BASE_TBL_COUNT+TBL_COUNT : 1];
   A4W_FLAGS flags;
   REVISION rekey [HAS_REVISIONS!=NO_REVISIONS ? BASE_TBL_COUNT+TBL_COUNT : 1];
} REVNODE, FAR * LPREVNODE;

typedef struct tagREVLEVEL {
   INT iHdrPKeySize; // Size of the Header's primary key
   INT HeaderKeySegments; // # of segments header's key has
   INT DetailKeySegments; // # of segments detail adds to this header
   LPREVNODE revList; // list of revision lists
   BOOL dirty; // Has anything been InnerPosted to this level?
   LPREVNODE AttachedRevision; // Revision node currently attached (via Fetch/Read/Insert)
   LPREVNODE RekeyPending; // deep copy of .revList, which are waiting to be rekeyed
} REVLEVEL, FAR *LPREVLEVEL;

typedef struct {
   LPREVNODE *root;
   int level;
   LPREVNODE found;
   LPVOID key;
} REVGRAFTPOINT, *PREVGRAFTPOINT;



#if !defined(__cplusplus)
 struct tagV;
 #define VIEW_HANDLE_STRUCT tagV
#else
 struct VEXTRA;
 #define VIEW_HANDLE_STRUCT VEXTRA
#endif

// Composite notification contexts
typedef struct tagCMPNOTIFYCONTEXT {
   struct VIEW_HANDLE_STRUCT *lpv;
   INT composite;
} CMPNOTIFYCONTEXT, * LPCMPNOTIFYCONTEXT;

// chain of registered notification callbacks
typedef struct tagNOTIFYCONTEXT {
   struct tagNOTIFYCONTEXT *next;
   A4W_NOTIFY_PROC notify;
   LPVOID context;
   A4W_FLAGS flags;
   struct VIEW_HANDLE_STRUCT *lpv;
} NOTIFYCONTEXT, * LPNOTIFYCONTEXT;

typedef struct tagTABLESELECTION {
   int count;
   char fields[MAX_FIELDS+1][SIZEOF_FIELDNAME];
} TABLESELECTION, *PTABLESELECTION;

typedef struct tagVIEWSELECTION {
   INT count;
   LONG fields [FLD_IDX_COUNT + 1];
   WORD flags;
   PTABLESELECTION subclassor;
   TABLESELECTION tables [BASE_TBL_COUNT + TBL_COUNT + (BASE_TBL_COUNT>0 ? 0 : 1)];
} VIEWSELECTION, *PVIEWSELECTION;



// View handle -- setup by a view upon being opened. The pointer to the
// memAlloc'ed buffer is returned for callers to use in view calls.
// Any information which must be kept per open instance of the view
// must be in this structure. It can be extended by defining the VEXTRA
// data structure.
struct tagV {
   HPIB hpib; // Caller's program information block
   WORD wLinkNo; // Database link number
   BOOL bVerifying; // inside scLoanVerify routine
   BOOL bBrowsing; // Current browse state; FALSE=>reestablish position
   BOOL bBrowseEnded; // TRUE=>reestablish position; usually = !bBrowsing
   BOOL bAhead; // Current browse direction
   BOOL bDescendSupported; // Reverse browsing supported?
   BOOL bFieldChanged; // Used only by Put
   FILTER filter; // Current filter structure
   SHORT nCurrentRange; // Filter working variable
   BOOL bDirty; // Fields have changed since record was last established
   BOOL bVerified; // Entire record has been successfully verified
   BOOL bExists; // Current record exists
   WORD wKey; // Current key as passed to scLoanOrder
   WORD wActualKey; // Key number as required by database API
   WORD wNoOfKeys; // Actual number of keys for primary table
   DBSINT sysAccess; // Current value of SYSACCESS phantom field
   DBSLONG refIntegrity; // Referential integrity options (phantom field)
   DBSBOOL bCheckDuplicates; // Current value of DUPKEYCHECK phantom field
   LONG alAttributes [IDXIDX(FLD_IDX_LIMIT)]; // View field attributes
   LONG attributesNotify [IDXIDX(FLD_IDX_LIMIT)]; // parallel to alAttributes
#if TBL_COUNT>0
   TABLEHANDLE ahTable [BASE_TBL_COUNT+TBL_COUNT]; // Opened database table handles
#endif
#if BASE_TBL_COUNT+TBL_COUNT>0
   DBTABLE aTableInfo [BASE_TBL_COUNT+TBL_COUNT]; // Array of database table info structs
#endif
#if BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT>0
   LPSTR record [BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT]; // Current database record(s)
   LPSTR recordTemp [BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT]; // transient copy of current record
 #if defined(DO_RECORDREAD) || defined(DO_CONCURRENCYETC)
   LPSTR recordRead [BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT]; // Copy of current record as read/init
 #endif
   LPSTR recordNotify [BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT]; // Copy of current record as at start of view call
 #if defined(DO_CONCURRENCYETC)
   IDXCONFLICT conflicts [FLD_IDX_COUNT]; // Fields in conflict
 #endif
#endif
   BOOL bUnpostedRevisions; // Used instead of revDirty when HDR_HAS_REVISIONS>0
   BOOL bConsuming; // Consuming revisions for post/cancel
   BOOL bConsumingRekeys; // Consuming just the rekey sources for post
   INT levelSwitched; //
   BOOL bAttachRequested; // Requests attaching (via switching) through REVLEVELs
#if HAS_REVISIONS
   REVISION rev [BASE_TBL_COUNT+TBL_COUNT]; // revision list handles; 1-to-1 with ahTable
   REVISION revCache [BASE_TBL_COUNT+TBL_COUNT]; // cached EMPTY revision list handles; used as template so that revCreateFromHandleErr() can be used
 #if HDR_HAS_REVISIONS
   REVLEVEL revLevel [HDR_HAS_REVISIONS]; // nested detail levels
   REVNODE **revConsumingRekeys[HDR_HAS_REVISIONS]; // Stack of track backs to remember where consuming left off
 #endif
#endif
#if CMP_COUNT+MAN_CMP_COUNT>0
 #if HCHY_CMP_COUNT+DMND_CMP_COUNT+IMP_CMP_COUNT>0
   BOOL cmpForeign [IDXIDX(FLD_IDX_LIMIT)]; // fields which are foreign keys
 #endif
 #if CMP_COUNT-HDR_CMP_COUNT>0
   LONG cmpFields [CMP_COUNT-HDR_CMP_COUNT] [IDXIDX(FLD_IDX_LIMIT)];
 #endif
   VIEWDEF cmp [CMP_COUNT+MAN_CMP_COUNT]; // Composed views' VIEWDEF's
   BOOL cmpGenStub [CMP_COUNT+MAN_CMP_COUNT]; // generic stub trap flags
   CMPKEY cmpKey [CMP_COUNT+MAN_CMP_COUNT]; // Composite key definitions
   CMPNOTIFYCONTEXT cmpNotifyContext [CMP_COUNT+MAN_CMP_COUNT]; // Composite notification contexts
 #if DMND_CMP_COUNT+IMP_CMP_COUNT+MAN_CMP_COUNT>0
   // State arrays for demand, implicit and manually maintained composites
   BOOL impOpen [CMP_COUNT+MAN_CMP_COUNT];
   INT impRead [CMP_COUNT+MAN_CMP_COUNT];
 #endif
#endif
#if defined(DO_HEADERETC)
   LPSTR detailSave; // Saved detail field values affecting header composite
#endif
   SHORT subFields; // number of fields in base view
   SHORT subKeys; // number of keys in base view
   VIEWDEF subCmp; // base view's handle
   CMPKEY subCmpKey; // Primary key definition of base view
   LPSTR subFilter; // current filter reduced to refer only to base view's fields
   CHAR subVersionTemplate [SIZEOF_VERSION]; // Version of base view's template
   LONG subDateTemplate; // Date of base view's template
   INT ScratchAllocated; // Bytes allocated on ScratchStack
   BYTE ScratchStack [DO_SCRATCHSTACK+1]; // Transient storage push-down, grows up
   LPROTOVIEW RotoView; // ROTOVIEW structure for current invocation (NULL when V not yet available).
   INT RotoLength; // Length of above structure
   DB_ERRNUM eRevision; // Database error within filePost, filePrePost, PrePostEtc
   ERRNUM eValidation; // View error within validation function
   LPSTR dbFilter; // current filter reduced to refer only to physical fields
   LPSTR rangeFilter; // Reconstituted ranges from filter and current record
   LPSTR fetchedRecords; // records retrieved via dbFetch
   WORD fetchedRecordCount; // number of records in V.fetchedRecords
   WORD currentFetchedRecord; // current record in V.fetchedRecords
   WORD transLevel; // Active transaction level
   INT transIDs; // Number of transaction IDs on the stack below
   DWORD transIDstack[DO_TRANSACTIONSTACK]; // Stack of transaction IDs; used with lnk*Trans() APIs
   LPRVH myself; // my own RVH, so I can tell others to call me
   BOOL bUnvalidated; // validating flag from viewInstanceOpen
   BOOL bRevisioned; // revisioning flag from viewInstanceOpen
   BOOL bReadOnly; // read-only flag from viewInstanceOpen
   BOOL bRawData; // raw-data flag from viewInstanceOpen
   BOOL bCascades; // cascading flag from viewInstanceOpen
   BOOL bInherits; // heritability flag from viewInstanceOpen
   WORD wFetchCount; // dbFetch count from viewInstanceOpen
   WORD wDriverID; // type of DB driver 0=Pervasive.SQL, 2=MS SQLServer, 3=IBM DB2, 4=Oracle
   WORD wPrimaryRecordLength; // actual length of primary table's record
   WORD wDetailFilterSegments; // number of segments whose values are pinned when composed to header
   INT filterExpressionCast; // composite or table to reference when reconstituting filter with tableName or detailName
   LPVOID OpenExtra; // copy of extra data received by scLoanInstanceOpen
   A4W_SIZE OpenExtraSize; // size of viewInstanceOpen's extra parameter
   A4W_FLAGS OpenFlags; // Original flagset passed to viewInstanceOpen
   LONG rotoID; // My own rotoID; needs SCLOAN_ROTOID to be defined to be meaningful
   BOOL bSelectFromStart; // viewFilterSelect option; reset upon fetch
   BOOL bBrowseInSync; // Are the DB logical position, current record values, and filter state in sync?
   LPNOTIFYCONTEXT NotifyList; // List of clients to notify
   LPNOTIFYCONTEXT *NextNotifyList; // address of pointer to next insertion point
   BOOL bKeyGenerated; // Record's current key value was generated
   CHAR OrgID [SIZEOF_ORGID]; // Cached result of lnkGetOrgID, the database the link references
   WORD wOrgType; // Cached result of lnkGetOrgType, indicating whether the database is company, combined or system
   BOOL bSecEnabled; // Cached result of lnkIsSecEnabled, facilitating GetPermissions()
   BYTE abKeyBefore [MAX_KEY_SIZE]; // key before insertion; currently only with SEQUENCE_REVISIONS
#if defined(DO_LOADCOMPANYINFO)
   COMPANYINFO CompanyInfo; // Cached result of cpGetCompanyInfo()
#endif
   SMSERIESINFO SeriesInfo; // Cached result of smGetSeriesInfo()
   PVIEWSELECTION pViewSelection; // Current subset of fields to which record operations are restricted.
   INT EntryPath; // This view instance has an active invocation on the call stack
   A4W_FLAGS QueuedNotifyField [IDXIDX(FLD_IDX_LIMIT)]; // Queued notifications that are to be fired upon entrypoint completion
   BOOL FieldsWereQueued; // Have any field notifications been queued up in V.QueuedNotifyField?
#if !defined(__cplusplus)
 #if defined(DO_VIEWHANDLE)
   VEXTRA extra; // Programmer-defined view handle extensions, defined in scLoan1.h
 #endif
#else // defined(__cplusplus)
   tagV();
#endif
};



// Field presentation definitions

// Types of internal presentation representations
#define  PRESENTS_NONE        ' '
#define  PRESENTS_LIST        'L'
#define  PRESENTS_LIST_INLINE 'I'
#define  PRESENTS_MASK        'M'

// Field presentation definition structure. An instance of this structure
// must be created and referenced for each field with presents info. Note that
// this is an internal structure, and is mapped by the template to the
// external representation.
typedef struct tagPRESENTATION {
   CHAR type;        // One of PRESENTS_* above
   INT elements;     // number of list entries (only if type=='L'|'I')
   INT size;         // size of buffer holding all strings (both type=='L'&'M')
   LPSTR mask;       // mask string (only if type=='M'); strings if 'I'
   LPSHORT listNums; // array of integers mapping to strings (int listNums[elements])
   LPRSCID listStrs; // array of resource IDs for strings (int listStrs[elements])
} PRESENTATIONINFO, FAR * LPPRESENTATION;

// Helper macros: use these to construct PRESENTATIONINFO variables. For all
// macros `id' is a variable token, and will have either "List" or "Mask"
// pasted on the end for the final variable name. Masks are constructed with
// DECLARE_MASK; in-line masks with DECLARE_IMASK. Lists are constructed with
// DECLARE_LIST_NUMS, DECLARE_LIST_STRS, and DECLARE_LIST; in-line lists with
// DECLARE_LIST_NUMS, DECLARE_ILIST_STRS, and DECLARE_ILIST.
#define  DECLARE_LIST_NUMS(id)   static SHORT NEAR id ## Nums[] =
#define  DECLARE_LIST_STRS(id)   static RSCID NEAR id ## Strs[] =
#define  DECLARE_ILIST_STRS(id)  static CHAR NEAR id ## Strs[] =
#define  DECLARE_LIST(id)        static PRESENTATIONINFO id ## List = {PRESENTS_LIST, sizeof (id ## Nums)/sizeof (id ## Nums[0]), 0, NULL, id ## Nums, id ## Strs}
#define  DECLARE_ILIST(id)       static PRESENTATIONINFO id ## List = {PRESENTS_LIST_INLINE, sizeof (id ## Nums)/sizeof (id ## Nums[0]), 0, id ## Strs, id ## Nums, NULL}
#define  DECLARE_MASK(id,mask)   static PRESENTATIONINFO id ## Mask = {PRESENTS_MASK, 1, 0, MAKERSC(mask)};
#define  DECLARE_IMASK(id,mask)  static PRESENTATIONINFO id ## Mask = {PRESENTS_MASK, 1, 0, mask};

// Presents list value not possible for SHORTs
#define  PRESENTS_LIST_NOTFOUND  0x77778888



// Handy pointer to validation function typedef
typedef BOOL (WINAPI * VALIDATION) (struct VIEW_HANDLE_STRUCT *, LONG, LPVOID);

// Special field handling feature flags. Used to set the flags field of IDXMAP
// Note that only FLD_VALIDATE is currently used. All others are reserved
// for future use.
#define FLD_VALIDATE       0x1L /* always validate */
#define FLD_UNBUFFERED     0x2L /* not stored in any record layout */
#define FLD_FOREIGN        0x4L /* defined and stored at cmpView & cmpField */



// View field index storage mapping. Defines a field's title, table,
// and database field index in that table, plus miscellaneous view
// representation and handling items.
typedef struct tagIDX {
   RSCID title;             // resource ID of title string
   INT tblNo;               // index in TBLMAP array; -1 if not used
   INT tblFieldNo;          // field number in DBFIELD array of table
   VALIDATION validate;     // field validation routine; NULL if none
   LPPRESENTATION presents; // presentation information; NULL if none
   LONG flags;              // Special features; set with FLD_* constants
   LONG attributes;         // default attributes; XOR mask
   INT cmpView;             // reserved: set to 0
   LONG cmpField;           // reserved: set to 0
} IDXMAP, FAR * LPIDXMAP;



// The following structure is used in an array of tables. It is indexed
// by (IDXMAP).tblNo, with the special values noted in IDXMAP.
typedef struct tagTBL {
   LPDBTABLE table;  // Database table definition
   LPDBFIELD fields; // Table data field definitions
   LPWORD keys;      // Table key definitions
} TBLMAP, FAR * LPTBLMAP;



// View key definition structure. Represents the segments of a key as
// a set of view field indexes (rather than database field numbers)
typedef struct tagKEY {
   RSCID name;                          // resource ID of key name string
   SHORT segments;                      // # of segments (up to 10)
   LONG indexes [MAX_SEGMENTS_PER_KEY]; // array of view field index key segments
   INT foreign;                         // corresponding foreign key # in composite view
   BOOL system;                         // TRUE means system link
   A4W_FLAGS flags;                     // flags to pass viewInstanceOpen()
} KEYMAP, FAR *LPKEYMAP;



#define  CMPNAME_OPTION_NOTIFY      0x00000001
#define  CMPNAME_OPTION_VIEWPOOL    0x00000002



struct tagCMPNAME {
   CHAR rotoID [SIZEOF_ROTOIDSTR + 1]; // Composite view roto ID, with NULL terminator
   A4W_FLAGS flags;                    // flags to pass viewInstanceOpen()
   INT foreign;                        // corresponding foreign key # in composite view
   BOOL system;                        // TRUE means system link
   A4W_FLAGS options;                  // template-control options
   BOOL bViewPool;                     // TRUE means opt in for viewpool (i.e. viewAcquire, viewRelease, viewSpecify)
};
typedef struct tagCMPNAME FAR * LPCMPNAME;

#if !defined(DO_CMPNAMESTRUCT)
 typedef CHAR CMPNAME [SIZEOF_ROTOIDSTR + 1]; // Composite view roto ID name type; includes NULL terminator
#else
 typedef struct tagCMPNAME CMPNAME;
#endif



// Structure mapping security resource to the standard permission bit sets.
// Associative structure, where lpsResource is the key.
// There may be a chain of resources, in which case their cummulative
// bit-wise AND is the permission bitset used.
typedef struct tagPERMISSION {
   LPSTR lpsResource;
   LONG  lPermission;
   struct tagPERMISSION FAR * AndResources;
} PERMISSIONMAP, FAR * LPPERMISSIONMAP;



// Mapping from detail field index to header field index. Associative
// structure, where lDetail is the key. Used to associate fields in a
// detail view to fields in its header that depend on them.
typedef struct tagDETAIL {
   LONG lDetail;
   LONG lHeader;
} DETAILMAP, FAR * LPDETAILMAP;



// Re-entrancy state; used by Roto entries
typedef struct tagENTRYSTATE {
   BOOL bVerifying;
   BOOL bFieldChanged;
   INT ScratchAllocated;
   ERRNUM eRevision;
   ERRNUM eValidation;
   LPROTOVIEW RotoView;
   INT RotoLength;
   INT filterExpressionCast;
   WORD transLevel;
   int rvspyIndents;
   INT EntryPath;
#if defined(DO_ENTRYSTATEEXTRA)
   ENTRYSTATEEXTRA extra;
#endif
} ENTRYSTATE, FAR * LPENTRYSTATE;



// table of vectors to functions performing type-specific operations
typedef struct tagTYPEOPERATIONS {
   BOOL  (WINAPI * iszero)   (LPDBFIELD field, LPDATUM   data);
   void  (WINAPI * add)      (LPDBFIELD field, LPDATUM   to,    LPDATUM by);
   void  (WINAPI * subtract) (LPDBFIELD field, LPDATUM   from,  LPDATUM by);
} TYPEOPERATIONS, FAR * LPTYPEOPERATIONS;

typedef INT (WINAPI * FIELDCOMPARATOR) (LPDBFIELD field, LPDATUM d1, LPDATUM d2);



#if !defined(__cplusplus)

// When plain old C, typedef the old-fashioned V
typedef struct tagV V;

#else

}; // extern "C" {
}; // namespace A4WAPI {

// Need the nothrow class
#include <new>

namespace A4WAPI {
extern "C" {

// When C++, the template derives VBASE from tagV. The user then derives
// VEXTRA from VBASE, and finally the template derives V from VEXTRA.

struct VBASE : public tagV {
   // VBASE acts as the root of the "OO" version of V. Although it derives from
   // tagV it is intended as containment only; tagV remains a pure C structure.
   virtual ~VBASE();
};

#include "scLoan3.h"
typedef VEXTRA V;

#endif

// Regardless of C or C++, typedef a pointer to V
typedef V *LPV;



#define  CALLOUTERROR                  ERRNUM WINAPI
#define  ERROR_FROM_CALLOUT(expr)      (expr)
#define  ERROR_RETURN_CALLOUT(expr)    (expr)



// The following is for subclass views, to construct keys using fields
// from the base view's table
#define  KEY_FROMBASE   0x8000



/////////////////////////////////////////////////////////////////////////////
// Declarations for conditionally selected features. The corresponding
// definition in the scLoan1.c file must be done.

VIEWBASE ApplyHeaderFields (LPV lpv, INT op);
void WINAPI AttribClear (LPV lpv, LONG field, LONG bit);
LONG WINAPI AttribGet (LPV lpv, LONG field);
void WINAPI AttribPut (LPV lpv, LONG field, LONG bit);
void WINAPI AttribSet (LPV lpv, LONG field, LONG bit);
BOOL WINAPI AttribTest (LPV lpv, LONG field, LONG bit);
VIEWBASE AutoCancelBody (LPV lpv, LONG field);
VIEWCALL BaseNotify (LPVOID context, LONG reason, LONG rotoID, LONG info, LPVOID extra, LPRVH rvh, LPVOID view);
CALLOUTERROR CalculateFields (LPV lpv);
VIEWBASE CancelBody (LPV lpv, INT level);
VIEWBASE ComposeEtc (LPV lpv);
VIEWCALL CompositeNotify (LPVOID context, LONG reason, LONG rotoID, LONG info, LPVOID extra, LPRVH rvh, LPVOID view);
DB_ERRNUM WINAPI ConcurrencyEtc (LPV lpv, INT fields);
VIEWBASE CreateEtc (LPV lpv);
VIEWBASE DeleteBody (LPV lpv);
VIEWBASE DeleteDetailsBody (LPV lpv, INT c);
VIEWBASE DeleteValid (LPV lpv);
void WINAPI EntryStatePop (LPV lpv, LPENTRYSTATE state);
LPENTRYSTATE WINAPI EntryStatePush (LPV lpv, LPROTOVIEW v, INT length, LPENTRYSTATE state);
LPPRESENTATION WINAPI FindPresentsInfo (LPV lpv, LONG field);
#if !defined(DO_GENERATEKEYDELAYED)
 CALLOUTERROR GenerateKey (LPV lpv);
#else
 CALLOUTERROR GenerateKey (LPV lpv, INT delay);
#endif
VIEWBASE GetEtc (LPV lpv, LONG lField, LPSTR lpsBuffer, INT nSize);
A4W_FLAGS WINAPI GetPermissions (LPV lpv);
VIEWBASE HeaderEtc (LPV lpv, LONG field, INT op, LONG source, LPSTR old, LPSTR New);
CALLOUTERROR InitFieldStructEtc (LPV lpv, LONG lField);
VIEWBASE InitBodyGenBase (LPV lpv, INT fGenerate);
CALLOUTERROR InitNonBlankFields (LPV lpv);
INT WINAPI LibMainEtc (HINSTANCE hInstance, WORD wDataSeg, WORD wHeapSize, LPSTR lpszCmdLine);
VIEWBASE MapToDetail (LPV lpv, INT op, INT cmp, va_list arguments);
VIEWBASE NotifyFire (LPV lpv, LONG reason, LONG info, LPVOID extra);
VIEWBASE NotifyQueueFieldValue (LPV lpv, LONG field, LPDBFIELD def);
VIEWBASE OpenEtc (LPV lpv);
REV_ERRNUM WINAPI PrePostEtc (LPV lpv, INT op, INT record);
VIEWBASE ProcessEtc (LPV lpv);
VIEWBASE PutCmpField (LPV lpv, LONG lField, LPSTR lpsBuffer, INT size);
VIEWBASE PutCmpFieldAux (LPV lpv, LONG lField, LPSTR lpBuffer, INT nSize, BOOL validate, INT from, INT to);
CALLOUTERROR PutCmpFields (LPV lpv);
VIEWBASE PutCmpKey (LPV lpv, INT cmp, INT inst, BOOL validate);
VIEWBASE PutEtc (LPV lpv, LONG lField, LPSTR lpsBuffer, INT nSize);
void WINAPI ReportError (LPV lpv, RSCID error, LPSTR a1, LPSTR a2, LPSTR a3);
void WINAPI ReportErrorViaPIB (HPIB pib, RSCID error, LPSTR a1, LPSTR a2, LPSTR a3);
void WINAPI ReportGenericError (LPV lpv, WORD area, WORD op, WORD error, LPVOID extra);
void WINAPI ReportGenericErrorViaPIB (HPIB pib, WORD area, WORD op, WORD error, LPVOID extra);
VIEWBASE RekeyedRevision (LPV lpv, INT level, LPSTR from, LPSTR to, INT size);
VIEWBASE ReverseHeaderFields (LPV lpv, INT op);
VIEWBASE RevisionInnerPost (LPV lpv, INT level);
DB_ERRNUM WINAPI revPostEtc (LPV lpv, INT op, INT record);
VIEWCALL rotoEntry (LPROTOVIEW v, INT length);
VIEWBASE rotoEntryEtc (LPROTOVIEW v, INT length);
void WINAPI SaveHeaderFields (LPV lpv);
WORD WINAPI ValidateFieldDependencies (LPV lpv);
#if defined(DO_LAZYPUT)
 BOOL WINAPI ValidateKey (LPV lpv, INT view, INT inst);
#else
 BOOL WINAPI ValidateKey (LPV lpv, INT view, LPKEYMAP keyMap, LPLONG keyFields);
#endif
VIEWBASE xxxFetchFilter (LPV lpv, INT flags, LPFILTER filter, LPSHORT range, BOOL ascending);
VIEWBASE xxxRead (LPVOID lpView, BOOL bLock);



/////////////////////////////////////////////////////////////////////////////
// Declarations for generally available data structures. These must be
// initialized in the scLoan1.c file.

#if defined(DO_HEADERETC)
extern DETAILMAP headerFields [DO_HEADERETC];
#endif

#if BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT>0
extern TBLMAP tables [BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT];
#endif

#if KEY_COUNT>0
extern KEYMAP keyNumMap [KEY_COUNT];
#endif

#if HCHY_CMP_COUNT+DMND_CMP_COUNT+IMP_CMP_COUNT>0
extern KEYMAP hierarchyKeyMap [];
#endif

#if FLD_IDX_COUNT>0
extern LONG fldNumToIdx [FLD_IDX_COUNT];
#endif

extern IDXMAP fldIdxMap [IDXIDX(FLD_IDX_LIMIT)];

#if CMP_COUNT+MAN_CMP_COUNT>0
extern CMPNAME cmpNameList [CMP_COUNT+MAN_CMP_COUNT];
#endif

#if SUBCLASS_LEVEL!=NOT_SUBCLASS
extern CHAR subCmpName [SIZEOF_ROTOIDSTR + 1];
#endif

#if RSC_COUNT>0
extern PERMISSIONMAP permission [RSC_COUNT];
#endif

extern TYPEOPERATIONS BCDOperations;
extern TYPEOPERATIONS ByteOperations;
extern TYPEOPERATIONS IntegerOperations;
extern TYPEOPERATIONS LongOperations;
extern TYPEOPERATIONS StringOperations;
extern TYPEOPERATIONS RealOperations;

extern LPTYPEOPERATIONS aTypeOperations [FT_BOOL+1];
extern FIELDCOMPARATOR aTypeComparators [FT_BOOL+1];



/////////////////////////////////////////////////////////////////////////////
// Declarations for generally available subroutines found in scLoan.c

// The fileXXXX routines are not always defined by the template. For stub
// views they appear in scLoan1.c, and must be specified by the programmer.
// Regardless of their location they are always available except in superviews.
DB_ERRNUM WINAPI fileAdd (WORD wLinkNo, HPIB hpib);
DB_ERRNUM WINAPI fileBegin (LPV lpv);
DB_ERRNUM WINAPI fileCancel (LPV lpv);
DB_ERRNUM WINAPI fileClose (LPV lpv);
DB_ERRNUM WINAPI fileCommit (LPV lpv);
DB_ERRNUM WINAPI fileCreate (LPV lpv);
DB_ERRNUM WINAPI fileDelete (LPV lpv);
DB_ERRNUM WINAPI fileDirty (LPV lpv, LPBOOL dirty);
DB_ERRNUM WINAPI fileDriverInfo (WORD wLinkNo, HPIB hpib, LPDBDRVRINFO info);
DB_ERRNUM WINAPI fileDrop (WORD wLinkNo, HPIB hpib);
DB_ERRNUM WINAPI fileEmpty (LPV lpv);
DB_ERRNUM WINAPI fileError (WORD wLinkNo, HPIB hpib, DB_ERRNUM e);
DB_ERRNUM WINAPI fileFilterSegs (LPV lpv);
DB_ERRNUM WINAPI fileFirst (LPV lpv, BOOL bLock);
DB_ERRNUM WINAPI fileGet (LPV lpv, BOOL bLock);
DB_ERRNUM WINAPI fileInfo (WORD wLinkNo, HPIB hpib, INT table, LPDBTABLE info);
DB_ERRNUM WINAPI fileInsert (LPV lpv);
DB_ERRNUM WINAPI fileIsLocked (LPV lpv);
DB_ERRNUM WINAPI fileLinkFlags (WORD wLinkNo, HPIB hpib, LPWORD flags);
DB_ERRNUM WINAPI fileLocate (LPV lpv);
DB_ERRNUM WINAPI fileLock (LPV lpv);
DB_ERRNUM WINAPI fileNext (LPV lpv, BOOL bLock);
DB_ERRNUM WINAPI fileOpen (WORD wLinkNo, HPIB hpib, LPV lpv);
DB_ERRNUM WINAPI fileOptLock (LPV lpv, BOOL optimistic);
REV_ERRNUM WINAPI filePrePost (LPV lpv, LPWORD op, INT record);
REV_ERRNUM WINAPI filePost (LPV lpv);
DB_ERRNUM WINAPI fileFilterCount (LPV lpv, LPSTR filter, A4W_FLAGS flags, LP_A4W_SIZE count);
DB_ERRNUM WINAPI fileFilterDelete (LPV lpv, LPFILTER filter);
DB_ERRNUM WINAPI fileReverses (WORD wLinkNo);
DB_ERRNUM WINAPI fileRollback (LPV lpv);
DB_ERRNUM WINAPI fileSelectFields (LPV lpv);
DB_ERRNUM WINAPI fileTransBegin (LPV lpv);
DB_ERRNUM WINAPI fileTransCommit (LPV lpv);
DB_ERRNUM WINAPI fileTransRollback (LPV lpv);
DB_ERRNUM WINAPI fileUnLock (LPV lpv);
DB_ERRNUM WINAPI fileUpdate (LPV lpv);

DB_ERRNUM WINAPI fileAddBase (WORD wLinkNo, HPIB hpib);
DB_ERRNUM WINAPI fileBeginBase (LPV lpv);
DB_ERRNUM WINAPI fileCancelBase (LPV lpv);
DB_ERRNUM WINAPI fileCloseBase (LPV lpv);
DB_ERRNUM WINAPI fileCommitBase (LPV lpv);
DB_ERRNUM WINAPI fileCreateBase (LPV lpv);
DB_ERRNUM WINAPI fileDeleteBase (LPV lpv);
DB_ERRNUM WINAPI fileDirtyBase (LPV lpv, LPBOOL dirty);
DB_ERRNUM WINAPI fileDriverInfoBase (WORD wLinkNo, HPIB hpib, LPDBDRVRINFO info);
DB_ERRNUM WINAPI fileDropBase (WORD wLinkNo, HPIB hpib);
DB_ERRNUM WINAPI fileEmptyBase (LPV lpv);
DB_ERRNUM WINAPI fileErrorBase (WORD wLinkNo, HPIB hpib, DB_ERRNUM e);
DB_ERRNUM WINAPI fileFilterSegsBase (LPV lpv);
DB_ERRNUM WINAPI fileFirstBase (LPV lpv, BOOL bLock);
DB_ERRNUM WINAPI fileGetBase (LPV lpv, BOOL bLock);
DB_ERRNUM WINAPI fileInfoBase (WORD wLinkNo, HPIB hpib, INT table, LPDBTABLE info);
DB_ERRNUM WINAPI fileInsertBase (LPV lpv);
DB_ERRNUM WINAPI fileIsLockedBase (LPV lpv);
DB_ERRNUM WINAPI fileLinkFlagsBase (WORD wLinkNo, HPIB hpib, LPWORD flags);
DB_ERRNUM WINAPI fileLocateBase (LPV lpv);
DB_ERRNUM WINAPI fileLockBase (LPV lpv);
DB_ERRNUM WINAPI fileNextBase (LPV lpv, BOOL bLock);
DB_ERRNUM WINAPI fileOpenBase (WORD wLinkNo, HPIB hpib, LPV lpv);
DB_ERRNUM WINAPI fileOptLockBase (LPV lpv, BOOL optimistic);
REV_ERRNUM WINAPI filePrePostBase (LPV lpv, LPWORD op, INT record);
REV_ERRNUM WINAPI filePostBase (LPV lpv);
DB_ERRNUM WINAPI fileFilterCountBase (LPV lpv, LPSTR filter, A4W_FLAGS flags, LP_A4W_SIZE count);
DB_ERRNUM WINAPI fileFilterDeleteBase (LPV lpv, LPFILTER filter);
DB_ERRNUM WINAPI fileReversesBase (WORD wLinkNo);
DB_ERRNUM WINAPI fileRollbackBase (LPV lpv);
DB_ERRNUM WINAPI fileSelectFieldsBase (LPV lpv);
DB_ERRNUM WINAPI fileTransBeginBase (LPV lpv);
DB_ERRNUM WINAPI fileTransCommitBase (LPV lpv);
DB_ERRNUM WINAPI fileTransRollbackBase (LPV lpv);
DB_ERRNUM WINAPI fileUnLockBase (LPV lpv);
DB_ERRNUM WINAPI fileUpdateBase (LPV lpv);

// Miscellaneous file stub support routines
DB_ERRNUM WINAPI BufferedFetch (LPV lpv);
DB_ERRNUM WINAPI dbError (WORD wLinkNo, HPIB hpib, DB_ERRNUM e);
DB_ERRNUM WINAPI dbErrorV (LPV lpv, DB_ERRNUM d);
FL_ERRNUM WINAPI filterError (HPIB hpib, WORD op, FL_ERRNUM e);
FL_ERRNUM WINAPI filterErrorV (LPV lpv, WORD op, FL_ERRNUM f);
DB_ERRNUM WINAPI revError (HPIB hpib, LPVOID rev, DB_ERRNUM e);
DB_ERRNUM WINAPI revErrorV (LPV lpv, LPVOID rev, DB_ERRNUM d);

// Miscellanous template helper functions. These are implemented and used by
// the template for various purposes, particularly managing the view handle.
// They are all available for use in call-outs and overrides
VIEWBASE AcquireOneView (LPV lpv, INT c);
void WINAPI AddDeltaBCD (LPDBFIELD field, LPDATUM to, LPDATUM by);
void WINAPI AddDeltaByte (LPDBFIELD field, LPDATUM to, LPDATUM by);
void WINAPI AddDeltaInteger (LPDBFIELD field, LPDATUM to, LPDATUM by);
void WINAPI AddDeltaLong (LPDBFIELD field, LPDATUM to, LPDATUM by);
void WINAPI AddDeltaReal (LPDBFIELD field, LPDATUM to, LPDATUM by);
void WINAPI AddDeltaString (LPDBFIELD field, LPDATUM to, LPDATUM by);
VIEWBASE ApplyHeaderDelta (LPV lpv, LONG target, INT op, LONG source, LPDATUM old, LPDATUM New, LPTYPEOPERATIONS operation);
VIEWBASE ApplyHeaderFields (LPV lpv, INT op);
VIEWBASE ApplyHeaderFieldsBase (LPV lpv, INT op);
BOOL ApplyMask (LPV lpv, LONG lField, LPPRESENTATION p, LPSTR data, WORD wLength);
VIEWBASE AutoCancel (LPV lpv, LONG field);
VIEWBASE AutoCancelBody (LPV lpv, LONG field);
VIEWBASE BaseBrowse (LPV lpv, BOOL bSelectFromStart);
void WINAPI BaseClose (LPV lpv);
DB_ERRNUM WINAPI BaseFetch (LPV lpv, BOOL bLock, BOOL bSelectFromStart);
VIEWBASE BaseGetData (LPV lpv);
VIEWBASE BaseGetKey (LPV lpv);
VIEWBASE BaseGetPermissions (HPIB hpib, WORD wLinkNo, LPLONG permissions);
LPVOID WINAPI BaseLoad (INT roto);
VIEWCALL BaseNotify (LPVOID context, LONG reason, LONG rotoID, LONG info, LPVOID extra, LPRVH rvh, LPVOID view);
VIEWCALL BaseNotifyBase (LPVOID context, LONG reason, LONG rotoID, LONG info, LPVOID extra, LPRVH rvh, LPVOID view);
VIEWBASE BaseOpen (LPV lpv);
VIEWBASE BasePutData (LPV lpv);
VIEWBASE BasePutKey (LPV lpv);
INT WINAPI BaseRoto (HPIB hpib);
VIEWBASE BaseRotoEntry (LPROTOVIEW v, INT length);
void WINAPI BaseUnload (LPVIEWDEF base);
INT WINAPI BinaryComparator (LPDBFIELD field, LPDATUM d1, LPDATUM d2);
BOOL BinarySearch (const void *key, const void * array, const INT count, const INT size, PINT insertion);
VIEWBASE BrowseBody (LPV lpv, LPSTR expression, BOOL ascending);
VIEWBASE CancelBody (LPV lpv, INT level);
VIEWBASE CancelBodyBase (LPV lpv, INT level);
ERRNUM ClearAttribs (LPV lpv, LONG attribs);
VIEWBASE ClearChange (LPV lpv);
void WINAPI CloseImpViews (LPV lpv);
void WINAPI CloseOneView (LPV lpv, INT c);
INT WINAPI ComparePrimary (LPV lpv, LPSTR FAR * record);
VIEWBASE ComposeDemand (LPV lpv, INT c, LPVIEWDEF composite);
VIEWBASE ComposeDetail (LPV lpv, INT c, LPVIEWDEF composite);
VIEWBASE ComposeHeader (LPV lpv, LPVIEWDEF composite);
VIEWBASE ComposeHierarchical (LPV lpv, INT c, LPVIEWDEF composite);
INT WINAPI CompositeCategory (LPV lpv, INT c);
VIEWCALL CompositeNotify (LPVOID context, LONG reason, LONG rotoID, LONG info, LPVOID extra, LPRVH rvh, LPVOID view);
VIEWCALL CompositeNotifyBase (LPVOID context, LONG reason, LONG rotoID, LONG info, LPVOID extra, LPRVH rvh, LPVOID view);
VIEWCALL CompositeNotifyEntry (LPVOID context, LONG reason, LONG rotoID, LONG info, LPVOID extra, LPRVH rvh, LPVOID view);
void WINAPI CopyRecords (LPV lpv, LPSTR FAR * to, LPSTR FAR * from);
INT WINAPI DecimalComparator (LPDBFIELD field, LPDATUM d1, LPDATUM d2);
VIEWBASE DeleteBody (LPV lpv);
VIEWBASE DeleteBodyBase (LPV lpv);
VIEWBASE DeleteDetails (LPV lpv);
VIEWBASE DeleteDetailsBody (LPV lpv, INT c);
VIEWBASE DeleteDetailsBodyBase (LPV lpv, INT c);
VIEWBASE DemandOpen (LPV lpv, INT c);
VIEWCALL detailName (LPVOID lpView, LONG lField, LPSTR lpsName, LPSTR lpsDesc);
BOOL WINAPI DetailKeyWithinHeader (LPV lpv);
void WINAPI EntryStatePop (LPV lpv, LPENTRYSTATE state);
void WINAPI EntryStatePopBase (LPV lpv, LPENTRYSTATE state);
LPENTRYSTATE WINAPI EntryStatePush (LPV lpv, LPROTOVIEW v, INT length, LPENTRYSTATE state);
LPENTRYSTATE WINAPI EntryStatePushBase (LPV lpv, LPROTOVIEW v, INT length, LPENTRYSTATE state);
VIEWBASE GetETAG (LPV lpv, LPSTR lpsBuffer, INT nSize);
LPVIEWDEF WINAPI FindCmp (LPV lpv, INT cmp);
LPCMPNAME WINAPI FindCmpDef (INT cmp);
LPLONG WINAPI FindCmpField (LPV lpv, INT cmp, LONG field);
LPBOOL WINAPI FindCmpForeign (LPV lpv, LONG field);
LPCMPKEY WINAPI FindCmpKey (LPV lpv, INT cmp);
LPSTR WINAPI FindCmpName (INT cmp);
LPCMPNOTIFYCONTEXT WINAPI FindCmpNotify (LPV lpv, INT cmp);
LPDETAILMAP WINAPI FindDetailMap ();
LPDBFIELD WINAPI FindFieldDefV (LPV lpv, LONG field);
LPLONG WINAPI FindFieldIndexV (LPV lpv, INT field);
LPIDXMAP WINAPI FindFieldMapV (LPV lpv, LONG field);
LPSTR WINAPI FindFieldValue (LPV lpv, LONG field);
LPSTR WINAPI FindFieldValueAux (LPV lpv, LONG field, LPSTR FAR * records);
LPBOOL WINAPI FindGenStub (LPV lpv, INT cmp);
LPBOOL WINAPI FindImpOpen (LPV lpv, INT cmp);
LPBOOL WINAPI FindImpRead (LPV lpv, INT cmp);
LPKEYMAP WINAPI FindKeyDef (INT key);
LPKEYMAP WINAPI FindKeyMap (INT c);
LPPERMISSIONMAP WINAPI FindPermissionMap ();
LPPRESENTATION WINAPI FindPresentsInfo (LPV lpv, LONG field);
LPSTR FAR * WINAPI FindRecord (LPV lpv);
LPSTR FAR * WINAPI FindRecordNotify (LPV lpv);
LPSTR FAR * WINAPI FindRecordRead (LPV lpv);
LPSTR FAR * WINAPI FindRecordTemp (LPV lpv);
LPREVISION WINAPI FindRevCache (LPV lpv);
LPREVLEVEL WINAPI FindRevLevel (LPV lpv, INT level);
LPREVNODE ** WINAPI FindRevRekey (LPV lpv, INT level);
LPTABLEHANDLE WINAPI FindTableHandle (LPV lpv);
LPDBTABLE WINAPI FindTableInfo (LPV lpv, INT t);
LPTBLMAP WINAPI FindTableMap (INT t);
LPTBLMAP WINAPI FindTableMapV (LPV lpv, INT t);
LPREVISION WINAPI FindTableRev (LPV lpv);
PTABLESELECTION WINAPI FindTableSelection (const LPV lpv, const INT t);
WORD FindTableWidth (LPV lpv, INT t);
VIEWBASE FlagKey (LPV lpv, INT wKeyNo, BOOL bSet, LONG lMask);
VIEWBASE FlagKeyAux (LPV lpv, INT wKeyNo, INT keys, BOOL bSet, LONG lMask);
VIEWBASE GenerateKeyReally (LPV lpv);
DB_ERRNUM WINAPI GenerateSequence (LPV lpv);
VIEWBASE GenericStub (LPV lpv, INT c, LPBOOL gen);
A4W_FLAGS WINAPI GetPermissions (LPV lpv);
VIEWBASE GetTemplateVersion (LPV lpv, LPSTR rotoID, LPVIEWDEF view, LPSTR supports, LPBCDDATE date);
VIEWCALL identifyEntry (LPIDENTIFYVIEW identify, INT length);
VIEWBASE InitBody (LPV lpv);
VIEWBASE InitBodyGen (LPV lpv, INT fGenerate); // fGenerate is now a flagset
VIEWBASE InitBodyGenBase (LPV lpv, INT fGenerate);
VIEWBASE InitField (LPV lpv, LONG field);
void WINAPI InitFieldBuffer (LPVOID buffer, INT type, INT length);
VIEWBASE InitFieldList (LPV lpv, LONG field);
VIEWBASE InitFields (LPV lpv);
VIEWBASE InitFieldStruct (LPV lpv);
INT WINAPI IntegerComparator (LPDBFIELD field, LPDATUM d1, LPDATUM d2);
BOOL WINAPI isGenericStub (LPV lpv, INT c);
BOOL WINAPI isZeroDeltaBCD (LPDBFIELD field, LPDATUM data);
BOOL WINAPI isZeroDeltaByte (LPDBFIELD field, LPDATUM data);
BOOL WINAPI isZeroDeltaInteger (LPDBFIELD field, LPDATUM data);
BOOL WINAPI isZeroDeltaLong (LPDBFIELD field, LPDATUM data);
BOOL WINAPI isZeroDeltaReal (LPDBFIELD field, LPDATUM data);
BOOL WINAPI isZeroDeltaString (LPDBFIELD field, LPDATUM data);
VIEWBASE LoadFieldMask (LPV lpv, LONG field, LPSTR mask);
void WINAPI LoadMask (HPIB hpib, LPSTR maskID, INT maskSize, LPSTR mask);
VIEWBASE LoadOneView (LPV lpv, INT c);
LPSTR WINAPI LoadRsc (HPIB hpib, LPSTR strID, INT buffersize, LPSTR buffer, BOOL trim);
INT WINAPI LongComparator (LPDBFIELD field, LPDATUM d1, LPDATUM d2);
WORD WINAPI MapStubToTableHandle (LPV lpv, TABLEHANDLE handle);
VIEWBASE MapToDetail (LPV lpv, INT op, INT cmp, va_list arguments);
VIEWBASE MapToDetailBase (LPV lpv, INT op, INT cmp, va_list arguments);
ERRNUM MapToDetails (LPV lpv, INT op, ...);
INT WINAPI MapToInternalComposite (INT c);
VIEWBASE MapToNestedDetails (LPV lpv, INT op);
LONG WINAPI MapToNewFieldIndex (LONG field);
void WINAPI MaxDatabaseError (DB_ERRNUM *p, DB_ERRNUM d);
void WINAPI MaxError (LPERRNUM p, ERRNUM e);
VIEWBASE MergeConflictedRecords (LPV lpv);
VIEWBASE NormalizeFieldBuffer (LPV lpv, LONG field, LPSTR input, INT size, LPSTR output, LPBOOL mask_error);
VIEWBASE NotifyAdd (LPV lpv, A4W_NOTIFY_PROC notify, LPVOID context, A4W_FLAGS flags);
VIEWBASE NotifyClose (LPV lpv);
VIEWBASE NotifyFieldAttributes (LPV lpv);
VIEWBASE NotifyFieldValues (LPV lpv);
VIEWBASE NotifyFire (LPV lpv, LONG reason, LONG info, LPVOID extra);
VIEWBASE NotifyFireBase (LPV lpv, LONG reason, LONG info, LPVOID extra);
VIEWBASE NotifyQueuedFields (LPV lpv);
VIEWBASE NotifyQueueField (LPV lpv, LONG field, LONG reason);
VIEWBASE NotifyQueueFieldValue (LPV lpv, LONG field, LPDBFIELD def);
VIEWBASE NotifyQueueFieldValues (LPV lpv);
VIEWBASE NotifyRemove (LPV lpv, A4W_NOTIFY_PROC notify, LPVOID context);
VIEWBASE OpenImpViews (LPV lpv);
VIEWBASE OpenOneView (LPV lpv, INT c);
VIEWBASE OpenOneViewInstance (LPV lpv, INT c, A4W_FLAGS flags, LPVOID extra, A4W_SIZE size);
VIEWBASE OrderBody (LPV lpv, WORD keys, INT nKeyNo);
VIEWBASE OpenBody (LPRVH myself, HPIB hPIB, WORD wLinkNo, A4W_FLAGS flags, LPVOID extra, A4W_SIZE size, LPV FAR * lplpv);
BOOL WINAPI paramGetBoolean (HPIB pib, WORD linkNo, LPSTR rotoIDStr, LONG paramNo, LPDBSBOOL buffer);
BOOL WINAPI paramGetInteger (HPIB pib, WORD linkNo, LPSTR rotoIDStr, LONG paramNo, LPDBSINT buffer);
BOOL WINAPI paramGetLong (HPIB pib, WORD linkNo, LPSTR rotoIDStr, LONG paramNo, LPDBSLONG buffer);
BOOL WINAPI paramGetReal (HPIB pib, WORD linkNo, LPSTR rotoIDStr, LONG paramNo, LPDBSREAL buffer);
BOOL WINAPI paramGetString (HPIB pib, WORD linkNo, LPSTR rotoIDStr, LONG paramNo, LPSTR buffer, WORD bufferSize);
void WINAPI PropagatePrimary (LPV lpv);
void WINAPI PropagatePrimaryField (LPV lpv, LONG field);
VIEWBASE PullHeaderKey (LPV lpv);
VIEWBASE PutCmpDetailSequence (LPV lpv);
VIEWBASE PutCmpField (LPV lpv, LONG lField, LPSTR lpsBuffer, INT size);
VIEWBASE PutCmpFieldAux (LPV lpv, LONG lField, LPSTR lpBuffer, INT nSize, BOOL validate, INT from, INT to);
CALLOUTERROR PutCmpFields (LPV lpv);
VIEWBASE PutCmpKey (LPV lpv, INT cmp, INT inst, BOOL validate);
VIEWBASE PutCmpKeyBase (LPV lpv, INT cmp, INT inst, BOOL validate);
VIEWBASE PutETAG (LPV lpv, LPSTR lpsBuffer, INT nSize);
VIEWBASE QueryKeyTypes (LPVIEWDEF v, LPCMPKEY k);
INT WINAPI RealComparator (LPDBFIELD field, LPDATUM d1, LPDATUM d2);
void WINAPI ReleaseOneView (LPV lpv, INT c);
void WINAPI ReportAssertion (LPSTR file, INT line, LPSTR expr);
void WINAPI ReportBaseError (HPIB hpib, RSCID error, LPSTR a1, LPSTR a2, LPSTR a3);
void WINAPI ReportBaseLoadError (HPIB hpib, LPSTR rotoID);
void WINAPI ReportBaseMemoryError (HPIB hpib, RSCID op);
void WINAPI ReportBufferError (LPV lpv, LONG field);
void WINAPI ReportCompositeKeyError (LPV lpv, RSCID op, LPSTR rotoID);
void WINAPI ReportDatumError (LPV lpv, LONG field);
void WINAPI ReportDisabledError (LPV lpv, LONG field);
void WINAPI ReportError (LPV lpv, RSCID error, LPSTR a1, LPSTR a2, LPSTR a3);
void WINAPI ReportErrorViaPIB (HPIB pib, RSCID error, LPSTR a1, LPSTR a2, LPSTR a3);
void WINAPI ReportFieldError (LPV lpv, INT field);
void WINAPI ReportGenericError (LPV lpv, WORD area, WORD op, WORD error, LPVOID extra);
void WINAPI ReportGenericErrorViaPIB (HPIB pib, WORD area, WORD op, WORD error, LPVOID extra);
void WINAPI ReportIndexError (LPV lpv, LONG field);
void WINAPI ReportKeyError (LPV lpv, INT key);
void WINAPI ReportListError (LPV lpv, LONG field);
void WINAPI ReportLoadError (LPV lpv, LPSTR rotoID);
void WINAPI ReportMaskError (LPV lpv, LONG field);
void WINAPI ReportMemoryError (LPV lpv, RSCID op);
void WINAPI ReportReadonlyError (LPV lpv, LONG field);
void WINAPI ReportReverseError (LPV lpv);
void WINAPI ReportRotoError (LPV lpv, INT op);
void WINAPI ReportSecurityError (LPV lpv, RSCID op);
void WINAPI ReportString (LPSTR message);
void WINAPI ReportSubclassComposeError (LPV lpv);
VIEWBASE ReverseHeaderFields (LPV lpv, INT op);
VIEWBASE ReverseHeaderFieldsBase (LPV lpv, INT op);
LPREVNODE WINAPI RevisionAdd (LPV lpv, LPREVISION rev, LPVOID key);
DB_ERRNUM RevisionAllocateAfter (LPV lpv, LPDBFIELD f, LPVOID sequence);
DB_ERRNUM WINAPI RevisionAttach (LPV lpv);
DB_ERRNUM WINAPI RevisionCancel (LPV lpv, LPREVISION rev);
BOOL RevisionCheckDuplicates (LPV lpv, BOOL checked, LPREVISION rev);
BOOL WINAPI RevisionConsume (LPV lpv);
DB_ERRNUM WINAPI RevisionCreate (LPV lpv);
DB_ERRNUM WINAPI RevisionDirty (LPV lpv, LPREVISION rev, LPBOOL dirty);
DB_ERRNUM WINAPI RevisionDuplicate (LPV lpv, LPREVISION target, LPREVISION source);
DB_ERRNUM WINAPI RevisionGenerate (LPV lpv, LPREVISION lpRev, LPREVISION lpRevCache);
LPREVNODE WINAPI RevisionInnerAdd (LPV lpv, LPREVNODE FAR *adding, LPVOID key, INT level);
DB_ERRNUM WINAPI RevisionInnerAttach (LPV lpv, INT level);
DB_ERRNUM WINAPI RevisionInnerCancel (LPV lpv, INT level, LPREVISION rev);
BOOL WINAPI RevisionInnerConsume (LPV lpv, INT level, LPREVISION rev);
DB_ERRNUM WINAPI RevisionInnerCreate (LPV lpv, INT level);
DB_ERRNUM WINAPI RevisionInnerDirty (LPV lpv, INT level, LPBOOL dirty);
DB_ERRNUM WINAPI RevisionInnerDuplicate (LPV lpv, LPREVNODE source, INT level);
LPREVNODE WINAPI RevisionInnerFind (LPV lpv, LPVOID key, INT level);
DB_ERRNUM WINAPI RevisionInnerGraft (LPV lpv, PREVGRAFTPOINT graft, LPREVISION rev, A4W_FLAGS flags);
DB_ERRNUM WINAPI RevisionInnerMove (LPV lpv, LPREVNODE target, LPREVNODE FAR *source, INT level, A4W_FLAGS flags);
VIEWBASE RevisionInnerPost (LPV lpv, INT level);
VIEWBASE RevisionInnerPostBase (LPV lpv, INT level);
DB_ERRNUM WINAPI RevisionInnerSegments (LPV lpv, INT level);
DB_ERRNUM WINAPI RevisionInnerSwitch (LPV lpv, INT level, LPVOID key, LPREVNODE FAR *found);
void WINAPI RevisionMove (LPREVISION target, LPREVISION source, A4W_FLAGS flags);
DB_ERRNUM WINAPI RevisionOuterCancel (LPV lpv);
DB_ERRNUM WINAPI RevisionOuterDirty (LPV lpv, LPBOOL dirty);
VIEWBASE RevisionOuterPost (LPV lpv);
DB_ERRNUM WINAPI RevisionOuterSegments (LPV lpv);
VIEWBASE RevisionPost (LPV lpv);
DB_ERRNUM RevisionRealize (LPV lpv);
BOOL WINAPI RevisionRecursiveConsume (LPV lpv, LPREVNODE FAR *anchor, INT level, LPREVISION rev);
BOOL WINAPI RevisionRecursiveConsumeRekeys (LPV lpv, LPREVNODE FAR *anchor, INT level, LPREVISION rev);
DB_ERRNUM WINAPI RevisionRecursiveDuplicate (LPV lpv, LPREVNODE source, INT level, LPREVNODE FAR *target);
BOOL RevisionRecursiveFind (LPV lpv, INT level, LPVOID key, LPREVNODE FAR *root, PREVGRAFTPOINT graft);
DB_ERRNUM WINAPI RevisionRecursiveSegments (LPV lpv, LPREVNODE current);
DB_ERRNUM WINAPI RevisionRekey (LPV lpv, LPVOID OldKey, LPVOID NewKey, INT size, A4W_FLAGS flags);
DB_ERRNUM WINAPI RevisionSegments (LPV lpv, LPREVISION rev);
void RevisionSpy (LPV lpv, LPREVNODE node, INT level);
void RevisionSpyLevels (LPV lpv);
void RevisionSpyTree (LPV lpv, LPREVNODE node, INT level);
DB_ERRNUM RevisionWasRealized (LPV lpv);
VIEWBASE RewriteRecord (LPV lpv);
VIEWCALL rotoEntry (LPROTOVIEW v, INT length);
VIEWCALL rotoEntryBase (LPROTOVIEW v, INT length);
void rvspyNotify (LPV lpv, char *verb, LONG reason, LONG info, void *extra, void *context);
int rvspyPrint (const char *format, ...);
void WINAPI SaveHeaderFields (LPV lpv);
void WINAPI SaveHeaderFieldsBase (LPV lpv);
void WINAPI ScratchError (LPV lpv);
void WINAPI ScratchPop (LPV lpv, LPVOID buffer);
LPVOID WINAPI ScratchPush (LPV lpv, INT size);
VIEWBASE SecurityPermissions (HPIB hpib, WORD wLinkNo, LPPERMISSIONMAP resources, INT count, LP_A4W_FLAGS permissions);
ERRNUM SelectionCancel (LPV lpv);
ERRNUM SelectionIncrease (LPV lpv, A4W_FLAGS what, A4W_SIZE count, PLONG fields);
BOOL SelectionInsertName (LPV lpv, const char *name, const INT table);
ERRNUM SelectionValid (LPV lpv, A4W_SIZE count, PLONG fields);
ERRNUM SetAttribs (LPV lpv, LONG attribs);
INT WINAPI StringComparator (LPDBFIELD field, LPDATUM d1, LPDATUM d2);
void WINAPI SubtractDeltaBCD (LPDBFIELD field, LPDATUM from, LPDATUM by);
void WINAPI SubtractDeltaByte (LPDBFIELD field, LPDATUM from, LPDATUM by);
void WINAPI SubtractDeltaInteger (LPDBFIELD field, LPDATUM from, LPDATUM by);
void WINAPI SubtractDeltaLong (LPDBFIELD field, LPDATUM from, LPDATUM by);
void WINAPI SubtractDeltaReal (LPDBFIELD field, LPDATUM from, LPDATUM by);
void WINAPI SubtractDeltaString (LPDBFIELD field, LPDATUM from, LPDATUM by);
VIEWBASE SupportsAPIversion (LPV lpv, LPSTR rotoID, LPVIEWDEF view, LPSTR needs, LPBOOL supports);
void WINAPI SwapRecords (LPSTR FAR * set1, LPSTR FAR * set2);
VIEWCALL tableName (LPVOID lpView, LONG lField, LPSTR lpsName, LPSTR lpsDesc);
void WINAPI UnloadOneView (LPV lpv, INT c);
ERRNUM WINAPI UnpostedDetail (LPV lpv, INT level, INT c, LPBOOL unposted);
ERRNUM WINAPI UnpostedDetails (LPV lpv, INT level, LPBOOL unposted);
BOOL WINAPI ValidateBuffer (LPV lpv, LONG field, INT size);
BOOL WINAPI ValidateData (LPV lpv, LONG field, LPVOID datum);
BOOL WINAPI ValidateField (LPV lpv, LONG field, LPVOID buffer);
#if defined(DO_LAZYPUT)
 BOOL WINAPI ValidateKeyField (LPV lpv, LONG field, LPVOID buffer, INT size);
#else
 BOOL WINAPI ValidateKeyField (LPV lpv, LONG field);
#endif
BOOL WINAPI ValidateKeys (LPV lpv, BOOL verifying);
BOOL WINAPI ValidateList (LPV lpv, LPPRESENTATION p, LONG field, LPVOID data);
BOOL WINAPI ValidIndexV (LPV lpv, LONG field);
VIEWBASE viewGetBoolean (LPVOID rvh, LPVOID view, LONG field, LPDBSBOOL buffer);
VIEWBASE viewGetInteger (LPVOID rvh, LPVOID view, LONG field, LPDBSINT buffer);
VIEWBASE viewGetLong (LPVOID rvh, LPVOID view, LONG field, LPDBSLONG buffer);
VIEWBASE viewGetReal (LPVOID rvh, LPVOID view, LONG field, LPDBSREAL buffer);
VIEWBASE viewGetString (LPVOID rvh, LPVOID view, LONG field, LPSTR buffer, INT size);
VIEWBASE viewPutBoolean (LPVOID rvh, LPVOID view, LONG field, DBSBOOL buffer, BOOL verify);
VIEWBASE viewPutInteger (LPVOID rvh, LPVOID view, LONG field, DBSINT buffer, BOOL verify);
VIEWBASE viewPutLong (LPVOID rvh, LPVOID view, LONG field, DBSLONG buffer, BOOL verify);
VIEWBASE viewPutReal (LPVOID rvh, LPVOID view, LONG field, DBSREAL buffer, BOOL verify);
VIEWBASE xxxFetch (LPVOID lpView, INT flags);
VIEWBASE xxxFetchFilter (LPV lpv, INT flags, LPFILTER filter, LPSHORT range, BOOL ascending);
VIEWBASE xxxFetchFilterBase (LPV lpv, INT flags, LPFILTER filter, LPSHORT range, BOOL ascending);
VIEWCALL xxxKey (LPVOID lpView, INT nKeyNo, LPSTR lpsName, LPSHORT lpnFields, LPLONG lplKeyFields);
VIEWCALL xxxNameOnly (LPVOID lpView, LONG lField, LPSTR lpsName, LPSTR lpsDesc);
VIEWBASE xxxRead (LPVOID lpView, BOOL bLock);
VIEWBASE xxxReadBase (LPVOID lpView, BOOL bLock);
VIEWBASE xxxVerify (LPVOID lpView, BOOL verifying);



///////////////////////////////////////////////////////////////////////////////
// Inline versions of structure dereferencing and other helper functions

#if CMP_COUNT+MAN_CMP_COUNT>0
 #define InlineFindCmp(_v_,_c_)           (&(_v_)->cmp[_c_])
 #if defined(DO_CMPNAMESTRUCT)
  #define InlineFindCmpDef(_c_)           (&cmpNameList [_c_])
 #else
  #define InlineFindCmpDef(_c_)           ((LPCMPNAME) NULL)
 #endif
#else
 #define InlineFindCmp(_v_,_c_)           ((LPVIEWDEF) NULL)
 #define InlineFindCmpDef(_c_)            ((LPCMPNAME) NULL)
#endif

#if CMP_COUNT-HDR_CMP_COUNT>0
 #define InlineFindCmpField(_v_,_c_,_f_)  (&(_v_)->cmpFields[(_c_)-HDR_CMP_COUNT][IDXIDX((_f_))])
#else
 #define InlineFindCmpField(_v_,_c_,_f_)  ((LPLONG) NULL)
#endif

#if HCHY_CMP_COUNT+DMND_CMP_COUNT+IMP_CMP_COUNT>0
 #define InlineFindCmpForeign(_v_,_f_)    (&(_v_)->cmpForeign[IDXIDX(_f_)])
#else
 #define InlineFindCmpForeign(_v_,_f_)    ((LPBOOL) NULL)
#endif

#if CMP_COUNT+MAN_CMP_COUNT>0
 #define InlineFindCmpKey(_v_,_c_)        (&(_v_)->cmpKey[_c_])
 #if !defined(DO_CMPNAMESTRUCT)
  #define InlineFindCmpName(_c_)          (cmpNameList [_c_])
 #else
  #define InlineFindCmpName(_c_)          (cmpNameList [_c_].rotoID)
 #endif
 #define InlineFindCmpNotify(_v_,_c_)     (&(_v_)->cmpNotifyContext [_c_])
#else
 #define InlineFindCmpKey(_v_,_c_)        ((LPCMPKEY) NULL)
 #define InlineFindCmpName(_c_)           ((LPSTR) NULL)
 #define InlineFindCmpNotify(_v_,_c_)     ((LPCMPNOTIFYCONTEXT) NULL)
#endif

#if defined(DO_HEADERETC)
 #define InlineFindDetailMap()            (headerFields)
#else
 #define InlineFindDetailMap()            ((LPDETAILMAP) NULL)
#endif

#if FLD_IDX_COUNT>0
 #define InlineFindFieldIndex(_f_)        (&fldNumToIdx [_f_])
#else
 #define InlineFindFieldIndex(_f_)        ((LPLONG) NULL)
#endif

#define InlineFindFieldMap(_f_)           (&fldIdxMap [IDXIDX((_f_))])
#define InlineFindFieldValue(_v_,_f_)     (FindFieldValueAux ((_v_), (_f_), FindRecord ((_v_))))

#if CMP_COUNT+MAN_CMP_COUNT>0
 #define InlineFindGenStub(_v_,_c_)       (&(_v_)->cmpGenStub[_c_])
#else
 #define InlineFindGenStub(_v_,_c_)       ((LPBOOL) NULL)
#endif

#if DMND_CMP_COUNT+IMP_CMP_COUNT+MAN_CMP_COUNT>0
 #define InlineFindImpOpen(_v_,_c_)       (&(_v_)->impOpen [(_c_)-(EXP_CMP_COUNT-DMND_CMP_COUNT)])
 #define InlineFindImpRead(_v_,_c_)       (&(_v_)->impRead [(_c_)-(EXP_CMP_COUNT-DMND_CMP_COUNT)])
#else
 #define InlineFindImpOpen(_v_,_c_)       ((LPBOOL) NULL)
 #define InlineFindImpRead(_v_,_c_)       ((LPBOOL) NULL)
#endif

#if KEY_COUNT>0
 #define InlineFindKeyDef(_k_)            (&keyNumMap [(_k_)])
#else
 #define InlineFindKeyDef(_k_)            ((LPKEYMAP) NULL)
#endif

#if RSC_COUNT>0
 #define InlineFindPermissionMap()        (permission)
#else
 #define InlineFindPermissionMap()        ((LPPERMISSIONMAP) NULL)
#endif

#if BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT>0
 #define InlineFindRecord(_v_)            ((_v_)->record)
#else
 #define InlineFindRecord(_v_)            ((LPSTR FAR *) NULL)
#endif

#if BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT>0
 #define InlineFindRecordNotify(_v_)      ((_v_)->recordNotify)
#else
 #define InlineFindRecordNotify(_v_)      ((LPSTR FAR *) NULL)
#endif

#if BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT>0 && (defined(DO_RECORDREAD) || defined(DO_CONCURRENCYETC))
 #define InlineFindRecordRead(_v_)        ((_v_)->recordRead)
#else
 #define InlineFindRecordRead(_v_)        ((LPSTR FAR *) NULL)
#endif

#if BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT>0
 #define InlineFindRecordTemp(_v_)        ((_v_)->recordTemp)
#else
 #define InlineFindRecordTemp(_v_)        ((LPSTR FAR *) NULL)
#endif

#if BASE_TBL_COUNT+TBL_COUNT>0 && HAS_REVISIONS
 #define InlineFindRevCache(_v_)          ((_v_)->revCache)
#else
 #define InlineFindRevCache(_v_)          ((LPREVISION) NULL)
#endif

#if HDR_HAS_REVISIONS>0
 #define InlineFindRevLevel(_v_,_l_)      (&(_v_)->revLevel[(_l_)-1])
 #define InlineFindRevRekey(_v_,_l_)      (&(_v_)->revConsumingRekeys[(_l_)-1])
#else
 #define InlineFindRevLevel(_v_,_l_)      ((LPREVLEVEL) NULL)
 #define InlineFindRevRekey(_v_,_l_)      ((LPREVNODE **) NULL)
#endif

#if TBL_COUNT>0
 #define InlineFindTableHandle(_v_)       ((_v_)->ahTable)
#else
 #define InlineFindTableHandle(_v_)       ((LPTABLEHANDLE) NULL)
#endif

#if BASE_TBL_COUNT+TBL_COUNT>0
 #define InlineFindTableInfo(_v_,_t_)     (&(_v_)->aTableInfo[_t_])
#else
 #define InlineFindTableInfo(_v_,_t_)     ((LPDBTABLE) NULL)
#endif

#if BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT>0
 #define InlineFindTableMap(_t_)          (&tables[_t_])
#else
 #define InlineFindTableMap(_t_)          ((LPTBLMAP) NULL)
#endif

#if BASE_TBL_COUNT+TBL_COUNT>0 && HAS_REVISIONS
 #define InlineFindTableRev(_v_)          ((_v_)->rev)
#else
 #define InlineFindTableRev(_v_)          ((LPREVISION) NULL)
#endif

#if TBL_COUNT>0
 #define InlineFindTableSelection(_v_,_t_)   (NULL==(_v_)->pViewSelection ? NULL : &(_v_)->pViewSelection->tables[_t_])
#else
 #define InlineFindTableSelection(_v_,_t_)   ((PTABLESELECTION) NULL)
#endif

#if BASE_TBL_COUNT+TBL_COUNT+CALC_TBL_COUNT==0
 #define InlineFindTableWidth(_v_,_t_)    0
#elif defined(STUB_VIEW)
 #define InlineFindTableWidth(_v_,_t_)    (FindTableMapV ((_v_), (_t_))->table->wRecordLength)
#else
 #define InlineFindTableWidth(_v_,_t_) \
    ((_t_)>=BASE_TBL_COUNT+TBL_COUNT ? \
       FindTableMapV ((_v_), (_t_))->table->wRecordLength : \
       FindTableInfo ((_v_), (_t_))->wRecordLength)
#endif

#define InlineMapStubToTableHandle(_v_,_h_)  (_h_)
#define InlineMapToInternalComposite(_c_)    (_c_)
#define InlineMapToNewFieldIndex(_f_)        (_f_)

#define InlineMaxDatabaseError(_p_,_d_) { \
   if ( !DB_ERRNUM_IS_FAULTLESS (_d_) && DB_ERRNUM_IS_SUCCESS (* (_p_)) ) \
      * (_p_) = _d_; \
}

#define InlineMaxError(_p_,_e_) { \
   if ( !ERRNUM_IS_FAULTLESS (_e_) && ERRNUM_IS_SUCCESS (* (_p_)) ) \
      * (_p_) = _e_; \
}

#define InlineValidIndexV(_v_,_f_) \
   (IDX_IN_DOMAIN((_f_)) && DoFindFieldMapV ((_v_), (_f_))->tblNo>=0)



// Definitions for compatibility with pre-existing call-out code using these helpers

#if !(defined DoFindFieldMapV || defined DoValidIndexV)
 #define FindFieldDef(_f_)                FindFieldDefV (NULL, (_f_))
 #define ValidIndex(_f_)                  ValidIndexV (NULL, (_f_))
#endif

#if !defined DoFindFieldIndexV
 #define FindFieldIndex(_f_)              FindFieldIndexV (NULL, (_f_))
#endif

#if !defined DoFindFieldMapV
 #define FindFieldMap(_f_)                FindFieldMapV (NULL, (_f_))
#endif



// Default definitions of the structure dereferencing override functions

#if !defined(DoFindCmp)
 #define DoFindCmp(_v_,_c_)               InlineFindCmp((_v_),(_c_))
#endif

#if !defined(DoFindCmpDef)
 #define DoFindCmpDef(_c_)                InlineFindCmpDef((_c_))
#endif

#if !defined(DoFindCmpField)
 #define DoFindCmpField(_v_,_c_,_f_)      InlineFindCmpField((_v_),(_c_),(_f_))
#endif

#if !defined(DoFindCmpForeign)
 #define DoFindCmpForeign(_v_,_f_)        InlineFindCmpForeign((_v_),(_f_))
#endif

#if !defined(DoFindCmpKey)
 #define DoFindCmpKey(_v_,_c_)            InlineFindCmpKey((_v_),(_c_))
#endif

#if !defined(DoFindCmpName)
 #define DoFindCmpName(_c_)               InlineFindCmpName((_c_))
#endif

#if !defined(DoFindCmpNotify)
 #define DoFindCmpNotify(_v_,_c_)         InlineFindCmpNotify((_v_),(_c_))
#endif

#if !defined(DoFindDetailMap)
 #define DoFindDetailMap()                InlineFindDetailMap()
#endif

#if !defined(DoFindFieldIndexV)
 #define DoFindFieldIndexV(_v_,_f_)       InlineFindFieldIndex((_f_))
#endif

#if !defined(DoFindFieldMapV)
 #define DoFindFieldMapV(_v_,_f_)         InlineFindFieldMap((_f_))
#endif

#if !defined(DoFindFieldValue)
 #define DoFindFieldValue(_v_,_f_)        InlineFindFieldValue((_v_),(_f_))
#endif

#if !defined(DoFindGenStub)
 #define DoFindGenStub(_v_,_c_)           InlineFindGenStub((_v_),(_c_))
#endif

#if !defined(DoFindImpOpen)
 #define DoFindImpOpen(_v_,_c_)           InlineFindImpOpen((_v_),(_c_))
#endif

#if !defined(DoFindImpRead)
 #define DoFindImpRead(_v_,_c_)           InlineFindImpRead((_v_),(_c_))
#endif

#if !defined(DoFindKeyDef)
 #define DoFindKeyDef(_k_)                InlineFindKeyDef((_k_))
#endif

#if !defined(DoFindPermissionMap)
 #define DoFindPermissionMap()            InlineFindPermissionMap()
#endif

#if !defined(DoFindRecord)
 #define DoFindRecord(_v_)                InlineFindRecord((_v_))
#endif

#if !defined(DoFindRecordNotify)
 #define DoFindRecordNotify(_v_)          InlineFindRecordNotify((_v_))
#endif

#if !defined(DoFindRecordRead)
 #define DoFindRecordRead(_v_)            InlineFindRecordRead((_v_))
#endif

#if !defined(DoFindRecordTemp)
 #define DoFindRecordTemp(_v_)            InlineFindRecordTemp((_v_))
#endif

#if !defined(DoFindRevCache)
 #define DoFindRevCache(_v_)              InlineFindRevCache((_v_))
#endif

#if !defined(DoFindRevLevel)
 #define DoFindRevLevel(_v_,_l_)          InlineFindRevLevel((_v_),(_l_))
#endif

#if !defined(DoFindRevRekey)
 #define DoFindRevRekey(_v_,_l_)          InlineFindRevRekey((_v_),(_l_))
#endif

#if !defined(DoFindTableHandle)
 #define DoFindTableHandle(_v_)           InlineFindTableHandle((_v_))
#endif

#if !defined(DoFindTableInfo)
 #define DoFindTableInfo(_v_,_t_)         InlineFindTableInfo((_v_),(_t_))
#endif

#if !defined(DoFindTableMap)
 #define DoFindTableMap(_t_)              InlineFindTableMap((_t_))
#endif

#if !defined(DoFindTableMapV)
 #define DoFindTableMapV(_v_,_t_)         InlineFindTableMap((_t_))
#endif

#if !defined(DoFindTableRev)
 #define DoFindTableRev(_v_)              InlineFindTableRev((_v_))
#endif

#if !defined(DoFindTableSelection)
 #define DoFindTableSelection(_v_,_t_)    InlineFindTableSelection((_v_),(_t_))
#endif

#if !defined(DoFindTableWidth)
 #define DoFindTableWidth(_v_,_t_)        InlineFindTableWidth((_v_),(_t_))
#endif

#if !defined(DoMapStubToTableHandle)
 #define DoMapStubToTableHandle(_v_,_h_)  InlineMapStubToTableHandle((_v_),(_h_))
#endif

#if !defined(DoMapToInternalComposite)
 #define DoMapToInternalComposite(_c_)    InlineMapToInternalComposite((_c_))
#endif

#if !defined(DoMapToNewFieldIndex)
 #define DoMapToNewFieldIndex(_f_)        InlineMapToNewFieldIndex((_f_))
#endif

#if !defined(DoMaxDatabaseError)
 #define DoMaxDatabaseError(_p_,_x_)      { ERRNUM _d_ = (_x_); InlineMaxDatabaseError ((_p_),_d_); }
#endif

#if !defined(DoMaxError)
 #define DoMaxError(_p_,_x_)              { ERRNUM _e_ = (_x_); InlineMaxError ((_p_),_e_); }
#endif

#if !defined(DoValidIndexV)
 #define DoValidIndexV(_v_,_f_)           InlineValidIndexV((_v_),(_f_))
#endif



// Definitions of the structure dereferencing functions when inline
#if !defined(DO_HELPERSOUTOFLINE)
 #define FindCmp(_v_,_c_)                 DoFindCmp((_v_),(_c_))
 #define FindCmpDef(_c_)                  DoFindCmpDef((_c_))
 #define FindCmpField(_v_,_c_,_f_)        DoFindCmpField((_v_),(_c_),(_f_))
 #define FindCmpForeign(_v_,_f_)          DoFindCmpForeign((_v_),(_f_))
 #define FindCmpKey(_v_,_c_)              DoFindCmpKey((_v_),(_c_))
 #define FindCmpName(_c_)                 DoFindCmpName((_c_))
 #define FindCmpNotify(_v_,_c_)           DoFindCmpNotify((_v_),(_c_))
 #define FindDetailMap()                  DoFindDetailMap()
 #define FindFieldIndexV(_v_,_f_)         DoFindFieldIndexV((_v_),(_f_))
 #define FindFieldMapV(_v_,_f_)           DoFindFieldMapV((_v_),(_f_))
 #define FindFieldValue(_v_,_f_)          DoFindFieldValue((_v_),(_f_))
 #define FindGenStub(_v_,_c_)             DoFindGenStub((_v_),(_c_))
 #define FindImpOpen(_v_,_c_)             DoFindImpOpen((_v_),(_c_))
 #define FindImpRead(_v_,_c_)             DoFindImpRead((_v_),(_c_))
 #define FindKeyDef(_k_)                  DoFindKeyDef((_k_))
 #define FindPermissionMap()              DoFindPermissionMap()
 #define FindRecord(_v_)                  DoFindRecord((_v_))
 #define FindRecordNotify(_v_)            DoFindRecordNotify((_v_))
 #define FindRecordRead(_v_)              DoFindRecordRead((_v_))
 #define FindRecordTemp(_v_)              DoFindRecordTemp((_v_))
 #define FindRevCache(_v_)                DoFindRevCache((_v_))
 #define FindRevLevel(_v_,_l_)            DoFindRevLevel((_v_),(_l_))
 #define FindRevRekey(_v_,_l_)            DoFindRevRekey((_v_),(_l_))
 #define FindTableMap(_t_)                DoFindTableMap((_t_))
 #define FindTableMapV(_v_,_t_)           DoFindTableMapV((_v_),(_t_))
 #define FindTableHandle(_v_)             DoFindTableHandle((_v_))
 #define FindTableInfo(_v_,_t_)           DoFindTableInfo((_v_),(_t_))
 #define FindTableRev(_v_)                DoFindTableRev((_v_))
 #define FindTableSelection(_v_,_t_)      DoFindTableSelection((_v_),(_t_))
 #define FindTableWidth(_v_,_t_)          DoFindTableWidth((_v_),(_t_))
 #define MapStubToTableHandle(_v_,_h_)    DoMapStubToTableHandle((_v_),(_h_))
 #define MapToInternalComposite(_c_)      DoMapToInternalComposite((_c_))
 #define MapToNewFieldIndex(_f_)          DoMapToNewFieldIndex((_f_))
 #define MaxDatabaseError(_p_,_x_)        DoMaxDatabaseError((_p_),(_x_))
 #define MaxError(_p_,_x_)                DoMaxError((_p_),(_x_))
 #define ValidIndexV(_v_,_f_)             DoValidIndexV((_v_),(_f_))
#endif



// Macro definitions of call-outs when they are not otherwise defined

#if !defined(DO_APPLYHEADERFIELDS) && !defined(DO_HEADERETC)
 #define ApplyHeaderFields(x,y)        (ERRNUM_SUCCESS)
#endif

#if !defined(DO_ATTRIBETC)
 #define AttribClear(v,f,b)            ((v)->alAttributes[IDXIDX((f))]&=~(b))
 #define AttribGet(v,f)                ((v)->alAttributes[IDXIDX((f))])
 #define AttribPut(v,f,b)              ((v)->alAttributes[IDXIDX((f))]=(b))
 #define AttribSet(v,f,b)              ((v)->alAttributes[IDXIDX((f))]|=(b))
 #define AttribTest(v,f,b)             ((v)->alAttributes[IDXIDX((f))]&(b))
#endif

#if SUBCLASS_LEVEL==NOT_SUBCLASS
 #define BaseNotifyFire(W,X,Y,Z)       NotifyFire ((W),(X),(Y),(Z))
#else
 #define BaseNotifyFire(W,X,Y,Z)       (ERRNUM_SUCCESS)
#endif

#if !defined(DO_CALCULATEFIELDS)
 #define CalculateFields(x)            (ERRNUM_SUCCESS)
#endif

#if !defined(DO_COMPOSEETC)
 #define ComposeEtc(x)                 (ERRNUM_SUCCESS)
#endif

#if !defined(DO_CONCURRENCYETC)
 #define ConcurrencyEtc(x,y)           (DBS_SUCCESS)
#endif

#if !defined(DO_CREATEETC)
 #define CreateEtc(x)                  (ERRNUM_SUCCESS)
#endif

#if !defined(DO_DELETEVALID)
 #define DeleteValid(x)                (ERRNUM_SUCCESS)
#endif

#if !defined(DO_GENERATEKEY) && !defined (DO_GENERATEKEYDELAYED)
 #define GenerateKey(x)                (ERRNUM_SUCCESS)
#endif

#if !defined(DO_GENERATEKEYDELAYED)
 #define GenerateKeyDelayed(x,y)       GenerateKey ((x))
#else
 #define GenerateKeyDelayed(x,y)       GenerateKey ((x), (y))
#endif

#if !defined(DO_GETETC)
 #define GetEtc(x,y,z,u)               (ERRNUM_SUCCESS)
#endif

#if !defined(DO_HEADERETC)
 #define HeaderEtc(x,y,z,u,v,w)        (ERRNUM_SUCCESS)
#endif

#if !defined(DO_INITFIELDSTRUCTETC)
 #define InitFieldStructEtc(x,y)       (ERRNUM_SUCCESS)
#endif

#if !defined(DO_INITNONBLANKFIELDS)
 #define InitNonBlankFields(x)         (ERRNUM_SUCCESS)
#endif

#if !defined(DO_LIBMAINETC)
 #define LibMainEtc(x,y,z,u)           (1)
#endif

#if !defined(DO_NOTIFYQUEUEFIELDVALUE)
 #define NotifyQueueFieldValue(x,y,z)  (ERRNUM_SUCCESS)
 #define DO_NOTIFYQUEUEFIELDVALUE      0
#else
 #undef DO_NOTIFYQUEUEFIELDVALUE
 #define DO_NOTIFYQUEUEFIELDVALUE      1
#endif

#if !defined(DO_OPENETC)
 #define OpenEtc(x)                    (ERRNUM_SUCCESS)
#endif

#if !defined(DO_PREPOSTETC)
 #define PrePostEtc(x,y,z)             (POST_DONE)
#endif

#if !defined(DO_PROCESSETC)
 #define ProcessEtc(x)                 (ERRNUM_SUCCESS)
#endif

#if !defined(DO_REKEYEDREVISION)
 #define RekeyedRevision(x,y,z,u,v)    (ERRNUM_SUCCESS)
#endif

#if !defined(DO_REVERSEHEADERFIELDS) && !defined(DO_HEADERETC)
 #define ReverseHeaderFields(x,y)      (ERRNUM_SUCCESS)
#endif

#if !defined(DO_REVPOSTETC)
 #define revPostEtc(x,y,z)             (DBS_SUCCESS)
#endif

#if !defined(DO_ROTOENTRYETC)
 #define rotoEntryEtc(v,length)        (BaseRotoEntry (v, length))
#endif

#if !defined(DO_SAVEHEADERFIELDS) && !defined(DO_HEADERETC)
 #define SaveHeaderFields(x)           (ERRNUM_SUCCESS)
#endif

#if !defined(DO_VALIDATEFIELDDEPENDENCIES)
 #define ValidateFieldDependencies(x)  (0)
#endif

#if !defined(DO_VALIDATEKEYS)
 #define ValidateKeys(x,y)             (TRUE)
#endif



// Placeholders for structures when undefined

#if HCHY_CMP_COUNT+DMND_CMP_COUNT+IMP_CMP_COUNT==0
 #define hierarchyKeyMap               ((LPKEYMAP) NULL)
#endif

#if SUBCLASS_LEVEL==NOT_SUBCLASS
 #define subCmpName                    ((LPSTR) NULL)
#endif



//////////////////////////////////////////////////////////////////////////////
// Obsolesced functions

#define  ErrorMapDatabaseToExtended(LINK,E)  rvMapDatabaseErrorToExtended((LINK),(E))
#define  ErrorMapExtendedToOld(OP,E)         rvMapExtendedErrorToOld((OP),(E))
#define  ErrorMapFilterToDatabase(OP,F)      rvMapFilterErrorToDatabase((OP),(F))
#define  ErrorMapFilterToExtended(OP,E)      rvMapFilterErrorToExtended((OP),(E))
#define  ErrorMapViewToDatabase(OP,E)        rvMapViewErrorToDatabase((OP),(E))
#define  ErrorMapViewToExtended(OP,E)        rvMapViewErrorToExtended((OP),(E))
#define  ErrorMapViewToFilter(OP,E)          rvMapViewErrorToFilter((OP),(E))
#define  ReportBaseError(p,q,r,s,t)          ReportErrorViaPIB ((p),(q),(r),(s),(t))



//////////////////////////////////////////////////////////////////////////////
//
// A plethora of parameterized macros for making a variety of tasks simpler
//
//////////////////////////////////////////////////////////////////////////////



// DE/ALLOCATE_STRUCT: C/C++ compatible memory management; under C++ manages objects
#if !defined(__cplusplus)
 #define ALLOCATE_STRUCT(p_p,t_t)   *(p_p) = (t_t *) memAlloc (sizeof (t_t))
 #define DEALLOCATE_STRUCT(p)       memFree ((p))
#else
 #define ALLOCATE_STRUCT(p_p,t_t)   *(p_p) = new (std::nothrow) t_t
 #define DEALLOCATE_STRUCT(p)       delete (p)
#endif

// fileErrorV: wrapper allowing old fileError behaviour
#if !defined(DO_OLDFILEERROR)
 #define fileErrorV(v_v,d_d)  dbErrorV ((v_v), (d_d))
#else
 #define fileErrorV(v_v,d_d)  fileError ((v_v)->wLinkNo, (v_v)->hpib, (d_d))
#endif



// Determine the number of elements of an array
#define  ELEMENTS_OF(array)      (sizeof (array)/sizeof (*array))



///////////////////////////////////////////////////////////////////////////////
// Checking of return codes. Their use permits you to structure code to have
// a largely linear flow, such that if you reach a certain point you are
// guaranteed no errors have occurred. Thus you can avoid if/else constructs,
// and especially their nesting, which can quickly complicate logic. For an
// example refer below to the comments on the viewGet/viewPut helper macros.



// Helper macros to report the code, file, and line at which an error occurred
#if !defined(ACCPAC_DEBUG)
 #define REPORT_CALL_ERROR(E,EX)
 #define REPORT_DBCALL_ERROR(D,EX)
#else
 #define REPORT_CALL_ERROR(E,EX) \
    rvspyPrint ("ERRNUM #%d IN '%s' LINE #%d EXECUTING '%s'", \
                (E), __FILE__, __LINE__, #EX );
 #define REPORT_DBCALL_ERROR(D,EX) \
    rvspyPrint ("DB_ERRNUM #%d IN '%s' LINE #%d EXECUTING '%s'", \
                (D), __FILE__, __LINE__, #EX );
#endif



// Accumulate error status, and return it if in error
#define CHECK_CALL(E,EX) { \
   MaxError (&(E), (EX)); \
   if ( ERRNUM_IS_FAILURE ((E)) ) { \
      REPORT_CALL_ERROR ((E),EX); \
      return (E); \
   } \
}

// Accumulate error status, and return if in error
#define CHECK_CALL_NOSTATUS(E,EX) { \
   MaxError (&(E), (EX)); \
   if ( ERRNUM_IS_FAILURE ((E)) ) { \
      REPORT_CALL_ERROR ((E),EX); \
      return; \
   } \
}

// Accumulate error status, and return FALSE if in error
#define CHECK_CALL_BOOLEAN(E,EX) { \
   MaxError (&(E), (EX)); \
   if ( ERRNUM_IS_FAILURE ((E)) ) { \
      REPORT_CALL_ERROR ((E),EX); \
      return FALSE; \
   } \
}

// Accumulate error status, and go to label if in error
#define CHECK_CALL_GOTO(E,L,EX) { \
   MaxError (&(E), (EX)); \
   if ( ERRNUM_IS_FAILURE ((E)) ) { \
      REPORT_CALL_ERROR ((E),EX); \
      goto L; \
   } \
}

// Accumulate error status, and break if in error
#define CHECK_CALL_BREAK(E,EX) { \
   MaxError (&(E), (EX)); \
   if ( ERRNUM_IS_FAILURE ((E)) ) { \
      REPORT_CALL_ERROR ((E),EX); \
      break; \
   } \
}



//////////////////////////////////////////////////////////////////////////////
// Checking of return codes for fetch or read calls. EOF is not considered
// an error in these cases



// Accumulate error status, return it if in error, and break loop if EOF
#define CHECK_FETCH(E,EX) { \
   ERRNUM f = (EX); \
   if ( ERRNUM_IS_FAILURE (f) ) { \
      if ( f!=ERRNUM_RECORD_NO_MORE_DATA && \
           f!=ERRNUM_RECORD_NOT_FOUND && \
           f!=OLD_ERRNUM_RECORD_NOT_FOUND ) { \
         REPORT_CALL_ERROR (f,EX); \
         return f; \
      } \
      break; \
   } \
   MaxError (&(E), f); \
}

// Accumulate error status, return it if in error, and set flag if !EOF
#define CHECK_FETCH_UNROLL(E,FL,EX) { \
   ERRNUM f = (EX); \
   if ( ERRNUM_IS_SUCCESS (f) ) { \
      (FL) = TRUE; \
      MaxError (&(E), f); \
   } else { \
      if ( f!=ERRNUM_RECORD_NO_MORE_DATA && \
           f!=ERRNUM_RECORD_NOT_FOUND && \
           f!=OLD_ERRNUM_RECORD_NOT_FOUND ) { \
         REPORT_CALL_ERROR (f,EX); \
         return f; \
      } \
      (FL) = FALSE; \
   } \
}

// Accumulate error status, return it if in error, and break loop if EOF
#define CHECK_FETCH_IGNORE(E,EX) { \
   ERRNUM f = (EX); \
   if ( f!=ERRNUM_RECORD_NO_MORE_DATA && \
        f!=OLD_ERRNUM_RECORD_NOT_FOUND && \
        f!=ERRNUM_RECORD_NOT_FOUND ) { \
      RVSPYTRACE ("CHECK_FETCH_IGNORE"); \
      REPORT_CALL_ERROR (f,EX); \
      MaxError (&(E), f); \
   } \
}

// Accumulate error status, goto a label if in error, and break loop if EOF
#define CHECK_FETCH_GOTO(E,L,EX) { \
   ERRNUM f = (EX); \
   if ( ERRNUM_IS_FAILURE (f) ) { \
      if ( f!=ERRNUM_RECORD_NO_MORE_DATA && \
           f!=ERRNUM_RECORD_NOT_FOUND && \
           f!=OLD_ERRNUM_RECORD_NOT_FOUND ) { \
         REPORT_CALL_ERROR (f,EX); \
         goto L; \
      } \
      break; \
   } \
   MaxError (&(E), f); \
}



//////////////////////////////////////////////////////////////////////////////
// viewGet and viewPut usage aids. Pseudo-prototypes are given before each.
// The "token" type is a C token used by the preprocessor for pasting.
// The intent of these macros is 3-fold:
//
//    1) to let you write put/get calls as 1-liners, simplifying maintenance
//    2) to be type-safe, thereby letting the compiler help you
//    3) add helpful information to the RVSPY log naming the field and operation
//
// For example, in combination with the return checking macros,
// the following expression:
//
//    CHECK_CALL (e, VIEW_GET_BOOLEAN (BKACCT, MULTICUR, bkacct, multicur));
//
// when compiled for debugging expands (approximately) to:
//
//    {
//       ReportString ("VIEW_GET_STRING(BKACCT.MULTICUR)");
//       {
//          ERRNUM _e_ = viewGetBoolean (bkacct->rvh, bkacct->view, BKACCT_IDX(MULTICUR), &multicur);
//
//          if ( !(_e_==0 && (e==0 || (e<0 || e==10))) )
//             e = _e_;
//       }
//       if ( e>0 && e!=10 ) {
//          rvspyPrint ("ERRNUM #%d IN '%s' LINE #%d EXECUTING '%s'",
//                      e, "BKCHK1.C", 526,
//                      "viewGetBoolean (bkacct->rvh, bkacct->view, BKACCT_IDX(MULTICUR), &multicur)");
//          return e;
//       }
//    }
//
// or when compiled for release expands (approximately) to:
//
//    {
//       ERRNUM _e_ = viewGetBoolean (bkacct->rvh, bkacct->view, BKACCT_IDX(MULTICUR), &multicur);
//
//       if ( !(_e_==0 && (e==0 || (e<0 || e==10))) )
//          e = _e_;
//    }
//    if ( e>0 && e!=10 ) {
//       return e;
//    }



// Helper macro used below to report "OPERATION VIEW.FIELD"
#define REPORT_FIELD(op,vn,id)   RVSPYTRACE (op "(" #vn "." #id ")")



// Helper macro used below to find the buffer size. It tries to use sizeof(),
// but if it looks like a pointer, then it uses the size constant
#define LIMIT_FIELD(siz,ptr) ( \
   sizeof((ptr))==sizeof(void*) ? \
      (siz) : \
      ((siz)<sizeof((ptr)) ? \
         (siz) : \
         sizeof((ptr))))

// Same as above, except it assumes the buffer is 1 character longer than the
// actual datum, in order to receive a NULL-terminated string
#define LIMIT_STRING_FIELD(siz,ptr) ( \
   sizeof((ptr))==sizeof(void*) ? \
      (siz) : \
      ((siz)<sizeof((ptr))-1 ? \
         (siz) : \
         sizeof((ptr))-1))



// ERRNUM VIEW_PUT (token view, token field, LPVIEWDEF viewdef, LPVOID data, BOOL validate);
#define VIEW_PUT(vn,id,vd,ptr,ver) ( \
   REPORT_FIELD("VIEW_PUT",vn,id), \
   viewPut ((vd)->rvh, (vd)->view, \
            vn##_IDX(id), (char *) (ptr), vn##_SIZ(id), (ver)))

// ERRNUM VIEW_PUT_BOOLEAN (token view, token field, LPVIEWDEF viewdef, DBSBOOL data, BOOL validate);
#define VIEW_PUT_BOOLEAN(vn,id,vd,val,ver) ( \
   REPORT_FIELD("VIEW_PUT_BOOLEAN",vn,id), \
   viewPutBoolean ((vd)->rvh, (vd)->view, vn##_IDX(id), (val), (ver)))

// ERRNUM VIEW_PUT_INTEGER (token view, token field, LPVIEWDEF viewdef, DBSINT data, BOOL validate);
#define VIEW_PUT_INTEGER(vn,id,vd,val,ver) ( \
   REPORT_FIELD("VIEW_PUT_INTEGER",vn,id), \
   viewPutInteger ((vd)->rvh, (vd)->view, vn##_IDX(id), (val), (ver)))

// ERRNUM VIEW_PUT_LONG (token view, token field, LPVIEWDEF viewdef, DBSLONG data, BOOL validate);
#define VIEW_PUT_LONG(vn,id,vd,val,ver) ( \
   REPORT_FIELD("VIEW_PUT_LONG",vn,id), \
   viewPutLong ((vd)->rvh, (vd)->view, vn##_IDX(id), (val), (ver)))

// ERRNUM VIEW_PUT_REAL (token view, token field, LPVIEWDEF viewdef, DBSREAL data, BOOL validate);
#define VIEW_PUT_REAL(vn,id,vd,val,ver) ( \
   REPORT_FIELD("VIEW_PUT_REAL",vn,id), \
   viewPutReal ((vd)->rvh, (vd)->view, vn##_IDX(id), (val), (ver)))



// ERRNUM VIEW_GET (token view, token field, LPVIEWDEF viewdef, LPVOID data);
#define VIEW_GET(vn,id,vd,ptr) ( \
   REPORT_FIELD("VIEW_GET",vn,id), \
   viewGet ((vd)->rvh, (vd)->view, vn##_IDX(id), (char *) (ptr), \
            LIMIT_FIELD(vn##_SIZ(id), (ptr))))

// ERRNUM VIEW_GET_BOOLEAN (token view, token field, LPVIEWDEF viewdef, DBSBOOL data);
#define VIEW_GET_BOOLEAN(vn,id,vd,var) ( \
   REPORT_FIELD("VIEW_GET_BOOLEAN",vn,id), \
   viewGetBoolean ((vd)->rvh, (vd)->view, vn##_IDX(id), &(var)))

// ERRNUM VIEW_GET_INTEGER (token view, token field, LPVIEWDEF viewdef, DBSINT data);
#define VIEW_GET_INTEGER(vn,id,vd,var) ( \
   REPORT_FIELD("VIEW_GET_INTEGER",vn,id), \
   viewGetInteger ((vd)->rvh, (vd)->view, vn##_IDX(id), &(var)))

// ERRNUM VIEW_GET_LONG (token view, token field, LPVIEWDEF viewdef, DBSLONG data);
#define VIEW_GET_LONG(vn,id,vd,var) ( \
   REPORT_FIELD("VIEW_GET_LONG",vn,id), \
   viewGetLong ((vd)->rvh, (vd)->view, vn##_IDX(id), &(var)))

// ERRNUM VIEW_GET_REAL (token view, token field, LPVIEWDEF viewdef, DBSREAL data);
#define VIEW_GET_REAL(vn,id,vd,var) ( \
   REPORT_FIELD("VIEW_GET_REAL",vn,id), \
   viewGetReal ((vd)->rvh, (vd)->view, vn##_IDX(id), &(var)))

// ERRNUM VIEW_GET_STRING (token view, token field, LPVIEWDEF viewdef, LPSTR data);
#define VIEW_GET_STRING(vn,id,vd,ptr) ( \
   REPORT_FIELD("VIEW_GET_STRING",vn,id), \
   viewGetString ((vd)->rvh, (vd)->view, vn##_IDX(id), (ptr), \
                  LIMIT_STRING_FIELD(vn##_SIZ(id), (ptr))))



// BOOL PARAM_GET (LPV lpv, token view, token field, LPVOID data);
#define PARAM_GET(vh,vn,id,ptr) ( \
   REPORT_FIELD("PARAM_GET",vn,id), \
   paramGet ((vh)->hpib, (vh)->wLinkNo, vn##_VIEW, vn##_IDX(id), \
             (ptr), LIMIT_FIELD(vn##_SIZ(id), (ptr))))

// BOOL PARAM_GET_BOOLEAN (LPV lpv, token view, token field, DBSBOOL data);
#define PARAM_GET_BOOLEAN(vh,vn,id,var) ( \
   REPORT_FIELD("PARAM_GET_BOOLEAN",vn,id), \
   paramGetBoolean ((vh)->hpib, (vh)->wLinkNo, vn##_VIEW, vn##_IDX(id), &(var)))

// BOOL PARAM_GET_INTEGER (LPV lpv, token view, token field, DBSINT data);
#define PARAM_GET_INTEGER(vh,vn,id,var) ( \
   REPORT_FIELD("PARAM_GET_INTEGER",vn,id), \
   paramGetInteger ((vh)->hpib, (vh)->wLinkNo, vn##_VIEW, vn##_IDX(id), &(var)))

// BOOL PARAM_GET_LONG (LPV lpv, token view, token field, DBSLONG data);
#define PARAM_GET_LONG(vh,vn,id,var) ( \
   REPORT_FIELD("PARAM_GET_LONG",vn,id), \
   paramGetLong ((vh)->hpib, (vh)->wLinkNo, vn##_VIEW, vn##_IDX(id), &(var)))

// BOOL PARAM_GET_REAL (LPV lpv, token view, token field, DBSREAL data);
#define PARAM_GET_REAL(vh,vn,id,var) ( \
   REPORT_FIELD("PARAM_GET_REAL",vn,id), \
   paramGetReal ((vh)->hpib, (vh)->wLinkNo, vn##_VIEW, vn##_IDX(id), &(var)))

// BOOL PARAM_GET_STRING (LPV lpv, token view, token field, LPSTR data);
#define PARAM_GET_STRING(vh,vn,id,ptr) ( \
   REPORT_FIELD("PARAM_GET_STRING",vn,id), \
   paramGetString ((vh)->hpib, (vh)->wLinkNo, vn##_VIEW, vn##_IDX(id), \
                   (ptr), LIMIT_STRING_FIELD(vn##_SIZ(id), (ptr))))



//////////////////////////////////////////////////////////////////////////////
// Database error-checking macros



// Accumulate error status, and return it if in error
#define CHECK_DBCALL(D,EX) { \
   MaxDatabaseError (&(D), (EX)); \
   if ( DB_ERRNUM_IS_FAILURE ((D)) ) { \
      REPORT_DBCALL_ERROR ((D),EX); \
      return (D); \
   } \
}

// Accumulate error status, and return if in error
#define CHECK_DBCALL_NOSTATUS(D,EX) { \
   MaxDatabaseError (&(D), (EX)); \
   if ( DB_ERRNUM_IS_FAILURE ((D)) ) { \
      REPORT_DBCALL_ERROR ((D),EX); \
      return; \
   } \
}

// Accumulate error status, and return FALSE if in error
#define CHECK_DBCALL_BOOLEAN(D,EX) { \
   MaxDatabaseError (&(D), (EX)); \
   if ( DB_ERRNUM_IS_FAILURE ((D)) ) { \
      REPORT_DBCALL_ERROR ((D),EX); \
      return FALSE; \
   } \
}

// Accumulate error status, and go to label if in error
#define CHECK_DBCALL_GOTO(D,L,EX) { \
   MaxDatabaseError (&(D), (EX)); \
   if ( DB_ERRNUM_IS_FAILURE ((D)) ) { \
      REPORT_DBCALL_ERROR ((D),EX); \
      goto L; \
   } \
}

// Accumulate error status, and break if in error
#define CHECK_DBCALL_BREAK(D,EX) { \
   MaxDatabaseError (&(D), (EX)); \
   if ( DB_ERRNUM_IS_FAILURE ((D)) ) { \
      REPORT_DBCALL_ERROR ((D),EX); \
      break; \
   } \
}



// Accumulate error status, return it if in error, and break loop if EOF
#define CHECK_DBFETCH(D,EX) { \
   DB_ERRNUM f = (EX); \
   if ( DB_ERRNUM_IS_FAILURE (f) ) { \
      if ( f!=DBS_NO_MORE_DATA && \
           f!=DBS_NOT_FOUND ) { \
         REPORT_DBCALL_ERROR (f,EX); \
         return f; \
      } \
      break; \
   } \
   MaxDatabaseError (&(D), f); \
}

// Accumulate error status, return it if in error, and set flag if !EOF
#define CHECK_DBFETCH_UNROLL(D,FL,EX) { \
   DB_ERRNUM f = (EX); \
   if ( DB_ERRNUM_IS_SUCCESS (f) ) { \
      (FL) = TRUE; \
      MaxDatabaseError (&(D), f); \
   } else { \
      if ( f!=DBS_NO_MORE_DATA && \
           f!=DBS_NOT_FOUND ) { \
         REPORT_DBCALL_ERROR (f,EX); \
         return f; \
      } \
      (FL) = FALSE; \
   } \
}

// Accumulate error status, goto label if in error, and break loop if EOF
#define CHECK_DBFETCH_GOTO(D,L,EX) { \
   DB_ERRNUM f = (EX); \
   if ( DB_ERRNUM_IS_FAILURE (f) ) { \
      if ( f!=DBS_NO_MORE_DATA && \
           f!=DBS_NOT_FOUND ) { \
         REPORT_DBCALL_ERROR (f,EX); \
         goto L; \
      } \
      break; \
   } \
   MaxDatabaseError (&(D), f); \
}



/////////////////////////////////////////////////////////////////////////////
// Experimental stuff
#define  VIEW_OP_TABLE_HANDLES   -10149
VIEWCALL viewTableHandles (LPVOID rvh, LPVOID view, INT count, LPWORD handles);
VIEWCALL scLoanTableHandles (LPV lpv, INT count, LPWORD handles);



/////////////////////////////////////////////////////////////////////////////
// Prototype declarations for the standard view services

VIEWCALL scLoanAttribs           (LPVOID lpView, LONG lField, LPLONG lpAttributes);
VIEWCALL scLoanBlkGet            (LPVOID lpView, INT lFields, LPLONG lFieldList, LPSHORT lpnSizeList, LPSTR lpsBuffer);
VIEWCALL scLoanBlkPut            (LPVOID lpView, INT lFields, LPLONG lFieldList, LPSHORT lpnSizeList, LPSTR lpsBuffer, BOOL bVerify);
VIEWCALL scLoanBrowse            (LPVOID lpView, LPSTR lpsExpression, BOOL bAscending);
VIEWCALL scLoanCancel            (LPVOID lpView);
VIEWCALL scLoanClose             (LPVOID lpView);
VIEWCALL scLoanCmpNames          (INT roto, LPSTR lpsCompositeNames, LPSHORT lpnCount);
VIEWCALL scLoanCompose           (LPVOID lpView, LPVIEWDEF lpvdefComposites);
VIEWCALL scLoanCreate            (HPIB hPIB, WORD wLinkNo);
VIEWCALL scLoanDelete            (LPVOID lpView);
VIEWCALL scLoanDirty             (LPVOID lpView, LPBOOL bChanged);
VIEWCALL scLoanDrop              (HPIB hPIB, WORD wLinkNo);
VIEWCALL scLoanExists            (LPVOID lpView, LPBOOL bExists);
VIEWCALL scLoanFetch             (LPVOID lpView);
VIEWCALL scLoanFetchLock         (LPVOID lpView);
VIEWCALL scLoanField             (LPVOID lpView, INT nFldNumber, LPSTR lpsFldName, LPLONG lField);
VIEWCALL scLoanFieldExists       (LPV view, LONG field, LP_A4W_FLAGS flags);
VIEWCALL scLoanFieldName         (LPV view, LONG field, LPSTR name, LPSTR desc, A4W_SIZE size);
VIEWCALL scLoanFields            (LPVOID lpView, LPSHORT lFields);
VIEWCALL scLoanFilterCount       (LPV view, LPSTR filter, A4W_FLAGS flags, LP_A4W_SIZE count);
VIEWCALL scLoanFilterDelete      (LPV view, LPSTR filter, A4W_FLAGS flags);
VIEWCALL scLoanFilterFetch       (LPV view, A4W_FLAGS flags);
VIEWCALL scLoanFilterSelect      (LPV view, INT key, LPSTR filter, A4W_FLAGS flags);
VIEWCALL scLoanGet               (LPVOID lpView, LONG lField, LPSTR buffer, INT nSize);
VIEWCALL scLoanInit              (LPVOID lpView);
VIEWCALL scLoanInsert            (LPVOID lpView);
VIEWCALL scLoanInstanceFieldList (LPV view, A4W_FLAGS flags, A4W_SIZE count, PLONG fields);
VIEWCALL scLoanInstanceNotify    (LPV view, A4W_NOTIFY_PROC notify, LPVOID context, A4W_FLAGS flags);
VIEWCALL scLoanInstanceOpen      (LPRVH rvh, HPIB PIB, WORD link, A4W_FLAGS flags, LPVOID extra, A4W_SIZE size, LPV FAR * view);
VIEWCALL scLoanInstanceProtocol  (LPV view, A4W_FLAGS flags, LP_A4W_FLAGS protocols, LP_A4W_SIZE count);
VIEWCALL scLoanInstanceSecurity  (LPV view, LP_A4W_FLAGS flags);
VIEWCALL scLoanKey               (LPVOID lpView, INT nKeyNo, LPSTR sName, LPSHORT lFields, LPLONG lplKeyFields);
VIEWCALL scLoanKeys              (LPVOID lpView, LPSHORT lpnKeys);
VIEWCALL scLoanName              (LPVOID lpView, LONG lField, LPSTR lpsName, LPSTR lpsDesc);
VIEWCALL scLoanOpen              (HPIB hPIB, WORD wLinkNo, LPVOID FAR * lpView);
VIEWCALL scLoanOrder             (LPVOID lpView, INT nKey);
VIEWCALL scLoanPost              (LPVOID lpView);
VIEWCALL scLoanPresents          (LPVOID lpView, LONG lField, LPSTR lpsMask, LPSHORT lpnList, LPSHORT lpnCount, LPVOID lpBuffer, INT nSize);
VIEWCALL scLoanProcess           (LPVOID lpView);
VIEWCALL scLoanPut               (LPVOID lpView, LONG lField, LPSTR lpsBuffer, INT nSize, BOOL bVerify);
VIEWCALL scLoanRead              (LPVOID lpView);
VIEWCALL scLoanReadLock          (LPVOID lpView);
VIEWCALL scLoanRecordClear       (LPV view);
VIEWCALL scLoanRecordGenerate    (LPV view, A4W_FLAGS flags);
VIEWCALL scLoanRevisionCancel    (LPV view, INT level);
VIEWCALL scLoanRevisionExists    (LPV view, INT level, LP_A4W_FLAGS flags);
VIEWCALL scLoanRevisionPost      (LPV view, INT level);
VIEWCALL scLoanRevisionRekey     (LPV lpv, LPVOID OldKey, LPVOID NewKey, INT size, A4W_FLAGS flags);
VIEWCALL scLoanRevisionUnposted  (LPV view, INT level, LP_A4W_FLAGS flags);
VIEWCALL scLoanSecurity          (HPIB hPIB, WORD wLinkNo, LPLONG lplPermissions);
VIEWCALL scLoanTableEmpty        (LPV view);
VIEWCALL scLoanType              (LPVOID lpView, LONG lField, LPTYPE lptype);
VIEWCALL scLoanUnLock            (LPVOID lpView);
VIEWCALL scLoanUpdate            (LPVOID lpView);
VIEWCALL scLoanVerify            (LPVOID lpView);
VIEWCALL scLoanVersionTemplate   (INT roto, LPSTR version, LPBCDDATE date);
VIEWCALL scLoanVersionAPI        (INT roto, LPSTR version);
VIEWCALL scLoanViewName          (HPIB pib, LPSTR name, INT size);
VIEWCALL scLoanViewTableCount    (INT roto, LPSHORT tables);
VIEWCALL scLoanViewTables        (INT roto, LPSTR tables, INT size);



/////////////////////////////////////////////////////////////////////////////
// Declarations for service routine overrides

VIEWCALL scLoanBaseAttribs           (LPVOID lpView, LONG lField, LPLONG lpAttributes);
VIEWCALL scLoanBaseBlkGet            (LPVOID lpView, INT lFields, LPLONG lFieldList, LPSHORT lpnSizeList, LPSTR lpsBuffer);
VIEWCALL scLoanBaseBlkPut            (LPVOID lpView, INT lFields, LPLONG lFieldList, LPSHORT lpnSizeList, LPSTR lpsBuffer, BOOL bVerify);
VIEWCALL scLoanBaseBrowse            (LPVOID lpView, LPSTR lpsExpression, BOOL bAscending);
VIEWCALL scLoanBaseCancel            (LPVOID lpView);
VIEWCALL scLoanBaseClose             (LPVOID lpView);
VIEWCALL scLoanBaseCmpNames          (INT roto, LPSTR lpsCompositeNames, LPSHORT lpnCount);
VIEWCALL scLoanBaseCompose           (LPVOID lpView, LPVIEWDEF lpvdefComposites);
VIEWCALL scLoanBaseCreate            (HPIB hPIB, WORD wLinkNo);
VIEWCALL scLoanBaseDelete            (LPVOID lpView);
VIEWCALL scLoanBaseDirty             (LPVOID lpView, LPBOOL bChanged);
VIEWCALL scLoanBaseDrop              (HPIB hPIB, WORD wLinkNo);
VIEWCALL scLoanBaseExists            (LPVOID lpView, LPBOOL bExists);
VIEWCALL scLoanBaseFetch             (LPVOID lpView);
VIEWCALL scLoanBaseFetchLock         (LPVOID lpView);
VIEWCALL scLoanBaseField             (LPVOID lpView, INT nFldNumber, LPSTR lpsFldName, LPLONG lField);
VIEWCALL scLoanBaseFieldExists       (LPV view, LONG field, LP_A4W_FLAGS flags);
VIEWCALL scLoanBaseFieldName         (LPV view, LONG field, LPSTR name, LPSTR desc, A4W_SIZE size);
VIEWCALL scLoanBaseFields            (LPVOID lpView, LPSHORT lFields);
VIEWCALL scLoanBaseFilterCount       (LPV view, LPSTR filter, A4W_FLAGS flags, LP_A4W_SIZE count);
VIEWCALL scLoanBaseFilterDelete      (LPV view, LPSTR filter, A4W_FLAGS flags);
VIEWCALL scLoanBaseFilterFetch       (LPV view, A4W_FLAGS flags);
VIEWCALL scLoanBaseFilterSelect      (LPV view, INT key, LPSTR filter, A4W_FLAGS flags);
VIEWCALL scLoanBaseGet               (LPVOID lpView, LONG lField, LPSTR buffer, INT nSize);
VIEWCALL scLoanBaseInit              (LPVOID lpView);
VIEWCALL scLoanBaseInsert            (LPVOID lpView);
VIEWCALL scLoanBaseInstanceFieldList (LPV view, A4W_FLAGS flags, A4W_SIZE count, PLONG fields);
VIEWCALL scLoanBaseInstanceNotify    (LPV view, A4W_NOTIFY_PROC notify, LPVOID context, A4W_FLAGS flags);
VIEWCALL scLoanBaseInstanceOpen      (LPRVH rvh, HPIB PIB, WORD link, A4W_FLAGS flags, LPVOID extra, A4W_SIZE size, LPV FAR * view);
VIEWCALL scLoanBaseInstanceProtocol  (LPV view, A4W_FLAGS flags, LP_A4W_FLAGS protocols, LP_A4W_SIZE count);
VIEWCALL scLoanBaseInstanceSecurity  (LPV view, LP_A4W_FLAGS flags);
VIEWCALL scLoanBaseKey               (LPVOID lpView, INT nKeyNo, LPSTR sName, LPSHORT lFields, LPLONG lplKeyFields);
VIEWCALL scLoanBaseKeys              (LPVOID lpView, LPSHORT lpnKeys);
VIEWCALL scLoanBaseName              (LPVOID lpView, LONG lField, LPSTR lpsName, LPSTR lpsDesc);
VIEWCALL scLoanBaseOpen              (HPIB hPIB, WORD wLinkNo, LPVOID FAR * lpView);
VIEWCALL scLoanBaseOrder             (LPVOID lpView, INT nKey);
VIEWCALL scLoanBasePost              (LPVOID lpView);
VIEWCALL scLoanBasePresents          (LPVOID lpView, LONG lField, LPSTR lpsMask, LPSHORT lpnList, LPSHORT lpnCount, LPVOID lpBuffer, INT nSize);
VIEWCALL scLoanBaseProcess           (LPVOID lpView);
VIEWCALL scLoanBasePut               (LPVOID lpView, LONG lField, LPSTR lpsBuffer, INT nSize, BOOL bVerify);
VIEWCALL scLoanBaseRead              (LPVOID lpView);
VIEWCALL scLoanBaseReadLock          (LPVOID lpView);
VIEWCALL scLoanBaseRecordClear       (LPV view);
VIEWCALL scLoanBaseRecordGenerate    (LPV view, A4W_FLAGS flags);
VIEWCALL scLoanBaseRevisionCancel    (LPV view, INT level);
VIEWCALL scLoanBaseRevisionExists    (LPV view, INT level, LP_A4W_FLAGS flags);
VIEWCALL scLoanBaseRevisionPost      (LPV view, INT level);
VIEWCALL scLoanBaseRevisionRekey     (LPV lpv, LPVOID OldKey, LPVOID NewKey, INT size, A4W_FLAGS flags);
VIEWCALL scLoanBaseRevisionUnposted  (LPV view, INT level, LP_A4W_FLAGS flags);
VIEWCALL scLoanBaseSecurity          (HPIB hPIB, WORD wLinkNo, LPLONG lplPermissions);
VIEWCALL scLoanBaseTableEmpty        (LPV view);
VIEWCALL scLoanBaseType              (LPVOID lpView, LONG lField, LPTYPE lptype);
VIEWCALL scLoanBaseUnLock            (LPVOID lpView);
VIEWCALL scLoanBaseUpdate            (LPVOID lpView);
VIEWCALL scLoanBaseVerify            (LPVOID lpView);

/////////////////////////////////////////////////////////////////////////////
// Declarations for the most basic service routines, which always return
// extended errors

VIEWCALL scLoanExtendedBaseAttribs           (LPVOID lpView, LONG lField, LPLONG lpAttributes);
VIEWCALL scLoanExtendedBaseBlkGet            (LPVOID lpView, INT lFields, LPLONG lFieldList, LPSHORT lpnSizeList, LPSTR lpsBuffer);
VIEWCALL scLoanExtendedBaseBlkPut            (LPVOID lpView, INT lFields, LPLONG lFieldList, LPSHORT lpnSizeList, LPSTR lpsBuffer, BOOL bVerify);
VIEWCALL scLoanExtendedBaseBrowse            (LPVOID lpView, LPSTR lpsExpression, BOOL bAscending);
VIEWCALL scLoanExtendedBaseCancel            (LPVOID lpView);
VIEWCALL scLoanExtendedBaseClose             (LPVOID lpView);
VIEWCALL scLoanExtendedBaseCmpNames          (INT roto, LPSTR lpsCompositeNames, LPSHORT lpnCount);
VIEWCALL scLoanExtendedBaseCompose           (LPVOID lpView, LPVIEWDEF lpvdefComposites);
VIEWCALL scLoanExtendedBaseCreate            (HPIB hPIB, WORD wLinkNo);
VIEWCALL scLoanExtendedBaseDelete            (LPVOID lpView);
VIEWCALL scLoanExtendedBaseDirty             (LPVOID lpView, LPBOOL bChanged);
VIEWCALL scLoanExtendedBaseDrop              (HPIB hPIB, WORD wLinkNo);
VIEWCALL scLoanExtendedBaseExists            (LPVOID lpView, LPBOOL bExists);
VIEWCALL scLoanExtendedBaseFetch             (LPVOID lpView);
VIEWCALL scLoanExtendedBaseFetchLock         (LPVOID lpView);
VIEWCALL scLoanExtendedBaseField             (LPVOID lpView, INT nFldNumber, LPSTR lpsFldName, LPLONG lField);
VIEWCALL scLoanExtendedBaseFieldExists       (LPV view, LONG field, LP_A4W_FLAGS flags);
VIEWCALL scLoanExtendedBaseFieldName         (LPV view, LONG field, LPSTR name, LPSTR desc, A4W_SIZE size);
VIEWCALL scLoanExtendedBaseFields            (LPVOID lpView, LPSHORT lFields);
VIEWCALL scLoanExtendedBaseFilterCount       (LPV view, LPSTR filter, A4W_FLAGS flags, LP_A4W_SIZE count);
VIEWCALL scLoanExtendedBaseFilterDelete      (LPV view, LPSTR filter, A4W_FLAGS flags);
VIEWCALL scLoanExtendedBaseFilterFetch       (LPV view, A4W_FLAGS flags);
VIEWCALL scLoanExtendedBaseFilterSelect      (LPV view, INT key, LPSTR filter, A4W_FLAGS flags);
VIEWCALL scLoanExtendedBaseGet               (LPVOID lpView, LONG lField, LPSTR buffer, INT nSize);
VIEWCALL scLoanExtendedBaseInit              (LPVOID lpView);
VIEWCALL scLoanExtendedBaseInsert            (LPVOID lpView);
VIEWCALL scLoanExtendedBaseInstanceFieldList (LPV view, A4W_FLAGS flags, A4W_SIZE count, PLONG fields);
VIEWCALL scLoanExtendedBaseInstanceNotify    (LPV view, A4W_NOTIFY_PROC notify, LPVOID context, A4W_FLAGS flags);
VIEWCALL scLoanExtendedBaseInstanceOpen      (LPRVH rvh, HPIB PIB, WORD link, A4W_FLAGS flags, LPVOID extra, A4W_SIZE size, LPV FAR * view);
VIEWCALL scLoanExtendedBaseInstanceProtocol  (LPV view, A4W_FLAGS flags, LP_A4W_FLAGS protocols, LP_A4W_SIZE count);
VIEWCALL scLoanExtendedBaseInstanceSecurity  (LPV view, LP_A4W_FLAGS flags);
VIEWCALL scLoanExtendedBaseKey               (LPVOID lpView, INT nKeyNo, LPSTR sName, LPSHORT lFields, LPLONG lplKeyFields);
VIEWCALL scLoanExtendedBaseKeys              (LPVOID lpView, LPSHORT lpnKeys);
VIEWCALL scLoanExtendedBaseName              (LPVOID lpView, LONG lField, LPSTR lpsName, LPSTR lpsDesc);
VIEWCALL scLoanExtendedBaseOpen              (HPIB hPIB, WORD wLinkNo, LPVOID FAR * lpView);
VIEWCALL scLoanExtendedBaseOrder             (LPVOID lpView, INT nKey);
VIEWCALL scLoanExtendedBasePost              (LPVOID lpView);
VIEWCALL scLoanExtendedBasePresents          (LPVOID lpView, LONG lField, LPSTR lpsMask, LPSHORT lpnList, LPSHORT lpnCount, LPVOID lpBuffer, INT nSize);
VIEWCALL scLoanExtendedBaseProcess           (LPVOID lpView);
VIEWCALL scLoanExtendedBasePut               (LPVOID lpView, LONG lField, LPSTR lpsBuffer, INT nSize, BOOL bVerify);
VIEWCALL scLoanExtendedBaseRead              (LPVOID lpView);
VIEWCALL scLoanExtendedBaseReadLock          (LPVOID lpView);
VIEWCALL scLoanExtendedBaseRecordClear       (LPV view);
VIEWCALL scLoanExtendedBaseRecordGenerate    (LPV view, A4W_FLAGS flags);
VIEWCALL scLoanExtendedBaseRevisionCancel    (LPV view, INT level);
VIEWCALL scLoanExtendedBaseRevisionExists    (LPV view, INT level, LP_A4W_FLAGS flags);
VIEWCALL scLoanExtendedBaseRevisionPost      (LPV view, INT level);
VIEWCALL scLoanExtendedBaseRevisionRekey     (LPV lpv, LPVOID OldKey, LPVOID NewKey, INT size, A4W_FLAGS flags);
VIEWCALL scLoanExtendedBaseRevisionUnposted  (LPV view, INT level, LP_A4W_FLAGS flags);
VIEWCALL scLoanExtendedBaseSecurity          (HPIB hPIB, WORD wLinkNo, LPLONG lplPermissions);
VIEWCALL scLoanExtendedBaseTableEmpty        (LPV view);
VIEWCALL scLoanExtendedBaseType              (LPVOID lpView, LONG lField, LPTYPE lptype);
VIEWCALL scLoanExtendedBaseUnLock            (LPVOID lpView);
VIEWCALL scLoanExtendedBaseUpdate            (LPVOID lpView);
VIEWCALL scLoanExtendedBaseVerify            (LPVOID lpView);

/////////////////////////////////////////////////////////////////////////////
// Declarations for the most basic service routines, which always return
// extended errors

VIEWCALL viewExtendedAttribs           (LPVOID rvh, LPVOID view, LONG field, LPLONG attributes);
VIEWCALL viewExtendedBlkGet            (LPVOID rvh, LPVOID view, INT fields, LPLONG fieldList, LPSHORT sizeList, LPVOID buffer);
VIEWCALL viewExtendedBlkPut            (LPVOID rvh, LPVOID view, INT fields, LPLONG fieldList, LPSHORT sizeList, LPVOID buffer, BOOL verify);
VIEWCALL viewExtendedBrowse            (LPVOID rvh, LPVOID view, LPSTR filter, BOOL ascending);
VIEWCALL viewExtendedCall              (LPVOID rvh, LPROTOVIEW comm, INT length);
VIEWCALL viewExtendedCallParam         (LPVOID rvh, INT op, LPVOID view, INT i, BOOL flag, LONG field, LPVOID p, LPVOID q, LPVOID r, LPVOID s, INT length, LPVOID extra);
VIEWCALL viewExtendedCancel            (LPVOID rvh, LPVOID view);
VIEWCALL viewExtendedClose             (LPVOID rvh, LPVOID view);
VIEWCALL viewExtendedCmpNames          (LPVOID rvh, LPSTR compositeNames, LPSHORT count);
VIEWCALL viewExtendedCompose           (LPVOID rvh, LPVOID view, LPVIEWDEF composites);
VIEWCALL viewExtendedCreate            (LPVOID rvh, HPIB PIB, WORD link);
VIEWCALL viewExtendedDelete            (LPVOID rvh, LPVOID view);
VIEWCALL viewExtendedDirty             (LPVOID rvh, LPVOID view, LPBOOL changed);
VIEWCALL viewExtendedDrop              (LPVOID rvh, HPIB PIB, WORD link);
VIEWCALL viewExtendedExists            (LPVOID rvh, LPVOID view, LPBOOL exists);
VIEWCALL viewExtendedFetch             (LPVOID rvh, LPVOID view);
VIEWCALL viewExtendedFetchLock         (LPVOID rvh, LPVOID view);
VIEWCALL viewExtendedField             (LPVOID rvh, LPVOID view, INT number, LPSTR name, LPLONG field);
VIEWCALL viewExtendedFieldExists       (LPRVH rvh, LPVOID view, LONG field, LP_A4W_FLAGS flags);
VIEWCALL viewExtendedFieldName         (LPRVH rvh, LPVOID view, LONG field, LPSTR name, LPSTR desc, A4W_SIZE size);
VIEWCALL viewExtendedFields            (LPVOID rvh, LPVOID view, LPSHORT fields);
VIEWCALL viewExtendedFilterCount       (LPRVH rvh, LPVOID view, LPSTR filter, A4W_FLAGS flags, LP_A4W_SIZE count);
VIEWCALL viewExtendedFilterDelete      (LPRVH rvh, LPVOID view, LPSTR filter, A4W_FLAGS flags);
VIEWCALL viewExtendedFilterFetch       (LPRVH rvh, LPVOID view, A4W_FLAGS flags);
VIEWCALL viewExtendedFilterSelect      (LPRVH rvh, LPVOID view, INT key, LPSTR filter, A4W_FLAGS flags);
VIEWCALL viewExtendedGet               (LPVOID rvh, LPVOID view, LONG field, LPVOID buffer, INT size);
VIEWCALL viewExtendedInit              (LPVOID rvh, LPVOID view);
VIEWCALL viewExtendedInsert            (LPVOID rvh, LPVOID view);
VIEWCALL viewExtendedInstanceFieldList (LPRVH rvh, LPVOID view, A4W_FLAGS flags, A4W_SIZE count, PLONG fields);
VIEWCALL viewExtendedInstanceNotify    (LPRVH rvh, LPVOID view, A4W_NOTIFY_PROC notify, LPVOID context, A4W_FLAGS flags);
VIEWCALL viewExtendedInstanceOpen      (LPRVH rvh, HPIB PIB, WORD link, A4W_FLAGS flags, LPVOID extra, A4W_SIZE size, LPVOID FAR * view);
VIEWCALL viewExtendedInstanceProtocol  (LPRVH rvh, LPVOID view, A4W_FLAGS flags, LP_A4W_FLAGS protocols, LP_A4W_SIZE count);
VIEWCALL viewExtendedInstanceSecurity  (LPRVH rvh, LPVOID view, LP_A4W_FLAGS flags);
VIEWCALL viewExtendedKey               (LPVOID rvh, LPVOID view, INT number, LPSTR name, LPSHORT fields, LPLONG keyFields);
VIEWCALL viewExtendedKeys              (LPVOID rvh, LPVOID view, LPSHORT keys);
VIEWCALL viewExtendedName              (LPVOID rvh, LPVOID view, LONG field, LPSTR name, LPSTR desc);
VIEWCALL viewExtendedOpen              (LPVOID rvh, HPIB PIB, WORD link, LPVOID FAR * view);
VIEWCALL viewExtendedOrder             (LPVOID rvh, LPVOID view, INT key);
VIEWCALL viewExtendedPost              (LPVOID rvh, LPVOID view);
VIEWCALL viewExtendedPresents          (LPVOID rvh, LPVOID view, LONG field, LPSTR mask, LPSHORT list, LPSHORT count, LPSTR strings, INT size);
VIEWCALL viewExtendedProcess           (LPVOID rvh, LPVOID view);
VIEWCALL viewExtendedPut               (LPVOID rvh, LPVOID view, LONG field, LPVOID buffer, INT size, BOOL verify);
VIEWCALL viewExtendedRead              (LPVOID rvh, LPVOID view);
VIEWCALL viewExtendedReadLock          (LPVOID rvh, LPVOID view);
VIEWCALL viewExtendedRecordClear       (LPRVH rvh, LPVOID view);
VIEWCALL viewExtendedRecordGenerate    (LPRVH rvh, LPVOID view, A4W_FLAGS flags);
VIEWCALL viewExtendedRevisionCancel    (LPRVH rvh, LPVOID view, INT level);
VIEWCALL viewExtendedRevisionExists    (LPRVH rvh, LPVOID view, INT level, LP_A4W_FLAGS flags);
VIEWCALL viewExtendedRevisionPost      (LPRVH rvh, LPVOID view, INT level);
VIEWCALL viewExtendedRevisionRekey     (LPRVH rvh, LPVOID lpv, LPVOID OldKey, LPVOID NewKey, INT size, A4W_FLAGS flags);
VIEWCALL viewExtendedRevisionUnposted  (LPRVH rvh, LPVOID view, INT level, LP_A4W_FLAGS flags);
VIEWCALL viewExtendedSecurity          (LPVOID rvh, HPIB PIB, WORD link, LPLONG permissions);
VIEWCALL viewExtendedTableEmpty        (LPRVH rvh, LPVOID view);
VIEWCALL viewExtendedType              (LPVOID rvh, LPVOID view, LONG field, LPTYPE type);
VIEWCALL viewExtendedUnLock            (LPVOID rvh, LPVOID view);
VIEWCALL viewExtendedUpdate            (LPVOID rvh, LPVOID view);
VIEWCALL viewExtendedVerify            (LPVOID rvh, LPVOID view);

/////////////////////////////////////////////////////////////////////////////
// Declarations for the most basic service routines, which always return
// extended errors

VIEWCALL viewOldAttribs           (LPVOID rvh, LPVOID view, LONG field, LPLONG attributes);
VIEWCALL viewOldBlkGet            (LPVOID rvh, LPVOID view, INT fields, LPLONG fieldList, LPSHORT sizeList, LPVOID buffer);
VIEWCALL viewOldBlkPut            (LPVOID rvh, LPVOID view, INT fields, LPLONG fieldList, LPSHORT sizeList, LPVOID buffer, BOOL verify);
VIEWCALL viewOldBrowse            (LPVOID rvh, LPVOID view, LPSTR filter, BOOL ascending);
VIEWCALL viewOldCall              (LPVOID rvh, LPROTOVIEW comm, INT length);
VIEWCALL viewOldCallParam         (LPVOID rvh, INT op, LPVOID view, INT i, BOOL flag, LONG field, LPVOID p, LPVOID q, LPVOID r, LPVOID s, INT length, LPVOID extra);
VIEWCALL viewOldCancel            (LPVOID rvh, LPVOID view);
VIEWCALL viewOldClose             (LPVOID rvh, LPVOID view);
VIEWCALL viewOldCmpNames          (LPVOID rvh, LPSTR compositeNames, LPSHORT count);
VIEWCALL viewOldCompose           (LPVOID rvh, LPVOID view, LPVIEWDEF composites);
VIEWCALL viewOldCreate            (LPVOID rvh, HPIB PIB, WORD link);
VIEWCALL viewOldDelete            (LPVOID rvh, LPVOID view);
VIEWCALL viewOldDirty             (LPVOID rvh, LPVOID view, LPBOOL changed);
VIEWCALL viewOldDrop              (LPVOID rvh, HPIB PIB, WORD link);
VIEWCALL viewOldExists            (LPVOID rvh, LPVOID view, LPBOOL exists);
VIEWCALL viewOldFetch             (LPVOID rvh, LPVOID view);
VIEWCALL viewOldFetchLock         (LPVOID rvh, LPVOID view);
VIEWCALL viewOldField             (LPVOID rvh, LPVOID view, INT number, LPSTR name, LPLONG field);
VIEWCALL viewOldFieldExists       (LPRVH rvh, LPVOID view, LONG field, LP_A4W_FLAGS flags);
VIEWCALL viewOldFieldName         (LPRVH rvh, LPVOID view, LONG field, LPSTR name, LPSTR desc, A4W_SIZE size);
VIEWCALL viewOldFields            (LPVOID rvh, LPVOID view, LPSHORT fields);
VIEWCALL viewOldFilterCount       (LPRVH rvh, LPVOID view, LPSTR filter, A4W_FLAGS flags, LP_A4W_SIZE count);
VIEWCALL viewOldFilterDelete      (LPRVH rvh, LPVOID view, LPSTR filter, A4W_FLAGS flags);
VIEWCALL viewOldFilterFetch       (LPRVH rvh, LPVOID view, A4W_FLAGS flags);
VIEWCALL viewOldFilterSelect      (LPRVH rvh, LPVOID view, INT key, LPSTR filter, A4W_FLAGS flags);
VIEWCALL viewOldGet               (LPVOID rvh, LPVOID view, LONG field, LPVOID buffer, INT size);
VIEWCALL viewOldInit              (LPVOID rvh, LPVOID view);
VIEWCALL viewOldInsert            (LPVOID rvh, LPVOID view);
VIEWCALL viewOldInstanceFieldList (LPRVH rvh, LPVOID view, A4W_FLAGS flags, A4W_SIZE count, PLONG fields);
VIEWCALL viewOldInstanceNotify    (LPRVH rvh, LPVOID view, A4W_NOTIFY_PROC notify, LPVOID context, A4W_FLAGS flags);
VIEWCALL viewOldInstanceOpen      (LPRVH rvh, HPIB PIB, WORD link, A4W_FLAGS flags, LPVOID extra, A4W_SIZE size, LPVOID FAR * view);
VIEWCALL viewOldInstanceProtocol  (LPRVH rvh, LPVOID view, A4W_FLAGS flags, LP_A4W_FLAGS protocols, LP_A4W_SIZE count);
VIEWCALL viewOldInstanceSecurity  (LPRVH rvh, LPVOID view, LP_A4W_FLAGS flags);
VIEWCALL viewOldKey               (LPVOID rvh, LPVOID view, INT number, LPSTR name, LPSHORT fields, LPLONG keyFields);
VIEWCALL viewOldKeys              (LPVOID rvh, LPVOID view, LPSHORT keys);
VIEWCALL viewOldName              (LPVOID rvh, LPVOID view, LONG field, LPSTR name, LPSTR desc);
VIEWCALL viewOldOpen              (LPVOID rvh, HPIB PIB, WORD link, LPVOID FAR * view);
VIEWCALL viewOldOrder             (LPVOID rvh, LPVOID view, INT key);
VIEWCALL viewOldPost              (LPVOID rvh, LPVOID view);
VIEWCALL viewOldPresents          (LPVOID rvh, LPVOID view, LONG field, LPSTR mask, LPSHORT list, LPSHORT count, LPSTR strings, INT size);
VIEWCALL viewOldProcess           (LPVOID rvh, LPVOID view);
VIEWCALL viewOldPut               (LPVOID rvh, LPVOID view, LONG field, LPVOID buffer, INT size, BOOL verify);
VIEWCALL viewOldRead              (LPVOID rvh, LPVOID view);
VIEWCALL viewOldReadLock          (LPVOID rvh, LPVOID view);
VIEWCALL viewOldRecordClear       (LPRVH rvh, LPVOID view);
VIEWCALL viewOldRecordGenerate    (LPRVH rvh, LPVOID view, A4W_FLAGS flags);
VIEWCALL viewOldRevisionCancel    (LPRVH rvh, LPVOID view, INT level);
VIEWCALL viewOldRevisionExists    (LPRVH rvh, LPVOID view, INT level, LP_A4W_FLAGS flags);
VIEWCALL viewOldRevisionPost      (LPRVH rvh, LPVOID view, INT level);
VIEWCALL viewOldRevisionRekey     (LPRVH rvh, LPVOID lpv, LPVOID OldKey, LPVOID NewKey, INT size, A4W_FLAGS flags);
VIEWCALL viewOldRevisionUnposted  (LPRVH rvh, LPVOID view, INT level, LP_A4W_FLAGS flags);
VIEWCALL viewOldSecurity          (LPVOID rvh, HPIB PIB, WORD link, LPLONG permissions);
VIEWCALL viewOldTableEmpty        (LPRVH rvh, LPVOID view);
VIEWCALL viewOldType              (LPVOID rvh, LPVOID view, LONG field, LPTYPE type);
VIEWCALL viewOldUnLock            (LPVOID rvh, LPVOID view);
VIEWCALL viewOldUpdate            (LPVOID rvh, LPVOID view);
VIEWCALL viewOldVerify            (LPVOID rvh, LPVOID view);



#if DO_EXTENDEDERRORS<UNIVERSAL_EXTENDEDERRORS

 #if defined(__scLoan_c) || DO_EXTENDEDERRORS>NO_EXTENDEDERRORS

  #define viewAttribs           viewExtendedAttribs
  #define viewBlkGet            viewExtendedBlkGet
  #define viewBlkPut            viewExtendedBlkPut
  #define viewBrowse            viewExtendedBrowse
  #define viewCall              viewExtendedCall
  #define viewCallParam         viewExtendedCallParam
  #define viewCancel            viewExtendedCancel
  #define viewClose             viewExtendedClose
  #define viewCmpNames          viewExtendedCmpNames
  #define viewCompose           viewExtendedCompose
  #define viewCreate            viewExtendedCreate
  #define viewDelete            viewExtendedDelete
  #define viewDirty             viewExtendedDirty
  #define viewDrop              viewExtendedDrop
  #define viewExists            viewExtendedExists
  #define viewFetch             viewExtendedFetch
  #define viewFetchLock         viewExtendedFetchLock
  #define viewField             viewExtendedField
  #define viewFieldExists       viewExtendedFieldExists
  #define viewFieldName         viewExtendedFieldName
  #define viewFields            viewExtendedFields
  #define viewFilterCount       viewExtendedFilterCount
  #define viewFilterDelete      viewExtendedFilterDelete
  #define viewFilterFetch       viewExtendedFilterFetch
  #define viewFilterSelect      viewExtendedFilterSelect
  #define viewGet               viewExtendedGet
  #define viewInit              viewExtendedInit
  #define viewInsert            viewExtendedInsert
  #define viewInstanceFieldList viewExtendedInstanceFieldList
  #define viewInstanceNotify    viewExtendedInstanceNotify
  #define viewInstanceOpen      viewExtendedInstanceOpen
  #define viewInstanceProtocol  viewExtendedInstanceProtocol
  #define viewInstanceSecurity  viewExtendedInstanceSecurity
  #define viewKey               viewExtendedKey
  #define viewKeys              viewExtendedKeys
  #define viewName              viewExtendedName
  #define viewOpen              viewExtendedOpen
  #define viewOrder             viewExtendedOrder
  #define viewPost              viewExtendedPost
  #define viewPresents          viewExtendedPresents
  #define viewProcess           viewExtendedProcess
  #define viewPut               viewExtendedPut
  #define viewRead              viewExtendedRead
  #define viewReadLock          viewExtendedReadLock
  #define viewRecordClear       viewExtendedRecordClear
  #define viewRecordGenerate    viewExtendedRecordGenerate
  #define viewRevisionCancel    viewExtendedRevisionCancel
  #define viewRevisionExists    viewExtendedRevisionExists
  #define viewRevisionPost      viewExtendedRevisionPost
  #define viewRevisionRekey     viewExtendedRevisionRekey
  #define viewRevisionUnposted  viewExtendedRevisionUnposted
  #define viewSecurity          viewExtendedSecurity
  #define viewTableEmpty        viewExtendedTableEmpty
  #define viewType              viewExtendedType
  #define viewUnLock            viewExtendedUnLock
  #define viewUpdate            viewExtendedUpdate
  #define viewVerify            viewExtendedVerify

 #else

  #define viewAttribs           viewOldAttribs
  #define viewBlkGet            viewOldBlkGet
  #define viewBlkPut            viewOldBlkPut
  #define viewBrowse            viewOldBrowse
  #define viewCall              viewOldCall
  #define viewCallParam         viewOldCallParam
  #define viewCancel            viewOldCancel
  #define viewClose             viewOldClose
  #define viewCmpNames          viewOldCmpNames
  #define viewCompose           viewOldCompose
  #define viewCreate            viewOldCreate
  #define viewDelete            viewOldDelete
  #define viewDirty             viewOldDirty
  #define viewDrop              viewOldDrop
  #define viewExists            viewOldExists
  #define viewFetch             viewOldFetch
  #define viewFetchLock         viewOldFetchLock
  #define viewField             viewOldField
  #define viewFieldExists       viewOldFieldExists
  #define viewFieldName         viewOldFieldName
  #define viewFields            viewOldFields
  #define viewFilterCount       viewOldFilterCount
  #define viewFilterDelete      viewOldFilterDelete
  #define viewFilterFetch       viewOldFilterFetch
  #define viewFilterSelect      viewOldFilterSelect
  #define viewGet               viewOldGet
  #define viewInit              viewOldInit
  #define viewInsert            viewOldInsert
  #define viewInstanceFieldList viewOldInstanceFieldList
  #define viewInstanceNotify    viewOldInstanceNotify
  #define viewInstanceOpen      viewOldInstanceOpen
  #define viewInstanceProtocol  viewOldInstanceProtocol
  #define viewInstanceSecurity  viewOldInstanceSecurity
  #define viewKey               viewOldKey
  #define viewKeys              viewOldKeys
  #define viewName              viewOldName
  #define viewOpen              viewOldOpen
  #define viewOrder             viewOldOrder
  #define viewPost              viewOldPost
  #define viewPresents          viewOldPresents
  #define viewProcess           viewOldProcess
  #define viewPut               viewOldPut
  #define viewRead              viewOldRead
  #define viewReadLock          viewOldReadLock
  #define viewRecordClear       viewOldRecordClear
  #define viewRecordGenerate    viewOldRecordGenerate
  #define viewRevisionCancel    viewOldRevisionCancel
  #define viewRevisionExists    viewOldRevisionExists
  #define viewRevisionPost      viewOldRevisionPost
  #define viewRevisionRekey     viewOldRevisionRekey
  #define viewRevisionUnposted  viewOldRevisionUnposted
  #define viewSecurity          viewOldSecurity
  #define viewTableEmpty        viewOldTableEmpty
  #define viewType              viewOldType
  #define viewUnLock            viewOldUnLock
  #define viewUpdate            viewOldUpdate
  #define viewVerify            viewOldVerify

 #endif

#endif



#if defined(__cplusplus)
}
#endif



#endif
