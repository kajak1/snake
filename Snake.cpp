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
  // working
//  for(int i = 0; i < length; i++){
//    sf::Vector2f pos = parts[i].getPosition();
//    parts[i].setPosition(pos.x + (speed * dirX[indX]), pos.y + (speed * dirY[indY]));
//  }

  // new
  sf::Vector2f pos = parts[0].getPosition();
  sf::Vector2f pos2;
  parts[0].setPosition(pos.x + (speed * dirX[indX]), pos.y + (speed * dirY[indY]));

  for(int i = 1; i < length - 1; i++){
    if(i % 2 == 0){
      pos = parts[i].getPosition();
      parts[i].setPosition(pos2.x, pos2.y);
      continue;
    }
    if(i % 2 == 1){
      pos2 = parts[i].getPosition();
      parts[i].setPosition(pos.x, pos.y);
      continue;
    }
  }
}

void Snake::update() {
  move();
  // check whether he ate something
}

int Snake::getLength() const {
  return length;
}

void Snake::turn(Turn direction) {
  switch (direction) {
    case LEFT:
      turnLeft();
      break;
    case RIGHT:
      turnRight();
      break;
  }
}

int Snake::getDirX() const {
  return dirX[indX];
}

int Snake::getDirY() const {
  return dirY[indY];
}

void Snake::turnRight() {
  // change X and Y index, to get proper directions
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
}

void Snake::turnLeft() {
  // change X and Y index, to get proper directions
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
}
