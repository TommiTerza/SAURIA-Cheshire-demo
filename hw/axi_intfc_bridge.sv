/*
 * Copyright 2025 PoliTo
 * Solderpad Hardware License, Version 2.1, see LICENSE.md for details.
 * SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1
 *
 * Author: Tommaso Terzano <tommaso.terzano@polito.it> 
 *                         <tommaso.terzano@gmail.com>
 *  
 * Info: Bridge between interface-based AXI protocol and structure based AXI protocol.
 */

module axi_intfc_bridge #(
  // You can add parameters for ID/Data widths if needed,
  // or rely on those defined inside the interface and structs.
)(
  /* From the struct side: */
  input  req_t                axi_req_i,
  output resp_t               axi_rsp_o,

  /* To the interface side:
   * 
   * We assume the interface is declared outside and passed in.
   * The interface is in Slave mode, meaning it expects signals as inputs. 
   */
  AXI_BUS.Slave axi_if
);

  /* AW CHANNEL: Master → Slave */
  assign axi_if.aw_id     = axi_req_i.aw.id;
  assign axi_if.aw_addr   = axi_req_i.aw.addr;
  assign axi_if.aw_len    = axi_req_i.aw.len;
  assign axi_if.aw_size   = axi_req_i.aw.size;
  assign axi_if.aw_burst  = axi_req_i.aw.burst;
  assign axi_if.aw_lock   = axi_req_i.aw.lock;
  assign axi_if.aw_cache  = axi_req_i.aw.cache;
  assign axi_if.aw_prot   = axi_req_i.aw.prot;
  assign axi_if.aw_qos    = axi_req_i.aw.qos;
  assign axi_if.aw_region = axi_req_i.aw.region;
  assign axi_if.aw_atop   = axi_req_i.aw.atop;
  assign axi_if.aw_user   = axi_req_i.aw.user;

  assign axi_if.aw_valid  = axi_req_i.aw_valid;
  assign axi_rsp_o.aw_ready = axi_if.aw_ready;

  /* W CHANNEL: Master → Slave */
  assign axi_if.w_data  = axi_req_i.w.data;
  assign axi_if.w_strb  = axi_req_i.w.strb;
  assign axi_if.w_last  = axi_req_i.w.last;
  assign axi_if.w_user  = axi_req_i.w.user;

  assign axi_if.w_valid = axi_req_i.w_valid;
  assign axi_rsp_o.w_ready = axi_if.w_ready;

  /* B CHANNEL: Slave → Master */
  assign axi_if.b_ready    = axi_req_i.b_ready;
  assign axi_rsp_o.b_valid = axi_if.b_valid;

  assign axi_rsp_o.b.id    = axi_if.b_id;
  assign axi_rsp_o.b.resp  = axi_if.b_resp;
  assign axi_rsp_o.b.user  = axi_if.b_user;

  /* AR CHANNEL: Master → Slave */
  assign axi_if.ar_id     = axi_req_i.ar.id;
  assign axi_if.ar_addr   = axi_req_i.ar.addr;
  assign axi_if.ar_len    = axi_req_i.ar.len;
  assign axi_if.ar_size   = axi_req_i.ar.size;
  assign axi_if.ar_burst  = axi_req_i.ar.burst;
  assign axi_if.ar_lock   = axi_req_i.ar.lock;
  assign axi_if.ar_cache  = axi_req_i.ar.cache;
  assign axi_if.ar_prot   = axi_req_i.ar.prot;
  assign axi_if.ar_qos    = axi_req_i.ar.qos;
  assign axi_if.ar_region = axi_req_i.ar.region;
  assign axi_if.ar_user   = axi_req_i.ar.user;

  assign axi_if.ar_valid  = axi_req_i.ar_valid;
  assign axi_rsp_o.ar_ready = axi_if.ar_ready;

/* R CHANNEL: Slave → Master */  
  assign axi_if.r_ready   = axi_req_i.r_ready;
  assign axi_rsp_o.r_valid = axi_if.r_valid;

  assign axi_rsp_o.r.id    = axi_if.r_id;
  assign axi_rsp_o.r.data  = axi_if.r_data;
  assign axi_rsp_o.r.resp  = axi_if.r_resp;
  assign axi_rsp_o.r.last  = axi_if.r_last;
  assign axi_rsp_o.r.user  = axi_if.r_user;

endmodule
