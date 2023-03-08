#ifndef MINA_EDITOR_EDITOR_H
#define MINA_EDITOR_EDITOR_H

#include "Engine/pch.hpp"

namespace Mina
{
class Editor
{
	using Layers = std::vector<std::unique_ptr<class Layer>>;

private:
	const class Window& window;
	Layers layers;

public:
	Editor() = delete;
	Editor(const Editor&) = delete;
	Editor(Editor&&) = delete;
	Editor& operator=(const Editor&) = delete;
	Editor& operator=(Editor&&) = delete;

	explicit Editor(class Window& window);
	~Editor();

	void init();
	void preRender();
	void postRender();
	void shutdown();

	void addLayer(std::unique_ptr<class Layer> layer);
	void updateLayers(class Scene& scene);

private:
	void drawDock();
	void drawMenuBar();
};
}	 // namespace Mina

#endif