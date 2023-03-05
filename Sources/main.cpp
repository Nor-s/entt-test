#include "App.h"

using namespace Mina;

int main()
{
	setlocale(LC_ALL, ".utf8");
	App::get().init();
	App::get().loop();
}