module rom#(
    parameter WIDTH=32,
    parameter DEPTH=4096,
    parameter INIT_F="",
    parameter ADDRW=12 //log2(DEPTH)
  )(
    input  wire         clk,
    input  wire  [ADDRW-1:0] addr,
    output reg   [WIDTH-1:0] data
    );

    reg [WIDTH-1:0] memory [DEPTH-1:0];

    initial begin
        $display("Creating rom_sync from init file '%s'.", INIT_F);
        $readmemh(INIT_F, memory);
    end

    always @(posedge clk) begin
        data <= memory[addr];
    end
endmodule
