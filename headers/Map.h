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
  Field board[20][32];
  int width = 32;
  int height = 20;
  int foodCount = 1;
  int offsetX = 100.f;
  int offsetY = 120.f;

  FoodPos foodPos;
  GameMode mode;
  GameState gameState;
  public:
    Map(GameMode mode, Snake &snake);
    int getWidth() const;
    int getHeight() const;
    int getOffsetX() const;
    int getOffsetY() const;

    bool isValid(int row, int column) const;

    void createFood();
    void clearFood();
    bool hasFood(int row, int column) const;
    void checkFoodEat();

    void updateSnakePos();
    bool isSnakeOutside() const;
    bool snakeSelfCollide() const;
};

#endif //SNAKE_MAP_H
