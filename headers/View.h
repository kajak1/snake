#ifndef SNAKE_VIEW_H
#define SNAKE_VIEW_H

#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Game.h"

class View{
  Snake &snake;
  Game &game;
  sf::RenderWindow &window;

  public:
    View(Snake &snake, Game &game, sf::RenderWindow &window);
    void drawSnake();
    void drawMap();
};

#endif //SNAKE_VIEW_H
