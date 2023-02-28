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
	NONE = 0,
	RGBA8,
	RGB,
	RED_INTEGER,
	ERROR
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
	explicit Texture(std::string _path, const TextureFormat& _format = TextureFormat::NONE);
	Texture();

public:
	virtual ~Texture();

	virtual void bind() = 0;
	virtual void unbind() = 0;

	operator const TextureHandle&() const
	{
		return handle;
	}

	[[nodiscard]] const MSize& getSize() const;
	[[nodiscard]] const std::string& getType() const;
	[[nodiscard]] const std::string& getPath() const;
	[[nodiscard]] TextureFormat getFormat() const;
};

}	 // namespace Mina

#endif	  // MINA_TEXTURE_HPP
