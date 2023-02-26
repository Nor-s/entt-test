#ifndef MINA_RENDER_MESHFACTORY_HPP
#define MINA_RENDER_MESHFACTORY_HPP

#include "../pch.hpp"
#include "Mesh.h"

namespace Mina
{

class MeshFactory
{
private:
public:
	virtual std::unique_ptr<Mesh> create(std::vector<Vertex>&& vertices,
										 std::vector<uint32_t>&& indices,
										 std::vector<Texture>&& textures,
										 Material&& mat) = 0;

	virtual std::unique_ptr<Mesh> create(std::vector<Vertex>&& vertices, std::vector<uint32_t>&& indices) = 0;

	virtual std::unique_ptr<Mesh> create(std::vector<Vertex>&& vertices) = 0;
};

}	 // namespace Mina

#endif