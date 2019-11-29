VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "ACCPACCustCtls"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Attribute VB_Description = "Collection of ACCPACCustCtl objects (customizable ACCPACControls)"
Attribute VB_Ext_KEY = "SavedWithClassBuilder6" ,"Yes"
Attribute VB_Ext_KEY = "Collection" ,"ACCPACCustCtl"
Attribute VB_Ext_KEY = "Member0" ,"ACCPACCustCtl"
Attribute VB_Ext_KEY = "Top_Level" ,"Yes"
' ACCPAC UI DEVELOPERS: DO NOT MODIFY THIS FILE!
'
' Class Module: ACCPACCustCtls (Private Collection:
'               only visible in UI project)
' Template Release Version: 1.0
'
' Description: Collection of ACCPACCustCtl items.
'              This collection holds the
'              customizable ACCPACControls (each
'              wrapped as an ACCPACCustCtl, which
'              itself wraps a non-data source
'              control) that are found on an ACCPAC
'              UI Control.  (Since this is a private
'              collection, NOTHING is exposed.)
'
' Copyright 2000-2001 ACCPAC International, Inc.
'   All rights reserved.
'

Option Compare Text
Option Explicit

'local variable to hold collection
Private mCol As Collection

' NON-TRANSLATED string constant to give the **UI**
' programmer an idea of why an error occurred.
Private Const CCtlsErrNote As String = _
    "NOTE TO UI PROGRAMMERS: You may get this error" _
    & " if you" & vbCrLf & "have deleted and/or " & _
    "renamed some controls on this UI," & vbCrLf & _
    "and these controls have been hidden by " & _
    "customizations." & vbCrLf & "If this is the " & _
    "case, please delete and redo ALL of the" & _
    vbCrLf & "profiles' customizations for this UI."

' ACCPACCustCtls should ONLY be added inside the
' UI's InitCollections (for error handling to work).
' The aCtl argument MUST be ByRef in order for the
' safe setting of "Enabled"/"Visible" to work
' (because we need to make sure that the ACTUAL
' ACCPACControl, and NOT a copy, gets its
' bCustWantsEnabled/bCustWantsVisible flags set).
Friend Function Add(ByRef aCtl As ACCPACControl) As ACCPACCustCtl
On Error Resume Next
    ' For error handling purposes, we delegate to
    ' the helper function to do the actual work.
    ' AddHelper will propagate errors back to here,
    ' and as they aren't handled here, they will be
    ' PROPAGATED BACK TO THE UI's InitCollections.
    Set Add = AddHelper(aCtl)
End Function

' This PRIVATE function does the actual adding, but
' provides a much better way to do error handling.
Private Function AddHelper(ByRef aCtl As ACCPACControl) As ACCPACCustCtl
On Error GoTo AddHelperHandler
    Dim cCtlNewMember As ACCPACCustCtl
    Dim strNewMemberName As String
    
    ' Create a new object.
    Set cCtlNewMember = New ACCPACCustCtl

    ' Attach the (customizable) ACCPACControl to its
    ' wrapper, then find the new (wrapper)
    ' ACCPACCustCtl's name (to be used as a key in
    ' the collection).  (Errors need to be re-raised
    ' in order to get to this function's handler.)
    With cCtlNewMember
        Set .WrappedACtl = aCtl
        With Err
            If .Number <> 0 Then
                .Raise .Number, .Source, _
                    .Description, .HelpFile, _
                    .HelpContext
            End If
        End With  ' Err
        
        strNewMemberName = .Name
        With Err
            If .Number <> 0 Then
                .Raise .Number, .Source, _
                    .Description, .HelpFile, _
                    .HelpContext
            End If
        End With  ' Err
    End With  ' cCtlNewMember
    
    ' Add the new ACCPACCustCtl to the collection
    ' (using its name as the key).
    mCol.Add cCtlNewMember, strNewMemberName
    
    ' Return the (newly created) ACCPACCustCtl.
    Set AddHelper = cCtlNewMember
    
    ' Destroy object variables that aren't needed.
    Set cCtlNewMember = Nothing
Exit Function

AddHelperHandler:
    Dim lErrNum As Long
    Dim strErrSource As String
    Dim strErrOrigDesc As String
    Dim strErrHelpFile As String
    Dim lErrHelpContext As Long
    Dim strErrNewDesc As String
    
    ' Save the error information in variables (as
    ' destroying cCtlNewMember clears Err).
    With Err
        lErrNum = .Number
        strErrSource = .Source
        strErrOrigDesc = .Description
        strErrHelpFile = .HelpFile
        lErrHelpContext = .HelpContext
    End With  ' Err
    
    ' Force a breakpoint to help diagnosis.  (The
    ' debug message will be printed later by the
    ' UI's InitCollections error handler, BUT THIS
    ' BREAKPOINT ALLOWS UI PROGRAMMERS TO CHECK AND
    ' WATCH VARIABLES' VALUES.)
    Debug.Assert False  ' press F5 or F8 to continue
    
    ' Set objects (and return value) to Nothing.
    Set AddHelper = Nothing
    Set cCtlNewMember = Nothing
    
    ' Build the enhanced error description (includes
    ' newline afterwards).
    strErrNewDesc = "  Collection Class: " & _
        "ACCPACCustCtls" & vbCrLf & "  Function: " & _
        "AddHelper (does the work for ""Add"")" & _
        vbCrLf & "  Argument Signature: ByRef aCtl " _
        & "As ACCPACControl" & vbCrLf & "  Return " _
        & "Type: ACCPACCustCtl" & vbCrLf & vbCrLf & "  " & _
        strErrOrigDesc & vbCrLf
    
    ' RE-RAISE the error (with enhanced description)
    Err.Raise lErrNum, strErrSource, strErrNewDesc, _
        strErrHelpFile, lErrHelpContext
End Function

' This NEEDS to be public in order for it to have
' the proper ProcedureID to be the default property.
Public Property Get Item(vntIndexKey As Variant) As ACCPACCustCtl
Attribute Item.VB_UserMemId = 0
On Error GoTo GetItemHandler
    'used when referencing an element in the collection
    'vntIndexKey contains either the Index or Key to the collection,
    'this is why it is declared as a Variant
    'Syntax: Set foo = x.Item(xyz) or Set foo = x.Item(5)
    Set Item = mCol(vntIndexKey)
Exit Property

GetItemHandler:
    Dim lErrNum As Long
    Dim strErrSource As String
    Dim strErrOrigDesc As String
    Dim strErrHelpFile As String
    Dim lErrHelpContext As Long
    Dim strErrNewDesc As String
    Dim strIdx As String
        
    ' Save the error information in variables (as
    ' the GetColIdxStr call clears the error).
    With Err
        lErrNum = .Number
        strErrSource = .Source
        strErrOrigDesc = .Description
        strErrHelpFile = .HelpFile
        lErrHelpContext = .HelpContext
    End With  ' Err
    
    ' Get the STRING version of the argument.
    strIdx = GetColIdxStr(vntIndexKey)
    
    ' Build the enhanced error description.
    strErrNewDesc = "Collection Class: " & _
        "ACCPACCustCtls" & vbCrLf & "Property: " & _
        "(Get) Item" & vbCrLf & "Argument: " & _
        "vntIndexKey = " & strIdx & vbCrLf & vbCrLf _
        & strErrOrigDesc
    
    ' Print a debug message (geared toward **UI**
    ' programmers) with error information and a note
    ' about the error's possible cause and solution.
    ' (Include extra newlines at beginning and end.)
    Debug.Print vbCrLf & "Error #" & CStr(lErrNum) & _
        " - [Source: " & strErrSource & "]" & vbCrLf _
        & strErrNewDesc & vbCrLf & vbCrLf & _
        CCtlsErrNote & vbCrLf
    
    ' RE-RAISE the error to let VB GPF (so macro
    ' programmers can see the error too).
    Err.Raise lErrNum, strErrSource, strErrNewDesc, _
        strErrHelpFile, lErrHelpContext
End Property

Friend Property Get Count() As Long
On Error GoTo GetCountHandler
    'used when retrieving the number of elements in the
    'collection. Syntax: Debug.Print x.Count
    Count = mCol.Count
Exit Property

GetCountHandler:
    Dim lErrNum As Long
    Dim strErrSource As String
    Dim strErrOrigDesc As String
    Dim strErrHelpFile As String
    Dim lErrHelpContext As Long
    Dim strErrNewDesc As String
        
    ' Save the error information in variables (as
    ' other calls may clear the error).
    With Err
        lErrNum = .Number
        strErrSource = .Source
        strErrOrigDesc = .Description
        strErrHelpFile = .HelpFile
        lErrHelpContext = .HelpContext
    End With  ' Err
    
    ' Build the enhanced error description.
    strErrNewDesc = "Collection Class: " & _
        "ACCPACCustCtls" & vbCrLf & "Property: " & _
        "(Get) Count" & vbCrLf & vbCrLf & _
        strErrOrigDesc
    
    ' Print a debug message (geared toward **UI**
    ' programmers) with error information and a note
    ' about the error's possible cause and solution.
    ' (Include extra newlines at beginning and end.)
    Debug.Print vbCrLf & "Error #" & CStr(lErrNum) & _
        " - [Source: " & strErrSource & "]" & vbCrLf _
        & strErrNewDesc & vbCrLf & vbCrLf & _
        CCtlsErrNote & vbCrLf
    
    ' RE-RAISE the error to let VB GPF (so macro
    ' programmers can see the error too).
    Err.Raise lErrNum, strErrSource, strErrNewDesc, _
        strErrHelpFile, lErrHelpContext
End Property

Friend Sub Remove(vntIndexKey As Variant)
On Error GoTo RemoveHandler
    'used when removing an element from the collection
    'vntIndexKey contains either the Index or Key, which is why
    'it is declared as a Variant
    'Syntax: x.Remove(xyz)
    mCol.Remove vntIndexKey
Exit Sub

RemoveHandler:
    Dim lErrNum As Long
    Dim strErrSource As String
    Dim strErrOrigDesc As String
    Dim strErrHelpFile As String
    Dim lErrHelpContext As Long
    Dim strErrNewDesc As String
    Dim strIdx As String
        
    ' Save the error information in variables (as
    ' the GetColIdxStr call clears the error).
    With Err
        lErrNum = .Number
        strErrSource = .Source
        strErrOrigDesc = .Description
        strErrHelpFile = .HelpFile
        lErrHelpContext = .HelpContext
    End With  ' Err
    
    ' Get the STRING version of the argument.
    strIdx = GetColIdxStr(vntIndexKey)
    
    ' Build the enhanced error description.
    strErrNewDesc = "Collection Class: " & _
        "ACCPACCustCtls" & vbCrLf & "Sub: Remove" & _
        vbCrLf & "Argument: vntIndexKey = " & strIdx _
        & vbCrLf & vbCrLf & strErrOrigDesc
    
    ' Print a debug message (geared toward **UI**
    ' programmers) with error information and a note
    ' about the error's possible cause and solution.
    ' (Include extra newlines at beginning and end.)
    Debug.Print vbCrLf & "Error #" & CStr(lErrNum) & _
        " - [Source: " & strErrSource & "]" & vbCrLf _
        & strErrNewDesc & vbCrLf & vbCrLf & _
        CCtlsErrNote & vbCrLf
    
    ' RE-RAISE the error (with NEW description) to
    ' let VB GPF (so macro programmers can see the
    ' error too).
    Err.Raise lErrNum, strErrSource, strErrNewDesc, _
        strErrHelpFile, lErrHelpContext
End Sub

' This NEEDS to be public in order for it to be
' hidden and have the proper ProcedureID.
Public Property Get NewEnum() As IUnknown
Attribute NewEnum.VB_UserMemId = -4
Attribute NewEnum.VB_MemberFlags = "40"
On Error GoTo GetNewEnumHandler
    'this property allows you to enumerate
    'this collection with the For...Each syntax
    Set NewEnum = mCol.[_NewEnum]
Exit Property

GetNewEnumHandler:
    Dim lErrNum As Long
    Dim strErrSource As String
    Dim strErrOrigDesc As String
    Dim strErrHelpFile As String
    Dim lErrHelpContext As Long
    Dim strErrNewDesc As String
        
    ' Save the error information in variables (as
    ' other calls may clear the error).
    With Err
        lErrNum = .Number
        strErrSource = .Source
        strErrOrigDesc = .Description
        strErrHelpFile = .HelpFile
        lErrHelpContext = .HelpContext
    End With  ' Err
    
    ' Build the enhanced error description.
    strErrNewDesc = "Collection Class: " & _
        "ACCPACCustCtls" & vbCrLf & "Property: " & _
        "(Get) NewEnum" & vbCrLf & vbCrLf & _
        strErrOrigDesc
    
    ' Print a debug message (geared toward **UI**
    ' programmers) with error information and a note
    ' about the error's possible cause and solution.
    ' (Include extra newlines at beginning and end.)
    Debug.Print vbCrLf & "Error #" & CStr(lErrNum) & _
        " - [Source: " & strErrSource & "]" & vbCrLf _
        & strErrNewDesc & vbCrLf & vbCrLf & _
        CCtlsErrNote & vbCrLf
    
    ' RE-RAISE the error to let VB GPF (so macro
    ' programmers can see the error too).
    Err.Raise lErrNum, strErrSource, strErrNewDesc, _
        strErrHelpFile, lErrHelpContext
End Property

' NO NEED FOR ERROR HANDLING!
Private Sub Class_Initialize()
    'creates the collection when this class is created
    Set mCol = New Collection
End Sub

Private Sub Class_Terminate()
On Error Resume Next
    'destroys collection when this class is terminated
    Set mCol = Nothing
    Err.Clear
End Sub
