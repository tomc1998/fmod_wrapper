#include <cassert>
#include "fmod_system.hpp"
#include "fmod_error_util.hpp"

FMOD::Studio::System* fmod_system = nullptr;

void init_fmod_system() {
  check_err(FMOD::Studio::System::create(&fmod_system)); // Create the Studio System object.

  // Initialise the low level fmod_system - not sure if we need this, found in the FMOD examples
  // TODO Check whether this is needed
  FMOD::System* lowLevelSystem = NULL;
  check_err(fmod_system->getLowLevelSystem(&lowLevelSystem) );
  check_err(lowLevelSystem->setSoftwareFormat(0, FMOD_SPEAKERMODE_5POINT1, 0) );

  // Initialize FMOD Studio, which will also initialize FMOD Low Level
  check_err(fmod_system->initialize(512, FMOD_STUDIO_INIT_NORMAL, FMOD_INIT_NORMAL, 0));
}

FMOD::Studio::System* get_fmod_system() {
  assert(fmod_system != nullptr);
  return fmod_system;
}
