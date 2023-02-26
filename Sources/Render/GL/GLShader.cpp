#include "Render/GL/GLShader.h"
#include "Commons/Logger.h"

namespace Mina::GL
{

GLShader::GLShader(const char* vertex_path, const char* fragment_path, const char* geometry_path)
{
}

GLShader::~GLShader()
{
}

void GLShader::bind()
{
	glUseProgram(handle);
}

void GLShader::unbind()
{
	glUseProgram(0);
}

bool GLShader::checkLink(GLuint shader)
{
	GLint success;
	GLchar info_log[1024];
	glGetProgramiv(shader, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(shader, 1024, NULL, info_log);
		MINA_ERROR("PROGRAM_LINKING : {}", info_log);
		return false;
	}
	return true;
}

bool GLShader::checkCompile(GLuint shader)
{
	GLint success;
	GLchar info_log[1024];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 1024, NULL, info_log);
		MINA_ERROR("PROGRAM_COMPILE : {}", info_log);
		return false;
	}
	return true;
}

}	 // namespace Mina::GL

namespace Mina::GL
{

inline int GetLocation(Shader& shader, const char* const name)
{
	return glGetUniformLocation(shader.getHandle(), name);
}

void GlUniformInt(Shader& shader, const char* const name, int value)
{
	glUniform1i(GetLocation(shader, name), value);
}
void GlUniformUint(Shader& shader, const char* const name, unsigned int value)
{
	glUniform1ui(GetLocation(shader, name), value);
}
void GlUniformBool(Shader& shader, const char* const name, bool value)
{
	GlUniformInt(shader, name, static_cast<int>(value));
}

void GlUniformFloat(Shader& shader, const char* const name, float value)
{
	glUniform1f(GetLocation(shader, name), value);
}
void GlUniformVec2(Shader& shader, const char* const name, const glm::vec2& value)
{
	glUniform2fv(GetLocation(shader, name), 1, glm::value_ptr(value));
}
void GlUniformVec2(Shader& shader, const char* const name, float x, float y)
{
	glUniform2f(GetLocation(shader, name), x, y);
}
void GlUniformVec3(Shader& shader, const char* const name, const glm::vec3& value)
{
	glUniform3fv(GetLocation(shader, name), 1, glm::value_ptr(value));
}
void GlUniformVec3(Shader& shader, const char* const name, float x, float y, float z)
{
	glUniform3f(GetLocation(shader, name), x, y, z);
}
void GlUniformVec3(Shader& shader, const char* const name, float xyz)
{
	GlUniformVec3(shader, name, xyz, xyz, xyz);
}
void GlUniformVec4(Shader& shader, const char* const name, const glm::vec4& value)
{
	glUniform4fv(GetLocation(shader, name), 1, glm::value_ptr(value));
}
void GlUniformVec4(Shader& shader, const char* const name, float x, float y, float z, float w)
{
	glUniform4f(GetLocation(shader, name), x, y, z, w);
}

void GlUniformMat2(Shader& shader, const char* const name, const glm::mat2& mat)
{
	glUniformMatrix2fv(GetLocation(shader, name), 1, GL_FALSE, &mat[0][0]);
}
void GlUniformMat3(Shader& shader, const char* const name, const glm::mat3& mat)
{
	glUniformMatrix3fv(GetLocation(shader, name), 1, GL_FALSE, &mat[0][0]);
}
void GlUniformMat4(Shader& shader, const char* const name, const glm::mat4& mat)
{
	glUniformMatrix4fv(GetLocation(shader, name), 1, GL_FALSE, &mat[0][0]);
}

}	 // namespace Mina::GL