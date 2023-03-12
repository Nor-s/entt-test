#include "Engine/Render/GL/GLFramebuffer.h"
#include "Engine/Render/GL/GLTextureFactory.h"
#include "Engine/Render/GL/GLTexture.h"

#include "Engine/Commons/Logger.h"

namespace Mina::GL
{

DepthBufferHandle CreateDepthBuffer(const MSize& size, DepthFormat format, int multiSampleNum = 1)
{
	DepthBufferHandle depthBuffer;

	glGenRenderbuffers(1, &depthBuffer);
	glBindRenderbuffer(GL_RENDERBUFFER, depthBuffer);
	if (multiSampleNum > 1)
	{
		glRenderbufferStorageMultisample(GL_RENDERBUFFER, multiSampleNum, GL_DEPTH_COMPONENT, size.width, size.height);
	}
	else
	{
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, size.width, size.height);
	}
	glBindRenderbuffer(GL_RENDERBUFFER, 0);

	return depthBuffer;
}

GLFramebuffer::GLFramebuffer(const FramebufferSpec& spec) : Framebuffer(spec)
{
}

GLFramebuffer::~GLFramebuffer()
{
	MINA_LOG("Deleting framebuffer: {}", handle);
	if (isValid)
	{
		glDeleteFramebuffers(1, &handle);
		colors.clear();
		glDeleteRenderbuffers(1, &depth);
	}
}

void GLFramebuffer::init()
{
	assert(colors.empty());

	GL_CALL(glGenFramebuffers(1, &handle));
	GL_CALL(glBindFramebuffer(GL_FRAMEBUFFER, handle));
	{
		GLTextureFactory textureFactory;
		for (auto& colorFormat : spec.colorAttachments)
		{
			addColorAttachment(textureFactory.create(spec.size, colorFormat, spec.multiSampleNum));
		}

		if (spec.depthAttachment != DepthFormat::NONE)
		{
			depth = CreateDepthBuffer(spec.size, spec.depthAttachment, spec.multiSampleNum);
		}
	}

	if (!checkStatus())
	{
		isValid = false;
		MINA_CRITICAL("Framebuffer is not complete!");
	}
	GL_CALL(glBindFramebuffer(GL_FRAMEBUFFER, 0));
}

void GLFramebuffer::clear()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

void GLFramebuffer::bind()
{
	GL_CALL(glBindFramebuffer(GL_FRAMEBUFFER, handle));
	GL_CALL(glViewport(0, 0, spec.size.width, spec.size.height));
}

void GLFramebuffer::unbind()
{
	GL_CALL(glBindFramebuffer(GL_FRAMEBUFFER, 0));
}

void GLFramebuffer::resize(const MSize& size)
{
	spec.size = size;
	if (isValid)
	{
		GL_CALL(glDeleteFramebuffers(1, &handle));
		colors.clear();
		if (spec.depthAttachment != DepthFormat::NONE)
		{
			glDeleteRenderbuffers(1, &depth);
		}
		isValid = true;
	}
	init();
}

void GLFramebuffer::addColorAttachment(std::unique_ptr<Texture> colorTexture)
{
	GLenum target = colorTexture->getMultiSampleNum() == 1 ? GL_TEXTURE_2D : GL_TEXTURE_2D_MULTISAMPLE;
	GL_CALL(glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + colors.size(), target, *colorTexture, 0));

	colors.emplace_back(std::move(colorTexture));
}

DepthBufferHandle GLFramebuffer::changeDepthAttachment(DepthBufferHandle depthBuffer)
{
	DepthBufferHandle old = depth;
	depth = depthBuffer;

	GL_CALL(glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, depth));

	if (!checkStatus())
	{
		MINA_CRITICAL("Framebuffer is not complete!");
	}

	return old;
}

bool GLFramebuffer::checkStatus()
{
	return glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE;
}

}	 // namespace Mina::GL