
# config.mk
# Cross compiler config

OS		 := linux
#OS		 := win32

PROC	 := i386
#PROC	 := arm

TOOLS	 := local
#TOOLS	 := debian
#TOOLS	 := android
#TOOLS	 := snapgear

CFG_ROOT := $(PRJ_LIBROOT)/../..
CFG_TOOLROOT := $(PRJ_LIBROOT)/../..
CFG_LIBROOT  := $(PRJ_LIBROOT)/..

ifdef DBG
CFG_CEXTRA	 := -g -DDEBUG -D_DEBUG
CFG_LEXTRA	 := -g -rdynamic
CFG_DPOSTFIX := _d
else
CFG_CEXTRA	 := -s
CFG_LEXTRA	 := -s
endif

ifdef UNICODE
CFG_CEXTRA := $(CFG_CEXTRA) -DUNICODE -D_UNICODE
endif

ifeq ($(OS),win32)

	PLATFORM := windows

	# Tools
	CFG_PP := cl /nologo /DWIN32 /wd4996
	CFG_LD := link /NOLOGO
	CFG_CC := cl /nologo /DWIN32 /wd4996
	CFG_AR := lib /nologo
	CFG_DP := cl /nologo
	CFG_MD := md
	CFG_RM := rmdir /s /q

	CFG_CC_OUT := /Fo
	CFG_LD_OUT := /OUT:
	CFG_AR_OUT := /OUT:

	CFG_CFLAGS := /EHsc /c

	CFG_OBJ_EXT := obj
	CFG_CUR_ROOT := $(shell cd)

	CFG_LIB_PRE	 :=
	CFG_LIB_POST := .lib
	CFG_EXE_POST := .exe

else

	PLATFORM := posix

	# Arm compiler
	ifeq ($(PROC),arm)

		ifeq ($(TOOLS),snapgear)
		
			# Snapgear
			CFG_TOOLPREFIX := $(CFG_TOOLROOT)/tools/snapgear/usr/local/bin/arm-linux-

			CFG_LFLAGS := $(CFG_LEXTRA) -static -lrt -pthread
			CFG_CFLAGS := $(CFG_CEXTRA) -c -MMD -DOEX_ARM -DOEX_LOWRAM -DOEX_NOSTRUCTINIT -DOEX_PACKBROKEN -DOEX_NOUUID -DOEX_NOSHM
			CFG_SFLAGS := $(CFG_CFLAGS) -S -MMD
			CFG_AFLAGS := cq
			
		else
		
			# Google Android
			TOOLS := android
			CFG_TOOLPREFIX := $(CFG_TOOLROOT)/tools/android/CodeSourcery/Sourcery_G++_Lite/bin/arm-none-linux-gnueabi-

			CFG_LFLAGS := $(CFG_LEXTRA) -static -lrt -pthread 
			CFG_CFLAGS := $(CFG_CEXTRA) -c -MMD -DOEX_ARM -DOEX_LOWRAM -DOEX_NOSHM -DOEX_NOUUID
			CFG_SFLAGS := $(CFG_CFLAGS) -S -MMD
			CFG_AFLAGS := cq
			
		endif

	else

		# Local platform
		CFG_TOOLPREFIX := 

		CFG_LFLAGS := $(CFG_LEXTRA) -lrt -pthread -luuid
		CFG_CFLAGS := $(CFG_CEXTRA) -c -MMD
		CFG_SFLAGS := $(CFG_CFLAGS) -S -MMD
		CFG_AFLAGS := cq
		
	endif

	# Tools
	CFG_PP := $(CFG_TOOLPREFIX)g++
	CFG_LD := $(CFG_TOOLPREFIX)g++
	CFG_CC := $(CFG_TOOLPREFIX)gcc
	CFG_AR := $(CFG_TOOLPREFIX)ar
	CFG_DP := $(CFG_TOOLPREFIX)makedepend
	CFG_MD := mkdir -p
	CFG_RM := rm -rf
	
	CFG_LD_OUT := -o $(nullstring)

	CFG_OBJ_EXT := o
	CFG_CUR_ROOT := $(shell pwd)
	
	CFG_LIB_PRE	 := lib
	CFG_LIB_POST := .a
	
endif

CFG_BUILD_TYPE := $(PLATFORM)-$(OS)-$(PROC)-$(TOOLS)

ifdef UNICODE
CFG_BUILD_TYPE := $(CFG_BUILD_TYPE)-unicode
endif

ifdef DBG
CFG_BUILD_TYPE := $(CFG_BUILD_TYPE)-debug
endif

CFG_BINROOT  := $(CFG_LIBROOT)/bin/$(CFG_BUILD_TYPE)

ifdef PRJ_BINROOT
CFG_OUTROOT := $(PRJ_BINROOT)/bin/$(CFG_BUILD_TYPE)
else
CFG_OUTROOT  := $(CFG_BINROOT)
endif

