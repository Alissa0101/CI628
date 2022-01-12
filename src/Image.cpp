#include "Image.h"
#include <SDL_image.h>

void Image::init(double _x, double _y, std::string path) {
	x = _x;
	y = _y;

	surface = IMG_Load(path.c_str());

	setSize(surface->w, surface->h);
}

void Image::render(SDL_Renderer* renderer) {

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_Rect rect = {x - w/2, y - h/2, w, h};

	SDL_RenderCopyEx(renderer, texture, NULL, &rect, 0, NULL, SDL_FLIP_NONE);

	SDL_DestroyTexture(texture);

}

void Image::setSize(double _w, double _h) {
	w = _w;
	h = _h;
}

void Image::end() {
	
	SDL_FreeSurface(surface);
}