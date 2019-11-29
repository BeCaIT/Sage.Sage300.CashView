VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsTabManager"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Option Explicit

'=============================================================================
' This class was created to work around a bug in UserControls.  The bug is
' documented in Microsoft KB article
'
' Q192208: BUG: UserControl SHIFT+TAB Does Not Follow Tab Sequence
'
' To use this class, you need to have the following code in your user control
'
' Private m_TabManager As clsTabManager
'
' Private Sub UserControl_EnterFocus()
'    m_TabManager.ProcessEnterFocus
' End Sub
'
' Private Sub UserControl_ExitFocus()
'    m_TabManager.ProcessExitFocus
' End Sub
'
' Private Sub UserControl_Hide()
'    Set m_TabManager = Nothing
' End Sub
'
' Private Sub UserControl_Show()
'    If m_TabManager Is Nothing Then
'       Set m_TabManager = New clsTabManager
'       m_TabManager.ClassConstruct UserControl.Controls
'    End If
' End Sub
'=============================================================================

Private Declare Function SetFocusAPI Lib "user32" Alias "SetFocus" _
    (ByVal hWnd As Long) As Long
Private Declare Function GetKeyState Lib "user32" (ByVal nVirtKey As Long) _
    As Integer
Private Declare Function GetForegroundWindow Lib "user32" () As Long

' All the controls that can get focus are stored in this array in tab order.
Private m_WindowArray() As Control

' Number of controls
Private m_NumberOfWindows As Integer

' Store the last foreground window to work around the bug documented in
' Microsoft KB article Q253782.
Private m_hWndLastForeGround As Long

' Determine if ClassConstruct was called.
Dim m_ClassIsConstructed As Boolean

'==============================================================================
' Description: Construct the array of tabbable controls.
' Parameters : CtlCollection - controls collection from the user control.
' Return Val : True if the class is ready to be used
' Notes      : This function needs to be called before you use the class and
'               whenever the Tab order of the controls is changed.
'==============================================================================
Public Function ClassConstruct(ByRef CtlCollection As Object) As Boolean
   Reset
   If Not (CtlCollection Is Nothing) Then
      SetupWindowArray CtlCollection
    
      m_ClassIsConstructed = True
      ClassConstruct = True
      m_hWndLastForeGround = GetForegroundWindow
   Else
      m_ClassIsConstructed = False
      ClassConstruct = False
   End If
End Function

'=============================================================================
' Description: Set focus to the last control in the tab order and should be
'               called from the EnterFocus event of the UserControl.
' Parameters : None.
' Return Val : True if the focus was changed, false if it wasn't.
'=============================================================================
Public Function ProcessEnterFocus() As Boolean
   Dim LastCtl As Control
   ProcessEnterFocus = False

   If IsUserShiftTabbing() Then
      Set LastCtl = GetLastFocusableTabStop()
      If (Not (LastCtl Is Nothing)) And _
            m_hWndLastForeGround = GetForegroundWindow Then
         SetFocusAPI LastCtl.hWnd
         ProcessEnterFocus = True
      Else
         m_hWndLastForeGround = GetForegroundWindow
      End If
   End If
End Function

'=============================================================================
' Description: Record the current foreground window and should be
'               called from the ExitFocus event of the UserControl.
' Parameters : None.
' Return Val : True.
'=============================================================================
Public Function ProcessExitFocus() As Boolean
   m_hWndLastForeGround = GetForegroundWindow
   ProcessExitFocus = True
End Function

'=============================================================================
' Description: Return the the last control that can get focus.
' Parameters : None.
' Return Val : The last control that can get focus.  If there is none, Nothing
'               will be returned.
'=============================================================================
Public Function GetLastFocusableTabStop() As Control
   Dim i As Integer
  
   Set GetLastFocusableTabStop = Nothing
  
   For i = m_NumberOfWindows - 1 To 0 Step -1
      If CanWindowGetFocus(m_WindowArray(i)) Then
         Set GetLastFocusableTabStop = m_WindowArray(i)
         Exit For
      End If
   Next i
End Function

'=============================================================================
' Description: Determine if the given control can get focus or not.  This will
'               take into account the Tabstop, Visible and enabled property
'               and only return True if all are set to True.
' Parameters : ctl - The control to check if allowed to get focus.
' Return Val : True if the given window can get focus, False if it cannot
'=============================================================================
Private Function CanWindowGetFocus(ctl As Control)
   On Error GoTo PropertiesNotSupported
  
   If ctl.TabStop And ctl.Visible And ctl.Enabled Then
      CanWindowGetFocus = True
   Else
      CanWindowGetFocus = False
   End If
  
   Exit Function

PropertiesNotSupported:
   ' If no Tabstop, visible or enabled properties, it can't get focus
   CanWindowGetFocus = False
End Function

'=============================================================================
' Description: Walk the controls collection of the given container and fill
'               the array of windows that are tabable controls.  We have to
'               use an On Error trap since we need to check things via the
'               Hwnd and not all controls in the controls collection will
'               have an hWnd.  All items that have an hWnd will be in this
'               array when we are done.
' Parameters : CtlCollection - Controls collection from the user control.
' Return Val : None.
'=============================================================================
Private Sub SetupWindowArray(ByRef CtlCollection As Object)
   Dim ctl As Control
   Dim CtlHwnd As Long
   Dim i As Integer
   Dim NbrValidWindows As Long
   Dim NbrCtls As Long
  
   Dim TmpArray() As Control
   NbrCtls = CtlCollection.Count
   ReDim TmpArray(NbrCtls) As Control
  
   NbrValidWindows = 0
   m_NumberOfWindows = 0
  
   On Error GoTo NoHwnd
  
   For Each ctl In CtlCollection
      ' This may trigger an Error, but the error trap should
      ' catch it and return control to next statement.
      CtlHwnd = ctl.hWnd
    
      If CtlHwnd <> 0 Then
         ' Order the controls by tabindex.  VB Makes sure that Tab
         ' Indexes always start at 0 and go up consecutively by 1
         Set TmpArray(ctl.TabIndex) = ctl
         NbrValidWindows = NbrValidWindows + 1
      Else
         Set TmpArray(ctl.TabIndex) = Nothing
      End If
   Next ctl

   ' Now copy the array to the windows array.
   ReDim m_WindowArray(NbrValidWindows) As Control
  
   For i = 0 To NbrCtls - 1
      If Not (TmpArray(i) Is Nothing) Then
         Set m_WindowArray(m_NumberOfWindows) = TmpArray(i)
         m_NumberOfWindows = m_NumberOfWindows + 1
      End If
   Next i
  
   Exit Sub
  
NoHwnd:
   CtlHwnd = 0
   Resume Next
End Sub

'=============================================================================
' Description: Check to see if user is shift-tabbing
' Parameters : None.
' Return Val : True if the user is shift-tabbing, False if not
'=============================================================================
Private Function IsUserShiftTabbing() As Boolean
   IsUserShiftTabbing = False

   If GetKeyState(vbKeyTab) < 0 And GetKeyState(vbKeyShift) < 0 Then
      IsUserShiftTabbing = True
   End If
End Function

'=============================================================================
' Description: Reset all of the data for this class.
' Parameters : None.
' Return Val : None.
'=============================================================================
Private Sub Reset()
   m_ClassIsConstructed = False
   m_NumberOfWindows = 0
  
   Erase m_WindowArray
End Sub

Private Sub Class_Initialize()
   Reset
End Sub

Private Sub Class_Terminate()
   Reset
End Sub
