#ifndef MINA_RENDER_WINDOW_H
#define MINA_RENDER_WINDOW_H

#include "../pch.hpp"

namespace Mina
{
using window_size = int;

struct WindowContext
{
	window_size width{};
	window_size height{};
	std::string title{};
};

class Window
{
protected:
	WindowContext context;
	float factor{};

public:
	Window() = delete;
	Window(const Window&) = delete;
	Window(Window&&) = delete;
	Window& operator=(const Window&) = delete;
	Window& operator=(Window&&) = delete;

	explicit Window(WindowContext c);

	virtual ~Window();

	virtual inline void* getHandle() const = 0;
	virtual inline void init() = 0;
	virtual inline bool shouldClose() = 0;
	virtual inline void processEvents() = 0;
	virtual inline void swapBuffers() = 0;
	virtual inline void processResize() = 0;
};

}	 // namespace Mina

#endif
