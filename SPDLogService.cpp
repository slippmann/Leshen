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

void SPDLogService::Info(const char* message)
{
	log(LogLevel::INFO, message);
}

void SPDLogService::Debug(const char* message)
{
	log(LogLevel::DEBUG, message);
}

void SPDLogService::Warn(const char* message)
{
	log(LogLevel::WARN, message);
}

void SPDLogService::Error(const char* message)
{
	log(LogLevel::ERR, message);
}

void SPDLogService::log(LogLevel level, const char* message)
{
	for (auto& logger : loggers)
	{
		if (logger.get() != nullptr)
		{
			switch (level)
			{
				case LogLevel::INFO:
				{
					logger->info(message);
					break;
				}

				case LogLevel::DEBUG:
				{
					logger->debug(message);
					break;
				}

				case LogLevel::WARN:
				{
					logger->warn(message);
					break;
				}

				case LogLevel::ERR:
				{
					logger->error(message);
					break;
				}
			}
		}
	}
}
