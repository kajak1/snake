#include "../headers/menus/Menu.h"
#include <iostream>

Menu::Menu() {
  setupFont();
}

void Menu::setupFont() {
  if (!font.loadFromFile("RobotoMono-Regular.ttf")) {
    std::cout << "ERROR!\n";
  }
}

void Menu::setupTxt(sf::Text &entity, std::string text, sf::Color txtColor, int fontSize, sf::Vector2f pos) {
  entity.setFont(font);
  entity.setString(text);
  entity.setCharacterSize(fontSize);
  entity.setFillColor(txtColor);

  sf::FloatRect textRect = entity.getLocalBounds();
  entity.setOrigin(textRect.left + textRect.width/2.0f,textRect.top  + textRect.height/2.0f);
  entity.setPosition(pos);
}