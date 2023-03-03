#ifndef MINA_RENDER_GL_GL_MESH_H
#define MINA_RENDER_GL_GL_MESH_H

#include "../Mesh.h"
#include "GLBuffers.hpp"

namespace Mina::GL
{
class GLMeshFactory;

class GLMesh final : public Mesh
{
private:
	friend class GLMeshFactory;

	GLVertexBuffers buffers{};

private:
	GLMesh(std::vector<Vertex>&& vertices,
		   std::vector<uint32_t>&& indices,
		   std::vector<std::unique_ptr<Texture>>&& textures,
		   Material& mat);

	GLMesh(std::vector<Vertex>&& vertices, std::vector<uint32_t>&& indices);
	explicit GLMesh(std::vector<Vertex>&& vertices);

	void initBuffer();

public:
	GLMesh() = delete;
	GLMesh(const GLMesh&) = delete;
	GLMesh(GLMesh&&) = delete;

	GLMesh& operator=(const GLMesh&) = delete;
	GLMesh& operator=(GLMesh&&) = delete;

	~GLMesh() override;
};

}	 // namespace Mina::GL

#endif
