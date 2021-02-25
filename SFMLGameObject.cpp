#include "SFMLGameObject.h"

SFMLGameObject::SFMLGameObject()
{
}

void SFMLGameObject::Load(const char* fileName)
{
	if (!texture.loadFromFile(fileName))
	{
		throw std::runtime_error("File not found");
	}

	sprite.setTexture(texture);
}

void SFMLGameObject::SetPosition(Point2D position)
{
	rect.Origin = position;
	sprite.setPosition(position.X, position.Y);
}

const sf::Sprite& SFMLGameObject::GetSprite() const
{
	return sprite;
}
