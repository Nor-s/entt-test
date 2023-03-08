//
// Created by Nor-s on 2023/02/27.
//

#ifndef MINA_GLTEXTUREFACTORY_H
#define MINA_GLTEXTUREFACTORY_H

#include "../TextureFactory.hpp"

namespace Mina::GL
{

class GLTextureFactory : public TextureFactory
{
public:
	GLTextureFactory();
	~GLTextureFactory();
	std::unique_ptr<Texture> create(const MSize& size, TextureFormat format, int multiSample) override;
	std::unique_ptr<Texture> create(std::string_view path, TextureFormat format) override;
	std::unique_ptr<Texture> create(unsigned char* data, const MSize& size) override;
};

}	 // namespace Mina::GL

#endif	  // MINA_GLTEXTUREFACTORY_H
