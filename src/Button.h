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

		void init(SDL_Rect rect);

		void render(SDL_Renderer* renderer);

		void listener(SDL_Event& event);


};