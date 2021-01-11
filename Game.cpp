#include "Game.h"

Game::Game()
{
	currentState = GameState::Uninitialized;
}

////////////////////
/// \brief Get the global Game instance.
/// If the instance is not already initialized, this call will initialize it.
/// 
/// \return Reference to the Game instance.
/// 
////////////////////
Game& Game::GetInstance()
{
	static Game instance;
	return instance;
}

////////////////////
/// \brief Start the game.
/// This will start the main game loop and handle game states.
/// 
////////////////////
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

////////////////////
/// \brief The main game loop.
/// The loop responsible for updating the game. The functionality
/// changes depending on Game::currentState.
/// 
////////////////////
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