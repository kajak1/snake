#ifndef SNAKE_MAP_H
#define SNAKE_MAP_H

#include "Snake.h"

enum GameMode  { EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

struct Field{
  bool hasFruit;
  bool hasObstacle;
  bool hasSnake;
};

struct FoodPos{
  int row;
  int column;
};

class Map{
  Snake &snake;
  Field board[32][24];
  int width = 24;
  int height = 32;
  int foodCount = 1;
  FoodPos foodPos;
  GameMode mode;
  GameState gameState;
  public:
    Map(GameMode mode, Snake &snake);
    int getWidth() const;
    int getHeight() const;
    void createFood();
    void clearFood();
    void updateSnakePos();
    bool hasFood(int row, int column) const;
    void checkFoodEat();
};

#endif //SNAKE_MAP_H
