set(COMMON_SRC Commons/Logger.cpp)

set(EDITOR_SRC Editor/Window.cpp Editor/Platform/GlfwGLWindow.cpp
        Editor/Editor.cpp Editor/Layers/SceneLayer.cpp)

set(RENDER_SRC
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
        Render/GL/GLTextureFactory.cpp Render/Shader.cpp)

set(HELPER_SRC Helpers/Resources/ModelImporter.cpp
        Helpers/Resources/ModelExporter.cpp Helpers/Render/RenderHelper.cpp)

set(SYSTEM_SRC
        Systems/RenderSystem.cpp
        )

set(EXE_SRC main.cpp App.cpp)

add_executable(Mina ${EXE_SRC} ${EDITOR_SRC} ${HELPER_SRC} ${RENDER_SRC}
        ${COMMON_SRC} ${SYSTEM_SRC})
if (MSVC)
    target_compile_options(Mina PRIVATE "/utf-8")
else ()
    target_compile_options(Mina PRIVATE -Wall -Werror -std=c++17)
endif ()
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
