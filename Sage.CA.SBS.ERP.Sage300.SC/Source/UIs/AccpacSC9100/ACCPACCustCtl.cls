VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "ACCPACCustCtl"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Attribute VB_Description = "Customizable ACCPACControl (wrapped control) wrapper class"
Attribute VB_Ext_KEY = "SavedWithClassBuilder6" ,"Yes"
Attribute VB_Ext_KEY = "Top_Level" ,"Yes"
' ACCPAC UI DEVELOPERS: DO NOT MODIFY THIS FILE!
'
' Class Module: ACCPACCustCtl (Private: only visible
'               in UI project)
' Template Release Version: 1.0
'
' Description: Wrapper class for ACCPACControl items
'              that are customizable.  This wrapper
'              is needed so that a control's
'              "Enabled" and "Visible" properties
'              can be set safely.
'
' Copyright 2000-2001 ACCPAC International, Inc.
'   All rights reserved.
'

Option Compare Text
Option Explicit

Private mACCPACCtl As ACCPACControl


'---------------------------------------------------
' Class Initialization/Termination
'---------------------------------------------------

' NO NEED FOR ERROR HANDLING!
Private Sub Class_Initialize()
    Set mACCPACCtl = Nothing
End Sub

Private Sub Class_Terminate()
On Error Resume Next
    Set mACCPACCtl = Nothing
    Err.Clear
End Sub


'---------------------------------------------------
' Property For Wrapping the ACCPACControl
'---------------------------------------------------

' Set-once property (set by collection's "Add" sub).

'Friend Property Get WrappedACtl() As ACCPACControl
'On Error Resume Next
'    Set WrappedACtl = mACCPACCtl
'
'    ' Inline error handler
'    If Err.Number <> 0 Then
'        CustACCPACErrorHandler "WrappedACtl", _
'            ptPropertyGet, "Unspecified Error"
'    End If
'End Property

' The aCtl argument MUST be ByRef in order for the
' safe setting of "Enabled"/"Visible" to work
' (because we need to make sure that the ACTUAL
' ACCPACControl, and NOT a copy, gets its
' bCustWantsEnabled/bCustWantsVisible flags set).
Friend Property Set WrappedACtl(ByRef aCtl As _
        ACCPACControl)
On Error Resume Next
    ' If property hasn't been set yet, do so.
    If mACCPACCtl Is Nothing Then
        Set mACCPACCtl = aCtl
    End If
    
    ' Inline error handler
    If Err.Number <> 0 Then
        CustACCPACErrorHandler "WrappedACtl", _
            ptPropertySet, _
            "Wrapped ACCPACControl Not Set"
    End If
End Property


'---------------------------------------------------
' Properties for Setting "Enabled/Visible"
'---------------------------------------------------

Friend Property Get EnabledFlag() As Boolean
On Error Resume Next
    If (Not (mACCPACCtl Is Nothing)) Then
        EnabledFlag = mACCPACCtl.CustEnabledFlag
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CustACCPACErrorHandler "EnabledFlag", _
                ptPropertyGet, ErrPreserveGetName
        End If  ' Err.Number <> 0
    End If  ' Not (mACCPACCtl Is Nothing)
End Property

Friend Property Let EnabledFlag(ByVal bFlag As Boolean)
On Error Resume Next
    If (Not (mACCPACCtl Is Nothing)) Then
        mACCPACCtl.CustEnabledFlag = bFlag
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CustACCPACErrorHandler "EnabledFlag = " _
                & CStr(bFlag), ptPropertyLet, _
                ErrPreserveGetName
        End If  ' Err.Number <> 0
    End If  ' Not (mACCPACCtl Is Nothing)
End Property

Friend Property Get VisibleFlag() As Boolean
On Error Resume Next
    If (Not (mACCPACCtl Is Nothing)) Then
        VisibleFlag = mACCPACCtl.CustVisibleFlag
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CustACCPACErrorHandler "VisibleFlag", _
                ptPropertyGet, ErrPreserveGetName
        End If  ' Err.Number <> 0
    End If  ' Not (mACCPACCtl Is Nothing)
End Property

Friend Property Let VisibleFlag(ByVal bFlag As Boolean)
On Error Resume Next
    If (Not (mACCPACCtl Is Nothing)) Then
        mACCPACCtl.CustVisibleFlag = bFlag
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CustACCPACErrorHandler "VisibleFlag = " _
                & CStr(bFlag), ptPropertyLet, _
                ErrPreserveGetName
        End If  ' Err.Number <> 0
    End If  ' Not (mACCPACCtl Is Nothing)
End Property


'---------------------------------------------------
' Other Properties
'---------------------------------------------------

' (Read-only)
' The ACCPACControl's "Name" property will deal with
' whether the control is part of a control array or
' not (so we don't have to deal with that).
Friend Property Get Name() As String
On Error Resume Next
    If (Not (mACCPACCtl Is Nothing)) Then
        Name = mACCPACCtl.Name
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CustACCPACErrorHandler "Name", _
                ptPropertyGet, _
                "Wrapped ACCPACControl Has No Name"
        End If  ' Err.Number <> 0
    End If  ' Not (mACCPACCtl Is Nothing)
End Property

' (Read-only, although ACCPACCtl property is RW)
Friend Property Get Caption() As String
On Error Resume Next
    If (Not (mACCPACCtl Is Nothing)) Then
        Caption = mACCPACCtl.Caption

        ' Inline error handler
        If Err.Number <> 0 Then
            CustACCPACErrorHandler "Caption", _
                ptPropertyGet, ErrPreserveGetName
        End If  ' Err.Number <> 0
    End If  ' Not (mACCPACCtl Is Nothing)
End Property

' (Read-only)
' Set this property safely using EnabledFlag.
' NOTE: This shows whether or not the control is
'       ACTUALLY enabled.
Friend Property Get Enabled() As Boolean
On Error Resume Next
    If (Not (mACCPACCtl Is Nothing)) Then
        Enabled = mACCPACCtl.Enabled
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CustACCPACErrorHandler "Enabled", _
                ptPropertyGet, ErrPreserveGetName
        End If  ' Err.Number <> 0
    End If  ' Not (mACCPACCtl Is Nothing)
End Property

' (Read-only)
' Set this property safely using VisibleFlag.
' NOTE: This shows whether or not the control is
'       ACTUALLY visible.
Friend Property Get Visible() As Boolean
On Error Resume Next
    If (Not (mACCPACCtl Is Nothing)) Then
        Visible = mACCPACCtl.Visible
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CustACCPACErrorHandler "Visible", _
                ptPropertyGet, ErrPreserveGetName
        End If  ' Err.Number <> 0
    End If  ' Not (mACCPACCtl Is Nothing)
End Property


'---------------------------------------------------
' Private Error Handling Helper
'---------------------------------------------------

' This function returns the wrapped ACCPACControl's
' name and PRESERVES the original state of the Err
' object.  Calling "mACCPACCtl.Name" clears Err, so
' we lose the error's information if we try to pass
' "mACCPACCtl.Name" into CustACCPACErrorHandler
' directly.  By saving that original error before
' getting the name, this function will then put the
' error's information (number, source, description)
' back into Err so that CustACCPACErrorHandler will
' be able to report (and re-raise) the correct
' information.
' NOTE: We CAN'T re-raise the error because the
'       ACCPACCustCtl property/method has an "On
'       Error Resume Next", which will skip the
'       CustACCPACErrorHandler call (which calls
'       this function to use its return value as an
'       argument) if any error is raised here.
Private Function ErrPreserveGetName() As String
    Dim lErrNum As Long
    Dim strErrSource As String
    Dim strErrDesc As String
    Dim strErrHelpFile As String
    Dim lErrHelpContext As Long
        
    ' Save the error information before opening the
    ' ("Resume Next") error trap
    With Err
        lErrNum = .Number
        strErrSource = .Source
        strErrDesc = .Description
        strErrHelpFile = .HelpFile
        lErrHelpContext = .HelpContext
    End With  ' Err

On Error Resume Next  ' ignore errors produced here
    ' If there wasn't an error, EXIT THE FUNCTION
    If lErrNum = 0 Then
        Debug.Print "ErrPreserveGetName was called" _
            & " when there were no errors."
        ErrPreserveGetName = ""  ' "Default" name
        Exit Function
    End If
        
    ' IF WE'RE STILL IN THE SUB, WE DO HAVE AN ERROR
    
    If (mACCPACCtl Is Nothing) Then
        ErrPreserveGetName = ""  ' no name
    Else  ' mACCPACCtl exists
        ErrPreserveGetName = mACCPACCtl.Name
    End If
    
    ' Put the ORIGINAL error information back into
    ' the Err object (DON'T re-raise it)
    With Err
        .Number = lErrNum
        .Source = strErrSource
        .Description = strErrDesc
        .HelpFile = strErrHelpFile
        .HelpContext = lErrHelpContext
    End With  ' Err
End Function
