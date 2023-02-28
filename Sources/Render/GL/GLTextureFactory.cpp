#include "Render/GL/GLTexture.h"
#include "Render/GL/GLTextureFactory.h"

namespace Mina::GL
{
GLTextureFactory::GLTextureFactory() = default;
GLTextureFactory::~GLTextureFactory() = default;

std::unique_ptr<Texture> GLTextureFactory::create(const MSize& _size, TextureFormat _format, int _multiSample)
{
	return std::unique_ptr<Texture>(new GLTexture(_size, _format, _multiSample));
}
std::unique_ptr<Texture> GLTextureFactory::create(std::string_view _path, TextureFormat _format)
{
	return std::unique_ptr<Texture>(new GLTexture(std::string(_path.data()), _format));
}
std::unique_ptr<Texture> GLTextureFactory::create(unsigned char* data, const MSize& _size)
{
	return std::unique_ptr<Texture>(new GLTexture(data, _size));
}

}	 // namespace Mina::GL