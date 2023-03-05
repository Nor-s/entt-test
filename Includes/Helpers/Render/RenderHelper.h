#ifndef MINA_HELPERS_RENDER_RENDERHELPER_HPP
#define MINA_HELPERS_RENDER_RENDERHELPER_HPP

#include "../../Render/Mesh.h"
#include "../../Render/RenderAPI.h"
#include "../../Render/MeshFactory.hpp"

namespace Mina
{

std::unique_ptr<Mesh> CreateBiPyramid();

}	 // namespace Mina

#endif