#include <iostream>
#include "headers/View.h"
#include "headers/utils/constants.h"

View::View(Snake &snake,
           Map &map,
           StartMenu &startMenu,
           EndMenu &endMenu,
           GameplayMenu &gameplayMenu,
           sf::RenderWindow &window)
: snake(snake),
  map(map),
  startMenu(startMenu),
  endMenu(endMenu),
  gameplayMenu(gameplayMenu),
  window(window){}

void View::drawSnake() {
  for(auto part: snake.getParts()){
    part.setFillColor(snakeColor);
    window.draw(part);
  }
}

void View::drawMap() {
  for(int row = 0; row < map.getHeight(); row++){
    for(int column = 0; column < map.getWidth(); column++){
      sf::RectangleShape square(sf::Vector2f(20.f, 20.f));

      sf::Color color;

      if (map.hasFood(row, column)) {
        color = foodColor;
      } else if (map.hasObstacle(row, column)) {
        color = obstacleColor;
      } else {
        color = btnColor;
      }

      square.setOutlineThickness(1);
      square.setFillColor(color);
      square.setOutlineColor(sf::Color(212, 198, 133));
      square.setPosition((column*20.f) + map.getOffsetX(), (row*20.f) + map.getOffsetY());

      window.draw(square);
    }
  }
}

void View::drawStartMenu() {
  window.draw(startMenu.getGameTitleTxt());
  window.draw(startMenu.getEasyBtn());
  window.draw(startMenu.getEasyBtnTxt());

  window.draw(startMenu.getNormalBtn());
  window.draw(startMenu.getNormalBtnTxt());

  window.draw(startMenu.getHardBtn());
  window.draw(startMenu.getHardBtnTxt());
  window.draw(startMenu.getHighscoresBtn());
}

void View::drawGameplayMenu() {
  window.draw(gameplayMenu.getScoreTxt());
}

void View::drawEndMenu() {
  window.draw(endMenu.getGameOverTxt());
  window.draw(endMenu.getEndGameScoreTxt());
  window.draw(endMenu.getHighscoresTxt());

  for(sf::Text highscore: endMenu.gethighscoresVec()) {
    window.draw(highscore);
  }

  window.draw(endMenu.getRestartGameBtn());
  window.draw(endMenu.getRestartGameBtnTxt());

  window.draw(endMenu.getChangeDiffBtn());
  window.draw(endMenu.getChangeDiffBtnTxt());
}
