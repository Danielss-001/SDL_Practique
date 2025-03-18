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

void StartScene::TextMenu(SDL_Renderer* renderer) {

	int width, height;																    // I use these variables to calculate the size of the window, if I resize this one 

	SDL_GetRenderOutputSize(renderer, &width, &height);								    // This function gets the size of the window in integer variables

	////////////////// TEXTURE IF THE SOURCES //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	SDL_Color color_title = { 255,255,255,255 };                                        // We implement the color to the text using SDL_Color

	SDL_Texture* texture = font.TextTexture(renderer, "JUMP RUNNING", color_title);		// Source texture call to implement a new text in the scene

	SDL_FRect rect_title = {															// Create new SDL_FRect to represent text in a block
		(width - 400.0f) / 2,															// Here we implement the center position of the text in the scene, using the window size ||| x axis
		(height - 100.0f) / 2,															// Here we implement the center position of the text in the scene, using the window size ||| y axis
		400.0f,
		100.0f };

	////////////////// HERE, WE IMPLEMENT ALL THE SETTINGS TO THE SECOND TEXT /////////////////////////////////////////////////////////////////////////////////////////////////

	SDL_Color color_menu_text = { 0,86,178,0 };											// Here, I have implemented SDL_Color to change the color in text render

	SDL_Texture* texture_menu = font.TextTexture(renderer, "START GAME!", color_menu_text); // We call TextTexture to assign new text and color, using the renderer

	SDL_FRect rect_menu = {																// Here, I use the SDL_FRect to set the position and size of the text
		((width - 200.0f) / 2) + 90.0f,													
		((height - 50.0f) / 2) + 90.0f,
		200.f,
		50.0f
	};

	////////////////// HERE, WE IMPLEMENT ALL THE SETTINGS TO THE THRID TEXT ///////////////////////////////////////////////////////////////////////////////////////////////////

	SDL_Texture* texture_menu_options = font.TextTexture(renderer, "OPTIONS", color_menu_text);

	SDL_FRect rect_menu_options = {
		((width - 100.0f) / 2) + 135.0f,
		((height - 50.0f) / 2) + 150.0f,
		100.f,
		50.0f
	};

	////////////////// HERE, WE IMPLEMENT ALL THE SETTINGS TO THE FOURTH TEXT ///////////////////////////////////////////////////////////////////////////////////////////////////

	SDL_Color color_exit_text = {104, 97, 172, 0};

	SDL_Texture* texture_menu_exit = font.TextTexture(renderer, "EXIT", color_exit_text);

	SDL_FRect rect_menu_exit = {
		((width - 50.0f) / 2) + 160.0f,
		((height - 20.0f) / 2) + 200.0f,
		50.f,
		20.0f
	};

	if (!texture || !texture_menu || !texture_menu_options || !texture_menu_exit) {      // Checks if the texture text is loaded correctly
		std::cout << "Texture is null!" << std::endl;
	}
	else {

		// I render the cascading text, implementing the RenderCopy of the FontConfig class 

		font.RenderCopy(renderer, texture, &rect_title);							     // If it loads correctly, we render the text in the scene
		font.RenderCopy(renderer, texture_menu, &rect_menu);				
		font.RenderCopy(renderer, texture_menu_options, &rect_menu_options);
		font.RenderCopy(renderer,texture_menu_exit, &rect_menu_exit);
	}
}

void StartScene::Render(SDL_Renderer* renderer) {										// Render scene
	

	SDL_SetRenderDrawColor(renderer,79,3,58,0);											// Here, We set the color of the scene

	camera.RenderObject(renderer,start_screen);											// Render new rectangle
	
	TextMenu(renderer);

}

void StartScene::StartResize(int newWidth, int newHeight) {								 // Method for resize the scene based on the window resizing event 
	
	start_screen.w = static_cast<float>(newWidth);										// Transform variable newWidth into a float parameter
	start_screen.h = static_cast<float>(newHeight);										// Transform variable newHeight into a float parameter

}