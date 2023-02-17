#ifndef MINA_COMPONENTS_KEYFRAME_H
#define MINA_COMPONENTS_KEYFRAME_H

#include "transform.h"

namespace Mina::Component
{
struct PositionKeyframe
{
	glm::vec3 position;
	double time;
};

struct RotationKeyframe
{
	glm::quat rotation;
	double time;
};

struct ScaleKeyframe
{
	glm::vec3 scale;
	double time;
};

}	 // namespace Mina::Component
#endif