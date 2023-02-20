#include "App.h"

using namespace Mina;

int main()
{
	setlocale(LC_ALL, ".utf8");
	App& app = App::getInstance();
	app.init();
	app.loop();
}