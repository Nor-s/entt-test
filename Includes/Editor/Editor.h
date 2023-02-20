#ifndef MINA_EDITOR_EDITOR_H
#define MINA_EDITOR_EDITOR_H

#include "../pch.hpp"

namespace Mina
{
class Editor
{
private:
	class Window& window;

public:
	Editor() = delete;
	Editor(const Editor&) = delete;
	Editor(Editor&&) = delete;
	Editor& operator=(const Editor&) = delete;
	Editor& operator=(Editor&&) = delete;

	Editor(class Window& window);
	~Editor();

	void init();
	void preRender();
	void postRender();
	void shutdown();

private:
	void drawDock();
	void drawMenuBar();
};
}	 // namespace Mina

#endif