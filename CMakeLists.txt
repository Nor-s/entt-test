cmake_minimum_required(VERSION 3.21)

message("Using CMake version ${CMAKE_VERSION}")

project(
  EnttTest
  LANGUAGES CXX
  VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(external/entt)
add_subdirectory(src)
