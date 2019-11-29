Attribute VB_Name = "ACCPACTmplStrings"
Attribute VB_Description = "Module of default English string constants whose values are the same for ALL ACCPAC UI Controls"
' ACCPAC UI DEVELOPERS: DO NOT MODIFY THIS FILE!
'
' Module: ACCPACTmplStrings
' Template Release Version: 1.0
'
' Description: This module contains an ACCPAC UI
'              Control's DEFAULT ENGLISH STRING
'              CONSTANTS for SOME (template-
'              related) strings that need to be
'              translated.  These SAME strings are
'              in the associated English-Language
'              resource file.  UI PROGRAMMERS SHOULD
'              NEVER USE THESE DEFAULT CONSTANTS IN
'              THEIR CODE.
'
' NOTE: PUT YOUR UI'S SPECIFIC (TRANSLATABLE) STRING
'       CONSTANTS IN THE RESOURCE FILE.
'
' Copyright 2000-2001 ACCPAC International, Inc.
'   All rights reserved.
'

Option Compare Text
Option Explicit

'---------------------------------------------------
' Common (Project-Wide) Strings
'---------------------------------------------------

' Generic message box captions
' NOTE: UI PROGRAMMERS MUST USE THE "mstr" MEMBER
'       VARIABLE INSTEAD OF THE CONSTANT (i.e. use
'       mstrACCPACWarnMBCap, NOT ACCPACWarnMBCap).
Public Const ACCPACWarnMBCap As String = _
    "Warning"
Public Const ACCPACErrMBCap As String = _
    "Error"
    

'---------------------------------------------------
' Standard ACCPAC UI Control Strings
'---------------------------------------------------

' Strings related to the "Enhanced" UI name, which
' is used in message boxes where the UI needs to be
' identified, but its name isn't in the message
' box's caption
' NOTE: UI PROGRAMMERS SHOULDN'T USE THESE CONSTANTS.
Public Const AUILStrNameIdent As String = _
    "["
Public Const AUIRStrNameIdent As String = _
    "]"

' "UIClosed"-part message text parts
' NOTE: UI PROGRAMMERS SHOULDN'T USE THESE CONSTANTS.
Public Const ReopenTipsTxt As String = _
    "Before reopening the UI, you need to close its" _
    & " host window (or remove the UI from its host" _
    & " window)."
Public Const UIInitFailTxt As String = _
    "Failed to initialize the UI."
