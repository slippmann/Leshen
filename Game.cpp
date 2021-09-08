#include <fmt/fmt.h>

#include "Game.h"
// TODO: temporary test code. Remove asap
#include "MainMenuScene.h"

#include "ServiceManager.h"
#include "ILogService.h"
#include "IInputService.h"

// TODO: temporary test code. Remove asap
static MainMenuScene menu;

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
	ILogService* logger = dynamic_cast<ILogService*>(ServiceManager::GetService("Logger"));

	// TODO: temporary test code. Remove asap
	menu.OnCreate();

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
	IInputService* input = dynamic_cast<IInputService*>(ServiceManager::GetService("Input"));

	Point2D mousePos;

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
			menu.ProcessInput(*mainWindow);
			menu.Update(0);

			if (input->IsPressed(IInputService::Key::Escape))
			{
				logger->Debug("User pressed escape...");
			}

			menu.Draw(*mainWindow);
			mainWindow->Display();

			break;
		}

		default:
		{
			currentState = GameState::Exiting;
		}
	}
}