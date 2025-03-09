#pragma once
#include <iostream>
#include <SDL3_ttf/SDL_ttf.h>							

class FontConfig {
private:

	TTF_Font* font;
	SDL_Texture* text_texture;

public:
	
	FontConfig();
	
	~FontConfig();
	
	// Method to initialize font
	bool FontInit();

	// Get texture to change different texts in differents scenes
	SDL_Texture* TextTexture(SDL_Renderer* ,const char* );

	// Method for rendering text using text texture
	void RenderCopy(SDL_Renderer* ,SDL_Texture*);

};
