#include "../include/Snake.hpp"
void Snake::grow(){
    sf::Vector2<int> newPosition; 
    sf::Vector2<int> prevPosition = tail->getPosition();
    switch (direction){
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
            newPosition.y = prevPosition.x - 1;
            break; 

        case Directions::LEFT:
            newPosition.x = prevPosition.x + 1;
            newPosition.y = prevPosition.y;
            break; 
    }
    head->setPosition(newPosition);
    SnakeSegment* current = tail; 
       while(current->prev != nullptr){
           current->setPosition(current->prev->getPosition());
           current = current->prev;
        } 
} 
void Snake::changeDirection(Directions newDirection){
   direction = newDirection; 
}
void Snake::draw(){
    SnakeSegment* current = head;
    while(current != nullptr){
        window.draw(current->getSprite());
        current = current->next;
    }
}
