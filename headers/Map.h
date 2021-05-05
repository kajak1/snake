#ifndef SNAKE_MAP_H
#define SNAKE_MAP_H

enum GameMode  { EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

struct Field{
  bool hasFruit;
  bool hasObstacle;
};

class Map{
  Field board[50][50];
  int width = 50;
  int height = 50;
  GameMode mode;
  GameState gameState;
  public:
    Map(GameMode mode);
};

#endif //SNAKE_MAP_H
