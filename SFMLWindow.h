#pragma once

#include <SFML/Graphics.hpp>

#include "Window.h"

////////////////////
/// \brief SFML Window class.
///
////////////////////
class SFMLWindow : public Window
{
private:
	sf::RenderWindow window;

public:
	////////////////////
	/// \brief Construct a new SFML Window.
	///
	/// \param pxWidth	Width of the window in pixels.
	/// \param pxHeight	Height of the window in pixels.
	/// \param name	Name of the window. Displayed at the top of the window.
	///
	////////////////////
	SFMLWindow(unsigned int pxWidth, unsigned int pxHeight, const char* name);

	sf::RenderWindow& GetRenderWindow();

	virtual Rectangle2D GetRectangle() const override;

	virtual void Close() override;
	virtual void Clear() override;
	virtual void Draw(GameObject& gameObject) override;
	virtual void Display() override;
	virtual bool IsClosing() override;
};