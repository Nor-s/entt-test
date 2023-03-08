#include "pch.hpp"
#include "Commons/Logger.h"
#include "Render/Window/GlfwGLWindow.h"

namespace Mina
{
GlfwGLWindow::GlfwGLWindow(const WindowContext& context) : Window(context)
{
}

GlfwGLWindow::~GlfwGLWindow()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

void GlfwGLWindow::init()
{
	MINA_LOG("Initializing GLFW window");
	if (!glfwInit())
	{
		MINA_CRITICAL("GLFW couldn't be initialized.");
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifndef NDEBUG
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);
#endif
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	window = glfwCreateWindow(context.width, context.height, context.title.c_str(), nullptr, nullptr);
	if (!window)
	{
		glfwTerminate();
		MINA_CRITICAL("GLFW failed to create window");
	}
	glfwMakeContextCurrent(window);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
	{
		MINA_CRITICAL("Failed to initialize GLAD");
	}

	glfwSwapInterval(0);
}

void* GlfwGLWindow::getHandle() const
{
	return static_cast<void*>(window);
}

bool GlfwGLWindow::shouldClose()
{
	return glfwWindowShouldClose(window);
}

void GlfwGLWindow::processEvents()
{
	glfwPollEvents();
}

void GlfwGLWindow::swapBuffers()
{
	glfwSwapBuffers(window);
	glfwPollEvents();
}

void GlfwGLWindow::processResize()
{
	auto size = getFramebufferSize();
	while (size.first == 0 || size.second == 0)
	{
		glfwWaitEvents();
		size = getFramebufferSize();
	}
	setExtends(size.first, size.second);
}

void GlfwGLWindow::setExtends(window_size width, window_size height)
{
	context.width = width;
	context.height = height;
}

std::pair<window_size, window_size> GlfwGLWindow::getFramebufferSize()
{
	std::pair<window_size, window_size> size{0, 0};
	glfwGetFramebufferSize(window, &size.first, &size.second);
	return size;
}

}	 // namespace Mina
