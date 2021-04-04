#include "SFMLButtonGameObject.h"

#include "ServiceManager.h"
#include "IInputService.h"

void SFMLButtonGameObject::onHover()
{
	SetTexture(hoverTexture);
}

void SFMLButtonGameObject::onClick()
{
	SetTexture(clickTexture);
}

SFMLButtonGameObject::SFMLButtonGameObject()
{
	isClicked = false;
}

void SFMLButtonGameObject::Update(double deltaTime)
{
	IInputService* input = dynamic_cast<IInputService*>(ServiceManager::GetService("Input"));
	(void)deltaTime;

	isClicked = false;

	if (rect.Contains(input->GetMousePosition()))
	{
		if (input->IsDown(IInputService::MouseButton::Left))
		{
			onClick();
		}
		else
		{
			onHover();
		}
	}
	else
	{
		SetTexture(texture);
	}
}

void SFMLButtonGameObject::LoadHoverTexture(const char* texturePath)
{
	if (!hoverTexture.loadFromFile(texturePath))
	{
		throw std::runtime_error("File not found");
	}
}

void SFMLButtonGameObject::LoadClickTexture(const char* texturePath)
{
	if (!clickTexture.loadFromFile(texturePath))
	{
		throw std::runtime_error("File not found");
	}
}

bool SFMLButtonGameObject::IsClicked()
{
	IInputService* input = dynamic_cast<IInputService*>(ServiceManager::GetService("Input"));
	
	if (rect.Contains(input->GetMousePosition()))
	{
		return input->IsReleased(IInputService::MouseButton::Left);
	}
}
