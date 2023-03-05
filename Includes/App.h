#ifndef MINA_MINA_H
#define MINA_MINA_H

#include "pch.hpp"
#include "Commons/Singleton.hpp"

namespace Mina
{

class App : public Singleton<App>
{
	friend class Singleton<App>;

private:
	entt::registry registry{};
	std::unique_ptr<class Window> window{};
	std::unique_ptr<class Editor> editor{};
	std::unique_ptr<class Scene> scene{};

private:
	App();

	void preRender();
	void render();
	void postRender();

public:
	App(const App&) = delete;
	App(App&&) = delete;

	App& operator=(const App&) = delete;
	App& operator=(App&&) = delete;

	~App();

	void init();

	/**
	 * @pre init() must be called before this function
	 */
	void loop();
};

}	 // namespace Mina

#endif	  // MINA_MINA_H