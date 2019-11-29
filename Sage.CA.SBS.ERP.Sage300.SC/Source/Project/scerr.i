/////////////////////////////////////////////////////////////////////////////
//
//  File: scerr.i
//  Purpose: Constant definitions for C view template standard error messages
//
//  Copyright (c) 1993-2007 Sage Software, Inc.  All rights reserved.
//
/////////////////////////////////////////////////////////////////////////////


#ifndef __scerr_i
#define __scerr_i


#include <rotoview.h>


// Error message constants
#define  IDERR_SC_KEYNUM_MSG            (SC_ERROR_OFFSET + 0)
#define  IDERR_SC_FLDNUM_MSG            (SC_ERROR_OFFSET + 1)
#define  IDERR_SC_FLDIDX_MSG            (SC_ERROR_OFFSET + 2)
#define  IDERR_SC_MEMORY_MSG            (SC_ERROR_OFFSET + 3)
#define  IDERR_SC_DISABLED_MSG          (SC_ERROR_OFFSET + 4)
#define  IDERR_SC_READONLY_MSG          (SC_ERROR_OFFSET + 5)
#define  IDERR_SC_LIST_MSG              (SC_ERROR_OFFSET + 6)
#define  IDERR_SC_MASK_MSG              (SC_ERROR_OFFSET + 7)
#define  IDERR_SC_SECURITY_MSG          (SC_ERROR_OFFSET + 8)
#define  IDERR_SC_VIEWLOAD_MSG          (SC_ERROR_OFFSET + 9)
#define  IDERR_SC_VIEWCALL_MSG          (SC_ERROR_OFFSET + 10)
#define  IDERR_SC_VIEWOPEN_MSG          (SC_ERROR_OFFSET + 11)
#define  IDERR_SC_VIEWCOMP_MSG          (SC_ERROR_OFFSET + 12)
#define  IDERR_SC_FWDONLY_MSG           (SC_ERROR_OFFSET + 13)
#define  IDERR_SC_SUBCMP_MSG            (SC_ERROR_OFFSET + 14)
#define  IDERR_SC_CMPKEY_MSG            (SC_ERROR_OFFSET + 15)
#define  IDERR_SC_DATUM_MSG             (SC_ERROR_OFFSET + 16)
#define  IDERR_SC_FILTER_DELETE_MSG     (SC_ERROR_OFFSET + 17)
#define  IDERR_SC_BUFFER_MSG            (SC_ERROR_OFFSET + 18)



#define  IDOP_SC_INSTANCE_OPEN          36
#define  IDOP_SC_FILTER_DELETE          37
#define  IDOP_SC_FILTER_FETCH           38
#define  IDOP_SC_REVISION_CANCEL        39
#define  IDOP_SC_REVISION_EXISTS        40
#define  IDOP_SC_REVISION_POST          41
#define  IDOP_SC_REVISION_UNPOSTED      42
#define  IDOP_SC_TABLE_EMPTY            43
#define  IDOP_SC_INSTANCE_NOTIFY        44
#define  IDOP_SC_INSTANCE_SECURITY      45
#define  IDOP_SC_FILTER_SELECT          46
#define  IDOP_SC_RECORD_CLEAR           47
#define  IDOP_SC_RECORD_GENERATE        48
#define  IDOP_SC_FILTER_COUNT           49
#define  IDOP_SC_REVISION_REKEY         50
#define  IDOP_SC_INSTANCE_PROTOCOL      51
#define  IDOP_SC_INSTANCE_FIELDLIST     52
#define  IDOP_SC_FIELD_NAME             53
#define  IDOP_SC_FIELD_EXISTS           54

#define  SC_TEST_OP(op,id)              (op)==VIEW_OP_##id ? IDOP_SC_##id :

// View operation constants
#define  SC_OP_OFFSET                   (SC_ERROR_OFFSET + 20)
#define  MAKE_OP_RSC(op) (RSCID)\
   (SC_OP_OFFSET + ((op)<36 ? (op) : \
    (SC_TEST_OP(op,INSTANCE_OPEN) \
     (SC_TEST_OP(op,FILTER_DELETE) \
      (SC_TEST_OP(op,FILTER_FETCH) \
       (SC_TEST_OP(op,REVISION_CANCEL) \
        (SC_TEST_OP(op,REVISION_EXISTS) \
         (SC_TEST_OP(op,REVISION_POST) \
          (SC_TEST_OP(op,REVISION_UNPOSTED) \
           (SC_TEST_OP(op,TABLE_EMPTY) \
            (SC_TEST_OP(op,INSTANCE_NOTIFY) \
             (SC_TEST_OP(op,INSTANCE_SECURITY) \
              (SC_TEST_OP(op,FILTER_SELECT) \
               (SC_TEST_OP(op,RECORD_CLEAR) \
                (SC_TEST_OP(op,RECORD_GENERATE) \
                 (SC_TEST_OP(op,FILTER_COUNT) \
                  (SC_TEST_OP(op,REVISION_REKEY) \
                   (SC_TEST_OP(op,INSTANCE_PROTOCOL) \
                    (SC_TEST_OP(op,INSTANCE_FIELDLIST) \
                     (SC_TEST_OP(op,FIELD_NAME) \
                      (SC_TEST_OP(op,FIELD_EXISTS) \
                       -1)))))))))))))))))))))

#define  IDERR_SC_INVALID_OP            (SC_OP_OFFSET + -1)

#define  IDERR_SC_ATTRIBUTES_OP         (SC_OP_OFFSET + VIEW_OP_ATTRIBUTES  )
#define  IDERR_SC_BLKGET_OP             (SC_OP_OFFSET + VIEW_OP_BLKGET      )
#define  IDERR_SC_BLKPUT_OP             (SC_OP_OFFSET + VIEW_OP_BLKPUT      )
#define  IDERR_SC_BROWSE_OP             (SC_OP_OFFSET + VIEW_OP_BROWSE      )
#define  IDERR_SC_CANCEL_OP             (SC_OP_OFFSET + VIEW_OP_CANCEL      )
#define  IDERR_SC_CLOSE_OP              (SC_OP_OFFSET + VIEW_OP_CLOSE       )
#define  IDERR_SC_COMPOSE_OP            (SC_OP_OFFSET + VIEW_OP_COMPOSE     )
#define  IDERR_SC_COMPOSITES_OP         (SC_OP_OFFSET + VIEW_OP_COMPOSITES  )
#define  IDERR_SC_CREATE_OP             (SC_OP_OFFSET + VIEW_OP_CREATE      )
#define  IDERR_SC_DELETE_OP             (SC_OP_OFFSET + VIEW_OP_DELETE      )
#define  IDERR_SC_DIRTY_OP              (SC_OP_OFFSET + VIEW_OP_DIRTY       )
#define  IDERR_SC_DROP_OP               (SC_OP_OFFSET + VIEW_OP_DROP        )
#define  IDERR_SC_EXISTS_OP             (SC_OP_OFFSET + VIEW_OP_EXISTS      )
#define  IDERR_SC_FETCH_OP              (SC_OP_OFFSET + VIEW_OP_FETCH       )
#define  IDERR_SC_FETCH_OP_LOCK         (SC_OP_OFFSET + VIEW_OP_FETCH_LOCK  )
#define  IDERR_SC_FIELD_OP              (SC_OP_OFFSET + VIEW_OP_FIELD       )
#define  IDERR_SC_FIELDS_OP             (SC_OP_OFFSET + VIEW_OP_FIELDS      )
#define  IDERR_SC_GET_OP                (SC_OP_OFFSET + VIEW_OP_GET         )
#define  IDERR_SC_INITIALIZE_OP         (SC_OP_OFFSET + VIEW_OP_INITIALIZE  )
#define  IDERR_SC_INSERT_OP             (SC_OP_OFFSET + VIEW_OP_INSERT      )
#define  IDERR_SC_KEY_OP                (SC_OP_OFFSET + VIEW_OP_KEY         )
#define  IDERR_SC_KEYS_OP               (SC_OP_OFFSET + VIEW_OP_KEYS        )
#define  IDERR_SC_NAME_OP               (SC_OP_OFFSET + VIEW_OP_NAME        )
#define  IDERR_SC_OPEN_OP               (SC_OP_OFFSET + VIEW_OP_OPEN        )
#define  IDERR_SC_ORDER_OP              (SC_OP_OFFSET + VIEW_OP_ORDER       )
#define  IDERR_SC_POST_OP               (SC_OP_OFFSET + VIEW_OP_POST        )
#define  IDERR_SC_PRESENTATION_OP       (SC_OP_OFFSET + VIEW_OP_PRESENTATION)
#define  IDERR_SC_PROCESS_OP            (SC_OP_OFFSET + VIEW_OP_PROCESS     )
#define  IDERR_SC_PUT_OP                (SC_OP_OFFSET + VIEW_OP_PUT         )
#define  IDERR_SC_READ_OP               (SC_OP_OFFSET + VIEW_OP_READ        )
#define  IDERR_SC_READ_OP_LOCK          (SC_OP_OFFSET + VIEW_OP_READ_LOCK   )
#define  IDERR_SC_SECURITY_OP           (SC_OP_OFFSET + VIEW_OP_SECURITY    )
#define  IDERR_SC_TYPE_OP               (SC_OP_OFFSET + VIEW_OP_TYPE        )
#define  IDERR_SC_UNLOCK_OP             (SC_OP_OFFSET + VIEW_OP_UNLOCK      )
#define  IDERR_SC_UPDATE_OP             (SC_OP_OFFSET + VIEW_OP_UPDATE      )
#define  IDERR_SC_VERIFY_OP             (SC_OP_OFFSET + VIEW_OP_VERIFY      )

#define  IDERR_SC_INSTANCE_OPEN_OP      (SC_OP_OFFSET + IDOP_SC_INSTANCE_OPEN     )
#define  IDERR_SC_FILTER_DELETE_OP      (SC_OP_OFFSET + IDOP_SC_FILTER_DELETE     )
#define  IDERR_SC_FILTER_FETCH_OP       (SC_OP_OFFSET + IDOP_SC_FILTER_FETCH      )
#define  IDERR_SC_REVISION_CANCEL_OP    (SC_OP_OFFSET + IDOP_SC_REVISION_CANCEL   )
#define  IDERR_SC_REVISION_EXISTS_OP    (SC_OP_OFFSET + IDOP_SC_REVISION_EXISTS   )
#define  IDERR_SC_REVISION_POST_OP      (SC_OP_OFFSET + IDOP_SC_REVISION_POST     )
#define  IDERR_SC_REVISION_UNPOSTED_OP  (SC_OP_OFFSET + IDOP_SC_REVISION_UNPOSTED )
#define  IDERR_SC_TABLE_EMPTY_OP        (SC_OP_OFFSET + IDOP_SC_TABLE_EMPTY       )

#define  IDERR_SC_INSTANCE_NOTIFY_OP    (SC_OP_OFFSET + IDOP_SC_INSTANCE_NOTIFY   )
#define  IDERR_SC_INSTANCE_SECURITY_OP  (SC_OP_OFFSET + IDOP_SC_INSTANCE_SECURITY )
#define  IDERR_SC_FILTER_SELECT_OP      (SC_OP_OFFSET + IDOP_SC_FILTER_SELECT     )
#define  IDERR_SC_RECORD_CLEAR_OP       (SC_OP_OFFSET + IDOP_SC_RECORD_CLEAR      )
#define  IDERR_SC_RECORD_GENERATE_OP    (SC_OP_OFFSET + IDOP_SC_RECORD_GENERATE   )

#define  IDERR_SC_FILTER_COUNT_OP       (SC_OP_OFFSET + IDOP_SC_FILTER_COUNT      )
#define  IDERR_SC_REVISION_REKEY_OP     (SC_OP_OFFSET + IDOP_SC_REVISION_REKEY    )
#define  IDERR_SC_INSTANCE_PROTOCOL_OP  (SC_OP_OFFSET + IDOP_SC_INSTANCE_PROTOCOL )

#define  IDERR_SC_INSTANCE_FIELDLIST_OP (SC_OP_OFFSET + IDOP_SC_INSTANCE_FIELDLIST)
#define  IDERR_SC_FIELD_NAME_OP         (SC_OP_OFFSET + IDOP_SC_FIELD_NAME        )
#define  IDERR_SC_FIELD_EXISTS_OP       (SC_OP_OFFSET + IDOP_SC_FIELD_EXISTS      )




#endif

