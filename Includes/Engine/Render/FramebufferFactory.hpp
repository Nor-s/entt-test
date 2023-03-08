#ifndef MINA_RENDER_FRAMEBUFFERFACTORY_HPP
#define MINA_RENDER_FRAMEBUFFERFACTORY_HPP

#include "../pch.hpp"
#include "Framebuffer.hpp"

namespace Mina
{

class FramebufferFactory
{
public:
	FramebufferFactory() = default;
	virtual ~FramebufferFactory() = default;

	virtual std::unique_ptr<Framebuffer> create(const FramebufferSpec& spec) = 0;
};

}	 // namespace Mina

#endif
