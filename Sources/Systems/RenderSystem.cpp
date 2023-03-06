//
// Created by No on 2023-03-05.
//
#include "Systems/RenderSystem.h"

#include "Render/RenderAPI.h"
#include "Render/Scene.h"
#include "Render/DrawCommand.hpp"
#include "Render/GL/GLDrawCommand.h"
#include "Render/Shader.h"

#include "Helpers/Render/RenderHelper.h"

namespace Mina
{
void UpdateAnimationSystem(Scene& scene)
{
	//	registry.view<Skeleton>[] {
	//		update skeleton
	//	}
}
void UpdateRenderSystem(Scene& scene)
{
	auto biPyramid = CreateBiPyramid();
	auto shader = std::move(RenderAPI::get().createShader("Resources/Shaders/glsl/StaticMesh.vert", "Resources/Shaders/glsl/PhongLight.frag"));
	scene.begin();
	GL::GLDrawCommand drawCommand;

//	shader->bind();
//	drawCommand.drawBasicMesh(*shader, *biPyramid);
//	shader->unbind();

	scene.end();
}


};	  // namespace Mina