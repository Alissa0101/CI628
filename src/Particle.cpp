#include "Particle.h"

void Particle::init(SDL_Color _color){
	color = _color;
}

void Particle::update(SDL_Renderer* renderer){
    //renderCircle(renderer);

	if (color.a > 0) {
		int newAlpha = color.a - (rand() % 18 - 1);
		if (newAlpha < 0) {
			color.a = 0;
		}
		else {
			color.a = newAlpha;
		}
	}
	

	velX += accX;
	velY += accY;
	
	x += velX;
	y += velY;
	//std::cout << velX << " " << velY << std::endl;
	render(renderer);
}

void Particle::render(SDL_Renderer* renderer)
{
	//std::cout << "Drawing" << std::endl;
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_ADD);
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_Rect rect = { x, y, 10, 10 };
	SDL_RenderFillRect(renderer, &rect);
}



//void Particle::renderCircle(SDL_Renderer* renderer){
//    std::cout << "Drawing" << std::endl;
//    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
//    int radius = 50;
//    int N = 2 * radius + 1;
//
//    int xLocal, yLocal;
//
//    for (int i = 0; i < N; i++)
//    {
//        for (int j = 0; j < N; j++)
//        {
//            xLocal = i - radius;
//            yLocal = j - radius;
//
//            if (xLocal * xLocal + yLocal * yLocal <= radius * radius + 1) {
//                SDL_RenderDrawPoint(renderer, xLocal + x, yLocal + y);
//            }
//        }
//    }
//}




