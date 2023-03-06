//
// Created by No on 2023-03-06.
//

#ifndef MINA_GLUNIFORMBUFFER_H
#define MINA_GLUNIFORMBUFFER_H

#include "pch.hpp"
#include "Render/UniformBuffer.hpp"

namespace Mina::GL {

template<typename T>
class GLUniformBuffer : public UniformBuffer<T> {
private:
	int location{};
public:
	GLUniformBuffer() = delete;
	GLUniformBuffer(const GLUniformBuffer&) = delete;
	GLUniformBuffer(GLUniformBuffer&&) = delete;

	GLUniformBuffer& operator=(const GLUniformBuffer&) = delete;
	GLUniformBuffer& operator=(GLUniformBuffer&&) = delete;

	GLUniformBuffer(std::initializer_list<ShaderHandle> shaderList, const std::string& name, int location)
		: location(location)
	{
		std::vector<ShaderHandle> shaderHandles{shaderList};
		for(auto& shaderHandle : shaderHandles)
		{
			auto uniformBlockId = glGetUniformBlockIndex(shaderHandle, name.c_str());
			glUniformBlockBinding(shaderHandle, uniformBlockId, this->location);
		}

		glGenBuffers(1, &this->handle);
		glBindBuffer(GL_UNIFORM_BUFFER, this->handle);
		glBufferData(GL_UNIFORM_BUFFER, 2 * sizeof(glm::mat4), NULL, GL_STATIC_DRAW);
		glBindBuffer(GL_UNIFORM_BUFFER, 0);

		glBindBufferRange(GL_UNIFORM_BUFFER, 0, this->handle, 0, 2 * sizeof(glm::mat4));
	}

	~GLUniformBuffer() {
		glDeleteBuffers(1, &handle);
	}

	/**
	 * @param value: must raw type (ex. glm::value_ptr(projection))
	 */
	template<typename V>
	void setUniform(uint32_t offset, size_t size, V value) {
		glBindBuffer(GL_UNIFORM_BUFFER, handle);
		glBufferSubData(GL_UNIFORM_BUFFER, offset, size, value);
		glBindBuffer(GL_UNIFORM_BUFFER, 0);
	}
};

}

#endif	  // MINA_GLUNIFORMBUFFER_H
