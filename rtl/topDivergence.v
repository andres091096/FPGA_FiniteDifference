/* verilator lint_off UNUSED */
module topDivergence(i_clk, i_reset, i_start, o_valid, o_data);
  input  wire        i_clk;
  input  wire        i_reset;
  input  wire        i_start;
  output wire        o_valid;
  output wire [31:0] o_data;
  ///register an wires
  wire signed [31:0] w_datax;
  wire signed [31:0] w_datay;
  wire signed [31:0] w_data;
  wire signed [11:0] w_address;
  wire signed [11:0] w_address2;
  wire signed [11:0] r_address;
  wire               w_bussy;
  wire               w_read;
  wire               w_valid;
  wire               counter_en;

  initial w_address = 0;

  always @ (posedge i_clk) begin
    if (w_read) begin
      w_address <= w_address+1;
    end
  end

  always @ (posedge i_clk) begin
    if (counter_en) begin
      r_address <= r_address+1;
    end
  end

  rom #(.WIDTH(32), .DEPTH(4096), .INIT_F("Ux_fixed_point.mem"), .ADDRW(12))
      rom_Ux(i_clk, w_address, w_datax);

  rom #(.WIDTH(32), .DEPTH(4096), .INIT_F("Uy_fixed_point.mem"), .ADDRW(12))
      rom_Uy(i_clk, w_address, w_datay);

  dive2d #(.WIDTH(32), .ADD_W(12))
         dive2d_inst(i_clk, i_reset, w_datax, w_datay, i_start, w_read, w_data, w_address2, w_valid, w_bussy);

  ram #(.WIDTH(32), .ADDR_WIDTH(12))
      ramW(i_clk, w_valid, w_data, r_address, w_address2, o_data);
  assign o_valid = counter_en;

  // Control (FSM)
  localparam S0  = 2'b00; //IDLE state
  localparam S1    = 2'b01; //Save Input 1 **(Dy)**
  localparam S2    = 2'b10; //Save Input 2 **(Dy)** and Write FIFO
  localparam S3    = 2'b11; //Write FIFO
  reg [1:0] state = S0;
  always @(posedge i_clk)
    if (i_reset) begin
      state <= S0;
    end
    else
      case (state)
        S0 : begin
          if (i_start)
            state <= S1;
          else
            state <= S0;
          end
          S1 : begin
            if(w_valid)
              state <= S2;
            else
              state <= S1;
          end
          S2 : begin
            if(~w_valid)
              state <= S3;
            else
              state <= S2;
          end
          S3 : begin
            if(&r_address)
              state <= S0;
            else
              state <= S3;
          end
          default : begin  // Fault Recovery
            state <= S0;
          end
        endcase
       /* verilator lint_off COMBDLY */
         always @(*)
           case (state)
             S0 : begin
               counter_en <= 1'b0;
             end
             S1 : begin
               counter_en <= 1'b0;
             end
             S2 : begin
               counter_en <= 1'b0;
             end
             S3 : begin
               counter_en <= 1'b1;
             end
             default : begin
               counter_en <= 1'b0;
             end
           endcase
     /* verilator lint_on COMBDLY */

endmodule // top
/* verilator lint_on UNUSED */
