#define PRINT_Q_ON_POSEDGE
#include "Counter.h"
#include <systemc>

// Minimal TU for systemc-clang HDL extraction: instantiate the module.
SC_MODULE(TopWrap) {
  void sample_q(){ std::cout << sc_core::sc_time_stamp() << "," << q.read() << std::endl; }
  sc_core::sc_in<bool> clk{"clk"};
  sc_core::sc_in<bool> reset_n{"reset_n"};
  sc_core::sc_in<bool> en{"en"};
  sc_core::sc_out<sc_dt::sc_uint<8>> q{"q"};

  Counter<8> u_counter{"u_counter"};

  SC_CTOR(TopWrap) {
    SC_METHOD(sample_q); sensitive << clk.pos();
    u_counter.clk(clk);
    u_counter.reset_n(reset_n);
    u_counter.en(en);
    u_counter.q(q);
  }
};

int sc_main(int argc, char* argv[]) {
  sc_core::sc_clock clk{"clk", sc_core::sc_time(10, sc_core::SC_NS)};
  sc_core::sc_signal<bool> reset_n{"reset_n"};
  sc_core::sc_signal<bool> en{"en"};
  sc_core::sc_signal<sc_dt::sc_uint<8>> q{"q"};

  TopWrap top{"top"};
  top.clk(clk);
  top.reset_n(reset_n);
  top.en(en);
  top.q(q);

  sc_core::sc_start(sc_core::SC_ZERO_TIME);
  reset_n = false; en = false; sc_core::sc_start(sc_core::sc_time(20, sc_core::SC_NS));
  reset_n = true; en = true; sc_core::sc_start(sc_core::sc_time(200, sc_core::SC_NS));
  return 0;
}
