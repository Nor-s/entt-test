#ifndef MINA_COMPONENTS_RENDER_MESHCOMPONENT_HPP
#define MINA_COMPONENTS_RENDER_MESHCOMPONENT_HPP

#include "../pch.hpp"

namespace Mina
{

class RenderAPI
{
private:
	// static std::unique_ptr<RenderAPI> instance = nullptr;

	std::unique_ptr<class MeshFactory> meshFactory{};
	std::unique_ptr<class FramebufferFactory> framebufferFactory{};
	std::unique_ptr<class Render> render{};

	RenderAPI();

public:
	RenderAPI(const RenderAPI&) = delete;
	RenderAPI(RenderAPI&&) = delete;
	RenderAPI& operator=(const RenderAPI&) = delete;
	RenderAPI& operator=(RenderAPI&&) = delete;

	~RenderAPI();

	static RenderAPI& getInstance();
};

}	 // namespace Mina

#endif