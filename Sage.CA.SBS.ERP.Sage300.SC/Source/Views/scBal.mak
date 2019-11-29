#############################################################################
#
#  Makefile for SCBAL, application SC
#
#  Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.
#
#############################################################################

SCBAL: $(RUNPATH)\SCBAL.DLL iSCBAL

iSCBAL: $(INCPATH)\scBal.i $(INCPATH)\scBal.h $(GENPATH)\scBal.dep

$(RUNPATH)\SCBAL.DLL: $(OBJPATH)\scBal.obj $(OBJPATH)\scBal1.obj

$(OBJPATH)\scBal.obj: scBal.cpp iSC iSCBAL scBal1.h scBal2.h scBal3.h

$(OBJPATH)\scBal1.obj: scBal1.cpp iSC iSCBAL scBal1.h scBal2.h scBal3.h

# If there is a SCBAL2 table add table generation dependencies here based
# on the .tbl files
$(GENPATH)\scBal.dep: SCBAL.tbl SCBAL2.tbl
!IF "SCBAL"!="SCBAL"
   gentable -zSCBAL -T$** -o$(GENPATH)
   echo $@: $** >$@
!ENDIF
