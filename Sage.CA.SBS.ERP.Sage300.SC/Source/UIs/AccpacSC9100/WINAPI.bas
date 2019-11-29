Attribute VB_Name = "WINAPI"
Option Explicit

Private Declare Function GetTopWindow Lib "user32" (ByVal hwnd As Long) As Long
Private Declare Function GetNextWindow Lib "user32" Alias "GetWindow" (ByVal hwnd As Long, ByVal wFlag As Long) As Long
Private Declare Function GetClassName Lib "user32" Alias "GetClassNameA" (ByVal hwnd As Long, ByVal lpClassName As String, ByVal nMaxCount As Long) As Long

Private Declare Function SetFocus Lib "user32" (ByVal hwnd As Long) As Long
Private Declare Function SendMessage Lib "user32" Alias "SendMessageA" (ByVal hwnd As Long, ByVal wMsg As Long, ByVal wParam As Long, lParam As Any) As Long

Private Const EM_GETPASSWORDCHAR = &HD2
Private Const EM_SETPASSWORDCHAR = &HCC

Private Sub SetPasswordFieldInternal(ByVal hwnd As Long)
    If hwnd = 0 Then Exit Sub
        
    Dim className As String * 256
    GetClassName hwnd, className, 256
    
    If InStr(1, className, "AccpacEDIT") <> 1 Then
        SetPasswordFieldInternal GetNextWindow(hwnd, 2)
    Else
        If SendMessage(hwnd, EM_GETPASSWORDCHAR, 0, 0) <> 42 Then
            SendMessage hwnd, EM_SETPASSWORDCHAR, 42, 0
            SetFocus hwnd
        End If
    End If
End Sub

Public Sub SetPasswordField(ByVal fieldEditControl As AccpacFieldEditControl)
    SetPasswordFieldInternal GetTopWindow(fieldEditControl.hwnd)
End Sub
