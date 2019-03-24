/** For getting and creating the fmod system */

#pragma once

#include <fmod.hpp>
#include <fmod_studio.hpp>

/** Initialise the fmod system */
void init_fmod_system();

/** Get the fmod system - asserts if not initialised */
FMOD::Studio::System* get_fmod_system();
