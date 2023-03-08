#include "Render/GL/GLTexture.h"
#include "Render/GL/GLTextureFactory.h"
#include "Commons/Logger.h"

namespace Mina::GL
{

GLTextureFactory::GLTextureFactory() = default;
GLTextureFactory::~GLTextureFactory() = default;

std::unique_ptr<Texture> GLTextureFactory::create(const MSize& size, TextureFormat format, int multiSample)
{
	MINA_LOG("Creating texture: size: {}, {}", size.width, size.height);
	return std::unique_ptr<Texture>(new GLTexture(size, format, multiSample));
}

std::unique_ptr<Texture> GLTextureFactory::create(std::string_view path, TextureFormat format)
{
	MINA_LOG("Creating texture: path: {}", path);
	return std::unique_ptr<Texture>(new GLTexture(std::string(path.data()), format));
}

std::unique_ptr<Texture> GLTextureFactory::create(unsigned char* data, const MSize& size)
{
	MINA_LOG("Creating texture: data: {}, {}", size.width, size.height);
	return std::unique_ptr<Texture>(new GLTexture(data, size));
}

}	 // namespace Mina::GL