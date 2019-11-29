#ifndef __SC9100ID_H
#define __SC9100ID_H

//*****************************************************************
//
// File: SC9100ID.h
// UI:	C/S Options
//
// Copyright © 2019 Sage Software Asia Pte Ltd.
//   All rights reserved.
//
// Available IDs: 1000 (ID_BASE) to 30000
//
// NOTE: The BAS generator doesn't process C-style comments
//       properly (i.e. /* comment */).  Constant names must start
//       with a letter and can only contain alphanumeric characters
//       and underscores.
//
//******************************************************************

// UI-specific string IDs
// EXAMPLE: #define IDS_MyMsg  (ID_BASE + 0)
#define	IDS_TAB_COMPANY		(ID_BASE + 0)
#define	IDS_TAB_PROCESSING	(ID_BASE + 1)
#define	IDS_TAB_ACCOUNTS		(ID_BASE + 2)
#define	IDS_TAB_EMAIL			(ID_BASE + 3)

#define	IDS_PROCESSING_FRAME_SETTINGS		(ID_BASE + 10)
#define	IDS_PROCESSING_FRAME_STATISTICS	(ID_BASE + 11)
#define	IDS_PROCESSING_LABEL_PERIODS		(ID_BASE + 12)
#define	IDS_PROCESSING_PERIOD_FROM			(ID_BASE + 13)
#define	IDS_PROCESSING_PERIOD_TO			(ID_BASE + 14)
#define	IDS_PROCESSING_PERIOD_CURRENT		(ID_BASE + 15)
#define	IDS_PROCESSING_PERIOD_OVER			(ID_BASE + 16)
#define	IDS_PROCESSING_LABEL_DOCNUMBERS	(ID_BASE + 17)
#define	IDS_PROCESSING_DOCNUM_TYPE			(ID_BASE + 18)
#define	IDS_PROCESSING_DOCNUM_LENGTH		(ID_BASE + 19)
#define	IDS_PROCESSING_DOCNUM_PREFIX		(ID_BASE + 20)
#define	IDS_PROCESSING_DOCNUM_NEXTNBR		(ID_BASE + 21)
#define	IDS_PROCESSING_DOCNUM_FORECAST	(ID_BASE + 22)

#define	IDS_EMAIL_FRAME_SETTINGS			(ID_BASE + 30)
#define	IDS_EMAIL_FRAME_SENDTEST			(ID_BASE + 31)
#define	IDS_EMAIL_FRAME_ADVISORY			(ID_BASE + 32)
#define	IDS_EMAIL_LABEL_SENDTEST			(ID_BASE + 33)
#define	IDS_EMAIL_BUTTON_SENDTEST			(ID_BASE + 34)
#define	IDS_EMAIL_LABEL_ADVISORY			(ID_BASE + 35)

#define	IDS_EMAIL_CONSENT						(ID_BASE + 40)

// Other UI-specific resource IDs
// EXAMPLE: #define IDI_PicCust  (ID_BASE + 10000)


// +++

#endif  // __SC9100ID_H
