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
	void Info(const char* formatString, ...) override;
	void Debug(const char* formatString, ...) override;
	void Warn(const char* formatString, ...) override;
	void Error(const char* formatString, ...) override;

private:
	const int INT_max_size  = 1024 * 1024 * 5; // 5MB
	const int INT_max_files = 3;

	std::vector<std::shared_ptr<spdlog::logger>> loggers;
};