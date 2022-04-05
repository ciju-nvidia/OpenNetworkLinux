###############################################################################
#
# 
#
###############################################################################
THIS_DIR := $(dir $(lastword $(MAKEFILE_LIST)))
x86_64_nvidia_hgx_h100_INCLUDES := -I $(THIS_DIR)inc
x86_64_nvidia_hgx_h100_INTERNAL_INCLUDES := -I $(THIS_DIR)src
x86_64_nvidia_hgx_h100_DEPENDMODULE_ENTRIES := init:x86_64_nvidia_hgx_h100 ucli:x86_64_nvidia_hgx_h100

