`timescale 1ns / 1ps
module tb_counter2;
  top_wrap2_sc_module_0_if itf ();
  TopWrap2_sc_module_0 dut (itf);
  // clock
  initial itf.clk = 0;
  always #5 itf.clk = ~itf.clk;
  // stimulus
  initial begin
    itf.reset_n = 0;
    itf.en = 0;
    #20;  // 2 cycles
    itf.reset_n = 1;
    itf.en = 1;
  end
  // monitor two outputs
  always @(posedge itf.clk) begin
    $display("%0t,%0d,%0d", $time, itf.q0, itf.q1);
  end
  initial begin
    #200;
    $finish;
  end
endmodule
