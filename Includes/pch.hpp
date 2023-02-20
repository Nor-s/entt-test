#ifndef MINA_PCH_H
#define MINA_PCH_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>

// Entt
#include <entt/entt.hpp>

// GLM
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include <glm/gtx/quaternion.hpp>

// Assimp
#include <assimp/scene.h>

#include <assimp/Exporter.hpp>
#include <assimp/Importer.hpp>

// Stb
#include <stb/stb_image.h>
#include <stb/stb_image_write.h>

// glad
#include <glad/glad.h>

// glfw
#include <GLFW/glfw3.h>

// imgui
// #include <ImGuiFileDialog/ImGuiFileDialog.h>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/icons/icons.h>
#include <imgui/ImGuizmo.h>
#ifdef _WIN32
#pragma warning(disable : 4005)
#include <Windows.h>
// #include <shellapi.h>
#include <lmcons.h>
// #pragma comment(lib, "Shell32.lib")
#else
#include <pwd.h>
#include <unistd.h>
#endif

#endif	  // MINA_PCH_H