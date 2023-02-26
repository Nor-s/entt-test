#include "App.h"

#include "Editor/Editor.h"
#include "Editor/Platform/GlfwGLWindow.h"

#include "Commons/Logger.h"

namespace Mina
{

App::App() : registry{}
{
}

App::~App() = default;

App& App::getInstance()
{
	static App instance{};
	return instance;
}

void App::init()
{
	MINA_LOG("Initializing Mina");

	window = std::make_unique<GlfwGLWindow>(WindowContext{500, 500, "Mina"});
	window->init();

	editor = std::make_unique<Editor>(*window);
	editor->init();
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
}

void App::postRender()
{
	editor->postRender();
	window->swapBuffers();
}

}	 // namespace Mina