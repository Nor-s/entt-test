#ifndef MINA_RENDER_RENDER_H
#define MINA_RENDER_RENDER_H

#include "pch.hpp"

namespace Mina
{
class Render
{
private:
	std::unique_ptr<class Framebuffer> framebuffer;

public:
	virtual void begin() = 0;
	virtual void end() = 0;
	virtual Framebuffer& getFramebuffer() const = 0;
};
}	 // namespace Mina

#endif