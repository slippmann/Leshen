#include <math.h>

#include "Point2D.h"

Point2D::Point2D() : X(0.0), Y(0.0)
{
}

Point2D::Point2D(double x, double y) : X(x), Y(y)
{
}

double Point2D::Distance(Point2D point)
{
    return sqrt(pow(X - point.X, 2) + pow(Y - point.Y, 2));
}
