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

#https://stackoverflow.com/questions/34799916/copy-file-from-source-directory-to-binary-directory-using-cmake
add_custom_command(
        TARGET Mina POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_HOME_DIRECTORY}/Resources/
        ${CMAKE_BINARY_DIR}/bin/Resources/
        DEPENDS ${CMAKE_HOME_DIRECTORY}/Resources)