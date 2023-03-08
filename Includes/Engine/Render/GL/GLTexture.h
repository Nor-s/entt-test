//
// Created by Nor-s on 2023/02/27.
//

#ifndef MINA_GLTEXTURE_H
#define MINA_GLTEXTURE_H

#include "../Texture.h"

namespace Mina::GL
{
class GLTextureFactory;

class GLTexture : public Texture
{
	friend class GLTextureFactory;

protected:
	GLenum target{GL_TEXTURE_2D};

	/**
	 * for render texture
	 */
	explicit GLTexture(const MSize& textureSize, TextureFormat colorFormat = TextureFormat::RGBA8, int sampleNum = 1);

	/**
	 * for file texture
	 */
	explicit GLTexture(const std::string& filepath, TextureFormat colorFormat = TextureFormat::None);

	/**
	 * for embeded texture
	 */
	GLTexture(unsigned char* data, const MSize& textureSize);

public:
	GLTexture() = delete;
	~GLTexture();

	void bind() override;
	void unbind() override;

private:
	void setTexImage2D(unsigned char* data);
};

}	 // namespace Mina::GL

#endif	  // MINA_GLTEXTURE_H
