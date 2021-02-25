#pragma once

#include "Point2D.h"

////////////////////
/// \brief 2D rectangle in cartesian coordinates.
///
////////////////////
class Rectangle2D
{
public:
	/// Top left corner of rectangle.
	Point2D Origin;
	double Height;
	double Width;

	////////////////////
	/// \brief Default constructor.
	/// Initializes a zero area rectangle with origin at (0,0).
	///
	////////////////////
	Rectangle2D();

	////////////////////
	/// \brief Construct a rectangle from a point and the height and width.
	///
	/// \param origin	Top left corner point of rectangle.
	/// \param width	Width of the rectangle.
	/// \param height	Height of the rectangle.
	///
	////////////////////
	Rectangle2D(Point2D origin, double width, double height);

	////////////////////
	/// \brief Construct a rectangle from two opposite corner points.
	///
	/// \param corner1	First corner point.
	/// \param corner2	Second corner point.
	///
	////////////////////
	Rectangle2D(Point2D corner1, Point2D corner2);


	////////////////////
	/// \brief Check if a point exists within the rectangle.
	///
	/// \param point	Point to check.
	///
	////////////////////
	bool Contains(Point2D point);

	////////////////////
	/// \brief Get the center point of the rectangle.
	///
	/// \return The center point of the rectangle.
	///
	////////////////////
	Point2D GetCenter();

	////////////////////
	/// \brief Set the center point of the rectangle.
	///
	/// \param point	New center point.
	///
	////////////////////
	void SetCenter(Point2D point);
};