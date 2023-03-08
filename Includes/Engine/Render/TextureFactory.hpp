#ifndef MINA_TEXTURE_FACTORY_HPP
#define MINA_TEXTURE_FACTORY_HPP

#include "../pch.hpp"
#include "../Commons/Type.hpp"
#include "Texture.h"

namespace Mina
{

class TextureFactory
{
public:
	TextureFactory() = default;
	virtual ~TextureFactory() = default;
	virtual std::unique_ptr<Texture> create(const MSize& _size, TextureFormat _format, int _multiSample) = 0;
	virtual std::unique_ptr<Texture> create(std::string_view _path, TextureFormat _format) = 0;
	virtual std::unique_ptr<Texture> create(unsigned char* data, const MSize& _size) = 0;
};

}	 // namespace Mina

#endif