#pragma once

////////////////////
/// \brief Service interface.
/// All services that can be registered with the ServiceManager
/// need to inherit from this class.
////////////////////
class IService
{
protected:
	/// Name of the service
	const char* name;
};