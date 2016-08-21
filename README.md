# Conway's Game of Life
Conway's game of life in C++

    Any live cell with fewer than two live neighbours dies.
    Any live cell with two or three live neighbours lives on to the next generation.
    Any live cell with more than three live neighbours dies.
    Any dead cell with exactly three live neighbours becomes a live cell.

Supports cells at integer coordinates anywhere in the signed 64 bit integer range with wrap around.

Implemented using a map of living cells instead of keeping track of the full state of the entire board.
Each new generation only considers these cells and their neighbors.

Visualization done by SDL2.
The visualization only draws cells in the integer range from (0-800, 0-600), but cells outside that range are still running. 

## Installation

Compile with C++ 11 using an IDE like xcode or g++ with the proper compile flags

## Usage
Load an initial state for the game with a text file of living cells' x,y coordinates.
input1.txt is an example.
Press space to pause the game of life.

##Dependencies
Boost 

SDL2.0

