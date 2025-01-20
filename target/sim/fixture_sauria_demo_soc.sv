/*
 * Copyright 2025 PoliTo
 * Solderpad Hardware License, Version 2.1, see LICENSE.md for details.
 * SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1
 *
 * Author: Tommaso Terzano <tommaso.terzano@polito.it> 
 *                         <tommaso.terzano@gmail.com>
 *  
 * Info: Fixture module of the SAURIA demonstrator testbench. It integrated the main module of the
 *       SAURIA demonstrator with the vip_cheshire_soc, which provides useful functions to run
 *       simulations, such as loading executables, reading data from UART and so on.
 */

 

  /* Generate configuration for Cheshire */
  localparam cheshire_cfg_t CheshireCfg = gen_cheshire_cfg();