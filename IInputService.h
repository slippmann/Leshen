#pragma once

#include <bitset>

#include "IService.h"
#include "Point2D.h"
#include "Window.h"

////////////////////
/// \brief User input service interface.
/// Provides keyboard and mouse button states.
///
////////////////////
class IInputService : public IService
{
public:
	enum class Key
	{
		W = 0,
		A,
		S,
		D,
		Right,
		Left,
		Up,
		Down,
		E,
		Escape,
		Unknown
	};

	enum class MouseButton
	{
		Left = 0,
		Right,
		Unknown
	};

	////////////////////
	/// \brief Get the current set of pressed keys.
	///
	/// \returns std::bitset containing key states.
	/// Index the bitset using the Key enum.
	/// 
	////////////////////
	virtual std::bitset<10> GetKeys() = 0;

	////////////////////
	/// \brief Get the current set of pressed keys.
	///
	/// \returns std::bitset containing mouse button states.
	/// Index the bitset using the MouseButton enum.
	/// 
	////////////////////
	virtual std::bitset<2> GetMouseButtons() = 0;

	////////////////////
	/// \brief Get the current position of the mouse in a window.
	/// The coordinates returned are in window coordinate space.
	///
	/// \returns Point2D with the x and y position of the cursor.
	/// 
	////////////////////
	virtual Point2D GetMousePosition(Window* window) = 0;

	////////////////////
	/// \brief Update the current set of pressed keys.
	/// The keyboard button states will be queried and stored
	/// for later access via GetKeys().
	/// 
	////////////////////
	virtual void UpdateKeys() = 0;

	////////////////////
	/// \brief Check if a given key is currently down.
	///
	/// \param key	Key to query.
	/// 
	/// \return true if the button is down.
	/// 
	////////////////////
	virtual bool IsDown(Key key) = 0;

	////////////////////
	/// \brief Check if a given key has been pressed since the last update.
	/// If the key was already pressed, this function returns false.
	/// 
	/// \param key	Key to query.
	/// 
	/// \return true if the key was pressed.
	/// 
	////////////////////
	virtual bool IsPressed(Key key) = 0;

	////////////////////
	/// \brief Check if a given key has been released since the last update.
	/// If the key was not previously down, this function returns false.
	/// 
	/// \param key	Key to query.
	/// 
	/// \return true if the key was released.
	/// 
	////////////////////
	virtual bool IsReleased(Key key) = 0;


	////////////////////
	/// \brief Update the current set of pressed mouse buttons.
	/// The mouse button states will be queried and stored
	/// for later access via GetMouseButtons().
	/// 
	////////////////////
	virtual void UpdateMouseButtons() = 0;

	////////////////////
	/// \brief Check if a given mouse button is currently down.
	///
	/// \param button	MouseButton to query.
	/// 
	/// \return true if the button is down.
	/// 
	////////////////////
	virtual bool IsDown(MouseButton button) = 0;

	////////////////////
	/// \brief Check if a given mouse button has been pressed since the last update.
	/// If the button was already pressed, this function returns false.
	/// 
	/// \param button	MouseButton to query.
	/// 
	/// \return true if the key was pressed.
	/// 
	////////////////////
	virtual bool IsPressed(MouseButton button) = 0;

	////////////////////
	/// \brief Check if a given mouse button has been released since the last update.
	/// If the button was not previously down, this function returns false.
	/// 
	/// \param button	MouseButton to query.
	/// 
	/// \return true if the key was released.
	/// 
	////////////////////
	virtual bool IsReleased(MouseButton button) = 0;
};