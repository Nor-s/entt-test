#ifndef MINA_MINA_H
#define MINA_MINA_H

#include "pch.h"

namespace Mina
{
class Mina
{
public:
	Mina() = delete;
	Mina(const Mina&) = delete;
	Mina(Mina&&) = delete;
	Mina& operator=(const Mina&) = delete;
	Mina& operator=(Mina&&) = delete;

	explicit Mina(entt::registry& registry);
	void init();
	void loop();
	void preUpdate();
	void render();
	void postUpdate();

private:
	[[maybe_unused]] entt::registry& registry;
};
}	 // namespace Mina

#endif	  // MINA_MINA_H