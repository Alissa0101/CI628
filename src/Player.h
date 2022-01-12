#include "GameObject.h"


class Player : public GameObject {
	public:
		SDL_Rect rect = { 0, 0, 20, 60 };
		SDL_Surface* surface;

		int angle = 0;

		void init(int _x);

		void render(SDL_Renderer* renderer);

		void hit(int dir, int ballY);


};
