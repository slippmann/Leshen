#pragma once

#include "IService.h"

////////////////////
/// \brief Logging service interface.
///
////////////////////
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

	////////////////////
	/// \brief Set the log level.
	/// 
	/// \param LogLevel		The lowest level to log.
	/// 
	////////////////////
	virtual void SetLevel(LogLevel level) = 0;

	////////////////////
	/// \brief Log a message at info level.
	/// Formatting same as printf.
	/// 
	/// \param formatString	string to log.
	/// \param ...		additional args dependent on formatString.
	/// 
	////////////////////
	virtual void Info(const char* formatString, ...) = 0;

	////////////////////
	/// \brief Log a message at debug level.
	/// Formatting same as printf.
	/// 
	/// \param formatString	string to log.
	/// \param ...		additional args dependent on formatString.
	/// 
	////////////////////
	virtual void Debug(const char* formatString, ...) = 0;

	////////////////////
	/// \brief Log a message at warning level.
	/// Formatting same as printf.
	/// 
	/// \param formatString	string to log.
	/// \param ...		additional args dependent on formatString.
	/// 
	////////////////////
	virtual void Warn(const char* formatString, ...) = 0;
	
	////////////////////
	/// \brief Log a message at error level.
	/// Formatting same as printf.
	/// 
	/// \param formatString	string to log.
	/// \param ...		additional args dependent on formatString.
	/// 
	////////////////////
	virtual void Error(const char* formatString, ...) = 0;
};