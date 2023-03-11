//
// Created by No on 2023-03-11.
//

#ifndef MINA_SHADERMANAGER_H
#define MINA_SHADERMANAGER_H

#include "pch.hpp"
#include "Shader.h"
#include "UniformBuffer.hpp"

#ifdef USE_OPENGL
#include "GL/GLUniformBuffer.h"
#include "GL/GLShader.h"
#else
#error "Not implemented"
#endif

namespace Mina
{

class ShaderManager
{
private:
	/**
	 *	@tparam T  Components/Render/ component types
	 */
	template <typename T>
	std::unique_ptr<Shader>& getRawShader()
	{
		static std::unique_ptr<Shader> shader = nullptr;
		return shader;
	}

	/**
	 *	@tparam T  is struct for gpu data
	 */
	template <typename T>
	std::unique_ptr<UniformBuffer>& getRawUniformBuffer()
	{
		static std::unique_ptr<UniformBuffer> uniformBuffer = nullptr;
		return uniformBuffer;
	}

public:
	ShaderManager() = default;

	ShaderManager(const ShaderManager&) = delete;
	ShaderManager(ShaderManager&&) = delete;

	ShaderManager& operator=(const ShaderManager&) = delete;
	ShaderManager& operator=(ShaderManager&&) = delete;

	template <typename T>
	void setShader(std::string_view vertPath, std::string_view fragPath)
	{
#ifdef USE_OPENGL
		getRawShader<T>() = std::make_unique<GL::GLShader>(vertPath.data(), fragPath.data(), nullptr);
#else
		MINA_ERROR("Not implemented");
#endif
	}

	template <typename T>
	void setUniformBuffer(int bindingPoint)
	{
#ifdef USE_OPENGL
		getRawUniformBuffer<T>() = std::make_unique<GL::GLUniformBuffer>(sizeof(T), bindingPoint);
#else
		MINA_ERROR("Not implemented");
#endif
	}

	/**
	 *  @tparam T  is struct for gpu data
	 *  @tparam Ts Components/Render/ component types
	 */
	template <typename T, typename... Ts>
	void bindUniformBuffer(std::string_view name)
	{
		auto& uniformBuffer = getRawUniformBuffer<T>();
		assert(uniformBuffer);
		((uniformBuffer->bindShader(getRawShader<Ts>()->getHandle(), name)), ...);
	}

	/**
	 *  @tparam T  is struct for gpu data
	 *  @pre setUniformBuffer<T> must be called before this function
	 */
	template <typename T>
	UniformBuffer& getUniformBuffer()
	{
		auto& uniform = getRawUniformBuffer<T>();
		assert(uniform);
		return *uniform;
	}

	/**
	 *  @tparam T  Components/Render/ component types
	 *  @pre setShader<T> must be called before this function
	 */
	template <typename T>
	Shader& getShader()
	{
		auto& shader = getRawShader<T>();
		assert(shader);
		return *shader;
	}
};

}	 // namespace Mina

#endif	  // MINA_SHADERMANAGER_H
