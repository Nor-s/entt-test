//
// Created by No on 2023-03-11.
//

#include "Engine/Render/GL/GLUniformBuffer.h"

namespace Mina::GL
{
GLUniformBuffer::GLUniformBuffer(size_t size, int bindingPoint)
	: bindingPoint(bindingPoint)
{
	auto dataSize = static_cast<GLsizeiptr>(size);
	glGenBuffers(1, &this->handle);
	glBindBuffer(GL_UNIFORM_BUFFER, this->handle);
	glBufferData(GL_UNIFORM_BUFFER, dataSize, NULL, GL_STATIC_DRAW);
	glBindBuffer(GL_UNIFORM_BUFFER, 0);

	glBindBufferRange(GL_UNIFORM_BUFFER, this->bindingPoint, this->handle, 0, dataSize);
}

GLUniformBuffer::~GLUniformBuffer()
{
	glDeleteBuffers(1, &this->handle);
}

[[maybe_unused]] void GLUniformBuffer::bindShader(const ShaderHandle& shaderHandle, std::string_view name) const
{
	auto uniformBlockIndex = glGetUniformBlockIndex(shaderHandle, name.data());
	glUniformBlockBinding(shaderHandle, uniformBlockIndex, this->bindingPoint);
}

void GLUniformBuffer::setUniform(size_t offset, size_t size, const void* value)
{
	glBindBuffer(GL_UNIFORM_BUFFER, this->handle);
	glBufferSubData(GL_UNIFORM_BUFFER, static_cast<GLsizeiptr>(offset), static_cast<GLsizeiptr>(size), value);
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

}	 // namespace Mina::GL