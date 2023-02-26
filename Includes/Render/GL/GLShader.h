#ifndef MINA_RENDER_GL_GLSHADER_H
#define MINA_RENDER_GL_GLSHADER_H

#include "../Shader.hpp"

namespace Mina::GL
{
class GLShader : public Shader
{
public:
	GLShader() = delete;

	GLShader(const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr);
	~GLShader();

	void bind() override;
	void unbind() override;

private:
	bool checkLink(GLuint shader);
	bool checkCompile(GLuint shader);
};

inline void GlUniformInt(Shader& shader, const char* const name, int value);
inline void GlUniformUint(Shader& shader, const char* const name, unsigned int value);
inline void GlUniformBool(Shader& shader, const char* const name, bool value);
inline void GlUniformFloat(Shader& shader, const char* const name, float value);
inline void GlUniformVec2(Shader& shader, const char* const name, const glm::vec2& value);
inline void GlUniformVec2(Shader& shader, const char* const name, float x, float y);
inline void GlUniformVec3(Shader& shader, const char* const name, const glm::vec3& value);
inline void GlUniformVec3(Shader& shader, const char* const name, float x, float y, float z);
inline void GlUniformVec3(Shader& shader, const char* const name, float xyz);
inline void GlUniformVec4(Shader& shader, const char* const name, const glm::vec4& value);
inline void GlUniformVec4(Shader& shader, const char* const name, float x, float y, float z, float w);
inline void GlUniformMat2(Shader& shader, const char* const name, const glm::mat2& mat);
inline void GlUniformMat3(Shader& shader, const char* const name, const glm::mat3& mat);
inline void GlUniformMat4(Shader& shader, const char* const name, const glm::mat4& mat);

}	 // namespace Mina::GL

#endif