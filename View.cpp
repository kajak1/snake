#include "headers/View.h"

#include <iostream>

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
    window.draw(part);
  }
}

void View::drawMap() {
  for(int row = 0; row < map.getHeight(); row++){
    for(int column = 0; column < map.getWidth(); column++){
      sf::RectangleShape square(sf::Vector2f(20.f, 20.f));
      sf::Color color = map.hasFood(row, column) ? sf::Color::Magenta : sf::Color::Blue;

      square.setOutlineThickness(1);
      square.setFillColor(color);
      square.setOutlineColor(sf::Color::Red);
      square.setPosition((column*20.f) + map.getOffsetX(), (row*20.f) + map.getOffsetY());

      window.draw(square);
    }
  }
}

void View::drawStartMenu() {
  window.draw(startMenu.getGameTitleTxt());
  window.draw(startMenu.getStartGameBtn());
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
  window.draw(endMenu.getStartGameBtn());
}
