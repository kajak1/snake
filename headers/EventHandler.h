#ifndef SNAKE_EVENTHANDLER_H
#define SNAKE_EVENTHANDLER_H

#include "Game.h"
#include "Snake.h"

class EventHandler{
  Game &game;
  Snake &snake;
  public:
    EventHandler(Game &game, Snake &snake);

};

#endif //SNAKE_EVENTHANDLER_H
