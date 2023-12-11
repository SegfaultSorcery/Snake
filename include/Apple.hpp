#ifndef APPLE 
#define APPLE 
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include "Grid.hpp"
extern float appleRadius;
extern Grid& gameGrid;
class Apple{
private:
    sf::Vector2<int> position;
public:
    sf::CircleShape sprite;
    void setPosition(sf::Vector2<int> newPosition);

    Apple(int X, int Y){
        sprite.setFillColor(sf::Color::Red);
        sprite.setRadius(appleRadius);
        sprite.setOrigin(sf::Vector2f(appleRadius/2,appleRadius/2));
        sprite.setPosition(gameGrid.getPosition(X, Y));
    }
};
#endif //APPLE
