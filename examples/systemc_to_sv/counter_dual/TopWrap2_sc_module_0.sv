interface top_wrap2_sc_module_0_if;
  logic [0:0] clk;
  logic [0:0] reset_n;
  logic [0:0] en;
  logic [7:0] q0;
  logic [7:0] q1;
  modport port0(
    input clk,reset_n,en,
    output q0,q1
  );
endinterface

interface counter_sc_module_1_if;
  logic [0:0] clk;
  logic [0:0] reset_n;
  logic [0:0] en;
  logic [7:0] q;
  modport port0(
    input clk,reset_n,en,
    output q
  );
endinterface

interface counter_sc_module_2_if;
  logic [0:0] clk;
  logic [0:0] reset_n;
  logic [0:0] en;
  logic [7:0] q;
  modport port0(
    input clk,reset_n,en,
    output q
  );
endinterface

module TopWrap2_sc_module_0 (
 top_wrap2_sc_module_0_if.port0 itf
);
  initial begin

  end
  counter_sc_module_1_if u0_itf();

  Counter_sc_module_1 u0(
    u0_itf
  );
    assign u0_itf.clk = itf.clk;
    assign u0_itf.reset_n = itf.reset_n;
    assign u0_itf.en = itf.en;
    assign itf.q0 = u0_itf.q;
  always_comb begin
  end

  counter_sc_module_2_if u1_itf();

  Counter_sc_module_2 u1(
    u1_itf
  );
    assign u1_itf.clk = itf.clk;
    assign u1_itf.reset_n = itf.reset_n;
    assign u1_itf.en = itf.en;
    assign itf.q1 = u1_itf.q;
  always_comb begin
  end

endmodule
module Counter_sc_module_1 (
 counter_sc_module_1_if.port0 itf
);
  logic [7:0] counter_value_scclang_global_0;
  logic signed[31:0] state_run;
  logic signed[31:0] _next_state_run;
  logic signed[31:0] wait_counter_run;
  logic signed[31:0] _next_wait_counter_run;
  logic signed[31:0] wait_next_state_run;
  logic signed[31:0] _next_wait_next_state_run;
  logic [7:0] _main_counter_value_scclang_global_0;
  // Thread: run
  always @(posedge itf.clk) begin: run_state_update
    if (!itf.reset_n) begin
      state_run <= (0);
      wait_next_state_run <= (0);
      wait_counter_run <= (0);
      _main_counter_value_scclang_global_0 <= (0);
    end else begin
      state_run <= (_next_state_run);
      wait_counter_run <= (_next_wait_counter_run);
      wait_next_state_run <= (_next_wait_next_state_run);
      _main_counter_value_scclang_global_0 <= (counter_value_scclang_global_0);
    end

  end
  function automatic void run_func ();
  begin

    unique case(state_run)
      0: begin
        counter_value_scclang_global_0 = 0;
        itf.q = counter_value_scclang_global_0;
        _next_state_run = 1;
        return;
      end
      1: begin
        if (1) begin
        end
        if (!(itf.reset_n)) begin
          counter_value_scclang_global_0 = 0;
          itf.q = counter_value_scclang_global_0;
          _next_state_run = 2;
          return;
        end else begin
          if (itf.en) begin
            counter_value_scclang_global_0 = (counter_value_scclang_global_0) + (1);
            itf.q = counter_value_scclang_global_0;
            _next_state_run = 2;
            return;
          end else begin
            itf.q = counter_value_scclang_global_0;
            _next_state_run = 2;
            return;
          end

        end

      end
      2: begin
        if (1) begin
        end
        if (!(itf.reset_n)) begin
          counter_value_scclang_global_0 = 0;
          itf.q = counter_value_scclang_global_0;
          _next_state_run = 2;
          return;
        end else begin
          if (itf.en) begin
            counter_value_scclang_global_0 = (counter_value_scclang_global_0) + (1);
            itf.q = counter_value_scclang_global_0;
            _next_state_run = 2;
            return;
          end else begin
            itf.q = counter_value_scclang_global_0;
            _next_state_run = 2;
            return;
          end

        end

      end
    endcase
  end
  endfunction
  always_comb begin: run
  logic signed[31:0] __tmp_next_state_run;
  logic signed[31:0] __tmp_next_wait_counter_run;
  logic signed[31:0] __tmp_next_wait_next_state_run;
  logic [7:0] __tmp_counter_value_scclang_global_0;
  __tmp_next_state_run = state_run;
  __tmp_next_wait_counter_run = wait_counter_run;
  __tmp_next_wait_next_state_run = wait_next_state_run;
  __tmp_counter_value_scclang_global_0 = counter_value_scclang_global_0;
__tmp_next_state_run = state_run;
__tmp_next_wait_counter_run = wait_counter_run;
__tmp_next_wait_next_state_run = wait_next_state_run;
__tmp_counter_value_scclang_global_0 = _main_counter_value_scclang_global_0;
    run_func();
  end
endmodule
module Counter_sc_module_2 (
 counter_sc_module_2_if.port0 itf
);
  logic [7:0] counter_value_scclang_global_0;
  logic signed[31:0] state_run;
  logic signed[31:0] _next_state_run;
  logic signed[31:0] wait_counter_run;
  logic signed[31:0] _next_wait_counter_run;
  logic signed[31:0] wait_next_state_run;
  logic signed[31:0] _next_wait_next_state_run;
  logic [7:0] _main_counter_value_scclang_global_0;
  // Thread: run
  always @(posedge itf.clk) begin: run_state_update
    if (!itf.reset_n) begin
      state_run <= (0);
      wait_next_state_run <= (0);
      wait_counter_run <= (0);
      _main_counter_value_scclang_global_0 <= (0);
    end else begin
      state_run <= (_next_state_run);
      wait_counter_run <= (_next_wait_counter_run);
      wait_next_state_run <= (_next_wait_next_state_run);
      _main_counter_value_scclang_global_0 <= (counter_value_scclang_global_0);
    end

  end
  function automatic void run_func ();
  begin

    unique case(state_run)
      0: begin
        counter_value_scclang_global_0 = 0;
        itf.q = counter_value_scclang_global_0;
        _next_state_run = 1;
        return;
      end
      1: begin
        if (1) begin
        end
        if (!(itf.reset_n)) begin
          counter_value_scclang_global_0 = 0;
          itf.q = counter_value_scclang_global_0;
          _next_state_run = 2;
          return;
        end else begin
          if (itf.en) begin
            counter_value_scclang_global_0 = (counter_value_scclang_global_0) + (1);
            itf.q = counter_value_scclang_global_0;
            _next_state_run = 2;
            return;
          end else begin
            itf.q = counter_value_scclang_global_0;
            _next_state_run = 2;
            return;
          end

        end

      end
      2: begin
        if (1) begin
        end
        if (!(itf.reset_n)) begin
          counter_value_scclang_global_0 = 0;
          itf.q = counter_value_scclang_global_0;
          _next_state_run = 2;
          return;
        end else begin
          if (itf.en) begin
            counter_value_scclang_global_0 = (counter_value_scclang_global_0) + (1);
            itf.q = counter_value_scclang_global_0;
            _next_state_run = 2;
            return;
          end else begin
            itf.q = counter_value_scclang_global_0;
            _next_state_run = 2;
            return;
          end

        end

      end
    endcase
  end
  endfunction
  always_comb begin: run
  logic signed[31:0] __tmp_next_state_run;
  logic signed[31:0] __tmp_next_wait_counter_run;
  logic signed[31:0] __tmp_next_wait_next_state_run;
  logic [7:0] __tmp_counter_value_scclang_global_0;
  __tmp_next_state_run = state_run;
  __tmp_next_wait_counter_run = wait_counter_run;
  __tmp_next_wait_next_state_run = wait_next_state_run;
  __tmp_counter_value_scclang_global_0 = counter_value_scclang_global_0;
__tmp_next_state_run = state_run;
__tmp_next_wait_counter_run = wait_counter_run;
__tmp_next_wait_next_state_run = wait_next_state_run;
__tmp_counter_value_scclang_global_0 = _main_counter_value_scclang_global_0;
    run_func();
  end
endmodule