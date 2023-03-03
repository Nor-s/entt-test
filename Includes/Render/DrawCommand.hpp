#ifndef MINA_RENDER_DRAWCOMMAND_HPP
#define MINA_RENDER_DRAWCOMMAND_HPP

namespace Mina
{

using DrawBasicFunction = void (DrawCommand::*)(class Shader& shader, const class Mesh& mesh);

class DrawCommand
{
	virtual void drawBasicMesh(class Shader& shader, const class Mesh& mesh) = 0;
};

}	 // namespace Mina

#endif