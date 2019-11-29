#############################################################################
#
#  Makefile for SCTRAN, application SC
#
#  Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.
#
#############################################################################

SCTRAN: $(RUNPATH)\SCTRAN.DLL iSCTRAN

iSCTRAN: $(INCPATH)\scTran.i $(INCPATH)\scTran.h $(GENPATH)\scTran.dep

$(RUNPATH)\SCTRAN.DLL: $(OBJPATH)\scTran.obj $(OBJPATH)\scTran1.obj

$(OBJPATH)\scTran.obj: scTran.cpp iSC iSCTRAN scTran1.h scTran2.h scTran3.h

$(OBJPATH)\scTran1.obj: scTran1.cpp iSC iSCTRAN scTran1.h scTran2.h scTran3.h

# If there is a SCTRAN2 table add table generation dependencies here based
# on the .tbl files
$(GENPATH)\scTran.dep: SCTRAN.tbl SCTRAN2.tbl
!IF "SCTRAN"!="SCTRAN"
   gentable -zSCTRAN -T$** -o$(GENPATH)
   echo $@: $** >$@
!ENDIF
