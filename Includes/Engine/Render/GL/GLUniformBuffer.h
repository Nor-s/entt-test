//
// Created by No on 2023-03-06.
//

#ifndef MINA_GLUNIFORMBUFFER_H
#define MINA_GLUNIFORMBUFFER_H

#include "pch.hpp"
#include "Render/UniformBuffer.hpp"

namespace Mina::GL
{

class GLUniformBuffer : public UniformBuffer
{
private:
	int bindingPoint{};

public:
	GLUniformBuffer() = delete;
	GLUniformBuffer(const GLUniformBuffer&) = delete;
	GLUniformBuffer(GLUniformBuffer&&) = delete;

	GLUniformBuffer& operator=(const GLUniformBuffer&) = delete;
	GLUniformBuffer& operator=(GLUniformBuffer&&) = delete;

	GLUniformBuffer(size_t size, int bindingPoint);

	~GLUniformBuffer();

	[[maybe_unused]] void bindShader(const ShaderHandle& shaderHandle, std::string_view name) const override;
	void setUniform(size_t offset, size_t size, const void* value) override;
};

}	 // namespace Mina::GL

#endif	  // MINA_GLUNIFORMBUFFER_H
