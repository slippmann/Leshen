#include "Game.h"

Game::Game()
{
	currentState = GameState::Uninitialized;
}

Game& Game::GetInstance()
{
	static Game instance;
	return instance;
}

void Game::Start()
{
	mainWindow.create(sf::VideoMode(INT_MainWindowWidth, INT_MainWindowHeight), STR_MainWindowName);

	currentState = GameState::Playing;

	while (currentState != GameState::Exiting)
	{
		loop();
	}

	mainWindow.close();
}

void Game::loop()
{
	sf::Event currentEvent;
	mainWindow.pollEvent(currentEvent);

	if (currentEvent.type == sf::Event::Closed)
	{
		currentState = GameState::Exiting;
		return;
	}

	mainWindow.clear(sf::Color(0, 0, 0));

	switch (currentState)
	{
		case GameState::Playing:
		{
			// Draw
			mainWindow.display();

			if (currentEvent.type == sf::Event::KeyPressed)
			{
				if (currentEvent.key.code == sf::Keyboard::Escape)
				{
					currentState = GameState::PauseMenu;
				}
			}
			break;
		}

		default:
		{
			currentState = GameState::Exiting;
		}
	}
}