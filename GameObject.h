#pragma once

#include "Rectangle2D.h"

////////////////////
/// \brief Base game object class.
/// A class to manage sprites, positions, bounding boxes etc.
/// 
////////////////////
class GameObject
{
protected:
	Rectangle2D rect;

public:
	////////////////////
	/// \brief Load the object's texture from a file.
	///
	/// \param fileName	The path to the texture file.
	///
	////////////////////
	virtual void Load(const char* fileName);

	////////////////////
	/// \brief Update the game object.
	///
	/// \param deltaTime	Number of milliseconds since last update.
	///
	////////////////////
	virtual void Update(double deltaTime);

	////////////////////
	/// \brief Get the bounding rectangle of the game object.
	///
	/// \return A reference to the bounding rectangle.
	///
	////////////////////
	virtual const Rectangle2D& GetRect() const;

	////////////////////
	/// \brief Update the game object's bounding rectangle.
	///
	/// \param newRect		New bounding rectangle.
	///
	////////////////////
	virtual void SetRect(Rectangle2D newRect);

	////////////////////
	/// \brief Get the current position of the game object.
	///
	/// \return A reference to the game object's position.
	///
	////////////////////
	virtual const Point2D& GetPosition() const;

	////////////////////
	/// \brief Get the current position of the game object.
	///
	/// \param position		The new position of the game object.
	///
	////////////////////
	virtual void SetPosition(Point2D position);
};