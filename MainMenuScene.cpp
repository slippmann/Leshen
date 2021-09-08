#pragma once

#include "ServiceManager.h"
#include "IInputService.h"
#include "ILogService.h"
#include "SFMLButtonGameObject.h"

#include "MainMenuScene.h"

MainMenuScene::MainMenuScene()
{
	id = 0;
}

void MainMenuScene::OnCreate()
{
	auto start = std::make_shared<SFMLButtonGameObject>(SFMLButtonGameObject());
	auto stop = std::make_shared<SFMLButtonGameObject>(SFMLButtonGameObject());

	// Load button images
	start->Load("resources/textures/button.png");
	start->LoadHoverTexture("resources/textures/button_hover.png");
	start->LoadClickTexture("resources/textures/button_click.png");

	stop->Load("resources/textures/button.png");
	stop->LoadHoverTexture("resources/textures/button_hover.png");
	stop->LoadClickTexture("resources/textures/button_click.png");

	// Set button positions
	start->SetPosition(Point2D(500, 250));
	stop->SetPosition(Point2D(550, 250));

	objects.insert(std::pair<std::string, std::shared_ptr<GameObject>>("start", start));
	objects.insert(std::pair<std::string, std::shared_ptr<GameObject>>("stop", stop));
}

void MainMenuScene::OnDestroy()
{
}

void MainMenuScene::OnActivate()
{
}

void MainMenuScene::OnDeactivate()
{
}

void MainMenuScene::Update(double deltaTime)
{
	IInputService* input = dynamic_cast<IInputService*>(ServiceManager::GetService("Input"));
	ILogService* logger = dynamic_cast<ILogService*>(ServiceManager::GetService("Logger"));

	Point2D mousePos = input->GetMousePosition();

	// Check if start button is pressed
	if (input->IsReleased(IInputService::MouseButton::Left) &&
		objects["start"]->GetRect().Contains(mousePos))
	{
		logger->Debug("User Pressed Start Button!!");
	}

	// Check if stop button is pressed
	if (input->IsReleased(IInputService::MouseButton::Left) &&
		objects["stop"]->GetRect().Contains(mousePos))
	{
		logger->Debug("User Pressed Stop Button!!");
	}

	Scene::Update(deltaTime);
}
