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

std::unique_ptr<RenderAPI> RenderAPI::instance(new RenderAPI());

RenderAPI::RenderAPI()
{
	meshFactory = std::make_unique<GL::GLMeshFactory>();
	framebufferFactory = std::make_unique<GL::GLFramebufferFactory>();
}

RenderAPI::~RenderAPI()
{
}

RenderAPI& RenderAPI::get()
{
	return *instance;
}

MeshFactory& RenderAPI::getMeshFactory()
{
	return *meshFactory;
}

FramebufferFactory& RenderAPI::getFramebufferFactory()
{
	return *framebufferFactory;
}

}	 // namespace Mina
