#include "../include/Apple.hpp"
#include <random>
void Apple::setPosition(sf::Vector2<int> newPosition){
    position = newPosition;
    sprite.setPosition(gameGrid.getPosition(newPosition));
}
void Apple::draw(){
    window.draw(sprite);
}
void Apple::spawn(){
    std::random_device rd;    
    std::mt19937 gen(rd());
    std::uniform_int_distribution distributionX(0,gridColumns - 1);
    std::uniform_int_distribution distributionY(0,gridRows -1 );
    this->setPosition(sf::Vector2<int>(distributionX(gen), distributionY(gen)));
    this->draw();
}
