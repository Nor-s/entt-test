#ifndef MINA_COMMONS_LOGGER_H
#define MINA_COMMONS_LOGGER_H

#include "pch.hpp"

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#define SPDLOG_DEBUG_ON
#define SPDLOG_TRACE_ON

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace Mina
{
class Logger
{
private:
	static std::unique_ptr<Logger> instance;
	static std::shared_ptr<spdlog::logger> logger;

	Logger();

public:
	~Logger();

	static std::shared_ptr<spdlog::logger>& get();
};

}	 // namespace Mina

#define MINA_INFO(...) SPDLOG_LOGGER_INFO(::Mina::Logger::get(), __VA_ARGS__)
#define MINA_ERROR(...) SPDLOG_LOGGER_ERROR(::Mina::Logger::get(), __VA_ARGS__)
#define MINA_WARN(...) SPDLOG_LOGGER_WARN(::Mina::Logger::get(), __VA_ARGS__)
#define MINA_LOG(...) SPDLOG_LOGGER_TRACE(::Mina::Logger::get(), __VA_ARGS__)
#define MINA_CRITICAL(...) SPDLOG_LOGGER_CRITICAL(::Mina::Logger::get(), __VA_ARGS__)

#endif	  // MINA_COMMONS_LOGGER_H