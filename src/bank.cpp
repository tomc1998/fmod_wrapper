#include <vector>

#include <iostream>
#include <fmod.hpp>
#include <fmod_studio.hpp>
#include "fmod_error_util.hpp"
#include "bank.hpp"

bank::bank(FMOD::Studio::Bank* fmod_bank)
  : fmod_bank(fmod_bank) {
  int num_events;
  check_err(fmod_bank->getEventCount(&num_events));
  std::cout << "Num events = " << num_events << std::endl;
  if (num_events > 0) {
    std::vector<FMOD::Studio::EventDescription*> event_descriptions(num_events);
    check_err(fmod_bank->getEventList(event_descriptions.data(), num_events, &num_events));

    for (int ii = 0; ii < num_events; ++ii) {
      // Get the event name
      int name_len;
      check_err(event_descriptions[ii]->getPath(nullptr, 0, &name_len));
      char* name_chars = new char[name_len];
      check_err(event_descriptions[ii]->getPath(name_chars, name_len, nullptr));
      std::string name(name_chars);
      delete[] name_chars;
      std::cout << "Event name = " << name << std::endl;
      event_map.insert(std::make_pair(name, event { event_descriptions[ii], name }));
    }
  }
}

event* bank::load_event(const char* path) {
  const auto cached = event_map.find(path);
  return (cached != event_map.end()) ? &cached->second : nullptr;
}
