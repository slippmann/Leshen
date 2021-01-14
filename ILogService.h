#pragma once

#include "IService.h"

class ILogService : public IService
{
public:
	enum class LogLevel
	{
		DEBUG,
		INFO,
		WARN,
		ERR
	};

	virtual void SetLevel(LogLevel level) = 0;
	virtual void Info(const char* formatString, ...) = 0;
	virtual void Debug(const char* formatString, ...) = 0;
	virtual void Warn(const char* formatString, ...) = 0;
	virtual void Error(const char* formatString, ...) = 0;
};