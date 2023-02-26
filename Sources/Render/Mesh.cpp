#include "Render/Mesh.h"

namespace Mina
{
Mesh::Mesh(std::vector<Vertex>&& _vertices, std::vector<uint32_t>&& _indices, std::vector<Texture>&& _textures, Material&& _mat)
	: vertices(std::move(_vertices)), indices(std::move(_indices)), textures(std::move(_textures)), material(std::move(_mat))
{
}
Mesh::Mesh(std::vector<Vertex>&& _vertices, std::vector<uint32_t>&& _indices)
	: vertices(std::move(_vertices)), indices(std::move(_indices))
{
}

Mesh::Mesh(std::vector<Vertex>&& _vertices) : vertices(std::move(_vertices))
{
}
}	 // namespace Mina