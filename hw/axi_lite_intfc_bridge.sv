/*
 * Copyright 2025 PoliTo
 * Solderpad Hardware License, Version 2.1, see LICENSE.md for details.
 * SPDX-License-Identifier: Apache-2.0 WITH SHL-2.1
 *
 * Author: Tommaso Terzano <tommaso.terzano@polito.it> 
 *                         <tommaso.terzano@gmail.com>
 *
 * Info: Bridge between interface-based AXI-Lite protocol and structure-based AXI-Lite protocol 
 *       (PULP's reginterface).
 *       This module assumes a simple single-transaction model: if req_t.write == 1, it performs
 *       a write transaction; otherwise, it performs a read. On completion, rsp_t.ready is set, 
 *       and rsp_t.error signals whether an error (non-OKAY) response was received. 
 */

module axi_lite_intfc_bridge #(
  parameter int unsigned AXI_ADDR_WIDTH = 32,
  parameter int unsigned AXI_DATA_WIDTH = 32,
  
  /* Request struct of the AXI4 port */
  parameter type req_t = logic,
  /* Response struct of the AXI4 port */
  parameter type resp_t = logic
)(
  /* From the structure-based AXI-Lite side */
  input  req_t    axil_req_i,  // {addr, write, wdata, wstrb, valid}
  output rsp_t    axil_rsp_o,  // {rdata, error, ready}

  /* To the interface-based AXI-Lite side (in Slave mode) */
  AXI_LITE.Slave  axil_if
);

  /*----------------------------------------------------------------------
   * Local parameters & typedefs 
   * (These come from the interface, but you could also re-declare them here)
   *---------------------------------------------------------------------*/
  localparam int unsigned STRB_WIDTH = AXI_DATA_WIDTH / 8;

  /*----------------------------------------------------------------------
   * Default tie-offs or assumptions (PROT, etc.)
   * In a real design, you might configure these or tie them more carefully.
   *---------------------------------------------------------------------*/
  // Set the protection bits to zero, 3'b000 indicates "normal, non-secure, data access".
  localparam axi_pkg::prot_t DEFAULT_PROT = '0; 

  /* Write Address Channel (AW)
   * If we're doing a write (req.write=1, req.valid=1), drive AW with req.addr.
   */
  assign axil_if.aw_addr  = (axil_req_i.write && axil_req_i.valid)
                            ? axil_req_i.addr 
                            : '0;

  assign axil_if.aw_prot  = DEFAULT_PROT;
  
  /* For a basic bridging, AW valid is asserted if it's a valid write request. */
  assign axil_if.aw_valid = (axil_req_i.write && axil_req_i.valid);

  /* The interface drives aw_ready out. We do not gate it here.
  We won't wait for aw_ready to go high before driving w_valid. 
  This is a simplistic approach (no handshake stall).
  If you need full handshake correctness, add a small state machine. */
  
  /*----------------------------------------------------------------------
   * Write Data Channel (W)
   * If we're doing a write, drive w_data and w_strb.
   *---------------------------------------------------------------------*/
  assign axil_if.w_data  = (axil_req_i.write && axil_req_i.valid)
                           ? axil_req_i.wdata
                           : '0;

  assign axil_if.w_strb  = (axil_req_i.write && axil_req_i.valid)
                           ? axil_req_i.wstrb
                           : '0;

  // w_valid goes high when we are doing a write transaction
  assign axil_if.w_valid = (axil_req_i.write && axil_req_i.valid);

  /* We tie w_ready out to nothing special, 
   * but the interface can de-assert w_ready if it stalls data acceptance.
   */

  /* Write Response Channel (B)
   * We assume any time a write is in flight, we'll accept b_valid immediately. 
   * If we have a valid write request, we tie b_ready to 1 so we accept any response.
   * Some designs might tie b_ready only while that transaction is outstanding.
   * But for simplicity, keep b_ready high if we are "in a write request".
   */
  assign axil_if.b_ready = 1'b1;

  /* Read Address Channel (AR)
   * If we're doing a read (req.write=0, req.valid=1), drive AR with req.addr. 
   */
  assign axil_if.ar_addr = (!axil_req_i.write && axil_req_i.valid)
                           ? axil_req_i.addr
                           : '0;

  assign axil_if.ar_prot = DEFAULT_PROT;

  // ar_valid goes high when we are doing a read transaction
  assign axil_if.ar_valid = (!axil_req_i.write && axil_req_i.valid);

  /* Read Data Channel (R)
   * We'll tie r_ready=1 so we always accept read data immediately.
   */
  assign axil_if.r_ready = 1'b1;

  /* Response Back to Structure
   *   - axil_rsp_o.rdata = r_data if read transaction
   *   - axil_rsp_o.error = set if b_resp or r_resp != OKAY
   *   - axil_rsp_o.ready = 1 if either a write or read completed
   */

  // rdata is valid only if r_valid=1 (meaning a read completed).
  // If it was a write transaction, there's no read data, so we can tie 0 or keep last data.
  assign axil_rsp_o.rdata = (axil_if.r_valid) 
                            ? axil_if.r_data 
                            : '0;

  // For either a read or a write, we consider the transaction "done" if we see b_valid or r_valid.
  // b_valid is the write response, r_valid is the read data response.
  assign axil_rsp_o.ready = (axil_if.b_valid || axil_if.r_valid);

  // "error" if b_resp or r_resp is not OKAY (0). 
  // Typically, axi_pkg::resp_t is 2 bits (OKAY=2'b00, SLVERR=2'b10, DECERR=2'b11, etc.).
  wire logic b_error = (axil_if.b_valid && axil_if.b_resp != axi_pkg::OKAY);
  wire logic r_error = (axil_if.r_valid && axil_if.r_resp != axi_pkg::OKAY);

  assign axil_rsp_o.error = (b_error || r_error);

endmodule
