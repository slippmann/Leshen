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

	////////////////////
	/// \brief The main game loop.
	/// The loop responsible for updating the game. The functionality
	/// changes depending on Game::currentState.
	/// 
	////////////////////
	void loop();

public:
	// Prevent compiler from creating copy constructors
	Game(Game const&) = delete;
	void operator=(Game const&) = delete;

	////////////////////
	/// \brief Get the global Game instance.
	/// If the instance is not already initialized, this call will initialize it.
	/// 
	/// \return Reference to the Game instance.
	/// 
	////////////////////
	static Game& GetInstance();

	////////////////////
	/// \brief Start the game.
	/// This will start the main game loop and handle game states.
	/// 
	////////////////////
	void Start();
};