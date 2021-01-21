#include <stdexcept>

#include "Window.h"

#ifdef SFML_GRAPHICS
#include "SFMLWindow.h"
#endif

std::unique_ptr<Window> Window::Create(unsigned int pxWidth, unsigned int pxHeight, const char* name)
{
#ifdef SFML_GRAPHICS
	return std::unique_ptr<Window>(new SFMLWindow(pxWidth, pxHeight, name));
#else
	throw std::logic_error("No window library provided");
#endif
}
