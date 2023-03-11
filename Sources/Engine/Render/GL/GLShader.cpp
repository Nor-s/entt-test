#include "Render/GL/GLShader.h"
#include "Commons/Logger.h"

namespace Mina::GL
{

GLShader::GLShader(const char* vertexPath, const char* fragmentPath, const char* geometryPath)
{
	GL_CALL(handle = glCreateProgram());

	bool vertValid{false}, fragValid{false}, geometryValid{false};
	GLuint vert{}, frag{}, geometry{};
	{
		vert = compile(vertexPath, vertValid, GL_VERTEX_SHADER);
		frag = compile(fragmentPath, fragValid, GL_FRAGMENT_SHADER);
		geometry = compile(geometryPath, geometryValid, GL_GEOMETRY_SHADER);
	}

	GL_CALL(glLinkProgram(handle));
	checkLink(handle);

	deleteShader(vert, vertValid);
	deleteShader(frag, fragValid);
	deleteShader(geometry, geometryValid);
}

GLShader::~GLShader()
{
	GL_CALL(glDeleteProgram(handle));
}

void GLShader::bind()
{
	GL_CALL(glUseProgram(handle));
}

void GLShader::unbind()
{
	glUseProgram(0);
}

const ShaderHandle& GLShader::getHandle() const
{
	return handle;
}

GLuint GLShader::compile(const char* path, bool& isValid, GLenum type)
{
	if (path == nullptr)
	{
		isValid = false;
		return 0;
	}

	MINA_LOG("Compiling shader: {}", path);

	std::string code;
	std::ifstream file;

	file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		std::stringstream shader_stream;

		file.open(path);
		shader_stream << file.rdbuf();
		file.close();

		code = shader_stream.str();
	}
	catch (std::ifstream::failure& e)
	{
		MINA_CRITICAL("Failed to read shader file: {}", path);
	}

	const char* shader_code = code.c_str();

	GLuint shader = glCreateShader(type);
	GL_CALL(glShaderSource(shader, 1, &shader_code, NULL));
	GL_CALL(glCompileShader(shader));

	isValid = checkCompile(shader);
	if (isValid)
	{
		GL_CALL(glAttachShader(handle, shader));
	}

	return shader;
}

void GLShader::deleteShader(GLuint shader, bool isValid)
{
	if (isValid)
	{
		GL_CALL(glDeleteShader(shader));
	}
}

bool GLShader::checkLink(GLuint shader)
{
	GLint success;
	GLchar info_log[1024];

	GL_CALL(glGetProgramiv(shader, GL_LINK_STATUS, &success));
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
	int ret = -1;
	GL_CALL(ret = glGetUniformLocation(shader.getHandle(), name));
	return ret;
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
	glUniform3fv(GetLocation(shader, name), 1, &value[0]);
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