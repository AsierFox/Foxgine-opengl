#include "Logger.h"

std::shared_ptr<spdlog::logger> Foxgine::Logger::s_CoreLogger;
std::shared_ptr<spdlog::logger> Foxgine::Logger::s_ClientLogger;

void Foxgine::Logger::Init()
{
	spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");

	s_CoreLogger = spdlog::stdout_color_mt("LOGGER_CORE");
	s_ClientLogger = spdlog::stdout_color_mt("LOGGER_CLIENT");

	s_CoreLogger->set_level(spdlog::level::trace);
	s_ClientLogger->set_level(spdlog::level::trace);
}
