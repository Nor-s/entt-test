set(RENDER_SRC
    Render/Window.cpp
    Render/Window/GlfwGLWindow.cpp
    Render/Camera.cpp
    Render/Scene.cpp
    Render/RenderAPI.cpp
    Render/Texture.cpp
    Render/Mesh.cpp
    Render/GL/GLDrawCommand.cpp
    Render/GL/GLMesh.cpp
    Render/GL/GLMeshFactory.cpp
    Render/GL/GLFramebuffer.cpp
    Render/GL/GLFramebufferFactory.cpp
    Render/GL/GLShader.cpp
    Render/GL/GLTexture.cpp
    Render/GL/GLTextureFactory.cpp
    Render/Shader.cpp Render/GL/GLUniformBuffer.cpp)

set(COMMON_SRC Commons/Logger.cpp)

set(HELPER_SRC Helpers/Resources/ModelImporter.cpp
               Helpers/Entity/EntityHelper.cpp)

set(SYSTEM_SRC Systems/RenderSystem.cpp)

add_library(MinaEngine ${HELPER_SRC} ${RENDER_SRC} ${COMMON_SRC} ${SYSTEM_SRC})

if(MSVC)
  target_compile_options(MinaEngine PRIVATE "/utf-8")
else()
  target_compile_options(MinaEngine PRIVATE -Wall -Werror -std=c++17)
endif()

target_link_libraries(
  MinaEngine
  PUBLIC EnTT::EnTT
         glm::glm
         assimp::assimp
         STB_IMAGE
         glfw
         spdlog
         glad)

target_include_directories(
  MinaEngine
  PUBLIC ./
         ../
         ${CMAKE_HOME_DIRECTORY}/**
         ${CMAKE_HOME_DIRECTORY}/Sources
         ${CMAKE_HOME_DIRECTORY}/Includes/Engine/**
         ${CMAKE_HOME_DIRECTORY}/Externals/
         ${CMAKE_HOME_DIRECTORY}/Externals/entt/single_include
         ${CMAKE_HOME_DIRECTORY}/Externals/entt/
         ${CMAKE_HOME_DIRECTORY}/Externals/glm/
         ${CMAKE_HOME_DIRECTORY}/Externals/stb
         ${CMAKE_HOME_DIRECTORY}/Externals/assimp)
