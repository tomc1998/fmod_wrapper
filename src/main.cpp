#include <iostream>

#include "fmod_error_util.hpp"
#include "bank_manager.hpp"
#include "fmod_system.hpp"

int main(int argc, char** argv) {
  try {
    init_fmod_system();
    bank_manager::instance().load("test-banks/Desktop/Master Bank.strings.bank");
    bank* master = bank_manager::instance().load("test-banks/Desktop/Master Bank.bank");
  } catch (fmod_exception e) {
    std::cerr << "FMOD Exception: " << e.message << std::endl;
  }
  return 0;
}
