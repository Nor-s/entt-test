#include "Render/RenderAPI.h"
#include "Commons/Logger.h"
#include "Commons/Type.hpp"

#include "Render/MeshFactory.hpp"

#ifdef USE_OPENGL
#include "Render/GL/GLMeshFactory.h"
#else

#endif

namespace Mina
{

std::unique_ptr<RenderAPI> RenderAPI::instance(new RenderAPI());

RenderAPI::RenderAPI()
{
	meshFactory = std::make_unique<GL::GLMeshFactory>();
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

}	 // namespace Mina
