`timescale 1ns / 1ps
module tb_counter;
  top_wrap_sc_module_0_if itf ();
  TopWrap_sc_module_0 dut (itf);
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
  // monitor
  always @(posedge itf.clk) begin
    $display("%0t,%0d", $time, itf.q);
  end
  initial begin
    // run for 20 cycles
    #200;
    $finish;
  end
endmodule
