#include "Render/Texture.h"

namespace Mina
{
Texture::Texture(std::string filepath, const TextureFormat& colorFormat)
	: path(std::move(filepath)), format(colorFormat)
{
}

Texture::Texture() = default;
Texture::~Texture() = default;

[[nodiscard]] const TextureHandle& Texture::getHandle() const
{
	return handle;
}

[[nodiscard]] const MSize& Texture::getSize() const
{
	return size;
}

[[nodiscard]] const std::string& Texture::getType() const
{
	return type;
}

[[nodiscard]] const std::string& Texture::getPath() const
{
	return path;
}

[[nodiscard]] TextureFormat Texture::getFormat() const
{
	return format;
}

[[nodiscard]] int Texture::getMultiSampleNum() const
{
	return multiSample;
}

}	 // namespace Mina