#include "../headers/menus/EndMenu.h"
#include "../headers/utils/constants.h"


EndMenu::EndMenu() :
  restartGameBtnPos(sf::Vector2f(840/2 + 50, 300)),
  changeDiffBtnPos(sf::Vector2f(840/2 + 50, 450))
  {
  setupTxt(gameOverTxt, "GAME OVER", textColor, 69, sf::Vector2f(840.f/2, 50.f));
  setupTxt(endGameScoreTxt, "SCORE: 0", textColor, 48, sf::Vector2f(840.f/2, 150.f));
  setupTxt(highscoresTxt, "HIGHSCORES: ", textColor, 36, sf::Vector2f(180.f, 290.f));
  setupTxt(restartGameBtnTxt, "RESTART", textColor, 30,  sf::Vector2f(restartGameBtnPos.x + btnWidth/2, restartGameBtnPos.y + btnHeight/2));
  setupTxt(changeDiffBtnTxt, "CHANGE \nDIFFICULTY", textColor, 30, sf::Vector2f(changeDiffBtnPos.x + btnWidth/2, changeDiffBtnPos.y + btnHeight/2));

  changeDiffBtn.setSize(sf::Vector2f(btnWidth, btnHeight));
  changeDiffBtn.setPosition(changeDiffBtnPos);
  changeDiffBtn.setFillColor(btnColor);

  restartGameBtn.setSize(sf::Vector2f(btnWidth, btnHeight));
  restartGameBtn.setPosition(restartGameBtnPos);
  restartGameBtn.setFillColor(btnColor);
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

void EndMenu::createhighscoresVec(std::vector<int> highscores) {
  highscoresVec.clear();
  if(highscores.size() > 0) {
    for (size_t i = 0; i <= highscores.size() - 1; i++){
      sf::Text highscoreTMP;
      std::string text = std::to_string(i+1) + ": " + std::to_string(highscores[i]);
      if ( i > 4) {
        setupTxt(highscoreTMP, text, textColor, 26, sf::Vector2f(250.f, (50.f * (i-5)) + 350.f));
      } else {
        setupTxt(highscoreTMP, text, textColor, 26, sf::Vector2f(90.f, (50.f * i) + 350.f));
      }
      highscoresVec.push_back(highscoreTMP);
    }
  }
}

std::vector<sf::Text> EndMenu::gethighscoresVec() const {
  return highscoresVec;
}

sf::Text EndMenu::getHighscoresTxt() const {
  return highscoresTxt;
}

sf::RectangleShape EndMenu::getRestartGameBtn() const {
  return restartGameBtn;
}

sf::Text EndMenu::getRestartGameBtnTxt() const {
  return restartGameBtnTxt;
}

sf::RectangleShape EndMenu::getChangeDiffBtn() const {
  return changeDiffBtn;
}

sf::Text EndMenu::getChangeDiffBtnTxt() const {
  return changeDiffBtnTxt;
}
