#ifndef MINA_COMPONENTS_BONE_HPP
#define MINA_COMPONENTS_BONE_HPP

#include "../pch.hpp"

#include "Transform.hpp"

namespace Mina
{
struct Bone
{
	Transform transform;
	std::string name;
};
}	 // namespace Mina

#endif	  // MINA_COMPONENTS_BONE_HPP