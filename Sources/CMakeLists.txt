set(EXE_SRC main.cpp Mina.cpp)
add_executable(Mina ${EXE_SRC} ${COMPONENTS_SRC})
target_compile_options(Mina PRIVATE -Wall -Werror -std=c++17)
target_link_libraries(Mina EnTT::EnTT glm::glm assimp::assimp STB_IMAGE)
target_include_directories(
  Mina
  PUBLIC ./
         ../
         ${CMAKE_HOME_DIRECTORY}/Sources
         ${CMAKE_HOME_DIRECTORY}/Includes/
         ${CMAKE_HOME_DIRECTORY}/Includes/Components
         ${CMAKE_HOME_DIRECTORY}/Externals/
         ${CMAKE_HOME_DIRECTORY}/Externals/entt/single_include
         ${CMAKE_HOME_DIRECTORY}/Externals/glm/
         ${CMAKE_HOME_DIRECTORY}/Externals/stb
         ${CMAKE_HOME_DIRECTORY}/Externals/assimp)
