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
    renderText(renderer, std::to_string(game_data.player1Score).c_str(), 72, 100, 100, false);
    renderText(renderer, std::to_string(game_data.player2Score).c_str(), 72, 100, 100, true);
    

}

/// <summary>
/// Render text at a position
/// https://stackoverflow.com/questions/36198732/draw-text-to-screen
/// </summary>
/// <param name="renderer"></param>
/// <param name="text"></param>
/// <param name="fontSize"></param>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="boundLeft"></param>
void MyGame::renderText(SDL_Renderer* renderer, const char* text, int fontSize, int x, int y, bool boundLeft)
{
    SDL_Color color = { 255, 255, 255 };;

    TTF_Init();
    TTF_Font* font = TTF_OpenFont("arial.ttf", fontSize);
    SDL_Surface* textSurface = TTF_RenderText_Blended(font, text, color);

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_Rect dest = { x, y, textSurface->w, textSurface->h };
    if (boundLeft) {
        dest = { 800 - x - textSurface->w, y, textSurface->w, textSurface->h };
    }
    SDL_RenderCopy(renderer, textTexture, NULL, &dest);

    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
    TTF_CloseFont(font);
    TTF_Quit();
}
