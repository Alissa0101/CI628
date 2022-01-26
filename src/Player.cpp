#include "Player.h"
#include <SDL_image.h>

void Player::init(int _x){
	x = static_cast<int>(_x);

	surface = IMG_Load("Assets/BatTexture.png");

}

void Player::render(SDL_Renderer* renderer){
	rect.x = static_cast<int>(x);
	rect.y = static_cast<int>(y);

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	

	//SDL_RenderCopy(renderer, texture, NULL, NULL);
	//SDL_RenderPresent(renderer);
	
	SDL_RenderCopyEx(renderer, texture, NULL, &rect, angle, NULL, SDL_FLIP_NONE);

	if (angle > 0) {
		angle -= rand() % 10 + 1;
	} else if (angle < 0) {
		angle += rand() % 10 + 1;
	} if (angle >= -3 && angle <= 3) {
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


