#ifndef MINA_RENDER_GL_GLSHADER_H
#define MINA_RENDER_GL_GLSHADER_H

#include "Render/Shader.h"

namespace Mina::GL
{
class GLShader : public Shader
{
private:
	ShaderHandle handle;

public:
	GLShader() = delete;

	GLShader(const GLShader&) = delete;
	GLShader(GLShader&&) = delete;

	GLShader& operator=(const GLShader&) = delete;
	GLShader& operator=(GLShader&&) = delete;

	GLShader(const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr);
	~GLShader();

	void bind() override;
	void unbind() override;
	[[nodiscard]] const ShaderHandle& getHandle() const override;


private:
	GLuint compile(const char* path, bool& isValid, GLenum type);
	void deleteShader(GLuint shader, bool isValid);
	bool checkLink(GLuint shader);
	bool checkCompile(GLuint shader);
};

void GlUniformInt(Shader& shader, const char* const name, int value);
void GlUniformUint(Shader& shader, const char* const name, unsigned int value);
void GlUniformBool(Shader& shader, const char* const name, bool value);
void GlUniformFloat(Shader& shader, const char* const name, float value);
void GlUniformVec2(Shader& shader, const char* const name, const glm::vec2& value);
void GlUniformVec2(Shader& shader, const char* const name, float x, float y);
void GlUniformVec3(Shader& shader, const char* const name, const glm::vec3& value);
void GlUniformVec3(Shader& shader, const char* const name, float x, float y, float z);
void GlUniformVec3(Shader& shader, const char* const name, float xyz);
void GlUniformVec4(Shader& shader, const char* const name, const glm::vec4& value);
void GlUniformVec4(Shader& shader, const char* const name, float x, float y, float z, float w);
void GlUniformMat2(Shader& shader, const char* const name, const glm::mat2& mat);
void GlUniformMat3(Shader& shader, const char* const name, const glm::mat3& mat);
void GlUniformMat4(Shader& shader, const char* const name, const glm::mat4& mat);

}	 // namespace Mina::GL

#endif