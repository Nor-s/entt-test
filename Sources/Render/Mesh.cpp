#include "Render/Mesh.h"

namespace Mina
{

Mesh::Mesh(std::vector<Vertex>&& _vertices,
		   std::vector<uint32_t>&& _indices,
		   std::vector<std::unique_ptr<Texture>>&& _textures,
		   Material& _mat)
	: vertices(std::move(_vertices)), indices(std::move(_indices)), textures(std::move(_textures)), material(_mat)
{
}

Mesh::Mesh(std::vector<Vertex>&& _vertices, std::vector<uint32_t>&& _indices)
	: vertices(std::move(_vertices)), indices(std::move(_indices))
{
}

Mesh::Mesh(std::vector<Vertex>&& _vertices) : vertices(std::move(_vertices))
{
}

const Material& Mesh::getMaterial() const
{
	return material;
}

const std::vector<Vertex>& Mesh::getVertices() const
{
	return vertices;
}

const std::vector<uint32_t>& Mesh::getIndices() const
{
	return indices;
}

const std::vector<std::unique_ptr<Texture>>& Mesh::getTextures() const
{
	return textures;
}

}	 // namespace Mina