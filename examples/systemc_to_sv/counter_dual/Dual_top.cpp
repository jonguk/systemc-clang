#include "/home/jonguk/Projects/CXL_SWITCH/systemc-clang/examples/systemc_to_sv/counter/Counter.h"
#include <systemc>

SC_MODULE(TopWrap2) {

  sc_core::sc_in<bool> clk{"clk"};
  sc_core::sc_in<bool> reset_n{"reset_n"};
  sc_core::sc_in<bool> en{"en"};
  sc_core::sc_out<sc_dt::sc_uint<8>> q0{"q0"};
  sc_core::sc_out<sc_dt::sc_uint<8>> q1{"q1"};

  Counter<8> u0{"u0"};
  Counter<8> u1{"u1"};

  SC_CTOR(TopWrap2) {
    u0.clk(clk); u0.reset_n(reset_n); u0.en(en); u0.q(q0);
    u1.clk(clk); u1.reset_n(reset_n); u1.en(en); u1.q(q1);
  }
};

int sc_main(int argc, char* argv[]) {
  sc_core::sc_clock clk{"clk", sc_core::sc_time(10, sc_core::SC_NS)};
  sc_core::sc_signal<bool> reset_n{"reset_n"};
  sc_core::sc_signal<bool> en{"en"};
  sc_core::sc_signal<sc_dt::sc_uint<8>> q0{"q0"};
  sc_core::sc_signal<sc_dt::sc_uint<8>> q1{"q1"};

  TopWrap2 top{"top2"};
  top.clk(clk); top.reset_n(reset_n); top.en(en); top.q0(q0); top.q1(q1);

  sc_core::sc_start(sc_core::SC_ZERO_TIME);
  // Reset deassert late then run
  reset_n = false; en = false; sc_core::sc_start(sc_core::sc_time(20, sc_core::SC_NS));
  reset_n = true; en = true; sc_core::sc_start(sc_core::sc_time(200, sc_core::SC_NS));

  return 0;
}
