VERSION 5.00
Object = "{831FDD16-0C5C-11D2-A9FC-0000F8754DA1}#2.0#0"; "MSCOMCTL.OCX"
Begin VB.Form ACCPACUICustomizeBox 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Customize (DO NOT MODIFY FORM PROPERTIES/CODE!!!)"
   ClientHeight    =   7215
   ClientLeft      =   2715
   ClientTop       =   1005
   ClientWidth     =   9165
   Icon            =   "ACCPACUICustomizeBox.frx":0000
   LinkTopic       =   "Form1"
   LockControls    =   -1  'True
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   7215
   ScaleWidth      =   9165
   ShowInTaskbar   =   0   'False
   StartUpPosition =   1  'CenterOwner
   Begin VB.CommandButton cmdNewProfile 
      Height          =   315
      Left            =   5010
      Picture         =   "ACCPACUICustomizeBox.frx":000C
      Style           =   1  'Graphical
      TabIndex        =   2
      Top             =   135
      Width           =   240
   End
   Begin VB.ComboBox cboWorkingProfile 
      Height          =   315
      Left            =   2100
      Sorted          =   -1  'True
      Style           =   2  'Dropdown List
      TabIndex        =   1
      Top             =   150
      Width           =   2865
   End
   Begin MSComctlLib.ListView lvwOtherProfiles 
      Height          =   1515
      Left            =   150
      TabIndex        =   8
      Top             =   5100
      Width           =   8865
      _ExtentX        =   15637
      _ExtentY        =   2672
      View            =   3
      Sorted          =   -1  'True
      LabelWrap       =   -1  'True
      HideSelection   =   -1  'True
      Checkboxes      =   -1  'True
      _Version        =   393217
      ForeColor       =   -2147483640
      BackColor       =   -2147483643
      BorderStyle     =   1
      Appearance      =   1
      NumItems        =   1
      BeginProperty ColumnHeader(1) {BDD1F052-858B-11D1-B16A-00C0F0283628} 
         Key             =   "ProfileID"
         Text            =   "ProfileID"
         Object.Width           =   2540
      EndProperty
   End
   Begin MSComctlLib.TreeView tvwShow 
      Height          =   3165
      Left            =   150
      TabIndex        =   6
      Top             =   1425
      Width           =   8865
      _ExtentX        =   15637
      _ExtentY        =   5583
      _Version        =   393217
      LabelEdit       =   1
      LineStyle       =   1
      Checkboxes      =   -1  'True
      Appearance      =   1
   End
   Begin VB.CommandButton cmdSave 
      Caption         =   "&Save"
      Height          =   315
      Left            =   7950
      TabIndex        =   11
      Top             =   6750
      Width           =   1065
   End
   Begin VB.CommandButton cmdCancel 
      Cancel          =   -1  'True
      Caption         =   "Cancel"
      Height          =   315
      Left            =   6750
      TabIndex        =   10
      Top             =   6750
      Width           =   1065
   End
   Begin VB.CommandButton cmdOK 
      Caption         =   "OK"
      Default         =   -1  'True
      Height          =   315
      Left            =   5550
      TabIndex        =   9
      Top             =   6750
      Width           =   1065
   End
   Begin VB.TextBox txtWPDesc 
      BackColor       =   &H8000000F&
      Height          =   315
      Left            =   2100
      Locked          =   -1  'True
      TabIndex        =   4
      TabStop         =   0   'False
      Text            =   "(profile description goes here)"
      Top             =   600
      Width           =   6915
   End
   Begin VB.Label lblWorking 
      Caption         =   "@&Working Profile@"
      ForeColor       =   &H80000008&
      Height          =   315
      Left            =   150
      TabIndex        =   0
      Top             =   150
      Width           =   1890
   End
   Begin VB.Label lblDescription 
      Caption         =   "@Description@"
      ForeColor       =   &H80000008&
      Height          =   315
      Left            =   150
      TabIndex        =   3
      Top             =   600
      Width           =   1890
   End
   Begin VB.Label lblOtherProfiles 
      Caption         =   "@&Apply this customization to the other selected profiles@"
      ForeColor       =   &H80000008&
      Height          =   240
      Left            =   150
      TabIndex        =   7
      Top             =   4800
      Width           =   8865
   End
   Begin VB.Label lblShow 
      Caption         =   "@S&how these controls on the form@"
      ForeColor       =   &H80000008&
      Height          =   240
      Left            =   150
      TabIndex        =   5
      Top             =   1125
      Width           =   8865
   End
End
Attribute VB_Name = "ACCPACUICustomizeBox"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Attribute VB_Description = """Customize"" box for the ACCPAC UI Control"
' ACCPAC UI DEVELOPERS: DO NOT MODIFY THIS FILE!
'
' Form Class Module: ACCPACUICustomizeBox
' Template 5.5A Revision: cycle 2
'
' Description: This module contains code for the
'              "Customize" box.  This box allows
'              users with administrator privileges
'              to decide which customizable controls
'              (that are part of your ACCPAC UI
'              control) to show in various profiles.
'
' Copyright 1999-2007 Sage Accpac International, Inc.
'   All rights reserved.
'

Option Compare Text
Option Explicit


'---------------------------------------------------
' Constants
'---------------------------------------------------

' "UI Profile Maintenance" object ID
Private Const UIProfMaintPrgID As String = "AS8001"

' "Other Profiles" box layout constants
Private Const CBOthProfilesColWidth As Single = 2660

' "Other Profiles" box key constants (which AREN'T
' translated as they are INTERNAL keys that aren't
' shown)
Private Const CBOthProfilesPIDKey As String = _
    "ProfileID"

' NON-translated "no resources" message
Private Const CBNoLocResourcesMsg As String = _
    "[""Customize"" Box]" & vbCrLf & vbCrLf & _
    NoLocResourcesTxt


'---------------------------------------------------
' Variables
'---------------------------------------------------

' NOTE: We NEED mIResTmpl as we send it to
'       StdACCPACErrorHandler in different places!!!
'       We NEED mobjUICtrl as we need its ServerName
'       to open "UI Profile Maintenance" modally.
' Members for arguments passed from the UI control
Private mCustCtls As ACCPACCustCtls
Private mCustSession As AccpacSession
Private mobjUICtrl As Object  ' WE NEED THIS HERE!!!
Private mIResTmpl As IResources  ' WE NEED THIS HERE!!!
Private mstrWkProfileID As String

' System DB link private member (since saving must
' be done to the system DB and most UIs only have
' a company link)
Private mCustDBLinkSysRW As AccpacDBLink

' Other private members
Private mstrHelpFile As String
Private mstrACCPACErrMBCap As String
Private mstrACCPACWarnMBCap As String
Private mstrCBDlgCap As String
Private mstrCBDlgIdent As String
Private mstrCBNoSaveForOKMsg As String
Private mstrCBSetupFormFailMsg As String
Private mstrWkProfileDesc As String


'---------------------------------------------------
' "Customize" Box Event Handlers
'---------------------------------------------------

' The "Working Profile" box's "Click" event happens
' when you CHOOSE an item, THEN CLOSE the dropdown
' part (OR PRESS [ESC]).  If you "re-choose" the
' same working profile, this event STILL happens, so
' we must handle this case (i.e. don't go through
' all of the work to change the working profile).
' If there's NO working profile selected and you
' OPEN, then CLOSE, the dropdown part with the mouse
' WITHOUT CHOOSING ANYTHING, this event DOESN'T
' HAPPEN.  BUT, if there's NO working profile
' selected and you OPEN the dropdown part, then
' HIGHLIGHT an item but then PRESS [ESC], this event
' STILL HAPPENS.  Thus, we have to handle the case
' where you "re-choose" nothing, in which case we
' have to pop up the message box and disable some
' of the dialog box's controls.
' NOTE: The "Other Profiles" box is cleared when the
'       working profile ACTUALLY CHANGES.  This will
'       prevent a different profile's customizations
'       from being saved in other profiles that go
'       with the previous working profile.
Private Sub cboWorkingProfile_Click()
On Error GoTo cboWorkingProfileClickHandler
    If cboWorkingProfile.Text = mstrWkProfileID Then
        ' The admin "re-chose" the previous working
        ' profile, so don't change anything.  If
        ' NO working profile was previously chosen
        ' (and there's STILL none chosen now),
        ' disable part of the dialog (until a
        ' working profile is selected).
        If (mstrWkProfileID = "") Or (mstrWkProfileID = vbNullString) Then
            EnableWPDependentParts False
        End If  ' (mstrWkProfileID = "") Or (mstrWkProfileID = vbNullString)
    Else
        ' The admin selected a DIFFERENT working
        ' profile, so do the changes.
        Dim lvwItems As ListItems
        Set lvwItems = lvwOtherProfiles.ListItems
        
        If (Not (lvwItems Is Nothing)) Then
            ' If there used to be a working profile,
            ' add it back to the "Other Profiles"
            ' box.
            If (mstrWkProfileID <> "") And (mstrWkProfileID <> vbNullString) Then
                Dim lsItem As ListItem
                Set lsItem = lvwItems.Add(, , _
                                    mstrWkProfileID)
            
                If (Not (lsItem Is Nothing)) Then
                    lsItem.Tag = mstrWkProfileDesc
                End If  ' Not (lsItem Is Nothing)
            End If  ' (mstrWkProfileID <> "") And (mstrWkProfileID <> vbNullString)
            
            ' After taking care of the previous
            ' working profile, we can now set the
            ' changed working profile's ID member.
            ' We use this ID to find the profile in
            ' the "Other Profiles" box so that it
            ' can be removed ("hidden") and so that
            ' we can store/display the changed
            ' working profile's description.
            mstrWkProfileID = cboWorkingProfile.Text
            
            Dim lsNewWPItem As ListItem
            Set lsNewWPItem = _
                lvwOtherProfiles.FindItem( _
                           mstrWkProfileID, lvwText)
            If (Not (lsNewWPItem Is Nothing)) Then
                With lsNewWPItem
                    ' Get the description from the
                    ' tag (and save in member).
                    mstrWkProfileDesc = .Tag
                    
                    ' Display the new description.
                    txtWPDesc.Text = mstrWkProfileDesc
                    
                    ' NOW, remove ("hide") the
                    ' profile.
                    Dim cutIdx As Integer
                    cutIdx = .Index
                    lvwItems.Remove cutIdx
                End With  ' lsNewWPItem
            End If
            
            ' Now, uncheck everything in the list
            ' box AND show this changed working
            ' profile's customizations (this will
            ' also enable the whole dialog).
            UncheckOtherProfiles
            ShowProfileCustomizations
        End If  ' Not (lvwItems Is Nothing)
    End If  ' cboWorkingProfile.Text = mstrWkProfileID
    
    Err.Clear  ' in case of uncleared errors raised by objects
Exit Sub

cboWorkingProfileClickHandler:
    ' Display (and clear) the error, then go on.
    StdACCPACErrorHandler mobjUICtrl, mCustSession, _
        mIResTmpl, True, True
    Resume Next
End Sub

Private Sub cmdCancel_Click()
On Error Resume Next
    ' JUST close the dialog box (WITHOUT SAVING ANY
    ' UNSAVED CHANGES).
    Unload Me
    Err.Clear
End Sub

Private Sub cmdNewProfile_Click()
On Error Resume Next
    ' Disable the button temporarily so that the
    ' user won't be able to click it more than once
    ' before the first popup UI is closed.
    cmdNewProfile.Enabled = False
    
    If (Not (mCustSession Is Nothing)) Then
        Dim contUIProfiles As AccpacContainerObject
        Dim strArrKeys(1 To 1) As String
        Dim strArrVals(1 To 1) As String
        Dim strCLSID As String
        Dim strCodebase As String
        Dim strObjHandle As String
        Dim strProcessorName As String
        Dim strReturn As String
        
        ' Create the special SUPPRESS_CUSTOMIZE=YES
        ' object key to pass to the the "UI Profile
        ' Maintenance" UI, so it won't show the
        ' "Customize" box (and create a "loop" of
        ' UI/Customize/UI/Customize...).
        strArrKeys(1) = "SUPPRESS_CUSTOMIZE"
        strArrVals(1) = "YES"
        
        ' Get the appropriate Roto information for
        ' the "UI Profile Maintenance" UI.
        mCustSession.CreateObjectHandle _
            UIProfMaintPrgID, _
            KVBuildList(strArrKeys, strArrVals), _
            strObjHandle, strCLSID, strCodebase
        
        ' Show the UI modally (the return value will
        ' be the current profile ID for the UI when
        ' it is closed).
        Set contUIProfiles = New AccpacContainerObject
        With contUIProfiles
            .Init strCLSID, strCodebase, _
                strObjHandle, mobjUICtrl.ServerName
            strReturn = .Show(Me.hWnd)
            .Close
        End With  ' contUIProfiles
        Set contUIProfiles = Nothing  ' no longer needed
        
        ' Retrieve the working profile ID from the
        ' packaged return value.
        KVGetValue strReturn, "PROFILEID", mstrWkProfileID
        
        ' Hide and clear the "Working Profiles"
        ' combo box and the "Other Profiles" list.
        ' then clear it.
        With cboWorkingProfile
            .Visible = False
            .Clear
        End With  ' cboWorkingProfile
        
        With lvwOtherProfiles
            .Visible = False
            
            If (Not (.ListItems Is Nothing)) Then
                .ListItems.Clear
            End If
        End With  ' lvwOtherProfiles
        
        ' Clear the description member for now.
        mstrWkProfileDesc = ""
        
        ' Ignore errors before setting up the
        ' profiles again.
        Err.Clear
        
        ' Set up the profiles again (and uncheck the
        ' "Other Profiles" list), then set up
        ' customizations based on the working
        ' profile ID (if any) returned from the UI.
        SetupProfiles
        Err.Clear  ' ignore any errors raised (FOR NOW)
        UncheckOtherProfiles
        ShowProfileCustomizations  ' CALLS EnableWPDependentParts
        
        ' Show the "Working Profiles" combo box (and
        ' set focus on it) and the "Other Profiles"
        ' list again.
        With cboWorkingProfile
            .Visible = True
            .SetFocus
        End With  'cboWorkingProfile
        
        lvwOtherProfiles.Visible = True
    End If
    
    ' Re-enable the button.
    cmdNewProfile.Enabled = True
    
    Err.Clear
End Sub

Private Sub cmdOK_Click()
On Error Resume Next
    ' NOTE: We don't JUST call SaveCustomizations as
    '       its "select a working profile" message
    '       (if there's no working profile) would
    '       mislead the admin.  In this case, we
    '       would STILL close the dialog.  Thus,
    '       (s)he would NOT get to select one.
    ' NOTE: Do we STILL get to the "no working
    '       profile" case here, as the caller
    '       doesn't even pop the dialog box upon a
    '       setup failure?
    If (mstrWkProfileID = "") Or (mstrWkProfileID = vbNullString) Then
        ' Inform the admin with a WARNING message
        ' that the dialog will close without saving
        ' customizations due to no working profile.
        MsgBox mstrCBNoSaveForOKMsg, _
            ACCPACWarnMBStyle, mstrACCPACWarnMBCap, _
            mstrHelpFile, HCIDCBNoSaveForOK
    Else
        ' Save the customizations.
        SaveCustomizations
    End If
    
    ' NOW, close the dialog box.
    Unload Me
    Err.Clear
End Sub

Private Sub cmdSave_Click()
On Error Resume Next
    ' Save the customizations themselves.
    SaveCustomizations
    
    ' (DON'T SHOW/HIDE ANYTHING ON THE UI: IT SHOULD
    '  BE SYNCHRONIZED INSIDE tvwShow_NodeCheck())
    ' (DON'T UNCHECK THE "ADDITIONAL PROFILES")
    ' (DON'T CHANGE THE WORKING PROFILE)
    ' (DON'T CHANGE THE TREEVIEW'S CHECKBOXES)
    
    ' Set the focus to the "Working Profile" box.
    If Me.Visible = True Then
        cboWorkingProfile.SetFocus
    End If
    
    Err.Clear
End Sub

' This happens at "<form>.Show vbModal" but right
' before the "GotFocus" event.
Private Sub Form_Activate()
On Error Resume Next
    ' Set the focus to the "Working Profile" box.
    If Me.Visible = True Then
        cboWorkingProfile.SetFocus
    End If
    
    Err.Clear
End Sub

' NO NEED FOR ERROR HANDLING!
Private Sub Form_Initialize()
    ' Set object members to Nothing.
    ClearMemberObjs
    
    ' Set other members to defaults.
    mstrHelpFile = App.HelpFile
    mstrACCPACErrMBCap = ""
    mstrACCPACWarnMBCap = ""
    mstrCBDlgCap = ""
    mstrCBDlgIdent = ""
    mstrCBNoSaveForOKMsg = ""
    mstrCBSetupFormFailMsg = ""
    mstrWkProfileID = ""
    mstrWkProfileDesc = ""
End Sub

' NOTE: "Visible" will ALWAYS be False here, BUT
'       we can set "Enabled" here.
Private Sub Form_Load()
On Error Resume Next
    ' Set the dialog box's properties.
    With Me
        .Caption = ""
        .Enabled = True
        .HelpContextID = HCIDCBDlg
        .ScaleMode = vbTwips
    End With  ' Me
    
    ' Set the displayed captions/text.
    lblDescription.Caption = ""
    lblOtherProfiles.Caption = ""
    lblShow.Caption = ""
    lblWorking.Caption = ""
    txtWPDesc.Text = ""
    
    ' Set the "Working Profiles" box properties (and
    ' clear it).
    With cboWorkingProfile
        ' Set its properties.
        .Enabled = False  ' disabled until setup's done
        .HelpContextID = HCIDCBCboWorkingProfile
        
        ' Make sure it's clear.
        .Clear
    End With  ' cboWorkingProfile
    
    ' Set the "New Profile" button's properties.
    With cmdNewProfile
        .Cancel = False  ' NOT mapped to [Esc]
        .Default = False  ' NOT mapped to [Enter]
        .Enabled = False  ' disabled until setup's done
        .HelpContextID = HCIDCBCmdNewProfile
        Set .Picture = Nothing  ' no picture
    End With  ' cmdNewProfile
    
    ' Set the profile description's help context ID
    ' (other properties are set at design time).
    txtWPDesc.HelpContextID = HCIDCBTxtWPDesc
    
    ' Set the "OK" button's properties.
    With cmdOK
        .Cancel = False  ' NOT mapped to [Esc]
        .Caption = ""
        .Default = True  ' MAPPED TO [Enter]
        .Enabled = False  ' working profile-dependent
        .HelpContextID = HCIDCBCmdOK
    End With  ' cmdOK
    
    ' Set the "Cancel" button's properties.
    With cmdCancel
        .Cancel = True  ' MAPPED TO [Esc]
        .Caption = ""
        .Default = False  ' NOT mapped to [Enter]
        .Enabled = True
        .HelpContextID = HCIDCBCmdCancel
    End With  ' cmdCancel
    
    ' Set the "Save" button's properties.
    With cmdSave
        .Cancel = False  ' NOT mapped to [Esc]
        .Caption = ""
        .Default = False  ' NOT mapped to [Enter]
        .Enabled = False  ' working profile-dependent
        .HelpContextID = HCIDCBCmdSave
    End With  ' cmdSave
    
    ' Set the "Other Profiles" box properties (and
    ' clear it).
    With lvwOtherProfiles
        ' Set its properties
        .Checkboxes = True
        .ColumnHeaders(CBOthProfilesPIDKey).Width = _
                               CBOthProfilesColWidth
        .Enabled = False  ' working profile-dependent
        .FullRowSelect = False
        .GridLines = False
        .HelpContextID = HCIDCBLvwOtherProfiles
        .HideColumnHeaders = True
        .HideSelection = False
        .LabelEdit = lvwManual
        .Sorted = True
        .View = lvwReport
        
        ' Make sure it's clear
        If (Not (.ListItems Is Nothing)) Then
            .ListItems.Clear
        End If
    End With  ' lvwOtherProfiles
    
    ' Set the "Show Controls" box properties (and
    ' clear it).
    With tvwShow
        ' Set its properties
        .Checkboxes = True
        .Enabled = False  ' working profile-dependent
        .FullRowSelect = False
        .HelpContextID = HCIDCBTvwShow
        .HideSelection = True
        .LabelEdit = tvwManual
        .LineStyle = tvwRootLines
        .Scroll = True
        .Sorted = False
        .Style = tvwTextOnly
        
        ' Make sure it's clear
        If (Not (.Nodes Is Nothing)) Then
            .Nodes.Clear
        End If
    End With  ' tvwShow
    
    Err.Clear
End Sub

Private Sub Form_Terminate()
On Error Resume Next
    ' Make sure that member objects are destroyed.
    ClearMemberObjs
    
    Err.Clear
End Sub

' This happens BEFORE the caller (i.e. the UI's
' CustomizeBox sub) gets the working profile ID
' from the WorkingProfileID property (even though
' the "get" happens between "<form>.Show vbModal"
' and "Unload <form>").
Private Sub Form_Unload(Cancel As Integer)
On Error Resume Next
    ' Hide the controls that need clearing (hide
    ' them for repaint efficiency), then clear them.
    With cboWorkingProfile
        .Visible = False
        .Clear
    End With  ' cboWorkingProfile
    
    With tvwShow
        .Visible = False
        
        If (Not (.Nodes Is Nothing)) Then
            .Nodes.Clear
        End If
    End With  ' tvwShow
    
    With lvwOtherProfiles
        .Visible = False
        
        If (Not (.ListItems Is Nothing)) Then
            .ListItems.Clear
        End If
    End With  ' lvwOtherProfiles
    
    ' Destroy member objects (includes closing the
    ' customize-specific read-write system DB link).
    ClearMemberObjs
    
    ' DO NOT reset the working profile information
    ' (as the "Get" is done AFTER this sub, even
    ' though it's before "Unload" in the caller).
    
    Err.Clear
End Sub

Private Sub tvwShow_NodeCheck(ByVal Node As MSComctlLib.Node)
On Error Resume Next
    If (Not (Node Is Nothing)) And (Not (mCustCtls Is Nothing)) Then
        With Node
            Dim cSelCtl As ACCPACCustCtl
            Set cSelCtl = mCustCtls(.Tag)  ' node tag has control name
            
            If (Not (cSelCtl Is Nothing)) Then
                If .Checked = True Then
                    ' Enable/show the corresponding
                    ' control temporarily.
                    With cSelCtl
                        .EnabledFlag = True
                        .VisibleFlag = True
                    End With  ' cSelCtl
                Else
                    ' Hide/disable the corresponding
                    ' control temporarily.
                    With cSelCtl
                        .VisibleFlag = False
                        .EnabledFlag = False
                    End With  ' cSelCtl
                End If  ' .Checked = True
            End If  ' (Not (cSelCtl Is Nothing))
        End With  ' Node
    End If
    
    Err.Clear
End Sub


'---------------------------------------------------
' Form Setup Functions/Subs
'---------------------------------------------------

' This function MUST be called from within the UI
' project BEFORE "<form>.Show vbModal", but AFTER
' "Load <form>".  (If called this way, this function
' will go AFTER Form_Load and BEFORE Form_Activate.)
' "<form>.Show" should ONLY happen if this function
' returns "True" (i.e. setup was successful).
' NOTE: "Visible" will ALWAYS be False here, BUT
'       we can set "Enabled" here.
Friend Function SetupForm( _
        ByRef CustomCtls As ACCPACCustCtls, _
        ByRef CustomSession As AccpacSession, _
        ByRef objUICtrl As Object, _
        ByVal IResTmpl As IResources, _
        ByVal strWorkingProfileID As String) _
        As Boolean
On Error GoTo SetupFormHandler
    Dim bResSetup As Boolean
    
    ' Set the dialog's resource object member to
    ' the corresponding passed-in argument.
    Set mIResTmpl = IResTmpl
    
    ' Get the localized resources.
    bResSetup = SetResources
    If bResSetup = False Then
        ' We couldn't get the localized resources,
        ' so destroy all member objects.
        ClearMemberObjs
        
        ' Clear the working profile information (a
        ' failed setup means there's no working
        ' profile anymore).
        mstrWkProfileID = ""
        mstrWkProfileDesc = ""
        
        ' Unload the form (ASSUME this function was
        ' called AFTER "Load <form>"), indicate that
        ' setup failed, then GET OUT of this
        ' function.
        Unload Me
        SetupForm = False
        Exit Function
    End If
    
    ' IF WE GOT TO HERE, WE MANAGED TO GET LOCALIZED
    ' RESOURCES.
    
    ' Apply any language-specific layout changes.
    ApplyLangLayout
    
    ' Set some other of the dialog's private members
    ' to the rest of the passed-in arguments.
    Set mCustCtls = CustomCtls
    Set mCustSession = CustomSession
    Set mobjUICtrl = objUICtrl
    mstrWkProfileID = strWorkingProfileID
    
    ' Open a read-write system DB link from the
    ' session, as we need to save changes to the
    ' system DB (and most UIs only have a company
    ' link).
    If (Not (mCustSession Is Nothing)) Then
        Set mCustDBLinkSysRW = mCustSession.OpenDBLink( _
                DBLINK_SYSTEM, DBLINK_FLG_READWRITE)
    End If
    
    ' Initialize the profiles displays (WHICH WILL
    ' SET mstrWkProfileID TO "" IF THE PASSED IN
    ' PROFILE ID DOESN'T EXIST) and the "Show
    ' Controls" box.
    SetupProfiles
    SetupShowControlsBox
    
    ' If there's a (passed-in) working profile, show
    ' its customizations and enable the working
    ' profile-dependent parts of the dialog.
    ' (Otherwise, ShowProfileCustomizations will
    ' disable part of the dialog and tell the admin
    ' to select a working profile.)
    ShowProfileCustomizations
    
    ' Now that we've set everything up, enable the
    ' previously disabled NON working profile-
    ' dependent controls.
    cboWorkingProfile.Enabled = True
    
    With cmdNewProfile
        If ACCPACProgramName = "AS8001" Then
            ' Since the "UI Profile Maintenance" UI
            ' is the one calling us, hide the "new"
            ' button so another instance of that UI
            ' won't be opened by us.
            .Enabled = False
            .Visible = False
        Else
            ' NOTE: The control will be visible
            '       later.
            .Enabled = True
        End If
    End With  ' cmdNewProfile
    
    ' Indicate that setup was successful.
    SetupForm = True
    Err.Clear  ' in case of uncleared errors raised by objects
Exit Function

SetupFormHandler:
    With Err
        ' Print a debug message (for programmers).
        Debug.Print """Customize"" box's SetupForm " _
            & "failed due to Error #" & _
            CStr(.Number) & " -" & vbCrLf & _
            "  Err.Source = " & .Source & vbCrLf & _
            "  Err.Description = " & .Description
    End With  ' Err
    
    ' Use an ERROR message to tell the admin that
    ' setup failed (so (s)he won't be surprised).
    ' NOTE: The MsgBox call clears the Err object.
    MsgBox mstrCBSetupFormFailMsg, ACCPACErrMBStyle, _
        mstrACCPACErrMBCap, mstrHelpFile, _
        HCIDCBSetupFormFail
    
    ' Destroy member objects.
    ClearMemberObjs
    
    ' Clear the working profile information (as a
    ' failed setup means there's no working profile,
    ' even if a saved one was passed in).
    mstrWkProfileID = ""
    mstrWkProfileDesc = ""
    
    ' Assume <form>.SetupForm is called AFTER "Load
    ' <form>".  Thus, unload the form and indicate
    ' that setup failed.
    Unload Me
    SetupForm = False
    
    Err.Clear
End Function


'---------------------------------------------------
' Friend Properties
'---------------------------------------------------

' (Read-Only)
' The caller (i.e. the UI's CustomizeBox sub) should
' save the "Working Profile" box's state by getting
' this WorkingProfileID after "<form>.Show vbModal"
' but before "Unload <form>".
Friend Property Get WorkingProfileID() As String
On Error Resume Next
    WorkingProfileID = mstrWkProfileID
    Err.Clear
End Property


'---------------------------------------------------
' Private Setup Helpers
'---------------------------------------------------

' This sub applies the language-specific layout
' changes to the "Customize" box.
' NOTE: For the "Customize" box, the layout IDs are
'       "hardcoded", so we don't have to find them.
Private Sub ApplyLangLayout()
On Error Resume Next
    With Me
        Dim sHeight As Single
        Dim sWidth As Single
        Dim bDlgSizeChanged As Boolean
        
        ' Change the "Customize" box's size if need
        ' be.  (The size variables have to be set
        ' initially to the current ScaleHeight and
        ' ScaleWidth.  They will then be set to the
        ' new ScaleHeight/ScaleWidth.)
        sHeight = .ScaleHeight
        sWidth = .ScaleWidth
        
        bDlgSizeChanged = GetNewFormSize(mIResTmpl, _
            IDD_CBDlgSizeInfo, sHeight, sWidth)
        If bDlgSizeChanged = True Then
            .Height = .Height + (sHeight - .ScaleHeight)
            .Width = .Width + (sWidth - .ScaleWidth)
        End If
    End With  ' Me
    
    ' NOTE: It's OK if the "Customize" box's size
    '       didn't change.
    
    ' Change constituent control layouts (if
    ' necessary).  We don't need to know whether or
    ' not the layout has changed.
    ApplyNewCtlLayout mIResTmpl, Controls, _
                      IDD_CBCtlLayoutInfo
    
    ' Apply the new font (if necessary) to the form
    ' and to all its constituent controls.
    ' NOTE: According to KB article Q206907, the
    '       font should be changed AFTER resizing.
    ApplyNewFont mIResTmpl, Me
    
    Err.Clear
End Sub

' This function should ONLY be called by SetupForm.
' If the localized resource object exists, the
' resources are retrieved and this function returns
' True (to indicate success).  Otherwise, it returns
' False (to indicate failure).
Private Function SetResources() As Boolean
On Error Resume Next
    If mIResTmpl Is Nothing Then
        ' We don't have a resource object, so inform
        ' the user (in ENGLISH).
        ' NOTE: UI PROGRAMMERS MUST USE
        '       mstrACCPACErrMBCap INSTEAD OF
        '       ACCPACErrMBCap.
        MsgBox CBNoLocResourcesMsg, _
            ACCPACErrMBStyle, ACCPACErrMBCap, _
            mstrHelpFile, HCIDNoLocResources
            
        ' Indicate that we failed to get resources.
        SetResources = False
    Else
        ' Grab the resources.
        With mIResTmpl
            ' Set message box caption members.
            mstrACCPACErrMBCap = _
                .GetResString(IDS_ACCPACErrMBCap)
            mstrACCPACWarnMBCap = _
                .GetResString(IDS_ACCPACWarnMBCap)
                
            ' Set the dialog caption, THEN its
            ' identifier (depends on caption).
            mstrCBDlgCap = _
                .GetResString(IDS_CBDlgCap)
            mstrCBDlgIdent = _
                .GetResString(IDS_CBLStrDlgIdent) & _
                mstrCBDlgCap & _
                .GetResString(IDS_CBRStrDlgIdent)
                
            ' Set other message string members (some
            ' depend on the dialog identifier).
            mstrCBSetupFormFailMsg = _
                mstrCBDlgIdent & vbCrLf & vbCrLf & _
                .GetResString(IDS_CBSetupFormFailTxt)
            mstrCBNoSaveForOKMsg = _
                mstrCBDlgIdent & vbCrLf & vbCrLf & _
                .GetResString(IDS_CBNoSaveForOKTxt)
                
            ' Set the captions.
            Me.Caption = mstrCBDlgCap
            lblDescription.Caption = _
                .GetResString(IDS_CBLblDescriptionCap)
            lblOtherProfiles.Caption = _
                .GetResString(IDS_CBLblOtherProfilesCap)
            lblShow.Caption = _
                .GetResString(IDS_CBLblShowCap)
            lblWorking.Caption = _
                .GetResString(IDS_CBLblWorkingCap)
            cmdOK.Caption = _
                .GetResString(IDS_CBCmdOKCap)
            cmdCancel.Caption = _
                .GetResString(IDS_CBCmdCancelCap)
            cmdSave.Caption = _
                .GetResString(IDS_CBCmdSaveCap)
            
            ' Set the "New Profile" button bitmap.
            cmdNewProfile.Picture = _
                .GetResPicture(IDB_CBCmdNewProfile, _
                               vbResBitmap)
        End With  ' mIResTmpl
        
        ' Indicate that we managed to get resources.
        SetResources = True
    End If
    
    Err.Clear
End Function

' This sub should ONLY be called by SetupForm.  It
' sets up the "Show Controls" box (i.e. the box
' showing the names and captions of each of the UI's
' customizable controls).  It DOESN'T figure out
' what the working profile is (if there's any), so
' it DOESN'T show its customizations (i.e. it DOES
' NOT check the checkboxes).  Errors should be
' PASSED BACK TO SetupForm.
' NOTE: "Visible" will ALWAYS be False here, BUT
'       we can set "Enabled" here.
Private Sub SetupShowControlsBox()
    Dim tvwNodes As Nodes
    Set tvwNodes = tvwShow.Nodes
    
    If (Not (tvwNodes Is Nothing)) And (Not (mCustCtls Is Nothing)) Then
        ' Add items (each represents a customizable
        ' control) to the "Show Controls" box.
        Dim cCtl As ACCPACCustCtl
        For Each cCtl In mCustCtls
            If (Not (cCtl Is Nothing)) Then
                With cCtl
                    Dim ndNewItem As Node
                    Dim cCtlName As String
                    Dim cCtlCaption As String
                    Dim strItemText As String
                    
                    ' We should raise an error if we
                    ' can't get the name (errors
                    ' need EXPLICIT re-raising to
                    ' get to SetupForm's handler).
                    cCtlName = .Name
                    With Err
                        If .Number <> 0 Then
                            .Raise .Number, .Source, _
                                .Description, _
                                .HelpFile, _
                                .HelpContext
                        End If
                    End With  ' Err
                    
                    ' Get the caption if it exists
                    ' (errors won't be automatically
                    ' re-raised, so we can handle
                    ' them HERE).
                    cCtlCaption = .Caption
                    If Err.Number <> 0 Then
                        cCtlCaption = ""  ' default caption
                        Err.Clear  ' handled error
                    End If
                    
                    ' Build and add the item.
                    strItemText = "[" & cCtlName & _
                        "]    """ & cCtlCaption & _
                        """"
                    Set ndNewItem = tvwNodes.Add(, , _
                                      , strItemText)
                
                    ' Save the control's name in the
                    ' item's tag.
                    If (Not (ndNewItem Is Nothing)) Then
                        ndNewItem.Tag = cCtlName
                    End If
                End With  ' cCtl
            End If
        Next cCtl
    End If
End Sub


'---------------------------------------------------
' Other Private Helpers
'---------------------------------------------------

' This sub sets up the "Working Profiles" and
' "Other Profiles" boxes, as well as the
' "Description" (label) of the working profile.  It
' also sets the working profile member variables.
' MOST errors should be PASSED BACK TO the caller
' (SetupForm will fail, while cmdNewProfile_Click
' will ignore the errors).
' NOTE: This sub does NOT determine whether or not
'       to disable part of the dialog (and display
'       the "no working profile" message box).
' NOTE: cmdNewProfile_Click should HIDE and CLEAR
'       the "Working Profiles" AND "Other Profiles"
'       boxes BEFORE calling this sub.  It also has
'       to SHOW the boxes AFTER calling this sub.
Private Sub SetupProfiles()
    Dim lvwItems As ListItems
    Set lvwItems = lvwOtherProfiles.ListItems
    
    If (Not (lvwItems Is Nothing)) And (Not (mCustDBLinkSysRW Is Nothing)) Then
        Dim strArrProfileIDs() As String
        Dim strArrProfileDescs() As String
        
        ' Try to get the list of profiles (into the
        ' two arrays being passed in BY REF).
        mCustDBLinkSysRW.GetProfiles strArrProfileIDs, _
                                     strArrProfileDescs

' Change error handlers so we can handle errors from
' trying to get the bounds of empty arrays (which we
' may get if there are NO profiles).  Unlike other
' errors, this case should NOT cause setup to fail.
On Error Resume Next
        ' NOTE: GetProfiles GUARANTEES that the
        '       ProfileIDs and ProfileDescs arrays
        '       will be the SAME SIZE, so ASSUME
        '       that both arrays' bounds will be
        '       those of the ProfileIDs array.
        Dim lPIDsLBound As Long
        Dim lPIDsUBound As Long
        
        lPIDsLBound = LBound(strArrProfileIDs)
        lPIDsUBound = UBound(strArrProfileIDs)
        
        If Err.Number <> 0 Then
            ' We don't have to add anything to the
            ' profiles boxes.  Just clear the error.
            Err.Clear
            
' Now that the error's cleared, send new errors back
' to the caller.
On Error GoTo 0
        Else
' Send new errors back to the caller.
On Error GoTo 0
            ' Add EACH profile to BOTH the "Working
            ' Profiles" box AND to the "Other
            ' Profiles" box (description as tag).
            ' NOTE: DON'T look for/set the working
            '       profile as it's added to the
            '       "Working Profiles" box because
            '       its ListIndex may shift since
            '       this box is still being SORTED.
            Dim i As Long
            For i = lPIDsLBound To lPIDsUBound
                Dim strProfileID As String
                strProfileID = strArrProfileIDs(i)
                
                cboWorkingProfile.AddItem strProfileID
                
                Dim lsItem As ListItem
                Set lsItem = lvwItems.Add(, , _
                                       strProfileID)
                If (Not (lsItem Is Nothing)) Then
                    lsItem.Tag = _
                            strArrProfileDescs(i)
                End If
            Next i
        End If
        
        ' Look for the passed-in working profile in
        ' the "Other Profiles" list (it hasn't been
        ' removed yet).  If no profile was passed in
        ' we will look for "", which will result in
        ' the profile NOT being found.
        Dim lsHiddenItem As ListItem
        Set lsHiddenItem = _
            lvwOtherProfiles.FindItem( _
                           mstrWkProfileID, lvwText)
        If lsHiddenItem Is Nothing Then
            ' NO working profile was found, so make
            ' sure that the working profile members,
            ' the "Working Profiles" box, and the
            ' description reflect this fact.
            mstrWkProfileID = ""
            mstrWkProfileDesc = ""
            
            cboWorkingProfile.ListIndex = -1
            txtWPDesc.Text = mstrWkProfileDesc
        Else
            ' We found the working profile (i.e.
            ' mstrWkProfileID is correct).
            With lsHiddenItem
                ' Set the description member.
                mstrWkProfileDesc = .Tag
                    
                ' NOW, remove ("hide") the profile.
                Dim cutIdx As Integer
                cutIdx = .Index
                lvwItems.Remove cutIdx
            End With  ' lsHiddenItem
            
            ' Display the description.
            txtWPDesc.Text = mstrWkProfileDesc
                    
            With cboWorkingProfile
                ' Get the "Working Profiles" box to
                ' show the (passed-in) working
                ' profile.
                Dim idx As Integer
                For idx = 0 To (.ListCount - 1)
                    If (.List(idx) = mstrWkProfileID) Then
                        .ListIndex = idx
                        Exit For  ' don't keep looking
                    End If
                Next idx
            End With  ' cboWorkingProfile
        End If  ' lsHiddenItem Is Nothing
    End If  ' (Not (lvwItems Is Nothing)) And (Not (mCustDBLinkSysRW Is Nothing))
End Sub

' This sub saves the customizations for the selected
' profile (and any other profile).
Private Sub SaveCustomizations()
On Error GoTo SaveCustomizationsHandler
    Dim lvwItems As ListItems
    Dim tvwNodes As Nodes
    
    Set lvwItems = lvwOtherProfiles.ListItems
    Set tvwNodes = tvwShow.Nodes
    
    If (mstrWkProfileID = "") Or (mstrWkProfileID = vbNullString) Then
        ' There's no working profile selected, so
        ' disable part of the dialog (until a
        ' working profile is selected).
        EnableWPDependentParts False
    ElseIf (Not (lvwItems Is Nothing)) _
      And (Not (tvwNodes Is Nothing)) _
      And (Not (mCustDBLinkSysRW Is Nothing)) _
      And (Not (mCustSession Is Nothing)) _
      Then
        ' NOTE: In building the string arrays, I
        '       chose to build a string and then
        '       split it.  This saves us from
        '       ReDim-ing the array or looping
        '       through collections a second time to
        '       get counts.
        
        ' Build the array of profiles that will be
        ' saving the current customizations.
        Dim strChosenProfileIDs As String
        strChosenProfileIDs = mstrWkProfileID
        
        Dim lsItem As ListItem
        For Each lsItem In lvwItems
            If (Not (lsItem Is Nothing)) Then
                With lsItem
                    ' Chosen profile items ARE
                    ' checked.
                    If .Checked = True Then
                        strChosenProfileIDs = _
                            strChosenProfileIDs & _
                            "," & .Text
                    End If
                End With  ' lsItem
            End If
        Next lsItem
        
        Dim strArrChProfileIDs() As String
        strArrChProfileIDs = Split( _
                           strChosenProfileIDs, ",")
        
        ' Build the array of hidden controls.
        Dim strHiddenCtls As String
        strHiddenCtls = ""
        
        Dim ndItem As Node
        For Each ndItem In tvwNodes
            If (Not (ndItem Is Nothing)) Then
                With ndItem
                    ' Hidden controls go with items
                    ' that AREN'T checked (control
                    ' NAME is stored in tag).
                    If .Checked = False Then
                        strHiddenCtls = _
                            strHiddenCtls & "," & _
                            .Tag
                    End If
                End With  ' ndItem
            End If
        Next ndItem
        
        ' Trim the first "," off of the string (if
        ' it has at least one item).
        Dim lHCTrimmedLen As Long
        lHCTrimmedLen = Len(strHiddenCtls) - 1  ' to trim ","
        
        ' If the string was empty, DON'T trim it (we
        ' MUST pass a NON-NEGATIVE trim length to
        ' "Right").
        If lHCTrimmedLen < 0 Then
            lHCTrimmedLen = 0
        End If
        
        ' NOTE: DON'T use CStr (as control names are
        '       in ENGLISH and we DON'T want
        '       automatic translation).
        strHiddenCtls = Right(strHiddenCtls, _
                              lHCTrimmedLen)
        
        Dim strArrHidnCtls() As String
        strArrHidnCtls = Split(strHiddenCtls, ",")
                    
        ' Save our updated customization choices.
        ' (The changes are saved to the master copy
        ' in the system DB, then propagated to the
        ' copies in the associated company DBs.)
        ' Then, show any resulting messages (i.e.
        ' "incomplete propagation" warnings.)
        mCustDBLinkSysRW.SaveProfileCustomizations _
                    strArrChProfileIDs, ACCPACUIKey, _
                    strArrHidnCtls
        StdACCPACErrorHandler mobjUICtrl, _
            mCustSession, mIResTmpl, False, True
        
        ' Since there's a working profile, make sure
        ' that we show the whole dialog.
        EnableWPDependentParts True
    End If
    
    Err.Clear  ' in case of uncleared errors raised by objects
Exit Sub

SaveCustomizationsHandler:
    ' Display (and clear) the error, then go on.
    StdACCPACErrorHandler mobjUICtrl, mCustSession, _
        mIResTmpl, True, True
    Resume Next
End Sub

' This sub shows a profile's (previously saved)
' customizations BOTH on the "Show Controls" box
' (by (un)checking boxes) AND on the UI control (by
' hiding/showing constituent controls).  IT IS ALSO
' RESPONSIBLE FOR MAKING SURE THAT THE WHOLE DIALOG
' IS ENABLED IF A WORKING PROFILE EXISTS AND FOR
' DISABLING PART OF THE DIALOG (AND CHECKING ALL
' BOXES) IF IT DOESN'T.
Private Sub ShowProfileCustomizations()
On Error Resume Next
    Dim tvwNodes As Nodes
    Dim ndItem As Node
    Dim bOrigVisible As Boolean
    
    With tvwShow
        Set tvwNodes = .Nodes
        bOrigVisible = .Visible
    End With  ' tvwShow
    
    If (tvwNodes Is Nothing) _
      Or (mCustCtls Is Nothing) _
      Or (mCustDBLinkSysRW Is Nothing) _
      Or (mCustSession Is Nothing) _
      Then
        ' We don't have the needed objects to go on,
        ' so disable part of the dialog and GET OUT
        ' of this sub (after CLEARING errors).
        EnableWPDependentParts False
        Set tvwNodes = Nothing  ' to be sure
        Err.Clear
        Exit Sub
    End If
    
    ' IF WE GOT TO HERE, THE NEEDED OBJECTS EXIST.
    
    ' Hide the "Show Controls" box temporarily
    ' (if it's visible) for repaint efficiency.
    If (bOrigVisible = True) Then
        tvwShow.Visible = False
    End If
    
    ' Reset the state of the customizable UI
    ' controls by "showing" them all (at first).
    Dim cCtl As ACCPACCustCtl
    For Each cCtl In mCustCtls
        If (Not (cCtl Is Nothing)) Then
            With cCtl
                If (.VisibleFlag = False) Or (.EnabledFlag = False) Then
                    .EnabledFlag = True
                    .VisibleFlag = True
                End If
            End With  ' cCtl
        End If
    Next cCtl
    
    ' Ignore errors caused by trying to enable
    ' and show all of the customizable controls.
    Err.Clear
    
    ' ONLY proceed if we HAVE a working profile (and
    ' if the collections/objects exist).
    If (mstrWkProfileID = "") Or (mstrWkProfileID = vbNullString) Then
        ' Since there's NO working profile, check
        ' all of the "Show Controls" items.
        For Each ndItem In tvwNodes
            If (Not (ndItem Is Nothing)) Then
                ndItem.Checked = True
            End If
        Next ndItem
        
        ' Disable part of the dialog (until a
        ' working profile is selected).
        EnableWPDependentParts False
    Else
        ' Get the profile's customizations.
        Dim strArrHiddenCtls() As String
        strArrHiddenCtls = _
            mCustDBLinkSysRW.GetProfileCustomizations( _
                       mstrWkProfileID, ACCPACUIKey)
        
        ' Display/CLEAR any errors (but keep going).
        If Err.Number <> 0 Then
            StdACCPACErrorHandler mobjUICtrl, _
                mCustSession, mIResTmpl, True, True
        End If
        
        ' Save the hidden controls array's bounds.
        Dim lHCtlsLBound As Long
        Dim lHCtlsUBound As Long
        
        lHCtlsLBound = LBound(strArrHiddenCtls)
        lHCtlsUBound = UBound(strArrHiddenCtls)
        
        If Err.Number = 0 Then
            ' There ARE hidden controls.  Go through
            ' each "Show Control" item: check it
            ' until you find that it's a hidden
            ' control (in which case, uncheck the
            ' item and hide the control).
            ' NOTE: (Un)checking items in code does
            '       NOT raise the NodeChecked event.
            For Each ndItem In tvwNodes
                If (Not (ndItem Is Nothing)) Then
                    With ndItem
                        Dim ndCtlName As String
                        Dim i As Long
                        ndCtlName = .Tag
                        
                        ' Check it until told otherwise.
                        .Checked = True
                        
                        For i = lHCtlsLBound To lHCtlsUBound
                            Dim strHCtlName As String
                            strHCtlName = strArrHiddenCtls(i)
                            
                            If strHCtlName = ndCtlName Then
                                .Checked = False
                                
                                ' Hide/disable the control too.
                                Dim cHCtl As ACCPACCustCtl
                                Set cHCtl = mCustCtls(ndCtlName)
                                If (Not (cHCtl Is Nothing)) Then
                                    With cHCtl
                                        .VisibleFlag = False
                                        .EnabledFlag = False
                                    End With  ' cHCtl
                                End If
                                
                                ' We matched a string: no need to check the rest.
                                Exit For
                            End If
                        Next i
                    End With  ' ndItem
                End If
            Next ndItem
        Else
            ' We won't be able to access the array
            ' of hidden controls as we can't get its
            ' bounds.  This could be because THERE
            ' ARE NO HIDDEN CONTROLS (or an error
            ' occurred in trying to get this array).
            ' Thus, we just go through the "Show
            ' Controls" box and check all its items.
            For Each ndItem In tvwNodes
                If (Not (ndItem Is Nothing)) Then
                    ndItem.Checked = True
                End If
            Next ndItem
        End If
        
        ' Since we have a working profile, enable
        ' the whole dialog.
        EnableWPDependentParts True
    End If
    
    ' Show the "Show Controls" box if it was shown
    ' originally.
    If bOrigVisible = True Then
        tvwShow.Visible = True
    End If  ' bOrigVisible = True
    
    Err.Clear
End Sub

' This sub clears all of the checkmarks in the
' "Other Profiles" box.  It should be done whenever
' the working profile changes (including when a new
' working profile is added successfully).
Private Sub UncheckOtherProfiles()
On Error Resume Next
    Dim lvwItems As ListItems
    Set lvwItems = lvwOtherProfiles.ListItems
    
    If (Not (lvwItems Is Nothing)) Then
        Dim bOrigVisible As Boolean
        bOrigVisible = lvwOtherProfiles.Visible
        
        ' Hide the "Other Profiles" box temporarily
        ' (if it's visible) for repaint efficiency.
        If bOrigVisible = True Then
            lvwOtherProfiles.Visible = False
        End If
        
        ' Uncheck all of the "Other Profiles" items.
        Dim lsItem As ListItem
        For Each lsItem In lvwItems
            If (Not (lsItem Is Nothing)) Then
                lsItem.Checked = False
            End If
        Next lsItem
        
        ' Show the "Other Profiles" box if it was
        ' originally shown.
        If bOrigVisible = True Then
            lvwOtherProfiles.Visible = True
        End If  ' bOrigVisible = True
    End If  ' Not (lvwItems Is Nothing)
    
    Err.Clear
End Sub

' This sub enables or disables the "Show Controls"
' and "Other Profiles" boxes, as well as the "Save"
' and "OK" buttons, as these are dependent on the
' working profile existing.
Private Sub EnableWPDependentParts(ByVal bEnabled As Boolean)
On Error Resume Next
    ' Enable/disable working-profile dependent parts
    ' of the dialog.
    tvwShow.Enabled = bEnabled
    lvwOtherProfiles.Enabled = bEnabled
    cmdSave.Enabled = bEnabled
    cmdOK.Enabled = bEnabled
    
    Err.Clear
End Sub

' This sub sets all member objects to Nothing.
Private Sub ClearMemberObjs()
On Error Resume Next
    ' Set all member objects to Nothing, closing the
    ' customize-specific read-write system DB link
    ' if needed.
    If (Not (mCustDBLinkSysRW Is Nothing)) Then
        mCustDBLinkSysRW.Close
        Set mCustDBLinkSysRW = Nothing
    End If
    
    Set mCustCtls = Nothing
    Set mCustSession = Nothing
    Set mobjUICtrl = Nothing
    Set mIResTmpl = Nothing
    
    Err.Clear
End Sub
