#############################################################################
#
#  Makefile for SC language resources
#
#  Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.
#
#############################################################################



#############################################################################
# Options

# Define the target language if not English
#RESBRANCH = ENG

# Define the version
VERSION = 63A

# Add extra directories when searching for inclusions
# beyond the defaults of $(INCPATH) and $(GENPATH)
#INCSRCH = -I
#RESSRCH = -I

# Specify custom C, resource, or link options
#COPTS =
#ROPTS =



!INCLUDE <ACCPAC.MAK>



#############################################################################
# Targets

all: $(RESPATH)\SC$(VERSION)$(RESBRANCH).DLL $(RESPATH)\grp.dat reports help docs

$(RESPATH)\SC$(VERSION)$(RESBRANCH).DLL: $(OBJPATH)\SC$(VERSION)$(RESBRANCH).RES

$(OBJPATH)\SC$(VERSION)$(RESBRANCH).RES: $(OBJPATH)\SCENG.RES
   copy $? $@

#######################################################################
# Add a dependency for each view's or datapipe's ZZZZ.RC file to the
# following target
# +++

$(OBJPATH)\SCENG.RES: scEng.rc scerr.rc scdp.rc \
   $(INCPATH)\sc.i $(INCPATH)\scerr.i $(INCPATH)\scdp.i \
	scOpt.rc $(INCPATH)\scOpt.i $(GENPATH)\scOpt.dep \
	scAcct.rc $(INCPATH)\scAcct.i $(GENPATH)\scAcct.dep \
	scBal.rc $(INCPATH)\scBal.i $(GENPATH)\scBal.dep \
	scTran.rc $(INCPATH)\scTran.i $(GENPATH)\scTran.dep \
	scLoan.rc $(INCPATH)\scLoan.i $(GENPATH)\scLoan.dep \
	scPro.rc $(INCPATH)\scPro.i $(GENPATH)\scPro.dep \
#  zzzz.rc $(INCPATH)\zzzz.i $(GENPATH)\zzzz.dep

# ---
reports:
	copy ..\Reports\*.rpt $(RESPATH)\

help:
	copy ..\Help\*.chm $(RESPATH)\..\..\Help

docs:
	copy ..\Docs\*.* $(RESPATH)\..\..\Docs