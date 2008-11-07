
default_target: all

#-------------------------------------------------------------------
# Project
#-------------------------------------------------------------------
PRJ_NAME := cvaux
PRJ_TYPE := lib
PRJ_INCS := lib/opencv/cxcore/include 	\
			lib/opencv/cv/include		\
			lib/opencv/cv/src
PRJ_LIBS := 

PRJ_LIBROOT := ..

#-------------------------------------------------------------------
# Configure build
#-------------------------------------------------------------------
include $(PRJ_LIBROOT)/config.mk

#-------------------------------------------------------------------
# File locations
#-------------------------------------------------------------------
export LOC_TAG := def
LOC_INC_def := $(CFG_LIBROOT)/opencv/cvaux/include
LOC_SRC_def := $(CFG_LIBROOT)/opencv/cvaux/src
include $(PRJ_LIBROOT)/build.mk

#-------------------------------------------------------------------
# Execute the build
#-------------------------------------------------------------------
include $(PRJ_LIBROOT)/go.mk

