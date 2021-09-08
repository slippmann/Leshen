#include "ServiceManager.h"
#include "IInputService.h"

#include "Scene.h"

void Scene::SetId(unsigned int idNum)
{
	id = idNum;
}

void Scene::LateUpdate(double deltaTime)
{
}

void Scene::Draw(Window& window)
{
	for (auto& object : objects)
	{
		window.Draw(*object.second);
	}
}

void Scene::ProcessInput(Window& window)
{
	IInputService* input = dynamic_cast<IInputService*>(ServiceManager::GetService("Input"));

	input->UpdateKeys();
	input->UpdateMouse(window);
}

void Scene::Update(double deltaTime)
{
	for (auto& object : objects)
	{
		object.second->Update(deltaTime);
	}
}
