`timescale 1ns / 1ps
interface top_wrap_sc_module_0_if;
  logic [0:0] clk;
  logic [0:0] reset_n;
  logic [0:0] en;
  logic [7:0] q;
  modport port0(input clk, reset_n, en, output q);
endinterface

interface counter_sc_module_1_if;
  logic [0:0] clk;
  logic [0:0] reset_n;
  logic [0:0] en;
  logic [7:0] q;
  modport port0(input clk, reset_n, en, output q);
endinterface

module TopWrap_sc_module_0 (
    top_wrap_sc_module_0_if.port0 itf
);
  initial begin

  end
  counter_sc_module_1_if u_counter_itf ();

  Counter_sc_module_1 u_counter (u_counter_itf);
  assign u_counter_itf.clk = itf.clk;
  assign u_counter_itf.reset_n = itf.reset_n;
  assign u_counter_itf.en = itf.en;
  assign itf.q = u_counter_itf.q;
  always_comb begin
  end

endmodule
module Counter_sc_module_1 (
    counter_sc_module_1_if.port0 itf
);
  // Simple 2-process FSM with registered outputs
  typedef int state_t;
  state_t state_run, next_state_run;
  logic [7:0] counter_reg, counter_next;

  // Combinational next-state and next-data logic
  always_comb begin
    next_state_run = state_run;
    counter_next   = counter_reg;
    unique case (state_run)
      0: begin
        counter_next   = 0;
        next_state_run = 1;
      end
      1, 2: begin
        if (!itf.reset_n) begin
          counter_next   = 0;
          next_state_run = 2;
        end else if (itf.en) begin
          counter_next   = counter_reg + 1;
          next_state_run = 2;
        end else begin
          next_state_run = 2;
        end
      end
      default: begin
        next_state_run = 0;
        counter_next   = 0;
      end
    endcase
  end

  // Synchronous registers and registered output
  always_ff @(posedge itf.clk) begin
    if (!itf.reset_n) begin
      state_run   <= 0;
      counter_reg <= 0;
      itf.q       <= 0;
    end else begin
      state_run   <= next_state_run;
      counter_reg <= counter_next;
      itf.q       <= counter_next;
    end
  end
endmodule
