#############################################################################
#
#  Makefile for SCLOAN, application SC
#
#  Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.
#
#############################################################################

SCLOAN: $(RUNPATH)\SCLOAN.DLL iSCLOAN

iSCLOAN: $(INCPATH)\scLoan.i $(INCPATH)\scLoan.h $(GENPATH)\scLoan.dep \
	$(INCPATH)\scEmail.h $(INCPATH)\scUtil.h

$(RUNPATH)\SCLOAN.DLL: $(OBJPATH)\scLoan.obj $(OBJPATH)\scLoan1.obj \
	$(OBJPATH)\scEmail.obj $(OBJPATH)\scUtil.obj

$(OBJPATH)\scLoan.obj: scLoan.cpp iSC iSCLOAN scLoan1.h scLoan2.h scLoan3.h

$(OBJPATH)\scLoan1.obj: scLoan1.cpp iSC iSCLOAN scLoan1.h scLoan2.h scLoan3.h

$(OBJPATH)\scEmail.obj: scEmail.cpp iSC iSCLOAN

$(OBJPATH)\scUtil.obj: scUtil.cpp iSC iSCLOAN

# If there is a SCLOAN2 table add table generation dependencies here based
# on the .tbl files
$(GENPATH)\scLoan.dep: SCLOAN.tbl SCLOAN2.tbl
!IF "SCLOAN"!="SCLOAN"
   gentable -zSCLOAN -T$** -o$(GENPATH)
   echo $@: $** >$@
!ENDIF
