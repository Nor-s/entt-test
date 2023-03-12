#include "Engine/Render/RenderAPI.h"
#include "Engine/Render/MeshFactory.hpp"
#include "Engine/Render/FramebufferFactory.hpp"
#include "Engine/Render/Shader.h"
#include "Engine/Render/ShaderManager.h"

#ifdef USE_OPENGL
#include "Engine/Render/GL/GLMeshFactory.h"
#include "Engine/Render/GL/GLFramebufferFactory.h"
#include "Engine/Render/GL/GLShader.h"
#endif

#include "Engine/Commons/Logger.h"
#include "Engine/Commons/Type.hpp"

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

ShaderManager& RenderAPI::getShaderManager() const
{
	return *shaderManager;
}




}	 // namespace Mina
