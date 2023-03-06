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

	RenderAPI();

public:
	RenderAPI(const RenderAPI&) = delete;
	RenderAPI(RenderAPI&&) = delete;

	RenderAPI& operator=(const RenderAPI&) = delete;
	RenderAPI& operator=(RenderAPI&&) = delete;

	~RenderAPI();

	[[nodiscard]] class MeshFactory& getMeshFactory() const;
	[[nodiscard]] class FramebufferFactory& getFramebufferFactory() const;
	[[nodiscard]] std::unique_ptr<class Shader> createShader(std::string_view vertPath, std::string_view fragPath);
};

}	 // namespace Mina

#endif
