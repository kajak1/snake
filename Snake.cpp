#include "headers/Snake.h"

Snake::Snake() {}

int Snake::getWidth() const {
  return width;
}
int Snake::getHeight() const {
  return height;
}

int Snake::getPosX() const {
  return posX;
}

int Snake::getPosY() const {
  return posY;
}

void Snake::moveX() {
  posX += speed;
}

void Snake::moveY() {
  posY += speed;
}

void Snake::update() {
  moveX();
  moveY();
  // move snake
  // check whether he ate something
}

