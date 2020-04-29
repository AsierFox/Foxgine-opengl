#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include "Core.h"

namespace Foxgine
{
	class FOXGINE_API Logger
	{
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	public:

		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return Logger::s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return Logger::s_ClientLogger; }
	};
}

// CORE MACROS
#define FOXGINE_CORE_TRACE(...) ::Foxgine::Logger::GetCoreLogger()->trance(__VA_ARGS__)
#define FOXGINE_CORE_INFO(...)  ::Foxgine::Logger::GetCoreLogger()->info(__VA_ARGS__)
#define FOXGINE_CORE_WARN(...)  ::Foxgine::Logger::GetCoreLogger()->warn(__VA_ARGS__)
#define FOXGINE_CORE_ERROR(...) ::Foxgine::Logger::GetCoreLogger()->error(__VA_ARGS__)

// CLIENT MACROS
#define FOXGINE_TRACE(...) ::Foxgine::Logger::GetClientLogger()->trance(__VA_ARGS__)
#define FOXGINE_INFO(...)  ::Foxgine::Logger::GetClientLogger()->info(__VA_ARGS__)
#define FOXGINE_WARN(...)  ::Foxgine::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define FOXGINE_ERROR(...) ::Foxgine::Logger::GetClientLogger()->error(__VA_ARGS__)

// Can redefine to replace the MACRO with nothing to ignore the functions at compilation, and don't generates its binaries
//#define FOXGINE_CORE_INFO
