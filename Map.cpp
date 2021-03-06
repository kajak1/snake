#include "headers/Map.h"
#include <iostream>

Map::Map(Snake &snake) : snake(snake){
  createBoard(NORMAL);
}

void Map::createBoard(GameMode mode) {
  this->mode = mode;
  // 0 to 19
  for(int row = 0; row < height; row++){
    // 0 to 31
    for(int column = 0; column < width; column++){
      board[row][column].hasSnake = false;
      board[row][column].hasFruit = false;
      board[row][column].hasObstacle = false;
    }
  }

  for(int i = 0; i < snake.getLength(); i++){
    int x = snake.getPartPos(i).x - offsetX;
    int y = snake.getPartPos(i).y - offsetY;
    int row = y/snake.getWidth();
    int column = x/snake.getHeight();

    if(isValid(row, column)){
      board[row][column].hasSnake = true;
    }
  }

  int foodPlaced = 0;
  while(foodPlaced < foodCount){
    createFood();
    foodPlaced++;
  }

  obstaclesPos.clear();
  if (this->mode == HARD) {
    int obstaclePlaced = 0;
    while(obstaclePlaced < obstacleCount){
      createObstalces();
      obstaclePlaced++;
    }
  }
}

int Map::getWidth() const {
  return width;
}

int Map::getHeight() const {
  return height;
}

void Map::updateSnakePos() {
  //clear its old position on board
  for(int row = 0; row < height; row++){
    for(int column = 0; column < width; column++){
      if(board[row][column].hasSnake){
        board[row][column].hasSnake = false;
      }
    }
  }

  // create new one
  for(int i = 0; i < snake.getLength(); i++){
    int x = snake.getPartPos(i).x - offsetX;
    int y = snake.getPartPos(i).y - offsetY;
    int row = y/snake.getWidth();
    int column = x/snake.getHeight();

    if(isValid(row, column)){
      board[row][column].hasSnake = true;
    }
  }
}

void Map::createFood() {
  int randRow = rand() % height;
  int randColumn = rand() % width;

  if(!board[randRow][randColumn].hasFruit
    && !board[randRow][randColumn].hasSnake
    && !board[randRow][randColumn].hasObstacle){
    board[randRow][randColumn].hasFruit = true;
    foodPos.row = randRow;
    foodPos.column = randColumn;
  } else {
    createFood();
  }
}

void Map::clearFood() {
  int row = foodPos.row;
  int column = foodPos.column;
  board[row][column].hasFruit = false;
}

bool Map::hasFood(int row, int column) const {
  if(board[row][column].hasFruit){
    return true;
  }
  return false;
}

bool Map::checkFoodEat() {
  int x = snake.getPartPos(0).x - offsetX;
  int y = snake.getPartPos(0).y - offsetY;
  int row = y/snake.getWidth();
  int column = x/snake.getHeight();
  if(row == foodPos.row && column == foodPos.column){
    snake.incLength();
    clearFood();
    createFood();
    return true;
  }
  return false;
}

bool Map::isSnakeOutside() const {
  int x = snake.getPartPos(0).x - offsetX;
  int y = snake.getPartPos(0).y - offsetY;

  int mapWidth = width * 20.f;
  int mapHeight = height * 20.f;

  if(x > mapWidth - 20.f || x < 0 || y > mapHeight - 20.f || y < 0){
    return true;
  }
  return false;
}

int Map::getOffsetX() const {
  return offsetX;
}

int Map::getOffsetY() const {
  return offsetY;
}

bool Map::snakeSelfCollide() const {
  int headX = snake.getPartPos(0).x - offsetX;
  int headY = snake.getPartPos(0).y - offsetY;

  for(int i = 1; i < snake.getLength(); i++){
    int x = snake.getPartPos(i).x - offsetX;
    int y = snake.getPartPos(i).y - offsetY;

    if(headX == x && headY == y){
      return true;
    }
  }
  return false;
}

bool Map::isValid(int row, int column) const {
  if(row > height-1 || row < 0 || column < 0 || column > width-1){
    return false;
  }
  return true;
}

void Map::createObstalces() {
  int randRow = rand() % height;
  int randColumn = rand() % width;

  if(!board[randRow][randColumn].hasObstacle
     && !board[randRow][randColumn].hasSnake
     && !board[randRow][randColumn].hasFruit
     && isObstacleAllowed(randRow, randColumn)) {
      board[randRow][randColumn].hasObstacle = true;
      ObstaclePos pos {
        .row = randRow,
        .column = randColumn
      };
      obstaclesPos.push_back(pos);
    } else {
    createObstalces();
  }
}

bool Map::isObstacleAllowed(int row, int column) const {
  int x = snake.getPartPos(0).x - offsetX;
  int y = snake.getPartPos(0).y - offsetY;
  int snakeRow = y/snake.getWidth();
  int snakeColumn = x/snake.getHeight();
  if ((row < snakeRow || row > snakeRow) && (column < snakeColumn-2 || column > snakeColumn+3)) {
    return true;
  }
  return false;
}

bool Map::snakeObstacleCollide() const {
  int x = snake.getPartPos(0).x - offsetX;
  int y = snake.getPartPos(0).y - offsetY;
  int row = y/snake.getWidth();
  int column = x/snake.getHeight();
  for (ObstaclePos obstacle: obstaclesPos) {
    if (row == obstacle.row && column == obstacle.column) {
      return true;
    }
  }
  return false;
}

bool Map::hasObstacle(int row, int column) const {
  if(board[row][column].hasObstacle){
    return true;
  }
  return false;
}

