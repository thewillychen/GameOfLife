//
//  main.cpp
//  GameOfLife
//
//  Created by Willy Chen on 8/18/16.
//  Copyright (c) 2016 Willy Chen. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <boost/functional/hash.hpp>

using namespace std;

typedef pair<long long, long long> cell;
typedef unordered_map<cell, int, boost::hash<pair<long long, long long>>> cell_map;
static const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
static const int dy[] = { 0, 0, 1, -1, 1, -1, -1, 1 };

class Game {
public:
    Game(vector<cell> cells);
    void update();
    
private:
    cell_map living;
    cell_map neighbors;
    cell_map nextGen;
    int countNeighbors(long long x, long long y);
    
};

Game::Game(vector<cell> cells){
    //iterate through the list of cells, adding each one into living
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
        else if(neighbors.count(c) > 0){
            neighbors[c] = neighbors[c]+1;
        }
        else{
            neighbors[c] = 1;
        }
    }
    return numAlive;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Game of life\n";
    return 0;
}
