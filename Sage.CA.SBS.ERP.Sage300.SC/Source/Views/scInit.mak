#############################################################################
#
#  Makefile for SCINIT, application SC
#
#  Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.
#
#############################################################################

LOPTS = -export:rotoEntry,@1000    \
        -export:identifyEntry,@999 \
        -export:activateCheckCompatibility,@998 \
        -export:activateCheckPrerequisites,@997 \
        -export:activateCleanup,@996 \
        -export:activateInvoke,@995 \
        -export:activateSetup,@994 \
        -export:activateValidateParams,@993

SCINIT: $(RUNPATH)\SCINIT.DLL iSCINIT

iSCINIT: $(INCPATH)\scInit.i $(INCPATH)\scInit.h $(GENPATH)\scInit.dep

$(RUNPATH)\SCINIT.DLL: $(OBJPATH)\scInit.obj $(OBJPATH)\scInit1.obj
	$(LN) $(LFLAGS) $(OBJLIST) $** -out:$@ $(_L_LIBLIST)
	if exist $(_L_MANIFEST) $(MT) $(MFLAGS) -outputresource:$@;2

$(OBJPATH)\scInit.obj: scInit.cpp iSC iSCINIT scInit1.h scInit2.h scInit3.h

$(OBJPATH)\scInit1.obj: scInit1.cpp iSC iSCINIT scInit1.h scInit2.h scInit3.h \
	iSCOPT iSCACCT iSCBAL iSCTRAN iSCPRO

# If there is a SCINIT2 table add table generation dependencies here based
# on the .tbl files
$(GENPATH)\scInit.dep: SCINIT.tbl
!IF "SCINIT"!="SCINIT"
   gentable -zSCINIT -T$** -o$(GENPATH)
   echo $@: $** >$@
!ENDIF

## restore the orignal value
LOPTS = -export:rotoEntry,@1000 -export:identifyEntry,@999