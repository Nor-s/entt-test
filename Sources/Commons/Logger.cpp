#include "Commons/Logger.h"

#ifndef NDEBUG
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#define SPDLOG_DEBUG_ON
#define SPDLOG_TRACE_ON
namespace Mina
{
std::unique_ptr<Logger> Logger::instance(new Logger());
std::shared_ptr<spdlog::logger> Logger::logger{};

Logger::Logger()
{
	std::vector<spdlog::sink_ptr> logSinks;
	logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
	logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("Mina.log", true));

	logSinks[0]->set_pattern("%^[%n][%H:%M:%S.%e --%L]%$ (%s::%! #%#) %v");
	logSinks[1]->set_pattern("[%n][%L][%H:%M:%S.%e] %v");

	logger = std::make_shared<spdlog::logger>("MINA", begin(logSinks), end(logSinks));
	spdlog::register_logger(logger);
	logger->set_level(spdlog::level::trace);
	logger->flush_on(spdlog::level::trace);
}
Logger::~Logger() = default;

std::shared_ptr<spdlog::logger>& Logger::get()
{
	return logger;
}

}	 // namespace Mina
#endif
