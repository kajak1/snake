#include "../headers/menus/GameplayMenu.h"

GameplayMenu::GameplayMenu() {
  setupTxt(scoreTxt, "SCORE: 0", 36, sf::Vector2f(840.f/2, 50.f));
}

void GameplayMenu::updateScoreTxt(int score) {
  std::string scoreValue = std::to_string(score);
  scoreTxt.setString("SCORE: " + scoreValue);

  sf::FloatRect textRect = scoreTxt.getLocalBounds();
  scoreTxt.setOrigin(textRect.left + textRect.width/2.0f,textRect.top  + textRect.height/2.0f);
  scoreTxt.setPosition(840/2, 50);
}

sf::Text GameplayMenu::getScoreTxt() const{
  return scoreTxt;
}


