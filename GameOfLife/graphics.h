//
//  graphics.h
//  
//
//  Created by Willy Chen on 8/21/16.
//
//

#ifndef ____graphics__
#define ____graphics__

#include <stdio.h>
#include <SDL2/SDL.h>

const int WINDOW_SIZE_X = 600;
const int WINDOW_SIZE_Y = 800;

class Graphics{
public:
    Graphics();
    Graphics(const Graphics&) = delete;
    ~Graphics();
    void render(const Game& game);
    
    double camera_x;
    double camera_y;
    double zoom;

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif /* defined(____graphics__) */

