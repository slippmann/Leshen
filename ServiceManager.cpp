#include <stdexcept>

#include "ServiceManager.h"

void ServiceManager::RegisterService(std::string serviceName, std::unique_ptr<IService>& service)
{
    services.insert(std::make_pair(serviceName, std::move(service)));
}

IService* ServiceManager::GetService(std::string serviceName)
{
	auto itr = services.find(serviceName);

	if (itr == services.end())
	{
		throw std::runtime_error("Service " + serviceName + " not found.");
	}

	return itr->second.get();
}
