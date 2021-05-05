#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include <vector>
#include <SFML/Graphics.hpp>

enum Turn { LEFT, RIGHT };

class Snake{
  int length = 300;

  int width = 20.f;
  int height = 20.f;
  int posX = 100.f;
  int posY = 100.f;
  int speed = 5;

  int dirX[4] = {-1, 0, 1, 0};
  int dirY[4] = {-1, 0, 1, 0};
  int indX = 3;
  int indY = 2;

  void move();

  void turnLeft();
  void turnRight();
  public:
    std::vector<sf::RectangleShape> parts;
    Snake(bool debug);
    int getLength() const;
    int getWidth() const;
    int getHeight() const;
    int getPosX() const;
    int getPosY() const;
    int getDirX() const;
    int getDirY() const;

    void update();

    void turn(Turn direction);
};

#endif //SNAKE_SNAKE_H
