#ifndef MINA_RENDER_SHADER_HPP
#define MINA_RENDER_SHADER_HPP

#include "../Commons/Type.hpp"
#include "pch.hpp"

namespace Mina
{

class Shader
{
protected:
	ShaderHandle handle;

public:
	Shader() = default;
	virtual ~Shader() = default;
	virtual void bind() = 0;
	virtual void unbind() = 0;

	const ShaderHandle& getHandle() const
	{
		return handle;
	}
};

}	 // namespace Mina
#endif