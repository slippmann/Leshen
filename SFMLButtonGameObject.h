#pragma once

#include "SFMLGameObject.h"

class SFMLButtonGameObject : public SFMLGameObject
{
private:
	bool isClicked;

	sf::Texture hoverTexture;
	sf::Texture clickTexture;

	void onHover();
	void onClick();

public:
	SFMLButtonGameObject();

	virtual void Update(double deltaTime) override;

	void LoadHoverTexture(const char* texturePath);
	void LoadClickTexture(const char* texturePath);
	bool IsClicked() const;
};
