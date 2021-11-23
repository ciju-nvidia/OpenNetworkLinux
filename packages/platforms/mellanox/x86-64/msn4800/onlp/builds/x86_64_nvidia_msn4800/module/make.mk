###############################################################################
#
# 
#
###############################################################################
THIS_DIR := $(dir $(lastword $(MAKEFILE_LIST)))
x86_64_nvidia_msn4800_INCLUDES := -I $(THIS_DIR)inc
x86_64_nvidia_msn4800_INTERNAL_INCLUDES := -I $(THIS_DIR)src
x86_64_nvidia_msn4800_DEPENDMODULE_ENTRIES := init:x86_64_nvidia_msn4800 ucli:x86_64_nvidia_msn4800

