
PRJ_RELROOT := ../..
include $(PRJ_RELROOT)/buildpath.mk

default_target: all

#-------------------------------------------------------------------
# Project
#-------------------------------------------------------------------
PRJ_NAME := sqbind
PRJ_TYPE := lib
PRJ_INCS := winglib/lib/oexlib SqPlus/include SqPlus/sqplus
PRJ_LIBS := 

#-------------------------------------------------------------------
# Configure build
#-------------------------------------------------------------------
include $(PRJ_LIBROOT)/config.mk

#-------------------------------------------------------------------
# File locations
#-------------------------------------------------------------------
export LOC_TAG := def
include $(PRJ_LIBROOT)/build.mk

export LOC_TAG := import
LOC_INC_import := $(CFG_LIBROOT)/winglib/lib/sqbind
LOC_SRC_import := $(CFG_LIBROOT)/winglib/lib/sqbind/import
include $(PRJ_LIBROOT)/build.mk

#-------------------------------------------------------------------
# Execute the build
#-------------------------------------------------------------------
include $(PRJ_LIBROOT)/go.mk


