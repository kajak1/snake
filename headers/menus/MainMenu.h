#ifndef SNAKE_MAINMENU_H
#define SNAKE_MAINMENU_H

#include <SFML/Graphics.hpp>
#include "Menu.h"

class MainMenu: public Menu {
  protected:
    const int btnWidth = 270.f;
    const int btnHeight = 100.f;
    sf::RectangleShape startGameBtn;
    sf::RectangleShape highcoresBtn;

  public:
    MainMenu();
    sf::RectangleShape getStartGameBtn() const;
    sf::RectangleShape getHighscoresBtn() const;
};
#endif //SNAKE_MAINMENU_H
