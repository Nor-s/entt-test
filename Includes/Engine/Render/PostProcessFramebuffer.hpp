#ifndef MINA_RENDER_POSTPROCESSFRAMEBUFFER_HPP
#define MINA_RENDER_POSTPROCESSFRAMEBUFFER_HPP

#include "pch.hpp"
#include "Framebuffer.hpp"

namespace Mina
{
class PostProcessFramebuffer : public Framebuffer
{
private:
	const Framebuffer& framebuffer;

public:
	PostProcessFramebuffer() = delete;
	PostProcessFramebuffer(const PostProcessFramebuffer&) = delete;
	PostProcessFramebuffer(PostProcessFramebuffer&&) = delete;

	PostProcessFramebuffer& operator=(const PostProcessFramebuffer&) = delete;
	PostProcessFramebuffer& operator=(PostProcessFramebuffer&&) = delete;

	PostProcessFramebuffer(const Framebuffer& framebuff) : framebuffer(framebuff)
	{
	}

	virtual void bind() = 0;
	virtual void draw() = 0;
	virtual void unbind() = 0;
};
}	 // namespace Mina

#endif