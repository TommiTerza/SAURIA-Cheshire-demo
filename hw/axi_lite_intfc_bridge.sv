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
  parameter int unsigned DataWidth = 32,
  // RegBus request type (must match your system's definition)
  parameter type reg_req_t = logic,
  // RegBus response type
  parameter type reg_rsp_t = logic,
  // AXI-Lite request type
  parameter type axi_lite_req_t = logic,
  // AXI-Lite response type
  parameter type axi_lite_rsp_t = logic
)(
  //----------------------------------------------------------------------------
  // Clocks and Resets
  //----------------------------------------------------------------------------
  input  logic        clk_i,
  input  logic        rst_ni,

  //----------------------------------------------------------------------------
  // AXI-Lite side (Slave interface)
  //   An external AXI-Lite Master will drive these requests (axi_lite_req_i),
  //   and we must produce responses (axi_lite_rsp_o).
  //----------------------------------------------------------------------------
  input  axi_lite_req_t axi_lite_req_i,
  output axi_lite_rsp_t axi_lite_rsp_o,

  //----------------------------------------------------------------------------
  // RegBus side
  //   We produce a single read/write command (reg_req_o) from each AXI-Lite
  //   transaction, and we wait for a reg_rsp_i to finalize the transaction.
  //----------------------------------------------------------------------------
  output reg_req_t reg_req_o,
  input  reg_rsp_t reg_rsp_i
);

  //----------------------------------------------------------------------------
  // Local signals for transaction tracking
  //----------------------------------------------------------------------------
  // We'll store whether we have an ongoing write or read request until the
  // regbus side has responded. This is a basic approach: we block further
  // requests until the transaction completes.
  // 
  // If your system needs more concurrency, consider a small state machine.
  //----------------------------------------------------------------------------
  logic write_pending_q, read_pending_q;

  // Example: latch AW vs. AR addresses, then wait for W data or regbus response
  // For brevity, we show a single-cycle approach. 
  // For actual AXI-Lite compliance, you might handle handshake stalls carefully.

  //----------------------------------------------------------------------------
  // AXI-Lite: "aw_valid" => we have a write address, "w_valid" => write data
  // AXI-Lite: "ar_valid" => we have a read address
  //
  // We combine address + data into reg_req_o, then wait for reg_rsp_i.
  //----------------------------------------------------------------------------

  // Write address handshake (AW)
  // - If aw_valid=1 & aw_ready=1, capture address and mark write pending
  // - In a minimal design, we might tie aw_ready high if no transaction is pending
  assign axi_lite_rsp_o.aw_ready = ~write_pending_q & ~read_pending_q;

  // Write data handshake (W)
  // - If w_valid=1 & w_ready=1, we then finalize the reg_req_o
  // - Similarly, we might tie w_ready to the same condition
  assign axi_lite_rsp_o.w_ready  = ~write_pending_q & ~read_pending_q;

  // Write response (B)
  // - We produce b_valid once regbus indicates "ready"
  // - The response "b_resp" is an error if reg_rsp_i.error=1
  //
  // A single transaction approach: b_valid is high once we see reg_rsp_i.ready for a write
  // and we have a pending write.
  assign axi_lite_rsp_o.b_valid = write_pending_q & reg_rsp_i.ready;
  assign axi_lite_rsp_o.b.resp  = (reg_rsp_i.error) ? axi_pkg::RESP_SLVERR 
                                                    : axi_pkg::RESP_OKAY;

  // The master sets b_ready to 1 when it accepts the response, so we can clear.
  wire logic clear_write = axi_lite_rsp_o.b_valid & axi_lite_req_i.b_ready;

  //----------------------------------------------------------------------------
  // Read address handshake (AR)
  // - If ar_valid=1 & ar_ready=1, capture address and mark read pending
  // - Tie ar_ready high if no transaction is pending
  assign axi_lite_rsp_o.ar_ready = ~write_pending_q & ~read_pending_q;

  // Read data (R)
  // - We produce r_valid once regbus indicates "ready" for a read transaction
  // - r_data is from reg_rsp_i.rdata, r_resp depends on reg_rsp_i.error
  assign axi_lite_rsp_o.r_valid       = read_pending_q & reg_rsp_i.ready;
  assign axi_lite_rsp_o.r.data       = reg_rsp_i.rdata;
  assign axi_lite_rsp_o.r.resp       = (reg_rsp_i.error) ? axi_pkg::RESP_SLVERR 
                                                         : axi_pkg::RESP_OKAY;

  // The master sets r_ready=1 to accept the read data, so we can clear read pending
  wire logic clear_read = axi_lite_rsp_o.r_valid & axi_lite_req_i.r_ready;

  //----------------------------------------------------------------------------
  // Registers for pending states
  //----------------------------------------------------------------------------
  always_ff @(posedge clk_i or negedge rst_ni) begin
    if (!rst_ni) begin
      write_pending_q <= 1'b0;
      read_pending_q  <= 1'b0;
    end
    else begin
      // If we see aw_valid & aw_ready => new write request
      if (axi_lite_req_i.aw_valid & axi_lite_rsp_o.aw_ready) begin
        write_pending_q <= 1'b1;
      end
      // Clear after the B channel handshake completes
      else if (clear_write) begin
        write_pending_q <= 1'b0;
      end

      // If we see ar_valid & ar_ready => new read request
      if (axi_lite_req_i.ar_valid & axi_lite_rsp_o.ar_ready) begin
        read_pending_q <= 1'b1;
      end
      // Clear after the R channel handshake
      else if (clear_read) begin
        read_pending_q <= 1'b0;
      end
    end
  end

  //----------------------------------------------------------------------------
  // Combine AW+W into a single regbus request
  // For a minimal approach, we only build reg_req_o once we see both AW & W
  // valid & handshake. In a real design, you might store AW address on AW handshake
  // and store W data on W handshake. This simple code just merges them if they
  // appear in the same cycle. 
  // If they're separate cycles, you need a small pipeline or queue.
  //----------------------------------------------------------------------------
  wire logic do_write = (axi_lite_req_i.aw_valid & axi_lite_rsp_o.aw_ready) 
                     & (axi_lite_req_i.w_valid  & axi_lite_rsp_o.w_ready);

  // Similarly, do_read is set on ar_valid & ar_ready
  wire logic do_read  = (axi_lite_req_i.ar_valid & axi_lite_rsp_o.ar_ready);

  // The reg_req_t might have fields: addr, write, wdata, wstrb, valid (example)
  assign reg_req_o.addr   = do_write ? axi_lite_req_i.aw.addr 
                         : do_read  ? axi_lite_req_i.ar.addr 
                         : '0;
  assign reg_req_o.write  = do_write;
  assign reg_req_o.wdata  = axi_lite_req_i.w.data;
  assign reg_req_o.wstrb  = axi_lite_req_i.w.strb;
  assign reg_req_o.valid  = do_write | do_read;

endmodule

`include "axi/typedef.svh"
`include "axi/assign.svh"

//----------------------------------------------------------------------------
// Interface wrapper: if your code expects an AXI_LITE interface in Slave mode
// and your system uses reg_req_t/reg_rsp_t, do something like this:
//----------------------------------------------------------------------------
module axi_lite_to_reg_intf #(
  parameter int ADDR_WIDTH = 32,
  parameter int DATA_WIDTH = 32,
  // RegBus request/response types
  parameter type reg_req_t = logic,
  parameter type reg_rsp_t = logic
)(
  input  logic       clk_i,
  input  logic       rst_ni,
  // RegBus
  output reg_req_t   reg_req_o,
  input  reg_rsp_t   reg_rsp_i,
  // AXI-Lite interface in Slave mode
  AXI_LITE.Slave     axi_i
);

  //------------------------------------------------------------------------------
  // Generate AXI-Lite request/response structs via macros
  //  e.g. if you want an AW/W/AR struct, etc. 
  //------------------------------------------------------------------------------
  localparam int STRB_WIDTH = DATA_WIDTH / 8;

  typedef logic [ADDR_WIDTH-1:0] addr_t;
  typedef logic [DATA_WIDTH-1:0] data_t;
  typedef logic [STRB_WIDTH-1:0] strb_t;

  `AXI_LITE_TYPEDEF_AW_CHAN_T(aw_chan_t, addr_t)
  `AXI_LITE_TYPEDEF_W_CHAN_T (w_chan_t, data_t, strb_t)
  `AXI_LITE_TYPEDEF_B_CHAN_T (b_chan_t)
  `AXI_LITE_TYPEDEF_AR_CHAN_T(ar_chan_t, addr_t)
  `AXI_LITE_TYPEDEF_R_CHAN_T (r_chan_t, data_t)
  `AXI_LITE_TYPEDEF_REQ_T(axi_lite_req_t, aw_chan_t, w_chan_t, ar_chan_t)
  `AXI_LITE_TYPEDEF_RESP_T(axi_lite_rsp_t, b_chan_t, r_chan_t)

  // Local AXI struct signals 
  axi_lite_req_t local_req;
  axi_lite_rsp_t local_rsp;

  // Assign from interface => local_req
  `AXI_LITE_ASSIGN_TO_REQ(local_req, axi_i)

  // Assign local_rsp => interface
  `AXI_LITE_ASSIGN_FROM_RESP(axi_i, local_rsp)

  // Output signals to the regbus bridging logic
  // (We use the bridging module defined above: axi_lite_to_reg)
  axi_lite_intfc_bridge #(
    .DataWidth      (DATA_WIDTH),
    .reg_req_t      (reg_req_t),
    .reg_rsp_t      (reg_rsp_t),
    .axi_lite_req_t (axi_lite_req_t),
    .axi_lite_rsp_t (axi_lite_rsp_t)
  ) i_axi_lite_to_reg (
    .clk_i         (clk_i),
    .rst_ni        (rst_ni),
    .axi_lite_req_i(local_req),
    .axi_lite_rsp_o(local_rsp),
    .reg_req_o     (reg_req_o),
    .reg_rsp_i     (reg_rsp_i)
  );

endmodule
