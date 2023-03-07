//
// Created by No on 2023-03-06.
//

#ifndef MINA_GLUNIFORMBUFFER_H
#define MINA_GLUNIFORMBUFFER_H

#include "pch.hpp"
#include "Render/UniformBuffer.hpp"

namespace Mina::GL {

class GLUniformBuffer : public UniformBuffer{
private:
	int bindingPoint{};
public:
	GLUniformBuffer() = delete;
	GLUniformBuffer(const GLUniformBuffer&) = delete;
	GLUniformBuffer(GLUniformBuffer&&) = delete;

	GLUniformBuffer& operator=(const GLUniformBuffer&) = delete;
	GLUniformBuffer& operator=(GLUniformBuffer&&) = delete;

	GLUniformBuffer(std::initializer_list<ShaderHandle> shaderList, const std::string& name, size_t size, int bindingPoint)
		: bindingPoint(bindingPoint)
	{
		std::vector<ShaderHandle> shaderHandles{shaderList};
		for(auto& shaderHandle : shaderHandles)
		{
			auto uniformBlockIndex = glGetUniformBlockIndex(shaderHandle, name.c_str());
			glUniformBlockBinding(shaderHandle, uniformBlockIndex, this->bindingPoint);
		}

		glGenBuffers(1, &this->handle);
		glBindBuffer(GL_UNIFORM_BUFFER, this->handle);
		glBufferData(GL_UNIFORM_BUFFER, size, NULL, GL_STATIC_DRAW);
		glBindBuffer(GL_UNIFORM_BUFFER, 0);

		glBindBufferRange(GL_UNIFORM_BUFFER, 0, this->handle, 0, size);
	}

	~GLUniformBuffer() {
		glDeleteBuffers(1, &this->handle);
	}

	void setUniform(uint32_t offset, size_t size, const void* value) {
		glBindBuffer(GL_UNIFORM_BUFFER, this->handle);
		glBufferSubData(GL_UNIFORM_BUFFER, offset, size, value);
		glBindBuffer(GL_UNIFORM_BUFFER, 0);
	}
};

}

#endif	  // MINA_GLUNIFORMBUFFER_H
