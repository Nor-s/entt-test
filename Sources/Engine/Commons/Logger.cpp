#include "Engine/Commons/Logger.h"

namespace Mina
{

std::shared_ptr<spdlog::logger> Logger::logger{nullptr};

Logger::Logger()
{
	std::vector<spdlog::sink_ptr> logSinks;
	logSinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
	logSinks.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("Mina.log", true));

	logSinks[0]->set_pattern("%^[%n][%H:%M:%S.%e --%L] %v%$ {%s::%! #%#}");
	logSinks[1]->set_pattern("[%n][%L][%H:%M:%S.%e] %v");

	logger = std::make_shared<spdlog::logger>("MINA", begin(logSinks), end(logSinks));
	spdlog::register_logger(logger);
	logger->set_level(spdlog::level::trace);
	logger->flush_on(spdlog::level::trace);
}
const std::shared_ptr<spdlog::logger>& Logger::getLogger() const
{
	return logger;
}

}	 // namespace Mina
