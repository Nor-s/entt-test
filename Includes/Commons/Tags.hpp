#ifndef MINA_COMMONS_TAGS_HPP
#define MINA_COMMONS_TAGS_HPP

#include <entt/entt.hpp>

namespace Mina::Tag
{
using namespace entt::literals;

// Object Tags
using StaticModel = entt::tag<"StaticModel"_hs>;
using DynamicModel = entt::tag<"DynamicModel"_hs>;
using Bone = entt::tag<"Bone"_hs>;

// Editor Tags
using Tooltip = entt::tag<"tooltip"_hs>;
using UIContext = entt::tag<"uicontext"_hs>;
using HUD = entt::tag<"hud"_hs>;

// Event Tags
using Inputs = entt::tag<"inputs"_hs>;

}	 // namespace Mina::Tag

#endif	  // MINA_COMMONS_TAGS_HPP