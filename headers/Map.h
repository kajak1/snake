#ifndef SNAKE_MAP_H
#define SNAKE_MAP_H

#include "Snake.h"
#include "utils/constants.h"

struct Field {
  bool hasFruit;
  bool hasObstacle;
  bool hasSnake;
};

struct FoodPos {
  int row;
  int column;
};

struct ObstaclePos {
  int row = -1;
  int column = -1;
};

class Map {
  Snake &snake;
  Field board[20][32];
  const int width = 32;
  const int height = 20;
  int foodCount = 1;
  int obstacleCount = 30;
  const int offsetX = 100.f;
  const int offsetY = 120.f;

  GameMode mode;

  FoodPos foodPos;
  std::vector<ObstaclePos> obstaclesPos;

  public:
    Map(Snake &snake);

    void createBoard(GameMode mode);

    int getWidth() const;
    int getHeight() const;
    int getOffsetX() const;
    int getOffsetY() const;

    bool isValid(int row, int column) const;

    void createFood();
    void clearFood();
    bool hasFood(int row, int column) const;
    bool checkFoodEat();

    void createObstalces();
    bool snakeObstacleCollide() const;
    bool hasObstacle(int row, int column) const;
    bool isObstacleAllowed(int row, int column) const;

    void updateSnakePos();
    bool isSnakeOutside() const;
    bool snakeSelfCollide() const;
};

#endif //SNAKE_MAP_H
