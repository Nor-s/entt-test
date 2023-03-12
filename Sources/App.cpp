#include "App.h"

#include "Editor/Editor.h"
#include "Editor/Layers/SceneLayer.h"

#include "Engine/Commons/Logger.h"

#include "Engine/Render/Scene.h"
#include "Engine/Render/RenderAPI.h"
#include "Engine/Render/Framebuffer.hpp"
#include "Engine/Render/FramebufferFactory.hpp"
#include "Engine/Render/ShaderManager.h"
#include "Engine/Render/Window/GlfwGLWindow.h"

#include "Engine/Helpers/Entity/EntityHelper.h"

#include "Engine/Systems/RenderSystem.h"

#include "Engine/Components/Render/MeshComponent.hpp"
#include "Engine/Components/UniformBufferDatas.hpp"

namespace Mina
{

App::App() : registry{}, scene{nullptr}
{
}

App::~App()
{
	window.reset(nullptr);
}
void App::init()
{
	MINA_LOG("Initializing Mina");

#ifdef USE_OPENGL
	window = std::make_unique<GlfwGLWindow>(WindowContext{500, 500, "Mina"});
	window->init();
#else
#endif

	FramebufferSpec spec = {MSize{500, 500}, {FramebufferTextureFormat ::RGBA8}, DepthFormat::Depth};

	scene = std::make_unique<Scene>(registry, RenderAPI::get().getFramebufferFactory().create(spec));

	editor = std::make_unique<Editor>(*window);
	{
		editor->init();
		editor->addLayer(std::make_unique<SceneLayer>());
	}

	// tmp code
	{
		CreateBiPyramid(scene->getRegistry());
		auto& shaderMgr = RenderAPI::get().getShaderManager();
		shaderMgr.setShader<DynamicMeshComponent>("Resources/Shaders/glsl/DynamicMesh.vert",
												  "Resources/Shaders/glsl/PhongLight.frag");
		shaderMgr.setShader<StaticMeshComponent>("Resources/Shaders/glsl/StaticMesh.vert",
												 "Resources/Shaders/glsl/PhongLight.frag");
		shaderMgr.setUniformBuffer<ViewProj>(0);
		shaderMgr.bindUniformBuffer<ViewProj, DynamicMeshComponent, StaticMeshComponent>("ViewProj");
	}
}

void App::loop()
{
	MINA_LOG("Starting main loop");

	while (!window->shouldClose())
	{
		preRender();
		{
			render();
		}
		postRender();
	}

	MINA_LOG("End main loop");

	registry.clear();
	scene.reset(nullptr);
	editor.reset(nullptr);
}

void App::preRender()
{
	window->processResize();
	editor->preRender();
}

void App::render()
{
	UpdateAnimationSystem(*scene);
	UpdateRenderSystem(*scene);
	editor->updateLayers(*scene);
}

void App::postRender()
{
	editor->postRender();
	window->swapBuffers();
}

}	 // namespace Mina