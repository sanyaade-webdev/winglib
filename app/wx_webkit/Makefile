
PRJ_RELROOT := ../..
include $(PRJ_RELROOT)/buildpath.mk

default_target: all

#-------------------------------------------------------------------
# Project
#-------------------------------------------------------------------
PRJ_NAME := wx_webkit
PRJ_DEPS := WebKit
PRJ_TYPE := exe
PRJ_LIBS := oexlib
PRJ_INCS := winglib/lib/oexlib curl/include WebKit/WebKit/win
PRJ_DEFS := NDEBUG=1 USE_FREETYPE PTW32_STATIC_LIB

#-------------------------------------------------------------------
# Configure build
#-------------------------------------------------------------------
include $(PRJ_LIBROOT)/config.mk

ifeq ($(PLATFORM),windows)
	PRJ_OSLB := comctl32 comdlg32 uuid oleaut32
	PRJ_LIBS := $(PRJ_LIBS) jpeg WebKit wxWidgets sqlite xml zlib jpeg curl
	PRJ_DEFS := $(PRJ_DEFS) 
		# NEED_ERRNO
	PRJ_INCS := $(PRJ_INCS) winglib/dep/etc/wxWidgets/inc/windows wxWidgets/include

else
	PRJ_LIBS := $(PRJ_LIBS) jpeg
	PRJ_EXTC := `wx-config --cppflags`
	PRJ_EXTL := `wx-config --libs`
	PRJ_OSLB := X11 GLU Xxf86vm
endif

#-------------------------------------------------------------------
# File locations
#-------------------------------------------------------------------
export LOC_TAG := def
include $(PRJ_LIBROOT)/build.mk

#-------------------------------------------------------------------
# Execute the build
#-------------------------------------------------------------------
include $(PRJ_LIBROOT)/go.mk


