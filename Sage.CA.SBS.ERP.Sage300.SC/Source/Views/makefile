#############################################################################
#
#  Makefile for SC views
#
#  Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.
#
#############################################################################



#############################################################################
# Build targeting options

LOPTS = -export:rotoEntry,@1000 -export:identifyEntry,@999

DESCRIPTION = Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.

#LIBLIST = optviews.lib  # to link optional field views
#PCHBASE = sc          # to use precompiled headers

!INCLUDE <ACCPAC.MAK>



#############################################################################
# Targets

# Add a sub-target for each view
all: \
   SCOPT \
	SCACCT \
	SCBAL \
	SCTRAN \
	SCPRO \
	SCLOAN \
	SCSCHDL \
	SCINIT \

# Add a sub-target for each view's inclusions
includes: \
   common \
   iSCOPT \
	iSCACCT \
	iSCBAL \
	iSCTRAN \
	iSCPRO \
	iSCLOAN \
	iSCSCHDL \
	iSCINIT \

# This is intended as a common sub-target used by all the views for
# inclusions shared by all views.
iSC: common $(PCHFILE)

common: \
   $(INCPATH)\sc.h \
   $(INCPATH)\sc.i \
   $(INCPATH)\scerr.i \
   $(INCPATH)\scdp.i \



#############################################################################
# Makefiles

# Add an inclusion for each view's makefile
!INCLUDE scOpt.mak
!INCLUDE scAcct.mak
!INCLUDE scBal.mak
!INCLUDE scTran.mak
!INCLUDE scLoan.mak
!INCLUDE scPro.mak
!INCLUDE scSchdl.mak
!INCLUDE scInit.mak
