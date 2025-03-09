#pragma once
#include "../include/IScene.h"
#include "../include/config.h"


class FactoryScene;										// Forward statement for the size used in memory for FactoryScene here | The include "FactoryScene.h" in "GameScene.cpp"

class GameScene : public IScene {
private:

	Player							player;
	Level							level;
	Camera&							camera;
	FactoryScene&					factory_scene;						
	SDL_FRect						pause_rect;
	GameWindow&						window;
	std::vector<std::vector<int>>	levels;
	bool							is_paused = false;
	int								width_camera;
	int								height_camera;

public:
	
	GameScene(Player& player, Level& level,std::vector<std::vector<int>>& levels, Camera&, int, int,FactoryScene&, GameWindow& window);	// Factory call to modify in GameScene

	// Here,we put player's and paused event control
	void HandleEvents()override;

	// In this method, set player's update
	void Update(SDL_Renderer* renderer)override;				

	// In this method, we set the camera render control for each scene
	void Render(SDL_Renderer* renderer) override;
	
	// This method implements the game pause event
	void HandlePausedEvents(SDL_Event& event);

	// Here, we are rendering the pause screen without rely(depender) on the camera render
	SDL_FRect RenderPauseScreen(SDL_Renderer* render);

	// Here, we get the pause variable
	bool const IsPaused();
};
