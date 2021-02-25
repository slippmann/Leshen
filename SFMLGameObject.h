#pragma once

#include <SFML/Graphics.hpp>

#include "GameObject.h"

////////////////////
/// \brief SFML game object class.
/// Derived from GameObject.
/// 
////////////////////
class SFMLGameObject : public GameObject
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

public:
	SFMLGameObject();

	virtual void Load(const char* fileName) override;
	virtual void SetPosition(Point2D position) override;

	////////////////////
	/// \brief Get the SFML sprite member variable.
	///
	/// \return A reference to the SFML sprite.
	///
	////////////////////
	const sf::Sprite& GetSprite() const;
};