set(COMMON_SRC ${CMAKE_HOME_DIRECTORY}/Sources/Commons/Logger.cpp)
set(EDITOR_SRC
    ${CMAKE_HOME_DIRECTORY}/Sources/Editor/Window.cpp
    ${CMAKE_HOME_DIRECTORY}/Sources/Editor/Platform/GlfwGLWindow.cpp
    ${CMAKE_HOME_DIRECTORY}/Sources/Editor/Editor.cpp)

set(RENDER_SRC
    ${CMAKE_HOME_DIRECTORY}/Sources/Render/RenderAPI.cpp
    ${CMAKE_HOME_DIRECTORY}/Sources/Render/Mesh.cpp
    ${CMAKE_HOME_DIRECTORY}/Sources/Render/GL/GLMesh.cpp
    ${CMAKE_HOME_DIRECTORY}/Sources/Render/GL/GLShader.cpp
    ${CMAKE_HOME_DIRECTORY}/Sources/Render/GL/GLMeshFactory.cpp
    ${CMAKE_HOME_DIRECTORY}/Sources/Render/GL/GLShader.cpp)

set(HELPER_SRC
    ${CMAKE_HOME_DIRECTORY}/Sources/Helpers/Resources/ModelImporter.cpp
    ${CMAKE_HOME_DIRECTORY}/Sources/Helpers/Resources/ModelExporter.cpp)

set(EXE_SRC ${CMAKE_HOME_DIRECTORY}/Sources/main.cpp
            ${CMAKE_HOME_DIRECTORY}/Sources/App.cpp)

add_executable(Mina ${EXE_SRC} ${EDITOR_SRC} ${HELPER_SRC} ${RENDER_SRC}
                    ${COMMON_SRC})
target_compile_options(Mina PRIVATE -Wall -Werror -std=c++17)
target_link_libraries(
  Mina
  EnTT::EnTT
  glm::glm
  assimp::assimp
  STB_IMAGE
  glfw
  spdlog
  imgui
  glad)

target_include_directories(
  Mina
  PUBLIC ./
         ../
         ${CMAKE_HOME_DIRECTORY}/**
         ${CMAKE_HOME_DIRECTORY}/Sources
         ${CMAKE_HOME_DIRECTORY}/Includes/**
         ${CMAKE_HOME_DIRECTORY}/Includes/Helpers/**
         ${CMAKE_HOME_DIRECTORY}/Includes/Editor/**
         ${CMAKE_HOME_DIRECTORY}/Includes/Components/**
         ${CMAKE_HOME_DIRECTORY}/Includes/Render/**
         ${CMAKE_HOME_DIRECTORY}/Includes/Render/GL/**
         ${CMAKE_HOME_DIRECTORY}/Externals/
         ${CMAKE_HOME_DIRECTORY}/Externals/entt/single_include
         ${CMAKE_HOME_DIRECTORY}/Externals/entt/
         ${CMAKE_HOME_DIRECTORY}/Externals/glm/
         ${CMAKE_HOME_DIRECTORY}/Externals/stb
         ${CMAKE_HOME_DIRECTORY}/Externals/assimp)
