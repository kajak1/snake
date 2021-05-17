#ifndef SNAKE_MENU_H
#define SNAKE_MENU_H

#include <SFML/Graphics.hpp>

class Menu {
  protected:
    sf::Font font;

  public:
    Menu();
    void setupFont();
    void setupTxt(sf::Text &entity, std::string text, int fontSize, int posY);
};

#endif //SNAKE_MENU_H
