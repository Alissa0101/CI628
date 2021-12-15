#include "Button.h"

void Button::init(SDL_Rect _rect){
	rect = _rect;
}

void Button::render(SDL_Renderer* renderer){


    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        switch (e.type) {
        case SDL_QUIT:
            break;
        case SDL_MOUSEBUTTONDOWN:
            rect.w = rect.w*1.1;
            break;

        }
    }

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &rect);
}

void Button::destroy(){
}
