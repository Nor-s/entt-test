#include "Render/RenderAPI.h"
#include "Render/MeshFactory.hpp"
#include "Render/FramebufferFactory.hpp"

#ifdef USE_OPENGL
#include "Render/GL/GLMeshFactory.h"
#include "Render/GL/GLFramebufferFactory.h"
#endif

#include "Commons/Logger.h"
#include "Commons/Type.hpp"

namespace Mina
{

RenderAPI::RenderAPI()
{
	meshFactory = std::make_unique<GL::GLMeshFactory>();
	framebufferFactory = std::make_unique<GL::GLFramebufferFactory>();
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

}	 // namespace Mina
