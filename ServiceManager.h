#pragma once

#include <map>
#include <memory>
#include <string>

#include "IService.h"

////////////////////
/// \brief Global service manager. Takes ownership of all
/// services that are registered to it.
/// 
////////////////////
class ServiceManager
{
private:
	/// A dictionary containing all registered services
	static std::map<std::string, std::unique_ptr<IService>> services;

public:
	////////////////////
	/// \brief Register a service with the ServiceManager.
	/// The ServiceManager will take ownership of the service.
	/// 
	/// \param serviceName	Name of the service (used to search for the service)
	/// \param service		A unique pointer to the service object
	/// 
	////////////////////
	static void RegisterService(std::string serviceName, std::unique_ptr<IService>& service);

	////////////////////
	/// \brief Get a pointer to a service.
	/// The ServiceManager will return the service with the given name.
	/// 
	/// \param serviceName	The name of the service to return
	/// 
	/// \returns A pointer to the service with the given name. If no such
	/// service exists, throws exception.
	/// 
	////////////////////
	static IService* GetService(std::string serviceName);
};