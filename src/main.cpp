#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp> 
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../include/variables.hpp"
#include "../include/Grid.hpp" 
#include "../include/Apple.hpp"
#include "../include/SnakeSegment.hpp"
#include "../include/Snake.hpp"
const sf::Vector2<int> windowSize(1920,1080);
Grid Grid::gameGrid;
Grid& gameGrid = Grid::get();
bool gameOver = false;
// Apple apple(4,4);
SnakeSegment segment1;
SnakeSegment segment2;
Snake snake(20,20);
int i = 0; 
sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "SNAKE");

int main(){
    // Declare and create a new window
    window.setFramerateLimit(60);
    // initalize grid singleton
    snake.grow();
    snake.grow();
    snake.grow();
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
        snake.draw();
        // snake.grow();
        segment1.setPosition(sf::Vector2<int>(31,31));
        segment2.setPosition(sf::Vector2<int>(30,30));
        window.draw(segment1.getSprite());
        window.draw(segment2.getSprite());
        // snake.changeDirection(Directions::DOWN);
        // window.draw(apple.sprite);
        window.display();
        sf::sleep(sf::seconds(2));
        snake.update(); 
    }
}

