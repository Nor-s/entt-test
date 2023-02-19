

#include "Mina.h"

#include "Editor/Platform/GlfwGLWindow.h"

namespace Mina
{
Mina::Mina(entt::registry& registry) : registry(registry)
{
}
Mina::~Mina() = default;

void Mina::init()
{
	window = std::make_unique<GlfwGLWindow>(WindowContext{500, 500, "Mina"});
	window->init();
}

void Mina::loop()
{
	while (!window->shouldClose())
	{
		preRender();
		{
			render();
		}
		postRender();
	}
}

void Mina::preRender()
{
	window->processResize();
}

void Mina::render()
{
}

void Mina::postRender()
{
	window->swapBuffers();
}

}	 // namespace Mina