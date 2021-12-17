#include "Button.h"

void Button::init(SDL_Rect _rect){
	rect = _rect;
}

void Button::render(SDL_Renderer* renderer){

    //std::cout << "button" << std::endl;


	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(renderer, &rect);
}

void Button::listener(SDL_Event& event) {
	switch (event.type) {
		case SDL_MOUSEBUTTONDOWN:
			//pressed = true;
			int x, y;
			Uint32 buttons;

			buttons = SDL_GetMouseState(&x, &y);

			if (rect.x <= x && x <= (rect.x + rect.w) && rect.y <= y && y <= (rect.y + rect.h)) {
				pressed = true;
			}
			break;
	}

	

}
