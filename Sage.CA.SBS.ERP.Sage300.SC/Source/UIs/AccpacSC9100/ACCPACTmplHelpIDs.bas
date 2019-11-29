Attribute VB_Name = "ACCPACTmplHelpIDs"
Attribute VB_Description = "Module of help context ID constants whose values are the same for ALL ACCPAC UI Controls"
' ACCPAC UI DEVELOPERS: DO NOT MODIFY THIS FILE!
'
' Module: ACCPACTmplHelpIDs
' Template 5.1A Revision: cycle 8
'
' Description: This module contains an ACCPAC UI
'              Control's (template-related) standard
'              help context ID constants.
'
' NOTE: PUT YOUR UI'S SPECIFIC HELP CONTEXT IDs INTO
'       ACCPACUIGlobals.bas, OR YOUR OWN MODULE(S).
'
' Copyright 2000-2002 ACCPAC International, Inc.
'   All rights reserved.
'

Option Compare Text
Option Explicit


'---------------------------------------------------
' Common (Project-Wide) Help Context IDs
'---------------------------------------------------

' "Contents" and "Using Help" IDs
Public Const HCIDContents As Long = &H0  ' goes to default page
Public Const HCIDUsingHelp As Long = &H50000

' Common resource-related error/warning messages
Public Const HCIDNoLocResources As Long = 10000  ' decimal


'---------------------------------------------------
' Standard ACCPAC UI Control Help Context IDs
'---------------------------------------------------

' Standard ACCPAC UI menu items.  (The popup menu
' items will use the SAME HelpContextIDs as their
' corresponding "regular" menu items.  The top level
' popup item, which has no corresponding "regular"
' menu item, has NO help either, so its HCID is 0.)
Public Const HCIDAUIMnuFile As Long = &H0
Public Const HCIDAUIMnuFilePrint As Long = &H78
Public Const HCIDAUIMnuFilePrintSetup As Long = &H82
Public Const HCIDAUIMnuFileCustomize As Long = 150  ' decimal
Public Const HCIDAUIMnuFileImport As Long = &H6E
Public Const HCIDAUIMnuFileExport As Long = &H6F
Public Const HCIDAUIMnuFileClose As Long = &H8C
Public Const HCIDAUIMnuHelp As Long = &H0
Public Const HCIDAUIMnuHelpContents As Long = &H259
Public Const HCIDAUIMnuHelpUsingHelp As Long = &H265
Public Const HCIDAUIMnuHelpAbout As Long = &H26D
Public Const HCIDAUIPopmnuTopLevel As Long = &H0

' Other standard ACCPAC UI constituent controls
Public Const HCIDAUIAppCloseButton As Long = HCIDAUIMnuFileClose
Public Const HCIDAUIAppDeleteButton As Long = 10070  ' decimal
Public Const HCIDAUIAppSaveButton As Long = 10080  ' decimal
Public Const HCIDAUIAppPrintButton As Long = HCIDAUIMnuFilePrint

' Messages shown to users
Public Const HCIDLocUsePrevRes As Long = 10000
Public Const HCIDAUIInitDBFail As Long = 10010
Public Const HCIDAUIActDSFail As Long = 10020
Public Const HCIDAUICheckRightsFail As Long = 10030
Public Const HCIDAUIAccessDenied As Long = 10040
Public Const HCIDAUIInitIRIFail As Long = 10050
Public Const HCIDAUIDelRecord As Long = HCIDAUIAppDeleteButton
Public Const HCIDAUISaveRecord As Long = HCIDAUIAppSaveButton


'---------------------------------------------------
' "Customize" (Dialog) Box Help Context IDs
'---------------------------------------------------

' "Customize" box dialog's "default"
Public Const HCIDCBDlg As Long = 150  ' decimal

' "Customize" box's constituent controls
Public Const HCIDCBCboWorkingProfile As Long = 150  ' decimal
Public Const HCIDCBCmdNewProfile As Long = 150  ' decimal
Public Const HCIDCBTxtWPDesc As Long = 150  ' decimal
Public Const HCIDCBCmdOK As Long = 150  ' decimal
Public Const HCIDCBCmdCancel As Long = 150  ' decimal
Public Const HCIDCBCmdSave As Long = 150  ' decimal
Public Const HCIDCBLvwOtherProfiles As Long = 150  ' decimal
Public Const HCIDCBTvwShow As Long = 150  ' decimal

' "Customize" box-related error/warning messages
Public Const HCIDCBNoSaveForOK As Long = 150  ' decimal
Public Const HCIDCBSetupFormFail As Long = 150  ' decimal
