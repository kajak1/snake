#include "../headers/menus/StartMenu.h"

StartMenu::StartMenu() {
  setupTxt(gameTitleTxt, "SNAKE", 50, 150);
  startGameBtn.setPosition(sf::Vector2f((840 - btnWidth)/2, 290));
  highcoresBtn.setPosition(sf::Vector2f((840 - btnWidth)/2, 410));
}

sf::Text StartMenu::getGameTitleTxt() const {
  return gameTitleTxt;
}

