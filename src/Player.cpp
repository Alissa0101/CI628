#include "Player.h"

void Player::render(SDL_Renderer* renderer){
	rect.x = static_cast<int>(x);
	rect.y = static_cast<int>(y);
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(renderer, &rect);
}
