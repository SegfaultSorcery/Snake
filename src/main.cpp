#include <random>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp> 
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "../include/variables.hpp"
#include "../include/Grid.hpp" 
#include "../include/Apple.hpp"
#include "../include/SnakeSegment.hpp"
#include "../include/Snake.hpp"
const sf::Vector2<int> windowSize(1920,1080);
Grid Grid::gameGrid;
Grid& gameGrid = Grid::get();
Apple apple;
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
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type){
                case sf::Event::Closed: 
                    window.close();
                    break;
                // User Controls
                case sf::Event::KeyPressed:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
                        snake.changeDirection(Directions::UP);
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
                        snake.changeDirection(Directions::LEFT);
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
                        snake.changeDirection(Directions::DOWN);
                    }
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
                        snake.changeDirection(Directions::RIGHT);
                    }
                    break;
            }
        }
        // Player Controls
        if(!gameOver){
            window.clear(); 
            apple.spawn();
            snake.update(); 
            segment1.setPosition(sf::Vector2<int>(31,31));
            segment2.setPosition(sf::Vector2<int>(30,30));
            window.display();
            sf::sleep(sf::seconds(0.3));
        }
        else{
            std::cout << "Game Over" << std::endl;
            window.clear();
            snake.changeColor(sf::Color::Blue);
            snake.draw();
            window.display();

            break;
        }
    }
    std::cin.get();
}

