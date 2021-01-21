#include "Game.h"

#include "ServiceManager.h"
#include "SPDLogService.h"

Game::Game()
{
	mainWindow = Window::Create(INT_MainWindowWidth, INT_MainWindowHeight, STR_MainWindowName);
	currentState = GameState::Uninitialized;
}

Game& Game::GetInstance()
{
	static Game instance;
	return instance;
}

void Game::Start()
{
	ILogService* logger = (ILogService*)ServiceManager::GetService("Logger");

	logger->Info("Starting Game");

	currentState = GameState::Playing;

	while (currentState != GameState::Exiting)
	{
		loop();
	}

	logger->Info("Exiting game");

	mainWindow->Close();
}

void Game::loop()
{
	ILogService* logger = dynamic_cast<ILogService*>(ServiceManager::GetService("Logger"));

	if (mainWindow->IsClosing())
	{
		currentState = GameState::Exiting;
		return;
	}

	mainWindow->Clear();

	switch (currentState)
	{
		case GameState::Playing:
		{
			// Draw
			mainWindow->Display();

			/*if (currentEvent.type == sf::Event::KeyPressed)
			{
				if (currentEvent.key.code == sf::Keyboard::Escape)
				{
					logger->Debug("User pressed escape...");
				}
			}*/
			break;
		}

		default:
		{
			currentState = GameState::Exiting;
		}
	}
}