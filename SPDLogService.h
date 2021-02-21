#pragma once

#include <spdlog/spdlog.h>

#include "ILogService.h"

////////////////////
/// \brief SPDLog logging service.
///
////////////////////
class SPDLogService : public ILogService
{
private:
	const char* name;

	const int INT_max_size  = 1024 * 1024 * 5; // 5MB
	const int INT_max_files = 3;

	void log(LogLevel level, const char* message);

	std::vector<std::shared_ptr<spdlog::logger>> loggers;

public:
	SPDLogService();

	////////////////////
	/// \brief Initialize the service with a log file.
	/// 
	/// \param logFilePath	path to the log file.
	/// 
	////////////////////
	SPDLogService(const char* logFilePath);

	virtual const char* GetName() const override;

	virtual void SetLevel(LogLevel level) override;
	virtual void Info(const char* message) override;
	virtual void Debug(const char* message) override;
	virtual void Warn(const char* message) override;
	virtual void Error(const char * message) override;

	virtual ~SPDLogService() override;
};