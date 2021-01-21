#pragma once

#include <memory>

class Window
{
public:
	static std::unique_ptr<Window> Create(unsigned int pxWidth, unsigned int pxHeight, const char* name);

	virtual void Close() = 0;
	virtual void Clear() = 0;
	virtual void Draw() = 0;
	virtual void Display() = 0;
	virtual bool IsClosing() = 0;
};