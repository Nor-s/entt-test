#ifndef MINA_COMPONENTS_BONE_H
#define MINA_COMPONENTS_BONE_H

#include "../pch.h"

#include "transform.h"

namespace Mina::Component
{
struct Bone
{
	Transform transform;
	std::string name;
};
}	 // namespace Mina::Component

#endif