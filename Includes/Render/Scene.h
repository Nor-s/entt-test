#ifndef MINA_RENDER_SCENE_H
#define MINA_RENDER_SCENE_H

#include "pch.hpp"
#include "Commons/Type.hpp"

namespace Mina
{

class Scene
{
private:
	entt::registry& registry;
	std::unique_ptr<class Framebuffer> framebuffer;
	std::unique_ptr<class Camera> camera;

public:
	Scene(entt::registry& registry, std::unique_ptr<class Framebuffer> framebuffer);
	~Scene();

	void resizeScreen(const MSize& size);

	void begin();
	void end();

	[[nodiscard]] entt::registry& getRegistry() const;
	[[nodiscard]] const class Framebuffer& getFramebuffer() const;
	[[nodiscard]] const class Camera& getCamera() const;
};

}	 // namespace Mina

#endif
