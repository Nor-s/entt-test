#include "Mina.h"

int main()
{
	setlocale(LC_ALL, ".utf8");
	entt::registry registry;
	Mina::Mina mina = Mina::Mina(registry);
	mina.init();
	mina.loop();
}