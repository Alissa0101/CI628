#include "Button.h"

void Button::init(SDL_Rect _rect){
	rect = _rect;
	renderColor = color;
}

void Button::setHoverColor(SDL_Color _color) {
	hoverColor = _color;
}

void Button::render(SDL_Renderer* renderer){

    //std::cout << "button" << std::endl;


	SDL_SetRenderDrawColor(renderer, renderColor.r, renderColor.g, renderColor.b, renderColor.a);
	SDL_RenderFillRect(renderer, &rect);
}

void Button::clickListener(SDL_Event& event) {
	switch (event.type) {
		case SDL_MOUSEBUTTONDOWN:
			//pressed = true;
			int x, y;
			Uint32 buttons;

			buttons = SDL_GetMouseState(&x, &y);

			if (isPointOverButton(x, y) == true) {
				pressed = true;
			}
			
			break;
	}
}

void Button::hoverListener(SDL_Event& event) {
	if (pressed == false) {
		int x, y;
		Uint32 buttons;

		buttons = SDL_GetMouseState(&x, &y);

		if (isPointOverButton(x, y) == true) {
			renderColor = hoverColor;
		}
		else {
			renderColor = color;
		}
	}
}

bool Button::isPointOverButton(double _x, double _y) {
	if (rect.x <= _x && _x <= (rect.x + rect.w) && rect.y <= _y && _y <= (rect.y + rect.h)) {
		return true;
	}
	return false;
}
