#include "Render/GL/GLMesh.h"
#include "Render/GL/GLMeshFactory.h"

namespace Mina::GL
{
std::unique_ptr<Mesh> GLMeshFactory::create(std::vector<Vertex>&& vertices,
											std::vector<uint32_t>&& indices,
											std::vector<Texture>&& textures,
											Material&& mat)
{
	return std::unique_ptr<Mesh>(new GLMesh(std::move(vertices), std::move(indices), std::move(textures), std::move(mat)));
}

std::unique_ptr<Mesh> GLMeshFactory::create(std::vector<Vertex>&& vertices, std::vector<uint32_t>&& indices)
{
	return std::unique_ptr<Mesh>(new GLMesh(std::move(vertices), std::move(indices)));
}

std::unique_ptr<Mesh> GLMeshFactory::create(std::vector<Vertex>&& vertices)
{
	return std::unique_ptr<Mesh>(new GLMesh(std::move(vertices)));
}

}	 // namespace Mina::GL