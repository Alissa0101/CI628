#include "Player.h"
#include <SDL_image.h>

void Player::render(SDL_Renderer* renderer){
	rect.x = static_cast<int>(x);
	rect.y = static_cast<int>(y);

	//SDL_Surface* image = SDL_LoadBMP("textTexture.png");
	SDL_Texture* texture = IMG_LoadTexture(renderer, "BatTexture.png");//SDL_CreateTextureFromSurface(renderer, image);

	SDL_Rect dstRect;

	//SDL_QueryTexture(texture, NULL, NULL, &dstRect.w, &dstRect.h);

	dstRect.x = rect.x;
	dstRect.y = rect.y;
	

	dstRect.w = rect.w;
	dstRect.h = rect.h;

	//SDL_RenderCopy(renderer, texture, NULL, NULL);
	//SDL_RenderPresent(renderer);
	
	SDL_RenderCopyEx(renderer, texture, NULL, &dstRect, angle, NULL, SDL_FLIP_NONE);

	if (angle > 0) {
		angle -= rand() % 10 + 1;
	} else if (angle < 0) {
		angle += rand() % 10 + 1;
	}
	if (angle >= -3 && angle <= 3) {
		angle = 0;
	}
	
	//SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	//SDL_RenderFillRect(renderer, &rect);

	//SDL_RenderCopyEx(renderer, tex, NULL, NULL, 0, NULL, SDL_FLIP_NONE);
	SDL_DestroyTexture(texture);
	
}

void Player::hit(int dir, int ballY) {

	angle = -((y + (rect.h/2))-ballY) * dir;
	
}


