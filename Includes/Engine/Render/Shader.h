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
	Shader();
	virtual ~Shader();
	virtual void bind() = 0;
	virtual void unbind() = 0;

	[[nodiscard]] const ShaderHandle& getHandle() const
	{
		return handle;
	}
};

}	 // namespace Mina
#endif