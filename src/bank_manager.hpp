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

  /** Get a bank based on the bank path, or null if not found. A bank path is
      "bank:/" followed by the file name, minus the .bank. For example, for the bank
      'asserts/banks/master-bank.bank', the path would be 'bank:/master-bank'. */
  bank* get(const char* bank_path);

  /** Unload a bank */
  void unload(const char* bank_path);

  /** Returns a pointer to the bank if loaded, or null for a failure (error
      printed to console). */
  bank* load(const char* path);
};
