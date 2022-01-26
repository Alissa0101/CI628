#include "Sound.h"

void Sound::init(){

	background = Mix_LoadMUS("Assets/Sounds/background.wav");
	bat = Mix_LoadWAV("Assets/Sounds/bat.wav");
	score = Mix_LoadWAV("Assets/Sounds/score.wav");
	gameOver = Mix_LoadWAV("Assets/Sounds/gamemover.wav");

}

void Sound::playSound(SoundTypes soundType) {
	switch (soundType) {
		case SOUND_BACKGROUND:
			Mix_PlayMusic(background, 100); break;
		case SOUND_HITBAT:
			Mix_PlayChannel(-1, bat, 0); break;
		case SOUND_SCORE:
			Mix_PlayChannel(-1, score, 0); break;
		case SOUND_GAMEOVER:
			Mix_PlayChannel(-1, gameOver, 0); break;
	}
}

void Sound::destroy() {
	Mix_FreeMusic(background);
}