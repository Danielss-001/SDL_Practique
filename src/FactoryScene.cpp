#include "../include/FactoryScene.h"
#include "../include/GameScene.h"												// Include here "GameScene.h" to avoid problems related to the cycle of declarations between two classes
#include "../include/StartScene.h"

FactoryScene::FactoryScene(Player& player, Level& level) :						// Constructor class
	player(player),
	level(level),
	level_number(0)
{}

void FactoryScene::Update(GameWindow& window, 
	SDL_Renderer* render,  
	Camera& camera, 
	int width, 
	int height) {																// In this method the factory update is implemented

	if (level_number > 3) {														// Here it is checked that the level number does not exceed 3
		level_number = 1;														// Assing 1 in the level number
	}
	
	if (!game_scene) {															// If you do not implement game_scene, create new scene		

		switch (level_number) {													// Change level_number 

		case 0:																	// introduction and the title the game scene

			game_scene = std::make_unique<StartScene>(*this);					// Create the start scene 

			break;

		case 1:																	// Chage level one
			
			window.SetBackgroundColor(66, 199, 255, 0);							// Here you set the background color depending on the level

			level.SetTileColor(1, 75, 0, 0);									// Here the color of the tiles is set according to the level

			game_scene = std::make_unique<GameScene>(player,					// Create new scene with level One rendering. PDT: don't forget to create an abstract level class
				level,															// ... for different change in physics and atmosphere, using interfaces :)
				Levels::levelOne, 
				camera, width, height,
				*this);

			break;
		case 2:																	// Change level two

			window.SetBackgroundColor(124, 133, 190, 0);						// Here you set the background color depending on the level

			level.SetTileColor(60, 10, 30, 0);									// Here the color of the tiles is set according to the level

			game_scene = std::make_unique<GameScene>(player,					// Change new scene with level Two rendering settings in level.
				level, 
				Levels::levelTwo, 
				camera, width, height,
				*this);

			break;
		case 3:

			window.SetBackgroundColor(250, 180, 195, 0);						// Here you set the background color depending on the level

			level.SetTileColor(100, 80, 85, 0);									// Here the color of the tiles is set according to the level

			game_scene = std::make_unique<GameScene>(player,					// Change new scene with level Two rendering settings in level.
				level,
				Levels::levelThree,
				camera, width, height,
				*this);
			break;
		default:
			return;
		}
	}

	SDL_SetRenderDrawColor(render,window.GetBackgroundColor().r,				// Here the window method is called to the maintain the new color set at each level
		window.GetBackgroundColor().g,											// IMPORTANT: You are using for the rendering behavior | 1. background 2. tiles 3. player
		window.GetBackgroundColor().b, 
		window.GetBackgroundColor().a);

	window.clear();																// Clear window rewrite color and render

	game_scene->HandleEvents();													// Here, it calls the game scene event handler for use in the main loop
	game_scene->Render(render);													// The scene rendering handler is called here
	game_scene->Update(render);													// Method for called update scene

}


void FactoryScene::SetLevelNumber(int new_level) {								// The Method sets the level number

	if (level_number != new_level) {											// If the number of the level changes
		level_number = new_level;												// Asign new number level
		game_scene.reset();														// Clean memory and reset game_scene
	}
}
int FactoryScene::GetLevelNumber() const {										// Obtain the current numerical level
	return level_number;
}