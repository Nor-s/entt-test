#ifndef MINA_RENDER_GL_GLFRAMEBUFFER_H
#define MINA_RENDER_GL_GLFRAMEBUFFER_H

#include "../Framebuffer.hpp"

namespace Mina::GL
{

class GLFramebufferFactory;

class GLFramebuffer : public Framebuffer
{
	friend class GLFramebufferFactory;

protected:
	GLFramebuffer();

	/**
	 * @pre need bind before call this
	 */
	void initColorAttachment(std::vector<std::unique_ptr<Texture>>&& colorTextures) override;

	/**
	 * @pre need bind before call this
	 */
	void addColorAttachment(std::unique_ptr<Texture> colorTexture) override;

	/**
	 * @pre need bind before call this
	 * @return old DepthAttachment
	 */
	DepthBufferHandle changeDepthAttachment(DepthBufferHandle DepthBuffer) override;

	bool checkStatus() override;

public:
	~GLFramebuffer();

	void bind() override;
	void unbind() override;
};

}	 // namespace Mina::GL

#endif