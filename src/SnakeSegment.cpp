#include "../include/SnakeSegment.hpp"
#include <SFML/Graphics/CircleShape.hpp>
void SnakeSegment::setPosition(sf::Vector2<int> newPosition){
    position = newPosition;
    sprite.setPosition(gameGrid.getPosition(position));
}
sf::Vector2<int> SnakeSegment::getPosition(){
    return position;
}

sf::CircleShape SnakeSegment::getSprite(){
    return sprite;
}
