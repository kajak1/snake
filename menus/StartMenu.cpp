#include <iostream>
#include "../headers/menus/StartMenu.h"
#include "../headers/utils/constants.h"

StartMenu::StartMenu() :
  easyBtnPos(180.f, 290.f),
  normalBtnPos(340.f, 290.f),
  hardBtnPos(500.f, 290.f) {
  setupTxt(gameTitleTxt, "SNAKE", textColor, 80, sf::Vector2f(840.f/2, 150.f));

  easyBtn.setPosition(easyBtnPos);
  normalBtn.setPosition(normalBtnPos);
  hardBtn.setPosition(hardBtnPos);

  easyBtn.setSize(sf::Vector2f(startBtnWidth, startBtnHeight));
  normalBtn.setSize(sf::Vector2f(startBtnWidth, startBtnHeight));
  hardBtn.setSize(sf::Vector2f(startBtnWidth, startBtnHeight));

  easyBtn.setFillColor(btnColor);
  normalBtn.setFillColor(btnColor);
  hardBtn.setFillColor(btnColor);

  setupTxt(easyBtnTxt, "EASY", textColor, 32, sf::Vector2f( (840/2) - startBtnWidth - 10.f, 290.f + startBtnHeight/2));
  setupTxt(normalBtnTxt, "NORMAL", textColor, 32, sf::Vector2f( (840/2), 290.f + startBtnHeight/2));
  setupTxt(hardBtnTxt, "HARD", textColor, 32, sf::Vector2f( (840/2) + startBtnWidth + 10.f, 290.f + startBtnHeight/2));

  highcoresBtn.setPosition(sf::Vector2f((840 - btnWidth)/2, 410));
}

sf::Text StartMenu::getGameTitleTxt() const {
  return gameTitleTxt;
}

sf::RectangleShape StartMenu::getEasyBtn() const {
  return easyBtn;
}

sf::RectangleShape StartMenu::getNormalBtn() const {
  return normalBtn;
}

sf::RectangleShape StartMenu::getHardBtn() const {
  return hardBtn;
}

sf::Text StartMenu::getEasyBtnTxt() const {
  return easyBtnTxt;
}

sf::Text StartMenu::getNormalBtnTxt() const {
  return normalBtnTxt;
}

sf::Text StartMenu::getHardBtnTxt() const {
  return hardBtnTxt;
}

sf::RectangleShape StartMenu::getHighscoresBtn() const {
  return highcoresBtn;
}

