#pragma once
#include "SDL.h"
#include <SDL_ttf.h>

#include "GameObject.h"

class Button : public GameObject{

	private:

		SDL_Rect rect;

	public:

		void init(SDL_Rect rect);

		void render(SDL_Renderer* renderer);

		void destroy();

};