#ifndef SNAKE_ENDMENU_H
#define SNAKE_ENDMENU_H

#include "Menu.h"

class EndMenu : public Menu{
  sf::Text gameOverTxt;
  sf::Text endGameScoreTxt;
  sf::Text highscoresTxt;

  sf::RectangleShape restartGameBtn;
  sf::Vector2f restartGameBtnPos;
  sf::Text restartGameBtnTxt;

  sf::RectangleShape changeDiffBtn;
  sf::Vector2f changeDiffBtnPos;
  sf::Text changeDiffBtnTxt;

  std::vector<sf::Text> highscoresVec;

  public:
    EndMenu();
    sf::Text getGameOverTxt() const;
    sf::Text getEndGameScoreTxt() const;
    sf::Text getHighscoresTxt() const;

    sf::RectangleShape getRestartGameBtn() const;
    sf::Text getRestartGameBtnTxt() const;

    sf::RectangleShape getChangeDiffBtn() const;
    sf::Text getChangeDiffBtnTxt() const;

    void updateEndGameScoreTxt(int score);

    void createhighscoresVec(std::vector<int> highscores);
    std::vector<sf::Text> gethighscoresVec() const;
};

#endif //SNAKE_ENDMENU_H
