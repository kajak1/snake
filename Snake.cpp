#include <iostream>
#include "headers/Snake.h"

Snake::Snake() {
  for(int i = 0; i < length; i++){
    sf::RectangleShape newPart(sf::Vector2f(width, height));
    newPart.setPosition(posX-(i * width), posY);
    parts.push_back(newPart);
  }
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
  sf::Vector2f pos = parts[0].getPosition();

  for(int i = length - 1; i > 0; i--) {
    sf::Vector2f prevPos = parts[i - 1].getPosition();
    parts[i].setPosition(prevPos.x, prevPos.y);
  }

  int futurePosX = pos.x + (speed * dirX[indX]);
  int futurePosY = pos.y + (speed * dirY[indY]);

  parts[0].setPosition(futurePosX, futurePosY);
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

void Snake::incLength() {
  length++;
  sf::RectangleShape newPart(sf::Vector2f(width, height));
  sf::Vector2f lastPartPos = parts[length-2].getPosition(); // -2 because length-1 is the new created empty part
  newPart.setFillColor(sf::Color::Green);
  newPart.setPosition(lastPartPos.x, lastPartPos.y);
  parts.push_back(newPart);
}

sf::Vector2f Snake::getPartPos(int part) const {
  return parts[part].getPosition();
}

std::vector<sf::RectangleShape> Snake::getParts() {
  return parts;
}

void Snake::resetState() {
  length = 3;
  posX = 200.f;
  posY = 220.f;
  indX = 3;
  indY = 2;

  parts.clear();

  for(int i = 0; i < length; i++){
    sf::RectangleShape newPart(sf::Vector2f(width, height));
    newPart.setPosition(posX-(i * width), posY);
    parts.push_back(newPart);
  }
}

