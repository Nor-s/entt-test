#include "Render/GL/GLFramebuffer.h"

namespace Mina::GL
{

GLFramebuffer::GLFramebuffer() : Framebuffer()
{
	glGenFramebuffers(1, &handle);
}

void GLFramebuffer::bind()
{
	glBindFramebuffer(GL_FRAMEBUFFER, handle);
	glViewport(0, 0, spec.size.width, spec.size.height);
}

void GLFramebuffer::unbind()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

}	 // namespace Mina::GL