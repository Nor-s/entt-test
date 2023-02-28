#include "Render/Texture.h"

namespace Mina
{
Texture::Texture(std::string _path, const TextureFormat& _format) : path(std::move(_path)), format(_format)
{
}
Texture::Texture() = default;
Texture::~Texture() = default;

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

}	 // namespace Mina