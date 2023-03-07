#ifndef MINA_COMPONENTS_RENDER_MESHCOMPONENT_HPP
#define MINA_COMPONENTS_RENDER_MESHCOMPONENT_HPP

#include "../pch.hpp"
#include "../../Render/Mesh.h"

namespace Mina
{


struct StaticMeshComponent
{
	std::unique_ptr<Mesh> mesh;
};

struct DynamicMeshComponent
{
	std::unique_ptr<Mesh> mesh;
};

};	  // namespace Mina

#endif