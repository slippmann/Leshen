#include <stdexcept>

#include "Window.h"

#ifdef USE_SFML
#include "SFMLWindow.h"
#endif

std::unique_ptr<Window> Window::Create(unsigned int pxWidth, unsigned int pxHeight, const char* name)
{
#ifdef USE_SFML
	return std::unique_ptr<Window>(new SFMLWindow(pxWidth, pxHeight, name));
#else
	throw std::logic_error("No window library provided");
#endif
}
