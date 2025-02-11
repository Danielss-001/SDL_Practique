#pragma once
#include <SDL3/SDL.h>

class Camera {
private:
	SDL_FRect camera;
public:

	// Constructor camera
	Camera(float x,float y,float screenWidth, float screenHeight);					
	
	// Control render object relative camera vision
	SDL_FRect TransformToCameraView(const SDL_FRect& worldRect) const;				

	// Control all renderer  objects depending the to camera view || Major Performance
	void RenderObject(SDL_Renderer* renderer,SDL_FRect worldRect) const;			

	// Update camera, where move by motion player center
	void UpdateCamera(const SDL_FRect* player, int levelWith, int levelHeight);		

	// Control camera size, if the resize window
	void CameraResize(int newWith, int newHeight);									
	
};
