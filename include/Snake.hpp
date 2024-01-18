#ifndef SNAKE 
#define SNAKE
#include "SnakeSegment.hpp"
#include "SFML/System/Vector2.hpp"
#include "Grid.hpp"
#include "Directions.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
extern Grid& gameGrid;
extern sf::RenderWindow window;
extern bool gameOver;

class Snake{
private:
    SnakeSegment* head = new SnakeSegment; 
    SnakeSegment* tail = head;
    Directions direction = Directions::UP;
public:
    int length = 0;
    void grow();
    void update();
    void changeDirection(Directions newDirection);
    void draw();
    void changeColor(sf::Color color);
    Snake(int x, int y){
        head->setPosition(sf::Vector2<int>(x,y));
        head->prev = nullptr;
        head->next = nullptr;
    }
    ~Snake(){
        SnakeSegment* current = head->next;
        while(current != nullptr){
            delete current->prev;
            current = current->next; 
        }
        delete tail;
    }
    
};
#endif //SNAKE 
