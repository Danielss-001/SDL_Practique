#include "../include/GameScene.h"
#include "../include/FactoryScene.h"												// Include FactoryScene.h for use implement methods in it

GameScene::GameScene(Player& player, Level& level, std::vector<std::vector<int>>& levels, FactoryScene& factory_scene) : // Constructor
	player(player),
	level(level),
	levels(levels),
	factory_scene(factory_scene)
{}

void GameScene::HandleEvents() {
	player.HandleInput();															// Call to the player's event method || Call method control handle input player (events)
}

void GameScene::Update(SDL_Renderer* renderer, Camera& camera, 
	int widtCamera, int heightCamera) {												// Implement render, camera and camera size to update camera with motion player on each frame

	player.Update(level.IsSolidCollisioner(levels,renderer),						// In the update player implement collisions with world and differents elements in the game
		level.ChangeLevelCoordenates(levels,renderer));

	if (player.ChangeLevelCheck(level.ChangeLevelCoordenates(levels,renderer))) {   // Get bool check from the player, to identify a change of level
		
		std::cout << "Change level: "<<factory_scene.GetLevelNumber()<<std::endl;	// Get the level_number that launches the current level
		factory_scene.SetLevelNumber(factory_scene.GetLevelNumber()+1);				// Change the level using the level_number, set in it
		return;																		// Reset the whole loop, to benefit th e game_scene
	}

	camera.UpdateCamera(&player.getRect(renderer), widtCamera, heightCamera);		// In this method, the camera is updated every time the player moves
}

void GameScene::Render(SDL_Renderer*renderer, Camera& camera) {						// Player, Objects and level rendering control | REMEMBER: The control rendering is from the camera
		
	for (const auto& tile : level.IsSolidCollisioner(levels,renderer)) {			// Here run through coordenates tiles vector 
		camera.RenderObject(renderer,tile);											// Level Tile rendering controller with loop
	}

	camera.RenderObject(renderer, level.ChangeLevelCoordenates(levels, renderer));	// Level change controller

	camera.RenderObject(renderer,player.getRect(renderer));							// Player rendering controller

}
