#ifndef VARIABLES
#define VARIABLES
class Grid;
class Snake;
class Apple;

const int windowSizeX = 1920; const int windowSizeY = 1080;
// inline constexpr int aspectRatioX = 16; 
// inline constexpr int aspectRatioY = 9;

float SnakeSegmentRadius = 10;
float appleRadius = 5;

enum directions {
   UP,LEFT,DOWN,RIGHT 
};
#endif // VARIABLES
