#pragma once
#include <SDL3/SDL.h>

class Camera {
private:
	SDL_FRect camera;
public:
	Camera(float x,float y,float screenWidth, float screenHeight);					// Constructor camera
	
	SDL_FRect TransformToCameraView(const SDL_FRect& worldRect) const;				// Control render object relative camera vision
	void RenderObject(SDL_Renderer* renderer,SDL_FRect worldRect) const;			// Control all renderer  objects depending the to camera view || Major Performance
	void UpdateCamera(const SDL_FRect* player, int levelWith, int levelHeight);
	void SmoothCameraUpdate(const SDL_FRect* player, float lerpFactor);
	
};
