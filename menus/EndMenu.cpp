#include "../headers/menus/EndMenu.h"

EndMenu::EndMenu() {
  setupTxt(gameOverTxt, "GAME OVER", 48, 50);
  setupTxt(endGameScoreTxt, "SCORE: 0", 48, 150);
  highcoresBtn.setPosition(840/2, 230);
  startGameBtn.setPosition(840/2, 330);
}

sf::Text EndMenu::getGameOverTxt() const {
  return gameOverTxt;
}

void EndMenu::updateEndGameScoreTxt(int score) {
  std::string scoreValue = std::to_string(score);
  endGameScoreTxt.setString("SCORE: " + scoreValue);

  sf::FloatRect textRect = endGameScoreTxt.getLocalBounds();
  endGameScoreTxt.setOrigin(textRect.left + textRect.width/2.0f,textRect.top  + textRect.height/2.0f);
  endGameScoreTxt.setPosition(840/2, 150);
}

sf::Text EndMenu::getEndGameScoreTxt() const {
  return endGameScoreTxt;
}
