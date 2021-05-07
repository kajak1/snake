#include "headers/Map.h"
#include <iostream>

Map::Map(GameMode mode, Snake &snake) : snake(snake){
  this->mode = mode;
  for(int row = 0; row < height; row++){
    for(int column = 0; column < width; column++){
      board[row][column].hasSnake = false;
      board[row][column].hasFruit = false;
      board[row][column].hasObstacle = false;
    }
  }

  std::vector<sf::RectangleShape> &parts = snake.getParts();
  for(int i = 0; i < snake.getLength(); i++){
    int x = parts[i].getPosition().x;
    int y = parts[i].getPosition().y;
    int row = x/snake.getWidth();
    int column = y/snake.getHeight();

    board[row][column].hasSnake = true;
  }

  int foodPlaced = 0;
  while(foodPlaced < foodCount){
    createFood();
    foodPlaced++;
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
  std::vector<sf::RectangleShape> &parts = snake.getParts();
  for(int i = 0; i < snake.getLength(); i++){
    int x = parts[i].getPosition().x;
    int y = parts[i].getPosition().y;
    int row = x/snake.getWidth();
    int column = y/snake.getHeight();

    board[row][column].hasSnake = true;
  }
}

void Map::createFood() {
  int randomRow = rand() % height;
  int randomColumn = rand() % width;

  if(!board[randomRow][randomColumn].hasFruit
    && !board[randomRow][randomColumn].hasSnake){
    board[randomRow][randomColumn].hasFruit = true;
    foodPos.row = randomRow;
    foodPos.column = randomColumn;
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

void Map::checkFoodEat() {
  std::vector<sf::RectangleShape> &parts = snake.getParts();
  int x = parts[0].getPosition().x;
  int y = parts[0].getPosition().y;
  int row = x/snake.getWidth();
  int column = y/snake.getHeight();
  if(row == foodPos.row && column == foodPos.column){
    snake.incLength();
    clearFood();
    createFood();
  }
}