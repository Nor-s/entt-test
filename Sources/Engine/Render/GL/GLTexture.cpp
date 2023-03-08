//
// Created by Nor-s on 2023/02/27.
//
#include "Render/GL/GLTexture.h"
#include "Commons/Logger.h"

namespace Mina::GL
{

[[maybe_unused]] GLenum GetTextureTarget(int multiSample)
{
	return (multiSample > 1) ? GL_TEXTURE_2D_MULTISAMPLE : GL_TEXTURE_2D;
}

GLenum ConvertFormat(TextureFormat format)
{
	switch (format)
	{
		case TextureFormat::None:
			return GL_NONE;
		case TextureFormat::RGBA8:
			return GL_RGBA;
		case TextureFormat::RGB:
			return GL_RGB;
		case TextureFormat::RED_INTEGER:
			return GL_RED_INTEGER;
		default:
			return GL_RGBA;
	}
}

GLenum ConvertInternalFormat(TextureFormat format)
{
	switch (format)
	{
		case TextureFormat::None:
			return GL_NONE;
		case TextureFormat::RGBA8:
			return GL_RGBA8;
		case TextureFormat::RGB:
			return GL_RGB8;
		case TextureFormat::RED_INTEGER:
			return GL_R32I;
		default:
			return GL_RGBA8;
	}
}

GLenum GetDataType(TextureFormat format)
{
	switch (format)
	{
		case TextureFormat::RED_INTEGER:
			return GL_INT;
		default:
			return GL_UNSIGNED_BYTE;
	}
}

inline void SetTexParameteri(TextureFormat format)
{
	// http://blog.daechan.net/2018/07/555-3-4-mipmap.html
	switch (format)
	{
		case TextureFormat::RED_INTEGER:
			GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
			GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
			break;

		default:
			GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
			GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));
			GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
			GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR));
			break;
	}
}

inline TextureFormat GetFormat(int channels)
{
	if (channels == 1)
		return TextureFormat::RED_INTEGER;
	else if (channels == 3)
		return TextureFormat::RGB;
	else if (channels == 4)
		return TextureFormat::RGBA8;

	return TextureFormat::None;
}

GLTexture::GLTexture(const MSize& textureSize, TextureFormat colorFormat, int sampleNum)
{
	MINA_LOG("Texture size: {}, {}", textureSize.width, textureSize.height);

	size = textureSize;
	format = colorFormat;
	multiSample = sampleNum;
	target = GetTextureTarget(multiSample);

	GL_CALL(glGenTextures(1, &handle));

	GL_CALL(glBindTexture(target, handle));
	setTexImage2D(nullptr);
	glBindTexture(target, 0);
}

GLTexture::GLTexture(const std::string& filepath, TextureFormat colorFormat) : Texture(filepath, colorFormat)
{
	MINA_LOG("Texture path: {}", filepath);

	glGenTextures(1, &handle);
	glBindTexture(target, handle);

	int channels;
	unsigned char* data = stbi_load(path.c_str(), &size.width, &size.height, &channels, 0);
	if (data)
	{
		format = GetFormat(channels);

		if (colorFormat != TextureFormat::None)
		{
			format = colorFormat;
		}
		setTexImage2D(data);
	}
	else
	{
		MINA_CRITICAL("Texture failed to load at path: {}", path);
		format = TextureFormat::Error;
	}

	stbi_image_free(data);
	glBindTexture(target, 0);
}

GLTexture::GLTexture(unsigned char* data, const MSize& textureSize)
{
	MINA_LOG("Texture Load Memory");

	GL_CALL(glGenTextures(1, &handle));
	GL_CALL(glBindTexture(GL_TEXTURE_2D, handle));

	unsigned char* imageData = nullptr;
	int channels{};
	if (size.height == 0)
	{
		imageData = stbi_load_from_memory(reinterpret_cast<unsigned char*>(data), textureSize.width, &size.width,
										  &size.height, &channels, 0);
	}
	else
	{
		imageData =
			stbi_load_from_memory(reinterpret_cast<unsigned char*>(data), textureSize.width * textureSize.height,
								  &size.width, &size.height, &channels, 0);
	}

	format = GetFormat(channels);

	setTexImage2D(imageData);

	stbi_image_free(data);
	glBindTexture(target, 0);
}

void GLTexture::setTexImage2D(unsigned char* data)
{
	GLenum eFormat = ConvertFormat(format);
	GLenum iFormat = ConvertInternalFormat(format);
	GLenum dataType = GetDataType(format);

	if (multiSample > 1)
	{
		GL_CALL(
			glTexImage2DMultisample(GL_TEXTURE_2D_MULTISAMPLE, multiSample, iFormat, size.width, size.height, GL_TRUE));
	}
	else
	{
		SetTexParameteri(format);
		GL_CALL(glTexImage2D(GL_TEXTURE_2D, 0, static_cast<GLint>(iFormat), size.width, size.height, 0, eFormat,
							 dataType, data));
		GL_CALL(glGenerateMipmap(GL_TEXTURE_2D));
	}
}

GLTexture::~GLTexture()
{
	MINA_LOG("Texture Destroyed: {} {}", handle, path);

	if (format != TextureFormat::Error && format != TextureFormat::None)
	{
		glDeleteTextures(1, &handle);
		format = TextureFormat::None;
		size = {0, 0};
		type = {};
		path = {};
		multiSample = 1;
	}
}

void GLTexture::bind()
{
	glBindTexture(target, handle);
}

void GLTexture::unbind()
{
	glBindTexture(target, 0);
}

}	 // namespace Mina::GL