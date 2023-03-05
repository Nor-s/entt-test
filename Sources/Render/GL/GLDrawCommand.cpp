#include "Render/GL/GLDrawCommand.h"
#include "Render/Shader.hpp"
#include "Render/Mesh.h"

#include "Render/GL/GLShader.h"
#include "Render/GL/GLMesh.h"

namespace Mina::GL
{

void SetMaterial(Shader& shader, const Material& material)
{
	GlUniformVec3(shader, "material.ambient", material.ambient);
	GlUniformVec3(shader, "material.diffuse", material.diffuse);
	GlUniformVec3(shader, "material.specular", material.specular);
	GlUniformFloat(shader, "material.shininess", material.shininess);
	GlUniformBool(shader, "material.hasDiffuseTexture", material.hasDiffuseTexture);
}

void BindTexture(Shader& shader, const std::vector<std::unique_ptr<Texture>>& textures)
{
	int size = static_cast<int>(textures.size());
	for (int i = 0; i < size; i++)
	{
		std::string name = textures[i]->getType();

		glActiveTexture(GL_TEXTURE0 + i);
		GlUniformInt(shader, name.c_str(), i);
		textures[i]->bind();
	}
}
void DrawMesh(Shader& shader, const Mesh& mesh) {
	const auto&  material = mesh.getMaterial();
	const auto&  textures = mesh.getTextures();
	const auto&  indices = mesh.getIndices();

	SetMaterial(shader, material);
	BindTexture(shader, textures);

	// draw mesh
	{
		const MeshHandle& meshHandle = mesh;
		glBindVertexArray(meshHandle);
		if (!indices.empty())
		{
			glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_INT, 0);
		}
		else
		{
			auto& vertices = mesh.getVertices();
			glDrawArrays(GL_TRIANGLES, 0, static_cast<int>(vertices.size()));
		}
		glBindVertexArray(0);
	}

	glActiveTexture(GL_TEXTURE0);
}

void GLDrawCommand::drawBasicMesh(Shader& shader, const Mesh& mesh)
{
	DrawMesh(shader, mesh);
}

DrawFunction GLDrawCommand::getDrawBasicFunction()
{
	return &DrawMesh;
}

}	 // namespace Mina::GL