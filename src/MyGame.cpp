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
            game_data.player2Score = stoi(args.at(1));
            player1ScoreText.setText(std::to_string(game_data.player1Score));
            player2ScoreText.setText(std::to_string(game_data.player2Score));
        }
        std::cout << "Received: " << cmd << " args: " << args.size() << std::endl;
    }
    else if (cmd == "BALL_HIT_BAT1") {
        if (args.size() == 0) {
            player1.hit(1, ball.y);
        }
        std::cout << "Received: " << cmd << " args: " << args.size() << std::endl;
    }
    else if (cmd == "BALL_HIT_BAT2") {
        if (args.size() == 0) {
            player2.hit(-1, ball.y);
        }
        std::cout << "Received: " << cmd << " args: " << args.size() << std::endl;
    }
    else {
        std::cout << "Received: " << cmd << " args: " << args.size() << std::endl;
    }
}

void MyGame::send(std::string message) {
    messages.push_back(message);
}

void MyGame::init(){

    ball.init(100, 100, 10, {255, 255, 0});

    player1.init(800 / 4, { 255, 255, 255, 255 });
    player2.init(3 * 800 / 4 - 20, { 255, 255, 255, 255 });

    //player1.rect = { 0, 0, 20, 60 };
    //player1.color = { 255, 255, 255, 255 };
    //player1.x = 800 / 4; // put the player on the left

    //player2.rect = { 0, 0, 20, 60 };
    //player2.color = { 255, 255, 255, 255 };
    //player2.x = 3 * 800 / 4 - 20; // put the player on the right

    player1ScoreText.init(100, 100, 72, false, {255, 255, 255});
    player2ScoreText.init(100, 100, 72, true, {255, 255, 255});

    particles.init(1000, 400, 400);
    
}

void MyGame::input(SDL_Event& event) {
    switch (event.key.keysym.sym) {
        case SDLK_w:
            send(event.type == SDL_KEYDOWN ? "W_DOWN" : "W_UP");
            break;
        case SDLK_s:
            send(event.type == SDL_KEYDOWN ? "S_DOWN" : "S_UP");
            break;
        case SDLK_i:
            send(event.type == SDL_KEYDOWN ? "I_DOWN" : "I_UP");
            break;
        case SDLK_k:
            send(event.type == SDL_KEYDOWN ? "K_DOWN" : "K_UP");
            break;
    }
}

void MyGame::update() {
    player1.y = game_data.player1Y;
    player2.y = game_data.player2Y;
    ball.x = game_data.ballX;
    ball.y = game_data.ballY;
    //particles.follow(ball.x, ball.y);
    //particles.fade(ball.x, ball.y);
}

void MyGame::render(SDL_Renderer* renderer) {

    particles.update(renderer, ball.x, ball.y);

    ball.render(renderer);

    player1.render(renderer);
    player2.render(renderer);
    
    player1ScoreText.render(renderer);
    player2ScoreText.render(renderer);

}

void MyGame::end() {
    player1ScoreText.end();
    player2ScoreText.end();
}

