#pragma once
#include <systemc>

// Parameterizable, synthesizable counter with enable and active-low synchronous reset.
// - Increments when 'en' is high on each rising clock edge
// - Resets to 0 when 'reset_n' is deasserted (low)
// - Drives 'q' each cycle

template <int WIDTH = 8>
SC_MODULE(Counter) {
  sc_core::sc_in<bool> clk{"clk"};
  sc_core::sc_in<bool> reset_n{"reset_n"};
  sc_core::sc_in<bool> en{"en"};
  sc_core::sc_out<sc_dt::sc_uint<WIDTH>> q{"q"};

  // Internal state
  sc_dt::sc_uint<WIDTH> counter_value{};

  SC_CTOR(Counter) {
    SC_CTHREAD(run, clk.pos());
  }

  void run() {
    counter_value = 0;
    q.write(counter_value);
    wait();

    while (true) {
      if (!reset_n.read()) {
        counter_value = 0;
      } else if (en.read()) {
        counter_value = counter_value + 1;
      }
      q.write(counter_value);
      wait();
    }
  }
};
