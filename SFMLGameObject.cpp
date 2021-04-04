#include "SFMLGameObject.h"

SFMLGameObject::SFMLGameObject()
{
}

void SFMLGameObject::Load(const char* fileName)
{
	sf::FloatRect sfRect;

	if (!texture.loadFromFile(fileName))
	{
		throw std::runtime_error("File not found");
	}

	sprite.setTexture(texture);
	sfRect = sprite.getGlobalBounds();

	rect.Width = sfRect.width;
	rect.Height = sfRect.height;
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

void SFMLGameObject::SetTexture(sf::Texture& newTexture, bool resize)
{
	if (sprite.getTexture() != &newTexture)
	{
		sprite.setTexture(newTexture, resize);
	}
}
