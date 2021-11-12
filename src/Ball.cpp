#include "Ball.h"

void Ball::init(int xInit, int yInit, int radiusInit, SDL_Color ColorInit){
	x = xInit;
	y = yInit;
	radius = radiusInit;
	color = ColorInit;
}

void Ball::render(SDL_Renderer* renderer){
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    int N = 2 * radius + 1;

    int xLocal, yLocal;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            xLocal = i - radius;
            yLocal = j - radius;

            if (xLocal * xLocal + yLocal * yLocal <= radius * radius + 1) {
                SDL_RenderDrawPoint(renderer, xLocal + x, yLocal + y);
            }
        }
    }
}
