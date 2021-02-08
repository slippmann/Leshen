#include <fmt/fmt.h>

#include "Game.h"

#include "ServiceManager.h"
#include "ILogService.h"
#include "IInputService.h"

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
	input->UpdateKeys();
	input->UpdateMouseButtons();

	switch (currentState)
	{
		case GameState::Playing:
		{
			// Draw
			mainWindow->Display();

			if (input->IsPressed(IInputService::MouseButton::Left))
			{
				Point2D clickPos = input->GetMousePosition(mainWindow.get());
				if (mainWindow->GetRectangle().Contains(clickPos))
				{
					logger->Debug(fmt::format("User clicked ({}, {})...", clickPos.X, clickPos.Y));
				}
			}

			if (input->IsPressed(IInputService::Key::Escape))
			{
				logger->Debug("User pressed escape...");
			}
			break;
		}

		default:
		{
			currentState = GameState::Exiting;
		}
	}
}