#pragma once
#include "../include/IScene.h"

class FactoryScene;										// Forward statement for the size used in memory for FactoryScene here | The include "FactoryScene.h" in "GameScene.cpp"

class GameScene : public IScene {
private:
	Player							player;
	Level							level;
	FactoryScene&					factory_scene;						
	std::vector<std::vector<int>>	levels;
public:
	
	GameScene(Player& player, Level& level,std::vector<std::vector<int>>& levels, FactoryScene& );	// Factory call to modify in GameScene

	// Here,we put player's event control
	void HandleEvents()override;

	// In this method, set player's update
	void Update(SDL_Renderer* renderer,Camera&,int,int)override;				

	// In this method, we set the camera render control for each scene
	void Render(SDL_Renderer* renderer, Camera&) override;
};
