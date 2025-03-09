#include "../include/StartScene.h"
#include "../include/FactoryScene.h"

StartScene::StartScene(Camera& camera, FactoryScene& factory) :							// Class constructor
	factory(factory),
	camera(camera)
{
	start_screen = { 0.0f, 0.0f, SCREEN_WIDTH,SCREEN_HEIGHT };							// Create new rectangle with the window height and width

	if (!font.FontInit()) {																// Here we initialize the font, for later use of the text renderer
		return;
	}

}

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
		
		if (event.window.type == SDL_EVENT_WINDOW_RESIZED) {							// Check if the window resize event is triggered. If so, resize the start-scene
			
			std::cout << "Window Resize" << std::endl;									// Confirm the window resizing event

			StartResize(event.window.data1, event.window.data2);						// Call method startResize to change width and height
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

	camera.RenderObject(renderer,start_screen);											// Render new rectangle
	
	SDL_Texture* texture = font.TextTexture(renderer, "START GAME");					// Source texture call to implement a new text in the scene

	if (!texture) {																		// Checks if the texture text is loaded correctly
		std::cout << "Texture is null!" << std::endl;
	}
	else {
		font.RenderCopy(renderer,texture);												// If it loads correctly, we render the text in the scene
	}

}

void StartScene::StartResize(int newWidth, int newHeight) {								// Method for resize the scene based on the window resizing event 
	
	start_screen.w = static_cast<float>(newWidth);										// Transform variable newWidth into a float parameter
	start_screen.h = static_cast<float>(newHeight);										// Transform variable newHeight into a float parameter

}