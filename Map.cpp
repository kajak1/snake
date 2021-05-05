#include "headers/Map.h"

Map::Map(GameMode mode) {
  this->mode = mode;
  for(int row = 0; row < height; row++){
    for(int column = 0; column < width; column++){
      board[row][column].hasFruit = false;
      board[row][column].hasObstacle = false;
    }
  }
}
