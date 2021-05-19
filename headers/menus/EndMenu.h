#ifndef SNAKE_ENDMENU_H
#define SNAKE_ENDMENU_H

#include "MainMenu.h"

class EndMenu : public MainMenu{
  sf::Text gameOverTxt;
  sf::Text endGameScoreTxt;

  std::vector<sf::Text> highscoresTxt;

  public:
    EndMenu();
    sf::Text getGameOverTxt() const;
    sf::Text getEndGameScoreTxt() const;
    void updateEndGameScoreTxt(int score);

    void createHighscoresTxt(std::vector<int> highscores);
    std::vector<sf::Text> getHighscoresTxt() const;
};

#endif //SNAKE_ENDMENU_H
