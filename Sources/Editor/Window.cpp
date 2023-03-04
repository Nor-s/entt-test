#include <utility>

#include "Editor/Window.h"

namespace Mina
{
Window::~Window() = default;

Window::Window(WindowContext  c) : context(std::move(c))
{
}

}	 // namespace Mina
