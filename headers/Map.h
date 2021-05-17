#ifndef SNAKE_MAP_H
#define SNAKE_MAP_H

#include "Snake.h"

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
  Field board[20][32];
  const int width = 32;
  const int height = 20;
  int foodCount = 1;
  const int offsetX = 100.f;
  const int offsetY = 120.f;

  FoodPos foodPos;
  public:
    Map(Snake &snake);
    int getWidth() const;
    int getHeight() const;
    int getOffsetX() const;
    int getOffsetY() const;

    bool isValid(int row, int column) const;

    void createFood();
    void clearFood();
    bool hasFood(int row, int column) const;
    bool checkFoodEat();

    void updateSnakePos();
    bool isSnakeOutside() const;
    bool snakeSelfCollide() const;

    void resetState();
};

#endif //SNAKE_MAP_H
