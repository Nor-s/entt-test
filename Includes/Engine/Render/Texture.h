//
// Created by Nor-s on 2023/02/27.
//

#ifndef MINA_TEXTURE_H
#define MINA_TEXTURE_H

#include "pch.hpp"
#include "Commons/Type.hpp"

namespace Mina
{

enum class TextureFormat
{
	None = 0,
	RGBA8,
	RGB,
	RED_INTEGER,
	Error
};

class TextureFactory;

class Texture
{
	friend class TextureFactory;

protected:
	MSize size{};

protected:
	std::string type{};
	std::string path{};
	TextureFormat format{};
	TextureHandle handle{};
	int multiSample{1};

protected:
	explicit Texture(std::string filepath, const TextureFormat& colorFormat = TextureFormat::None);
	Texture();

public:
	virtual ~Texture();

	virtual void bind() = 0;
	virtual void unbind() = 0;

	operator const TextureHandle&() const
	{
		return handle;
	}

	[[nodiscard]] const TextureHandle& getHandle() const;
	[[nodiscard]] const MSize& getSize() const;
	[[nodiscard]] const std::string& getType() const;
	[[nodiscard]] const std::string& getPath() const;
	[[nodiscard]] TextureFormat getFormat() const;
	[[nodiscard]] int getMultiSampleNum() const;
};

}	 // namespace Mina

#endif	  // MINA_TEXTURE_HPP
