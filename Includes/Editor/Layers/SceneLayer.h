//
// Created by No on 2023-03-05.
//

#ifndef MINA_SCENELAYERS_H
#define MINA_SCENELAYERS_H

#include "Engine/pch.hpp"

#include <imgui/imgui.h>

#include "Editor/Layer.hpp"

namespace Mina
{

class SceneLayer : public Layer
{
public:
	SceneLayer() = default;
	~SceneLayer() override = default;

	void processMouseEvent(ImGuiWindowFlags& winodwFlags);
	void update(class Scene& scene) override;
};

}	 // namespace Mina

#endif	  // MINA_SCENELAYERS_H
