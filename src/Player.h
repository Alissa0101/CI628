#include "GameObject.h"

static struct Color {
    int r = 255;
    int g = 255;
    int b = 255;
	int a = 255;
};

class Player : public GameObject {
	public:
		Color color;
		SDL_Rect rect = { 0, 0, 20, 60 };
		SDL_Surface* surface;

		int angle = 0;

		void init(int _x, Color _color);

		void render(SDL_Renderer* renderer);

		void hit(int dir, int ballY);
};
