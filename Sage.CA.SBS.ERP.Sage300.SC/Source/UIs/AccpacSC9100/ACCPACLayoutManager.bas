Attribute VB_Name = "ACCPACLayoutManager"
Attribute VB_Description = "Very simple visual layout manager for the ACCPAC UI Control"
' ACCPAC UI DEVELOPERS: DO NOT MODIFY THIS FILE!
'
' Module: ACCPACLayoutManager
' Template Release Version: 1.1
'
' Description: This module contains a simple layout
'              manager to aid in the visual layout
'              of controls on the ACCPAC UI Control
'              at run time.
'
' Copyright 1999-2001 ACCPAC International, Inc.
'   All rights reserved.
'

Option Compare Text
Option Explicit


'---------------------------------------------------
' Type/Enumeration Declarations
'---------------------------------------------------

Enum ItemResizeFlags
    MOVE_NONE = 0
    MOVE_LEFT = 1
    MOVE_RIGHT = 2
    MOVE_TOP = 4
    MOVE_BOTTOM = 8
End Enum

Type ITEM_RESIZE_INFO
    controlID As Control
    resizeFlags As ItemResizeFlags
    offsetFromRight As Single
    offsetFromBottom As Single
End Type


'---------------------------------------------------
' Layout-Related Functions/Subs
'---------------------------------------------------

Public Sub InitItemSizeInfo(ByVal cntLeft As Single, _
                            ByVal cntWidth As Single, _
                            ByVal cntTop As Single, _
                            ByVal cntHeight As Single, _
                            ByRef itemsResizeInfo() As ITEM_RESIZE_INFO)
On Error GoTo InitItemSizeInfoHandler
    Dim i As Long
    
    For i = LBound(itemsResizeInfo) To UBound(itemsResizeInfo)
        With itemsResizeInfo(i)
            Dim ctl As Control
            Set ctl = .controlID
            
            ' The array element's controlID should
            ' contain a (non-data source) control.
            If (Not (ctl Is Nothing)) Then
                If (TypeOf ctl Is Line) Then
                    Dim lnX1 As Single
                    Dim lnX2 As Single
                    Dim lnY1 As Single
                    Dim lnY2 As Single
                    Dim lnRight As Single
                    Dim lnBottom As Single
                    
                    With ctl
                        lnX1 = .X1
                        lnX2 = .X2
                        lnY1 = .Y1
                        lnY2 = .Y2
                    End With  ' ctl
                    
                    If lnX2 >= lnX1 Then
                        lnRight = lnX2
                    Else
                        lnRight = lnX1
                    End If
                    
                    If lnY2 >= lnY1 Then
                        lnBottom = lnY2
                    Else
                        lnBottom = lnY1
                    End If
                    
                    .offsetFromRight = (cntLeft _
                        + cntWidth) - lnRight
                    .offsetFromBottom = (cntTop _
                        + cntHeight) - lnBottom
                ElseIf (Not (TypeOf ctl Is AccpacDataSource)) _
                  And (Not (TypeOf ctl Is AccpacFieldGroup)) _
                  And (Not (TypeOf ctl Is CommonDialog)) _
                  And (Not (TypeOf ctl Is Menu)) _
                  And (Not (TypeOf ctl Is Timer)) _
                  Then
                    .offsetFromRight = _
                        (cntLeft + cntWidth) _
                        - (ctl.Left + ctl.Width)
                    .offsetFromBottom = _
                        (cntTop + cntHeight) _
                        - (ctl.Top + ctl.Height)
                Else
                    ' The UI programmer put in the
                    ' wrong control type, so print
                    ' a debug message and force a
                    ' breakpoint to help diagnosis.
                    Debug.Print "itemsResizeInfo(" & _
                        CStr(i) & ") should NOT " & _
                        "contain a data source or a" _
                        & " non-resizable control."
                    Debug.Assert False  ' press F5 or F8 to "Resume Next"
                End If  ' ctl Is Line / ElseIf ctl Is a resizable (non-data source) control
            Else
                ' The UI programmer didn't set
                ' .controlID (i.e. by putting the
                ' wrong value in lResizeInfoItems in
                ' [UICtrl]'s InitItemResizeInfo) or
                ' set it to Nothing, so print a
                ' debug message and force a
                ' breakpoint to help diagnosis.
                Debug.Print "itemsResizeInfo(" & _
                    CStr(i) & ") should NOT contain" _
                    & " Nothing."
                Debug.Assert False  ' press F5 or F8 to "Resume Next"
            End If  ' Not (ctl Is Nothing)
        End With  ' itemsResizeInfo(i)
    Next i
Exit Sub

InitItemSizeInfoHandler:
    ' NOTE: Ignore Err.Source: it's just the name
    '       of the project.
    Debug.Print "InitItemSizeInfo: Failed due to " & _
        "Error #" & CStr(Err.Number) & " -" & vbCrLf _
        & "  " & Err.Description
    
    ' Since the error is probably a UI programming
    ' error, force a breakpoint so the programmer
    ' can diagnose it.  Then, keep on going through
    ' this sub (i.e. try to initialize the next
    ' element: it might be OK).  Since we're in an
    ' error handler, we need to call "Resume Next".
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' clears error
End Sub

Public Sub SizeItems(ByVal cntLeft As Single, _
                     ByVal cntWidth As Single, _
                     ByVal cntTop As Single, _
                     ByVal cntHeight As Single, _
                     ByRef itemsResizeInfo() As ITEM_RESIZE_INFO)
On Error GoTo SizeItemsHandler
    Dim i As Long
    Dim ctlWidth As Single
    Dim ctlHeight As Single
    Dim newLeft As Single
    Dim newRight As Single
    Dim newTop As Single
    Dim newBottom As Single
    Dim oldX1 As Single
    Dim oldX2 As Single
    Dim oldY1 As Single
    Dim oldY2 As Single
    
    For i = LBound(itemsResizeInfo) To UBound(itemsResizeInfo)
        With itemsResizeInfo(i)
            Dim rFlags As ItemResizeFlags
            Dim ctl As Control
            
            rFlags = .resizeFlags
            Set ctl = .controlID
            
            ' The array element's controlID should
            ' contain a non-data source control.
            If (Not (ctl Is Nothing)) Then
                ' NOTE: DON'T hide the control
                '       temporarily, as it causes
                '       too much flicker.
                
                If (Not (TypeOf ctl Is AccpacDataSource)) _
                  And (Not (TypeOf ctl Is AccpacFieldGroup)) _
                  And (Not (TypeOf ctl Is CommonDialog)) _
                  And (Not (TypeOf ctl Is Menu)) _
                  And (Not (TypeOf ctl Is Timer)) _
                  Then
                    If (TypeOf ctl Is Line) Then
                        With ctl
                            oldX1 = .X1
                            oldX2 = .X2
                            oldY1 = .Y1
                            oldY2 = .Y2
                        End With  ' ctl
                        
                        If oldX1 <= oldX2 Then
                            newLeft = oldX1
                            newRight = oldX2
                        Else
                            newLeft = oldX2
                            newRight = oldX1
                        End If
                        
                        If oldY1 <= oldY2 Then
                            newTop = oldY1
                            newBottom = oldY2
                        Else
                            newTop = oldY2
                            newBottom = oldY1
                        End If
                        
                        ctlWidth = newRight - newLeft
                        ctlHeight = newBottom - newTop
                    Else
                        ' Set initial values (some
                        ' will change if we move).
                        With ctl
                            ctlWidth = .Width
                            ctlHeight = .Height
                            newLeft = .Left
                            newRight = .Left + ctlWidth
                            newTop = .Top
                            newBottom = .Top + ctlHeight
                        End With  ' ctl
                    End If
                
                    If 0 <> (rFlags And MOVE_RIGHT) Then
                        newRight = _
                            (cntLeft + cntWidth) _
                            - .offsetFromRight
                    End If  ' MOVE_RIGHT
                
                    If 0 <> (rFlags And MOVE_LEFT) Then
                        newLeft = newRight _
                            - ctlWidth
                    End If  ' MOVE_LEFT
                
                    If 0 <> (rFlags And MOVE_BOTTOM) Then
                        newBottom = _
                            (cntTop + cntHeight) _
                            - .offsetFromBottom
                    End If  ' MOVE_BOTTOM
                
                    If 0 <> (rFlags And MOVE_TOP) Then
                        newTop = newBottom _
                            - ctlHeight
                    End If  ' MOVE_TOP
                
                    If (TypeOf ctl Is Line) Then
                        With ctl
                            If oldX1 <= oldX2 Then
                                .X1 = newLeft
                                .X2 = newRight
                            Else
                                .X2 = newLeft
                                .X1 = newRight
                            End If
                            
                            If oldY1 <= oldY2 Then
                                .Y1 = newTop
                                .Y2 = newBottom
                            Else
                                .Y2 = newTop
                                .Y1 = newBottom
                            End If
                        End With  ' ctl
                    ElseIf (TypeOf ctl Is DriveListBox) _
                     Or (TypeOf ctl Is ComboBox) Then
                        ' These controls don't
                        ' support height changes.
                        ' (Even "simple" comboboxes
                        ' don't: contrary to MSDN.)
                        ctl.Move newLeft, newTop, _
                               (newRight - newLeft)
                    Else
                        ctl.Move newLeft, newTop, _
                               (newRight - newLeft), _
                               (newBottom - newTop)
                    End If  ' TypeOf ctl Is Line / ElseIf Typeof ctl Is (DriveListBox Or ComboBox)
                Else
                    ' The UI programmer put in the
                    ' wrong control type, so print
                    ' a debug message and force a
                    ' breakpoint to help diagnosis.
                    Debug.Print "itemsResizeInfo(" & _
                        CStr(i) & ") should NOT " & _
                        "contain a data source or a" _
                        & " non-resizable control."
                    Debug.Assert False  ' press F5 or F8 to "Resume Next"
                End If  ' ctl Is a resizable (non-data source) control
            Else
                ' The UI programmer didn't set
                ' .controlID (i.e. by putting the
                ' wrong value in lResizeInfoItems in
                ' [UICtrl]'s InitItemResizeInfo) or
                ' set it to Nothing, so print a
                ' debug message and force a
                ' breakpoint to help diagnosis.
                Debug.Print "itemsResizeInfo(" & _
                    CStr(i) & ") should NOT contain" _
                    & " Nothing."
                Debug.Assert False  ' press F5 or F8 to "Resume Next"
            End If  ' Not (ctl Is Nothing)
        End With  ' itemsResizeInfo(i)
    Next i
Exit Sub

SizeItemsHandler:
    ' NOTE: Ignore Err.Source: it's just the name
    '       of the project.
    Debug.Print "SizeItems: Failed due to Error #" _
        & CStr(Err.Number) & " -" & vbCrLf & "  " _
        & Err.Description
    
    ' Since the error is probably a UI programming
    ' error, force a breakpoint so the programmer
    ' can diagnose it.  Then, keep on going through
    ' this sub (i.e. try to size the next element:
    ' it might be OK).  Since we're in an error
    ' handler, we need to call "Resume Next".
    Debug.Assert False  ' press F5 or F8 to continue
    Resume Next  ' clears error
End Sub  ' DO NOT go back inside this sub
