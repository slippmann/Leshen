#pragma once

#include "Point2D.h"

class Rectangle2D
{
public:
	Point2D Origin;
	double Height;
	double Width;

	Rectangle2D();
	Rectangle2D(Point2D origin, double width, double height);
	Rectangle2D(Point2D corner1, Point2D corner2);

	bool Contains(Point2D point);
};