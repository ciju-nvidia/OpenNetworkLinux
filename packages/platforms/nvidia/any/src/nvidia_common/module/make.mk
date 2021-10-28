###############################################################################
#
#
#
###############################################################################
THIS_DIR := $(dir $(lastword $(MAKEFILE_LIST)))
nvidia_common_INCLUDES := -I $(THIS_DIR)inc
nvidia_common_INTERNAL_INCLUDES := -I $(THIS_DIR)src
nvidia_common_DEPENDMODULE_ENTRIES := init:nvidia_common ucli:nvidia_common

#
# This is a real bug:
#
# nvidia_common_fani.c:310:61: error: division 'sizeof (int *) / sizeof (int)' does not compute the number of array elements [-Werror=sizeof-pointer-div]
#
nvidia_common_CFLAGS := -Wno-sizeof-pointer-div
