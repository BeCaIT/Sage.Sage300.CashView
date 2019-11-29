VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "ACCPACDSControls"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Attribute VB_Description = "Collection of ACCPACDSControl objects (wrapped ACCPAC data sources)"
Attribute VB_Ext_KEY = "SavedWithClassBuilder6" ,"Yes"
Attribute VB_Ext_KEY = "Collection" ,"ACCPACDSControl"
Attribute VB_Ext_KEY = "Member0" ,"ACCPACDSControl"
Attribute VB_Ext_KEY = "Top_Level" ,"Yes"
' ACCPAC UI DEVELOPERS: DO NOT MODIFY THIS FILE!
'
' Class Module: ACCPACDSControls (Collection)
' Template Release Version: 1.0
'
' Description: Collection of ACCPACDSControl items.
'              This collection holds the data
'              source controls (each wrapped as an
'              ACCPACDSControl) that belong to an
'              ACCPAC UI Control.  The following
'              properties are exposed:
'               - Count (Read-only)
'               - Item (DEFAULT, Read-only)
'
' Copyright 1999-2001 ACCPAC International, Inc.
'   All rights reserved.
'

Option Compare Text
Option Explicit

'local variable to hold collection
Private mCol As Collection

' NON-TRANSLATED string constant to give the **UI**
' programmer an idea of why an error occurred.
Private Const DSCtlsErrNote As String = _
    "NOTE TO UI PROGRAMMERS: You may get this error" _
    & " if you" & vbCrLf & "have deleted and/or " & _
    "renamed some ACCPAC data sources on" & vbCrLf & _
    "this UI, but UI, macro, and/or test container" _
    & " code" & vbCrLf & "still looks for them in " _
    & "data source collections.  If" & vbCrLf & _
    "this is the case, check hardcoded bounds in " & _
    """For"" loops" & vbCrLf & "that deal with " & _
    "collection items and check for calls" & vbCrLf _
    & "where ACCPAC data source names are passed " & _
    "into" & vbCrLf & "collection methods (i.e. to " _
    & "get or remove an item)."

' ACCPACDSControls should ONLY be added inside the
' UI's InitCollections (for error handling to work).
Friend Function Add(ByVal ds As AccpacDataSource) _
                    As ACCPACDSControl
On Error Resume Next
    ' For error handling purposes, we delegate to
    ' the helper function to do the actual work.
    ' AddHelper will propagate errors back to here,
    ' and as they aren't handled here, they will be
    ' PROPAGATED BACK TO THE UI's InitCollections.
    Set Add = AddHelper(ds)
End Function

' This PRIVATE function does the actual adding, but
' provides a much better way to do error handling.
Private Function AddHelper(ByVal ds As AccpacDataSource) _
                          As ACCPACDSControl
On Error GoTo AddHelperHandler
    Dim dsNewMember As ACCPACDSControl
    Dim strNewMemberName As String
    
    ' Create a new object.
    Set dsNewMember = New ACCPACDSControl

    ' Setup the ACCPACDSControl instance by passing
    ' in the original data source control, then find
    ' the new (wrapper) ACCPACDSControl's name (to
    ' be used as a key in the collection).  (Errors
    ' need to be re-raised in order to get to this
    ' function's handler.)
    With dsNewMember
        .SetupInstance ds
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
    End With  ' dsNewMember
    
    ' Add the new ACCPACDSControl to the collection
    ' (using its name as the key).
    mCol.Add dsNewMember, strNewMemberName
    
    ' Return the (newly created) ACCPACDSControl.
    Set AddHelper = dsNewMember
    
    ' Destroy object variables that aren't needed.
    Set dsNewMember = Nothing
Exit Function

AddHelperHandler:
    Dim lErrNum As Long
    Dim strErrSource As String
    Dim strErrOrigDesc As String
    Dim strErrHelpFile As String
    Dim lErrHelpContext As Long
    Dim strErrNewDesc As String
    
    ' Save the error information in variables (as
    ' destroying dsNewMember clears Err).
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
    Set dsNewMember = Nothing

    ' Build the enhanced error description (includes
    ' newline afterwards).
    strErrNewDesc = "  Collection Class: " & _
        "ACCPACDSControls" & vbCrLf & "  Function: " _
        & "AddHelper (does the work for ""Add"")" & _
        vbCrLf & "  Argument Signature: ByVal ds As" _
        & " AccpacDataSource" & vbCrLf & "  Return " _
        & "Type: ACCPACDSControl" & vbCrLf & vbCrLf _
        & "  " & strErrOrigDesc & vbCrLf
    
    ' RE-RAISE the error (with enhanced description)
    Err.Raise lErrNum, strErrSource, strErrNewDesc, _
        strErrHelpFile, lErrHelpContext
End Function

Public Property Get Item(vntIndexKey As Variant) As ACCPACDSControl
Attribute Item.VB_Description = "Returns the ACCPACDSControl object as specified by its name (as a string) or a 1-based collection index."
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
        "ACCPACDSControls" & vbCrLf & "Property: " & _
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
        DSCtlsErrNote & vbCrLf
    
    ' RE-RAISE the error to let VB GPF (so macro
    ' programmers can see the error too).
    Err.Raise lErrNum, strErrSource, strErrNewDesc, _
        strErrHelpFile, lErrHelpContext
End Property

Public Property Get Count() As Long
Attribute Count.VB_Description = "Returns the number of ACCPACDSControl objects contained in the collection."
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
        "ACCPACDSControls" & vbCrLf & "Property: " & _
        "(Get) Count" & vbCrLf & vbCrLf & _
        strErrOrigDesc
    
    ' Print a debug message (geared toward **UI**
    ' programmers) with error information and a note
    ' about the error's possible cause and solution.
    ' (Include extra newlines at beginning and end.)
    Debug.Print vbCrLf & "Error #" & CStr(lErrNum) & _
        " - [Source: " & strErrSource & "]" & vbCrLf _
        & strErrNewDesc & vbCrLf & vbCrLf & _
        DSCtlsErrNote & vbCrLf
    
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
        "ACCPACDSControls" & vbCrLf & "Sub: Remove" _
        & vbCrLf & "Argument: vntIndexKey = " & _
        strIdx & vbCrLf & vbCrLf & strErrOrigDesc
    
    ' Print a debug message (geared toward **UI**
    ' programmers) with error information and a note
    ' about the error's possible cause and solution.
    ' (Include extra newlines at beginning and end.)
    Debug.Print vbCrLf & "Error #" & CStr(lErrNum) & _
        " - [Source: " & strErrSource & "]" & vbCrLf _
        & strErrNewDesc & vbCrLf & vbCrLf & _
        DSCtlsErrNote & vbCrLf
    
    ' RE-RAISE the error (with NEW description) to
    ' let VB GPF (so macro programmers can see the
    ' error too).
    Err.Raise lErrNum, strErrSource, strErrNewDesc, _
        strErrHelpFile, lErrHelpContext
End Sub

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
        "ACCPACDSControls" & vbCrLf & "Property: " & _
        "(Get) NewEnum" & vbCrLf & vbCrLf & _
        strErrOrigDesc
    
    ' Print a debug message (geared toward **UI**
    ' programmers) with error information and a note
    ' about the error's possible cause and solution.
    ' (Include extra newlines at beginning and end.)
    Debug.Print vbCrLf & "Error #" & CStr(lErrNum) & _
        " - [Source: " & strErrSource & "]" & vbCrLf _
        & strErrNewDesc & vbCrLf & vbCrLf & _
        DSCtlsErrNote & vbCrLf
    
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
