Attribute VB_Name = "ACCPACSystemManager"
Attribute VB_Description = "Module of standard functions and project-wide constants whose values are the same for ALL ACCPAC UI Controls"
' ACCPAC UI DEVELOPERS: DO NOT MODIFY THIS FILE!
'
' Module: ACCPACSystemManager
' Template 6.2A Revision: Release
'
' Description: This module contains an ACCPAC UI
'              Control's standard DLL entry points
'              and API declarations, project-wide
'              constants, utility methods, and
'              standard error handling subroutines.
'
' NOTE: If you would like to add any other DLL entry
'       points, project-wide constants, and error
'       handling subroutines, add them in
'       ACCPACUIGlobals or your own standard module.
'
' Copyright (c) 1999-2012 Sage Software, Inc.  All rights reserved.
'

Option Compare Text
Option Explicit

'---------------------------------------------------
' Common (Project-Wide) Constants
'---------------------------------------------------

' Raw data resource typeID (for GetResData)
Public Const RCDATA As Long = 10

' Types of resources (also used in error strings)
Public Const RESOURCES_COMMON As String = "common"
Public Const RESOURCES_APP As String = "module"
Public Const RESOURCES_UI As String = "UI-specific"

' Partial name of the common resource file (i.e.
' name except for the language ID part)
Public Const ACCPACTmplResApp As String = _
    "ACCPACTmplRes"

' Popup menu accelerator key code
Public Const ACCPACPopupMenuKeyCode As Integer = 93

' Generic message box style constants
Public Const ACCPACStdMBStyle As Long = _
    vbMsgBoxHelpButton + vbOKOnly
Public Const ACCPACWarnMBStyle As Long = _
    vbExclamation + vbMsgBoxHelpButton + vbOKOnly
Public Const ACCPACErrMBStyle As Long = _
    vbCritical + vbMsgBoxHelpButton + vbOKOnly

' NON-TRANSLATED English strings (for display when
' we can't get resources)
Public Const NoLocResourcesTxt As String = _
    "Localized resources aren't available."
Public Const ABNoLocResourcesMsg As String = _
    "[About " & ACCPACUIName & "]" & vbCrLf & vbCrLf _
    & NoLocResourcesTxt
Public Const LocUIFailTxt As String = _
    "Localized resource DLL missing:"


'---------------------------------------------------
' Standard ACCPAC UI Control Constants
'---------------------------------------------------
'
' NOTE: These constants were put HERE instead of
'       inside the "<UI>.ctl" file so that UI
'       programmers won't inadvertantly change them.
'       (This file shouldn't be modified, while the
'       "<UI>.ctl" needs to be modified.)
'

' "UIClosed"-part layout information (based on the
' default ScaleMode = 1 (twips), which will be used
' when creating dynamic controls and when resizing)
Public Const ACCPACUICLOSEDFrameHeight As Single = 1590
Public Const ACCPACUICLOSEDFrameOffset As Single = 150
Public Const ACCPACUICLOSEDLabelHorOffset As Single = 150  ' counting from frame
Public Const ACCPACUICLOSEDLabelVerOffset As Single = 300  ' counting from frame

' "Enhanced" UI name string for use in message boxes
' where the UI needs to be identified, but its name
' isn't in the message box's caption.  DON'T USE
' THIS CONSTANT UNLESS LOCALIZED RESOURCES AREN'T
' AVAILABLE.  (Use mstrAUINameIdentStr instead.)
Public Const AUINameIdentStr As String = _
    AUILStrNameIdent & ACCPACUIName & _
    AUIRStrNameIdent

' Full "UIClosed"-part messages ("Enhanced" UI name,
' a blank line, then the message text part).  DON'T
' USE THIS CONSTANT UNLESS LOCALIZED RESOURCES ARE
' NOT AVAILABLE.  (Use mstrUIInitFailMBMsg instead.)
Public Const UIInitFailMBMsg As String = _
    AUINameIdentStr & vbCrLf & vbCrLf & _
    UIInitFailTxt

' Message to display when we can't get resources for
' the UI.  (This is NEVER translated.)
Public Const AUINoLocResourcesMsg As String = _
    AUINameIdentStr & vbCrLf & vbCrLf & _
    NoLocResourcesTxt & vbCrLf & LocUIFailTxt


'---------------------------------------------------
' Constants and API Declarations for Saving UI Size
'---------------------------------------------------

' ACCPAC Property keys for saving height and width
Public Const UIHEIGHT_KEY As String = "UI_HEIGHT"
Public Const UIWIDTH_KEY As String = "UI_WIDTH"

' Constant for finding the top-level parent window
Public Const GA_ROOT As Long = 2

' API declaration for finding the top-level parent
' window (doesn't work in Win 95 or NT pre 4.0 SP4)
Public Declare Function GetAncestor _
    Lib "user32" _
    (ByVal hWnd As Long, _
     ByVal gaFlags As Long) _
    As Long

' API declarations for checking if the UI is
' minimized or maximized (respectively)
Public Declare Function IsIconic _
    Lib "user32" _
        (ByVal hWnd As Long) _
        As Long

Public Declare Function IsZoomed _
    Lib "user32" _
        (ByVal hWnd As Long) _
        As Long


'---------------------------------------------------
' Registry-Related Constants and API Declarations
'---------------------------------------------------
'
' NOTE: These constants were put HERE instead of
'       inside the "<UI>.ctl" file so that UI
'       programmers won't inadvertantly change them.
'       (This file shouldn't be modified, while the
'       "<UI>.ctl" needs to be modified.)
'

' Path to ACCPAC (Desktop) keys (in HKCU)
Public Const ACCPAC_KEYS_PATH As String = _
    "Software\ACCPAC INTERNATIONAL, INC.\ACCPAC\" & _
    "DESKTOP"

' Desktop Keys we want to access
Public Const ACCPAC_LANG_KEY As String = _
    "Language"

' Debug-related paths/keys/values (in HKLM)
' (For use in the future or for your convenience)
Public Const ACCPAC_DEBUG_PATH = _
    "SOFTWARE\ACCPAC INTERNATIONAL, INC.\ACCPAC\" & _
    "Debug"

' Registry-related constants
Public Const ERROR_SUCCESS As Long = 0&
Public Const HKEY_CURRENT_USER As Long = &H80000001
Public Const HKEY_LOCAL_MACHINE As Long = &H80000002
Public Const REG_SZ As Long = 1  ' Unicode null terminated string
Public Const KEY_QUERY_VALUE As Long = &H1
Public Const STRING_BUFFER_SIZE As Long = 255

' Registry-related Win32 API declarations
Public Declare Function RegOpenKeyEx _
    Lib "advapi32.dll" Alias "RegOpenKeyExA" _
        (ByVal hKey As Long, _
         ByVal lpSubKey As String, _
         ByVal ulOptions As Long, _
         ByVal samDesired As Long, _
         phkResult As Long) _
        As Long

Public Declare Function RegCloseKey _
    Lib "advapi32.dll" _
        (ByVal hKey As Long) _
        As Long

Public Declare Function RegQueryValueEx _
    Lib "advapi32.dll" Alias "RegQueryValueExA" _
        (ByVal hKey As Long, _
         ByVal lpValueName As String, _
         ByVal lpReserved As Long, _
         lpType As Long, _
         lpData As Any, _
         lpcbData As Long) _
        As Long
        ' NOTE: If you declare lpData as String, you
        '       must pass it ByVal.


'---------------------------------------------------
' HTML Help-Related Constants and API Declarations
'---------------------------------------------------

' HTML Help command constants
Public Const HH_DISPLAY_TOPIC As Long = &H0
Public Const HH_DISPLAY_TOC As Long = &H1
Public Const HH_HELP_CONTEXT As Long = &HF

Private Type SYSTEMTIME
        wYear As Integer
        wMonth As Integer
        wDayOfWeek As Integer
        wDay As Integer
        wHour As Integer
        wMinute As Integer
        wSecond As Integer
        wMilliseconds As Integer
End Type

' HTML Help API declaration
' NOTE: MSDN ("Declaring a DLL Procedure") says that
'       we need to use the ANSI ("A") version.
Public Declare Function HtmlHelp _
    Lib "HHCtrl.ocx" Alias "HtmlHelpA" _
        (ByVal hwndCaller As Long, _
         ByVal pszFile As String, _
         ByVal uCommand As Long, _
         dwData As Any) _
        As Long

Private Declare Sub GetSystemTime Lib "kernel32" (lpSystemTime As SYSTEMTIME)

'---------------------------------------------------
' IObjectSafety Constants and API Declarations
'---------------------------------------------------
'
' These are used for marking ACCPAC UI controls safe
' for scripting and initialization.  They come from
' MSDN Article Q182598.
'

Public Const IID_IDispatch = _
    "{00020400-0000-0000-C000-000000000046}"
Public Const IID_IPersistStorage = _
    "{0000010A-0000-0000-C000-000000000046}"
Public Const IID_IPersistStream = _
    "{00000109-0000-0000-C000-000000000046}"
Public Const IID_IPersistPropertyBag = _
    "{37D84F60-42CB-11CE-8135-00AA004BB851}"

Public Const INTERFACESAFE_FOR_UNTRUSTED_CALLER As Long = &H1
Public Const INTERFACESAFE_FOR_UNTRUSTED_DATA As Long = &H2
Public Const E_NOINTERFACE As Long = &H80004002
Public Const E_FAIL As Long = &H80004005
Public Const MAX_GUIDLEN = 40  ' Used as Long and Integer

Public Declare Sub CopyMemory _
    Lib "kernel32" Alias "RtlMoveMemory" _
        (pDest As Any, _
         pSource As Any, _
         ByVal ByteLen As Long)

Public Declare Function StringFromGUID2 _
    Lib "ole32.dll" _
        (rguid As Any, _
         ByVal lpstrClsId As Long, _
         ByVal cbMax As Integer) _
        As Long

Public Type udtGUID
    Data1 As Long
    Data2 As Integer
    Data3 As Integer
    Data4(7) As Byte
End Type

' These were variables to be set in "Sub Main", but
' since they're ALWAYS True, they're now constants
' and there's no need for "Sub Main".
Public Const m_fSafeForScripting As Boolean = True
Public Const m_fSafeForInitializing As Boolean = True


'---------------------------------------------------
' Access Rights Constants
'---------------------------------------------------

' Security resource name constants (for SecCheck)
Public Const RSC_ADMIN As String = "**ADMIN**"


'---------------------------------------------------
' ObjectKey-Related Constants
'---------------------------------------------------

Private Const ParamMarker As String = vbLf
Private Const EqualMarker As String = "\eq"
Private Const EscMarker As String = "\\"


'---------------------------------------------------
' Project-Wide Enumerations
'---------------------------------------------------

' Standard (PLUSAPI) error codes
Public Enum ACCPACErrorCode
    EC_Success = 0      ' OK
    EC_Open = 1         ' open failed
    EC_Close = 2        ' close failed
    EC_Seek = 3         ' seek failed
    EC_Read = 4         ' read failed
    EC_Write = 5        ' write failed
    EC_EOF = 6          ' EOF (end of file) reached
    EC_Disk_Full = 7    ' disk is full
    EC_Bad_Data = 8     ' data is corrupt or invalid
    EC_No_Access = 9    ' file locked or permission denied
    EC_Create = 10      ' create failed
    EC_Delete = 11      ' delete failed
    EC_Lock = 12        ' byte lock failed
    EC_Bad_Handle = 13  ' invalid file handle
    EC_Bad_File = 14    ' file not found
    EC_Bad_Path = 15    ' path not found
    EC_Bad_PW = 31       ' incorrect password
    EC_Buffer_Size = 32  ' buffer too small
    EC_No_Memory = 33    ' insufficient memory
    EC_No_Handles = 34   ' no more handles
    EC_Duplicate_Key = 50  ' record with same key already exists
    EC_Not_Found = 51      ' key/record not found
End Enum

' Type of procedure (function, sub, or property)
Public Enum ProcedureType
    ptFunction = 1
    ptPropertyGet = 2
    ptPropertyLet = 3
    ptPropertySet = 4
    ptSub = 5
End Enum


'---------------------------------------------------
' Language-Related Layout Utility Methods
'---------------------------------------------------

' This function retrieves the resource IDs for the
' language-specific layout changes to the form/UI
' of name strFrmName.  Those resource IDs are found
' in the mapping resource that's part of the RES
' file.  This function returns success/failure.
' Upon success, lFrmSizeID is set to the resource ID
' of the strFrmName form/UI size changes (this ID
' comes from the mapping), while lCtlLayoutID is set
' to the resource ID of that form/UI's constituent
' control layout changes.
' NOTE: This DOESN'T apply to the "Customize" box,
'       which has its own "hardcoded" IDs.
Public Function GetLangLayoutIDs(ByVal strFrmName As String, _
                        ByVal IResUI As IResources, _
                        ByRef lFrmSizeID As Long, _
                        ByRef lCtlLayoutID As Long) _
                       As Boolean
On Error Resume Next
    Dim strArrMap() As String
    Dim lLBMap As Long
    Dim lUBMap As Long
    Dim bGotMapArray As Boolean
    Dim i As Long
    
    ' Pull the layout ID mapping for this OCX.
    bGotMapArray = GetDataArray(IResUI, IDD_MapIDs, _
                          strArrMap, lLBMap, lUBMap)
    If bGotMapArray = False Then
        ' We DON'T have an ID mapping resource for
        ' the current language for this OCX, so
        ' indicate failure and GET OUT of the
        ' function (and clear errors).
        GetLangLayoutIDs = False
        Err.Clear
        Exit Function
    End If
    
    ' IF WE GOT TO HERE, WE HAVE AN ID MAPPING
    ' RESOURCE FOR THIS LANGUAGE/OCX COMBINATION.
    
    ' Look for the form/UI's mapping.
    For i = lLBMap To lUBMap
        Dim strArrKeyVal() As String
        Dim lLBKeyVal As Long
        
        ' Split the "key=value" pair.
        strArrKeyVal = Split(strArrMap(i), "=")
        Err.Clear  ' ignore earlier errors
        lLBKeyVal = LBound(strArrKeyVal)
        
        If Err.Number = 0 Then
            ' NOTE: Since LBound worked, UBound will
            '       also work.
            If (strArrKeyVal(lLBKeyVal) = strFrmName) _
              And (UBound(strArrKeyVal) = lLBKeyVal + 1) _
              Then
                ' We've found the mapping.  The
                ' value from that line is the ID
                ' for the form/UI size changes
                ' resource, while the constituent
                ' control layout changes resource
                ' ID is one more than that.
                lFrmSizeID = CLng(strArrKeyVal( _
                                    lLBKeyVal + 1))
                lCtlLayoutID = lFrmSizeID + 1
                
                ' Indicate success and GET OUT.
                GetLangLayoutIDs = True
                Err.Clear
                Exit Function
            End If
        Else
            ' This map line isn't valid, so clear
            ' the error and go to the next map line.
            Err.Clear
        End If  ' Err.Number = 0
    Next i
    
    ' IF WE GOT TO HERE, WE DIDN'T FIND THE MAPPING
    ' FOR THE FORM/UI.
    
    ' Indicate failure.
    GetLangLayoutIDs = False
    
    Err.Clear
End Function

' This function sets the form/UI's language-specific
' (minimum) ScaleHeight and/or ScaleWidth, if they
' are found in the resource.  The return value
' indicates whether or not there's been a change in
' at least one dimension.
' NOTE: sMinHeight and sMinWidth MUST contain the
'       original minimum ScaleHeight/ScaleWidth of
'       the form/UI when those variables are passed
'       in.  OTHERWISE, THIS FUNCTION'S RETURN VALUE
'       MAY INDICATE A CHANGE WHERE THER HAS BEEN
'       NO CHANGE.  If the function completes, the
'       minimum ScaleHeight/ScaleWidth (from the
'       resource) will be put into sMinHeight and
'       sMinWidth respectively.
Public Function GetNewFormSize(ByVal IRes As IResources, _
                        ByVal lFrmResID As Long, _
                        ByRef sMinHeight As Single, _
                        ByRef sMinWidth As Single) _
                       As Boolean
On Error Resume Next
    Dim bChangedSize As Boolean
    Dim strArrSizes() As String
    Dim lLBSizes As Long
    Dim lUBSizes As Long
    Dim bGotSizeArr As Boolean
    Dim i As Long
    
    bChangedSize = False  ' until told otherwise
    
    ' Get the array of sizes (if it can be found).
    bGotSizeArr = GetDataArray(IRes, lFrmResID, _
        strArrSizes, lLBSizes, lUBSizes)
    If bGotSizeArr = False Then
        ' We didn't find that resource, so indicate
        ' that there's no size changes for this
        ' form/UI, then GET OUT (and clear Err).
        GetNewFormSize = False
        Err.Clear
        Exit Function
    End If
    
    ' IF WE GOT TO HERE, THERE'S AN ARRAY AT THAT
    ' RESOURCE ID.
    
    For i = lLBSizes To lUBSizes
        Dim strArrSzLine() As String
        Dim lLBSzLine As Long
        
        ' Each line should be a comma-delimited list
        ' with the property and its value.
        strArrSzLine = Split(strArrSizes(i), ",")
        
        ' Look for the lower bound, IGNORING EARLIER
        ' ERRORS.
        Err.Clear
        lLBSzLine = LBound(strArrSzLine)
        
        If Err.Number = 0 Then
            ' There should only be 2 elements in
            ' this array.  (Since we got LBound, we
            ' should be able to get UBound without
            ' an error.)
            If (UBound(strArrSzLine) = lLBSzLine + 1) Then
                Dim strProp As String
                Dim sVal As Single
                
                strProp = strArrSzLine(lLBSzLine)
                sVal = CSng(strArrSzLine(lLBSzLine _
                                         + 1))
                
                If strProp = "ScaleHeight" Then
                    If (sVal <> sMinHeight) _
                      And (sVal > 0) Then
                        ' The height has changed.
                        sMinHeight = sVal
                        bChangedSize = True
                    End If  ' (sVal <> sMinHeight) And (sVal > 0)
                ElseIf strProp = "ScaleWidth" Then
                    If (sVal <> sMinWidth) _
                      And (sVal > 0) Then
                        ' The width has changed.
                        sMinWidth = sVal
                        bChangedSize = True
                    End If  ' (sVal <> sMinWidth) And (sVal > 0)
                End If  ' strProp = "ScaleHeight" / ElseIf strProp = "ScaleWidth"
            End If  ' UBound(strArrSzLine) = lLBSzLine + 1
        Else
            ' This line isn't valid, so go on to the
            ' next one (but clear the error).
            Err.Clear
        End If  ' Err.Number = 0
    Next i
    
    ' Return whether or not at least one of the
    ' dimensions has changed.
    GetNewFormSize = bChangedSize
    Err.Clear
End Function

' This function applies the language-specific layout
' of constituent controls to the form/UI whose
' Controls collection is passed into colCtls.  The
' new layout is stored in the lCtlResID resource in
' the IRes resource object.
Public Function ApplyNewCtlLayout(ByVal IRes As IResources, _
                            ByRef colCtls As Object, _
                            ByVal lCtlResID As Long) _
                           As Boolean
On Error Resume Next
    Dim strArrActTabs() As String
    Dim strArrCtlLayout() As String
    Dim lLBCtlLayout As Long
    Dim lUBCtlLayout As Long
    Dim bCtlLayoutExists As Boolean
    Dim i As Long
    
    ' Temporarily save the current active tab of
    ' each SSTab control (if any).
    strArrActTabs = SaveActiveTabs(colCtls)
    
    ' Get the array of constituent control layout
    ' changes.  Each element of the array is a line
    ' with comma-delimited information.  When split,
    ' the line should be as follows (LB is LBound):
    '   ArrLine(LB) = control name
    '   ArrLine(LB+1) = property name
    '   ArrLine(LB+2) = property value
    '   OPTIONAL: ArrLine(LB+3) = control array index
    ' NOTE: The FIRST set of changes have to do with
    '       switching any SSTab's active tab to the
    '       one against which the translated layouts
    '       were compared.  (This may NOT be the
    '       tab set in AppOpenSeqStart!!!)
    bCtlLayoutExists = GetDataArray(IRes, lCtlResID, _
        strArrCtlLayout, lLBCtlLayout, lUBCtlLayout)
    If bCtlLayoutExists = True Then
        For i = lLBCtlLayout To lUBCtlLayout
            Dim strArrLine() As String
            Dim lLBLine As Long
            Dim lUBLine As Long
            
            ' Split the line and get its bounds
            ' (IGNORE errors before the bounds).
            strArrLine = Split(strArrCtlLayout(i), _
                               ",")
            Err.Clear
            lLBLine = LBound(strArrLine)
            lUBLine = UBound(strArrLine)
            
            If Err.Number = 0 Then
                ' Change the property (if valid).
                If lUBLine = lLBLine + 2 Then
                    ' The control isn't part of a
                    ' control array.
                    CallByName _
                        colCtls(strArrLine(lLBLine)), _
                        strArrLine(lLBLine + 1), _
                        VbLet, _
                        strArrLine(lLBLine + 2)
                ElseIf lUBLine = lLBLine + 3 Then
                    ' The control is part of a
                    ' control array.
                    CallByName _
                        colCtls(strArrLine(lLBLine))(strArrLine(lLBLine + 3)), _
                        strArrLine(lLBLine + 1), _
                        VbLet, _
                        strArrLine(lLBLine + 2)
                End If  ' lUBLine = lLBLine + 2 / ElseIf lUBLine = lLBLine + 3
            Else
                ' This was an invalid line, so just
                ' go on to the next one.
                Err.Clear
            End If  ' Err.Number = 0
        Next i
    End If
    
    ' Restore the current active tab of each SSTab
    ' control (if any).
    RestoreActiveTabs colCtls, strArrActTabs
    
    ' Return whether or not there was a new control
    ' layout for this language.
    ApplyNewCtlLayout = bCtlLayoutExists
    Err.Clear
End Function

' This function applies the language-specific font
' to the form/UI passed into objUIFrm.
Public Function ApplyNewFont(ByVal IResTmpl As IResources, _
                    ByRef objUIFrm As Object, _
                    Optional ByVal bSetCtlFonts As Boolean = True) _
                   As Boolean
On Error Resume Next
    Dim strArrFontInfo() As String
    Dim lLBFontInfo As Long
    Dim lUBFontInfo As Long
    Dim bFontInfoExists As Boolean
    Dim bFontChanged As Boolean
    Dim i As Long
    
    bFontChanged = False  ' until told otherwise
    
    ' Get the new font's information.
    bFontInfoExists = GetDataArray(IResTmpl, _
        IDD_FontInfo, strArrFontInfo, lLBFontInfo, _
        lUBFontInfo)
    If bFontInfoExists = True Then
        For i = lLBFontInfo To lUBFontInfo
            Dim strArrLine() As String
            Dim lLBLine As Long
            
            ' Split the line and get its bounds
            ' (IGNORE errors before the bounds).
            strArrLine = Split(strArrFontInfo(i), _
                               ",")
            Err.Clear
            lLBLine = LBound(strArrLine)
            
            ' There should only be 2 elements in
            ' this array.  (Since we got LBound, we
            ' should be able to get UBound without
            ' an error.)
            If (UBound(strArrLine) = lLBLine + 1) Then
                bFontChanged = True
                
                ' Change that part of the font.
                CallByName objUIFrm.Font, _
                    strArrLine(lLBLine), VbLet, _
                    strArrLine(lLBLine + 1)
            Else
                ' This was an invalid line, so just
                ' go on to the next one.
                Err.Clear
            End If
        Next i
        
        If (bFontChanged = True) And (bSetCtlFonts = True) Then
            Dim ctl As Control
            For Each ctl In objUIFrm.Controls
                ' Change the constituent control's
                ' font (and headfont of a viewlist).
                If (TypeOf ctl Is AccpacViewList) Then
                    Set ctl.HeadFont = objUIFrm.Font
                End If
                
                Set ctl.Font = objUIFrm.Font
            Next ctl
        End If  ' (bFontChanged = True) And (bSetCtlFonts = True)
    End If  ' bFontInfoExists = True
    
    ' Return whether or not there was a new font for
    ' this language.
    ApplyNewFont = bFontInfoExists
    Err.Clear
End Function

' This function gets the data resource (of the
' specified ID) from the passed-in resource object,
' and splits it into a string array (the delimiter
' for the split is vbCrLf).  This function returns
' success/failure.  Upon success, strArr holds the
' string array, while lLBStrArr and lUBStrArr hold
' the array's lower and upper bound respectively.
' NOTE: If the split doesn't produce an array (i.e.
'       finding LBound fails), we return failure.
Public Function GetDataArray(ByVal IRes As IResources, _
                        ByVal lResID As Long, _
                        ByRef strArr() As String, _
                        ByRef lLBStrArr As Long, _
                        ByRef lUBStrArr As Long) _
                       As Boolean
On Error GoTo GetDataArrayHandler
    Dim btArr() As Byte
    
    If (IRes Is Nothing) Then
        ' This is a programmer error, so print a
        ' debug message and force a breakpoint to
        ' help with debugging.  Also indicate
        ' FAILURE and GET OUT.
        Debug.Print "IRes shouldn't be Nothing in " _
            & "GetLangLayoutIDs."
        Debug.Assert False  ' press F5 or F8 to continue
        GetDataArray = False
        Exit Function
    End If
    
    ' IF WE GOT TO HERE, THE LOCALIZED RESOURCE
    ' OBJECT EXISTS (IT SHOULD).
    
    ' Get and split the resource.
    ' NOTE: For proper data transformation, we NEED
    '       to retrieve the data into the byte array
    '       variable BEFORE splitting it.
    btArr = IRes.GetResData(lResID, RCDATA)
    strArr = Split(btArr, vbCrLf)
    
    ' Get the lower and upper bounds.
    lLBStrArr = LBound(strArr)
    lUBStrArr = UBound(strArr)
    
    If (Err.Number <> 0) Or (lLBStrArr > lUBStrArr) Then
        ' We DON'T really have an array (even though
        ' we don't have an error), so indicate
        ' failure.
        GetDataArray = False
    Else
        ' Indicate success.
        GetDataArray = True
    End If
Exit Function

GetDataArrayHandler:
    ' Indicate failure and clear errors.
    GetDataArray = False
    Err.Clear
End Function


'---------------------------------------------------
' Private Helpers for Language Layout Methods
'---------------------------------------------------

' This function looks for SSTabs in the collection
' of controls and saves their current active tab,
' so that we can go back to those tabs after doing
' control layout changes (which may change the
' active tabs).
Private Function SaveActiveTabs(ByRef colCtls As Object) _
                               As String()
On Error Resume Next
    Dim strActTabs As String
    Dim lActTabsLen As Long
    Dim ctl As Control
    
    strActTabs = ""
    
    ' Gather the SSTab information.
    For Each ctl In colCtls
        If (TypeOf ctl Is SSTab) Then
            With ctl
                Dim idx As Integer
                
                ' Start to add the information for
                ' this control.
                strActTabs = strActTabs & ";" & _
                    .Name & "," & .Tab
                
                ' Ignore earlier errors BEFORE finding
                ' the SSTab's array index (if any).
                Err.Clear
                idx = .Index
                
                If Err.Number = 0 Then
                    ' The SSTab is part of a control
                    ' array, so add its index too.
                    strActTabs = strActTabs & _
                        "," & idx
                Else
                    ' We don't need to add anything
                    ' (JUST clear the error).
                    Err.Clear
                End If
            End With  ' ctl
        End If
    Next ctl
    
    ' Now, trim the first ";" off the beginning of
    ' the string (if it wasn't empty).
    lActTabsLen = Len(strActTabs) - 1  ' to trim ";"
    If lActTabsLen < 0 Then
        ' We MUST pass a non-negative length to
        ' "Right".
        lActTabsLen = 0
    End If
    strActTabs = Right(strActTabs, lActTabsLen)
    
    ' Return the array of active tab information
    ' (if it exists).
    SaveActiveTabs = Split(strActTabs, ";")
    
    Err.Clear
End Function

' This sub restores the current active tabs for any
' SSTabs in the collection of controls.  This is
' done AFTER the control layout changes are applied
' (as they may have switched tabs).
Private Sub RestoreActiveTabs(ByRef colCtls As Object, _
                    ByRef strArrActTabs() As String)
On Error Resume Next
    Dim lLBActTabs As Long
    Dim lUBActTabs As Long
    Dim i As Long
    
    ' Get the array bounds.
    lLBActTabs = LBound(strArrActTabs)
    lUBActTabs = UBound(strArrActTabs)
    
    If (Err.Number <> 0) Or (lLBActTabs > lUBActTabs) Then
        ' We don't have an array, so there's nothing
        ' left to do but clear errors and GET OUT.
        Err.Clear
        Exit Sub
    End If
    
    ' IF WE GOT TO HERE, WE HAVE ACTIVE TABS TO
    ' RESTORE.
    
    For i = lLBActTabs To lUBActTabs
        Dim strArrLine() As String
        Dim lLBLine As Long
        Dim lUBLine As Long
        
        ' Split the line and get its bounds (IGNORE
        ' errors before the bounds).
        strArrLine = Split(strArrActTabs(i), ",")
        Err.Clear
        lLBLine = LBound(strArrLine)
        lUBLine = UBound(strArrLine)
        
        If Err.Number = 0 Then
            ' Restore the active tab (if valid).
            If lUBLine = lLBLine + 1 Then
                ' The control isn't part of a
                ' control array.
                colCtls(strArrLine(lLBLine)).Tab = _
                    strArrLine(lLBLine + 1)
            ElseIf lUBLine = lLBLine + 2 Then
                ' The control is part of a control
                ' array.
                colCtls(strArrLine(lLBLine))(strArrLine(lLBLine + 2)).Tab = _
                    strArrLine(lLBLine + 1)
            End If
        Else
            ' This was an invalid line, so just go
            ' on to the next one.
            Err.Clear
        End If  ' Err.Number = 0
    Next i
    
    Err.Clear
End Sub


'---------------------------------------------------
' ObjectKey Parameter Utility Methods
'---------------------------------------------------

' This function builds a standard ObjectKey string
' from an array of key (parameter name) strings
' (strArrKey) and an array of associated value
' strings (strArrVals).  ALL CALLERS that pass
' parameters (i.e. key/value pairs) to other UI's
' should call this function to package the
' parameters properly.
' NOTE: The array bounds (upper/lower) MUST match.
'       (i.e. We CAN'T have one array being 0-based
'       while the other is 1-based.)
Public Function KVBuildList(strArrKeys() As String, _
                            strArrVals() As String) _
                           As String
On Error Resume Next
    Dim lKeysLBound As Long
    Dim lKeysUBound As Long
    Dim lValsLBound As Long
    Dim lValsUBound As Long
    Dim i As Long

    ' Retrieve the key (parameter) array's bounds.
    lKeysLBound = LBound(strArrKeys)
    lKeysUBound = UBound(strArrKeys)
    
    If Err.Number <> 0 Then
        ' The UI programmer put in an emtpy array of
        ' keys, so print a debug message and force a
        ' breakpoint to help diagnosis.  Return an
        ' empty string, clear errors, and GET OUT of
        ' the function.
        Debug.Print "KVBuildList error: strArrKeys " _
            & "is empty."
        Debug.Assert False  ' press F5 or F8 to continue
        
        KVBuildList = ""
        Err.Clear
        Exit Function
    End If
    
    ' IF WE GOT TO HERE, WE HAVE A NON-EMPTY ARRAY
    ' OF KEYS.
    
    ' Retrieve the value array's bounds.
    lValsLBound = LBound(strArrVals)
    lValsUBound = UBound(strArrVals)
    
    If Err.Number <> 0 Then
        ' The UI programmer put in an empty array of
        ' values, so print a debug message and force
        ' a breakpoint to help diagnosis.  Return an
        ' empty string, clear errors, and GET OUT of
        ' the function.
        Debug.Print "KVBuildList error: strArrVals " _
            & "is empty."
        Debug.Assert False  ' press F5 or F8 to continue
        
        KVBuildList = ""
        Err.Clear
        Exit Function
    End If
    
    ' IF WE GOT TO HERE, WE HAVE A NON-EMPTY ARRAY
    ' OF VALUES.
    
    ' Make sure the array bounds match.
    If (lKeysLBound <> lValsLBound) _
      Or (lKeysUBound <> lValsUBound) _
      Then
        ' The two arrays don't have matching bounds,
        ' so print a debug message and force a
        ' breakpoint to help diagnosis.  Return an
        ' empty string, clear errors, and GET OUT of
        ' the function.
        Debug.Print "KVBuildList error: The array " _
            & "bounds for strArrKeys and strArrVals" _
            & " don't match."
        Debug.Assert False  ' press F5 or F8 to continue
        
        KVBuildList = ""
        Err.Clear
        Exit Function
    End If
    
    ' IF WE GOT TO HERE, THE ARRAY BOUNDS MATCH.
    
    ' Build up the string, one parameter at a time.
    KVBuildList = ""  ' default value
    For i = lKeysLBound To lKeysUBound
        KVBuildList = KVBuildList & _
            CreatePropertyString(strArrKeys(i), _
                                 strArrVals(i))
    Next i
    
    Err.Clear
End Function

' This function retrieves the value (into the
' strValue "ByRef" argument) associated with the key
' (parameter) named strKey from a string
' (strKeyValList) that contains key (parameter name)
' and value pairs.  The list of parameters should
' have been packaged by the other UI's into standard
' ObjectKey format (using the KVBuildList function).
' ALL RECEIVERS that receive standard ObjectKey
' strings from caller UI's should use this function
' for each parameter they want to retrieve.  The
' return value indicates whether or not the key was
' found (as strValue will be "" if the key wasn't
' found or if the value connected to that (valid)
' key happens to be "").
Public Function KVGetValue(ByVal strKeyValList As String, _
                           ByVal strKey As String, _
                           ByRef strValue As String) _
                          As Boolean
On Error Resume Next
    Dim iOffset1 As Integer    ' where the <key> is in the strKeyValList string
    Dim iOffset2 As Integer    ' where the <value> is in the strKeyValList string
    Dim lKeyLen As Long
    
    strValue = ""  ' until set otherwise
    
    ' Make sure the key isn't empty.
    If (strKey = "") Then
        ' The key (to search on) is empty, so print
        ' a debug message and force a breakpoint to
        ' help diagnosis.  Indicate "key not found",
        ' clear errors, and GET OUT of the function.
        Debug.Print "KVBuildList error: strKey is " _
            & "empty."
        Debug.Assert False
        
        KVGetValue = False
        Err.Clear
        Exit Function
    End If
    
    ' IF WE GOT TO HERE, WE'RE SEARCHING ON A NON-
    ' EMPTY KEY.
    
    ' Look for the "<key>=" string in the list.
    strKey = EscapeParam(strKey) & "="
    lKeyLen = Len(strKey)
    iOffset2 = StrComp(Left(strKeyValList, lKeyLen), _
                       strKey, vbBinaryCompare)
    If Err.Number <> 0 Then
        ' One of the strings is Null (error setting
        ' integer iOffset2), so print a debug
        ' message and force a breakpoint to help
        ' diagnosis.  Indicate "key not found",
        ' clear errors, and GET OUT of the function.
        Debug.Print "KVBuildList error: " & _
            "strKeyValList and/or strKey is Null."
        Debug.Assert False
        
        KVGetValue = False
        Err.Clear
        Exit Function
    End If
    
    ' IF WE GOT TO HERE, NONE OF THE ARGUMENTS ARE
    ' NULL.
    
    If iOffset2 = 0 Then
        ' It is the first key. Found it.
        iOffset1 = 1     ' Offset = 1
    Else
        ' It is not the first key. Not found yet.
        strKey = ParamMarker & strKey
        lKeyLen = Len(strKey)
        iOffset1 = InStr(1, strKeyValList, _
                        strKey, vbBinaryCompare)
        If iOffset1 = 0 Then
            ' We didn't find the parameter at all.
            ' Just indicate that the key wasn't
            ' found and GET OUT of the function.
            ' NOTE: This isn't an "error".
            KVGetValue = False
            Exit Function
        End If
    End If
    
    ' IF WE GOT TO HERE, WE FOUND THE KEY.
    
    ' Indicate that we found the key and go to the
    ' start of the value associated with that key.
    KVGetValue = True
    iOffset1 = iOffset1 + lKeyLen

    ' Get the value.
    iOffset2 = InStr(iOffset1, strKeyValList, ParamMarker, vbBinaryCompare)
    If iOffset2 = 0 Then  ' Missing end marked
        strValue = UnescapeParam( _
                       Mid(strKeyValList, iOffset1))
    Else
        strValue = UnescapeParam( _
                    Mid(strKeyValList, iOffset1, _
                        iOffset2 - iOffset1))
    End If
End Function


'---------------------------------------------------
' Private Helpers for ObjectKey Parameter Methods
'---------------------------------------------------

' This function creates a "Name=Value" pair (along
' with the parameter separator) for a parameter,
' which will end up as part of the ObjectKey.
Private Function CreatePropertyString(ByVal strParamName As String, _
                      ByVal strParamValue As String) _
                     As String
On Error Resume Next
    CreatePropertyString = _
        EscapeParam(strParamName) & _
        "=" & _
        EscapeParam(strParamValue) & _
        ParamMarker
    
    Err.Clear
End Function

Private Function EscapeParam(ByVal strUnescaped As String) _
                            As String
On Error Resume Next
    EscapeParam = Replace(strUnescaped, "\", EscMarker, , , vbBinaryCompare)
    EscapeParam = Replace(EscapeParam, "=", EqualMarker, , , vbBinaryCompare)
    EscapeParam = Replace(EscapeParam, ParamMarker, "\0", , , vbBinaryCompare)
    
    Err.Clear
End Function

Private Function UnescapeParam(ByVal strEscaped As String) _
                              As String
On Error Resume Next
    Dim sPos As Integer
    Dim ePos As Integer
    
    UnescapeParam = ""  ' until told otherwise
    
    sPos = 1
    ePos = InStr(1, strEscaped, "\", vbBinaryCompare)
    While ePos > 0
        If StrComp(Mid(strEscaped, ePos, Len(EqualMarker)), EqualMarker, vbBinaryCompare) = 0 Then
            UnescapeParam = UnescapeParam & Mid(strEscaped, sPos, ePos - sPos) & "="
            ePos = ePos + Len(EqualMarker)
            sPos = ePos
        ElseIf StrComp(Mid(strEscaped, ePos, Len("\0")), "\0", vbBinaryCompare) = 0 Then
            UnescapeParam = UnescapeParam & Mid(strEscaped, sPos, ePos - sPos) & ParamMarker
            ePos = ePos + Len("\0")
            sPos = ePos
        ElseIf StrComp(Mid(strEscaped, ePos, Len(EscMarker)), EscMarker, vbBinaryCompare) = 0 Then
            UnescapeParam = UnescapeParam & Mid(strEscaped, sPos, ePos - sPos) & "\"
            ePos = ePos + Len(EscMarker)
            sPos = ePos
        Else
            ePos = ePos + 1  ' invalid escape character!  Ignore to be safe!
        End If
        ePos = InStr(ePos, strEscaped, "\", vbBinaryCompare)
    Wend
    UnescapeParam = UnescapeParam & Mid(strEscaped, sPos)
    
    Err.Clear
End Function


'---------------------------------------------------
' Miscellaneous Utility Methods
'---------------------------------------------------

' This function takes in a message string and
' replaces "%i" tokens (where i is from 1 to 9 ONLY)
' with parameters from vParams (which is passed in
' as Array("string1", ...) ALWAYS).
' NOTE: UNLIKE THE SESSION, THE MAXIMUM IS 9 TOKENS!
Public Function MessageReplace(ByVal strMsg As String, _
                               ByVal vParams As Variant) _
                              As String
On Error GoTo MessageReplaceHandler
    Dim i As Long
    Dim lCnt As Long
    Dim lIdx As Long
    Dim lParamsLBound As Long
    Dim lParamsUBound As Long
    
    ' Start off with the original message.
    MessageReplace = strMsg  ' WON'T cause an error
    
    ' Figure out the array bounds and element count.
    lParamsLBound = LBound(vParams)
    lParamsUBound = UBound(vParams)
    lCnt = (lParamsUBound - lParamsLBound) + 1
    
    ' We can't replace anything past "%9".
    If lCnt > 9 Then
        lCnt = 9
    End If
    
    For i = 1 To lCnt
        ' Adjust for array vs. token bounds (i.e.
        ' "%i" is replaced by element lIdx, NOT i).
        ' THEN, make the current replacement.
        lIdx = (lParamsLBound + i) - 1
        MessageReplace = Replace(MessageReplace, _
            "%" & CStr(i), CStr(vParams(lIdx)))
    Next i
    
    Err.Clear
Exit Function

MessageReplaceHandler:
    ' Just GET OUT of the function (and clear Err).
    ' The return is whatever got replaced so far.
    ' NOTE: Empty arrays raises errors that don't
    '       need reporting.  Nothing is replaced.
    Err.Clear
End Function

' This function returns whether or not the view
' return code is an error.  (If it returns False, it
' could be a warning or a success code.)
' NO ERROR HANDLING! (Errors propagate to caller.)
Public Function IsVCError(ByVal retCode As AccpacCOMAPI.tagViewReturnCode) _
                         As Boolean
    ' Basically, error codes are positive numbers,
    ' except 10, which is the OLD warning code.
    IsVCError = ((retCode > VC_SUCCESS) _
                 And (retCode <> VC_OLD_WARNING))
End Function


'---------------------------------------------------
' Error Handling Functions
'---------------------------------------------------

' The standard error handler works this way:
' - IF there are SESSION ERRORS, they are shown in
'   the "ERROR" BOX.  Then, these SESSION ERRORS are
'   CLEARED.  If there's an accompanying VB ERROR,
'   WE NEVER display it (it's not useful).
' ** OTHERWISE **
' - Otherwise, there's ONLY a VB ERROR (if any).  If
'   bDisplayVBErr is True, the VB ERROR (if any) is
'   (ALSO) displayed to the user in a message box.
' ** IN BOTH CASES **
' - In BOTH cases, a DEBUG MESSAGE with the VB
'   ERROR'S details (or "No error") is printed to
'   help the UI developer.
' - In BOTH cases, if bClearVBErr is True, the VB
'   ERROR is cleared, otherwise (if an error exists)
'   it's re-raised (same number, source, etc.)
'
' NOTE: We NEED the session to be ByRef because we
'       may be clearing its errors (so if we had
'       ByVal, the actual mSession's errors wouldn't
'       be cleared).
Public Sub StdACCPACErrorHandler( _
                    ByRef objUICtrl As Object, _
                    ByRef Session As AccpacSession, _
                    ByVal IResTmpl As IResources, _
                    ByVal bDisplayVBErr As Boolean, _
                    ByVal bClearVBErr As Boolean)
    Dim lErrNum As Long
    Dim strErrSource As String
    Dim strErrDesc As String
    Dim strErrHelpFile As String
    Dim lErrHelpContext As Long
    
    ' Save the error information before opening our
    ' own error trap.
    With Err
        lErrNum = .Number
        strErrSource = .Source
        strErrDesc = .Description
        strErrHelpFile = .HelpFile
        lErrHelpContext = .HelpContext
    End With  ' Err
    
On Error GoTo SAEHHandler
    Dim errRpt As AccpacErrorReport
    Dim bSessErrsShown As Boolean
    Dim strDebugMsg As String
    Dim strACCPACErrMBCap As String
    Dim strMBMsg As String
    
    ' Create the debug message (always in English).
    If lErrNum = 0 Then
        strDebugMsg = "StdACCPACErrorHandler: NO VB" _
            & " ERROR"
    Else
        strDebugMsg = "StdACCPACErrorHandler: " & _
            "Called to handle Error #" & _
            CStr(lErrNum) & " -" & vbCrLf & "  " & _
            "Err.Source = " & strErrSource & vbCrLf _
            & "  Err.Description = " & strErrDesc
    End If
    
    ' Show (and clear) any session errors.
    Set errRpt = New AccpacErrorReport
    RaiseCloseSplashScreen objUICtrl  ' clears Err
    bSessErrsShown = errRpt.ShowError(Session)
    Set errRpt = Nothing  ' no longer needed
    
    If (bSessErrsShown = False) _
      And (bDisplayVBErr = True) _
      And (lErrNum <> 0) Then
        ' We don't have session errors, but we HAVE
        ' a VB ERROR that we want to show.  It needs
        ' resource strings.
        If IResTmpl Is Nothing Then
            ' We DON'T have localized resources, so
            ' show a "no resources" message instead
            ' (NO HELP).
            ' NOTE: UI PROGRAMMERS MUST USE
            '       mstrACCPACErrMBCap INSTEAD OF
            '       ACCPACErrMBCap.
            RaiseCloseSplashScreen objUICtrl  ' clears Err
            MsgBox NoLocResourcesTxt, _
                ACCPACErrMBStyle - vbMsgBoxHelpButton, _
                ACCPACErrMBCap
        Else
            ' We HAVE localized resources, so create
            ' the localized display strings.
            With IResTmpl
                strACCPACErrMBCap = _
                    .GetResString(IDS_ACCPACErrMBCap)
                strMBMsg = _
                    .GetResString(IDS_SAEHLStrECode) & _
                    CStr(lErrNum) & _
                    .GetResString(IDS_SAEHRStrECode) & _
                    vbCrLf & vbCrLf & strErrDesc
            End With  ' IResTmpl
            
            ' Now, display the VB ERROR.
            RaiseCloseSplashScreen objUICtrl  ' clears Err
            MsgBox strMBMsg, ACCPACErrMBStyle, _
                strACCPACErrMBCap, strErrHelpFile, _
                lErrHelpContext
        End If  ' IResTmpl Is Nothing
    End If  ' (bSessErrsShown = False) And (bDisplayVBErr = True) And (lErrNum <> 0)
    
    ' Print a debug message (VB Err or "no error").
    Debug.Print strDebugMsg
    
' Turn off the error trap before possibly re-raising
' the error.  (Err is cleared by this time).
On Error GoTo 0
    ' IF the intention was to re-raise the VB error,
    ' do so (if there was one).
    If (bClearVBErr = False) And (lErrNum <> 0) Then
        Err.Raise lErrNum, strErrSource, strErrDesc, _
            strErrHelpFile, lErrHelpContext
    End If
Exit Sub

SAEHHandler:
    Debug.Print "StdACCPACErrorHandler: Failed due " _
        & "to Error #" & CStr(Err.Number) & " -" & _
        vbCrLf & "  " & Err.Description
    
    ' IF the intention was to re-raise the ORIGINAL
    ' error that led StdACCPACErrorHandler to be
    ' called (and there was such an error), do so.
    ' Otherwise, clear the VB error object (which
    ' now holds the NEW error).
    If (bClearVBErr = False) And (lErrNum <> 0) Then
        Err.Raise lErrNum, strErrSource, strErrDesc, _
            strErrHelpFile, lErrHelpContext  ' ORIGINAL error
    Else
        Err.Clear  ' clear the NEW error
    End If
End Sub

' The UI (exposed) property error handler prints a
' DEBUG MESSAGE that contains the VB ERROR's (Err's)
' details.  It then CLEARS the VB ERROR.
Public Sub UIPropACCPACErrorHandler( _
                    ByVal propName As String, _
                    ByVal propType As ProcedureType, _
                    Optional ByVal errExtraInfo As String = "")
    Dim lErrNum As Long
    Dim strErrSource As String
    Dim strErrDesc As String
    
    ' Save the error information before opening our
    ' own error trap.
    ' NOTE: Since we DON'T re-raise errors and we
    '       DON'T display errors (in message boxes)
    '       in this sub, we DON'T need the HelpFile
    '       and HelpContext information.
    With Err
        lErrNum = .Number
        strErrSource = .Source
        strErrDesc = .Description
    End With  ' Err

On Error GoTo UIPAEHHandler
    ' If there wasn't an error, GET OUT of the sub.
    If lErrNum = 0 Then
        Debug.Print "UIPropACCPACErrorHandler was " _
            & "called when there were no errors." & _
            vbCrLf & "  Arguments: propName = " & _
            propName & ", propType = " & _
            ProcTypeStr(propType) & "," & vbCrLf & _
            "             errExtraInfo = " & _
            errExtraInfo
        
        Exit Sub
    End If
    
    ' IF WE'RE STILL IN THE SUB, WE DO HAVE AN ERROR
    ' TO REPORT.

    Dim strDebugMsg As String
    
    ' Create the debug message.
    strDebugMsg = "Error #" & CStr(lErrNum) & " - " _
        & "(UI) [" & ProcTypeStr(propType) & ": " & _
        propName & "]" & vbCrLf & "  " & strErrDesc
        
    ' If any extra information is given, add a new
    ' line containing this information to the
    ' debug message.
    If (errExtraInfo <> "") And (errExtraInfo <> vbNullString) Then
        strDebugMsg = strDebugMsg & vbCrLf & _
            "  " & errExtraInfo
    End If
    
    ' Print the debug message.
    Debug.Print strDebugMsg
    Err.Clear  ' just to be sure
Exit Sub

UIPAEHHandler:
    With Err
        Debug.Print "UIPropACCPACErrorHandler: " & _
            "Failed due to Error #" & CStr(.Number) _
            & " -" & vbCrLf & "  " & .Description
        .Clear
    End With  ' Err
End Sub

' DESIGN NOTE:
'   Because the caller of an ACCPACControl's
'   properties/methods is NOT in this module, the
'   error won't propagate up to the caller's error
'   handler (and so on), BUT the Err object will
'   STILL hold error information.  Thus, a UI
'   developer can choose to ignore the propagated
'   error or use "in-line" checks.
'   EXAMPLE: (Say, in "UI.InitAppControls()")
'       mAppControls("myCtl").UIVisibleFlag = False  ' in-line check this
'       If Err.Number <> 0 Then
'           ' At least try to disable it, but if we
'           ' can't do that either, that's OK.
'            mAppControls("myCtl").UIEnabledFlag = False  ' ignore propagation
'       End If

' The ACCPACControl (wrapped non-data source
' control) error handler prints a DEBUG MESSAGE that
' contains the VB ERROR's (Err's) details.  It then
' RE-RAISES the VB ERROR, but with a more detailed
' Err.Description. (The new Err.Description contains
' the contents of the debug message.)
' NOTE: DO NOT Do ANY "On Error..." before setting
'       lErrNum, etc. as "On Error..." will wipe
'       out the error.
Public Sub CtlACCPACErrorHandler( _
                    ByVal procName As String, _
                    ByVal procType As ProcedureType, _
                    ByVal errTitle As String, _
                    Optional ByVal errExtraInfo As String = "")
    Dim lErrNum As Long
    Dim strErrSource As String
    Dim strOrigErrDesc As String
    Dim strErrHelpFile As String
    Dim lErrHelpContext As Long
    Dim strNewErrDesc As String
    
    ' Save the error information before opening our
    ' own error trap.
    With Err
        lErrNum = .Number
        strErrSource = .Source
        strOrigErrDesc = .Description
        strErrHelpFile = .HelpFile
        lErrHelpContext = .HelpContext
    End With  ' Err
    
On Error GoTo CtlAEHHandler
    ' If there wasn't an error, GET OUT of the sub.
    If lErrNum = 0 Then
        Debug.Print "CtlACCPACErrorHandler was " & _
            "called when there were no errors." & _
            vbCrLf & "  Arguments: procName = " & _
            procName & ", procType = " & _
            ProcTypeStr(procType) & "," & vbCrLf & _
            "             errTitle = " & errTitle & _
            "," & vbCrLf & "             " & _
            "errExtraInfo = " & errExtraInfo
        
        Exit Sub
    End If
    
    ' IF WE'RE STILL IN THE SUB, WE DO HAVE AN ERROR
    ' TO REPORT.
    
    ' Make up the new error description (also used
    ' as the debug statement's string).
    strNewErrDesc = "Error #" & CStr(lErrNum) & _
        " - " & errTitle & " (ACCPACControl) [" & _
        ProcTypeStr(procType) & ": " & procName & _
        "]" & vbCrLf & "  " & strOrigErrDesc
    
    ' If any extra information is given, add a new
    ' line containing this information to the new
    ' error description.
    If (errExtraInfo <> "") And (errExtraInfo <> vbNullString) Then
        strNewErrDesc = strNewErrDesc & vbCrLf & _
            "  " & errExtraInfo
    End If
    
    Debug.Print strNewErrDesc

' Turn off the error trap before re-raising the
' error.
On Error GoTo 0
    Err.Raise lErrNum, strErrSource, strNewErrDesc, _
        strErrHelpFile, lErrHelpContext
Exit Sub

CtlAEHHandler:
    Debug.Print "CtlACCPACErrorHandler: Failed due " _
        & "to Error #" & CStr(Err.Number) & " -" & _
        vbCrLf & "  " & Err.Description
    
    ' Re-raise the ORIGINAL error that caused
    ' CtlACCPACErrorHandler to be called.
    Err.Raise lErrNum, strErrSource, strOrigErrDesc, _
        strErrHelpFile, lErrHelpContext
End Sub

' DESIGN NOTE:
'   Because the caller of an ACCPACCustCtl's
'   properties/methods is NOT in this module, the
'   error won't propagate up to the caller's error
'   handler (and so on), BUT the Err object will
'   STILL hold error information.  Thus, callers of
'   an ACCPACCustCtl can still use "in-line" checks.
'   EXAMPLE:
'       mCustomCtls(idx).VisibleFlag = False  ' in-line check this
'       If Err.Number <> 0 Then
'           ' At least try to disable it, but if we
'           ' can't do that either, that's OK.
'            mAppControls(idx).EnabledFlag = False  ' ignore propagation
'       End If

' The ACCPACCustCtl (wrapped ACCPACControl) error
' handler prints a DEBUG MESSAGE that contains the
' VB ERROR's (Err's) details.  It then RE-RAISES the
' VB ERROR with a more detailed Err.Description.
' (The new Err.Description contains the contents of
' the debug message.)
' NOTE: DO NOT Do ANY "On Error..." before setting
'       lErrNum, etc. as "On Error..." will wipe
'       out the error.
Public Sub CustACCPACErrorHandler( _
                    ByVal procName As String, _
                    ByVal procType As ProcedureType, _
                    ByVal errTitle As String)
    Dim lErrNum As Long
    Dim strErrSource As String
    Dim strOrigErrDesc As String
    Dim strErrHelpFile As String
    Dim lErrHelpContext As Long
    Dim strNewErrDesc As String
    
    ' Save the error information before opening our
    ' own error trap.
    With Err
        lErrNum = .Number
        strErrSource = .Source
        strOrigErrDesc = .Description
        strErrHelpFile = .HelpFile
        lErrHelpContext = .HelpContext
    End With  ' Err

On Error GoTo CustAEHHandler
    ' If there wasn't an error, GET OUT of the sub.
    If lErrNum = 0 Then
        Debug.Print "CustACCPACErrorHandler was " & _
            "called when there were no errors." & _
            vbCrLf & "  Arguments: procName = " & _
            procName & ", procType = " & _
            ProcTypeStr(procType) & "," & vbCrLf & _
            "             errTitle = " & errTitle
        
        Exit Sub
    End If
    
    ' IF WE'RE STILL IN THE SUB, WE DO HAVE AN ERROR
    ' TO REPORT.

    ' Make up the new error description (also used
    ' as the debug statement's string).
    strNewErrDesc = "Error #" & CStr(lErrNum) & _
        " - " & errTitle & " (ACCPACCustCtl) [" & _
        ProcTypeStr(procType) & ": " & procName & _
        "]" & vbCrLf & "  " & strOrigErrDesc
        
    Debug.Print strNewErrDesc

' Turn off the error trap before re-raising the
' error.
On Error GoTo 0
    Err.Raise lErrNum, strErrSource, strNewErrDesc, _
        strErrHelpFile, lErrHelpContext
Exit Sub

CustAEHHandler:
    Debug.Print "CustACCPACErrorHandler: Failed due" _
        & " to Error #" & CStr(Err.Number) & " -" & _
        vbCrLf & "  " & Err.Description
    
    ' Re-raise the ORIGINAL error that caused
    ' CustACCPACErrorHandler to be called.
    Err.Raise lErrNum, strErrSource, strOrigErrDesc, _
        strErrHelpFile, lErrHelpContext
End Sub

' The ACCPACDSControl (wrapped data source) error
' handler will show all SESSION ERRORS in the
' "ERROR" BOX, then CLEAR all of these SESSION
' ERRORS (if they and the passed-in data source
' exist).  WHETHER OR NOT THERE ARE ANY SESSION
' ERRORS, this error handler will ALWAYS print a
' DEBUG MESSAGE that contains the VB ERROR's (Err's)
' details and any extra information passed in by the
' caller (i.e. arguments passed in to the procedure
' that caused the error).  Finally, it will ALWAYS
' RE-RAISE the VB ERROR, but with a more detailed
' Err.Description. (The new Err.Description contains
' the contents of the debug message.)
' NOTE: We NEED the data source (ds) to be ByRef
'       because we may be clearing its session's
'       errors (so if we had ByVal, the actual
'       data source's session's errors wouldn't
'       be cleared).
' NOTE: DO NOT Do ANY "On Error..." before setting
'       lErrNum, etc. as "On Error..." will wipe
'       out the error.
Public Sub DSACCPACErrorHandler( _
                    ByRef ds As AccpacDataSource, _
                    ByVal procName As String, _
                    ByVal procType As ProcedureType, _
                    ByVal errTitle As String, _
                    Optional ByVal errExtraInfo As String = "")
    Dim lErrNum As Long
    Dim strErrSource As String
    Dim strOrigErrDesc As String
    Dim strErrHelpFile As String
    Dim lErrHelpContext As Long
    Dim strNewErrDesc As String
    
    ' Save the error information before opening our
    ' own error trap.
    With Err
        lErrNum = .Number
        strErrSource = .Source
        strOrigErrDesc = .Description
        strErrHelpFile = .HelpFile
        lErrHelpContext = .HelpContext
    End With  ' Err
    
On Error GoTo DSAEHHandler
    ' If there wasn't an error, GET OUT of the sub.
    If lErrNum = 0 Then
        Debug.Print "DSACCPACErrorHandler was " & _
            "called when there were no errors." & _
            vbCrLf & "  Arguments: ds " & _
            "(AccpacDataSource), procName = " & _
            procName & "," & vbCrLf & _
            "             procType = " & _
            ProcTypeStr(procType) & ", errTitle = " _
            & errTitle & "," & vbCrLf & _
            "             errExtraInfo = " & _
            errExtraInfo
        
        Exit Sub
    End If
    
    ' IF WE'RE STILL IN THE SUB, WE DO HAVE AN ERROR
    ' TO REPORT.
    
    ' Show (and clear) any session errors from the
    ' data source.  (First make sure that the data
    ' source exists.)
    ' NOTE: Since wrapped datasource controls aren't
    '       accessible to macros (unless they try
    '       in the BeforeUIAppOpened HIDDEN handler)
    '       and since we don't pass in the UI, we
    '       can't raise CloseSplashScreen here.
    If Not (ds Is Nothing) Then
        Dim errRpt As AccpacErrorReport
        
        Set errRpt = New AccpacErrorReport
        errRpt.ShowError ds.Session  ' passed ByRef
        Set errRpt = Nothing  ' no longer used
    End If
    
    ' Make up the new error description (also used
    ' as the debug message).
    strNewErrDesc = "Error #" & CStr(lErrNum) & _
        " - " & errTitle & " (ACCPACDSControl) [" & _
        ProcTypeStr(procType) & ": " & procName & _
        "]" & vbCrLf & "  " & strOrigErrDesc
        
    ' If any extra information is given, add a new
    ' line containing this information to the new
    ' error description.
    If (errExtraInfo <> "") And (errExtraInfo <> vbNullString) Then
        strNewErrDesc = strNewErrDesc & vbCrLf & _
            "  " & errExtraInfo
    End If
    
    ' Print a debug message for the VB error.
    Debug.Print strNewErrDesc
    
' Turn off the error trap before re-raising the
' error.
On Error GoTo 0
    Err.Raise lErrNum, strErrSource, strNewErrDesc, _
        strErrHelpFile, lErrHelpContext
Exit Sub

DSAEHHandler:
    Debug.Print "DSACCPACErrorHandler: Failed due " _
        & "to Error #" & CStr(Err.Number) & " -" & _
        vbCrLf & "  " & Err.Description
    
    ' Re-raise the ORIGINAL error that caused
    ' DSACCPACErrorHandler to be called.
    Err.Raise lErrNum, strErrSource, strOrigErrDesc, _
        strErrHelpFile, lErrHelpContext
End Sub


'---------------------------------------------------
' Public Error Handling Helper Functions
'---------------------------------------------------

' THIS FUNCTION AIDS COLLECTION CLASSES' ERROR
' HANDLERS FOR PROGRAMMING ERRORS (i.e. no message
' translation).  It returns the the STRING version
' of the index used to access collection items.
' Returned string based on the index's type:
'   * STRING: the index enclosed in quotes
'   * NON-STRING NUMERIC: the index (as string)
'   * OTHER: a "[WRONG TYPE...]" string
Public Function GetColIdxStr(ByVal vIdx As Variant) _
                                        As String
On Error Resume Next
    If VarType(vIdx) = vbString Then
        GetColIdxStr = """" & vIdx & """"  ' NO automatic translation from CStr!
    ElseIf IsEmpty(vIdx) = True Then
        ' NOTE: "Empty" is considered numeric, so we
        '       have to catch this case first.
        GetColIdxStr = "[WRONG TYPE: Variant is " & _
            "Empty]"
    ElseIf IsNumeric(vIdx) = True Then
        GetColIdxStr = CStr(vIdx)
    Else
        GetColIdxStr = "[WRONG TYPE: Variant is of " _
            & "type " & TypeName(vIdx) & "]"
    End If
    
    Err.Clear
End Function


'---------------------------------------------------
' Private Helpers for Error Handling Functions
'---------------------------------------------------

' NOTE: The CALLING FUNCTION/SUB MUST SAVE ITS ERROR
'       INFORMATION (i.e. Description, Number,
'       Source) BEFORE THIS FUNCTION IS CALLED!!!
'       Any errors will be cleared once inside
'       this function (and any errors returned will
'       be raised by this function).
Private Function ProcTypeStr(ByVal procType As ProcedureType) _
                                        As String
On Error GoTo ProcTypeStrHandler
    Select Case procType
        Case ptFunction
            ProcTypeStr = "Function"
        Case ptPropertyGet
            ProcTypeStr = "Property (Get)"
        Case ptPropertyLet
            ProcTypeStr = "Property (Let)"
        Case ptPropertySet
            ProcTypeStr = "Property (Set)"
        Case ptSub
            ProcTypeStr = "Sub"
        Case Else
            Debug.Print "ProcTypeStr: " & _
                CStr(procType) & " is an invalid " _
                & "procedure type" & vbCrLf & _
                "  (should be from 1 to 5)"
            ProcTypeStr = "UNKNOWN PROCEDURE TYPE"
    End Select
Exit Function

ProcTypeStrHandler:
    Debug.Print "ProcTypeStr: Failed due to Error #" _
        & CStr(Err.Number) & " -" & vbCrLf & "  " _
        & Err.Description
    ProcTypeStr = "UNKNOWN PROCEDURE TYPE"  ' return default string
    Err.Clear
End Function  ' DO NOT go back inside this function

' This sub gets the UI to raise the
' CloseSplashScreen event, but clears Err if needed.
Private Sub RaiseCloseSplashScreen(ByRef objUICtrl As Object)
On Error Resume Next
    If (Not (objUICtrl Is Nothing)) Then
        objUICtrl.FireCloseSplashScreen
    End If
    
    Err.Clear
End Sub


'---------------------------------------------------
' Public Helper Functions
'---------------------------------------------------

' This sub logs a help event with the PEP system
Public Sub LogAdvisorHelpEvent(Session As AccpacSession, ControlName As String, lHelpContextID As Long)
On Error GoTo LogAdvisorHandler
    Dim st As SYSTEMTIME
    GetSystemTime st
    Dim UTCNow As Variant
    UTCNow = DateSerial(st.wYear, st.wMonth, st.wDay)
    UTCNow = DateAdd("h", st.wHour, UTCNow)
    UTCNow = DateAdd("n", st.wMinute, UTCNow)
    UTCNow = DateAdd("s", st.wSecond, UTCNow)

    Dim dsInfo As AccpacAdvisorEventInfo
    Set dsInfo = New AccpacAdvisorEventInfo
    dsInfo.AddInfo AI_HELP_FILE, Mid$(App.HelpFile, 1 + InStrRev(App.HelpFile, "\"))
    dsInfo.AddInfo AI_HELP_CONTEXT, CStr(lHelpContextID)
    dsInfo.AddInfo AI_TASK_ID, ACCPACProgramName
    dsInfo.AddInfo AI_SCREEN_FIELD, CStr(ControlName)
    dsInfo.AddInfo AI_START_TIMESTAMP, UTCNow
    Session.LogAdvisorEvent AE_HELP, dsInfo
LogAdvisorHandler:
    Err.Clear
End Sub
