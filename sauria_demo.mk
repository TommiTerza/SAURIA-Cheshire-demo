# Copyright 2025 PoliTo
# Solderpad Hardware License, Version 2.1, see LICENSE.md for details.
# SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1
#
# Author: Tommaso Terzano <tommaso.terzano@polito.it> 
#                         <tommaso.terzano@gmail.com>
#
# Info: Makefile library of the SAURIA-Cheshire-demo project

# Sauria demo project defines
SAURIA_DEMO_ROOT    ?= $(shell realpath .)
SAURIA_DEMO_HW_DIR  := $(SAURIA_DEMO_ROOT)/hw
SAURIA_DEMO_SW_DIR  := $(SAURIA_DEMO_ROOT)/sw
SAURIA_DEMO_TGT_DIR := $(SAURIA_DEMO_ROOT)/target/
SAURIA_DEMO_XIL_DIR := $(SAURIA_DEMO_TGT_DIR)/fpga
SAURIA_DEMO_SIM_DIR := $(SAURIA_DEMO_TGT_DIR)/sim
SAURIA_DEMO_VSIM_DIR := $(SAURIA_DEMO_TGT_DIR)/sim/vsim

# Cheshire defines
CHS_ROOT  := $(shell bender path cheshire)

# SAURIA defines
SAURIA_ROOT := $(shell bender path sauria)
SAURIA_PULP_ROOT := $(SAURIA_ROOT)/pulp_platform
SAURIA_RTL_ROOT := $(SAURIA_ROOT)/RTL
SAURIA_INCLUDE_DIRS := +incdir+$(SAURIA_PULP_ROOT)/common_cells/include +incdir+$(SAURIA_PULP_ROOT)/axi/include

# Sauria demo include directories
SAURIA_DEMO_INCLUDE_DIR := +incdir+$(SAURIA_DEMO_ROOT)/hw/include \
													 +incdir+$(SAURIA_PULP_ROOT)/axi/include \
													 +incdir+$(SAURIA_PULP_ROOT)/common_cells/include \
													 +incdir+$(CHS_ROOT)/hw/include/cheshire

# Tools defines
BENDER_ROOT ?= $(SAURIA_DEMO_ROOT)/.bender

# Include the Cheshire Makefile
include $(shell bender path cheshire)/cheshire.mk

.PHONY: hw-all
hw-all:
	# $(MAKE) -B chs-hw-all
	vlog $(SAURIA_PULP_ROOT)/axi/src/axi_pkg.sv
	vlog $(SAURIA_RTL_ROOT)/src/sauria_pkg.sv

	# Compiling SAURIA core
	PULP_DIR=$(SAURIA_PULP_ROOT) RTL_DIR=$(SAURIA_RTL_ROOT) \
	vlog -f $(SAURIA_RTL_ROOT)/filelist.f $(SAURIA_INCLUDE_DIRS)

	# Compiling the SAURIA demo
	vlog $(SAURIA_DEMO_ROOT)/hw/axi_intfc_bridge.sv 
	vlog $(SAURIA_DEMO_ROOT)/hw/axi_lite_intfc_bridge.sv
	vlog $(SAURIA_DEMO_ROOT)/hw/sauria_demo_soc.sv
