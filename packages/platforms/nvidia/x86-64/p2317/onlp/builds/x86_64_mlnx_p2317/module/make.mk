###############################################################################
#
# 
#
###############################################################################
THIS_DIR := $(dir $(lastword $(MAKEFILE_LIST)))
x86_64_nvidia_e3597_INCLUDES := -I $(THIS_DIR)inc
x86_64_nvidia_e3597_INTERNAL_INCLUDES := -I $(THIS_DIR)src
x86_64_nvidia_e3597_DEPENDMODULE_ENTRIES := init:x86_64_nvidia_e3597 ucli:x86_64_nvidia_e3597

