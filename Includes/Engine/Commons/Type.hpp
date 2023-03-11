#ifndef MINA_COMMONS_TYPE_HPP
#define MINA_COMMONS_TYPE_HPP

#define USE_OPENGL

#include <cstdint>

namespace Mina
{
using time_t = double;

#ifdef USE_OPENGL

using ShaderHandle = unsigned int;
using FramebufferHandle = unsigned int;
using DepthBufferHandle = unsigned int;
using TextureHandle = unsigned int;
using MeshHandle = unsigned int;
using UniformBufferHandle = unsigned int;

#else

using ShaderHandle = VkPipeline;
using FramebufferHandle = unsigned int;
using DepthBufferHandle = unsigned int;
using TextureHandle = unsigned int;
using MeshHandle = unsigned int;
using UniformBufferHandle = unsigned int;


#endif	  // USE_OPENGL

struct MSize
{
	int width{};
	int height{};
};

}	 // namespace Mina

#endif