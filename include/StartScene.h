#pragma once
#include "../include/config.h"
#include "../include/IScene.h"

class FactoryScene;

class StartScene : public IScene {
private:
	FactoryScene&    factory;
	bool		     is_game_started = false;
public:

	StartScene(FactoryScene& factory);								// Constructor

	void HandleEvents() override;									// Handle control events inside events
	void Update(SDL_Renderer* renderer) override;					// Handle inputs and update scene
	void Render(SDL_Renderer* renderer) override;					// Handle control renderer each scene
};
