
#include <stdexcept>

#include "SFMLInputService.h"
#include "SFMLWindow.h"

sf::Keyboard::Key SFMLInputService::keyToSfmlKey(Key keyCode) const
{
	switch (keyCode)
	{
		case Key::W:		return sf::Keyboard::Key::W;
		case Key::A:		return sf::Keyboard::Key::A;
		case Key::S:		return sf::Keyboard::Key::S;
		case Key::D:		return sf::Keyboard::Key::D;
		case Key::E:		return sf::Keyboard::Key::E;
		case Key::Right:	return sf::Keyboard::Key::Right;
		case Key::Left:		return sf::Keyboard::Key::Left;
		case Key::Up:		return sf::Keyboard::Key::Up;
		case Key::Down:		return sf::Keyboard::Key::Down;
		case Key::Escape:	return sf::Keyboard::Key::Escape;
		default:
			throw std::logic_error("Unsupported key");
	}
}

sf::Mouse::Button SFMLInputService::buttonToSfmlButton(MouseButton buttonCode) const
{
	switch (buttonCode)
	{
		case MouseButton::Left:		return sf::Mouse::Button::Left;
		case MouseButton::Right:	return sf::Mouse::Button::Right;
		default:
			throw std::logic_error("Unsupported mouse button");
	}
}

SFMLInputService::SFMLInputService() : name(__func__)
{
}

const char* SFMLInputService::GetName() const
{
	return name;
}

void SFMLInputService::UpdateKeys()
{
	Key currentKey;

	// Save current key bits
	prevKeys = keys;
	keys.reset();

	for (int keyIndex = 0; keyIndex < UINT_NumKeys; keyIndex++)
	{
		currentKey = static_cast<Key>(keyIndex);
		if (sf::Keyboard::isKeyPressed(keyToSfmlKey(currentKey)))
			keys.set(keyIndex);
	}
}

void SFMLInputService::UpdateMouse(Window& window)
{
	MouseButton currentButton;

	sf::RenderWindow& renderWindow = dynamic_cast<SFMLWindow&>(window).GetRenderWindow();
	auto position = sf::Mouse::getPosition(renderWindow);

	mousePosition = Point2D(position.x, position.y);

	// Save current mouse button bits
	prevMouseButtons = mouseButtons;
	mouseButtons.reset();

	for (int buttonIndex = 0; buttonIndex < UINT_NumMouseButtons; buttonIndex++)
	{
		currentButton = static_cast<MouseButton>(buttonIndex);
		if (sf::Mouse::isButtonPressed(buttonToSfmlButton(currentButton)))
			mouseButtons.set(buttonIndex);
	}
}

std::bitset<IInputService::UINT_NumKeys> SFMLInputService::GetKeys() const
{
	return keys;
}

std::bitset<IInputService::UINT_NumMouseButtons> SFMLInputService::GetMouseButtons() const
{
	return mouseButtons;
}

Point2D SFMLInputService::GetMousePosition() const
{
	return mousePosition;
}

bool SFMLInputService::IsDown(Key key) const
{
	return keys[static_cast<size_t>(key)] == 1;
}

bool SFMLInputService::IsPressed(Key key) const
{	
	int keyIndex = static_cast<size_t>(key);
	return (prevKeys[keyIndex] == 0 && keys[keyIndex] == 1);
}

bool SFMLInputService::IsReleased(Key key) const
{
	int keyIndex = static_cast<size_t>(key);
	return (prevKeys[keyIndex] == 1 && keys[keyIndex] == 0);
}

bool SFMLInputService::IsDown(MouseButton button) const
{
	return mouseButtons[static_cast<size_t>(button)] == 1;
}

bool SFMLInputService::IsPressed(MouseButton button) const
{
	int buttonIndex = static_cast<size_t>(button);
	return (prevMouseButtons[buttonIndex] == 0 && mouseButtons[buttonIndex] == 1);
}

bool SFMLInputService::IsReleased(MouseButton button) const
{
	int buttonIndex = static_cast<size_t>(button);
	return (prevMouseButtons[buttonIndex] == 1 && mouseButtons[buttonIndex] == 0);
}

SFMLInputService::~SFMLInputService()
{
}
