#include "../include/Camera.h"

Camera::Camera(float x, float y, float screenWidth, float screenHeight) : camera({x,y,screenWidth,screenHeight}) {}// Constructor

void Camera::UpdateCamera(const SDL_FRect* player, int levelWidth, int levelHeight) {

	// Using camera in function the position the player
	camera.x = player->x + player->w / 2 - camera.w / 2;				// Center camera in the coordenates player
	camera.y = player->y + player->h / 2 - camera.h / 2;				// Center camera in vertical position player

	// Avoid(evitar) that camera out level limits
	if (camera.x < 0) camera.x = 0;
	if (camera.y < 0) camera.y = 0;
	if (camera.x + camera.w > levelWidth) camera.x = levelWidth - camera.w;
	if (camera.y + camera.h > levelHeight) camera.y = levelHeight - camera.h;

	
}

// Method change coordenates the object to favor view camera 
SDL_FRect Camera::TransformToCameraView(const SDL_FRect& worldRect) const {

	SDL_FRect copyCoordenates = worldRect;								// Here copy coordenates from the original object

	// Adjust coordenates to camera view
	copyCoordenates.x -= camera.x;										// Adjust(ajustar) coordenates object for camera view in X axis
	copyCoordenates.y -= camera.y;										// Adjust(ajustar) coordenates object for camera view in Y axis

	return copyCoordenates;												// Return new object with new coordenates
}

// Renderer only object camera view || major performance at renderer only object in screen
void Camera::RenderObject(SDL_Renderer* renderer, SDL_FRect worldRect) const {

	SDL_FRect cameraViewRect = TransformToCameraView(worldRect);		// Transform global object to camera view 

	if (SDL_HasRectIntersectionFloat(&camera, &worldRect)) {			// Verify if world object is in camera view for guaranted the render object in camera view
		SDL_RenderFillRect(renderer, &cameraViewRect);					// Render new position object in camera view
	}
}

// Method control resized camera, change the camera struct fRect - 'w' and 'h'
void Camera::CameraResize(int newWidth, int newHeight) {
	
	camera.w = static_cast<float>(newWidth);							// Change width size in camera rect.w
	camera.h = static_cast<float>(newHeight);							// Change height size in camera rect.h

}