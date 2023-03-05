//
// Created by No on 2023-03-05.
//

#include "Editor/Layers/SceneLayer.h"
#include "Render/Scene.h"
#include "Render/Framebuffer.hpp"

#include "Commons/Logger.h"

#define IMGUI_DEFINE_MATH_OPERATORS
#include <imgui/imgui_internal.h>

namespace Mina
{

void SceneLayer::processMouseEvent(ImGuiWindowFlags& windowFlags)
{
	//	auto scene_pos_ = ImGui::GetWindowPos();
	//	auto scene_cursor_y_ = ImGui::GetCursorPosY();
	//	ImVec2 mouse_pos = ImGui::GetMousePos();
	//	int y = (scene_cursor_y_ + height_ + 16.0f) - mouse_pos.y;
	//	int x = mouse_pos.x - scene_pos_.x;
	//
	//	// process doubli clicked
	ImGuiWindow* window = ImGui::GetCurrentWindow();
	//	if (ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left) && ImGui::IsMouseHoveringRect(window->InnerRect.Min,
	// window->InnerRect.Max))
	//	{
	//		anim::LOG("double click" + std::to_string(x) + " " + std::to_string(y));
	//		ui_context.scene.is_picking = true;
	//		ui_context.scene.x = x;
	//		ui_context.scene.y = y;
	//	}
	//	is_hovered_ = !ImGuizmo::IsUsing() && ImGui::IsWindowHovered() &&
	// ImGui::IsMouseHoveringRect(window->InnerRect.Min, window->InnerRect.Max);
	windowFlags = !ImGui::IsWindowDocked() && ImGui::IsMouseHoveringRect(window->InnerRect.Min, window->InnerRect.Max)
					  ? ImGuiWindowFlags_NoMove
					  : 0;
}

void DrawScene(const Framebuffer& framebuffer, const ImVec2& size)
{
	void* texture = reinterpret_cast<void*>(static_cast<intptr_t>(framebuffer.getColorTexture(0).getHandle()));
	ImGui::Image(texture, size, ImVec2{0, 1}, ImVec2{1, 0});

	const auto& framebufferSize = framebuffer.getSize();
	if (static_cast<float>(framebufferSize.width) != size.x || static_cast<float>(framebufferSize.height) != size.y)
	{
		// todo:: send scene.resize message
	}
}

void SceneLayer::update(Scene& scene)
{
	static ImGuiWindowFlags sceneWindowFlags = 0;
	const auto& framebuffer = scene.getFramebuffer();

	// draw scene window
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, {0.0f, 0.0f});
	if (ImGui::Begin("scene", 0, sceneWindowFlags | ImGuiWindowFlags_NoScrollbar))
	{
		ImVec2 viewportPanelSize = ImGui::GetContentRegionAvail();
		DrawScene(framebuffer, viewportPanelSize);
		processMouseEvent(sceneWindowFlags);
	}

	ImGui::PopStyleVar();
	ImGui::End();
}

}	 // namespace Mina