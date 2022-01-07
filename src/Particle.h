#pragma once
#include "GameObject.h"
#include "SDL.h"

class Particle : public GameObject{
	private:

		

	public:

		SDL_Color startColor = { 255, 255, 255 };
		SDL_Color endColor = { 255, 255, 255 };

		SDL_Color color = { 255, 255, 255, 0 };

		double velX = 0;//(rand() * 10.0 / RAND_MAX * 1) / 2;
		double velY = 0;// (rand() * 10.0 / RAND_MAX * 1) / 2;

		double accX = 0;// (rand() * 10.0 / RAND_MAX * 1) / 2;
		double accY = 0;// (rand() * 10.0 / RAND_MAX * 1) / 2;

		void init(SDL_Color _color);

		void update(SDL_Renderer* renderer);

		void lerpColors(double fraction);

		void render(SDL_Renderer* renderer);

		//void renderCircle(SDL_Renderer* renderer);

};

