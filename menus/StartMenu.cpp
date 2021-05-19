#include "../headers/menus/StartMenu.h"

StartMenu::StartMenu() {
  setupTxt(gameTitleTxt, "SNAKE", 50, sf::Vector2f(840.f/2, 150.f));
  startGameBtn.setPosition(sf::Vector2f((840 - btnWidth)/2, 290));
  highcoresBtn.setPosition(sf::Vector2f((840 - btnWidth)/2, 410));
}

sf::Text StartMenu::getGameTitleTxt() const {
  return gameTitleTxt;
}

