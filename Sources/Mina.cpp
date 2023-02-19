#include "Mina.h"

namespace Mina
{
Mina::Mina(entt::registry& registry) : registry(registry)
{
}

void Mina::init()
{
}

void Mina::loop()
{
	// while (true)
	{
		preUpdate();
		render();
		postUpdate();
	}
}

void Mina::preUpdate()
{
}

void Mina::render()
{
}

void Mina::postUpdate()
{
}

}	 // namespace Mina