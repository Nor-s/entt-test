#ifndef MINA_RENDER_FRAMEBUFFER_HPP
#define MINA_RENDER_FRAMEBUFFER_HPP

#include "pch.hpp"

#include "Mesh.h"

namespace Mina
{

enum class FramebufferTextureFormat
{
	None = 0,
	// Color
	RGBA8,
	RGB,
	RED_INTEGER,

	// Depth/stencil
	DEPTH24STENCIL8,

	// Defaults
	Depth = DEPTH24STENCIL8
};

struct FramebufferTextureSpec
{
	FramebufferTextureSpec() = delete;
	FramebufferTextureSpec(FramebufferTextureFormat format) : textureFormat(format)
	{
	}
	FramebufferTextureFormat textureFormat{FramebufferTextureFormat::None};
};

struct FramebufferSpec
{
	FramebufferSpec() = delete;
	FramebufferSpec(uint32_t w,
					uint32_t h,
					uint32_t msaaSamples,
					std::initializer_list<FramebufferTextureSpec> colorAttachmentsSpec,
					FramebufferTextureSpec depthAttachmentSpec = FramebufferTextureFormat::None)
		: width(w), height(h), samples(msaaSamples), colorAttachments(colorAttachmentsSpec), depthAttachment(depthAttachmentSpec)
	{
	}

	uint32_t width{}, height{};
	std::vector<FramebufferTextureSpec> colorAttachments{};
	FramebufferTextureSpec depthAttachment{FramebufferTextureFormat::None};
	uint32_t samples{1};
};

class Framebuffer
{
private:
	uint32_t handle;
	std::vector<Texture> colors;
	uint32_t depth;

public:
	virtual void bind() = 0;
	virtual void draw() = 0;
	virtual void unbind() = 0;
	virtual uint32_t getHandle() = 0;
	virtual Texture getColorTexture(int idx) = 0;
};
}	 // namespace Mina

#endif