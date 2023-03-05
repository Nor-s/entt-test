#ifndef MINA_RENDER_GL_GLDRAWCOMMAND_H
#define MINA_RENDER_GL_GLDRAWCOMMAND_H

#include "../DrawCommand.hpp"

namespace Mina::GL
{

class GLDrawCommand : public DrawCommand
{
	void drawBasicMesh(class Shader& shader, const class Mesh& mesh) override;
	DrawFunction getDrawBasicFunction() override;
};

}	 // namespace Mina::GL

#endif