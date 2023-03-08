#include "Render/GL/GLDrawCommand.h"
#include "Render/Shader.h"
#include "Render/Mesh.h"

#include "Render/GL/GLShader.h"
#include "Render/GL/GLMesh.h"
#include "Commons/Logger.h"

namespace Mina::GL
{

void SetMaterial(Shader& shader, const Material& material)
{
	GL_CALL(GlUniformVec3(shader, "material.ambient", material.ambient));
	GL_CALL(GlUniformVec3(shader, "material.diffuse", material.diffuse));
	GL_CALL(GlUniformVec3(shader, "material.specular", material.specular));
	GL_CALL(GlUniformFloat(shader, "material.shininess", material.shininess));
	GL_CALL(GlUniformBool(shader, "material.hasDiffuseTexture", material.hasDiffuseTexture));
}

void BindTexture(Shader& shader, const std::vector<std::unique_ptr<Texture>>& textures)
{
	int size = static_cast<int>(textures.size());
	for (int i = 0; i < size; i++)
	{
		std::string name = textures[i]->getType();

		GL_CALL(glActiveTexture(GL_TEXTURE0 + i));
		GlUniformInt(shader, name.c_str(), i);
		textures[i]->bind();
	}
}

void DrawMesh(Shader& shader, const Mesh& mesh, const glm::mat4& worldTransform)
{
	const auto& material = mesh.getMaterial();
	const auto& textures = mesh.getTextures();
	const auto& indices = mesh.getIndices();

	SetMaterial(shader, material);
	BindTexture(shader, textures);

	GL_CALL(GlUniformMat4(shader, "world", worldTransform));

	// draw mesh
	{
		const MeshHandle& meshHandle = mesh;
		GL_CALL(glBindVertexArray(meshHandle));
		if (!indices.empty())
		{
			GL_CALL(glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_INT, 0));
		}
		else
		{
			auto& vertices = mesh.getVertices();
			GL_CALL(glDrawArrays(GL_TRIANGLES, 0, static_cast<int>(vertices.size())));
		}
		GL_CALL(glBindVertexArray(0));
	}

	glActiveTexture(GL_TEXTURE0);
}

void GLDrawCommand::drawBasicMesh(Shader& shader, const Mesh& mesh, const glm::mat4& worldTransform)
{
	DrawMesh(shader, mesh, worldTransform);
}

DrawFunction GLDrawCommand::getDrawBasicFunction()
{
	return &DrawMesh;
}

}	 // namespace Mina::GL