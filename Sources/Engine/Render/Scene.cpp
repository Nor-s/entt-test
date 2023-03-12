//
// Created by No on 2023-03-04.
//
#include "Engine/Render/Scene.h"
#include "Engine/Render/Framebuffer.hpp"
#include "Engine/Render/Camera.h"

#include "Engine/Helpers/MathHelper.hpp"
#include "Engine/Commons/Logger.h"

namespace Mina
{

Scene::Scene(entt::registry& registry, std::unique_ptr<Framebuffer> framebuffer)
	: registry(registry), framebuffer(std::move(framebuffer))
{
	MINA_LOG("Initializing scene with framebuffer: size: {}, {}", this->framebuffer->getSize().width,
			 this->framebuffer->getSize().height);

	camera = std::make_unique<Camera>(ViewParams(), ProjectionParams());
	camera->setAspectRatio(Aspect(this->framebuffer->getSize()));
}

Scene::~Scene() = default;

void Scene::resizeScreen(const MSize& size)
{
	framebuffer->resize(size);
	camera->setAspectRatio(Aspect(framebuffer->getSize()));
}

void Scene::begin()
{
	framebuffer->bind();
	framebuffer->clear();
}

void Scene::end()
{
	framebuffer->unbind();
}

entt::registry& Scene::getRegistry() const
{
	return registry;
}

const Framebuffer& Scene::getFramebuffer() const
{
	return *framebuffer;
}

const Camera& Scene::getCamera() const
{
	return *camera;
}

}	 // namespace Mina