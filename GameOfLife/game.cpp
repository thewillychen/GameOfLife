//
//  game.cpp
//  
//


#include "game.h"
using namespace std;

//Instantiates the original living cells of the game of life
Game::Game(vector<cell> cells){
    generation = 0;
    paused = true;
    for(cell c : cells){
        living[c] = 1;
    }
}

//Determine the next generation
//Iterates through living cells
//Checks the number of neighbors while adding dead neighbors to another map
//Applies Conway's Game of Life rules to currently living cells and then dead cells
void Game::update(){
    if(paused){
        return;
    }
    cell_map nextGen;
    generation++;
    for(auto cellValue : living){
        cell c = cellValue.first;
        int numAlive = countNeighbors(c.first, c.second);
        if(numAlive == 2 || numAlive == 3){
            nextGen[c] = 1;
        }
    }
    
    for(auto cellToCount : deadNeighbors){
        if(cellToCount.second == 3){
            nextGen[cellToCount.first] = 1;
        }
    }
    deadNeighbors.clear();
    
    living = nextGen;
    return;
}

//Checks each of the 8 positions around x,y
//Adds dead neighbors to the dead neighbors map to check if these will be alive next gen
int Game::countNeighbors(long long x, long long y){
    int numAlive = 0;
    for(int d = 0; d <8; d++){
        cell c = make_pair(x+dx[d],y+dy[d]);
        if(living.count(c) > 0){
            numAlive++;
        }
        else{
            deadNeighbors[c]+=1;
        }
    }
    return numAlive;
}

void Game::printVerbose(){
    cout << "Generation: " << generation << " Living cells: " << living.size() << endl;
    for(auto cellValue : living){
        cout << cellValue.first.first << ", " << cellValue.first.second << endl;
    }
}

void Game::print(){
    cout << "Generation: " << generation << " Living cells: " << living.size() << endl;
    return;
}

void Game::pause(){
    paused = !paused;
    return;
}