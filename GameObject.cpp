#include "GameObject.h"

void GameObject::Load(const char* fileName)
{
}

void GameObject::Update(double deltaTime)
{
}

void GameObject::SetRect(Rectangle2D newRect)
{
	rect = newRect;
}

const Rectangle2D& GameObject::GetRect() const
{
	return rect;
}

const Point2D& GameObject::GetPosition() const
{
	return rect.Origin;
}

void GameObject::SetPosition(Point2D position)
{
	rect.Origin = position;
}
