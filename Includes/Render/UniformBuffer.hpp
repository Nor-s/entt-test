//
// Created by No on 2023-03-06.
//

#ifndef MINA_UNIFORMBUFFER_HPP
#define MINA_UNIFORMBUFFER_HPP

#include "pch.hpp"
#include "Commons/Type.hpp"

namespace Mina
{

template<typename T>
class UniformBuffer
{
protected:
	uint32_t handle{};

public:
	UniformBuffer() = default;

	UniformBuffer(const UniformBuffer&) = delete;
	UniformBuffer(UniformBuffer&&) = delete;

	UniformBuffer& operator=(const UniformBuffer&) = delete;
	UniformBuffer& operator=(UniformBuffer&&) = delete;

	virtual ~UniformBuffer() = default;

//	void setUniform(const std::string& name, const void* data, uint32_t size);
};

}	 // namespace Mina

#endif	  // MINA_UNIFORMBLOCK_HPP
