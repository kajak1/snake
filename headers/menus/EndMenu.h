#ifndef SNAKE_ENDMENU_H
#define SNAKE_ENDMENU_H

#include "MainMenu.h"

class EndMenu : public MainMenu{
  sf::Text gameOverTxt;
  sf::Text endGameScoreTxt;

  public:
    EndMenu();
    sf::Text getGameOverTxt() const;
    sf::Text getEndGameScoreTxt() const;
    void updateEndGameScoreTxt(int score);
};

#endif //SNAKE_ENDMENU_H
