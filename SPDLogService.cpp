#include <stdarg.h>

#include "SPDLogService.h"

#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/rotating_file_sink.h"

SPDLogService::SPDLogService()
{
	name = __func__;

	spdlog::set_pattern("[%Y-%m-%d %T %z] [%^%=7l%$] [thread %t] %v");

	loggers.push_back(
		spdlog::stdout_color_mt("console_logger")
	);
}

SPDLogService::SPDLogService(const char* logFilePath) : SPDLogService()
{
	loggers.push_back(
		spdlog::rotating_logger_mt("file_logger", logFilePath, INT_max_size, INT_max_files)
	);
}

void SPDLogService::SetLevel(LogLevel level)
{
	if (level == LogLevel::DEBUG)
		spdlog::set_level(spdlog::level::debug);
	else if (level == LogLevel::INFO)
		spdlog::set_level(spdlog::level::info);
	else if (level == LogLevel::WARN)
		spdlog::set_level(spdlog::level::warn);
	else if (level == LogLevel::ERR)
		spdlog::set_level(spdlog::level::err);
}

void SPDLogService::Info(const char* formatString, ...)
{
	va_list args;
	va_start(args, formatString);

	for (auto& logger : loggers)
	{
		if (logger.get() != nullptr)
		{
			logger->info(formatString, args);
		}
	}

	va_end(args);
}

void SPDLogService::Debug(const char* formatString, ...)
{
	va_list args;
	va_start(args, formatString);

	for (auto& logger : loggers)
	{
		if (logger.get() != nullptr)
		{
			logger->debug(formatString, args);
		}
	}

	//std::vprintf(formatString, args);

	va_end(args);
}

void SPDLogService::Warn(const char* formatString, ...)
{
	va_list args;
	va_start(args, formatString);

	for (auto& logger : loggers)
	{
		if (logger.get() != nullptr)
		{
			logger->warn(formatString, args);
		}
	}

	va_end(args);
}

void SPDLogService::Error(const char* formatString, ...)
{
	va_list args;
	va_start(args, formatString);

	for (auto& logger : loggers)
	{
		if (logger.get() != nullptr)
		{
			logger->error(formatString, args);
		}
	}

	va_end(args);
}
