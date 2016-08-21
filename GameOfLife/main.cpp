//
//  main.cpp
//  GameOfLife
//

#include <iostream>
#include <vector>
#include <fstream>
#include "graphics.h"
#include "game.h"

using namespace std;
const int TARGET_FRAMERATE = 60;
const int TARGET_TICKRATE = 2;
const int FRAMES_PER_TICK = TARGET_FRAMERATE / TARGET_TICKRATE;
const int TARGET_TIMESTEP = 1000 / TARGET_FRAMERATE;

vector<cell> parseInput(string file){
    string line;
    ifstream input;
    input.open(file);
    vector<cell> aliveCells;
    while(getline(input, line)){
        istringstream iss(line);
        long long x, y;
        if(!(iss >> x >> y)){
            break; //error
        }
        cell c = make_pair(x, y);
        aliveCells.push_back(c);
    }
    input.close();
    return aliveCells;
}

int main(int argc, const char * argv[]) {
    std::cout << "Game of life\n";
    Game gol = Game(parseInput(argv[1]));
    Graphics graphics;
    unsigned int timestep, time0, time1 = 0;
    unsigned int frame_count = 0;
    bool quit = false;
    SDL_Event e;
    gol.pause();
    
    while(!quit){
        time0 = time1;
        time1 = SDL_GetTicks();
        timestep = time1-time0;
        frame_count++;
        
        if (frame_count % FRAMES_PER_TICK == 0) {
            gol.update();
            gol.print();
        }
        
        while(SDL_PollEvent(&e) !=0){
            //Quit game of life
            if(e.type == SDL_QUIT){
                quit = true;
            }
            //Pause
            else if (e.type == SDL_KEYDOWN and e.key.keysym.sym == SDLK_SPACE) {
                gol.pause();
            }
        }
        
        graphics.render(gol);
        
        if (timestep < TARGET_TIMESTEP) {
            SDL_Delay(TARGET_TIMESTEP - timestep);
            time1 += TARGET_TIMESTEP - timestep;
        }
    }
    cout << "Exiting Game" << endl;
    return 0;
}


















