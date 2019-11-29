#############################################################################
#
#  Makefile for SCPRO, application SC
#
#  Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.
#
#############################################################################

SCPRO: $(RUNPATH)\SCPRO.DLL iSCPRO

iSCPRO: $(INCPATH)\scPro.i $(INCPATH)\scPro.h $(GENPATH)\scPro.dep

$(RUNPATH)\SCPRO.DLL: $(OBJPATH)\scPro.obj $(OBJPATH)\scPro1.obj \
	$(OBJPATH)\scEmail.obj $(OBJPATH)\scUtil.obj

$(OBJPATH)\scPro.obj: scPro.cpp iSC iSCPRO scPro1.h scPro2.h scPro3.h

$(OBJPATH)\scPro1.obj: scPro1.cpp iSC iSCPRO scPro1.h scPro2.h scPro3.h

$(OBJPATH)\scEmail.obj: scEmail.cpp iSC iSCLOAN

$(OBJPATH)\scUtil.obj: scUtil.cpp iSC iSCLOAN

# If there is a SCPRO2 table add table generation dependencies here based
# on the .tbl files
$(GENPATH)\scPro.dep: SCPRO.tbl
!IF "SCPRO"!="SCPRO"
   gentable -zSCPRO -T$** -o$(GENPATH)
   echo $@: $** >$@
!ENDIF
