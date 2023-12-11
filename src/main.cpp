#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../include/variables.hpp"
#include "../include/Grid.hpp" 
#include "../include/Apple.hpp"

const sf::Vector2<int> windowSize(1920,1080);
Grid Grid::gameGrid;
Grid& gameGrid = Grid::get();
Apple apple(4,4);

int main(){
    
    // Declare and create a new window
    sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "SNAKE");
    window.setFramerateLimit(60);
    // initalize grid singleton

    while (window.isOpen())
    {
       // Event processing
        sf::Event event;
        while (window.pollEvent(event))
        {
           // Request for closing the window
           if (event.type == sf::Event::Closed)
               window.close();
        }
        window.clear(); 
        window.draw(apple.sprite);
        window.display();
    }

}

