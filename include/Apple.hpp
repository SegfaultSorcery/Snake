#ifndef APPLE 
#define APPLE 
#include <random>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Grid.hpp"
extern float appleRadius;
extern Grid& gameGrid;
extern sf::RenderWindow window;
class Apple{
private:
    sf::Vector2<int> position;
    void draw();
public:
    void spawn();
    sf::CircleShape sprite;
    void setPosition(sf::Vector2<int> newPosition);

    Apple(){
        sprite.setFillColor(sf::Color::Red);
        sprite.setRadius(appleRadius);
        sprite.setOrigin(sf::Vector2f(appleRadius/2,appleRadius/2));
    }
    Apple(int X, int Y){
        sprite.setFillColor(sf::Color::Red);
        sprite.setRadius(appleRadius);
        sprite.setOrigin(sf::Vector2f(appleRadius/2,appleRadius/2));
        sprite.setPosition(gameGrid.getPosition(X, Y));
    }
};
#endif //APPLE
