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
    double halfHeight = 0.0;
    double halfWidth = 0.0;
    
    Origin = Point2D();
    Height = fabs(corner1.Y - corner2.Y);
    Width = fabs(corner1.X - corner2.X);

    halfHeight = Height / 2;
    halfWidth = Width / 2;

    if (corner1.X > corner2.X)
    {
        halfWidth = -halfWidth;
    }

    if (corner1.Y > corner2.Y)
    {
        halfHeight = -halfHeight;
    }

    Origin.X = corner1.X + halfWidth;
    Origin.Y = corner1.Y + halfHeight;
}

bool Rectangle2D::Contains(Point2D point)
{
    return (point.X <= Origin.X + (Width / 2)  &&
            point.X >= Origin.X - (Width / 2)  &&
            point.Y <= Origin.Y + (Height / 2) &&
            point.Y >= Origin.Y - (Height / 2));
}
