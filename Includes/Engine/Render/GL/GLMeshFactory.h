#ifndef MINA_RENDER_GL_GLMESHFACTORY_H
#define MINA_RENDER_GL_GLMESHFACTORY_H

#include "../MeshFactory.hpp"
#include "GLBuffers.hpp"

namespace Mina::GL
{
// Singleton
class GLMeshFactory : public MeshFactory
{
private:
public:
	GLMeshFactory();
	~GLMeshFactory();

	std::unique_ptr<Mesh> create(std::vector<Vertex>&& vertices,
								 std::vector<uint32_t>&& indices,
								 std::vector<std::unique_ptr<Texture>>&& textures,
								 Material& mat) override;

	std::unique_ptr<Mesh> create(std::vector<Vertex>&& vertices, std::vector<uint32_t>&& indices) override;

	std::unique_ptr<Mesh> create(std::vector<Vertex>&& vertices) override;
};
}	 // namespace Mina::GL

#endif