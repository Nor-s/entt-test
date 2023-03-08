add_subdirectory(Engine)

set(EDITOR_SRC Editor/Editor.cpp Editor/Layers/SceneLayer.cpp)

set(EXE_SRC main.cpp App.cpp)

add_executable(Mina ${EXE_SRC} ${EDITOR_SRC})

if(MSVC)
  target_compile_options(Mina PRIVATE "/utf-8")
else()
  target_compile_options(Mina PRIVATE -Wall -Werror -std=c++17)
endif()
target_link_libraries(Mina MinaEngine imgui)

target_include_directories(
  Mina PUBLIC ./ ../ ${CMAKE_HOME_DIRECTORY}/Includes/Editor/**)
