set(EXE_SRC main.cpp Mina.cpp)
add_executable(Mina ${EXE_SRC} ${COMPONENTS_SRC})
target_compile_options(Mina PRIVATE -Wall -Werror -std=c++17)
target_link_libraries(Mina EnTT::EnTT glm::glm assimp::assimp STB_IMAGE)
target_include_directories(
  Mina
  PUBLIC ./
         ../
         ${CMAKE_HOME_DIRECTORY}/src
         ${CMAKE_HOME_DIRECTORY}/include/
         ${CMAKE_HOME_DIRECTORY}/include/components
         ${CMAKE_HOME_DIRECTORY}/external/
         ${CMAKE_HOME_DIRECTORY}/external/entt/single_include
         ${CMAKE_HOME_DIRECTORY}/external/glm/
         ${CMAKE_HOME_DIRECTORY}/external/stb
         ${CMAKE_HOME_DIRECTORY}/external/assimp)
