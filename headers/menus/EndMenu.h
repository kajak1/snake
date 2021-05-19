#ifndef SNAKE_ENDMENU_H
#define SNAKE_ENDMENU_H

#include "MainMenu.h"

class EndMenu : public MainMenu{
  sf::Text gameOverTxt;
  sf::Text endGameScoreTxt;
  sf::Text highscoresTxt;

  std::vector<sf::Text> highscoresVec;

  public:
    EndMenu();
    sf::Text getGameOverTxt() const;
    sf::Text getEndGameScoreTxt() const;
    sf::Text getHighscoresTxt() const;
    
    void updateEndGameScoreTxt(int score);

    void createhighscoresVec(std::vector<int> highscores);
    std::vector<sf::Text> gethighscoresVec() const;
};

#endif //SNAKE_ENDMENU_H
