#ifndef MINA_COMMONS_TAGS_HPP
#define MINA_COMMONS_TAGS_HPP

#include <entt/entt.hpp>

namespace Mina::Tag
{
using namespace entt::literals;

// Object Tags
using StaticMesh = entt::tag<"StaticMesh"_hs>;
using DynamicMesh = entt::tag<"DynamicMesh"_hs>;
using Bone = entt::tag<"Bone"_hs>;
using Player = entt::tag<"Player"_hs>;

// Editor Tags
using UIContext = entt::tag<"uicontext"_hs>;

// Event Tags
using Inputs = entt::tag<"inputs"_hs>;

}	 // namespace Mina::Tag

#endif	  // MINA_COMMONS_TAGS_HPP