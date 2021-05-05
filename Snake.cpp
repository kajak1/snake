#include <iostream>
#include "headers/Snake.h"

Snake::Snake(bool debug) {
  if(debug){
    for(int i = 0; i < length; i++){
      sf::RectangleShape newPart(sf::Vector2f(width, height));
      newPart.setPosition(posX-(i * width), posY);
      parts.push_back(newPart);
    }
    return;
  }

  sf::RectangleShape newPart(sf::Vector2f(width, height));
  newPart.setPosition(posX, posY);
  parts.push_back(newPart);
}

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

void Snake::move() {
  for(int i = 0; i < length; i++){
    sf::Vector2f pos = parts[i].getPosition();
    parts[i].setPosition(pos.x + (speed * dirX[indX]), pos.y + (speed * dirY[indY]));
  }
  std::cout << dirX[indX] << " " << dirY[indY] << '\n';
//  posX += speed;
}

void Snake::update() {
  move();
//  moveY();
  // move snake
  // check whether he ate something
}

int Snake::getLength() const {
  return length;
}

void Snake::turn(Turn direction) {
  switch (direction) {
    case LEFT:
      if(indX > 0){
        indX -= 1;
      } else {
        indX = 3;
      }

      if(indY < 3){
        indY += 1;
      } else {
        indY = 0;
      }
      break;
    case RIGHT:
      if(indX < 3){
        indX += 1;
      } else {
        indX = 0;
      }

      if(indY > 0){
        indY -= 1;
      } else {
        indY = 3;
      }
      break;
  }
}

int Snake::getDirX() const {
  return dirX[indX];
}

int Snake::getDirY() const {
  return dirY[indY];
}
