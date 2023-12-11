#include "../include/SnakeSegment.hpp"
void SnakeSegment::setPosition(sf::Vector2<int> newPosition){
    position = gameGrid.getPosition(newPosition);
    segment.setPosition(position);
}
