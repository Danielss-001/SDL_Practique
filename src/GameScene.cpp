#include "../include/GameScene.h"
#include "../include/FactoryScene.h"												// Include FactoryScene.h for use implement methods in it

GameScene::GameScene(Player& player, 
	Level& level, 
	std::vector<std::vector<int>>& levels, 
	Camera& camera, 
	int width_camera, 
	int height_camera, 
	FactoryScene& factory_scene,
	GameWindow& window):												   // Scene Constructor

	player(player),
	level(level),
	levels(levels),
	camera(camera),
	width_camera(width_camera),
	height_camera(height_camera),
	factory_scene(factory_scene),
	window(window)
{
	pause_rect = { 0.0f, 0.0f, SCREEN_WIDTH , SCREEN_HEIGHT };				// Create FRect for the pause screen 
}

void GameScene::HandleEvents() {													// Scene event control

	SDL_Event event;

	while (SDL_PollEvent(&event)) {													// Its true if capturing anything event | CHECK MAIN LOOP EVENT IN THIS GAME SCENE
		switch (event.type) {

		case SDL_EVENT_QUIT:														// If event-type is quit application
			
			SDL_Quit();																// Stop SDL game
			exit(0);																// Close window
			
			break;

		case SDL_EVENT_KEY_DOWN:													// If the type of event is any key pressed 
			
			HandlePausedEvents(event);												// We Call the pause event control
			
			break;
		
		default:
			break;
		}

		if (!is_paused) {															// If you don't paused the game, we will read the player's event
			player.HandleInput(event);												// Call to the player's event method || Call method control handle input player (events)
		}
	}

}

void GameScene::HandlePausedEvents(SDL_Event& event) {								// We Implemented event pause control

	if (event.key.key == SDLK_P) {													// Check if the key is "p"
		is_paused = !is_paused;														// Change "is_paused" depending on key pressed
		std::cout << (is_paused ? "game Paused" : "game resumed")					// Check if the game is paused or not 
			<< std::endl;
	}
}

void GameScene::Update(SDL_Renderer* renderer) {									// Implement render, camera and camera size to update camera with motion player on each frame

	if (is_paused) {																// If the game is paused, we stop updating the game in the loop main
		return;
	}

	player.Update(level.IsSolidCollisioner(levels,renderer),						// In the update player implement collisions with world and differents elements in the game
		level.ChangeLevelCoordenates(levels,renderer));

	if (player.ChangeLevelCheck(level.ChangeLevelCoordenates(levels,renderer))) {   // Get bool check from the player, to identify a change of level
	
		std::cout << "Change level: "<<factory_scene.GetLevelNumber()<<std::endl;	// Get the level_number that launches the current level
		factory_scene.SetLevelNumber(factory_scene.GetLevelNumber()+1);				// Change the level using the level_number, set in it
		return;																		// Reset the whole loop, to benefit th e game_scene
	}
	if (player.PlayerIsDead()) {													
	
		std::cout << "Player is dead!" << " New level: \n" <<						// Verification of dead player and new level number
			factory_scene.GetLevelNumber() << std::endl;						

		factory_scene.SetLevelNumber(factory_scene.GetLevelNumber()-1);				// Resets the level number if the player is dead
		return;
	}


	camera.UpdateCamera(&player.getRect(renderer), width_camera, height_camera);	// In this method, the camera is updated every time the player moves
}

void GameScene::Render(SDL_Renderer*renderer) {										// Player, Objects and level rendering control | REMEMBER: The control rendering is from the camera
	
	if (is_paused) {
		RenderPauseScreen(renderer);
	}

	for (const auto& tile : level.IsSolidCollisioner(levels,renderer)) {			// Here run through coordenates tiles vector 
		camera.RenderObject(renderer,tile);											// Level Tile rendering controller with loop
	} 

	camera.RenderObject(renderer, level.ChangeLevelCoordenates(levels, renderer));	// Level change controller

	camera.RenderObject(renderer,player.getRect(renderer));							// Player rendering controller

}


SDL_FRect GameScene::RenderPauseScreen(SDL_Renderer* render) {						// Here, we implement the rendering settings of the game pause 
	
	SDL_SetRenderDrawColor(render,0,0,0,150);										// Set pause screen color

	pause_rect.w = static_cast<float>(window.NewSizeWindow()[0]);
	pause_rect.h = static_cast<float>(window.NewSizeWindow()[1]);
	
	SDL_RenderFillRect(render,&pause_rect);											// We render without relying on camera rendering

	return pause_rect;																// Return the rect of the screen
}

bool const GameScene::IsPaused() {													// We get the pause variable
	return is_paused;
}

