#ifndef SNAKE_STARTMENU_H
#define SNAKE_STARTMENU_H

#include <SFML/Graphics.hpp>
#include "Menu.h"

class StartMenu: Menu {
  sf::Text gameTitleTxt;

  const int startBtnWidth = 150.f;
  const int startBtnHeight = 80.f;

  sf::RectangleShape highcoresBtn;

  sf::RectangleShape easyBtn;
  sf::RectangleShape normalBtn;
  sf::RectangleShape hardBtn;

  sf::Text easyBtnTxt;
  sf::Text normalBtnTxt;
  sf::Text hardBtnTxt;

  sf::Vector2f easyBtnPos;
  sf::Vector2f normalBtnPos;
  sf::Vector2f hardBtnPos;

  public:
    StartMenu();
    sf::Text getGameTitleTxt() const;
    sf::RectangleShape getEasyBtn() const;
    sf::RectangleShape getNormalBtn() const;
    sf::RectangleShape getHardBtn() const;

    sf::Text getEasyBtnTxt() const;
    sf::Text getNormalBtnTxt() const;
    sf::Text getHardBtnTxt() const;

    sf::RectangleShape getHighscoresBtn() const;
};

#endif //SNAKE_STARTMENU_H
