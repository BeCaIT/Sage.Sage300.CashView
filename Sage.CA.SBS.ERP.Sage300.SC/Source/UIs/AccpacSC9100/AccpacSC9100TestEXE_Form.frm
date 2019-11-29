VERSION 5.00
Object = "*\AAccpacSC9100.vbp"
Begin VB.Form AccpacSC9100TestEXE_Form 
   Caption         =   "VB Test Form"
   ClientHeight    =   8190
   ClientLeft      =   2250
   ClientTop       =   1635
   ClientWidth     =   8640
   Icon            =   "AccpacSC9100TestEXE_Form.frx":0000
   LinkTopic       =   "Form1"
   ScaleHeight     =   8190
   ScaleWidth      =   8640
   Begin AccpacSC9100.AccpacSC9100UICtrl ACCPACUIControl1 
      Height          =   7290
      Left            =   150
      TabIndex        =   3
      Top             =   150
      Width           =   8340
      _ExtentX        =   14711
      _ExtentY        =   12859
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
   End
   Begin VB.CommandButton cmdTestColors 
      Caption         =   "Test C&olors"
      Height          =   315
      Left            =   1875
      TabIndex        =   1
      Top             =   7725
      Width           =   1275
   End
   Begin VB.CommandButton cmdExit 
      Caption         =   "E&xit"
      Height          =   315
      Left            =   7425
      TabIndex        =   2
      Top             =   7725
      Width           =   1065
   End
   Begin VB.CommandButton cmdTestCollections 
      Caption         =   "Test Co&llections"
      Height          =   315
      Left            =   150
      TabIndex        =   0
      Top             =   7725
      Width           =   1590
   End
   Begin VB.Line Line1 
      X1              =   150
      X2              =   8475
      Y1              =   7575
      Y2              =   7575
   End
   Begin VB.Menu mnuTestPopup 
      Caption         =   "Test &Popup"
      NegotiatePosition=   1  'Left
   End
End
Attribute VB_Name = "AccpacSC9100TestEXE_Form"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
'
' [ Standard Executable Program for Testing an
'   ACCPAC UI Control. ]
' Form Class Module: AccpacSC9100TestEXE_Form
' Template 5.1A Revision: cycle 11
'
' Description: This module contains event handler
'              (and helper function) code for the
'              form that serves as the VB test
'              container for an ACCPAC UI Control.
'              This includes code for testing the
'              exposed collections.
'
' NOTE: The ACCPAC UI Control instance on this form
'       should be named ACCPACUIControl1.  If need
'       be, go to the form designer view and change
'       the ACCPAC UI Control instance's name to
'       ACCPACUIControl1 in the "Properties" Window.
'
' MODIFICATIONS NEEDED:
'   1. In the Form's visual designer, select the
'      form itself.  Select its "Icon" property and
'      press this property's "..." button.  The
'      resulting "Load Icon" dialog box lets you
'      navigate to and choose the ICON (.ico file)
'      for the test executable.  This icon should be
'      the SAME as the "About" box's icon.
'
'   2. Replace the YYYY in the "Copyright" comment
'      below with the latest year in which your UI
'      was developed.
'
'   3. Add more testing code if desired.
'
' Copyright 1999-YYYY ACCPAC International, Inc.
'   All rights reserved.
'

' NO ERROR HANDLING IN THIS TEST CONTAINER (UNLESS
' YOU USE IT TO TEST YOUR CONTROL'S ERROR HANDLING).

Option Compare Text
Option Explicit


'---------------------------------------------------
' Constants
'---------------------------------------------------

' Message strings
Private Const TestDlgCapStart As String = _
    "VB Test Container: "


'---------------------------------------------------
' Variables
'---------------------------------------------------

' Private members for testing colors
Private origUIBackColor As OLE_COLOR
Private origFormBackColor As OLE_COLOR
Private bToggle As Boolean ' T = form color, F = UI color

' Private members for resizing
Private msBCmdOffset As Single
Private msBLineOffset As Single
Private msBUIOffset As Single
Private msROffset As Single


'---------------------------------------------------
' Test Handlers for ACCPAC UI Control-Raised Events
'---------------------------------------------------

Private Sub ACCPACUIControl1_AfterCtlClick( _
                    ByVal strFormName As String, _
                    ByVal strCtlName As String)
    Debug.Print "Received AfterCtlClick event:" & _
        vbCrLf & "  strFormName = " & strFormName & _
        vbCrLf & "  strCtlName = " & strCtlName
End Sub

Private Sub ACCPACUIControl1_BeforeCtlClick( _
                    ByVal strFormName As String, _
                    ByVal strCtlName As String, _
                    pStatus As AccpacCOMAPI.tagEventStatus)
    Debug.Print "Received BeforeCtlClick event:" & _
        vbCrLf & "  strFormName = " & strFormName & _
        vbCrLf & "  strCtlName = " & strCtlName & _
        vbCrLf & "  pStatus = " & pStatus
End Sub

Private Sub ACCPACUIControl1_BeforeUIAppClosed()
    Debug.Print "Received BeforeUIAppClosed event"
End Sub

Private Sub ACCPACUIControl1_OnLaunchObject( _
                    ByVal strTargetClass As String, _
                    ByVal strCodebase As String, _
                    ByVal strObjectHandle As String)
    MsgBox "UI tried to launch object:" & vbCrLf & _
        "strTargetClass = " & strTargetClass & vbCrLf & _
        "strCodebase = " & strCodebase & vbCrLf & _
        "strObjectHandle = " & strObjectHandle
End Sub

Private Sub ACCPACUIControl1_OnLaunchURL( _
                            ByVal strURL As String)
    MsgBox "UI tried to launch URL:" & vbCrLf & _
        "strURL = " & strURL
End Sub

Private Sub ACCPACUIControl1_OnUIAppClosed()
    Debug.Print "Received OnUIAppClosed event"
    
    ' Close the test form too.
    Unload Me
End Sub

Private Sub ACCPACUIControl1_OnUIAppOpened()
    Debug.Print "Received OnUIAppOpened event"
    
    With ACCPACUIControl1
        ' Update the test form's caption and icon
        ' (as the UI's language may have changed).
        Me.Caption = TestDlgCapStart & .UIName
        Set Me.Icon = .UIIcon
        
        ' We NEED to set focus here.  Otherwise,
        ' there's NO focus, so tabbing doesn't work
        ' until you use the mouse to set focus
        ' somewhere.
        If (.Enabled = True) And (.Visible = True) Then
            .SetFocus
        End If
    End With  ' ACCPACUIControl1
End Sub

Private Sub ACCPACUIControl1_OnUIForceSize( _
                    ByVal sNewWidth As Single, _
                    ByVal sNewHeight As Single, _
                    ByVal sTwipsPerPixelX As Single, _
                    ByVal sTwipsPerPixelY As Single)
    Debug.Print "Received OnUIForceSize Event (w = " _
           & sNewWidth & ", h = " & sNewHeight & "," _
           & vbCrLf & "  TwipsPerPixelX = " & _
           sTwipsPerPixelX & ", TwipsPerPixelY = " & _
           sTwipsPerPixelY & ")"

    ' Resize the form to accomodate the UI in the
    ' size that it desires.
    With Me
        .Move .Left, .Top, _
            ACCPACUIControl1.Left + sNewWidth + msROffset, _
            ACCPACUIControl1.Top + sNewHeight + msBUIOffset
    End With  ' Me
End Sub


'---------------------------------------------------
' Other Test Form Event Handlers
'---------------------------------------------------

Private Sub cmdExit_Click()
    Debug.Print "Test Form: cmdExit_Click"
    
    Unload Me
End Sub

Private Sub cmdTestCollections_Click()
    Debug.Print "Test Form: cmdTestCollections_Click"
    
    With ACCPACUIControl1
        Dim i As Long
        Dim dbLink As AccpacDBLink
        Dim dsc As ACCPACDSControl
        
        If .UIAppIsOpen = True Then
            MsgBox "UI's application part is OPEN"
            
            Dim c As ACCPACControl
            
            ' Test the collection of application-
            ' part (non data source) controls
            i = 0
            For Each c In .UIAppControls
                i = i + 1
                MsgBox "Application part: Control #" _
                    & CStr(i) & " = " & c.Name
            Next c
            
            MsgBox "UIAppControls.Count = " _
                & CStr(.UIAppControls.Count)
        Else
            MsgBox "UI's application part is CLOSED"
        End If
        
        ' Test the collection of DB links
        i = 0
        For Each dbLink In .UIDBLinks
            i = i + 1
            MsgBox "Found DB link #" & CStr(i)
        Next dbLink
        
        MsgBox "Total DB links found = " & CStr(i) & _
            ", UIDBLinks.Count = " & _
            CStr(.UIDBLinks.Count)
        
        ' Test the collection of data source
        ' controls
        i = 0
        For Each dsc In .UIDSControls
            i = i + 1
            MsgBox "Found data source #" & CStr(i) & _
                ":" & vbCrLf & "ViewID = " & _
                dsc.ViewID & ", Active = " & _
                CStr(dsc.Active)
        Next dsc
        
        MsgBox "Total data sources found = " & _
            CStr(i) & ", UIDSControls.Count = " & _
            CStr(.UIDSControls.Count)
        
        If (.Enabled = True) And (.Visible = True) Then
            .SetFocus
        End If
    End With  ' ACCPACUIControl1
End Sub

Private Sub cmdTestColors_Click()
    Debug.Print "Test Form: cmdTestColors_Click"
    
    ' NOTE: DO NOT play the hide/show thing with
    '       the UI Control as this will cause
    '       CloseUIApp/OpenUIApp.
    With ACCPACUIControl1
        If bToggle = True Then
            Me.BackColor = origFormBackColor
            
            ' Must set the control's Backstyle
            ' BEFORE setting other things that
            ' depend on the BackStyle's value
            .BackStyle = Opaque
            .BackColor = origFormBackColor
            .BorderStyle = None
        Else
            Me.BackColor = origUIBackColor
            
            ' Must set the control's Backstyle
            ' BEFORE setting other things that
            ' depend on the BackStyle's value
            .BackStyle = Transparent
            .BackColor = origUIBackColor
            .BorderStyle = FixedSingle
        End If
        
        bToggle = Not (bToggle)
    End With  ' ACCPACUIControl1
End Sub

' NOTE: These initial layout offsets CAN'T be
'       calculated earlier (i.e. in Form_Load) or
'       else the values are wrong (and the test
'       form's buttons are partially cut off).
' NOTE: If a UI has a message box BEFORE the
'       "DoEvents" call in "RefreshMenus" (called
'       from "UC_Show"), the test form's "Activate"
'       event WON'T be raised!
Private Sub Form_Activate()
    Debug.Print "Form_Activate"
    
    Dim sFrmHeight As Single
    
    With Me
        ' Set the scale mode to twips.
        .ScaleMode = vbTwips
        
        ' Figure out the form's height.
        sFrmHeight = .Height
    End With  ' Me
        
    ' Set the bottom and right offsets for the
    ' controls on the form.
    With cmdExit
        msBCmdOffset = sFrmHeight - (.Top + .Height)
    End With  ' cmdExit
    
    msBLineOffset = sFrmHeight - Line1.Y1
    
    With ACCPACUIControl1
        msBUIOffset = sFrmHeight - (.Top + .Height)
        msROffset = Me.Width - (.Left + .Width)
        
        ' Also place the line properly.
        Line1.X1 = .Left
        Line1.X2 = .Left + .Width
    End With  ' ACCPACUIControl1
End Sub

' This is the FIRST event: CONSTITUENT CONTROLS
' DON'T EXIST YET.
Private Sub Form_Initialize()
    Debug.Print "Form_Initialize"
End Sub

' This happens after Initialize.
Private Sub Form_Load()
    Debug.Print "Form_Load"
    
    With ACCPACUIControl1
        If .Resizable = True Then
            ' Make this form resizable too.
            Me.BorderStyle = vbSizable
        Else
            ' Make this form a fixed dialog (non-
            ' resizable too).
            Me.BorderStyle = vbFixedDialog
        End If
        
        ' NOTE: The UI is STILL INVISIBLE here, so
        '       we HAVE NO localized resources yet!
        '       We can get the name (it's a default
        '       constant), but we NOT the icon!!!
        Me.Caption = TestDlgCapStart & .UIName
    End With  ' ACCPACUIControl1
    
    ' Initialize the members for use by the "Test
    ' Colors" button's handler.
    origFormBackColor = Me.BackColor
    origUIBackColor = ACCPACUIControl1.BackColor
End Sub

Private Sub Form_QueryUnload(Cancel As Integer, UnloadMode As Integer)
    Debug.Print "Form_QueryUnload"
    
    With ACCPACUIControl1
        ' See if we should close the UI's
        ' application part (as well as this form) or
        ' cancel this action.
        If .QueryCloseUIApp = True Then
            .CloseUIApp
            Debug.Print "Exiting..."
        Else
            Cancel = True
            Debug.Print "Cancelled exit"
        End If
    End With  ' ACCPACUIControl1
End Sub

' This happens after Initialize or Load, but before
' Activate.
' NOTE: Resize won't happen if we find out that the
'       UI "isn't resizable" during Load, as finding
'       that out means the form is set to become a
'       fixed dialog (rather than a resizable one).
Private Sub Form_Resize()
    Debug.Print "Form_Resize"
    
    Dim sNewFHeight As Single
    Dim sNewFWidth As Single
    
    ' Don't try to resize the constituent controls
    ' until AFTER the control offset members are set
    ' in "Activate".  Just GET OUT of this sub.
    If (msBCmdOffset <= 0) Or (msBLineOffset <= 0) _
      Or (msBUIOffset <= 0) Or (msROffset <= 0) Then
        Exit Sub
    End If
    
    ' Save the form's new height and width in local
    ' variables.
    With Me
        sNewFHeight = .Height
        sNewFWidth = .Width
    End With  ' Me
    
    ' Check the form's height to see if the form is
    ' minimized.  If so, GET OUT of this sub.
    If sNewFHeight <= 360 Then
        Exit Sub
    End If
    
    ' Stretch the UI Control (bottom/right).
    With ACCPACUIControl1
        .Move .Left, .Top, _
            sNewFWidth - (.Left + msROffset), _
            sNewFHeight - (.Top + msBUIOffset)
    End With  ' ACCPACUIControl1
    
    ' Stretch the line horizontally and move it
    ' vertically.
    With Line1
        .X2 = sNewFWidth - (msROffset + .X1)
        .Y1 = sNewFHeight - msBLineOffset
        .Y2 = sNewFHeight - msBLineOffset
    End With  ' Line1
    
    ' Move the "Test Collections" button vertically.
    With cmdTestCollections
        .Top = sNewFHeight - (.Height + msBCmdOffset)
    End With  ' cmdTestCollections
    
    ' Move the "Test Colors" button vertically.
    With cmdTestColors
        .Top = sNewFHeight - (.Height + msBCmdOffset)
    End With  ' cmdTestColors
    
    ' Move the "Exit" button horizontally and
    ' vertically (to stay at bottom right).
    With cmdExit
        .Move sNewFWidth - (.Width + msROffset), _
            sNewFHeight - (.Height + msBCmdOffset)
    End With  ' cmdExit
End Sub

' This happens AFTER Unload.
Private Sub Form_Terminate()
    Debug.Print "Form_Terminate"
End Sub

Private Sub Form_Unload(Cancel As Integer)
    Debug.Print "Form_Unload"
End Sub

Private Sub mnuTestPopup_Click()
    Debug.Print "Test Form: mnuTestPopup_Click"
    
    ' Show the UI Control's popup menu at the top
    ' left corner of the UI Control's area.
    ACCPACUIControl1.ShowMenus
End Sub
