#pragma once

#include <memory>
#include <string>
#include <map>

#include "Scene.h"
#include "Window.h"

////////////////////
/// \brief The main menu scene class.
/// 
////////////////////
class MainMenuScene : public Scene
{
public:
	MainMenuScene();

	virtual void OnCreate() override;
	virtual void OnDestroy() override;
	virtual void OnActivate() override;
	virtual void OnDeactivate() override;

	virtual void Update(double deltaTime) override;
};
