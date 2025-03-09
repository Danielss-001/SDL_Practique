#include "../include/FontConfig.h"															// IMPORTANT :: The font size depends on the copyRender, specifically on the SDL_FRect where the texture is inserted in SDL_RenderTexture
#include "../include/config.h"

FontConfig::FontConfig() {																	// This method is the constructor. Here, set the TTF and Texture of the text punter to null
	font = nullptr;																			// Punter text	
	text_texture = nullptr;																	// Punter texture text
}

bool FontConfig::FontInit() {																// Here, the source is initialized, just like the window, you need to initialize the fonts and the verification test.

	if (TTF_Init() != 1) {																	// Call "TTF_Init" to initialize the source 
		std::cout << "Error init ttf: " << SDL_GetError() << std::endl;						// Verification error 
		return false;																		// If an error is encountered it returns false
	}

	font = TTF_OpenFont("./assets/block.ttf",50.0f);										// We open the TTF method to access the font type and implement the font size

	if (!font) {																			// If the source is not found, returns error
		std::cout << "Error load font: " <<SDL_GetError()<< std::endl;						// Checking the type of error
		return false;
	}
	return true;																			// This method return an boolean 
}

// ------- REMEMBER :: Implement the color structure for color change
SDL_Texture* FontConfig::TextTexture(SDL_Renderer* renderer, const char* text) {			// This method returns SDL_Texture, required for RenderTexture,and also implements the text or words to be renderer

	if (!font) {																			// here, we check if the source is not found
		std::cout << "Error in font load" << std::endl;
	}

	SDL_Color text_color = {255,255,255,255};												// Implement SDL_Color to assign a new color to the text

	SDL_Surface* text_surface = TTF_RenderText_Solid(font,text,strlen(text), text_color);	// Create a surface, necessary for the text renderer ... here insert new text and color

	if (!text_surface) {																	// We check if the surface has not been created correctly
		std::cout << "Error in surface: " << SDL_GetError() << std::endl;
		return nullptr;																		// if an error encountered it returns nullptr 
	}

	text_texture = SDL_CreateTextureFromSurface(renderer,text_surface);						// Assign a new texture to texture punter using surface
	SDL_DestroySurface(text_surface);														// Destroy surface

	return text_texture;																	// Return texture created
}

// ------- REMEMBER :: It is possible to create SDL_FRect in different scenes to change the position and size of the font -------
void FontConfig::RenderCopy(SDL_Renderer* renderer, SDL_Texture* texture) {					// This method is used to apply the texture to the text render

	SDL_FRect rect = {																		// Create new SDL_FRect to represent text in a block
		(SCREEN_WIDTH - 400.0f)/2,															// Here we implement the position of the text in the scene, using the window size ||| x axis
		(SCREEN_HEIGHT - 100.0f)/2,															// Here we implement the position of the text in the scene, using the window size ||| y axis
		400.0f, 
		100.0f };
	SDL_RenderTexture(renderer,texture,NULL, &rect);										// Use SDL_RenderTexture to render text, using texture and new rect
}

FontConfig::~FontConfig() {																	// This method is the class destructor. In this method all the pointers implemented in the class are destroyed, cleaning the memory
	SDL_DestroyTexture(text_texture);
	TTF_CloseFont(font);
	TTF_Quit();
}