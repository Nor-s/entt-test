#ifndef MINA_EDITOR_GLFWGLWINDOW_H
#define MINA_EDITOR_GLFWGLWINDOW_H

#include "../Window.h"

namespace Mina
{
class GlfwGLWindow : public Window
{
private:
	GLFWwindow* window;

public:
	GlfwGLWindow() = delete;
	GlfwGLWindow(const GlfwGLWindow&) = delete;
	GlfwGLWindow(GlfwGLWindow&&) = delete;
	GlfwGLWindow& operator=(const GlfwGLWindow&) = delete;
	GlfwGLWindow& operator=(GlfwGLWindow&&) = delete;

	GlfwGLWindow(const WindowContext& c);

	virtual ~GlfwGLWindow();

	inline void* getHandle() const override;
	inline void init() override;
	inline bool shouldClose() override;
	inline void processEvents() override;
	inline void swapBuffers() override;
	inline void processResize() override;

private:
	inline void setExtends(window_size width, window_size height);
	inline std::pair<window_size, window_size> getFramebufferSize();
};

}	 // namespace Mina

#endif