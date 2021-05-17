#ifndef SNAKE_STARTMENU_H
#define SNAKE_STARTMENU_H

#include <SFML/Graphics.hpp>
#include "MainMenu.h"

class StartMenu : public MainMenu {
  sf::Text gameTitleTxt;

  public:
    StartMenu();
    sf::Text getGameTitleTxt() const;
};

#endif //SNAKE_STARTMENU_H
