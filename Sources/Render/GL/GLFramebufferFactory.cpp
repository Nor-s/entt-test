#include "Render/GL/GLFramebuffer.h"
#include "Render/GL/GLFramebufferFactory.h"
#include "Commons/Logger.h"

namespace Mina::GL
{

std::unique_ptr<Framebuffer> GLFramebufferFactory::create(const FramebufferSpec& spec)
{
	MINA_LOG("Creating framebuffer with spec: size: {}, {}", spec.size.width, spec.size.height);

	auto framebuffer =  std::unique_ptr<GLFramebuffer>(new GLFramebuffer(spec));
	framebuffer->init();

	return framebuffer;
}

}	 // namespace Mina::GL