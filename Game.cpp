#include <fmt/fmt.h>

#include "Game.h"
// TODO: temporary test code. Remove asap
#include "SFMLGameObject.h"

#include "ServiceManager.h"
#include "ILogService.h"
#include "IInputService.h"

// TODO: temporary test code. Remove asap
static SFMLGameObject player;

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
	player.Load("resources/textures/player.png");

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
			Point2D mousePos = input->GetMousePosition(mainWindow.get());
			// TODO: temporary test code. Remove asap
			Point2D newPosition = player.GetPosition();

			if (input->IsPressed(IInputService::MouseButton::Left))
			{
				if (mainWindow->GetRectangle().Contains(mousePos))
				{
					logger->Debug(fmt::format("User clicked ({}, {})...", mousePos.X, mousePos.Y));
				}
			}

			// TODO: temporary test code. Remove asap
			if (input->IsDown(IInputService::Key::W))
			{
				newPosition.Y -= 2;
			}
			if (input->IsDown(IInputService::Key::S))
			{
				newPosition.Y += 2;
			}
			if (input->IsDown(IInputService::Key::D))
			{
				newPosition.X += 2;
			}
			if (input->IsDown(IInputService::Key::A))
			{
				newPosition.X -= 2;
			}

			if (mainWindow->GetRectangle().Contains(newPosition))
			{
				player.SetPosition(newPosition);
			}

			if (input->IsPressed(IInputService::Key::Escape))
			{
				logger->Debug("User pressed escape...");
			}

			// Draw
			mainWindow->Draw(player);
			mainWindow->Display();

			break;
		}

		default:
		{
			currentState = GameState::Exiting;
		}
	}
}