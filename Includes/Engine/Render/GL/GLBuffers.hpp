#ifndef MINA_RENDER_GL_GLBUFFERS_HPP
#define MINA_RENDER_GL_GLBUFFERS_HPP

namespace Mina::GL
{

struct GLVertexBuffers
{
	unsigned int VAO{};
	unsigned int VBO{};
	unsigned int EBO{};
};

}	 // namespace Mina::GL

#endif