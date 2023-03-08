//
// Created by No on 2023-03-05.
//
#include "Systems/RenderSystem.h"

#include "Render/RenderAPI.h"
#include "Render/Scene.h"
#include "Render/DrawCommand.hpp"
#include "Render/GL/GLDrawCommand.h"
#include "Render/Shader.h"

#include "Components/Render/MeshComponent.hpp"
#include "Components/TransformComponent.hpp"
#include "Components/State.hpp"

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
	static auto defaultStaticMeshShader = std::move(RenderAPI::get().createShader("Resources/Shaders/glsl/StaticMesh.vert",
																		   "Resources/Shaders/glsl/PhongLight.frag"));
	static auto defaultDynamicMeshShader = std::move(RenderAPI::get().createShader("Resources/Shaders/glsl/StaticMesh.vert",
																				  "Resources/Shaders/glsl/PhongLight.frag"));
	scene.begin();
	GL::GLDrawCommand drawCommand;

	auto& registry = scene.getRegistry();
	auto staticMeshView = registry.view<State::Running, StaticMeshComponent, TransformComponent>();

	defaultStaticMeshShader->bind();
	{
		for (auto entity : staticMeshView)
		{
			const auto& transform = staticMeshView.get<TransformComponent>(entity);
			auto& mesh = staticMeshView.get<StaticMeshComponent>(entity);
			drawCommand.drawBasicMesh(*defaultStaticMeshShader, *mesh.mesh, transform.mat);
		}
	}
	defaultStaticMeshShader->unbind();

	scene.end();
}


};	  // namespace Mina