#include "pch.hpp"
#include "Render/GL/GLMesh.h"

namespace Mina::GL
{

GLMesh::GLMesh(std::vector<Vertex>&& vertices, std::vector<uint32_t>&& indices, std::vector<Texture>&& textures, Material&& mat)
	: Mesh(std::move(vertices), std::move(indices), std::move(textures), std::move(mat))
{
	initBuffer();
}

GLMesh::GLMesh(std::vector<Vertex>&& vertices, std::vector<uint32_t>&& indices) : Mesh(std::move(vertices), std::move(indices))
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

	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);
	if (indices.size() > 0)
	{
		glGenBuffers(1, &buffers.EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers.EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
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
	// vertex bitangent
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

}	 // namespace Mina::GL