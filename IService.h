#pragma once

////////////////////
/// \brief Service interface.
/// All services that can be registered with the ServiceManager
/// need to inherit from this class.
/// 
////////////////////
class IService
{
public:
	virtual const char* GetName() const = 0;
	virtual ~IService() = 0 {}
};