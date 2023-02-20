#ifndef MINA_COMPONENTS_BONE_HPP
#define MINA_COMPONENTS_BONE_HPP

#include "../pch.hpp"

#include "Transform.hpp"

namespace Mina::Component
{
struct Bone
{
	Transform transform;
	std::string name;
};
}	 // namespace Mina::Component

#endif	  // MINA_COMPONENTS_BONE_HPP