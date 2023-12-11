#ifndef SNAKE_SEGMENT
#define SNAKE_SEGMENT
#include "Grid.hpp"
#include "SFML/Graphics.hpp"
#include <SFML/Graphics/CircleShape.hpp>

extern float SnakeSegmentRadius;

class SnakeSegment{
private:
    sf::Vector2f position;
    sf::CircleShape segment;
public:
    SnakeSegment* link;
    SnakeSegment(sf::Vector2<int> Position) : position(gameGrid.getPosition(Position)){
        segment.setFillColor(sf::Color::Green);
        segment.setRadius(SnakeSegmentRadius);
        segment.setOrigin(sf::Vector2f(SnakeSegmentRadius/2,SnakeSegmentRadius/2));
        link = new SnakeSegment(sf::Vector2<int>(0,0));
    }
    void setPosition(sf::Vector2<int> newPosition);
};
#endif //SNAKE_SEGMENT
