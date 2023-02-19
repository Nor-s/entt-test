#include "Editor/Window.h"

namespace Mina
{
Window::~Window() = default;

Window::Window(const WindowContext& c) : context(c)
{
}

}	 // namespace Mina
