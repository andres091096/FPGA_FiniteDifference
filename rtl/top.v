/* verilator lint_off UNUSED */
module top(i_clk, i_reset, i_start, o_valid, o_datax, o_datay);
  input  wire        i_clk;
  input  wire        i_reset;
  input  wire        i_start;
  output wire        o_valid;
  output wire [31:0] o_datax;
  output wire [31:0] o_datay;
  ///register an wires
  wire signed [31:0] w_data;
  wire signed [11:0] w_address;
  wire signed [11:0] w_Dxaddr;
  wire               w_bussy;
  wire               w_DxValid;
  wire               w_DyValid;

  rom #(.WIDTH(32), .DEPTH(4096), .INIT_F("U_fixed_point.mem"), .ADDRW(12))
        rom_int(i_clk, w_address, w_data);

  diff2d #(.WIDTH(32), .ADD_W(12))
         diff2d_inst(i_clk, i_reset, w_data, i_start, o_datax, o_datay, w_address, w_Dxaddr, w_DyValid, w_DxValid, w_bussy);

  assign o_valid = w_DyValid;

endmodule // top
/* verilator lint_on UNUSED */
