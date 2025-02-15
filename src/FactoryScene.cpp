#include "../include/FactoryScene.h"
#include "../include/GameScene.h"												// Include here "GameScene.h" to avoid problems related to the cycle of declarations between two classes

FactoryScene::FactoryScene(Player& player, Level& level) :						// Constructor class
	player(player),
	level(level),
	level_number(1)
{}

void FactoryScene::Update( SDL_Renderer* render, Camera& camera, int width, int height) { // In this method the factory update is implemented

	if (!game_scene) {															// If you do not implement game_scene, create new scene		

		switch (level_number) {													// Change level_number 
		case 0:																	// introduction and the title the game scene
			break;

		case 1:																	// Chage level one

			game_scene = std::make_unique<GameScene>(player,					// Create new scene with level One rendering. PDT: don't forget to create an abstract level class
				level,															// ... for different change in physics and atmosphere, using interfaces :)
				Levels::levelOne, 
				*this);

			break;
		case 2:																	// Change level two

			game_scene = std::make_unique<GameScene>(player,					// Change new scene with level Two rendering settings in level.
				level, 
				Levels::levelTwo, 
				*this);

			break;
		default:
			return;
		}
	}

	game_scene->HandleEvents();													// Here, it calls the game scene event handler for use in the main loop
	game_scene->Render(render, camera);											// The scene rendering handler is called here
	game_scene->Update(render, camera, width, height);							// Method for called update scene

}


void FactoryScene::SetLevelNumber(int new_level) {

	if (level_number != new_level) {											// If the number of the level changes
		level_number = new_level;												// Asign nwe number level
		game_scene.reset();														// Clean memory and reset game_scene
	}
}
int FactoryScene::GetLevelNumber() const {										// Obtain the current numerical level
	return level_number;
}