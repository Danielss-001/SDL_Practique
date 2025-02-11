#include "../include/GameScene.h"

GameScene::GameScene(Player& player, Level& level,std::vector<std::vector<int>>& levels) : // Constructor
	player(player), 
	level(level), 
	levels(levels)
{}

void GameScene::HandleEvents() {
	player.HandleInput();															// Call to the player's event method || Call method control handle input player (events)
}

void GameScene::Update(SDL_Renderer* renderer, Camera& camera, 
	int widtCamera, int heightCamera) {												// Implement render, camera and camera size to update camera with motion player on each frame

	player.Update(level.IsSolidCollisioner(levels,renderer),						// In the update player implement collisions with world and differents elements in the game
		level.ChangeLevelCoordenates(levels,renderer));

	camera.UpdateCamera(&player.getRect(renderer), widtCamera, heightCamera);		// In this method, the camera is updated every time the player moves
}

void GameScene::Render(SDL_Renderer*renderer, Camera& camera) {						// Player, Objects and level rendering control | REMEMBER: The control rendering is from the camera
	
	for (const auto& tile : level.IsSolidCollisioner(levels,renderer)) {			// Here run through coordenates tiles vector 
		camera.RenderObject(renderer,tile);											// Level Tile rendering controller with loop
	}

	camera.RenderObject(renderer, level.ChangeLevelCoordenates(levels, renderer));	// Level change controller

	camera.RenderObject(renderer,player.getRect(renderer));							// Player rendering controller

}
