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
	const char* name;

	std::bitset<UINT_NumKeys> keys;
	std::bitset<UINT_NumKeys> prevKeys;
	std::bitset<UINT_NumMouseButtons> mouseButtons;
	std::bitset<UINT_NumMouseButtons> prevMouseButtons;

	Point2D mousePosition;

	////////////////////
	/// \brief Convert Key object to sf::Keyboard::Key.
	///
	/// \param keyCode	Key object to convert.
	/// 
	/// \return sf::Keyboard::Key that corresponds to the keyCode.
	///
	////////////////////
	sf::Keyboard::Key keyToSfmlKey(Key keyCode) const;

	////////////////////
	/// \brief Convert mouse button object to sf::Mouse::Button.
	///
	/// \param buttonCode	MouseButton object to convert.
	/// 
	/// \return sf::Mouse::Button that corresponds to the buttonCode.
	///
	////////////////////
	sf::Mouse::Button buttonToSfmlButton(MouseButton buttonCode) const;

public:
	SFMLInputService();

	virtual const char* GetName() const override;

	virtual std::bitset<UINT_NumKeys> GetKeys() const override;
	virtual std::bitset<UINT_NumMouseButtons> GetMouseButtons() const override;
	virtual Point2D GetMousePosition() const override;

	virtual void UpdateKeys() override;
	virtual bool IsDown(Key key) const override;
	virtual bool IsPressed(Key key) const override;
	virtual bool IsReleased(Key key) const override;

	virtual void UpdateMouse(Window& window) override;
	virtual bool IsDown(MouseButton button) const override;
	virtual bool IsPressed(MouseButton button) const override;
	virtual bool IsReleased(MouseButton button) const override;

	virtual ~SFMLInputService() override;
};