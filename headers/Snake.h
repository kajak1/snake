#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

class Snake{
  int width = 50.f;
  int height = 50.f;
  int posX = 10.f;
  int posY = 10.f;
  int dirX = 1;
  int dirY = 1;
  int speed = 1;

  void moveX();
  void moveY();

  public:
    Snake();
    int getWidth() const;
    int getHeight() const;
    int getPosX() const;
    int getPosY() const;
    void update();
    void turn();
};

#endif //SNAKE_SNAKE_H
