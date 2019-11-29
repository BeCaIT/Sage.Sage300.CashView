#############################################################################
#
#  Makefile for SCOPT, application SC
#
#  Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.
#
#############################################################################

SCOPT: $(RUNPATH)\SCOPT.DLL iSCOPT

iSCOPT: $(INCPATH)\scOpt.i $(INCPATH)\scOpt.h $(GENPATH)\scOpt.dep \
	$(INCPATH)\scEmail.h $(INCPATH)\scUtil.h

$(RUNPATH)\SCOPT.DLL: $(OBJPATH)\scOpt.obj $(OBJPATH)\scOpt1.obj \
	$(OBJPATH)\scEmail.obj $(OBJPATH)\scUtil.obj

$(OBJPATH)\scOpt.obj: scOpt.cpp iSC iSCOPT scOpt1.h scOpt2.h scOpt3.h

$(OBJPATH)\scOpt1.obj: scOpt1.cpp iSC iSCOPT scOpt1.h scOpt2.h scOpt3.h

$(OBJPATH)\scEmail.obj: scEmail.cpp iSC iSCOPT

$(OBJPATH)\scUtil.obj: scUtil.cpp iSC iSCOPT

# If there is a SCOPT2 table add table generation dependencies here based
# on the .tbl files
$(GENPATH)\scOpt.dep: SCOPT.tbl SCOPT2.tbl
!IF "SCOPT"!="SCOPT"
   gentable -zSCOPT -T$** -o$(GENPATH)
   echo $@: $** >$@
!ENDIF
