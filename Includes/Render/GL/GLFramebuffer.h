#ifndef MINA_RENDER_GL_GLFRAMEBUFFER_H
#define MINA_RENDER_GL_GLFRAMEBUFFER_H

#include "../Framebuffer.hpp"

namespace Mina::GL
{

class GLFramebufferFactory;

class GLFramebuffer : public Framebuffer
{
	friend class GLFramebufferFactory;

private:
	bool isValid{true};

protected:
	explicit GLFramebuffer(const FramebufferSpec& spec);

	void init();

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
	void resize(const MSize& size) override;
};

}	 // namespace Mina::GL

#endif