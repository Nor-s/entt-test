#ifndef MINA_RENDER_FRAMEBUFFER_HPP
#define MINA_RENDER_FRAMEBUFFER_HPP

#include "pch.hpp"

#include "../Commons/Type.hpp"
#include "Mesh.h"
#include "Texture.h"

namespace Mina
{
using FramebufferTextureFormat = TextureFormat;

enum class DepthFormat
{
	NONE = 0,
	// Depth/stencil
	DEPTH24STENCIL8,

	// Defaults
	Depth = DEPTH24STENCIL8
};

struct FramebufferSpec
{
	FramebufferSpec() = delete;
	FramebufferSpec(MSize _size,
					std::initializer_list<FramebufferTextureFormat> colors,
					DepthFormat depthAttachmentSpec = DepthFormat::NONE)
		: size(_size), colorAttachments(colors), depthAttachment(depthAttachmentSpec)
	{
	}

	MSize size;
	uint32_t samples{1};
	std::vector<FramebufferTextureFormat> colorAttachments{};
	DepthFormat depthAttachment{DepthFormat::NONE};
};

class Framebuffer
{
protected:
	FramebufferSpec spec;
	FramebufferHandle handle{};
	std::vector<std::unique_ptr<Texture>> colors;
	DepthBufferHandle depth{};

protected:
	Framebuffer() : spec({{1, 1}, {}})
	{
	}

	//	void initColorAttachment(std::vector<Texture> colors) = 0;

public:
	Framebuffer(const Framebuffer&) = delete;
	Framebuffer(Framebuffer&&) = delete;

	Framebuffer& operator=(const Framebuffer&) = delete;
	Framebuffer& operator=(Framebuffer&&) = delete;

	virtual ~Framebuffer() = default;

	virtual void bind() = 0;
	virtual void unbind() = 0;

	explicit operator const FramebufferHandle&() const
	{
		return handle;
	}

	Texture& getColorTexture(int idx)
	{
		return *colors[idx];
	}

	FramebufferHandle& getHandle()
	{
		return handle;
	}

	FramebufferSpec& getSpec()
	{
		return spec;
	}
};
}	 // namespace Mina

#endif