#include <math.h>

#include "Rectangle2D.h"

Rectangle2D::Rectangle2D() : Width(0.0), Height(0.0)
{
    Origin = Point2D(0.0, 0.0);
}

Rectangle2D::Rectangle2D(Point2D o, double w, double h) : Origin(o), Width(w), Height(h)
{
}

Rectangle2D::Rectangle2D(Point2D corner1, Point2D corner2)
{
    Origin = Point2D(
        fmin(corner1.X, corner2.X),
        fmin(corner1.Y, corner2.Y)
    );
    Height = fabs(corner1.Y - corner2.Y);
    Width = fabs(corner1.X - corner2.X);
}

bool Rectangle2D::Contains(Point2D point)
{
    return (point.X <= Origin.X + Width  &&
            point.X >= Origin.X          &&
            point.Y <= Origin.Y + Height &&
            point.Y >= Origin.Y);
}

Point2D Rectangle2D::GetCenter()
{
    return Point2D(
        Origin.X + (Width / 2.0),
        Origin.Y + (Height / 2.0)
    );
}

void Rectangle2D::SetCenter(Point2D point)
{
    Origin.X = point.X - (Width / 2.0);
    Origin.Y = point.Y - (Height / 2.0);
}
