#pragma once

#include <string>
#include "event_instance.hpp"

namespace FMOD {
  namespace Studio {
    class EventDescription;
  }
}

/**
   Models FMOD event descriptions
*/
struct event {
  FMOD::Studio::EventDescription* fmod_bank;
  std::string path;

  event_instance instance();
};
