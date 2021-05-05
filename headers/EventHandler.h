#ifndef SNAKE_EVENTHANDLER_H
#define SNAKE_EVENTHANDLER_H

#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Snake.h"
#include "View.h"

class EventHandler{
  Snake &snake;
  Game &game;
  View &view;
  sf::RenderWindow &window;

  public:
    EventHandler(Snake &snake, Game &game, View &view, sf::RenderWindow &window);
    void listen(sf::Event &event);
    void handleBtnClick(sf::Event &event);
};

#endif //SNAKE_EVENTHANDLER_H
