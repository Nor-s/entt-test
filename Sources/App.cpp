#include "App.h"

#include "Editor/Editor.h"
#include "Editor/Platform/GlfwGLWindow.h"

#include "Commons/Logger.h"

#include "Render/Scene.h"
#include "Render/RenderAPI.h"
#include "Render/Framebuffer.hpp"
#include "Render/FramebufferFactory.hpp"

#include "Helpers/Render/RenderHelpers.hpp"

namespace Mina
{

App::App() : registry{}, scene{nullptr}
{
}

App::~App() {
	MINA_LOG("Destroying Mina");
	window.reset(nullptr);
	editor.reset(nullptr);
	scene.reset(nullptr);
}

void App::init()
{
	MINA_LOG("Initializing Mina");

	window = std::make_unique<GlfwGLWindow>(WindowContext{500, 500, "Mina"});
	window->init();

	editor = std::make_unique<Editor>(*window);
	editor->init();

	FramebufferSpec spec = {
		MSize{500, 500},
		{FramebufferTextureFormat ::RGBA8},
		DepthFormat::Depth
	};

	scene = std::make_unique<Scene>(registry, std::move(RenderAPI::get().getFramebufferFactory().create(spec)));
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
	// scene->render();
//	 editor->render();
}

void App::postRender()
{
	editor->postRender();
	window->swapBuffers();
}

}	 // namespace Mina