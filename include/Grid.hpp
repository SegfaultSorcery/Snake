#ifndef GRID 
#define GRID
#include "SFML/System/Vector2.hpp"
#include "iostream"
#include <vector>

extern const int windowSizeX;
extern const int windowSizeY;
extern const int gridColumns;
extern const int gridRows; 

class Grid{
private:
    //delete copy constructor
    Grid(const Grid&) = delete;
    std::vector<std::vector<sf::Vector2f>> grid;
    Grid(){
        grid.reserve(gridRows+1);
        for(int i = 0; i <= gridRows; i++ ){
            for(int j = 0; j <= gridColumns; j++){
                grid[i].push_back(sf::Vector2f(j*20, i*20)); 
            }
        }
    }
public:
    static Grid gameGrid;
    static Grid& get();
    sf::Vector2f getPosition(int x, int y);
    sf::Vector2f getPosition(sf::Vector2<int> position);
};

#endif // GRID 
