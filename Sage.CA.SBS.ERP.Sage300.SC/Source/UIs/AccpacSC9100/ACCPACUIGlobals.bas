Attribute VB_Name = "ACCPACUIGlobals"
Attribute VB_Description = "Module of global constants and functions that differ among ACCPAC UI Controls"
' ACCPAC UI DEVELOPERS: DO NOT DELETE ANY STANDARD
'       CONSTANT DECLARATIONS (AND DON'T CHANGE
'       THEIR VARIABLE NAMES), BUT CHANGE THEIR
'       VALUES IF NEEDED.
'
' Module: ACCPACUIGlobals
' Template 5.3A Revision: cycle 1
'
' Description: This module contains some standard
'              constant declarations for an ACCPAC
'              UI Control.  It may also contain any
'              other global (project-wide) things,
'              like constants or DLL entry points,
'              that are specific to the individual
'              UI.  The English <RotoID>.rc file's
'              resource string 101 should match the
'              ACCPACUIName constant's value.
'
' NOTE: Replace the YYYY below with the latest year
'       in which your UI was developed.
'
' Copyright 1999-YYYY ACCPAC International, Inc.
'   All rights reserved.
'

Option Compare Text
Option Explicit

'---------------------------------------------------
' Standard UI-Specific Globals
'---------------------------------------------------

' Default string constant USED ONLY WHEN LOCALIZED
' RESOURCES CAN'T BE CREATED: VALUE MAY NEED
' MODIFICATION (HERE **AND** IN <RotoID>.rc)
Public Const ACCPACUIName As String = _
    "S/C Options"
    ' <PUT THE UI'S DEFAULT (ENGLISH) DISPLAY NAME
    '  IN THE STRING ABOVE.  PLACE THE SAME DISPLAY
    '  NAME IN RESOURCE STRING 101 IN <RotoID>.rc.
    '  USE THE SAMPLE RC FILES TO CREATE A SKELETON
    '  <RotoID>.rc (AS WELL AS <RotoID>ID.h,
    '  <AppID>Client.rc, <AppID>ClientID.h, and
    '  <AppID>Version.rc2).  USE THE SAMPLE MAKEFILE
    '  AS THE BASIS OF YOUR MAKEFILE FOR THOSE
    '  RESOURCES.  TO SEE THE STRINGS FROM THE RC
    '  FILES, THE BUILT UI-SPECIFIC AND APP-WIDE
    '  RESOURCE DLLS NEED TO BE COPIED INTO THE
    '  APPROPRIATE LANGUAGE SUBDIRECTORY UNDER THE
    '  ACCPAC DIRECTORY.>

' Other standard constants: VALUES MAY NEED
' MODIFICATION
Public Const ACCPACUIKey As String = _
    "SCOptions"
    ' <PUT A UNIQUE KEY (USED FOR CUSTOMIZATIONS)
    '  ASSOCIATED WITH THIS UI IN THE STRING ABOVE.
    '  THE KEY IS UP TO 35 ALPHANUMERIC CHARACTERS
    '  AND SHOULD BE THE UI'S DEFAULT DISPLAY NAME,
    '  BUT AS A MIXED-CASE WORD WITHOUT SPACES.>
Public Const ACCPACAppID As String = _
    "SC"
    ' <PUT THIS UI'S AppID IN THE STRING ABOVE.  THE
    '  AppID IS THE ID FOR THE ACCPAC APPLICATION
    '  (MODULE) THAT THIS UI BELONGS TO.>
Public Const ACCPACProgramName As String = _
    "SC9100"
    ' <PUT THIS UI'S ROTO ID (PROGRAM NAME) IN THE
    '  STRING ABOVE.>
Public Const ACCPACAppVersion As String = _
    "63A"
    ' <PUT THIS UI'S APPLICATION VERSION IN THE
    '  STRING ABOVE.  THE VERSION IS THAT OF THE
    '  ACCPAC APPLICATION (MODULE) THAT THIS UI
    '  BELONGS TO.>
Public Const ACCPACUIResizable As Boolean = False
    ' <TO ALLOW USERS TO RESIZE YOUR UI, SET THE
    '  VALUE OF THIS CONSTANT TO True.  FOR
    '  NON-RESIZABLE UI'S, SET THE VALUE TO False.>


'---------------------------------------------------
' UI-Specific Help Context IDs
'---------------------------------------------------

' <PLACE UI-SPECIFIC HELP CONTEXT ID CONSTANTS
'  HERE, OR IN YOUR OWN MODULE(S).>
'
' INSTRUCTIONS:
'   You'll need at least one help ID for the UI, and
' up to one help ID per control/message that you add
' to the UI.  You'll also need help IDs for popup
' forms that you add: at least one per popup form,
' and up to one per control/message that you add.
'
'   Set constituent controls' help context IDs to
' the appropriate constants in "HelpIDsCallout" in
' the UI's (.ctl) code, or in "SetHelpContextIDs"
' in popup forms derived from PFrmDS.frm.  Messages'
' help context IDs are set when the errors are put
' into the session or in the MsgBox calls.
'
' You DON'T need help context ID constants for:
' * Standard ACCPAC UI menu items and constituent
'   controls (i.e. mnuFile_Print, APP_Save_Button),
'   as well as standard (template) messages (i.e.
'   mstrSaveRecordMsg).  Their constants are already
'   set in ACCPACTmplHelpIDs.bas.
' * Data sources and other invisible controls.
' * BrowsePath.frm and RemoteRptSelector.frm.  Each
'   one uses the help context ID of the control
'   that calls it (i.e. the "Browse" button).
'
' EXAMPLES:
'   Public Const HCIDBK1001 As Long = &H123
'   Public Const HCIDBKACCTProfileTAB As Long = &H234
'   Public Const HCIDCmdDoSomething As Long = &H345
'   Public Const HCIDSomeMessage As Long = &H456


'---------------------------------------------------
' Server-Side Resource IDs
'---------------------------------------------------

' <PLACE RESOURCE ID CONSTANTS FOR SERVER-SIDE
'  STRINGS HERE, OR IN YOUR OWN MODULE(S).  THESE
'  CONSTANTS ARE ONLY NEEDED IF THE UI CALLS THE
'  SESSION'S "RscGetString" OR "Errors.PutRscMsg".
'  (THOSE CALLS INCREASE NETWORK TRAFFIC FOR REMOTE
'  UI'S: IT MAY BE BETTER TO MOVE SUCH MESSAGES TO
'  CLIENT-SIDE RC FILES.)>
' NOTE: Define client-side resource ID constants in
'       <RotoID>ID.h or <AppID>ClientID.h.


'---------------------------------------------------
' Other UI-Specific Globals
'---------------------------------------------------

' <PLACE YOUR OWN PROJECT-WIDE GLOBALS HERE, OR IN
'  YOUR OWN MODULE(S).  THIS IS A GOOD PLACE TO PUT
'  FIELD NAME AND SECURITY RESOURCE CONSTANTS, DLL
'  ENTRY POINTS, AND PROJECT-WIDE METHODS.>
Public Const SC_RSC_SCSETUP  As String = "SCSETUP"
Public Const SC_RSC_SCINQUIRY As String = "SCINQUIRY"

