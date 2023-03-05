#ifndef MINA_RENDER_DRAWCOMMAND_HPP
#define MINA_RENDER_DRAWCOMMAND_HPP

namespace Mina
{

using DrawFunction = void (*)(class Shader& shader, const class Mesh& mesh);

class DrawCommand
{
public:
	DrawCommand() = default;
	virtual ~DrawCommand() = default;
	virtual void drawBasicMesh(class Shader& shader, const class Mesh& mesh) = 0;
	virtual DrawFunction getDrawBasicFunction() = 0;
};

using DrawBasicFunction = void (DrawCommand::*)(class Shader& shader, const class Mesh& mesh);


}	 // namespace Mina

#endif