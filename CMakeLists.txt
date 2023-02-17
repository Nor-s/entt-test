cmake_minimum_required(VERSION 3.21)

message("Using CMake version ${CMAKE_VERSION}")

# for CCACHE
if(APPLE)
  find_program(CCACHE_PROGRAM ccache)
  if(CCACHE_PROGRAM)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
  endif()
endif()

# project setting
project(
  Mina
  LANGUAGES CXX
  VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)

message("CMAKE_RUNTIME_OUTPUT_DIRECTORY : ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message("CMAKE_BINARY_DIR : ${CMAKE_BINARY_DIR}")

# for apple ccache
if(APPLE)
  get_property(RULE_LAUNCH_COMPILE GLOBAL PROPERTY RULE_LAUNCH_COMPILE)
  if(RULE_LAUNCH_COMPILE AND CMAKE_GENERATOR STREQUAL "Xcode")
    # Set up wrapper scripts
    configure_file(launch-c.in launch-c)
    configure_file(launch-cxx.in launch-cxx)
    execute_process(COMMAND chmod a+rx "${CMAKE_BINARY_DIR}/launch-c"
                            "${CMAKE_BINARY_DIR}/launch-cxx")
    # Set Xcode project attributes to route compilation and linking through our
    # scripts
    set(CMAKE_XCODE_ATTRIBUTE_CC "${CMAKE_BINARY_DIR}/launch-c")
    set(CMAKE_XCODE_ATTRIBUTE_CXX "${CMAKE_BINARY_DIR}/launch-cxx")
    set(CMAKE_XCODE_ATTRIBUTE_LD "${CMAKE_BINARY_DIR}/launch-c")
    set(CMAKE_XCODE_ATTRIBUTE_LDPLUSPLUS "${CMAKE_BINARY_DIR}/launch-cxx")
  endif()
endif()

# Assimp option setting
option(ASSIMP_BUILD_ZLIB ON)
option(ASSIMP_BUILD_TESTS OFF)
option(ASSIMP_BUILD_ASSIMP_TOOLS OFF)
option(ASSIMP_INSTALL OFF)
option(ASSIMP_NO_EXPORT OFF)
if(WIN32)
  option(ASSIMP_RAPIDJSON_NO_MEMBER_ITERATOR OFF)
  set(ASSIMP_RAPIDJSON_NO_MEMBER_ITERATOR OFF)
endif()
set(ASSIMP_BUILD_ZLIB ON)
set(ASSIMP_BUILD_TESTS OFF)
set(ASSIMP_BUILD_ASSIMP_TOOLS OFF)
set(ASSIMP_INSTALL OFF)
set(ASSIMP_NO_EXPORT OFF)

# Add external library
add_subdirectory(external/entt)
add_subdirectory(external/glm)
add_subdirectory(external/assimp)
add_library(STB_IMAGE "external/stb/stb_image.cpp" "external/stb/stb_image.h"
                      "external/stb/stb_image_write.h")

# Add main source code
add_subdirectory(src)
