#ifndef MINA_RENDER_SHADER_HPP
#define MINA_RENDER_SHADER_HPP

#include "../Commons/Type.hpp"
#include "pch.hpp"

namespace Mina
{

class Shader
{
public:
	Shader(const Shader&) = delete;
	Shader(Shader&&) = delete;

	Shader& operator=(const Shader&) = delete;
	Shader& operator=(Shader&&) = delete;

	Shader();
	virtual ~Shader();

	virtual void bind() = 0;
	virtual void unbind() = 0;
	[[nodiscard]] virtual const ShaderHandle& getHandle() const = 0;
};

}	 // namespace Mina
#endif