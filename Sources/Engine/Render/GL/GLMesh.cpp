#include "Engine/pch.hpp"
#include "Engine/Render/GL/GLShader.h"
#include "Engine/Render/GL/GLMesh.h"

#include "Engine/Commons/Logger.h"

namespace Mina::GL
{

GLMesh::GLMesh(std::vector<Vertex>&& vertices,
			   std::vector<uint32_t>&& indices,
			   std::vector<std::unique_ptr<Texture>>&& textures,
			   Material& mat)
	: Mesh(std::move(vertices), std::move(indices), std::move(textures), mat)
{
	MINA_LOG("Creating GLMesh with {} vertices and {} indices", vertices.size(), indices.size());
	initBuffer();
}

GLMesh::GLMesh(std::vector<Vertex>&& vertices, std::vector<uint32_t>&& indices)
	: Mesh(std::move(vertices), std::move(indices))
{
	MINA_LOG("Creating GLMesh with {} vertices and {} indices", vertices.size(), indices.size());
	initBuffer();
}

GLMesh::GLMesh(std::vector<Vertex>&& vertices) : Mesh(std::move(vertices))
{
	MINA_LOG("Creating GLMesh with {} vertices", vertices.size());
	initBuffer();
}

void GLMesh::initBuffer()
{
	GL_CALL(glGenVertexArrays(1, &buffers.VAO));
	GL_CALL(glGenBuffers(1, &buffers.VBO));

	GL_CALL(glBindVertexArray(buffers.VAO));
	GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, buffers.VBO));

	GL_CALL(glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(vertices.size() * sizeof(Vertex)), &vertices[0],
						 GL_STATIC_DRAW));
	if (!indices.empty())
	{
		GL_CALL(glGenBuffers(1, &buffers.EBO));
		GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers.EBO));
		GL_CALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, static_cast<GLsizeiptr>(indices.size() * sizeof(unsigned int)),
							 &indices[0], GL_STATIC_DRAW));
	}

	glEnableVertexAttribArray(0);
	// vertex position
	GL_CALL(glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) 0));
	// vertex normals
	glEnableVertexAttribArray(1);
	GL_CALL(glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, normal)));
	// vertex texture coords
	glEnableVertexAttribArray(2);
	GL_CALL(glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, texCoords)));

	// vertex tangent
	glEnableVertexAttribArray(3);
	GL_CALL(glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, tangent)));
	// vertex biTangent
	glEnableVertexAttribArray(4);
	GL_CALL(glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, bitangent)));
	// ids
	glEnableVertexAttribArray(5);
	GL_CALL(glVertexAttribIPointer(5, 4, GL_INT, sizeof(Vertex), (void*) offsetof(Vertex, boneIds)));
	// weights
	glEnableVertexAttribArray(6);
	GL_CALL(glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*) offsetof(Vertex, weights)));
	glBindVertexArray(0);

	handle = buffers.VAO;
}

GLMesh::~GLMesh()
{
	GL_CALL(glDeleteVertexArrays(1, &buffers.VAO));
	GL_CALL(glDeleteBuffers(1, &buffers.VBO));
	GL_CALL(glDeleteBuffers(1, &buffers.EBO));
}

}	 // namespace Mina::GL