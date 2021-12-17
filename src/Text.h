#include "GameObject.h"

class Text : public GameObject {
public:

	SDL_Color color = { 255, 255, 255, 255 };
	std::string text = "0";
	int fontSize = 72;
	bool boundRight = false;
	bool centerAlign = false;

	TTF_Font* font;//s = TTF_OpenFont("C:/Users/btwil/Desktop/University/Year 3/Multiplayer/CI628/build/pong.ttf", fontSize);

	void init(int xInit, int yInit, int fontSizeInit, bool boundRightInit, SDL_Color colorInit);

	void setText(std::string newText);

	void render(SDL_Renderer* renderer);

	void end();
};