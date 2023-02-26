#ifndef MINA_COMPONENTS_KEYFRAME_HPP
#define MINA_COMPONENTS_KEYFRAME_HPP

#include "Transform.hpp"
#include "../Commons/KeySet.hpp"

namespace Mina
{
struct KeyPosition
{
	time_t time;
	glm::vec3 position;
};

struct KeyRotation
{
	time_t time;
	glm::quat rotation;
};

struct KeyScale
{
	time_t time;
	glm::vec3 scale;
};

struct Keyframes
{
	KeySet<KeyPosition> positions;
	KeySet<KeyRotation> rotations;
	KeySet<KeyScale> scales;
};
}	 // namespace Mina

#endif