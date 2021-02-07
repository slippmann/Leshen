#pragma once

class Point2D
{
public:
	double X;
	double Y;

	Point2D();
	Point2D(double x, double y);

	double Distance(Point2D point);
};