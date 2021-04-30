module dive2d (i_clk, i_reset, i_datax, i_datay, i_start, o_read, o_data, o_address, o_valid, o_bussy);
  parameter WIDTH = 32, ADD_W = 12;
  localparam l = 6; //log2(px); px =64
  localparam BANKW = 32*64; //log2(px); px =64
  input  wire                      i_clk;
  input  wire                      i_reset;
  input  wire signed [(WIDTH-1):0] i_datax;
  input  wire signed [(WIDTH-1):0] i_datay;
  input  wire                      i_start;
  output wire                      o_read;
  output wire signed [(WIDTH-1):0] o_data;
  output wire signed [(ADD_W-1):0] o_address;
  output wire                      o_valid;
  output wire                      o_bussy;
  //////////////////////////////////////////////////////////////////////////////
  // Registers and wires
  //////////////////////////////////////////////////////////////////////////////
  reg  signed [(WIDTH-1):0] r_datax; //Dx
  reg  signed [(WIDTH-1):0] r_datay; //Dy
  reg  signed [(WIDTH-1):0] r_outx; //Dx
  reg  signed [(WIDTH-1):0] r_outy; //Dy
  reg  signed [(WIDTH-1):0] r_DyOp1; //First operand Dy
  reg  signed [(WIDTH-1):0] r_DyOp2; //Second operand Dy
  reg  signed [(WIDTH-1):0] r_DyOp0; //First Column operand Dy
  reg  signed [(WIDTH-1):0] r_DxOp1; //First operand Dx
  wire signed [(WIDTH-1):0] r_OutFIFO; //Second operand Dx
  reg         [(BANKW-1):0] Bank_y; //register bank for Dy result
  reg         [(BANKW-1):0] Bank_x; //register bank for Dx result
  reg         [64:0]        Bank_valid; //register bank for Dx result
  reg         [ADD_W:0]     counter;
  reg         [(ADD_W-1):0] w_address;
  reg         [(l-1):0]     column_counter;
  reg         [(l-1):0]     fifo_counter;
  reg                       counter_en;
  reg                       r_maxcolum;
  reg                       column_en;
  reg                       r_Valid;
  reg                       DyOp1_en;
  reg                       DyOp2_en;
  reg                       DxOp1_en;
  reg                       datay_en;
  reg                       datax_en;
  wire                      FIFO_wr;
  reg                       FIFO_rd;
  reg                       save_Op0; //first Op0 value
  reg                       r_bussy;
  wire                      full_FIFO;
  wire signed [(WIDTH-1):0] w_op1; //First operand multiplexor

  initial counter        = 0;
  initial fifo_counter   = 0;
  initial column_counter = 0;

  always @ (posedge i_clk) begin
    if(DyOp1_en)
      r_DyOp1 <= i_datay;
  end
  always @ (posedge i_clk) begin
    if(DxOp1_en)
      r_DxOp1 <= i_datax;
  end
  always @ (posedge i_clk) begin
    if(&column_counter|save_Op0) //column_counter == px-1;
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
          f0(i_clk, FIFO_wr, r_DxOp1, FIFO_rd,  r_OutFIFO);

  assign w_op1 = (&column_counter) ? r_DyOp0 : r_DyOp1; //column_counter == px-1

  always @ (posedge i_clk) begin
    if(datay_en)
      r_datay <= r_DyOp2 - w_op1;
  end
  always @ (posedge i_clk) begin
    if(datax_en)
      r_datax <= r_OutFIFO-r_DxOp1;
  end
  // registe banks
  always @ (posedge i_clk) begin
    Bank_y     <= {Bank_y[(63*WIDTH)-1:0],r_datay};
    Bank_x     <= {Bank_x[(63*WIDTH)-1:0],r_datax};
    Bank_valid <= {Bank_valid[63:0],datax_en};
  end
  //
  always @ (posedge i_clk) begin
    r_outx <= Bank_x[(BANKW-1):BANKW-WIDTH];
  end
  always @ (posedge i_clk) begin
    r_maxcolum <= &(column_counter);
  end
  always @ (posedge i_clk) begin
    if (r_maxcolum)
      r_outy <= r_datay;
    else //column_counter == 0
      r_outy <= Bank_y[(BANKW-1):BANKW-WIDTH];
  end
  //
  always @ (posedge i_clk) begin
    if(r_Valid)
      w_address <= w_address+1;
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
    if (DxOp1_en) begin
      fifo_counter <= fifo_counter+1;
    end
  end
  assign full_FIFO = &fifo_counter; //column_counter start one clock cycle before the fifo_wr signal and can predict the full_fifo signal.

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
          if (counter[ADD_W])
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
          if (&fifo_counter)
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
        DxOp1_en   <= 1'b0;
        DxOp1_en   <= 1'b0;
        save_Op0   <= 1'b0;
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
        DxOp1_en   <= 1'b0;
        save_Op0   <= 1'b0;
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
        DxOp1_en   <= 1'b1;
        save_Op0   <= 1'b0;
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
        DxOp1_en   <= 1'b1;
        save_Op0   <= 1'b1;
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
        DxOp1_en   <= 1'b1;
        save_Op0   <= 1'b0;
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
        DxOp1_en   <= 1'b1;
        save_Op0   <= 1'b0;
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
        DxOp1_en   <= 1'b1;
        save_Op0   <= 1'b0;
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
        DxOp1_en   <= 1'b1;
        save_Op0   <= 1'b0;
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
        DxOp1_en   <= 1'b1;
        save_Op0   <= 1'b0;
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
        DxOp1_en   <= 1'b1;
        save_Op0   <= 1'b0;
        DyOp2_en   <= 1'b1;
        datay_en   <= 1'b1;
        datax_en   <= 1'b1;
        FIFO_rd    <= 1'b1;
      end
      S10 : begin
        r_bussy    <= 1'b1;
        counter_en <= 1'b1;
        column_en  <= 1'b1;
        DyOp1_en   <= 1'b1;
        DxOp1_en   <= 1'b1;
        save_Op0   <= 1'b0;
        DyOp2_en   <= 1'b1;
        datay_en   <= 1'b1;
        datax_en   <= 1'b1;
        FIFO_rd    <= 1'b1;
      end
      S11 : begin
        r_bussy    <= 1'b1;
        counter_en <= 1'b0;
        column_en  <= 1'b1;
        DyOp1_en   <= 1'b0;
        DxOp1_en   <= 1'b0;
        save_Op0   <= 1'b0;
        DyOp2_en   <= 1'b1;
        datay_en   <= 1'b1;
        datax_en   <= 1'b1;
        FIFO_rd    <= 1'b1;
      end
      S12 : begin
        r_bussy    <= 1'b1;
        counter_en <= 1'b0;
        column_en  <= 1'b1;
        DyOp1_en   <= 1'b0;
        DxOp1_en   <= 1'b0;
        save_Op0   <= 1'b0;
        DyOp2_en   <= 1'b0;
        datay_en   <= 1'b1;
        datax_en   <= 1'b0;
        FIFO_rd    <= 1'b0;
      end
      default : begin
        r_bussy    <= 1'b0;
        counter_en <= 1'b0;
        column_en  <= 1'b0;
        DyOp1_en   <= 1'b0;
        DxOp1_en   <= 1'b0;
        save_Op0   <= 1'b0;
        DyOp2_en   <= 1'b0;
        datay_en   <= 1'b0;
        datax_en   <= 1'b0;
        FIFO_rd    <= 1'b0;
      end
    endcase
/* verilator lint_on COMBDLY */
  always @ (posedge i_clk) begin
    r_Valid <= Bank_valid[64];
  end
  //////////////////////////////////////////////////////////////////////////////
  // Output logic
  //////////////////////////////////////////////////////////////////////////////
  assign o_data   = r_outx + r_outy;
  assign o_address = w_address + 12'b000001000000;
  assign o_valid  = r_Valid;
  assign o_bussy  = r_bussy;
  assign o_read   = counter_en;

endmodule // diff_2d
