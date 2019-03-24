#pragma once

#include "bank.hpp"
#include <unordered_map>
#include <string>

/** Singleton for storing banks */
class bank_manager {
  std::unordered_map<std::string, bank> bank_map;

  bank_manager();

public:

  static bank_manager& instance();

  /** Unload a bank */
  void unload(const char* bank_path);

  /** Returns a pointer to the bank if loaded, or null for a failure (error
      printed to console). Caches, so future calls will load the same bank. */
  bank* load(const char* path);
};
