#ifndef MINA_RENDER_FRAMEBUFFER_HPP
#define MINA_RENDER_FRAMEBUFFER_HPP

#include <utility>

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
	int multiSampleNum{1};
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
	explicit Framebuffer(FramebufferSpec spec)
		: spec(std::move(spec))
	{
	}

	/**
	 * @pre need bind before call this
	 */
	virtual void addColorAttachment(std::unique_ptr<Texture> colorTexture) = 0;

	/**
	 * @return old DepthAttachment
	 */
	virtual DepthBufferHandle changeDepthAttachment(DepthBufferHandle depthBuffer) = 0;

	virtual bool checkStatus() = 0;

public:
	Framebuffer(const Framebuffer&) = delete;
	Framebuffer(Framebuffer&&) = delete;

	Framebuffer& operator=(const Framebuffer&) = delete;
	Framebuffer& operator=(Framebuffer&&) = delete;

	virtual ~Framebuffer() = default;

	virtual void clear() = 0;
	virtual void bind() = 0;
	virtual void unbind() = 0;
	virtual void resize(const MSize& size) = 0;

	explicit operator const FramebufferHandle&() const
	{
		return handle;
	}

	[[nodiscard]] const Texture& getColorTexture(int idx) const
	{
		assert(idx < colors.size());

		return *colors[idx];
	}

	[[nodiscard]] const FramebufferHandle& getHandle() const
	{
		return handle;
	}

	[[nodiscard]] const FramebufferSpec& getSpec() const
	{
		return spec;
	}

	[[nodiscard]] const MSize& getSize() const
	{
		return spec.size;
	}

};

}	 // namespace Mina

#endif