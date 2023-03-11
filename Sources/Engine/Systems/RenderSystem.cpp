//
// Created by No on 2023-03-05.
//
#include "Systems/RenderSystem.h"

#include "Render/RenderAPI.h"
#include "Render/Scene.h"
#include "Render/DrawCommand.hpp"
#include "Render/GL/GLDrawCommand.h"
#include "Render/Shader.h"
#include "Render/ShaderManager.h"

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

template<typename T>
void DrawComponents(entt::registry& registry) {
	static GL::GLDrawCommand drawCommand;
	const auto& view = registry.view<State::Running, T, TransformComponent>();
	auto& shader = RenderAPI::get().getShaderManager().getShader<T>();

	shader.bind();
	{
		for (auto entity : view)
		{
			const auto& transform = view.get<TransformComponent>(entity);
			auto& mesh = view.get<T>(entity);
			drawCommand.drawBasicMesh(shader, *mesh.mesh, transform.mat);
		}
	}
	shader.unbind();

}

void UpdateRenderSystem(Scene& scene)
{
	scene.begin();
	auto& registry = scene.getRegistry();
	DrawComponents<StaticMeshComponent>(registry);
	DrawComponents<DynamicMeshComponent>(registry);
	scene.end();
}

};	  // namespace Mina