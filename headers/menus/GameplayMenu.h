#ifndef SNAKE_GAMEPLAYMENU_H
#define SNAKE_GAMEPLAYMENU_H

#include "Menu.h"

class GameplayMenu : public Menu {
  sf::Text scoreTxt;

  public:
    GameplayMenu();
    sf::Text getScoreTxt() const;
    void updateScoreTxt(int score);
};

#endif //SNAKE_GAMEPLAYMENU_H
