//
// Created by No on 2023-03-06.
//

#ifndef MINA_UNIFORMBUFFER_HPP
#define MINA_UNIFORMBUFFER_HPP

#include "../pch.hpp"
#include "../Commons/Type.hpp"


namespace Mina
{

class UniformBuffer
{
protected:
	UniformBufferHandle handle{};

public:
	UniformBuffer() = default;

	UniformBuffer(const UniformBuffer&) = delete;
	UniformBuffer(UniformBuffer&&) = delete;

	UniformBuffer& operator=(const UniformBuffer&) = delete;
	UniformBuffer& operator=(UniformBuffer&&) = delete;

	virtual ~UniformBuffer() = default;

	[[maybe_unused]] virtual void bindShader(const ShaderHandle& shaderHandle, std::string_view name) const = 0;
	virtual void setUniform(size_t offset, size_t size, const void* value) = 0;

};

}	 // namespace Mina

#endif	  // MINA_UNIFORMBLOCK_HPP
