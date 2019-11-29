VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "ACCPACControl"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = True
Attribute VB_Description = "Generic control wrapper class"
Attribute VB_Ext_KEY = "SavedWithClassBuilder6" ,"Yes"
Attribute VB_Ext_KEY = "Top_Level" ,"No"
' ACCPAC UI DEVELOPERS: DO NOT MODIFY THIS FILE!
'
' Class Module: ACCPACControl
' Template 5.3A Revision: cycle 22
'
' Description: Wrapper class for (non-data source)
'              controls that exposes only a subset
'              of a control's methods and properties
'              (with "safe" setting of the "Enabled"
'              and "Visible" properties, in the form
'              of the "MacroEnabledFlag" and
'              "MacroVisibleFlag" properties).
'
' Exposed Methods: - GetControl
'                  - Move (moves Left AND Top ONLY)
'                  - SetFocus
'
' Exposed Properties: - Caption
'                     - Container (Read-only)
'                     - Enabled (Read-only)
'                     - Height
'                     - Left
'                     - MacroEnabledFlag
'                     - MacroVisibleFlag
'                     - Name (Read-only)
'                     - TabIndex
'                     - TabStop (Read-only) [BUT has "Friend" Let]
'                     - Top
'                     - Value
'                     - Visible (Read-only)
'                     - Width
'
' Copyright 1999-2004 ACCPAC International, Inc.
'   All rights reserved.
'

Option Compare Text
Option Explicit

' Member to hold the (non-data source) control
' NOTE: We CAN'T have a "WithEvents" Control type
'       variable, so we can't handle events!!!
Private mControl As Control

' Private members for safely setting the "Enabled"
' and "Visible" properties
Private bCustWantsEnabled As Boolean
Private bCustWantsVisible As Boolean
Private bMacroWantsEnabled As Boolean
Private bMacroWantsVisible As Boolean
Private bTmplWantsEnabled As Boolean
Private bTmplWantsVisible As Boolean
Private bUIWantsEnabled As Boolean
Private bUIWantsVisible As Boolean


'---------------------------------------------------
' Class Initialization/Termination
'---------------------------------------------------

' NO NEED FOR ERROR HANDLING!
Private Sub Class_Initialize()
    ' Set the wrapped control to Nothing.
    Set mControl = Nothing
    
    ' Set the members for safely setting "Enabled"
    ' and "Visible" all to True (by default, we want
    ' controls to be enabled and visible).
    bCustWantsEnabled = True
    bCustWantsVisible = True
    bMacroWantsEnabled = True
    bMacroWantsVisible = True
    bTmplWantsEnabled = True
    bTmplWantsVisible = True
    bUIWantsEnabled = True
    bUIWantsVisible = True
End Sub

Private Sub Class_Terminate()
On Error Resume Next
    Set mControl = Nothing
    Err.Clear
End Sub


'---------------------------------------------------
' Friend Properties
'---------------------------------------------------

' Set-once property (set by collection's "Add" sub).
' This can only be read from modules that are
' inside the ACCPAC UI Control's own project.

Friend Property Get WrappedControl() As Control
On Error Resume Next
    Set WrappedControl = mControl
    
    ' Inline error handler
    If Err.Number <> 0 Then
        CtlACCPACErrorHandler "WrappedControl", _
            ptPropertyGet, "Unspecified Error"
    End If
End Property

Friend Property Set WrappedControl(ByVal ctl As _
        Control)
On Error Resume Next
    ' If property hasn't been set yet, do so.
    If mControl Is Nothing Then
        Set mControl = ctl
    End If
    
    ' Inline error handler
    If Err.Number <> 0 Then
        CtlACCPACErrorHandler "WrappedControl", _
            ptPropertySet, "Wrapped Control Not Set"
    End If
End Property

' NOTE: The "Get" for TabStop is public.
Friend Property Let TabStop(ByVal bNewTabStop As Boolean)
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        mControl.TabStop = bNewTabStop
        
        ' Inline error handler
        ' NOTE: Unlike the "get", if the control
        '       doesn't have a tab stop, we can't
        '       set it, so keep the error.
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler "TabStop = " & _
                CStr(bNewTabStop), ptPropertyLet, _
                mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing
End Property


'---------------------------------------------------
' Private Helpers for Setting "Enabled/Visible"
'---------------------------------------------------

' NOTE: The caller MUST set its corresponding
'       "WantsEnabled" or "WantsVisible" flag to
'       TRUE BEFORE calling EnableWrappedControl or
'       ShowWrappedControl respectively.  Otherwise,
'       the caller's flag could be False, so these
'       functions won't enable/show the control,
'       thinking that someone wants it to be
'       disabled/hidden.

Private Sub EnableWrappedControl()
On Error GoTo EnableWrappedControlHandler
    If (Not (mControl Is Nothing)) Then
        If (bCustWantsEnabled = True) _
          And (bMacroWantsEnabled = True) _
          And (bTmplWantsEnabled = True) _
          And (bUIWantsEnabled = True) Then
            ' Everyone is OK with making it enabled.
            mControl.Enabled = True
        Else
            ' Someone wants it disabled.
            mControl.Enabled = False  ' just to be sure
        End If  ' All parties want the control enabled
    End If  ' Not (mControl Is Nothing)
Exit Sub

EnableWrappedControlHandler:
    With Err
        .Raise .Number, .Source, .Description, _
            .HelpFile, .HelpContext
    End With  ' Err
End Sub

Private Sub ShowWrappedControl()
On Error GoTo ShowWrappedControlHandler
    If (Not (mControl Is Nothing)) Then
        If (bCustWantsVisible = True) _
          And (bMacroWantsVisible = True) _
          And (bTmplWantsVisible = True) _
          And (bUIWantsVisible = True) _
          Then
            ' Everyone is OK with making it visible.
            mControl.Visible = True
        Else
            ' Someone wants it hidden.
            mControl.Visible = False  ' just to be sure
        End If  ' All parties want the control shown
    End If  ' Not (mControl Is Nothing)
Exit Sub

ShowWrappedControlHandler:
    With Err
        .Raise .Number, .Source, .Description, _
            .HelpFile, .HelpContext
    End With  ' Err
End Sub


'---------------------------------------------------
' Friend Properties for Setting "Enabled/Visible"
'---------------------------------------------------
'
' There are four "parties" (a.k.a. types of code)
' that may be trying to set a control's "Enabled"
' and/or "Visible" properties.  These parties are:
'   - "Customize" box-related code  ["Cust"]
'   - Other template code  ["Tmpl"]
'   - "Display" code specific to the UI  ["UI"]
'   - Macro code (from Automation)  ["Macro"]
' Thus, there's a rule for controlling when a
' control gets enabled/disabled and shown/hidden.
'
' GENERAL RULE FOR SETTING ENABLED/VISIBLE:
'   If ANY PARTY wants to disable/hide the control,
'   the control is disabled/hidden.  In order for a
'   control to be enabled/shown, ALL PARTIES must
'   want to enable/show the control.
'
' HOW THE RULE IS APPLIED:
'   Each party has "WantsEnabled" and "WantsVisible"
'   flags.  Each party indicates its intention by
'   setting its flags.  AFTER the party sets one of
'   its flags, everyone's flag is checked.  The
'   control is then enabled/shown if everyone's flag
'   is True.  Otherwise, it's disabled/hidden.
' NOTE: For some controls (i.e. non-customizable
'       controls), not all parties are "present".
'       In this case, the flags for the "absent"
'       parties are automatically set to TRUE (i.e.
'       bCustWantsEnabled and bCustWantsVisible are
'       TRUE for non-customizable controls).
'

Friend Property Get CustEnabledFlag() As Boolean
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        CustEnabledFlag = bCustWantsEnabled
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler "CustEnabledFlag", _
                ptPropertyGet, mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Property

Friend Property Let CustEnabledFlag(ByVal bFlag As Boolean)
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        bCustWantsEnabled = bFlag  ' set flag first
        EnableWrappedControl
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler "CustEnabledFlag " _
                & "= " & CStr(bFlag), ptPropertyLet, _
                mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Property

Friend Property Get CustVisibleFlag() As Boolean
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        CustVisibleFlag = bCustWantsVisible
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler "CustVisibleFlag", _
                ptPropertyGet, mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Property

Friend Property Let CustVisibleFlag(ByVal bFlag As Boolean)
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        bCustWantsVisible = bFlag  ' set flag first
        ShowWrappedControl
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler "CustVisibleFlag " _
                & "= " & CStr(bFlag), ptPropertyLet, _
                mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Property

Friend Property Get TmplEnabledFlag() As Boolean
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        TmplEnabledFlag = bTmplWantsEnabled
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler "TmplEnabledFlag", _
                ptPropertyGet, mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Property

Friend Property Let TmplEnabledFlag(ByVal bFlag As Boolean)
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        bTmplWantsEnabled = bFlag  ' set flag first
        EnableWrappedControl
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler "TmplEnabledFlag " _
                & "= " & CStr(bFlag), ptPropertyLet, _
                mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Property

Friend Property Get TmplVisibleFlag() As Boolean
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        TmplVisibleFlag = bTmplWantsVisible
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler "TmplVisibleFlag", _
                ptPropertyGet, mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Property

Friend Property Let TmplVisibleFlag(ByVal bFlag As Boolean)
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        bTmplWantsVisible = bFlag  ' set flag first
        ShowWrappedControl
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler "TmplVisibleFlag " _
                & "= " & CStr(bFlag), ptPropertyLet, _
                mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Property

Friend Property Get UIEnabledFlag() As Boolean
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        UIEnabledFlag = bUIWantsEnabled
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler "UIEnabledFlag", _
                ptPropertyGet, mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Property

Friend Property Let UIEnabledFlag(ByVal bFlag As Boolean)
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        bUIWantsEnabled = bFlag  ' set flag first
        EnableWrappedControl
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler "UIEnabledFlag = " _
                & CStr(bFlag), ptPropertyLet, _
                mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Property

Friend Property Get UIVisibleFlag() As Boolean
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        UIVisibleFlag = bUIWantsVisible
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler "UIVisibleFlag", _
                ptPropertyGet, mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Property

Friend Property Let UIVisibleFlag(ByVal bFlag As Boolean)
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        bUIWantsVisible = bFlag  ' set flag first
        ShowWrappedControl
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler "UIVisibleFlag = " _
                & CStr(bFlag), ptPropertyLet, _
                mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Property


'---------------------------------------------------
' Exposed Methods
'---------------------------------------------------

' This function returns the underlying control as an
' object, so that advanced macros can access a wider
' range of methods/properties as late-bound calls.
' By adding this method, we can keep WrappedControl
' as friend property that returns a Control.
' NOTE: Controls can only be passed to external
'       components as type Object (not Control).
Public Function GetControl() As Object
Attribute GetControl.VB_Description = "WARNING: THIS METHOD IS BEST SUITED FOR ADVANCED MACRO PROGRAMMERS.\r\nReturns the underlying control as an object, allowing late-bound access to its methods and properties."
On Error Resume Next
    Set GetControl = mControl
    
    ' Inline error handler
    If Err.Number <> 0 Then
        CtlACCPACErrorHandler "GetControl", _
            ptFunction, "Unspecified Error"
    End If  ' Err.Number <> 0
End Function

' NOTE: This sub is made as a convenience to change
'       the Left AND Top of the ACCPACControl at the
'       same time.  It is DIFFERENT from the "Move"
'       that it wraps in two ways: it doesn't set
'       width and height, and 'TOP' is a REQUIRED
'       argument.  To move just one coordinate, set
'       "Left" or "Top" (property).  To resize the
'       ACCPACControl, set "Height" and/or "Width".
Public Sub Move(Left As Single, Top As Single)
Attribute Move.VB_Description = "Moves the underlying control.  This method does not resize the control."
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        mControl.Move Left, Top
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler "Move", ptSub, _
                mControl.Name, _
                "Arguments: Left = " & CStr(Left) & _
                ", Top = " & CStr(Top)
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Sub

Public Sub SetFocus()
Attribute SetFocus.VB_Description = "Moves the focus to the underlying control."
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        mControl.SetFocus
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler "SetFocus", ptSub, _
                mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Sub


'---------------------------------------------------
' Exposed Properties
'---------------------------------------------------

' (Read-only)
' This property tries to return the ACCPACControl's
' name as a combination of the original control's
' name and index in a control array (i.e. acting as
' if the original control was part of a control
' array).  If the original control isn't part of a
' control array, this property uses error handling
' to set the ACCPACControl's name as just the
' original control's name.
Public Property Get Name() As String
Attribute Name.VB_Description = "Returns the underlying control's variable name (including the index within parentheses if it's part of a control array)."
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        Name = mControl.Name & "(" & mControl.Index _
            & ")"
        
        Select Case Err.Number
            Case 0
                ' No error: control is part of a
                ' control array
            Case 343  ' not part of control array
                ' We can fix "not part of control
                ' array", so clear the error, then
                ' try to return just the name.
                Err.Clear
                Name = mControl.Name  ' return only name
                
                ' Handle any NEW errors from "Name =
                ' mControl.Name"
                If Err.Number <> 0 Then
                    CtlACCPACErrorHandler "Name", _
                        ptPropertyGet, _
                        "Wrapped Control Has No Name"
                End If
            Case Else
                ' Handle any UNKNOWN errors from the
                ' FIRST attempt at setting "Name"
                CtlACCPACErrorHandler "Name", _
                    ptPropertyGet, _
                    "Wrapped Control Has No Name"
        End Select
    End If
End Property

' This returns the caption if the wrapped control
' actually has one.  Otherwise, an error is reported
' in a debug message (and the caption is "" by
' default).  Macro programmers need to do an
' explicit "If Err.Number <> 0" (even if they DON'T
' have "On Error Resume Next") if they want to catch
' the error.  (Things like the text on a text box or
' combo box are NOT captions.)
' NOTE: A field edit control may or may not have a
'       caption (even if it has labels).
' NOTE: The SSTab's caption is the caption on its
'       ACTIVE tab.  (Change the active tab to get
'       other tabs' captions.)
Public Property Get Caption() As String
Attribute Caption.VB_Description = "Returns/sets the ""label-part"" text displayed in the underlying control."
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        Caption = mControl.Caption
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler "Caption", _
                ptPropertyGet, mControl.Name
        ElseIf (Caption = "") Or (Caption = vbNullString) Then
            ' Since the "CaptionType" may be set
            ' incorrectly in the field edit control,
            ' try to GET the caption from its labels
            ' or text.
            Caption = CaptionFallback
            Err.Clear  ' just to be sure
        End If  ' Err.Number <> 0 / ElseIf Caption = ("" or vbNullString)
    End If  ' Not (mControl Is Nothing)
End Property

' This function looks in the various labels and text
' parts of an underlying field edit control to see
' if any of them are non-empty.  Otherwise, it just
' returns "" (as it was called when Caption = "").
' THIS FUNCTION WAS ADDED BECAUSE MAY FIELD EDIT
' CONTROLS SET THE "CaptionType" INCORRECTLY.
Private Function CaptionFallback() As String
On Error GoTo CaptionFallbackHandler
    Dim typCtl As tagFieldEditControlType
    
    If (Not (TypeOf mControl Is AccpacFieldEditControl)) Then
        ' It's not a field edit control, so the
        ' caption's empty anyways.
        CaptionFallback = ""
        Exit Function
    End If
    
    ' IF WE GOT TO HERE, IT'S A FIELD EDIT CONTROL.
    
    typCtl = mControl.ControlType
    
    If (typCtl = FIELD_EDIT_CONTROL_CHECK) _
      Or (typCtl = FIELD_EDIT_CONTROL_OPPOSITE_CHECK) _
      Or (typCtl = FIELD_EDIT_CONTROL_RADIO) Then
        ' First, look in the text.
        CaptionFallback = mControl.Text
        If (CaptionFallback <> "") And (CaptionFallback <> vbNullString) Then
            ' Found it in the text.
            Exit Function
        End If  ' (CaptionFallback <> "") And (CaptionFallback <> vbNullString)
        
        ' Next, look in the left label.
        CaptionFallback = mControl.LeftLabel
        If (CaptionFallback <> "") And (CaptionFallback <> vbNullString) Then
            ' Found it in the left label.
            Exit Function
        End If
        
        ' Next, look in the right label.
        CaptionFallback = mControl.RightLabel
        If (CaptionFallback <> "") And (CaptionFallback <> vbNullString) Then
            ' Found it in the right label.
            Exit Function
        End If
        
        If (Not (mControl.AccpacField Is Nothing)) Then
            ' Finally, look in the field description.
            CaptionFallback = mControl.AccpacField.Description
            If (CaptionFallback <> "") And (CaptionFallback <> vbNullString) Then
                ' Found it in the field description.
                Exit Function
            End If  ' (CaptionFallback <> "") And (CaptionFallback <> vbNullString)
        End If  ' Not (mControl.AccpacField Is Nothing)
    Else
        ' First, look in the left label.
        CaptionFallback = mControl.LeftLabel
        If (CaptionFallback <> "") And (CaptionFallback <> vbNullString) Then
            ' Found it in the left label.
            Exit Function
        End If
        
        ' Next, look in the right label.
        CaptionFallback = mControl.RightLabel
        If (CaptionFallback <> "") And (CaptionFallback <> vbNullString) Then
            ' Found it in the right label.
            Exit Function
        End If
        
        If (Not (mControl.AccpacField Is Nothing)) Then
            ' Next, look in the field description.
            CaptionFallback = mControl.AccpacField.Description
            If (CaptionFallback <> "") And (CaptionFallback <> vbNullString) Then
                ' Found it in the field description.
                Exit Function
            End If  ' (CaptionFallback <> "") And (CaptionFallback <> vbNullString)
        End If  ' Not (mControl.AccpacField Is Nothing)
        
        ' Finally, look in the text (it's probably
        ' not there).
        CaptionFallback = mControl.Text
        If (CaptionFallback <> "") And (CaptionFallback <> vbNullString) Then
            ' Found it in the text.
            Exit Function
        End If  ' (CaptionFallback <> "") And (CaptionFallback <> vbNullString)
    End If  ' typCtl = checkbox or radio-type control
    
    ' IF WE GOT TO HERE, THERE WAS NO NON-EMPTY
    ' CAPTION.
    
    CaptionFallback = ""  ' it really was empty
Exit Function

CaptionFallbackHandler:
    ' Just clear errors and return an empty caption.
    CaptionFallback = ""
    Err.Clear
End Function

' NOTE: The fallback scheme DOESN'T apply to setting
'       the caption.
Public Property Let Caption(ByVal strNewCaption As String)
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        mControl.Caption = strNewCaption
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler "Caption", _
                ptPropertyLet, mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Property

' (Read-only)
Public Property Get Container() As Object
Attribute Container.VB_Description = "Returns the container of the underlying control."
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        Set Container = mControl.Container
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler "Container", _
                ptPropertyGet, mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Property

' (Read-only)
' Set this property safely using zzzEnabledFlag
' (where "zzz" is "UI" for UI programmers and
' "Macro" for automation controllers).
' NOTE: This shows whether or not the control is
'       ACTUALLY enabled.
Public Property Get Enabled() As Boolean
Attribute Enabled.VB_Description = "Returns a value that shows whether the underlying control can respond to user-generated events.\r\n(Set this property using MacroEnabledFlag.)"
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        Enabled = mControl.Enabled
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler "Enabled", _
                ptPropertyGet, mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Property

Public Property Get Height() As Single
Attribute Height.VB_Description = "Returns/sets the height of the underlying control."
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        Height = mControl.Height
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler "Height", _
                ptPropertyGet, mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Property

Public Property Let Height(ByVal sNewHeight As Single)
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        mControl.Height = sNewHeight
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler "Height = " & _
                CStr(sNewHeight), ptPropertyLet, _
                mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Property

Public Property Get Left() As Single
Attribute Left.VB_Description = "Returns/sets the distance between the internal left edge of the underlying control and the left edge of its container."
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        Left = mControl.Left
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler "Left", _
                ptPropertyGet, mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Property

Public Property Let Left(ByVal sNewLeft As Single)
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        mControl.Left = sNewLeft
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler "Left = " & _
                CStr(sNewLeft), ptPropertyLet, _
                mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Property

Public Property Get MacroEnabledFlag() As Boolean
Attribute MacroEnabledFlag.VB_Description = "Returns/sets a flag requesting that the underlying control be enabled or disabled (i.e. respond to user-generated events or not)."
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        MacroEnabledFlag = bMacroWantsEnabled
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler _
                "MacroEnabledFlag", ptPropertyGet, _
                mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Property

Public Property Let MacroEnabledFlag(ByVal bFlag As Boolean)
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        bMacroWantsEnabled = bFlag  ' set flag first
        EnableWrappedControl
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler _
                "MacroEnabledFlag = " & CStr(bFlag), _
                ptPropertyLet, mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Property

Public Property Get MacroVisibleFlag() As Boolean
Attribute MacroVisibleFlag.VB_Description = "Returns/sets a flag requesting that the underlying control be visible or hidden."
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        MacroVisibleFlag = bMacroWantsVisible
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler _
                "MacroVisibleFlag", ptPropertyGet, _
                mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Property

Public Property Let MacroVisibleFlag(ByVal bFlag As Boolean)
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        bMacroWantsVisible = bFlag  ' set flag first
        ShowWrappedControl
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler _
                "MacroVisibleFlag = " & CStr(bFlag), _
                ptPropertyLet, mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Property

Public Property Get TabIndex() As Integer
Attribute TabIndex.VB_Description = "Returns/sets the tab order of the underlying control within its parent ACCPAC UI Control."
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        TabIndex = mControl.TabIndex
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler "TabIndex", _
                ptPropertyGet, mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Property

Public Property Let TabIndex(ByVal iNewTabIndex As Integer)
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        mControl.TabIndex = iNewTabIndex
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler "TabIndex = " & _
                CStr(iNewTabIndex), ptPropertyLet, _
                mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Property

' (Read-only): PUBLIC
' NOTE: The "Let" for TabStop is a Friend property.
Public Property Get TabStop() As Boolean
Attribute TabStop.VB_Description = "Returns a value indicating whether a user can use the TAB key to give the focus to the underlying control."
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        TabStop = mControl.TabStop
        
        ' Inline error handler
        Select Case Err.Number
            Case 0  ' no error
                ' Do Nothing: we're OK
            Case 438  ' control has no TabStop property
                ' "No TabStop" is equivalent to
                ' "TabStop = False", so clear the
                ' error and return "False".
                Err.Clear
                TabStop = False
                
                ' Handle any NEW errors from
                ' "TabStop = False"
                If Err.Number <> 0 Then
                    CtlACCPACErrorHandler "TabStop", _
                        ptPropertyGet, mControl.Name
                End If
            Case Else
                ' Handle any UNKNOWN errors from the
                ' FIRST attempt at setting "TabStop"
                CtlACCPACErrorHandler "TabStop", _
                    ptPropertyGet, mControl.Name
        End Select
    End If
End Property

Public Property Get Top() As Single
Attribute Top.VB_Description = "Returns/sets the distance between the internal top edge of the underlying control and the top edge of its container."
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        Top = mControl.Top
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler "Top", _
                ptPropertyGet, mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Property

Public Property Let Top(ByVal sNewTop As Single)
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        mControl.Top = sNewTop
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler "Top = " & _
                CStr(sNewTop), ptPropertyLet, _
                mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Property

Public Property Get Value() As Variant
Attribute Value.VB_Description = "Returns/sets the value of the underlying control."
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        If IsObject(mControl.Value) Then
            Set Value = mControl.Value
        ElseIf (TypeOf mControl Is VB.ComboBox) _
          Or (TypeOf mControl Is VB.ListBox) _
          Or (TypeOf mControl Is VB.TextBox) _
          Then
            Value = mControl.Text
        Else
            Value = mControl.Value
        End If
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler "Value", _
                ptPropertyGet, mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Property

Public Property Let Value(ByVal vNewValue As Variant)
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        If (TypeOf mControl Is VB.ComboBox) _
          Or (TypeOf mControl Is VB.ListBox) _
          Or (TypeOf mControl Is VB.TextBox) _
          Then
            mControl.Text = vNewValue
        Else
            mControl.Value = vNewValue
        End If
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler "Value = " & _
                CStr(vNewValue), ptPropertyLet, _
                mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Property

Public Property Set Value(ByVal vNewValue As Variant)
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        Set mControl.Value = vNewValue
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler "Value = (Variant" _
                & " Object)", ptPropertySet, _
                mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Property

' (Read-Only)
' Set this property safely using zzzVisibleFlag
' (where "zzz" is "UI" for UI programmers and
' "Macro" for automation controllers).
' NOTE: This shows whether or not the control is
'       ACTUALLY visible.
Public Property Get Visible() As Boolean
Attribute Visible.VB_Description = "Returns a value that shows whether the underlying control is visible or hidden.\r\n(Set this property using MacroVisibleFlag.)"
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        Visible = mControl.Visible
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler "Visible", _
                ptPropertyGet, mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Property

Public Property Get Width() As Single
Attribute Width.VB_Description = "Returns/sets the width of the underlying control."
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        Width = mControl.Width
    
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler "Width", _
                ptPropertyGet, mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Property

Public Property Let Width(ByVal sNewWidth As Single)
On Error Resume Next
    If (Not (mControl Is Nothing)) Then
        mControl.Width = sNewWidth
        
        ' Inline error handler
        If Err.Number <> 0 Then
            CtlACCPACErrorHandler "Width = " & _
                CStr(sNewWidth), ptPropertyLet, _
                mControl.Name
        End If  ' Err.Number <> 0
    End If  ' Not (mControl Is Nothing)
End Property
