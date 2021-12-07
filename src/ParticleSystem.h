#pragma once
#include "Particle.h"
#include "SDL.h"
#include <vector>


class ParticleSystem{
	private:

		int amount;
		std::vector<Particle*> particles;


	public:

		void init(int _amount, float x, float y);

		void update(SDL_Renderer* renderer, int targetX, int targetY);

		void destroy();

};

