
module diff2d(i_clk, i_reset, i_data, i_start, o_datax, o_datay, o_address, o_Dx_addr, o_DyValid, o_DxValid, o_bussy);
  parameter WIDTH = 32, ADD_W = 12;
  localparam l = 6; //log2(px); px =64
  input  wire                      i_clk;
  input  wire                      i_reset;
  input  wire signed [(WIDTH-1):0] i_data;
  input  wire                      i_start;
  output wire signed [(WIDTH-1):0] o_datax;
  output wire signed [(WIDTH-1):0] o_datay;
  output wire        [(ADD_W-1):0] o_address;
  output wire        [(ADD_W-1):0] o_Dx_addr;
  output wire                      o_DyValid;
  output wire                      o_DxValid;
  output wire                      o_bussy;
  //////////////////////////////////////////////////////////////////////////////
  // Registers and wires
  //////////////////////////////////////////////////////////////////////////////
  reg  signed [(WIDTH-1):0] r_datax;
  reg  signed [(WIDTH-1):0] r_datay;
  reg  signed [(WIDTH-1):0] r_DyOp1; //First operand
  reg  signed [(WIDTH-1):0] r_DyOp2; //Second operand
  reg  signed [(WIDTH-1):0] r_DyOp0; //First Column operand
  reg  signed [(WIDTH-1):0] r_OutFIFO; //
  reg         [(ADD_W-1):0] counter;
  reg         [(ADD_W-1):0] w_DxAddr;
  reg         [(l-1):0]     column_counter;
  reg         [(l-1):0]     fifo_counter;
  reg                       counter_en;
  reg                       column_en;
  reg                       r_DyValid;
  reg                       r_DxValid;
  reg                       DyOp1_en;
  reg                       DyOp2_en;
  reg                       datay_en;
  reg                       datax_en;
  reg                       FIFO_wr;
  reg                       FIFO_rd;
  reg                       r_bussy;
  wire                      full_FIFO;
  wire signed [(WIDTH-1):0] w_op1; //First operand multiplexor


  always @ (posedge i_clk) begin
    if(DyOp1_en)
      r_DyOp1 <= i_data;
  end
  always @ (posedge i_clk) begin
    if(&column_counter) //column_counter == 0;
      r_DyOp0 <= r_DyOp1;
  end
  always @ (posedge i_clk) begin
    if(DyOp2_en)
      r_DyOp2 <= r_DyOp1;
  end
  /// To Do:
  //        * El IDLE debe ser mas un reset de los conadores y del FIFO para el Todo anterior.
 assign FIFO_wr = DyOp2_en;
  fifo  #(.WIDTH(WIDTH), .M_WIDTH(l))
          f0(i_clk, FIFO_wr, r_DyOp1, FIFO_rd,  r_OutFIFO);

  assign w_op1 = (&column_counter) ? r_DyOp0 : r_DyOp1; //column_counter == px-1

  always @ (posedge i_clk) begin
    if(datay_en)
      r_datay <= w_op1-r_DyOp2;
  end
  always @ (posedge i_clk) begin
    if(datax_en)
      r_datax <= r_DyOp1-r_OutFIFO;
  end

  always @ (posedge i_clk) begin
    if (counter_en) begin
      counter <= counter+1;
    end
  end
  always @ (posedge i_clk) begin
    if (column_en) begin
      column_counter <= column_counter+1;
    end
  end
  always @ (posedge i_clk) begin
    if (DyOp1_en) begin
      fifo_counter <= fifo_counter+1;
    end
  end
  assign full_FIFO = &fifo_counter; //column_counter start one clock cycle before the fifo_wr signal and can predict the full_fifo signal.
  always @ (posedge i_clk) begin
    if (datax_en) begin
      w_DxAddr <= w_DxAddr+1;
    end
  end
  //////////////////////////////////////////////////////////////////////////////
  // Control (FSM)
  //////////////////////////////////////////////////////////////////////////////
  localparam IDLE  = 4'b0000; //IDLE state
  localparam S1    = 4'b0001; //Save Input 1 **(Dy)**
  localparam S2    = 4'b0010; //Save Input 2 **(Dy)** and Write FIFO
  localparam S3    = 4'b0011; //Write FIFO
  localparam S4    = 4'b0100; //Read FIFO
  localparam S5    = 4'b0101; //Save Input 2 **(Dx)**
  localparam S6    = 4'b0110; //Wait and save results
  localparam S7    = 4'b0111; //Save last Input 2 **(Dy)**
  localparam S8    = 4'b1000; //Save last Result **(Dy)**
  localparam S9    = 4'b1001; //Wait And save results
  localparam S10   = 4'b1010; //Save last Input 2 (Dx)
  localparam S11   = 4'b1011; //Save last Result (Dx)
  localparam S12   = 4'b1100; //Save last Result (Dx)
  reg [3:0] state = IDLE;
  always @(posedge i_clk)
    if (i_reset) begin
      state <= IDLE;
    end
    else
      case (state)
        IDLE : begin
          if (i_start)
            state <= S1;
          else
            state <= IDLE;
        end
        S1 : begin
            state <= S2;
        end
        S2 : begin
            state <= S3;
        end
        S3 : begin
          state <= S4;
        end
        S4 : begin
          if (full_FIFO)
            state <= S5;
          else
            state <= S4;
        end
        S5 : begin
          state <= S6;
        end
        S6 : begin
          state <= S7;
        end
        S7 : begin
          if (&counter)
            state <= S8;
          else
            state <= S7;
        end
        S8 : begin
          state <= S9;
        end
        S9 : begin
          state <= S10;
        end
        S10 : begin
          if (&column_counter)
            state <= S11;
          else
            state <= S10;
        end
        S11 : begin
          state <= S12;
        end
        S12 : begin
          state <= IDLE;
        end
        default : begin  // Fault Recovery
          state <= IDLE;
        end
      endcase
/* verilator lint_off COMBDLY */
  always @(*)
    case (state)
      IDLE : begin
        r_bussy    <= 1'b0;
        counter_en <= 1'b0;
        column_en  <= 1'b0;
        DyOp1_en   <= 1'b0;
        DyOp2_en   <= 1'b0;
        datay_en   <= 1'b0;
        datax_en   <= 1'b0;
        FIFO_rd    <= 1'b0;
      end
      S1 : begin
        r_bussy    <= 1'b1;
        counter_en <= 1'b1;
        column_en  <= 1'b0;
        DyOp1_en   <= 1'b0;
        DyOp2_en   <= 1'b0;
        datay_en   <= 1'b0;
        datax_en   <= 1'b0;
        FIFO_rd    <= 1'b0;
      end
      S2 : begin
        r_bussy    <= 1'b1;
        counter_en <= 1'b1;
        column_en  <= 1'b0;
        DyOp1_en   <= 1'b1;
        DyOp2_en   <= 1'b0;
        datay_en   <= 1'b0;
        datax_en   <= 1'b0;
        FIFO_rd    <= 1'b0;
      end
      S3 : begin
        r_bussy    <= 1'b1;
        counter_en <= 1'b1;
        column_en  <= 1'b0;
        DyOp1_en   <= 1'b1;
        DyOp2_en   <= 1'b1;
        datay_en   <= 1'b0;
        datax_en   <= 1'b0;
        FIFO_rd    <= 1'b0;
      end
      S4 : begin
        r_bussy    <= 1'b1;
        counter_en <= 1'b1;
        column_en  <= 1'b1;
        DyOp1_en   <= 1'b1;
        DyOp2_en   <= 1'b1;
        datay_en   <= 1'b1;
        datax_en   <= 1'b0;
        FIFO_rd    <= 1'b0;
      end
      S5 : begin
        r_bussy    <= 1'b1;
        counter_en <= 1'b1;
        column_en  <= 1'b1;
        DyOp1_en   <= 1'b1;
        DyOp2_en   <= 1'b1;
        datay_en   <= 1'b1;
        datax_en   <= 1'b0;
        FIFO_rd    <= 1'b1;
      end
      S6 : begin
        r_bussy    <= 1'b1;
        counter_en <= 1'b1;
        column_en  <= 1'b1;
        DyOp1_en   <= 1'b1;
        DyOp2_en   <= 1'b1;
        datay_en   <= 1'b1;
        datax_en   <= 1'b1;
        FIFO_rd    <= 1'b1;
      end
      S7 : begin
        r_bussy    <= 1'b1;
        counter_en <= 1'b1;
        column_en  <= 1'b1;
        DyOp1_en   <= 1'b1;
        DyOp2_en   <= 1'b1;
        datay_en   <= 1'b1;
        datax_en   <= 1'b1;
        FIFO_rd    <= 1'b1;
      end
      S8 : begin
        r_bussy    <= 1'b1;
        counter_en <= 1'b1;
        column_en  <= 1'b1;
        DyOp1_en   <= 1'b1;
        DyOp2_en   <= 1'b1;
        datay_en   <= 1'b1;
        datax_en   <= 1'b1;
        FIFO_rd    <= 1'b1;
      end
      S9 : begin
        r_bussy    <= 1'b1;
        counter_en <= 1'b1;
        column_en  <= 1'b1;
        DyOp1_en   <= 1'b1;
        DyOp2_en   <= 1'b0;
        datay_en   <= 1'b1;
        datax_en   <= 1'b1;
        FIFO_rd    <= 1'b1;
      end
      S10 : begin
        r_bussy    <= 1'b1;
        counter_en <= 1'b1;
        column_en  <= 1'b1;
        DyOp1_en   <= 1'b1;
        DyOp2_en   <= 1'b0;
        datay_en   <= 1'b0;
        datax_en   <= 1'b1;
        FIFO_rd    <= 1'b1;
      end
      S11 : begin
        r_bussy    <= 1'b1;
        counter_en <= 1'b0;
        column_en  <= 1'b0;
        DyOp1_en   <= 1'b0;
        DyOp2_en   <= 1'b0;
        datay_en   <= 1'b0;
        datax_en   <= 1'b1;
        FIFO_rd    <= 1'b1;
      end
      S12 : begin
        r_bussy    <= 1'b1;
        counter_en <= 1'b0;
        column_en  <= 1'b0;
        DyOp1_en   <= 1'b0;
        DyOp2_en   <= 1'b0;
        datay_en   <= 1'b0;
        datax_en   <= 1'b1;
        FIFO_rd    <= 1'b0;
      end
      default : begin
        r_bussy    <= 1'b0;
        counter_en <= 1'b0;
        column_en  <= 1'b0;
        DyOp1_en   <= 1'b0;
        DyOp2_en   <= 1'b0;
        datay_en   <= 1'b0;
        datax_en   <= 1'b0;
        FIFO_rd    <= 1'b0;
      end
    endcase
/* verilator lint_on COMBDLY */
  always @ (posedge i_clk) begin
    r_DyValid <= datay_en;
    r_DxValid <= datax_en;
  end
  //////////////////////////////////////////////////////////////////////////////
  // Output logic
  //////////////////////////////////////////////////////////////////////////////
  assign o_datax   = r_datax;
  assign o_datay   = r_datay;
  assign o_address = counter;
  assign o_Dx_addr = w_DxAddr;
  assign o_DyValid = r_DyValid;
  assign o_DxValid = r_DxValid;
  assign o_bussy   = r_bussy;

endmodule // diff_2d
