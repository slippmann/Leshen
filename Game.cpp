#include <fmt/fmt.h>

#include "Game.h"
// TODO: temporary test code. Remove asap
#include "SFMLButtonGameObject.h"

#include "ServiceManager.h"
#include "ILogService.h"
#include "IInputService.h"

// TODO: temporary test code. Remove asap
static SFMLButtonGameObject button;

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
	button.Load("resources/textures/button.png");
	button.LoadHoverTexture("resources/textures/button_hover.png");
	button.LoadClickTexture("resources/textures/button_click.png");
	button.SetPosition(Point2D(500, 250));

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
	input->UpdateMouse(*mainWindow.get());

	switch (currentState)
	{
		case GameState::Playing:
		{
			Point2D mousePos = input->GetMousePosition();

			button.Update(0);

			// TODO: temporary test code. Remove asap
			if (button.IsClicked())
			{
				logger->Debug(fmt::format("User clicked the button!"));
			}

			if (input->IsPressed(IInputService::Key::Escape))
			{
				logger->Debug("User pressed escape...");
			}

			// Draw
			mainWindow->Draw(button);
			mainWindow->Display();

			break;
		}

		default:
		{
			currentState = GameState::Exiting;
		}
	}
}