//
//  game.cpp
//  
//
//  Created by Willy Chen on 8/21/16.
//
//

#include "game.h"
using namespace std;

Game::Game(vector<cell> cells){
    //iterate through the list of cells, adding each one into living
    generation = 0;
    paused = true;
    for(cell c : cells){
        living[c] = 1;
    }
}

void Game::update(){
    //Living will be set to new map nextGen
    //Iterate through the living cells
    //  check number of neighbors - if within constraints add to nextGen
    //      At each stage, add each of these neighbors into the the map of neighbors and increment the count
    //      if found
    //Iterate through the neighbors map to add to nextGen every dead cell that has count 3// can do this during last step probably. add it to nextgen if it hits 3, remove if it hits 4
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
    //set living to be the next generation
    living = nextGen;
    return;
}

int Game::countNeighbors(long long x, long long y){
    //check each of 8 positions around x,y
    //add these to the neighbors map and do the count/adding to
    
    //should deal with wrapping around or bounding the board
    int numAlive = 0;
    for(int d = 0; d <8; d++){
        cell c = make_pair(x+dx[d],y+dy[d]);
        if(living.count(c) > 0){
            numAlive++;
        }
        //Only adding dead cells to the neighbors list. Alive cells will be taken care of in the iteration of update using countNeighbors
        else{
            deadNeighbors[c]+=1;
        }
    }
    return numAlive;
}

void Game::printFull(){
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