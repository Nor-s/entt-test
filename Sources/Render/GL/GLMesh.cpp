#include "pch.hpp"
#include "Render/GL/GLShader.h"
#include "Render/GL/GLMesh.h"

namespace Mina::GL
{

GLMesh::GLMesh(std::vector<Vertex>&& vertices,
			   std::vector<uint32_t>&& indices,
			   std::vector<std::unique_ptr<Texture>>&& textures,
			   Material& mat)
	: Mesh(std::move(vertices), std::move(indices), std::move(textures), mat)
{
	initBuffer();
}

GLMesh::GLMesh(std::vector<Vertex>&& vertices, std::vector<uint32_t>&& indices)
	: Mesh(std::move(vertices), std::move(indices))
{
	initBuffer();
}

GLMesh::GLMesh(std::vector<Vertex>&& vertices) : Mesh(std::move(vertices))
{
	initBuffer();
}

void GLMesh::initBuffer()
{
	glGenVertexArrays(1, &buffers.VAO);
	glGenBuffers(1, &buffers.VBO);

	glBindVertexArray(buffers.VAO);
	glBindBuffer(GL_ARRAY_BUFFER, buffers.VBO);

	glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(vertices.size() * sizeof(Vertex)), &vertices[0],
				 GL_STATIC_DRAW);
	if (!indices.empty())
	{
		glGenBuffers(1, &buffers.EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers.EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, static_cast<GLsizeiptr>(indices.size() * sizeof(unsigned int)),
					 &indices[0], GL_STATIC_DRAW);
	}

	glEnableVertexAttribArray(0);
	// vertex position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) 0);
	// vertex normals
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, normal));
	// vertex texture coords
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, texCoords));

	// vertex tangent
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, tangent));
	// vertex biTangent
	glEnableVertexAttribArray(4);
	glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, bitangent));
	// ids
	glEnableVertexAttribArray(5);
	glVertexAttribIPointer(5, 4, GL_INT, sizeof(Vertex), (void*) offsetof(Vertex, boneIds));
	// weights
	glEnableVertexAttribArray(6);
	glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, weights));
	glBindVertexArray(0);
}

GLMesh::~GLMesh()
{
	glDeleteVertexArrays(1, &buffers.VAO);
	glDeleteBuffers(1, &buffers.VBO);
	glDeleteBuffers(1, &buffers.EBO);
}

void GLMesh::draw(Shader& shader)
{
	// set material
	{
		GlUniformVec3(shader, "material.ambient", material.ambient);
		GlUniformVec3(shader, "material.diffuse", material.diffuse);
		GlUniformVec3(shader, "material.specular", material.specular);
		GlUniformFloat(shader, "material.shininess", material.shininess);
		GlUniformBool(shader, "material.hasDiffuseTexture", material.hasDiffuseTexture);
	}

	// bind texture
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

	// draw mesh
	{
		glBindVertexArray(buffers.VAO);
		if (!indices.empty())
		{
			glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_INT, 0);
		}
		else
		{
			glDrawArrays(GL_TRIANGLES, 0, static_cast<int>(vertices.size()));
		}
		glBindVertexArray(0);
	}

	glActiveTexture(GL_TEXTURE0);
}

}	 // namespace Mina::GL