#############################################################################
#
#  Makefile for SC common definitions
#
#  Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.
#
#############################################################################



#############################################################################
# Build targeting options

DESCRIPTION = Copyright © 2019 Sage Software Asia Pte Ltd. All rights reserved.

# If precompiled headers are to be used uncomment the following line
#PCHBASE = sc

!INCLUDE <ACCPAC.MAK>



#############################################################################
# Targets


# Overarching target to build everything
all: includes pch resource library extincludes


# Add dependencies for shared inclusions
includes: \
   $(INCPATH)\sc.h \
   $(INCPATH)\sc.i \
   $(INCPATH)\scerr.i \
   $(INCPATH)\scdp.i \


# precompiled headers shared by all objects.
pch: $(PCHFILE)

!IF DEFINED(PCHFILE)
$(PCHFILE): sc.c includes
!ENDIF


# Resource files
resource: \
   $(RUNPATH)\roto.dat \
   $(RUNPATH)\sc.rsc \
   $(RUNPATH)\sc.ini \
   $(RUNPATH)\scrpt.ini \


# Shared library
library:

$(RUNPATH)\roto.dat: roto.txt
	ccroto roto.txt roto.pre
	cclsroto roto.pre $(RUNPATH)\roto.dat
	del roto.pre

	
# External includes
extincludes:
	copy EXTERNAL\*.h $(INCPATH)\