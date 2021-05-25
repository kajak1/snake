#ifndef SNAKE_MENU_H
#define SNAKE_MENU_H

#include <SFML/Graphics.hpp>

class Menu {
  protected:
    sf::Font font;

  public:
    Menu();
    void setupFont();
    void setupTxt(sf::Text &entity, std::string text, sf::Color txtColor, int fontSize, sf::Vector2f pos);
};

#endif //SNAKE_MENU_H
