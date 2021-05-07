#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "View.h"

class Game{
  Snake &snake;
  Map &map;
  View &view;
  sf::RenderWindow &window;
  public:
    Game(Snake &snake, Map &map, View &view, sf::RenderWindow &window);
    void debug_display() const;
    void run();
};

#endif
