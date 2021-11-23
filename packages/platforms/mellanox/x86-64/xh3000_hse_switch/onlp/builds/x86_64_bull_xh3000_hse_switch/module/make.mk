###############################################################################
#
# 
#
###############################################################################
THIS_DIR := $(dir $(lastword $(MAKEFILE_LIST)))
x86_64_bull_xh3000_hse_switch_INCLUDES := -I $(THIS_DIR)inc
x86_64_bull_xh3000_hse_switch_INTERNAL_INCLUDES := -I $(THIS_DIR)src
x86_64_bull_xh3000_hse_switch_DEPENDMODULE_ENTRIES := init:x86_64_bull_xh3000_hse_switch ucli:x86_64_bull_xh3000_hse_switch

