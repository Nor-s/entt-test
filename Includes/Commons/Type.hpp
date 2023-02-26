#ifndef MINA_COMMONS_TYPE_HPP
#define MINA_COMMONS_TYPE_HPP

#define USE_OPENGL

namespace Mina
{
using time_t = double;

#ifdef USE_OPENGL
using ShaderHandle = unsigned int;
#else
using ShaderHandle = VkPipeline;
#endif

}	 // namespace Mina

#endif