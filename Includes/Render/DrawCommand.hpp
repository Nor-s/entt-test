#ifndef MINA_RENDER_DRAWCOMMAND_HPP
#define MINA_RENDER_DRAWCOMMAND_HPP

#include "../pch.hpp"

namespace Mina
{

using DrawFunction = void (*)(class Shader& shader, const class Mesh& mesh, const glm::mat4& worldTransform);

class DrawCommand
{
public:
	DrawCommand() = default;
	virtual ~DrawCommand() = default;
	virtual void drawBasicMesh(class Shader& shader, const class Mesh& mesh, const glm::mat4& worldTransform) = 0;
	virtual DrawFunction getDrawBasicFunction() = 0;
};

using DrawBasicFunction = void (DrawCommand::*)(class Shader& shader, const class Mesh& mesh, const glm::mat4& worldTransform);


}	 // namespace Mina

#endif