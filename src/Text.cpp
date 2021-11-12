#include "Text.h"



void Text::init(int xInit, int yInit, int fontSizeInit, bool boundRightInit, SDL_Color colorInit){
    color = colorInit;
    x = xInit;
    y = yInit;
    fontSize = fontSizeInit;
    boundRight = boundRightInit;
    font = TTF_OpenFont("pong.ttf", fontSize);
}

void Text::setText(std::string newText){
    
    if (text.compare(newText)) {
        color.a = 0;
    }
    text = newText;
}

/// <summary>
/// Render text
/// https://stackoverflow.com/questions/36198732/draw-text-to-screen
/// </summary>
/// <param name="renderer"></param>
/// <param name="text"></param>
/// <param name="fontSize"></param>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="boundRight"></param>
void Text::render(SDL_Renderer* renderer){

    if(text == ""){text = " "; }

    //not great. Find a way to store this somewhere
    SDL_Surface* textSurface = TTF_RenderText_Blended(font, text.c_str(), color);

    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_Rect dest = { x, y, textSurface->w, textSurface->h };
    if (boundRight) {
        dest = {  800 - static_cast<int>(x) - textSurface->w, static_cast<int>(y), textSurface->w, textSurface->h };
    }
    SDL_RenderCopy(renderer, textTexture, NULL, &dest);

    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
    //TTF_CloseFont(font);
    //TTF_Quit();
    if (color.a < 255) {
        if (color.a + 10 > 255) {
            color.a = 255;
        }
        else {
            color.a += 10;
        }
    }
}

void Text::end(){
    TTF_CloseFont(font);
    TTF_Quit();
}
