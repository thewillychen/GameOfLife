//
//  graphics.h
//  
//


#ifndef ____graphics__
#define ____graphics__

#include <stdio.h>
#include <SDL2/SDL.h>
#include "game.h"

const int WINDOW_SIZE_X = 800;
const int WINDOW_SIZE_Y = 600;

class Graphics{
public:
    Graphics();
    Graphics(const Graphics&) = delete;
    ~Graphics();
    void render(const Game&) const;
    
    double camera_x;
    double camera_y;
    double zoom;

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif /* defined(____graphics__) */

