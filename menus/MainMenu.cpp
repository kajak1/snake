#include "../headers/menus/MainMenu.h"

MainMenu::MainMenu() :
startGameBtn(sf::Vector2f(btnWidth, btnHeight)),
highcoresBtn(sf::Vector2f(btnWidth, btnHeight)) {}

sf::RectangleShape MainMenu::getStartGameBtn() const {
  return startGameBtn;
}

sf::RectangleShape MainMenu::getHighscoresBtn() const {
  return highcoresBtn;
}

