#pragma once

#include <spdlog/spdlog.h>

#include "ILogService.h"

////////////////////
/// \brief SPDLog logging service.
///
////////////////////
class SPDLogService : public ILogService
{
public:
	SPDLogService();

	////////////////////
	/// \brief Initialize the service with a log file.
	/// 
	/// \param logFilePath	path to the log file.
	/// 
	////////////////////
	SPDLogService(const char* logFilePath);

	void SetLevel(LogLevel level) override;
	void Info(const char* message) override;
	void Debug(const char* message) override;
	void Warn(const char* message) override;
	void Error(const char * message) override;

private:
	const int INT_max_size  = 1024 * 1024 * 5; // 5MB
	const int INT_max_files = 3;

	void log(LogLevel level, const char* message);

	std::vector<std::shared_ptr<spdlog::logger>> loggers;
};