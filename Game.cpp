#include <SFML/Graphics.hpp>

#include "headers/Snake.h"
#include "headers/Game.h"

Game::Game(Snake &snake, Map &map, StartMenu &startMenu,
           EndMenu &endMenu,
           GameplayMenu &gameplayMenu, View &view, sf::RenderWindow &window)
: snake(snake), map(map), startMenu(startMenu), endMenu(endMenu), gameplayMenu(gameplayMenu), view(view), window(window) {}

void Game::run() {
  if(menuActive == START_MENU) view.drawStartMenu();
  if(menuActive == GAMEPLAY) view.drawGameplayMenu();
  if(menuActive == END_MENU) view.drawEndMenu();

  if(gameState == RUNNING) {
    snake.update();
    checkScoreUpdate();
    map.updateSnakePos();
    if(map.isSnakeOutside() || map.snakeSelfCollide()){
      gameState = FINISHED_LOSS;
      menuActive = END_MENU;
      saveScore();
      endMenu.createHighscoresTxt(highscores.getHighscores());
    }
  }
  if(gameState == RUNNING) {
    view.drawMap();
    view.drawSnake();
  }
}

void Game::checkScoreUpdate() {
  if(map.checkFoodEat()){
    score += 50;
    gameplayMenu.updateScoreTxt(score);
    endMenu.updateEndGameScoreTxt(score);
  }
}

void Game::debug_display() const {
  sf::RectangleShape snakeShape(
          sf::Vector2f(snake.getWidth(), snake.getHeight())
  );
  snakeShape.setPosition(snake.getPosX(), snake.getPosY());
  window.draw(snakeShape);
}

void Game::startGame() {
  gameState = RUNNING;
  menuActive = GAMEPLAY;
}

GameState Game::getGameState() const {
  return gameState;
}

MenuActive Game::getActiveMenu() const {
  return menuActive;
}

void Game::restart() {
  snake.resetState();
  map.resetState();
  resetScore();

  gameplayMenu.updateScoreTxt(score);
  endMenu.updateEndGameScoreTxt(score);

  startGame();
}

void Game::resetScore() {
  score = 0;
}

void Game::saveScore()  {
  highscores.readFromFile();
  highscores.updateVector(score);
  highscores.saveToFile();
}