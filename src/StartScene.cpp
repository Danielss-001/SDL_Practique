#include "../include/StartScene.h"
#include "../include/FactoryScene.h"

StartScene::StartScene(FactoryScene& factory) :											// Class constructor
	factory(factory)
{}

void StartScene::HandleEvents() {														// We implement the scene start event configuration
	
	SDL_Event event;

	while (SDL_PollEvent(&event)) {														// Initializes event loop checking
		if (event.type == SDL_EVENT_QUIT) {												// If event is to close thegame
			SDL_Quit();																	// Stop the game
			exit(0);																	// Close window
		}

		if (!is_game_started && event.type == SDL_EVENT_KEY_DOWN) {						// Check if the game does not start and you predd any key
			if (event.key.key == SDLK_RETURN) {											// If the key pressed is "Enter"
				is_game_started = true;													// Init game | Start Game
			}
		}
	}
}

void StartScene::Update(SDL_Renderer* renderer) {										// In this method the scene is updated and the first level initialized
	if (is_game_started) {																// If the game is initialized
		factory.SetLevelNumber(1);														// Set the level number on the first level
	}
}

void StartScene::Render(SDL_Renderer* renderer) {										// Render scene
	
	SDL_SetRenderDrawColor(renderer,79,3,58,0);											// Here, We set the color of the scene
	SDL_FRect start_screen = { 0.0f,0.0f,SCREEN_WIDTH,SCREEN_HEIGHT };					// Create new rectangle with the window height and width 
	SDL_RenderFillRect(renderer,&start_screen);											// Render new rectangle
}
