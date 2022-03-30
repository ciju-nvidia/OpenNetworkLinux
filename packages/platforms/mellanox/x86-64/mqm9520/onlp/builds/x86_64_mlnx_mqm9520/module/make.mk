###############################################################################
#
# 
#
###############################################################################
THIS_DIR := $(dir $(lastword $(MAKEFILE_LIST)))
x86_64_mlnx_mqm9520_INCLUDES := -I $(THIS_DIR)inc
x86_64_mlnx_mqm9520_INTERNAL_INCLUDES := -I $(THIS_DIR)src
x86_64_mlnx_mqm9520_DEPENDMODULE_ENTRIES := init:x86_64_mlnx_mqm9520 ucli:x86_64_mlnx_mqm9520

