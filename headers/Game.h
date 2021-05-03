#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <SFML/Graphics.hpp>
#include "Snake.h"

class Game{
  Snake &snake;
  sf::RenderWindow &window;
  public:
    Game(Snake &snake, sf::RenderWindow &window);
    void debug_display() const;
};

#endif
