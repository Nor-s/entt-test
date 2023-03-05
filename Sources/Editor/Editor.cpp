#include "Editor.h"
#include "Layer.hpp"

#include "Platform/GlfwGLWindow.h"

namespace Mina
{

Editor::Editor(Window& window) : window{window}
{
}

Editor::~Editor(){
	shutdown();
}

void Editor::init()
{
	const char* glsl_version = "#version 330";

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();

	ImGuiIO& io = ImGui::GetIO();
	{
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;	 // Enable Keyboard Controls
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;		 // Enable Docking
	}

	ImGui::StyleColorsLight();
	ImGuiStyle& style = ImGui::GetStyle();
	{
		style.WindowRounding = 0.0f;
		style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		style.WindowPadding.x = 3.0f;
		style.WindowPadding.y = 3.0f;
		style.FramePadding.y = 1.0f;
	}

	io.Fonts->AddFontFromFileTTF("./Resources/Font/D2Coding.ttf", 16.0f, NULL, io.Fonts->GetGlyphRangesKorean());
	ImGui::LoadInternalIcons(io.Fonts);

	ImGui_ImplGlfw_InitForOpenGL(static_cast<GLFWwindow*>(window.getHandle()), true);
	ImGui_ImplOpenGL3_Init(glsl_version);
}

void Editor::preRender()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
	ImGuizmo::SetOrthographic(false);	 // is perspective
	ImGuizmo::BeginFrame();
	drawDock();
}

void Editor::postRender()
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	ImGuiIO& io = ImGui::GetIO();
	if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
	{
		GLFWwindow* backup_current_context = glfwGetCurrentContext();
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
		glfwMakeContextCurrent(backup_current_context);
	}
}

void Editor::shutdown()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

}	 // namespace Mina

namespace Mina
{

void Editor::drawDock()
{
	static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

	ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
	const ImGuiViewport* viewport = ImGui::GetMainViewport();
	{
		ImGui::SetNextWindowPos(viewport->WorkPos);
		ImGui::SetNextWindowSize(viewport->WorkSize);
		ImGui::SetNextWindowViewport(viewport->ID);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
		window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize |
						ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;

		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
	}

	ImGui::Begin("DockSpace", NULL, window_flags);
	{
		ImGui::PopStyleVar(3);
		// Submit the DockSpace
		ImGuiIO& io = ImGui::GetIO();
		if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
		{
			ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
			ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
		}
		drawMenuBar();
	}
	ImGui::End();
}

void Editor::drawMenuBar()
{
	if (ImGui::BeginMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Import: fbx, gltf2 ...", NULL, nullptr))
			{
			}
			ImGui::Separator();
			if (ImGui::MenuItem("Export: fbx, gltf2 ...", NULL, nullptr))
			{
			}
			ImGui::EndMenu();
		}

		// This is not the "immediate/current" framerate,
		// it is the rolling average framerate over the last 120 frames.
		ImGui::Text("미나 fps: %.2f", ImGui::GetIO().Framerate);
		ImGui::EndMenuBar();
	}
}

void Editor::addLayer(std::unique_ptr<Layer> layer)
{
	layers.emplace_back(std::move(layer));
}

void Editor::updateLayers(struct Scene& scene)
{
	for (auto& layer : layers)
	{
		layer->update(scene);
	}
}

}	 // namespace Mina