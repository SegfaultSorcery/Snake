#include "../include/Grid.hpp"
#include <SFML/System/Vector2.hpp>
sf::Vector2f Grid::getPosition(int x, int y){
    if(x > aspectRatioX + 1|| x < 0 || y > aspectRatioY || y < 0){
            std::cerr << "Grid::getPosition: Grid position out of range" << std::endl;
            return sf::Vector2f(-1,-1);
    }
    else{
        return grid[y][x]; 
    }
}
Grid& Grid::get(){
    return(gameGrid);
}
