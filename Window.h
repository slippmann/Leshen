#pragma once

#include <memory>

#include "Rectangle2D.h"

////////////////////
/// \brief Generic window object.
///
////////////////////
class Window
{
public:
	////////////////////
	/// \brief Create a new unique window object.
	///
	/// \param pxWidth	Width of the window in pixels.
	/// \param pxHeight	Height of the window in pixels.
	/// \param name	Name of the window. Displayed at the top of the window.
	/// 
	/// \return std::unique_ptr to the window object.
	/// 
	////////////////////
	static std::unique_ptr<Window> Create(unsigned int pxWidth, unsigned int pxHeight, const char* name);


	////////////////////
	/// \brief Get the rectangle that defines the size of the window.
	///
	/// \return The window rectangle.
	/// 
	////////////////////
	virtual Rectangle2D GetRectangle() = 0;


	////////////////////
	/// \brief Close the window.
	/// 
	////////////////////
	virtual void Close() = 0;

	////////////////////
	/// \brief Clear screen by drawing a fully black screen.
	/// Need to call Display() to update window on-screen.
	/// 
	////////////////////
	virtual void Clear() = 0;

	////////////////////
	/// \brief Draw object onto the window.
	/// Need to call Display() to update window on-screen.
	///
	/// \returns std::bitset containing key states.
	/// Index the bitset using the Key enum.
	/// 
	////////////////////
	virtual void Draw() = 0;

	////////////////////
	/// \brief Display the window on screen.
	/// 
	////////////////////
	virtual void Display() = 0;

	////////////////////
	/// \brief Check if the window is currently closing.
	///
	/// \returns true if the window is closing.
	/// 
	////////////////////
	virtual bool IsClosing() = 0;
};