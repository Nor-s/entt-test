#include "Render/GL/GLFramebuffer.h"
#include "Render/GL/GLFramebufferFactory.h"
#include "Render/GL/GLTexture.h"
#include "Render/GL/GLTextureFactory.h"
#include "Commons/Logger.h"

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

std::unique_ptr<Framebuffer> GLFramebufferFactory::create(FramebufferSpec&& spec)
{
	auto framebuffer = std::unique_ptr<GLFramebuffer>(new GLFramebuffer());

	framebuffer->bind();
	{
		std::vector<std::unique_ptr<Texture>> colorTextures;
		{
			GLTextureFactory textureFactory;
			for (auto& colorFormat : spec.colorAttachments)
			{
				colorTextures.emplace_back(textureFactory.create(spec.size, colorFormat, spec.multiSampleNum));
			}
		}

		framebuffer->initColorAttachment(std::move(colorTextures));

		if (spec.depthAttachment != DepthFormat::NONE)
		{
			GLTextureFactory textureFactory;
			auto depthBuffer = CreateDepthBuffer(spec.size, spec.depthAttachment, spec.multiSampleNum);
			framebuffer->changeDepthAttachment(depthBuffer);
		}
	}
	framebuffer->unbind();

	if (framebuffer->checkStatus())
	{
		MINA_CRITICAL("Framebuffer is not complete!");
	}

	return framebuffer;
}

}	 // namespace Mina::GL