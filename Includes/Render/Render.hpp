#ifndef MINA_RENDER_RENDER_HPP
#define MINA_RENDER_RENDER_HPP

namespace Mina
{
class Render
{
	virtual void basicDraw(class Shader& shader, class Mesh& mesh) = 0;
	virtual void instancedDraw(class Shader& shader, class Mesh& mesh) = 0;
	virtual void stencilDraw(class Shader& shader, class Mesh& mesh) = 0;
};

}	 // namespace Mina

#endif