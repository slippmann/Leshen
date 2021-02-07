#include <stdexcept>

#include "SFMLWindow.h"

SFMLWindow::SFMLWindow(unsigned int pxWidth, unsigned int pxHeight, const char* name)
{
	window.create(sf::VideoMode(pxWidth, pxHeight), name);
	window.setVerticalSyncEnabled(true);
}

sf::RenderWindow* SFMLWindow::GetRenderWindow()
{
	return &window;
}

Rectangle2D SFMLWindow::GetRectangle()
{
	sf::Vector2 size = window.getSize();
	return Rectangle2D(Point2D(0.0, 0.0), Point2D(size.x, size.y));
}

void SFMLWindow::Close()
{
	window.close();
}

void SFMLWindow::Clear()
{
	window.clear();
}

void SFMLWindow::Draw()
{
	throw std::logic_error("Not implemented");
}

void SFMLWindow::Display()
{
	window.display();
}

bool SFMLWindow::IsClosing()
{
	sf::Event currentEvent;

	while (window.pollEvent(currentEvent))
	{
		if (currentEvent.type == sf::Event::Closed)
		{
			return true;
		}
	}

	return false;
}