#############################################################################
#
#  Makefile for SCACCT, application SC
#
#  Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.
#
#############################################################################

SCACCT: $(RUNPATH)\SCACCT.DLL iSCACCT

iSCACCT: $(INCPATH)\scAcct.i $(INCPATH)\scAcct.h $(GENPATH)\scAcct.dep

$(RUNPATH)\SCACCT.DLL: $(OBJPATH)\scAcct.obj $(OBJPATH)\scAcct1.obj

$(OBJPATH)\scAcct.obj: scAcct.cpp iSC iSCACCT scAcct1.h scAcct2.h scAcct3.h

$(OBJPATH)\scAcct1.obj: scAcct1.cpp iSC iSCACCT scAcct1.h scAcct2.h scAcct3.h

# If there is a SCACCT2 table add table generation dependencies here based
# on the .tbl files
$(GENPATH)\scAcct.dep: SCACCT.tbl SCACCT2.tbl
!IF "SCACCT"!="SCACCT"
   gentable -zSCACCT -T$** -o$(GENPATH)
   echo $@: $** >$@
!ENDIF
