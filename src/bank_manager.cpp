#include <iostream>
#include <utility>
#include "bank.hpp"
#include "bank_manager.hpp"
#include "fmod_error_util.hpp"
#include "fmod_system.hpp"

bank_manager* bank_manager_instance = nullptr;

bank_manager::bank_manager() {}

bank_manager& bank_manager::instance() {
  if (!bank_manager_instance) {
    bank_manager_instance = new bank_manager();
  }
  return *bank_manager_instance;
}

bank* bank_manager::load(const char* path) {
  const auto cached = bank_map.find(path);
  if (cached != bank_map.end()) {
    return &cached->second;
  }
  const auto system = get_fmod_system();
  FMOD::Studio::Bank* fmod_bank = nullptr;
  check_err(system->loadBankFile(path, FMOD_STUDIO_LOAD_BANK_NORMAL, &fmod_bank));

  // make the bank & insert
  bank b { fmod_bank };
  return &bank_map.insert(std::make_pair(std::string(path), std::move(b))).first->second;
}
