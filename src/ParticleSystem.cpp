#include "ParticleSystem.h"

void ParticleSystem::init(int _amount, float _x, float _y){
	amount = _amount;
	for (int i = 0; i < _amount; i++) {
		Particle* particle = new Particle();
		particle->x = _x + (rand() * 500 / RAND_MAX * 1) / 2;
		particle->y = _y + (rand() * 500 / RAND_MAX * 1) / 2;
		particles.push_back(particle);
		//sstd::cout << "added " << i << std::endl;
	}
}



void ParticleSystem::update(SDL_Renderer* renderer, int targetX, int targetY){
	for (Particle* particle : particles) {
		if (particle->color.a == 0) {
			particle->x = targetX + (rand() % 10 - 1);
			particle->y = targetY + (rand() % 10 - 1);

			particle->velX = 0;
			//particle->velY = 0;
			particle->velY = -(((double)rand() / (RAND_MAX / 2)) + 1) / 2;

			particle->color.a = 255;

		}
		particle->update(renderer);
	}
}

void ParticleSystem::setStartColor(SDL_Color color) {
	for (Particle* particle : particles) {
		particle->startColor = color;
	}
}

void ParticleSystem::setEndColor(SDL_Color color) {
	for (Particle* particle : particles) {
		particle->endColor = color;
	}
}