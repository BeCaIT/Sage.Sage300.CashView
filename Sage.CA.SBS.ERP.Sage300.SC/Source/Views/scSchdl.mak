#############################################################################
#
#  Makefile for SCSCHDL, application SC
#
#  Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.
#
#############################################################################

SCSCHDL: $(RUNPATH)\SCSCHDL.DLL iSCSCHDL

iSCSCHDL: $(INCPATH)\scSchdl.i $(INCPATH)\scSchdl.h $(GENPATH)\scSchdl.dep

$(RUNPATH)\SCSCHDL.DLL: $(OBJPATH)\scSchdl.obj $(OBJPATH)\scSchdl1.obj

$(OBJPATH)\scSchdl.obj: scSchdl.cpp iSC iSCSCHDL scSchdl1.h scSchdl2.h scSchdl3.h $(INCPATH)\CSCBSK.H

$(OBJPATH)\scSchdl1.obj: scSchdl1.cpp iSC iSCSCHDL scSchdl1.h scSchdl2.h scSchdl3.h $(INCPATH)\CSCBSK.H

# If there is a SCSCHDL2 table add table generation dependencies here based
# on the .tbl files
$(GENPATH)\scSchdl.dep: SCSCHDL.tbl
!IF "SCSCHDL"!="SCSCHDL"
   gentable -zSCSCHDL -T$** -o$(GENPATH)
   echo $@: $** >$@
!ENDIF
