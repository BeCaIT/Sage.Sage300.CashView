#------------------------------------------------------------------
#
# File    :  Makefile
# Purpose :  Makefile template for Client-side DLLs.
#
# Copyright (c) 1994-2016 Sage Software, Inc.  All rights reserved.
#   All rights reserved.
#
# NOTE: For ENG builds, this Makefile should be run before building
#       the OCXs and UI CABs, so that OCXs build with the correct
#       generated BAS modules and UI CABs include the ENG DLLs.
#
#------------------------------------------------------------------

###################################################################
# Change the following macro ("variable") definitions as needed.
# Avoid paths with spaces in them.
#

APPID = SC
APPVER = 63A
DISPLAYVER = 6.3A
BUILDVER = 6,3,0,0
LANG = ENG

!IF !DEFINED(PLUSWDEVPATH)
PLUSWDEVPATH = C:\PLUSWDEV
!ENDIF

BMPPATH = $(PLUSWDEVPATH)\BITMAPS
ICONPATH = $(PLUSWDEVPATH)\ICONS

SRCPATH = C:\Projects\Sage.CA.SBS.ERP.Sage300.SC\Sage.CA.SBS.ERP.Sage300.SC\Source
UIS_PATH = $(SRCPATH)\UIs
UIS_RESPATH = $(UIS_PATH)\RESOURCE
UIS_GENPATH = $(UIS_PATH)\GEN

BUILDPATH = C:\Projects\Sage.CA.SBS.ERP.Sage300.SC\Sage.CA.SBS.ERP.Sage300.SC\Build32
DLL_PATH = $(BUILDPATH)\RUNTIME\$(LANG)
CAB_PATH = $(BUILDPATH)\CABS\$(LANG)

RC = rc -r -d _APP_FILE_VERSION_RES_=\"$(BUILDVER)\" \
        -d _APP_FILE_VERSION_RES2_=$(BUILDVER) \
        -d _APP_PRODUCT_VERSION_RES_=\"$(DISPLAYVER)\" \
        -i$(BMPPATH) \
        -i$(ICONPATH)

LINK = link -dll -heap:0 -machine:IX86 -out:$@ -noentry


###################################################################
# Main Dependencies (don't need changes in most cases)

all: "$(DLL_PATH)\DEP.DAT"

"$(DLL_PATH)\DEP.DAT": AppRes \
                       UIRes \
                       $(LANG)\DEP.TXT
  ccdep $(LANG)\DEP.TXT "$(DLL_PATH)\DEP.DAT"


# APPLANG.MAK contains AppRes (app-wide client-side DLL) build
# instructions and dependencies.  It builds the app-wide CAB and
# client-side DLL.  For ENG builds, it also generates the app-wide
# resource ID BAS module.  APPLANG.MAK may be changed to a custom
# build file.
#
!INCLUDE <APPLANG.MAK>


###################################################################
# Add a dependency for each UI under the "UIRes" line.  Use the
# UI's Roto ID.  Use "\" to separate lines.
# EXAMPLE:
#   UIRes: \
#     BK0000 \
#     BK1000
#

UIRes: \
	SC9100 \


###################################################################
# Add a section for each UI.
# EXAMPLE:
#   ROTOID=BK0000
#   !INCLUDE <UILANG.MAK>
#
# UILANG.MAK contains UI-specific DLL build instructions and
# dependencies.  It builds the UI-specific DLL.  A UI-specific
# resource ID BAS module is also generated for ENG builds only.  A
# CAB file is built for non-ENG builds only.  (CAB files aren't
# built for ENG DLL builds because a UI-specific ENG DLL goes into
# its OCX's UI CAB file.)  UILANG.MAK may be changed to a custom
# build file on a per-UI basis.
#
ROTOID=SC9100
!INCLUDE <UILANG.MAK>


# +++
