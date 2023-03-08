#include "App.h"

#include "Editor/Editor.h"
#include "Editor/Layers/SceneLayer.h"
#include "Editor/Platform/GlfwGLWindow.h"

#include "Commons/Logger.h"

#include "Render/Scene.h"
#include "Render/RenderAPI.h"
#include "Render/Framebuffer.hpp"
#include "Render/FramebufferFactory.hpp"

#include "Helpers/Entity/EntityHelper.h"

#include "Systems/RenderSystem.h"

namespace Mina
{

App::App() : registry{}, scene{nullptr}
{
}

App::~App()
{
	MINA_LOG("Destroying Mina");
	registry.clear();
	scene.reset(nullptr);
	editor.reset(nullptr);
	window.reset(nullptr);
}

void App::init()
{
	MINA_LOG("Initializing Mina");

	window = std::make_unique<GlfwGLWindow>(WindowContext{500, 500, "Mina"});
	window->init();

	FramebufferSpec spec = {MSize{500, 500}, {FramebufferTextureFormat ::RGBA8}, DepthFormat::Depth};

	scene = std::make_unique<Scene>(registry, RenderAPI::get().getFramebufferFactory().create(spec));
	CreateBiPyramid(scene->getRegistry());
	editor = std::make_unique<Editor>(*window);
	editor->init();
	editor->addLayer(std::make_unique<SceneLayer>());
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