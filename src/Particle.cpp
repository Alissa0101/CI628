#include "Particle.h"

void Particle::init(SDL_Color _color){
	color = _color;
}

void Particle::update(SDL_Renderer* renderer){
    //renderCircle(renderer);

	if (color.a > 0) {
		int newAlpha = color.a - (rand() % 19 - 1);
		if (newAlpha < 0) {
			color.a = 0;
		}
		else {
			color.a = newAlpha;
		}
	}
	
	lerpColors((double)color.a/255);

	velX += accX;
	velY += accY;
	
	x += velX;
	y += velY;
	//std::cout << velX << " " << velY << std::endl;
	render(renderer);
}

void Particle::lerpColors(double fraction) {
	color.r = (startColor.r - endColor.r) * fraction + endColor.r;
	color.g = (startColor.g - endColor.g) * fraction + endColor.g;
	color.b = (startColor.b - endColor.b) * fraction + endColor.b;
}

void Particle::render(SDL_Renderer* renderer)
{
	//std::cout << "Drawing" << std::endl;
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_ADD);
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_Rect rect = { x, y, 10, 10 };
	SDL_RenderFillRect(renderer, &rect);
}




