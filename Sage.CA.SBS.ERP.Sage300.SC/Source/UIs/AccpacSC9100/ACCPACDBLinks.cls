VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "ACCPACDBLinks"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Attribute VB_Description = "Collection of AccpacDBLink objects (ACCPAC DB links)"
Attribute VB_Ext_KEY = "SavedWithClassBuilder6" ,"Yes"
Attribute VB_Ext_KEY = "Collection" ,"AccpacDBLink"
Attribute VB_Ext_KEY = "Member0" ,"AccpacDBLink"
Attribute VB_Ext_KEY = "Top_Level" ,"Yes"
' ACCPAC UI DEVELOPERS: DO NOT MODIFY THIS FILE!
'
' Class Module: ACCPACDBLinks (Collection)
' Template 5.5A Revision: cycle 1
'
' Description: Collection of AccpacDBLink items.
'              This collection holds the open DB
'              links in the ACCPAC UI Control.  The
'              following properties are exposed:
'               - Count (Read-only)
'               - Item (DEFAULT, Read-only)
'
' Copyright 1999-2007 Sage Accpac International, Inc.
'   All rights reserved.
'

Option Compare Text
Option Explicit

'local variable to hold collection
Private mCol As Collection

' NON-TRANSLATED string constant to give the **UI**
' programmer an idea of why an error occurred.
Private Const DBLinksErrNote As String = _
    "NOTE TO UI PROGRAMMERS: You may get this error" _
    & " if you" & vbCrLf & "have deleted and/or " & _
    "renamed some AccpacDBLink variables" & vbCrLf & _
    "in this UI's code.  If this is the case, check" _
    & " the UI" & vbCrLf & "code and your (test) " & _
    "macro and/or test container code" & vbCrLf & _
    "for hardcoded bounds in ""For"" loops that " & _
    "deal with" & vbCrLf & "wrapped DB links and " & _
    "check for calls where DB link" & vbCrLf & _
    "variable names are passed into collection " & _
    "methods (i.e." & vbCrLf & "to get or remove a " _
    & "wrapped DB link)."
    
' SUGGESTED: Have the sKey argument the same name as
' the variable holding the DB link (but written as a
' string).  I.e. Add(dbLinkCmpRW, "dbLinkCmpRW").
' NOTE: A DB link that's Nothing can be added to the
'       collection (and that's OK).  Programmers
'       should check for DB links being Nothing when
'       working with an ACCPACDBLinks collection.
Friend Sub Add(ByVal DBLink As AccpacDBLink, Optional ByVal sKey As String = "")
On Error Resume Next
    ' Add it to the collection (with or without key)
    If (sKey = "") Or (sKey = vbNullString) Then
        mCol.Add DBLink
    Else
        mCol.Add DBLink, sKey
    End If
    
    ' Inline error handler
    If Err.Number <> 0 Then
        Dim strErrSpecificTxt As String
        
        ' Create the part of the debug message that
        ' depends on what error got raised.
        If Err.Number = 457 Then
            ' We have a duplicate key.
            strErrSpecificTxt = "Key: sKey = """ & _
                sKey & """"
        Else
            ' We have some other error.
            strErrSpecificTxt = "Arguments: dbLink " _
                & "(AccpacDBLink), sKey = """ & sKey _
                & """" & vbCrLf & "Private member: " _
                & "mCol = "
            
            ' Include information on whether the
            ' private collection member is Nothing.
            If mCol Is Nothing Then
                strErrSpecificTxt = _
                   strErrSpecificTxt & "Nothing"
            Else
                strErrSpecificTxt = _
                    strErrSpecificTxt & _
                    "(Collection object)"
            End If  ' mCol Is Nothing
        End If  ' Err.Number = 457
        
        ' Print the (more informative) debug message
        ' (with blank lines before and after it) and
        ' force a breakpoint to help diagnosis.
        ' NOTE: The original (and less informative)
        '       error will be shown to the user and
        '       printed inside the UI's OpenUIApp,
        '       which finishes handling errors
        '       caught inside the UI's InitDBLinks
        '       (such as an error in this sub).
        Debug.Print vbCrLf & "Collection Class: " & _
            "ACCPACDBLinks" & vbCrLf & "Sub: Add" & _
            vbCrLf & strErrSpecificTxt & vbCrLf & _
            vbCrLf & Err.Description & vbCrLf
        Debug.Assert False  ' press F5 or F8 to continue
        
        ' NOTE: DON'T clear Err as we want the UI's
        '       InitDBLinks to catch it (with its
        '       "If Err.Number <> 0") and propagate
        '       it to the UI's OpenUIApp (to finish
        '       the error handling).
    End If
End Sub

' NOTE: DB link items can be Nothing (that's OK).
'       Programmers should check for DB links being
'       Nothing when working with an ACCPACDBLinks
'       collection (i.e. in a "For...Each" loop).
' EXAMPLE:
'   For Each dbLink In UI.UIDBLinks
'       If (Not (dbLink Is Nothing)) Then
'                ' do something
'       End If
'   Next dbLink
Public Property Get Item(vntIndexKey As Variant) As AccpacDBLink
Attribute Item.VB_Description = "Returns the AccpacDBLink object as specified by its variable name on the UI (as a string) or a 1-based collection index."
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
        "ACCPACDBLinks" & vbCrLf & "Property: (Get)" _
        & " Item" & vbCrLf & "Argument: vntIndexKey" _
        & " = " & strIdx & vbCrLf & vbCrLf & _
        strErrOrigDesc
    
    ' Print a debug message (geared toward **UI**
    ' programmers) with error information and a note
    ' about the error's possible cause and solution.
    ' (Include extra newlines at beginning and end.)
    Debug.Print vbCrLf & "Error #" & CStr(lErrNum) & _
        " - [Source: " & strErrSource & "]" & vbCrLf _
        & strErrNewDesc & vbCrLf & vbCrLf & _
        DBLinksErrNote & vbCrLf
    
    ' RE-RAISE the error to let VB GPF (so macro
    ' programmers can see the error too).
    Err.Raise lErrNum, strErrSource, strErrNewDesc, _
        strErrHelpFile, lErrHelpContext
End Property

Public Property Get Count() As Long
Attribute Count.VB_Description = "Returns the number of AccpacDBLink objects contained in the collection."
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
        "ACCPACDBLinks" & vbCrLf & "Property: (Get)" _
        & " Count" & vbCrLf & vbCrLf & _
        strErrOrigDesc
    
    ' Print a debug message (geared toward **UI**
    ' programmers) with error information and a note
    ' about the error's possible cause and solution.
    ' (Include extra newlines at beginning and end.)
    Debug.Print vbCrLf & "Error #" & CStr(lErrNum) & _
        " - [Source: " & strErrSource & "]" & vbCrLf _
        & strErrNewDesc & vbCrLf & vbCrLf & _
        DBLinksErrNote & vbCrLf
    
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
        "ACCPACDBLinks" & vbCrLf & "Sub: Remove" & _
        vbCrLf & "Argument: vntIndexKey = " & strIdx _
        & vbCrLf & vbCrLf & strErrOrigDesc
    
    ' Print a debug message (geared toward **UI**
    ' programmers) with error information and a note
    ' about the error's possible cause and solution.
    ' (Include extra newlines at beginning and end.)
    Debug.Print vbCrLf & "Error #" & CStr(lErrNum) & _
        " - [Source: " & strErrSource & "]" & vbCrLf _
        & strErrNewDesc & vbCrLf & vbCrLf & _
        DBLinksErrNote & vbCrLf
    
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
        "ACCPACDBLinks" & vbCrLf & "Property: (Get)" _
        & " NewEnum" & vbCrLf & vbCrLf & _
        strErrOrigDesc
    
    ' Print a debug message (geared toward **UI**
    ' programmers) with error information and a note
    ' about the error's possible cause and solution.
    ' (Include extra newlines at beginning and end.)
    Debug.Print vbCrLf & "Error #" & CStr(lErrNum) & _
        " - [Source: " & strErrSource & "]" & vbCrLf _
        & strErrNewDesc & vbCrLf & vbCrLf & _
        DBLinksErrNote & vbCrLf
    
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
