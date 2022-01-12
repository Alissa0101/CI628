#pragma once
#include "SDL.h"
#include <SDL_ttf.h>

#include "GameObject.h"

class Button : public GameObject{

	private:

		SDL_Rect rect;

		

	public:

		bool pressed = false;

		SDL_Color color = {255, 255, 255 ,255};
		SDL_Color hoverColor = {255, 255, 255, 255};
		SDL_Color renderColor;

		void init(SDL_Rect rect);

		void render(SDL_Renderer* renderer);

		void setHoverColor(SDL_Color color);

		bool isPointOverButton(double x, double y);

		void clickListener(SDL_Event& event);

		void hoverListener(SDL_Event& event);


};