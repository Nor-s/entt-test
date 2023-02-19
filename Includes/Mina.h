#ifndef MINA_MINA_H
#define MINA_MINA_H

#include "pch.h"

namespace Mina
{
class Window;
class Mina
{
private:
	[[maybe_unused]] entt::registry& registry;
	std::unique_ptr<Window> window;

public:
	Mina() = delete;
	Mina(const Mina&) = delete;
	Mina(Mina&&) = delete;
	Mina& operator=(const Mina&) = delete;
	Mina& operator=(Mina&&) = delete;

	~Mina();

	explicit Mina(entt::registry& registry);
	void init();
	void loop();
	void preRender();
	void render();
	void postRender();
};
}	 // namespace Mina

#endif	  // MINA_MINA_H