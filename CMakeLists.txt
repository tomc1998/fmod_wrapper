cmake_minimum_required (VERSION 3.0)
project(fmod-wrapper)

set (CMAKE_C_COMPILER gcc)
set (CMAKE_CXX_COMPILER g++)

set (root-dir ${CMAKE_CURRENT_SOURCE_DIR})
set (src-dir ${root-dir}/src)

set (fmod-wrapper-srcs
  ${src-dir}/main.cpp
  ${src-dir}/bank_manager.cpp
  ${src-dir}/bank.cpp
  ${src-dir}/event.cpp
  ${src-dir}/event_instance.cpp
  ${src-dir}/fmod_system.cpp
  )

link_directories(/usr/local/lib ${root-dir}/lib/fmod)

# Build the executable
add_executable(fmod-wrapper ${fmod-wrapper-srcs})

# Setup include directories for the exe
set (fmod-wrapper-idir ${root-dir}/include/fmod)
target_include_directories(fmod-wrapper PUBLIC ${fmod-wrapper-idir})

# Link against any libraries
target_link_libraries(fmod-wrapper fmod fmodL fmodstudio fmodstudioL)

# Figure out per-platform compiler flags
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  set (CMAKE_CXX_FLAGS "--std=c++14 -Wall -g -O3 -Wno-pragma-once-outside-header")
endif()

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang")
  set (CMAKE_CXX_FLAGS "-std=c++14 -Wall -g -O3 -Wno-pragma-once-outside-header")
endif()

