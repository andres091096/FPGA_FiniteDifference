module rom(
    input  wire         clk,
    input  wire  [11:0] addr,
    output reg   [31:0] data
    );

    reg [31:0] memory [4095:0];

    initial begin
        $display("Creating rom_sync from init file '%s'.", "U_fixed_point.mem");
        $readmemh("U_fixed_point.mem", memory);
    end

    always @(posedge clk) begin
        data <= memory[addr];
    end
endmodule
