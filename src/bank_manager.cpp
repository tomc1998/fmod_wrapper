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
  const auto system = get_fmod_system();
  FMOD::Studio::Bank* fmod_bank = nullptr;
  check_err(system->loadBankFile(path, FMOD_STUDIO_LOAD_BANK_NORMAL, &fmod_bank));

  // Get the path
  int path_len;
  check_err(fmod_bank->getPath(nullptr, 0, &path_len));
  char* path_chars = new char[path_len];
  check_err(fmod_bank->getPath(path_chars, path_len, nullptr));
  std::string bank_path(path_chars);
  delete[] path_chars;

  std::cout << "Bank path = " << bank_path << std::endl;

  // make the bank & insert
  bank b { fmod_bank, bank_path };
  return &bank_map.insert(std::make_pair(std::move(bank_path), std::move(b))).first->second;
}
