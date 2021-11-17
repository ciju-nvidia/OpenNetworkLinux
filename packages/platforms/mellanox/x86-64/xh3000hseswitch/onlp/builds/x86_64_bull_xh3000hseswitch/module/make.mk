###############################################################################
#
# 
#
###############################################################################
THIS_DIR := $(dir $(lastword $(MAKEFILE_LIST)))
x86_64_bull_xh3000hseswitch_INCLUDES := -I $(THIS_DIR)inc
x86_64_bull_xh3000hseswitch_INTERNAL_INCLUDES := -I $(THIS_DIR)src
x86_64_bull_xh3000hseswitch_DEPENDMODULE_ENTRIES := init:x86_64_bull_xh3000hseswitch ucli:x86_64_bull_xh3000hseswitch

