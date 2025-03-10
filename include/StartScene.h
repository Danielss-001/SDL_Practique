#pragma once
#include "../include/config.h"
#include "../include/IScene.h"
#include "../include/FontConfig.h"

class FactoryScene;

class StartScene : public IScene {
private:

	FactoryScene&    factory;
	FontConfig		 font;
	Camera&			 camera;
	SDL_FRect		 start_screen;						
	bool		     is_game_started = false;						// Initialized bool to false, until the "enter" key event triggers it

public:

	StartScene(Camera&,FactoryScene& factory);						// Constructor

	void HandleEvents() override;									// Handle control events inside events
	void Update(SDL_Renderer* renderer) override;					// Handle inputs and update scene
	void Render(SDL_Renderer* renderer) override;					// Handle control renderer each scene

	// This method is used to rewrite the size of the start-scene
	void StartResize(int,int);										 
};
