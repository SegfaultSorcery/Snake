#ifndef GRID 
#define GRID
#include "SFML/System/Vector2.hpp"
#include <iostream>

constexpr int aspectRatioX = 16; 
constexpr int aspectRatioY = 9;
extern const int windowSizeX;
extern const int windowSizeY;

class Grid{
private:
    //delete copy constructor
    Grid(const Grid&) = delete;
    sf::Vector2f grid[aspectRatioY + 1][aspectRatioX + 1];
    Grid(){
        float tempX;
        float tempY; 
        for(int i = 0; i <= aspectRatioY; i++){
            for(int j = 0; j <= aspectRatioX; j++){
                tempX = (float)windowSizeX/(float)aspectRatioX*(float)j;
                tempY = (float)windowSizeY/(float)aspectRatioY*(float)i;
                std::cout << tempX << " " << tempY << std::endl;
                grid[i][j] = sf::Vector2f(tempX, tempY);
            }
        }
    }

public:
    static Grid gameGrid;
    static Grid& get();
    sf::Vector2f getPosition(int x, int y);
};

#endif // GRID 
