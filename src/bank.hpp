#pragma once

#include <string>

namespace FMOD {
  namespace Studio {
    class Bank;
  }
}

struct bank {
  /** Instance of the fmod bank object */
  FMOD::Studio::Bank* fmod_bank;
  std::string path;
};
