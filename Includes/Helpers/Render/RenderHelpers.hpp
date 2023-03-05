#ifndef MINA_HELPERS_RENDER_RENDERHELPERS_HPP
#define MINA_HELPERS_RENDER_RENDERHELPERS_HPP

#include "../../Render/Mesh.h"
#include "../../Render/RenderAPI.h"
#include "../../Render/MeshFactory.hpp"

namespace Mina
{

std::unique_ptr<Mesh> createBiPyramid()
{
	float position[] = {
		0.0f,  1.0f,  0.0f,		// 0 (상단 꼭지점)
		1.0f,  0.0f,  0.0f,		// 1 (x축 양의 방향)
		0.0f,  0.0f,  1.0f,		// 2 (z축 양의 방향)
		-1.0f, 0.0f,  0.0f,		// 3 (x축 음의 방향)
		0.0f,  0.0f,  -1.0f,	// 4 (z축 음의 방향)
		0.0f,  -1.0f, 0.0f		// 5 (하단 꼭지점)
	};
	float normals[] = {
		0.0f,  1.0f,  0.0f,		// 0 (상단 꼭지점)
		1.0f,  1.0f,  1.0f,		// 1 (x축 양의 방향)
		1.0f,  1.0f,  1.0f,		// 2 (z축 양의 방향)
		-1.0f, 1.0f,  -1.0f,	// 3 (x축 음의 방향)
		-1.0f, 1.0f,  -1.0f,	// 4 (z축 음의 방향)
		0.0f,  -1.0f, 0.0f		// 5 (하단 꼭지점)
	};
	std::vector<uint32_t> indices{0, 1, 2, 0, 2, 3, 0, 3, 4, 0, 4, 1, 5, 2, 1, 5, 3, 2, 5, 4, 3, 5, 1, 4};

	std::vector<Vertex> vertices;
	for (int i = 0; i < 18; i+=3)
	{
		Vertex vert{};
		vert.position = {position[i], position[i + 1], position[i + 2]};
		vert.normal = {normals[i], normals[i + 1], normals[i + 2]};
		vertices.push_back(vert);
	}

	return RenderAPI::get().getMeshFactory().create(std::move(vertices), std::move(indices));
}

}	 // namespace Mina

#endif