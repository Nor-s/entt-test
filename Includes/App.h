#ifndef MINA_MINA_H
#define MINA_MINA_H

#include "pch.hpp"

namespace Mina
{
class App
{
private:
	std::unique_ptr<class Window> window;
	std::unique_ptr<class Editor> editor;
	entt::registry registry{};

	App();

public:
	App(const App&) = delete;
	App(App&&) = delete;
	App& operator=(const App&) = delete;
	App& operator=(App&&) = delete;

	~App();

	static App& getInstance();

	void init();
	void loop();
	void preRender();
	void render();
	void postRender();
};
}	 // namespace Mina

#endif	  // MINA_MINA_H