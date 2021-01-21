#pragma once

#include <SFML/Graphics.hpp>

#include "Window.h"

class SFMLWindow : public Window
{
public:
	SFMLWindow(unsigned int pxWidth, unsigned int pxHeight, const char* name);

	virtual void Close() override;
	virtual void Clear() override;
	virtual void Draw() override;
	virtual void Display() override;
	virtual bool IsClosing() override;

private:
	sf::RenderWindow window;
};