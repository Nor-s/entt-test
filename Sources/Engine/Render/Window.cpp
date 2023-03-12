#include <utility>

#include "Engine/Render/Window.h"

namespace Mina
{
Window::~Window() = default;

Window::Window(WindowContext c) : context(std::move(c))
{
}

}	 // namespace Mina
