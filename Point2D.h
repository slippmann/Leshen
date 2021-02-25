#pragma once

////////////////////
/// \brief 2D point in cartesian coordinates.
///
////////////////////
class Point2D
{
public:
	double X;
	double Y;

	////////////////////
	/// \brief Default constructor.
	/// Initializes x and y to 0.0.
	///
	////////////////////
	Point2D();

	////////////////////
	/// \brief Construct a Point2D from x and y coordinates.
	///
	/// \param x	The x coordinate.
	/// \param y	The y coordinate.
	///
	////////////////////
	Point2D(double x, double y);


	////////////////////
	/// \brief Total distance from one point to another.
	///
	/// \param point	Point to measure distance from.
	///
	////////////////////
	double Distance(Point2D point);
};