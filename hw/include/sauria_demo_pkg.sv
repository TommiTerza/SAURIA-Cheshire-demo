/*
 * Copyright 2025 PoliTo
 * Solderpad Hardware License, Version 2.1, see LICENSE.md for details.
 * SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1
 *
 * Author: Tommaso Terzano <tommaso.terzano@polito.it> 
 *                         <tommaso.terzano@gmail.com>
 *  
 * Info: Package for the SAURIA demonstrator, contains functions and parameters for Cheshire integration
 */

package sauria_demo_pkg;

  `include "cheshire/typedef.svh"

  import cheshire_pkg::*;

  /* This function returns a Cheshire configuration. */
  function automatic cheshire_pkg::cheshire_cfg_t gen_cheshire_cfg();
    cheshire_pkg::cheshire_cfg_t ret = cheshire_pkg::DefaultCfg;
    
    ret.AxiExtNumSlv = 1;
    ret.RegExtNumSlv = 1;

    return ret;
  endfunction
  
endpackage
