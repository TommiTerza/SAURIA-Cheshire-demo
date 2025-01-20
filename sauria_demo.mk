# Copyright 2025 PoliTo
# Solderpad Hardware License, Version 2.1, see LICENSE.md for details.
# SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1
#
# Author: Tommaso Terzano <tommaso.terzano@polito.it> 
#                         <tommaso.terzano@gmail.com>
#
# Info: Makefile library of the SAURIA-Cheshire-demo project

# Sauria demo project defines
SAURIA_DEMO_ROOT    ?= $(shell bender path sauria_demo)
SAURIA_DEMO_HW_DIR  := $(SAURIA_DEMO_ROOT)/hw
SAURIA_DEMO_SW_DIR  := $(SAURIA_DEMO_ROOT)/sw
SAURIA_DEMO_TGT_DIR := $(SAURIA_DEMO_ROOT)/target/
SAURIA_DEMO_XIL_DIR := $(SAURIA_DEMO_TGT_DIR)/fpga
SAURIA_DEMO_SIM_DIR := $(SAURIA_DEMO_TGT_DIR)/sim
SAURIA_DEMO_VSIM_DIR := $(SAURIA_DEMO_TGT_DIR)/sim/vsim

# Cheshire defines
CHS_ROOT  := $(shell bender path cheshire)

# Tools defines
BENDER_ROOT ?= $(SAURIA_DEMO_ROOT)/.bender

# Include the Cheshire Makefile
include $(shell bender path cheshire)/cheshire.mk

# Build the hw
.PHONY: hw-all
hw-all: $(MAKE) -B chs-hw-all
