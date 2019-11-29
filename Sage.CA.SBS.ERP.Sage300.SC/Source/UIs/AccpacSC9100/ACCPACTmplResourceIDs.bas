Attribute VB_Name = "ACCPACTmplResourceIDs"
Attribute VB_Description = "Module of resource ID constants whose values are the same for ALL ACCPAC UI Controls"
' ACCPAC UI DEVELOPERS: DO NOT MODIFY THIS FILE!
'
' Module: ACCPACTmplResourceIDs
' Template 5.3A Revision: cycle 4
'
' Description: This module contains an ACCPAC UI
'              Control's (template-related) standard
'              resource ID constants.
'
' NOTE: PUT YOUR UI'S SPECIFIC RESOURCE IDs INTO
'       <RotoID>.rc and <RotoID>ID.h.  THE SAMPLE
'       LANGUAGE DLL MAKEFILE INCLUDES COMMANDS TO
'       MAKE <RotoID>ID.bas AND <AppID>ClientID.bas,
'       WHICH WILL CONTAIN THOSE CONSTANTS.
' NOTE: This file (ACCPACTmplResourceIDs.bas)
'       contains some standard resource IDs that are
'       the same for all UI's, even though their
'       corresponding resources are UI-specific
'       (i.e. all UI names have the same ID).
'
' Copyright 2000-2004 ACCPAC International, Inc.
'   All rights reserved.
'

Option Compare Text
Option Explicit


'---------------------------------------------------
' UI-Specific Resources (Already in Template):
' 101-999, 30001+
'---------------------------------------------------

' UI's ID mapping for language-related layout info
Public Const IDD_MapIDs As Long = 101

' UI's associated icon (also used in "About" box)
Public Const IDI_ABPicIcon As Long = 101

' UI name
Public Const IDS_ACCPACUIName As Long = 101


'---------------------------------------------------
' Module-Wide Resources (Already in Template):
' 101-999, 30001+
'---------------------------------------------------

' KEEP THESE ID'S (AND THIS RANGE) FOR NOW, AS THE
' "ABOUT" BOX COMPONENT STILL USES THESE ID'S.
' HOWEVER, SINCE THE UI'S DON'T REFERENCE THESE
' CONSTANTS, THEY CAN BE COMMENTED OUT.

' Module (application) name
'Public Const IDS_ACCPACAppName As Long = 101

' "About" box information-related message strings
'Public Const IDS_ABVersionMsg As Long = 102
'Public Const IDS_ABCopyrightMsg As Long = 103


'---------------------------------------------------
' Common-To-All (Project-Wide) Resources: 101-1000
'---------------------------------------------------

' Font information (for the language)
Public Const IDD_FontInfo As Long = 101

' Generic message box captions
Public Const IDS_ACCPACWarnMBCap As Long = 101
Public Const IDS_ACCPACErrMBCap As Long = 102

' Standard error handler (generic) string constants
Public Const IDS_SAEHLStrECode As Long = 103
Public Const IDS_SAEHRStrECode As Long = 104  ' ENG: Empty

' Added Nov. 21, 2001: information/confirmation
' message box captions
' NOTE: Since not having resources is an error
'       condition, these captions will NOT have
'       default English constants put into
'       ACCPACTmplStrings.bas.
Public Const IDS_ACCPACInfoMBCap As Long = 105
Public Const IDS_ACCPACConfMBCap As Long = 106


'---------------------------------------------------
' Standard ACCPAC UI Control Resources: 1001-2000
'---------------------------------------------------

' Strings related to the "Enhanced" UI name, which
' is used in message boxes where the UI needs to be
' identified, but its name isn't in the message
' box's caption
Public Const IDS_AUILStrNameIdent As Long = 1001
Public Const IDS_AUIRStrNameIdent As Long = 1002
    
' Standard menu item captions (regular/popup menus)
' (Separators have caption "-" in ALL languages)
Public Const IDS_AUIMnuFileCap As Long = 1003
Public Const IDS_AUIMnuFilePrintCap As Long = 1004
Public Const IDS_AUIMnuFilePrintSetupCap As Long = 1005
Public Const IDS_AUIMnuFileCustomizeCap As Long = 1006
Public Const IDS_AUIMnuFileImportCap As Long = 1007
Public Const IDS_AUIMnuFileExportCap As Long = 1008
Public Const IDS_AUIMnuFileCloseCap As Long = 1009
Public Const IDS_AUIMnuHelpCap As Long = 1010
Public Const IDS_AUIMnuHelpContentsCap As Long = 1011
Public Const IDS_AUIMnuHelpUsingHelpCap As Long = 1012
Public Const IDS_AUIMnuHelpAboutCap As Long = 1013
Public Const IDS_AUIPopmnuTopLevelCap As Long = 1014
Public Const IDS_AUIPopmnuFileCap As Long = 1015
Public Const IDS_AUIPopmnuFilePrintCap As Long = 1016
Public Const IDS_AUIPopmnuFilePrintSetupCap As Long = 1017
Public Const IDS_AUIPopmnuFileCustomizeCap As Long = 1018
Public Const IDS_AUIPopmnuFileImportCap As Long = 1019
Public Const IDS_AUIPopmnuFileExportCap As Long = 1020
Public Const IDS_AUIPopmnuFileCloseCap As Long = 1021
Public Const IDS_AUIPopmnuHelpCap As Long = 1022
Public Const IDS_AUIPopmnuHelpContentsCap As Long = 1023
Public Const IDS_AUIPopmnuHelpUsingHelpCap As Long = 1024
Public Const IDS_AUIPopmnuHelpAboutCap As Long = 1025

' Standard ACCPAC UI constituent control captions
Public Const IDS_AUIAppCloseButtonCap As Long = 1026
Public Const IDS_AUIAppDeleteButtonCap As Long = 1027
Public Const IDS_AUIAppSaveButtonCap As Long = 1028
Public Const IDS_AUIAppPrintButtonCap As Long = 1029

' "UIClosed"-part message text parts
Public Const IDS_ReopenTipsTxt As Long = 1030
Public Const IDS_UIClosedTxt As Long = 1031
Public Const IDS_UIInitFailTxt As Long = 1032

' Specific error/warning message text parts
Public Const IDS_AccessDeniedTxt As Long = 1033
Public Const IDS_ActDSFailTxt As Long = 1034
Public Const IDS_CheckRightsFailTxt As Long = 1035
Public Const IDS_InitDBFailTxt As Long = 1036
Public Const IDS_InitIRIFailTxt As Long = 1037
Public Const IDS_LocUsePrevResTxt As Long = 1038

' Other (standard) messages
Public Const IDS_CannotOpenUIMsg As Long = 1039
Public Const IDS_NoHelpFileMsg As Long = 1040
Public Const IDS_NoUsingHelpMsg As Long = 1041
' NO LONGER USED: 1042 (IDS_SavePromptMsg)
Public Const IDS_DelRecordMsg As Long = 1043
Public Const IDS_SaveRecordMsg As Long = 1044

' Added Mar. 7, 2001 (alternate control caption)
Public Const IDS_AUIAppAddButtonCap As Long = 1045

' Added Mar. 16, 2001 (title for report selection
' dialog box: both remote and local)
Public Const IDS_RptSelectorTitle As Long = 1046

' Added Jul. 20, 2001 (alternate save/add and delete
' messages)
' "Save/add/delete %1 %2" messages
Public Const IDS_SaveRecWithTypeMsg As Long = 1047
Public Const IDS_AddRecWithTypeMsg As Long = 1048
Public Const IDS_DelRecWithTypeMsg As Long = 1049

' "Save/add/delete %1" messages, where %1 = type
Public Const IDS_SaveSingleRecMsg As Long = 1050
Public Const IDS_AddSingleRecMsg As Long = 1051
Public Const IDS_DelSingleRecMsg As Long = 1052

' Added Aug. 6, 2002 (common activation UI strings)
Public Const IDS_AUIAppProceedButtonCap As Long = 1053
Public Const IDS_AcvLblCapActivate As Long = 1054
Public Const IDS_AcvLblCapCurActive As Long = 1055
Public Const IDS_AcvFindVerFailMsg As Long = 1056
Public Const IDS_AcvAlreadyActiveMsg As Long = 1057

' Added Jan. 16, 2004 (for optional fields)
Public Const IDS_AUIAppOFButtonCap As Long = 1058

' Added Feb. 5, 2004 (for optional fields)
Public Const IDS_OptFldTitle As Long = 1059


'---------------------------------------------------
' "About" (Dialog) Box Resources: 2001-2200
'---------------------------------------------------

' KEEP THESE ID'S (AND THIS RANGE), AS THE "ABOUT"
' BOX COMPONENT STILL USES THESE ID'S (IT TAKES IN
' THE VARIOUS RESOURCE FILES).  HOWEVER, SINCE THE
' UI'S DON'T REFERENCE THESE CONSTANTS, THEY CAN BE
' COMMENTED OUT.

' "About" box captions
'Public Const IDS_ABCmdOKCap As Long = 2001
'Public Const IDS_ABLStrDlgCap As Long = 2002
'Public Const IDS_ABRStrDlgCap As Long = 2003  ' ENG: Empty

' "About" box information-related message strings
'Public Const IDS_ABLStrAppLine As Long = 2004
'Public Const IDS_ABRStrAppLine As Long = 2005
'Public Const IDS_ABProductName As Long = 2006
'Public Const IDS_ABWarningMsg As Long = 2007


'---------------------------------------------------
' "Customize" (Dialog) Box Resources: 2201-2400
'---------------------------------------------------

' "Customize" box's language layout information
Public Const IDD_CBDlgSizeInfo As Long = 2201
Public Const IDD_CBCtlLayoutInfo As Long = 2202

' "Customize" box's "New Profile" button bitmap
Public Const IDB_CBCmdNewProfile As Long = 2201

' Strings related to the "Customize" box's dialog
' indentifier (included in dialog-related message
' box text for those message boxes that don't use
' the dialog's caption as their captions)
Public Const IDS_CBLStrDlgIdent As Long = 2201
Public Const IDS_CBRStrDlgIdent As Long = 2202

' "Customize" box captions
Public Const IDS_CBCmdSaveCap As Long = 2203
Public Const IDS_CBCmdCancelCap As Long = 2204
Public Const IDS_CBCmdOKCap As Long = 2205
Public Const IDS_CBDlgCap As Long = 2206
Public Const IDS_CBLblDescriptionCap As Long = 2207
Public Const IDS_CBLblOtherProfilesCap As Long = 2208
Public Const IDS_CBLblShowCap As Long = 2209
Public Const IDS_CBLblWorkingCap As Long = 2210

' "Customize" box-related error/warning message
' strings
Public Const IDS_CBNoSaveForOKTxt As Long = 2211
Public Const IDS_CBSetupFormFailTxt As Long = 2212


'---------------------------------------------------
' [Optional] "Browse Directory" (Dialog) Box
' Resources: 2401-2500
'---------------------------------------------------

' "Browse Directory" box captions
Public Const IDS_BDDlgCap As Long = 2401
Public Const IDS_BDLblDriveCap As Long = 2402
Public Const IDS_BDLblDirCap As Long = 2403
Public Const IDS_BDCmdOKCap As Long = 2404
Public Const IDS_BDCmdCancelCap As Long = 2405
