#include "Render/RenderAPI.h"
#include "Render/MeshFactory.hpp"
#include "Render/FramebufferFactory.hpp"
#include "Render/Shader.h"
#include "Render/UniformBuffer.hpp"

#ifdef USE_OPENGL
#include "Render/GL/GLMeshFactory.h"
#include "Render/GL/GLFramebufferFactory.h"
#include "Render/GL/GLShader.h"
#include "Render/GL/GLUniformBuffer.h"
#endif

#include "Commons/Logger.h"
#include "Commons/Type.hpp"

namespace Mina
{

RenderAPI::RenderAPI()
{
#ifdef USE_OPENGL
	meshFactory = std::make_unique<GL::GLMeshFactory>();
	framebufferFactory = std::make_unique<GL::GLFramebufferFactory>();
#endif
}

RenderAPI::~RenderAPI() = default;

MeshFactory& RenderAPI::getMeshFactory() const
{
	return *meshFactory;
}

FramebufferFactory& RenderAPI::getFramebufferFactory() const
{
	return *framebufferFactory;
}

std::unique_ptr<Shader> RenderAPI::createShader(std::string_view vertPath, std::string_view fragPath)
{
#ifdef USE_OPENGL
	return std::make_unique<GL::GLShader>(vertPath.data(), fragPath.data(), nullptr);
#else
	return nullptr;
#endif
}

std::unique_ptr<UniformBuffer> RenderAPI::createUniformBuffer(std::initializer_list<ShaderHandle> shaderList,
															  const std::string& name,
															  size_t size,
															  int bindingPoint)
{
#ifdef USE_OPENGL
	return std::make_unique<GL::GLUniformBuffer>(shaderList, name, size, bindingPoint);
#else
	return nullptr;
#endif
}

}	 // namespace Mina
