#include "GameObject.h"

class Ball : public GameObject {
	public:
		
		SDL_Color color = { 255, 255, 255, 255 };
		int radius = 1;
		
		void init(int xInit, int yInit, int radiusInit, SDL_Color ColorInit);

		void render(SDL_Renderer* renderer);
};