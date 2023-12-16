#include "../include/Grid.hpp"
sf::Vector2f Grid::getPosition(int x, int y){
    if(x >= grid[0].size() || x < 0 || y >= grid.size() || y < 0){
            std::cerr << "Grid::getPosition: Grid position out of range"<< " " << grid[0].size() << std::endl;
            return sf::Vector2f(-1,-1);
    }
    else{
        return grid[y][x]; 
    }
}
sf::Vector2f Grid::getPosition(sf::Vector2<int> position){
    if(position.x >= grid[0].size() || position.x < 0 || position.y >= grid[0].size() || position.y < 0){
            std::cerr << "Grid::getPosition: Grid position out of range"<< " " << grid[0].size() << std::endl;
            return sf::Vector2f(-1,-1);
    }
    else{
        return grid[position.y][position.x]; 
    }
}
Grid& Grid::get(){
    return(gameGrid);
}
