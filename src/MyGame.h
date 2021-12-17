#ifndef __MY_GAME_H__
#define __MY_GAME_H__

#include <iostream>
#include <vector>
#include <string>

#include "SDL.h"
#include <SDL_ttf.h>


#include "Player.h"
#include "Text.h"
#include "Ball.h"
#include "ParticleSystem.h"
#include "Button.h"

static struct GameData {
    int player1Y = 0;
    int player2Y = 0;
    int ballX = 0;
    int ballY = 0;
    int player1Score = 0;
    int player2Score = 0;
} game_data;

class MyGame {

    private:
        //SDL_Rect player1 = { 800/4, 0, 20, 60 };
        //SDL_Rect player2 = { 3 * 800 / 4 - 20, 0, 20, 60 };
        //SDL_Rect ball = {0, 0, 10, 10};
        
        Ball ball;

        Player player1;
        Player player2;

        Text player1ScoreText;
        Text player2ScoreText;

        Text titleText;

        Text player1ButtonText;
        Text player2ButtonText;

        ParticleSystem particles;

        Button player1Button;
        Button player2Button;

        bool enablePlayer1Controls = true;

        bool player1Ready = false;
        bool player2Ready = false;

        bool globalReady = false;
        bool localReady = false;
       
        
    public:
        std::vector<std::string> messages;

        void init();
        void initGameWorld();

        void on_receive(std::string message, std::vector<std::string>& args);
        void send(std::string message);
        void input(SDL_Event& event);
        void update();
        void render(SDL_Renderer* renderer);

        void renderFilledCircle(SDL_Renderer* renderer, int radius, int xOffset, int yOffset);

        void end();


};

#endif