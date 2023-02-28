#ifndef MINA_RENDER_GL_GLFRAMEBUFFER_H
#define MINA_RENDER_GL_GLFRAMEBUFFER_H

#include "../Framebuffer.hpp"

namespace Mina::GL
{

class GLFramebuffer : public Framebuffer
{
protected:
	GLFramebuffer();

public:
	void bind() override;
	void unbind() override;
};

}	 // namespace Mina::GL

#endif