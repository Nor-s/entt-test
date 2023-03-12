#ifndef MINA_COMMONS_LOGGER_H
#define MINA_COMMONS_LOGGER_H

#include "../pch.hpp"
#include "../Core/Singleton.hpp"

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#define SPDLOG_DEBUG_ON
#define SPDLOG_TRACE_ON

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace Mina
{
class Logger : public Singleton<Logger>
{
	friend class Singleton<Logger>;
	static std::shared_ptr<spdlog::logger> logger;

private:
	Logger();

public:
	~Logger() = default;
	[[nodiscard]] const std::shared_ptr<spdlog::logger>& getLogger() const;
};

}	 // namespace Mina

#define MINA_INFO(...) SPDLOG_LOGGER_INFO(::Mina::Logger::get().getLogger(), __VA_ARGS__)
#define MINA_ERROR(...) SPDLOG_LOGGER_ERROR(::Mina::Logger::get().getLogger(), __VA_ARGS__)
#define MINA_WARN(...) SPDLOG_LOGGER_WARN(::Mina::Logger::get().getLogger(), __VA_ARGS__)
#define MINA_LOG(...) SPDLOG_LOGGER_TRACE(::Mina::Logger::get().getLogger(), __VA_ARGS__)
#define MINA_CRITICAL(...) SPDLOG_LOGGER_CRITICAL(::Mina::Logger::get().getLogger(), __VA_ARGS__)

// https://github.com/ocornut/imgui/blob/bfce7750b168b5a857b4379596236dda7b58bd39/backends/imgui_impl_opengl3.cpp#L187
#ifndef NDEBUG
#define GL_CALL(_CALL)                                                      \
	do                                                                      \
	{                                                                       \
		_CALL;                                                              \
		GLenum gl_err = glGetError();                                       \
		if (gl_err != 0)                                                    \
			MINA_CRITICAL("GL error {} returned from {}.", gl_err, #_CALL); \
	} while (0)	   // Call with error check
#else
#define GL_CALL(_CALL) _CALL	// Call without error check
#endif

#endif	  // MINA_COMMONS_LOGGER_H