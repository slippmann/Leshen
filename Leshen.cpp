#include <iostream>
#include <memory>

#include "Game.h"

#include "ServiceManager.h"
#include "SPDLogService.h"
#include "SFMLInputService.h"

#if _DEBUG
const ILogService::LogLevel OBJ_LogLevel = ILogService::LogLevel::DEBUG;
#else
const ILogService::LogLevel OBJ_LogLevel = ILogService::LogLevel::WARN;
#endif

void initializeLogger()
{
	auto logService = new SPDLogService("logs/leshen.log");
	auto uniqueLogService = std::unique_ptr<IService>(logService);

	logService->SetLevel(OBJ_LogLevel);
	
	ServiceManager::RegisterService("Logger", uniqueLogService);
}

void initializeInputService()
{
	auto uniqueInputService = std::unique_ptr<IService>(new SFMLInputService());
	ServiceManager::RegisterService("Input", uniqueInputService);
}

void initializeServices()
{
	initializeLogger();
	initializeInputService();
}

int main(int argc, char** argv)
{
	initializeServices();

	Game::GetInstance().Start();

	return 0;
}