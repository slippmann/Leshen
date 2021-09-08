#pragma once

#include <memory>
#include <string>
#include <map>

#include "Window.h"

////////////////////
/// \brief The base scene class.
/// Framework for creating game scenes.
/// 
////////////////////
class Scene
{
protected:
	unsigned int id;
	std::map<std::string, std::shared_ptr<GameObject>> objects;

public:
	////////////////////
	/// \brief Set the ID number for the scene.
	///
	/// \param idNum	ID number.
	///
	////////////////////
	void SetId(unsigned int idNum);


	////////////////////
	/// \brief Actions to perform when the scene is created.
	///
	////////////////////
	virtual void OnCreate() = 0;

	////////////////////
	/// \brief Actions to perform when the scene is destroyed.
	///
	////////////////////
	virtual void OnDestroy() = 0;

	////////////////////
	/// \brief Actions to perform when the scene is activated.
	///
	////////////////////
	virtual void OnActivate() = 0;

	////////////////////
	/// \brief Actions to perform when the scene is deactivated.
	///
	////////////////////
	virtual void OnDeactivate() = 0;

	////////////////////
	/// \brief Process user input.
	/// 
	/// \param window	Reference to the game window. Needed to get relative position of the mouse.
	///
	////////////////////
	virtual void ProcessInput(Window& window);

	////////////////////
	/// \brief Update scene and the objects within.
	///
	/// \param deltaTime	Time that has passed since last update.
	/// 
	////////////////////
	virtual void Update(double deltaTime);

	////////////////////
	/// \brief Update performed after the Update method.
	/// Actions here will likely rely on changes from Update();
	///
	/// \param deltaTime	Time that has passed since last update.
	/// 
	////////////////////
	virtual void LateUpdate(double deltaTime);

	////////////////////
	/// \brief Draw the scene in the given window.
	///
	/// \param window	Reference to the window on which to draw.
	///
	////////////////////
	virtual void Draw(Window& window);
};