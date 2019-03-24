#pragma once

#include "event.hpp"
#include <unordered_map>
#include <string>

namespace FMOD {
  namespace Studio {
    class Bank;
  }
}

struct bank {
  /** Instance of the fmod bank object */
  FMOD::Studio::Bank* fmod_bank;

  std::unordered_map<std::string, event> event_map;

  bank(FMOD::Studio::Bank* fmod_bank);

  /** Load an event description, caching if already loaded */
  event* load_event(const char* path);
};
