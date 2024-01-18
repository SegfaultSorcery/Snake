#ifndef SNAKE_SEGMENT
#define SNAKE_SEGMENT
#include "Grid.hpp"
#include <SFML/Graphics/CircleShape.hpp>

extern float SnakeSegmentRadius;
extern Grid& gameGrid;
extern float SnakeSegmentRadius;

class SnakeSegment{
private:
    sf::Vector2<int> position;
    sf::CircleShape sprite;
public:
    SnakeSegment* prev = nullptr;
    SnakeSegment* next = nullptr;
    sf::Vector2<int> getPosition();
    sf::CircleShape getSprite();
    void setPosition(sf::Vector2<int> newPosition);
    void setColor(sf::Color color); 
    SnakeSegment(){
        sprite.setFillColor(sf::Color::Green);
        sprite.setRadius(SnakeSegmentRadius);
        sprite.setOrigin(sf::Vector2f(SnakeSegmentRadius/2,SnakeSegmentRadius/2));
        sprite.setPosition(sf::Vector2f(0,0));
    }
    SnakeSegment(sf::Vector2<int> Position) : position(Position){
        sprite.setFillColor(sf::Color::Green);
        sprite.setRadius(SnakeSegmentRadius);
        sprite.setOrigin(sf::Vector2f(SnakeSegmentRadius/2,SnakeSegmentRadius/2));
        sprite.setPosition(gameGrid.getPosition(position));
    }

    ~SnakeSegment(){
        delete prev; 
    }
};
#endif //SNAKE_SEGMENT
