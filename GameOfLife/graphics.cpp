//
//  graphics.cpp
//  
//
//  Created by Willy Chen on 8/21/16.
//
//

#include "graphics.h"
#include <cmath>

Graphics::Graphics(){
    camera_x = 0;
    camera_y = 0;
    zoom = 5;
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Game of Life", 0, 0, WINDOW_SIZE_X, WINDOW_SIZE_Y, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
}

Graphics::~Graphics() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Graphics::render(const Game& game) const {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect destination;
    // Draw board
    for (auto cellVal : game.living) {
        cell c = cellVal.first;
        if(c.first <= WINDOW_SIZE_X && c.first >= 0 && c.second <= WINDOW_SIZE_Y && c.second >=0){
            destination = {(int)(c.first * zoom - camera_x), (int)(c.second * zoom - camera_y), (int)ceil(zoom), (int)ceil(zoom)};
            SDL_RenderFillRect(renderer, &destination);
        }
    }
    
    SDL_RenderPresent(renderer);
}