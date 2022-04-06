###############################################################################
#
# 
#
###############################################################################
THIS_DIR := $(dir $(lastword $(MAKEFILE_LIST)))
x86_64_nvidia_sn5600_INCLUDES := -I $(THIS_DIR)inc
x86_64_nvidia_sn5600_INTERNAL_INCLUDES := -I $(THIS_DIR)src
x86_64_nvidia_sn5600_DEPENDMODULE_ENTRIES := init:x86_64_nvidia_sn5600 ucli:x86_64_nvidia_sn5600

