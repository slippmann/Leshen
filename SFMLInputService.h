#pragma once

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

#include "IInputService.h"
#include "Window.h"

////////////////////
/// \brief SFML user input service.
///
////////////////////
class SFMLInputService : public IInputService
{
private:
	const int UINT_NumKeys = static_cast<int>(Key::Unknown);
	const int UINT_NumMouseButtons = static_cast<int>(MouseButton::Unknown);

	std::bitset<10> keys;
	std::bitset<10> prevKeys;
	std::bitset<2> mouseButtons;
	std::bitset<2> prevMouseButtons;

	////////////////////
	/// \brief Convert Key object to sf::Keyboard::Key.
	///
	/// \param keyCode	Key object to convert.
	/// 
	/// \return sf::Keyboard::Key that corresponds to the keyCode.
	///
	////////////////////
	sf::Keyboard::Key keyToSfmlKey(Key keyCode);

	////////////////////
	/// \brief Convert mouse button object to sf::Mouse::Button.
	///
	/// \param buttonCode	MouseButton object to convert.
	/// 
	/// \return sf::Mouse::Button that corresponds to the buttonCode.
	///
	////////////////////
	sf::Mouse::Button buttonToSfmlButton(MouseButton buttonCode);

public:
	virtual std::bitset<10> GetKeys() override;
	virtual std::bitset<2> GetMouseButtons() override;
	virtual Point2D GetMousePosition(Window* window) override;

	virtual void UpdateKeys() override;
	virtual bool IsDown(Key key) override;
	virtual bool IsPressed(Key key) override;
	virtual bool IsReleased(Key key) override;

	virtual void UpdateMouseButtons() override;
	virtual bool IsDown(MouseButton button) override;
	virtual bool IsPressed(MouseButton button) override;
	virtual bool IsReleased(MouseButton button) override;
};