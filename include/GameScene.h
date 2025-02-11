#pragma once
#include "../include/IScene.h"

class GameScene : public IScene {
private:
	Player player;
	Level level;
	std::vector<std::vector<int>> levels;
public:

	GameScene(Player& player, Level& level,std::vector<std::vector<int>>& levels);

	// Here,we put player's event control
	void HandleEvents()override;

	// In this method, set player's update
	void Update(SDL_Renderer* renderer,Camera&,int,int)override;				

	// In this method, we set the camera render control for each scene
	void Render(SDL_Renderer* renderer, Camera&) override;
};
