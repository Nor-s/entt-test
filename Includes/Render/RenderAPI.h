#ifndef MINA_RENDER_RENDERAPI_H
#define MINA_RENDER_RENDERAPI_H

#include "../pch.hpp"
#include "Commons/Singleton.hpp"

namespace Mina
{

class RenderAPI : public Singleton<RenderAPI>
{
	friend class Singleton<RenderAPI>;

private:
	std::unique_ptr<class MeshFactory> meshFactory{};
	std::unique_ptr<class FramebufferFactory> framebufferFactory{};
	//	std::unique_ptr<class Render> render{};

	RenderAPI();

public:
	RenderAPI(const RenderAPI&) = delete;
	RenderAPI(RenderAPI&&) = delete;

	RenderAPI& operator=(const RenderAPI&) = delete;
	RenderAPI& operator=(RenderAPI&&) = delete;

	~RenderAPI();

	class MeshFactory& getMeshFactory() const;
	class FramebufferFactory& getFramebufferFactory() const;
};

}	 // namespace Mina

#endif
