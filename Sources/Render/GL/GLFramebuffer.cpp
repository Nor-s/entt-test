#include "Render/GL/GLFramebuffer.h"

namespace Mina::GL
{

GLFramebuffer::GLFramebuffer() : Framebuffer()
{
	glGenFramebuffers(1, &handle);
}

GLFramebuffer::~GLFramebuffer() = default;

void GLFramebuffer::bind()
{
	glBindFramebuffer(GL_FRAMEBUFFER, handle);
	glViewport(0, 0, spec.size.width, spec.size.height);
}

void GLFramebuffer::unbind()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void GLFramebuffer::initColorAttachment(std::vector<std::unique_ptr<Texture>>&& colorTextures)
{
	assert(colorTextures.size() > 0);

	colors.clear();
	spec.size = colorTextures[0]->getSize();
	spec.colorAttachments.clear();

	for (auto& colorTexture : colorTextures)
	{
		addColorAttachment(std::move(colorTexture));
	}
}

void GLFramebuffer::addColorAttachment(std::unique_ptr<Texture> colorTexture)
{
	spec.colorAttachments.push_back(colorTexture->getFormat());
	GLenum target = colorTexture->getMultiSampleNum() == 1 ? GL_TEXTURE_2D : GL_TEXTURE_2D_MULTISAMPLE;
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + colors.size() - 1, target, *colorTexture, 0);

	colors.emplace_back(std::move(colorTexture));
}

DepthBufferHandle GLFramebuffer::changeDepthAttachment(DepthBufferHandle depthBuffer)
{
	DepthBufferHandle old = depth;
	depth = depthBuffer;

	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, depth);

	return old;
}

bool GLFramebuffer::checkStatus()
{
	return glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE;
}

}	 // namespace Mina::GL