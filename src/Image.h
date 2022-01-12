#pragma once
#include "GameObject.h"
#include "SDL.h"

class Image : public GameObject {
	private:

		std::string imgPath = "";

		SDL_Surface* surface;

		double w;
		double h;

	public:

		void init(double x, double y, std::string path);

		void render(SDL_Renderer* renderer);

		void setSize(double w, double h);

		void end();

};