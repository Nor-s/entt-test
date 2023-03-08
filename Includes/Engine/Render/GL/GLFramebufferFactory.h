#ifndef MINA_RENDER_GL_GLFRAMEBUFFER_FACTORY_H
#define MINA_RENDER_GL_GLFRAMEBUFFER_FACTORY_H

#include "../FramebufferFactory.hpp"

namespace Mina::GL
{

class GLFramebufferFactory : public FramebufferFactory
{
public:
	std::unique_ptr<Framebuffer> create(const FramebufferSpec& spec) override;
};

}	 // namespace Mina::GL

#endif