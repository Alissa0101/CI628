#pragma once
#include "Particle.h"
#include "SDL.h"
#include <vector>

#include "GameObject.h"


class ParticleSystem : public GameObject{
	private:

		int amount;
		std::vector<Particle*> particles;


	public:

		

		void init(int _amount, float x, float y);

		void update(SDL_Renderer* renderer, int targetX, int targetY);

		void setStartColor(SDL_Color color);
		void setEndColor(SDL_Color color);

		void destroy();

};

