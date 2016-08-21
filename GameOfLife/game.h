//
//  game.h
//  
//


#ifndef ____game__
#define ____game__

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <boost/functional/hash.hpp>

using namespace std;

typedef pair<long long, long long> cell;
typedef unordered_map<cell, int, boost::hash<pair<long long, long long>>> cell_map;

const int dx[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
const int dy[] = { 0, 0, 1, -1, 1, -1, -1, 1 };

class Game {
public:
    Game(vector<cell> cells);
    void update();
    void print();
    void printVerbose();
    int generation;
    cell_map living;
    bool paused;
    void pause();
    
private:
    cell_map deadNeighbors;
    int countNeighbors(long long x, long long y);
    
};

#endif /* defined(____game__) */
