#pragma once

#include <fmod_errors.h>
#include <string>

struct fmod_exception {
  const char* message;
};

/** Checks the result, printing it out and throwing an 'fmod_exception' if the
    result is an error. */
inline void check_err(FMOD_RESULT res) {
  if (res != FMOD_OK) {
    throw fmod_exception { FMOD_ErrorString(res) };
  }
}
