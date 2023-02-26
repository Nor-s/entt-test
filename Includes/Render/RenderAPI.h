#ifndef MINA_RENDER_RENDERAPI_H
#define MINA_RENDER_RENDERAPI_H

#include "../pch.hpp"

namespace Mina
{

class RenderAPI
{
private:
	static std::unique_ptr<RenderAPI> instance;

	std::unique_ptr<class MeshFactory> meshFactory{};
	// std::unique_ptr<class FramebufferFactory> framebufferFactory{};
	// std::unique_ptr<class Render> render{};

	RenderAPI();

public:
	RenderAPI(const RenderAPI&) = delete;
	RenderAPI(RenderAPI&&) = delete;
	RenderAPI& operator=(const RenderAPI&) = delete;
	RenderAPI& operator=(RenderAPI&&) = delete;

	~RenderAPI();

	static RenderAPI& get();

	class MeshFactory& getMeshFactory();
};

}	 // namespace Mina

#endif