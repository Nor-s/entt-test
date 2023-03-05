#ifndef MINA_COMPONENTS_RENDER_MESH_H
#define MINA_COMPONENTS_RENDER_MESH_H

#include "pch.hpp"
#include "../Commons/Constants.hpp"
#include "../Commons/Type.hpp"
#include "Texture.h"

namespace Mina
{
class Shader;

struct Vertex
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec3 tangent;
	glm::vec3 bitangent;
	glm::vec2 texCoords;

	int boneIds[MAX_BONE_INFLUENCE];
	float weights[MAX_BONE_INFLUENCE];
};

struct Material
{
	glm::vec3 ambient{0.8f, 0.8f, 0.8f};
	glm::vec3 diffuse{1.0f, 1.0f, 1.0f};
	glm::vec3 specular{0.9f, 0.9f, 0.9f};

	float shininess{1.0f};
	bool hasDiffuseTexture{false};
	// const std::function<void(class Shader& shader)> updateToGPU{nullptr};
};

class Mesh
{
protected:
	MeshHandle handle;
	std::vector<Vertex> vertices{};
	std::vector<uint32_t> indices{};
	std::vector<std::unique_ptr<Texture>> textures{};
	Material material{};

protected:
	Mesh(std::vector<Vertex>&& _vertices,
		 std::vector<uint32_t>&& _indices,
		 std::vector<std::unique_ptr<Texture>>&& _textures,
		 Material& _mat);
	Mesh(std::vector<Vertex>&& _vertices, std::vector<uint32_t>&& _indices);
	explicit Mesh(std::vector<Vertex>&& _vertices);

public:
	virtual ~Mesh() = default;

	operator const MeshHandle&() const
	{
		return handle;
	}

	[[nodiscard]] const Material& getMaterial() const;
	[[nodiscard]] const std::vector<Vertex>& getVertices() const;
	[[nodiscard]] const std::vector<uint32_t>& getIndices() const;
	[[nodiscard]] const std::vector<std::unique_ptr<Texture>>& getTextures() const;
};

}	 // namespace Mina

#endif