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
	/// \param message	string to log.
	/// 
	////////////////////
	virtual void Info(const char * message) = 0;
	virtual void Info(std::string& message)  { Info(message.c_str()); };
	virtual void Info(std::string&& message) { Info(message.c_str()); };

	////////////////////
	/// \brief Log a message at debug level.
	/// Formatting same as printf.
	/// 
	/// \param message	string to log.
	/// 
	////////////////////
	virtual void Debug(const char* message) = 0;
	virtual void Debug(std::string& message)  { Debug(message.c_str()); };
	virtual void Debug(std::string&& message) { Debug(message.c_str()); };

	////////////////////
	/// \brief Log a message at warning level.
	/// Formatting same as printf.
	/// 
	/// \param message	string to log.
	/// 
	////////////////////
	virtual void Warn(const char* message) = 0;
	virtual void Warn(std::string& message)  { Warn(message.c_str()); };
	virtual void Warn(std::string&& message) { Warn(message.c_str()); };
	
	////////////////////
	/// \brief Log a message at error level.
	/// Formatting same as printf.
	/// 
	/// \param message	string to log.
	/// 
	////////////////////
	virtual void Error(const char* message) = 0;
	virtual void Error(std::string& message)  { Error(message.c_str()); };
	virtual void Error(std::string&& message) { Error(message.c_str()); };
};