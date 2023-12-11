#ifndef SNAKE 
#define SNAKE
#include "SnakeSegment.hpp"
#include "SFML/System/Vector2.hpp"
#include "variables.hpp"
#include "Grid.hpp"
class Snake{
private:
    SnakeSegment* head = nullptr;
    SnakeSegment* tail = nullptr;
 
public:
    void grow(){
        SnakeSegment* newTail = new SnakeSegment; 
        newTail->link = tail; 
        tail = newTail;
    }
    Snake(int x, int y){
        head->setPosition(gameGrid.getPosition(x,y));
    }
};
#endif //SNAKE 
