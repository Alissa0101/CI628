#pragma once
#include <iostream>
#include <SDL_mixer.h>
#include "string"

enum SoundTypes {
	SOUND_BACKGROUND,
	SOUND_HITBAT,
	SOUND_SCORE,
	SOUND_GAMEOVER
};

class Sound {
private:

	Mix_Music* background;
	Mix_Chunk* bat;
	Mix_Chunk* score;
	Mix_Chunk* gameOver;

public:

	void init();

	void playSound(SoundTypes soundType);

	void destroy();
	
};