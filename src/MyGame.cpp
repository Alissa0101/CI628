#include "MyGame.h"


void MyGame::on_receive(std::string cmd, std::vector<std::string>& args) {
    if (cmd == "GAME_DATA") {
        // we should have exactly 4 arguments
        if (args.size() == 4) {
            game_data.player1Y = stoi(args.at(0));
            game_data.player2Y = stoi(args.at(1));
            game_data.ballX = stoi(args.at(2));
            game_data.ballY = stoi(args.at(3));
        }
    }
    else if (cmd == "SCORES") {
        if (args.size() == 2) {
            game_data.player1Score = stoi(args.at(0));
            game_data.player2Score = stoi(args.at(1 ));
        }
        
    }
    else {
        std::cout << "Received: " << cmd << std::endl;
    }
}

void MyGame::send(std::string message) {
    messages.push_back(message);
}

void MyGame::input(SDL_Event& event) {
    switch (event.key.keysym.sym) {
        case SDLK_w:
            send(event.type == SDL_KEYDOWN ? "W_DOWN" : "W_UP");
            break;
        case SDLK_s:
            send(event.type == SDL_KEYDOWN ? "S_DOWN" : "S_UP");
            break;
    }
}

void MyGame::update() {
    player1.y = game_data.player1Y;
    player2.y = game_data.player2Y;
    ball.x = game_data.ballX;
    ball.y = game_data.ballY;
}

void MyGame::render(SDL_Renderer* renderer) {
    //Render player 1
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &player1);

    //Render player 2
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawRect(renderer, &player2);

    //Render the ball
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderDrawRect(renderer, &ball);


    //Render scores
    SDL_Surface* text;

    SDL_Color color = { 255, 255, 255 };

    text = TTF_RenderText_Solid( font_Arial, "Test text", color);

    SDL_Texture* text_texture;

    text_texture = SDL_CreateTextureFromSurface(renderer, text);
    
    SDL_Rect dest = { 100, 100, text->w, text->h };

    SDL_RenderCopy(renderer, text_texture, &dest, NULL);
}   