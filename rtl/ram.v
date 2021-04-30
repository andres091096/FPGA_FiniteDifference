// MIT License
//
// Copyright (c) 2021 Instituto Nacional de Astrofísica, Óptica y Electrónica.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
////////////////////////////////////////////////////////////////////////////////
`default_nettype	none
module ram(i_clk, i_we, i_data, i_addr_rd, i_addr_wr, o_data);
  parameter WIDTH = 32, ADDR_WIDTH = 12;
  localparam integer RAM_DEPTH     = 2**(ADDR_WIDTH);

  input  wire                  i_clk;        //clock signal
  input  wire                  i_we;         //write enable
  input  wire [WIDTH-1:0]      i_data;       //data to be written
  input  wire [ADDR_WIDTH-1:0] i_addr_rd;    //address
  input  wire [ADDR_WIDTH-1:0] i_addr_wr;    //address
  output wire [WIDTH-1:0]      o_data;       //read data
  //memory declaration.
  reg [WIDTH-1:0] mem[0:RAM_DEPTH-1];
  initial begin
        $readmemh("ram_zeros.mem", mem);
    end
  always @(posedge i_clk) begin
    if (i_we)
      mem[i_addr_wr] <= i_data;
  end

  assign  o_data = mem[i_addr_rd];

endmodule
