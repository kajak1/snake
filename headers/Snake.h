#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include <SFML/Graphics.hpp>
#include <vector>

enum Turn { LEFT, RIGHT };

class Snake{
  int length = 3;

  bool didTurn = false;

  const int width = 20.f;
  const int height = 20.f;
  int posX = 200.f;
  int posY = 220.f;
  int speed = 20;

  const int dirX[4] = {-1, 0, 1, 0};
  const int dirY[4] = {-1, 0, 1, 0};
  int indX = 3;
  int indY = 2;

  void move();

  void turnLeft();
  void turnRight();
  std::vector<sf::RectangleShape> parts;
  public:
    Snake();
    std::vector<sf::RectangleShape> getParts();
    sf::Vector2f getPartPos(int part) const;

    void setDidTurn(bool didTurn);
    bool getDidTurn() const;

    int getLength() const;
    void incLength();

    int getWidth() const;
    int getHeight() const;
    int getDirX() const;
    int getDirY() const;

    void update(sf::Clock &clock);
    void resetState();

    void turn(Turn direction);
};

#endif //SNAKE_SNAKE_H
