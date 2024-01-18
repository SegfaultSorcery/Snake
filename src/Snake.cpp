#include "../include/Snake.hpp"
void Snake::grow(){
    sf::Vector2<int> newPosition; 
    sf::Vector2<int> prevPosition = tail->getPosition();
    sf::Vector2<int> a;
    Directions tailDirection;
    if(tail->prev != nullptr){
        a = tail->prev->getPosition();
        
        if(prevPosition.x - a.x < 0){
            tailDirection = Directions::RIGHT;
        }
        else if(prevPosition.x - a.x > 0){
            tailDirection = Directions::LEFT;
        }
        else if(prevPosition.y - a.y > 0){
            tailDirection = Directions::DOWN;
        }
        else if(prevPosition.y - a.y < 0){
            tailDirection = Directions::UP;
        }
    }
    else{
        tailDirection = direction;
    }

    switch (tailDirection){
        case Directions::UP:
            newPosition.x = prevPosition.x;
            newPosition.y = prevPosition.y + 1;
            break;
            
        case Directions::RIGHT:
            newPosition.x = prevPosition.x - 1; 
            newPosition.y = prevPosition.y;
            break; 

        case Directions::DOWN:
            newPosition.x = prevPosition.x;
            newPosition.y = prevPosition.x - 1;
            break; 

        case Directions::LEFT:
            newPosition.x = prevPosition.x + 1;
            newPosition.y = prevPosition.y;
            break; 
    }
    SnakeSegment* newTail = new SnakeSegment(newPosition); 
    newTail->prev = tail;
    newTail->next = nullptr;
    tail->next = newTail;
    tail = newTail;
    length++;
}
void Snake::update(){
    sf::Vector2<int> newPosition;
    sf::Vector2<int> prevPosition = head->getPosition();
    switch (direction){
        case Directions::UP:
            newPosition.x = prevPosition.x;
            newPosition.y = prevPosition.y - 1;
            break;
            
        case Directions::RIGHT:
            newPosition.x = prevPosition.x + 1; 
            newPosition.y = prevPosition.y;
            break; 

        case Directions::DOWN:
            newPosition.x = prevPosition.x;
            newPosition.y = prevPosition.y + 1;
            break; 

        case Directions::LEFT:
            newPosition.x = prevPosition.x - 1;
            newPosition.y = prevPosition.y;
            break; 
    }
    SnakeSegment* current = tail; 
        while(current->prev != nullptr){
            if(newPosition == current->getPosition()){
                gameOver = true;
            }
            current->setPosition(current->prev->getPosition());
            current = current->prev;
        } 
    head->setPosition(newPosition);
    this->draw();

} 
void Snake::changeDirection(Directions newDirection){
    if(newDirection == Directions::UP && direction != Directions::DOWN
            || newDirection == Directions::RIGHT && direction != Directions::LEFT
            || newDirection == Directions::DOWN && direction != Directions::UP
            || newDirection == Directions::LEFT && direction != Directions::RIGHT
            ){
        direction = newDirection; 
    }
}
void Snake::draw(){
    SnakeSegment* current = head;
    while(current != nullptr){
        window.draw(current->getSprite());
        current = current->next;
    }
}
void Snake::changeColor(sf::Color color){
    SnakeSegment* current = head;
    while (current != nullptr){
        current->setColor(color);
        current = current->next;
    }
}
