VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "ACCPACDSControl"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Attribute VB_Description = "ACCPAC data source wrapper class"
Attribute VB_Ext_KEY = "SavedWithClassBuilder6" ,"Yes"
Attribute VB_Ext_KEY = "Top_Level" ,"Yes"
' ACCPAC UI DEVELOPERS: DO NOT MODIFY THIS FILE!
'
' Class Module: ACCPACDSControl
' Template 5.4A Revision: cycle 26
'
' Description: Wrapper class for data source
'              controls that exposes only a subset
'              of a data source control's methods
'              and properties.
'
' Exposed Methods: - BlkGet
'                  - BlkGetFields
'                  - BlkPut
'                  - Browse
'                  - Cancel
'                  - Clone
'                  - CloneEx
'                  - Delete
'                  - Fetch
'                  - FetchLock
'                  - FilterDelete
'                  - FilterFetch
'                  - FilterSelect
'                  - GetComposedView
'                  - GetControl
'                  - GetLookupValue
'                  - GoBottom
'                  - GoNext
'                  - GoPrev
'                  - GoToBookMark
'                  - GoTop
'                  - GoToRecordNumber
'                  - Init
'                  - InitPrimaryKeyFields
'                  - Insert
'                  - Post
'                  - Process
'                  - Read
'                  - ReadLock
'                  - RecordClear
'                  - RecordGenerate
'                  - RegisterLookup
'                  - RegisterLookupInstance
'                  - ReloadPropertyFilter
'                  - ResetRecordNumbers
'                  - RevisionCancel
'                  - RevisionExists
'                  - RevisionPost
'                  - RevisionUnposted
'                  - SetFireEvents
'                  - TableEmpty
'                  - UnLockView
'                  - UnregisterLookup
'                  - Update
'                  - Verify
'
' Exposed Properties: - Active (Read-only)
'                     - BrowseAscending (Read-only)
'                     - BrowseFilter (Read-only)
'                     - ComposeViewIDs (Read-only)
'                     - ComposeViewIDsArray (Read-only)
'                     - CompositeNames (Read-only)
'                     - DBLink (Read-only)
'                     - DBLinkFlag (Read-only)
'                     - DBLinkType (Read-only)
'                     - Description (Read-only)
'                     - Dirty (Read-only)
'                     - DisplayName (Read-only)
'                     - DSSession (Read-only)
'                     - Exists (Read-only)
'                     - Fields (Read-only)
'                     - FireOnKeyChanged
'                     - FireOnKeyChanging
'                     - FireOnRecordChanged
'                     - FireOnRecordChanging
'                     - InstanceExtra (Read-only)
'                     - InstanceNonheritable (Read-only)
'                     - InstanceNotify (Read-only)
'                     - InstancePrefetch (Read-only)
'                     - InstanceReadonly (Read-only)
'                     - InstanceSecurity (Read-only)
'                     - InstanceUnrevisioned (Read-only)
'                     - InstanceUnvalidated (Read-only)
'                     - Keys (Read-only)
'                     - LastReturnCode (Read-only)
'                     - Name (Read-only)
'                     - Order
'                     - ParentName (Read-only)
'                     - ProgramName (Read-only)
'                     - PropertyFilter (Read-only)
'                     - RecordBookMark (Read-only)
'                     - RecordNumber (Read-only)
'                     - ReferentialIntegrity
'                     - Security (Read-only)
'                     - SystemAccess
'                     - TemplateDate (Read-only)
'                     - TemplateVersion (Read-only)
'                     - UnpostedRevisions (Read-only)
'                     - UseOpenViewInstance (Read-only)
'                     - UseProcessServer (Read-only)
'                     - UseRecordNumbering (Read-only)
'                     - View (Read-only)
'                     - ViewID (Read-only)
'                     - ViewType (Read-only)
'
' Exposed Events: - OnActivate
'                 - OnKeyChanged
'                 - OnKeyChanging
'                 - OnRecordChanged
'                 - OnRecordChanging
'
' Copyright 1999-2006 Sage Accpac International, Inc.
'   All rights reserved.
'

Option Compare Text
Option Explicit

' Variable to hold the data source control
Private WithEvents mDataSource As AccpacDataSource
Attribute mDataSource.VB_VarHelpID = -1


'---------------------------------------------------
' Exposed Event Declarations
'---------------------------------------------------

Public Event OnActivate(ByVal bActive As Boolean)
Attribute OnActivate.VB_Description = "Fired after the underlying DataSource is activated or deactivated."
Public Event OnKeyChanged(ByVal eReason As tagEventReason, _
                          ByVal pField As IAccpacDSField, _
                          ByVal pMultipleFields As IAccpacDSFields)
Attribute OnKeyChanged.VB_Description = "Fired after an operation that changed the key field(s) of the current record.  This event is fired after OnRecordChanged."
Public Event OnKeyChanging(ByVal eReason As tagEventReason, _
                           ByRef pStatus As tagEventStatus, _
                           ByVal pField As IAccpacDSField, _
                           ByVal pMultipleFields As IAccpacDSFields)
Attribute OnKeyChanging.VB_Description = "Fired before an operation that would change the key field(s) of the current record.  The pStatus flag could be set to cancel the operation."
Public Event OnRecordChanged(ByVal eReason As tagEventReason, _
                             ByVal pField As IAccpacDSField, _
                             ByVal pMultipleFields As IAccpacDSFields)
Attribute OnRecordChanged.VB_Description = "Fired after an operation that changed the current record.  This event is fired before OnKeyChanged."
Public Event OnRecordChanging(ByVal eReason As tagEventReason, _
                              ByRef pStatus As tagEventStatus, _
                              ByVal pField As IAccpacDSField, _
                              ByVal pMultipleFields As IAccpacDSFields)
Attribute OnRecordChanging.VB_Description = "Fired before an operation that would change the current record.  The pStatus flag could be set to cancel the operation."


'---------------------------------------------------
' Class Initialization/Termination
'---------------------------------------------------

' NO NEED FOR ERROR HANDLING!
Private Sub Class_Initialize()
    Set mDataSource = Nothing
End Sub

Private Sub Class_Terminate()
On Error Resume Next
    Set mDataSource = Nothing
    Err.Clear
End Sub


'---------------------------------------------------
' Friend Method
'---------------------------------------------------

' "Set-once" method (set by collection's "Add" sub).
' This should NOT be called anywhere else.

Friend Sub SetupInstance(ByVal ds As AccpacDataSource)
On Error Resume Next
    If mDataSource Is Nothing Then
        Set mDataSource = ds
    End If
    
    ' Inline error handler (GETS OUT of the sub but
    ' DOESN'T clear the error)
    If Err.Number <> 0 Then
        DSACCPACErrorHandler mDataSource, _
            "SetupInstance", ptSub, _
            "Wrapped Data Source Not Set"
        Exit Sub
    End If
    
    ' IF WE GOT TO HERE, WE SET THE WRAPPED DATA
    ' SOURCE.
End Sub


'---------------------------------------------------
' Friend Property
'---------------------------------------------------

' This can only be read from modules that are
' inside the ACCPAC UI Control's own project.

'Friend Property Get WrappedDS() As AccpacDataSource
'On Error Resume Next
'    Set WrappedDS = mDataSource
'
'    ' Inline error handler
'    If Err.Number <> 0 Then
'        DSACCPACErrorHandler mDataSource, _
'            "WrappedDS", ptPropertyGet, _
'            "Unspecified Error"
'    End If
'End Property


'---------------------------------------------------
' Exposed Methods
'---------------------------------------------------

' Need to be NON-NULL: FieldIDs
Public Function BlkGet(ByVal FieldIDs As Variant) _
                                        As Variant
Attribute BlkGet.VB_Description = "Performs a block get of field values of the specified array of fields IDs.  Returns the array of field values."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        If IsObject(mDataSource.BlkGet(FieldIDs)) Then
            Set BlkGet = mDataSource.BlkGet(FieldIDs)
        Else
            BlkGet = mDataSource.BlkGet(FieldIDs)
        End If
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "BlkGet", ptFunction, _
                mDataSource.Name, _
                "Argument: FieldIDs (Variant)"
            ' Returns "Empty" by default
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
    ' ELSE: returns "Empty" by default
End Function

' Need to be NON-NULL: FieldIDs
Public Function BlkGetFields(ByVal FieldIDs As Variant) _
                                        As Variant
Attribute BlkGetFields.VB_Description = "Performs a block get of field objects of the specified array of fields IDs.  Returns the array of DataSource field objects."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        If IsObject(mDataSource.BlkGetFields(FieldIDs)) Then
            Set BlkGetFields = mDataSource.BlkGetFields(FieldIDs)
        Else
            BlkGetFields = mDataSource.BlkGetFields(FieldIDs)
        End If
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "BlkGetFields", ptFunction, _
                mDataSource.Name, _
                "Argument: FieldIDs (Variant)"
            ' Returns "Empty" by default
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
    ' ELSE: returns "Empty" by default
End Function

' Need to be NON-NULL: FieldIDs, pValues
Public Sub BlkPut(ByVal FieldIDs As Variant, _
                  ByVal pValues As Variant, _
                  ByVal Verify As Boolean)
Attribute BlkPut.VB_Description = "Performs a block put of the specified array of field values to the array of field IDs."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        mDataSource.BlkPut FieldIDs, pValues, Verify
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "BlkPut", ptSub, mDataSource.Name, _
                "Arguments: FieldIDs (Variant), " & _
                "pValues (Variant), Verify = " & _
                CStr(Verify)
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Sub

Public Sub Browse(ByVal bstrFilter As String, _
                  ByVal Ascending As Boolean)
Attribute Browse.VB_Description = "Establishes the browse filter and direction that affects all subsequent navigation routines."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        mDataSource.Browse bstrFilter, Ascending
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "Browse", ptSub, mDataSource.Name, _
                "Arguments: bstrFilter = " & _
                bstrFilter & ", Ascending = " & _
                CStr(Ascending)
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Sub

Public Sub Cancel()
Attribute Cancel.VB_Description = "Cancels any updates to the current record and reloads the record from the database."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        mDataSource.Cancel
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "Cancel", ptSub, mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Sub

' NOTE: ActiveX controls (such as AccpacDataSources)
'       can't be passed/returned to external
'       components as the control type.  They can
'       only be passed/returned as type Object.
Public Function Clone() As Object
Attribute Clone.VB_Description = "Creates a clone of the current underlying AccpacDataSource object."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        Set Clone = mDataSource.Clone
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "Clone", ptFunction, _
                mDataSource.Name
            ' Returns "Nothing" by default
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
    ' ELSE: returns "Nothing" by default
End Function

' NOTE: ActiveX controls (such as AccpacDataSources)
'       can't be passed/returned to external
'       components as the control type.  They can
'       only be passed/returned as type Object.
Public Function CloneEx(ByVal Activate As Boolean) _
                                        As Object
Attribute CloneEx.VB_Description = "Creates a clone of the current underlying AccpacDataSource object.  The Activate flag specifies whether or not the clone should be activated."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        Set CloneEx = mDataSource.CloneEx(Activate)
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "CloneEx", ptFunction, _
                mDataSource.Name, "Argument: " & _
                "Activate = " & CStr(Activate)
            ' Returns "Nothing" by default
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
    ' ELSE: returns "Nothing" by default
End Function

Public Sub Delete()
Attribute Delete.VB_Description = "Deletes the current record from the view."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        mDataSource.Delete
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "Delete", ptSub, mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Sub

Public Function Fetch() As Boolean
Attribute Fetch.VB_Description = "Fetches the next record according to the current Browse filter and direction.  Returns whether a record is fetched or not."
On Error Resume Next
    If mDataSource Is Nothing Then
        Fetch = False  ' unsuccessful
    Else
        Fetch = mDataSource.Fetch
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "Fetch", ptFunction, _
                mDataSource.Name
            Fetch = False  ' unsuccessful
        End If  ' Err.Number <> 0
    End If  ' mDataSource Is Nothing
End Function

Public Function FetchLock() As Boolean
Attribute FetchLock.VB_Description = "Fetches the next record according to the current Browse filter and direction, and locks the record. Returns whether a record is fetched or not."
On Error Resume Next
    If mDataSource Is Nothing Then
        FetchLock = False  ' unsuccessful
    Else
        FetchLock = mDataSource.FetchLock
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "FetchLock", ptFunction, _
                mDataSource.Name
            FetchLock = False  ' unsuccessful
        End If  ' Err.Number <> 0
    End If  ' mDataSource Is Nothing
End Function

Public Sub FilterDelete(ByVal bstrFilter As String, _
        ByVal strictness As tagFilterStrictnessEnum)
Attribute FilterDelete.VB_Description = "Deletes the specified set of records from the view."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        mDataSource.FilterDelete bstrFilter, _
            strictness
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "FilterDelete", ptSub, _
                mDataSource.Name, "Arguments: " & _
                "bstrFilter = " & bstrFilter & ", " & _
                "strictness = " & CStr(strictness)
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Sub

Public Function FilterFetch(ByVal bLock As Boolean) _
                                        As Boolean
Attribute FilterFetch.VB_Description = "Does the equivalent of GoNext, but bLock can be set to TRUE to lock the fetched record.  Returns whether the current record is moved or not."
On Error Resume Next
    If mDataSource Is Nothing Then
        FilterFetch = False  ' unsuccessful
    Else
        FilterFetch = mDataSource.FilterFetch(bLock)
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "FilterFetch", ptFunction, _
                mDataSource.Name, "Argument: " & _
                "bLock = " & CStr(bLock)
            FilterFetch = False  ' unsuccessful
        End If  ' Err.Number <> 0
    End If  ' mDataSource Is Nothing
End Function

Public Sub FilterSelect(ByVal bstrFilter As String, _
                ByVal Ascending As Boolean, _
                ByVal lOrder As Long, _
                ByVal origin As tagFilterOriginEnum)
Attribute FilterSelect.VB_Description = "Establishes the browse filter, direction, and origin that affect all subsequent navigation routines."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        mDataSource.FilterSelect bstrFilter, _
            Ascending, lOrder, origin
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "FilterSelect", ptSub, _
                mDataSource.Name, "Arguments: " & _
                "bstrFilter = " & bstrFilter & "," & _
                vbCrLf & "             Ascending = " _
                & CStr(Ascending) & ", lOrder = " & _
                CStr(lOrder) & ", Origin = " & _
                CStr(origin)
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Sub

Public Function GetComposedView(ByVal bstrName As String) _
                                    As AccpacView
Attribute GetComposedView.VB_Description = "Returns the AccpacView object composed to the internal view according the View ID.  Returns NULL if the View ID specified is not a view composed to the internal view."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        Set GetComposedView = mDataSource.GetComposedView(bstrName)
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "GetComposedView", ptFunction, _
                mDataSource.Name, _
                "Argument: bstrName = " & bstrName
            ' Returns "Nothing" by default
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
    ' ELSE: returns "Nothing" by default
End Function

' This function returns the underlying control as an
' object, so that advanced macros can access a wider
' range of methods/properties as late-bound calls.
' NOTE: Data sources can only be passed to external
'       components as type Object.
Public Function GetControl() As Object
Attribute GetControl.VB_Description = "WARNING: THIS METHOD IS BEST SUITED FOR ADVANCED MACRO PROGRAMMERS.\r\nReturns the underlying data source as an object, allowing late-bound access to its methods and properties."
On Error Resume Next
    Set GetControl = mDataSource
    
    ' Inline error handler
    If Err.Number <> 0 Then
        DSACCPACErrorHandler mDataSource, _
            "GetControl", ptFunction, _
            mDataSource.Name
        ' Returns "Nothing" by default
    End If  ' Err.Number <> 0
End Function

Public Function GetLookupValue(ByVal Cookie As Long) _
                                        As Variant
Attribute GetLookupValue.VB_Description = "Returns the current Lookup value according to the cookie returned by RegisterLookup."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        If IsObject(mDataSource.GetLookupValue(Cookie)) Then
            Set GetLookupValue = mDataSource.GetLookupValue(Cookie)
        Else
            GetLookupValue = mDataSource.GetLookupValue(Cookie)
        End If
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "GetLookupValue", ptFunction, _
                mDataSource.Name, _
                "Argument: Cookie = " & CStr(Cookie)
            ' Returns "Empty" by default
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
    ' ELSE: returns "Empty" by default
End Function

Public Function GoBottom() As Boolean
Attribute GoBottom.VB_Description = "Navigates to the last record in the set of records according to the current browse filter and direction.  Returns whether the current record is moved or not."
On Error Resume Next
    If mDataSource Is Nothing Then
        GoBottom = False  ' unsuccessful
    Else
        GoBottom = mDataSource.GoBottom
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "GoBottom", ptFunction, _
                mDataSource.Name
            GoBottom = False  ' unsuccessful
        End If  ' Err.Number <> 0
    End If  ' mDataSource Is Nothing
End Function

Public Function GoNext() As Boolean
Attribute GoNext.VB_Description = "Navigates to the next record in the set of records according to the current browse filter and direction.  Returns whether the current record is moved or not."
On Error Resume Next
    If mDataSource Is Nothing Then
        GoNext = False  ' unsuccessful
    Else
        GoNext = mDataSource.GoNext
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "GoNext", ptFunction, _
                mDataSource.Name
            GoNext = False  ' unsuccessful
        End If  ' Err.Number <> 0
    End If  ' mDataSource Is Nothing
End Function

Public Function GoPrev() As Boolean
Attribute GoPrev.VB_Description = "Navigates to the previous record in the set of records according to the current browse filter and direction.  Returns whether the current record is moved or not."
On Error Resume Next
    If mDataSource Is Nothing Then
        GoPrev = False  ' unsuccessful
    Else
        GoPrev = mDataSource.GoPrev
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "GoPrev", ptFunction, _
                mDataSource.Name
            GoPrev = False  ' unsuccessful
        End If  ' Err.Number <> 0
    End If  ' mDataSource Is Nothing
End Function

' Need to be NON-NULL: pBookMark
Public Function GoToBookMark(ByVal pBookMark As Variant) _
                                        As Boolean
Attribute GoToBookMark.VB_Description = "Navigates to the record as specified by the bookmark that is obtained from the RecordBookmark property from a previous record that was navigated to."
On Error Resume Next
    If mDataSource Is Nothing Then
        GoToBookMark = False  ' unsuccessful
    Else
        GoToBookMark = mDataSource.GoToBookMark(pBookMark)
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "GoToBookMark", ptFunction, _
                mDataSource.Name, _
                "Argument: pBookMark (Variant)"
            GoToBookMark = False  ' unsuccessful
        End If  ' Err.Number <> 0
    End If  ' mDataSource Is Nothing
End Function

Public Function GoTop() As Boolean
Attribute GoTop.VB_Description = "Navigates to the first record in the set of records according to the current browse filter and direction.  Returns whether the current record is moved or not."
On Error Resume Next
    If mDataSource Is Nothing Then
        GoTop = False  ' unsuccessful
    Else
        GoTop = mDataSource.GoTop
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "GoTop", ptFunction, _
                mDataSource.Name
            GoTop = False  ' unsuccessful
        End If  ' Err.Number <> 0
    End If  ' mDataSource Is Nothing
End Function

Public Function GoToRecordNumber(ByVal lRecordNumber As Long) _
                                As Boolean
Attribute GoToRecordNumber.VB_Description = "Goes to the specified record number. Returns whether the record is found."
On Error Resume Next
    If mDataSource Is Nothing Then
        GoToRecordNumber = False  ' unsuccessful
    Else
        GoToRecordNumber = mDataSource.GoToRecordNumber(lRecordNumber)
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "GoToRecordNumber", ptFunction, _
                mDataSource.Name, _
                "Argument: lRecordNumber = " & _
                CStr(lRecordNumber)
            GoToRecordNumber = False  ' unsuccessful
        End If  ' Err.Number <> 0
    End If  ' mDataSource Is Nothing
End Function

Public Sub Init()
Attribute Init.VB_Description = "Initializes the record."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        mDataSource.Init
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "Init", ptSub, mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Sub

Public Sub InitPrimaryKeyFields(ByVal Bookmark As Variant)
Attribute InitPrimaryKeyFields.VB_Description = "Initializes the primary key field values using the same key fields of the record as specified by the bookmark."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        mDataSource.InitPrimaryKeyFields Bookmark
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "InitPrimaryKeyFields", ptSub, _
                mDataSource.Name, "Argument: " & _
                "Bookmark (Variant)"
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Sub

Public Sub Insert()
Attribute Insert.VB_Description = "Inserts the current record into the view."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        mDataSource.Insert
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "Insert", ptSub, mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Sub

Public Sub Post()
Attribute Post.VB_Description = "Calls the Post method in the view."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        mDataSource.Post
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "Post", ptSub, mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Sub

Public Sub Process()
Attribute Process.VB_Description = "Calls the Process method in the view."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        mDataSource.Process
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "Process", ptSub, mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Sub

Public Function Read() As Boolean
Attribute Read.VB_Description = "Reads the record as specified by the current key field values. Returns whether the record is located or not."
On Error Resume Next
    If mDataSource Is Nothing Then
        Read = False  ' unsuccessful
    Else
        Read = mDataSource.Read
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "Read", ptFunction, mDataSource.Name
            Read = False  ' unsuccessful
        End If  ' Err.Number <> 0
    End If  ' mDataSource Is Nothing
End Function

Public Function ReadLock() As Boolean
Attribute ReadLock.VB_Description = "Reads the record as specified by the current key field values and if found, locks the record. Returns whether the record is located or not."
On Error Resume Next
    If mDataSource Is Nothing Then
        ReadLock = False  ' unsuccessful
    Else
        ReadLock = mDataSource.ReadLock
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "ReadLock", ptFunction, _
                mDataSource.Name
            ReadLock = False  ' unsuccessful
        End If  ' Err.Number <> 0
    End If  ' mDataSource Is Nothing
End Function

Public Sub RecordClear()
Attribute RecordClear.VB_Description = "Blanks, zeroes, or defaults the fields in the view."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        mDataSource.RecordClear
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "RecordClear", ptSub, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Sub

Public Sub RecordGenerate(ByVal bInsert As Boolean)
Attribute RecordGenerate.VB_Description = "Generates a unique nonexistent key, and blanks, zeroes, or defaults the remaining fields in the view."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        mDataSource.RecordGenerate bInsert
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "RecordGenerate", ptSub, _
                mDataSource.Name, "Argument: " & _
                "bInsert = " & CStr(bInsert)
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Sub

Public Function RegisterLookup(ByVal SourceFieldIDOrArrayOfIDs As Variant, _
                    ByVal TargetViewID As String, _
                    ByVal TargetViewOrder As Long, _
                    ByVal TargetDBLinkType As tagDBLinkTypeEnum, _
                    ByVal TargetFieldIDOrArrayOfIDs As Variant, _
                    ByVal TargetLookupFieldID As Long) _
                    As Long
Attribute RegisterLookup.VB_Description = "Registers a Lookup on the underlying DataSource.  Returns a cookie that represents the lookup."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        RegisterLookup = mDataSource.RegisterLookup( _
                        SourceFieldIDOrArrayOfIDs, _
                        TargetViewID, _
                        TargetViewOrder, _
                        TargetDBLinkType, _
                        TargetFieldIDOrArrayOfIDs, _
                        TargetLookupFieldID)
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "RegisterLookup", ptFunction, _
                mDataSource.Name, "Arguments: " & _
                "SourceFieldIDOrArrayOfIDs " & _
                "(Variant), TargetViewID = " & _
                TargetViewID & "," & vbCrLf & _
                "             TargetViewOrder = " & _
                CStr(TargetViewOrder) & ", " & _
                "TargetDBLinkType = " & _
                CStr(TargetDBLinkType) & "," & _
                vbCrLf & "             " & _
                "TargetFieldIDOrArrayOfIDs " & _
                "(Variant), TargetLookupFieldID = " _
                & CStr(TargetLookupFieldID)
            ' Returns 0 by default
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
    ' ELSE: returns 0 by default
End Function

Public Function RegisterLookupInstance(ByVal SourceFieldIDOrArrayOfIDs As Variant, _
        ByVal TargetViewID As String, _
        ByVal TargetViewOrder As Long, _
        ByVal TargetDBLinkType As tagDBLinkTypeEnum, _
        ByVal TargetFieldIDOrArrayOfIDs As Variant, _
        ByVal TargetLookupFieldID As Long, _
        Optional ByVal ReadOnly As Boolean, _
        Optional ByVal Unvalidated As Boolean, _
        Optional ByVal Unrevisioned As Boolean, _
        Optional ByVal Nonheritable As Boolean, _
        Optional ByVal Prefetch As Long, _
        Optional ByVal RawPut As Boolean, _
        Optional ByVal Noncascading As Boolean, _
        Optional ByVal extra As Variant) _
        As Long
Attribute RegisterLookupInstance.VB_Description = "Registers a Lookup on the underlying DataSource, specifiying how the target view instance should be opened.  Returns a cookie that represents the lookup."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        RegisterLookupInstance = _
            mDataSource.RegisterLookupInstance( _
                SourceFieldIDOrArrayOfIDs, _
                TargetViewID, TargetViewOrder, _
                TargetDBLinkType, _
                TargetFieldIDOrArrayOfIDs, _
                TargetLookupFieldID, ReadOnly, _
                Unvalidated, Unrevisioned, _
                Nonheritable, Prefetch, RawPut, _
                Noncascading, extra)
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "RegisterLookupInstance", _
                ptFunction, mDataSource.Name, _
                "Arguments: " & _
                "SourceFieldIDOrArrayOfIDs " & _
                "(Variant), TargetViewID = " & _
                TargetViewID & "," & vbCrLf & _
                "             TargetViewOrder = " & _
                CStr(TargetViewOrder) & ", " & _
                "TargetDBLinkType = " & _
                CStr(TargetDBLinkType) & "," & _
                vbCrLf & "             " & _
                "TargetFieldIDOrArrayOfIDs " & _
                "(Variant), TargetLookupFieldID = " _
                & CStr(TargetLookupFieldID) & "," & _
                vbCrLf & "             (Other " & _
                "Optional Arguments)"
            ' Returns 0 by default
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
    ' ELSE: returns 0 by default
End Function

Public Function ReloadPropertyFilter() As Boolean
Attribute ReloadPropertyFilter.VB_Description = "Causes the underlying DataSource to reload the PropertyFilter property from ACCPAC properties according to the ProgramName property."
On Error Resume Next
    If mDataSource Is Nothing Then
        ReloadPropertyFilter = False  ' no property filter change
    Else
        ReloadPropertyFilter = mDataSource.ReloadPropertyFilter
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "ReloadPropertyFilter", ptFunction, _
                mDataSource.Name
            ReloadPropertyFilter = False  ' no property filter change
        End If  ' Err.Number <> 0
    End If  ' mDataSource Is Nothing
End Function

Public Sub ResetRecordNumbers()
Attribute ResetRecordNumbers.VB_Description = "Resets all generated record numbers. Record numbers would be regenerated the next time any method is called that positions to a record."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        mDataSource.ResetRecordNumbers
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "ResetRecordNumbers", ptSub, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Sub

Public Sub RevisionCancel(ByVal level As Long)
Attribute RevisionCancel.VB_Description = "Rolls back any pending changes to the specified revision level, possibly the database."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        mDataSource.RevisionCancel level
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "RevisionCancel", ptSub, _
                mDataSource.Name, "Argument: " & _
                "level = " & CStr(level)
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Sub

Public Function RevisionExists(ByVal level As Long) _
                                        As Boolean
Attribute RevisionExists.VB_Description = "Returns whether or not the current record exists within the specified revision level, possibly the database."
On Error Resume Next
    If mDataSource Is Nothing Then
        RevisionExists = False  ' unsuccessful
    Else
        RevisionExists = mDataSource.RevisionExists(level)
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "RevisionExists", ptFunction, _
                mDataSource.Name, "Argument: " & _
                "level = " & CStr(level)
            RevisionExists = False  ' unsuccessful
        End If  ' Err.Number <> 0
    End If  ' mDataSource Is Nothing
End Function

Public Sub RevisionPost(ByVal level As Long)
Attribute RevisionPost.VB_Description = "Commits any pending changes to the specified revision level, possibly the database."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        mDataSource.RevisionPost level
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "RevisionPost", ptSub, _
                mDataSource.Name, "Argument: " & _
                "level = " & CStr(level)
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Sub

Function RevisionUnposted(ByVal level As Long) _
                                    As Boolean
Attribute RevisionUnposted.VB_Description = "Returns whether or not the specified revision level has unposted changes."
On Error Resume Next
    If mDataSource Is Nothing Then
        RevisionUnposted = False  ' unsuccessful
    Else
        RevisionUnposted = mDataSource.RevisionUnposted(level)
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "RevisionUnposted", ptFunction, _
                mDataSource.Name, "Argument: " & _
                "level = " & CStr(level)
            RevisionUnposted = False  ' unsuccessful
        End If  ' Err.Number <> 0
    End If  ' mDataSource Is Nothing
End Function

Public Sub SetFireEvents(ByVal FireEvents As Boolean)
Attribute SetFireEvents.VB_Description = "Sets the FireOnKeyChanging, FireOnKeyChanged, FireOnRecordChanging and FireOnRecordChanged properties of the underlying DataSource all at once."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        mDataSource.SetFireEvents FireEvents
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "SetFireEvents", ptSub, _
                mDataSource.Name, "Argument: " & _
                "FireEvents = " & CStr(FireEvents)
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Sub

Public Sub TableEmpty()
Attribute TableEmpty.VB_Description = "Deletes all records from the view by the fastest method available."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        mDataSource.TableEmpty
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "TableEmpty", ptSub, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Sub

' NOTE: We can't use "UnLock" as a sub, so it's
'       changed to "UnLockView".
Public Sub UnLockView()
Attribute UnLockView.VB_Description = "Unlocks the current record if it is previously locked by calling FetchLock or ReadLock."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        mDataSource.UnLock
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "UnLockView", ptSub, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Sub

Public Sub UnregisterLookup(ByVal Cookie As Long)
Attribute UnregisterLookup.VB_Description = "Unregisters the Lookup (identified by the cookie) on the underlying DataSource."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        mDataSource.UnregisterLookup Cookie
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "UnregisterLookup", ptSub, _
                mDataSource.Name, _
                "Argument: Cookie = " & CStr(Cookie)
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Sub

Public Sub Update()
Attribute Update.VB_Description = "Updates the current record."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        mDataSource.Update
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "Update", ptSub, mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Sub

Public Sub Verify()
Attribute Verify.VB_Description = "Verifies the current record's field values."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        mDataSource.Verify
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "Verify", ptSub, mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Sub


'---------------------------------------------------
' Exposed Properties
'---------------------------------------------------

' (Read-only)
' This property tries to return an ACCPACDSControl's
' name as a combination of the original data source
' control's name and index in a control array (i.e.
' acting as if the original data source control was
' part of a control array).  If the original data
' source control isn't part of a control array, this
' property uses error handling to set the
' ACCPACDSControl's name as just its original name.
Public Property Get Name() As String
Attribute Name.VB_Description = "Returns the underlying DataSource's variable name (including the index within parentheses if it's part of a control array)."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        Name = mDataSource.Name & "(" & _
            mDataSource.Index & ")"
        
        Select Case Err.Number
            Case 0
                ' No error: data source is part of a
                ' control array
            Case 343  ' not part of control array
                ' We can fix "not part of control
                ' array" , so clear the error, then
                ' try to return just the name.
                Err.Clear
                Name = mDataSource.Name  ' return only name
                
                ' Handle any NEW errors from "Name =
                ' mDataSource.Name"
                If Err.Number <> 0 Then
                    DSACCPACErrorHandler _
                        mDataSource, "Name", _
                        ptPropertyGet, "Wrapped " & _
                        "Data Source Has No Name"
                End If
            Case Else
                ' Handle any UNKNOWN errors from the
                ' FIRST attempt at setting "Name"
                DSACCPACErrorHandler mDataSource, _
                    "Name", ptPropertyGet, "Wrapped" _
                    & " Data Source Has No Name"
        End Select
    End If
End Property

' (Read-only)
Public Property Get Active() As Boolean
Attribute Active.VB_Description = "Returns a value that tells whether or not the underlying DataSource is activated."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        Active = mDataSource.Active
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "Active", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get BrowseAscending() As Boolean
Attribute BrowseAscending.VB_Description = "Returns the Ascending flag used in the last call to the Browse method."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        BrowseAscending = mDataSource.BrowseAscending
    
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "BrowseAscending", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get BrowseFilter() As String
Attribute BrowseFilter.VB_Description = "Returns the filter used in the last call to the Browse method."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        BrowseFilter = mDataSource.BrowseFilter
    
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "BrowseFilter", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get ComposeViewIDs() As String
Attribute ComposeViewIDs.VB_Description = "Returns a comma-delimited list of View IDs that the internal view would be automatically composed with."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        ComposeViewIDs = mDataSource.ComposeViewIDs
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "ComposeViewIDs", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get ComposeViewIDsArray() As Variant
Attribute ComposeViewIDsArray.VB_Description = "Returns an array of View IDs that the internal view would be automatically composed with."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        If IsObject(mDataSource.ComposeViewIDsArray) Then
            Set ComposeViewIDsArray = mDataSource.ComposeViewIDsArray
        Else
            ComposeViewIDsArray = mDataSource.ComposeViewIDsArray
        End If
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "ComposeViewIDsArray", _
                ptPropertyGet, mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get CompositeNames() As AccpacViewCompositeNames
Attribute CompositeNames.VB_Description = "Returns the AccpacViewCompositeNames object that contains the composition information as defined in the view."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        Set CompositeNames = mDataSource.CompositeNames
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "CompositeNames", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get DBLink() As AccpacDBLink
Attribute DBLink.VB_Description = "Returns the company or system AccpacDBLink object depending on the DBLinkType property."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        Set DBLink = mDataSource.DBLink
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "DBLink", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get DBLinkFlag() As tagDBLinkFlagsEnum
Attribute DBLinkFlag.VB_Description = "Returns the DBLink flag to use."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        DBLinkFlag = mDataSource.DBLinkFlag
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "DBLinkFlag", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get DBLinkType() As tagDBLinkTypeEnum
Attribute DBLinkType.VB_Description = "Returns the type of the DBLink to use."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        DBLinkType = mDataSource.DBLinkType
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "DBLinkType", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get Description() As String
Attribute Description.VB_Description = "Returns the description of the view."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        Description = mDataSource.Description
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "Description", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get Dirty() As Boolean
Attribute Dirty.VB_Description = "Returns whether the current record is dirty or not."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        Dirty = mDataSource.Dirty
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "Dirty", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get DisplayName() As String
Attribute DisplayName.VB_Description = "Returns the name of the underlying DataSource known to the container."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        DisplayName = mDataSource.DisplayName
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "DisplayName", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get DSSession() As AccpacSession
Attribute DSSession.VB_Description = "Returns the AccpacSession object that the underlying DataSource is attached to."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        Set DSSession = mDataSource.Session
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "DSSession", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get Exists() As Boolean
Attribute Exists.VB_Description = "Returns whether the current record as identified by the key field values exists in the view or not."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        Exists = mDataSource.Exists
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "Exists", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get Fields() As AccpacDSFields
Attribute Fields.VB_Description = "Returns the AccpacDSFields collection object that represents all the fields in the view."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        Set Fields = mDataSource.Fields
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "Fields", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

Public Property Get FireOnKeyChanged() As Boolean
Attribute FireOnKeyChanged.VB_Description = "Returns/sets a value that enables/supresses firing of the underlying DataSource's OnKeyChanged event."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        FireOnKeyChanged = mDataSource.FireOnKeyChanged
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "FireOnKeyChanged", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

Public Property Let FireOnKeyChanged(ByVal bNewFOnKChgd As Boolean)
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        mDataSource.FireOnKeyChanged = bNewFOnKChgd
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "FireOnKeyChanged = " & _
                CStr(bNewFOnKChgd), ptPropertyLet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

Public Property Get FireOnKeyChanging() As Boolean
Attribute FireOnKeyChanging.VB_Description = "Returns/sets a value that enables/supresses firing of the underlying DataSource's OnKeyChanging event."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        FireOnKeyChanging = mDataSource.FireOnKeyChanging
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "FireOnKeyChanging", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

Public Property Let FireOnKeyChanging(ByVal bNewFOnKChging As Boolean)
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        mDataSource.FireOnKeyChanging = bNewFOnKChging
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "FireOnKeyChanging = " & _
                CStr(bNewFOnKChging), ptPropertyLet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

Public Property Get FireOnRecordChanged() As Boolean
Attribute FireOnRecordChanged.VB_Description = "Returns/sets a value that enables/supresses firing of the underlying DataSource's OnRecordChanged event."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        FireOnRecordChanged = mDataSource.FireOnRecordChanged
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "FireOnRecordChanged", _
                ptPropertyGet, mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

Public Property Let FireOnRecordChanged(ByVal bNewFOnRChgd As Boolean)
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        mDataSource.FireOnRecordChanged = bNewFOnRChgd
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "FireOnRecordChanged = " & _
                CStr(bNewFOnRChgd), ptPropertyLet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

Public Property Get FireOnRecordChanging() As Boolean
Attribute FireOnRecordChanging.VB_Description = "Returns/sets a value that enables/supresses firing of the underlying DataSource's OnRecordChanging event."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        FireOnRecordChanging = mDataSource.FireOnRecordChanging
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "FireOnRecordChanging", _
                ptPropertyGet, mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

Public Property Let FireOnRecordChanging(ByVal bNewFOnRChging As Boolean)
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        mDataSource.FireOnRecordChanging = bNewFOnRChging
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "FireOnRecordChanging = " & _
                CStr(bNewFOnRChging), ptPropertyLet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get InstanceExtra() As Variant
Attribute InstanceExtra.VB_Description = "Returns the extra unstructured data given to the view instance when it was first opened."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        If IsObject(mDataSource.InstanceExtra) Then
            Set InstanceExtra = mDataSource.InstanceExtra
        Else
            InstanceExtra = mDataSource.InstanceExtra
        End If
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "InstanceExtra", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get InstanceNonheritable() As Boolean
Attribute InstanceNonheritable.VB_Description = "Returns whether the composites that the view opens implicitly inherit the flags with which the view was opened."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        InstanceNonheritable = mDataSource.InstanceNonheritable
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "InstanceNonheritable", _
                ptPropertyGet, mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get InstanceNotify() As Boolean
Attribute InstanceNotify.VB_Description = "Returns whether or not notifications from the view are received by the underlying DataSource."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        InstanceNotify = mDataSource.InstanceNotify
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "InstanceNotify", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get InstancePrefetch() As Long
Attribute InstancePrefetch.VB_Description = "Returns the number of records fetched at a time when the view instance is read-only."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        InstancePrefetch = mDataSource.InstancePrefetch
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "InstancePrefetch", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get InstanceReadonly() As Boolean
Attribute InstanceReadonly.VB_Description = "Returns whether or not the view was opened for read-only access."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        InstanceReadonly = mDataSource.InstanceReadonly
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "InstanceReadonly", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get InstanceSecurity() As tagViewSecurityEnum
Attribute InstanceSecurity.VB_Description = "Returns the current access rights that the current user is assigned on the view."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        InstanceSecurity = mDataSource.InstanceSecurity
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "InstanceSecurity", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get InstanceUnrevisioned() As Boolean
Attribute InstanceUnrevisioned.VB_Description = "Returns whether or not the revisioning is suppressed."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        InstanceUnrevisioned = mDataSource.InstanceUnrevisioned
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "InstanceUnrevisioned", _
                ptPropertyGet, mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get InstanceUnvalidated() As Boolean
Attribute InstanceUnvalidated.VB_Description = "Returns whether or not the validations are suppressed."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        InstanceUnvalidated = mDataSource.InstanceUnvalidated
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "InstanceUnvalidated", _
                ptPropertyGet, mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get Keys() As AccpacDSKeys
Attribute Keys.VB_Description = "Returns the AccpacDSKeys collection object that represents all the keys in the view."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        Set Keys = mDataSource.Keys
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "Keys", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get LastReturnCode() As Long
Attribute LastReturnCode.VB_Description = "Returns the ACCPAC API return code of the last view operation."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        LastReturnCode = mDataSource.LastReturnCode
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "LastReturnCode", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

Public Property Get Order() As Long
Attribute Order.VB_Description = "Returns/sets the view index to use."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        Order = mDataSource.Order
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "Order", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

Public Property Let Order(ByVal lNewOrder As Long)
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        mDataSource.Order = lNewOrder
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "Order = " & CStr(lNewOrder), _
                ptPropertyLet, mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get ParentName() As String
Attribute ParentName.VB_Description = "Returns the name of the underlying DataSource's parent DataSource."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        ParentName = mDataSource.ParentName
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "ParentName", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get ProgramName() As String
Attribute ProgramName.VB_Description = "Returns the program name (e.g. CS1000) of the application containing the underlying DataSource object."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        ProgramName = mDataSource.ProgramName
    
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "ProgramName", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get PropertyFilter() As String
Attribute PropertyFilter.VB_Description = "Returns the filter to be used in subsequent Browse methods as saved in ACCPAC properties."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        PropertyFilter = mDataSource.PropertyFilter
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "PropertyFilter", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get RecordBookMark() As Variant
Attribute RecordBookMark.VB_Description = "Returns the bookmark of the current record that could be passed later on to the GotoBookmark method."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        If IsObject(mDataSource.RecordBookMark) Then
            Set RecordBookMark = mDataSource.RecordBookMark
        Else
            RecordBookMark = mDataSource.RecordBookMark
        End If
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "RecordBookMark", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get RecordNumber() As Long
Attribute RecordNumber.VB_Description = "Returns the record number of the current record."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        RecordNumber = mDataSource.RecordNumber
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "RecordNumber", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

Public Property Get ReferentialIntegrity() As tagReferentialIntegrityEnum
Attribute ReferentialIntegrity.VB_Description = "Returns/sets the referential integrity flag of the view."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        ReferentialIntegrity = mDataSource.ReferentialIntegrity
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "ReferentialIntegrity", _
                ptPropertyGet, mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

Public Property Let ReferentialIntegrity(ByVal tagNewRI As tagReferentialIntegrityEnum)
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        mDataSource.ReferentialIntegrity = tagNewRI
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "ReferentialIntegrity = " & _
                CStr(tagNewRI), ptPropertyLet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get Security() As Long
Attribute Security.VB_Description = "Returns the access rights the current user is assigned on the current view."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        Security = mDataSource.Security
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "Security", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

Public Property Get SystemAccess() As tagSystemAccessEnum
Attribute SystemAccess.VB_Description = "Returns/sets the system access flags of the view."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        SystemAccess = mDataSource.SystemAccess
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "SystemAccess", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

Public Property Let SystemAccess(ByVal tagNewSA As tagSystemAccessEnum)
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        mDataSource.SystemAccess = tagNewSA
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "SystemAccess = " & CStr(tagNewSA), _
                ptPropertyLet, mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get TemplateDate() As Date
Attribute TemplateDate.VB_Description = "Returns the date of the template used by the view."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        TemplateDate = mDataSource.TemplateDate
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "TemplateDate", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get TemplateVersion() As String
Attribute TemplateVersion.VB_Description = "Returns the version of the template used by the view."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        TemplateVersion = mDataSource.TemplateVersion
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "TemplateVersion", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get UnpostedRevisions() As Boolean
Attribute UnpostedRevisions.VB_Description = "Returns whether there are unposted revisions in the view."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        UnpostedRevisions = mDataSource.UnpostedRevisions
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "UnpostedRevisions", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get UseOpenViewInstance() As Boolean
Attribute UseOpenViewInstance.VB_Description = "Returns whether the view was opened with OpenViewInstance."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        UseOpenViewInstance = mDataSource.UseOpenViewInstance
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "UseOpenViewInstance", _
                ptPropertyGet, mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get UseProcessServer() As Boolean
Attribute UseProcessServer.VB_Description = "Returns whether the attached view is using the ProcessServer."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        UseProcessServer = mDataSource.UseProcessServer
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "UseProcessServer", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get UseRecordNumbering() As Boolean
Attribute UseRecordNumbering.VB_Description = "Returns whether record numbers would be generated for each record."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        UseRecordNumbering = mDataSource.UseRecordNumbering
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "UseRecordNumbering", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get View() As AccpacView
Attribute View.VB_Description = "Returns the internal AccpacView object that the underlying DataSource represents.  This is NULL if that DataSource is not active."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        Set View = mDataSource.View
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "View", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
Public Property Get ViewID() As String
Attribute ViewID.VB_Description = "Returns the ID (Roto ID) of the view that the underlying DataSource represents."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        ViewID = mDataSource.ViewID
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "ViewID", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property

' (Read-only)
' NOTE: We can't use "Type" as a property, so it's
'       changed to "ViewType".
Public Property Get ViewType() As tagRotoViewTypeEnum
Attribute ViewType.VB_Description = "Returns the type of the view that the underlying DataSource represents."
On Error Resume Next
    If (Not (mDataSource Is Nothing)) Then
        ViewType = mDataSource.Type
        
        ' Inline error handler
        If Err.Number <> 0 Then
            DSACCPACErrorHandler mDataSource, _
                "ViewType", ptPropertyGet, _
                mDataSource.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mDataSource Is Nothing)
End Property


'---------------------------------------------------
' Event Handlers Used For Exposing Events
'---------------------------------------------------
'
' NO NEED FOR ERROR HANDLING!
' (IF VB GPF'S, SO BE IT.)
'

Private Sub mDataSource_OnActivate(ByVal bActive As Boolean)
    RaiseEvent OnActivate(bActive)
End Sub

Private Sub mDataSource_OnKeyChanged( _
        ByVal eReason As AccpacCOMAPI.tagEventReason, _
        ByVal pField As AccpacDataSrcCtl.IAccpacDSField, _
        ByVal pMultipleFields As AccpacDataSrcCtl.IAccpacDSFields)
    RaiseEvent OnKeyChanged(eReason, pField, pMultipleFields)
End Sub

Private Sub mDataSource_OnKeyChanging( _
        ByVal eReason As AccpacCOMAPI.tagEventReason, _
        pStatus As AccpacCOMAPI.tagEventStatus, _
        ByVal pField As AccpacDataSrcCtl.IAccpacDSField, _
        ByVal pMultipleFields As AccpacDataSrcCtl.IAccpacDSFields)
    RaiseEvent OnKeyChanging(eReason, pStatus, pField, pMultipleFields)
End Sub

Private Sub mDataSource_OnRecordChanged( _
        ByVal eReason As AccpacCOMAPI.tagEventReason, _
        ByVal pField As AccpacDataSrcCtl.IAccpacDSField, _
        ByVal pMultipleFields As AccpacDataSrcCtl.IAccpacDSFields)
    RaiseEvent OnRecordChanged(eReason, pField, pMultipleFields)
End Sub

Private Sub mDataSource_OnRecordChanging( _
        ByVal eReason As AccpacCOMAPI.tagEventReason, _
        pStatus As AccpacCOMAPI.tagEventStatus, _
        ByVal pField As AccpacDataSrcCtl.IAccpacDSField, _
        ByVal pMultipleFields As AccpacDataSrcCtl.IAccpacDSFields)
    RaiseEvent OnRecordChanging(eReason, pStatus, pField, pMultipleFields)
End Sub
