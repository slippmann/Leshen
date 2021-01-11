#pragma once

#include <SFML/Graphics.hpp>

////////////////////
/// \brief The main Game class.
/// Responsible for starting and managing the game.
/// 
////////////////////
class Game
{
private:
	static inline const char* STR_MainWindowName = "Leshen";
	static const int INT_MainWindowWidth = 1280;
	static const int INT_MainWindowHeight = 720;

	enum class GameState
	{
		Uninitialized,
		Playing,
		PauseMenu,
		Menu,
		Exiting
	};

	sf::RenderWindow mainWindow;
	GameState currentState;

	Game();
	void loop();

public:
	// Prevent compiler from creating copy constructors
	Game(Game const&) = delete;
	void operator=(Game const&) = delete;

	static Game& GetInstance();
	void Start();
};