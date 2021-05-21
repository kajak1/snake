#include <SFML/Graphics.hpp>

#include "headers/Snake.h"
#include "headers/Game.h"

Game::Game(Snake &snake, Map &map, StartMenu &startMenu,
           EndMenu &endMenu,
           GameplayMenu &gameplayMenu, View &view)
: snake(snake), map(map), startMenu(startMenu), endMenu(endMenu), gameplayMenu(gameplayMenu), view(view) {}

void Game::run() {
  if(menuActive == START_MENU) view.drawStartMenu();
  if(menuActive == GAMEPLAY) view.drawGameplayMenu();
  if(menuActive == END_MENU) view.drawEndMenu();

  if(gameState == RUNNING) {
    snake.setDidTurn(false);
    snake.update(clock);
    checkScoreUpdate();
    map.updateSnakePos();
    if(map.isSnakeOutside() || map.snakeSelfCollide() || map.snakeObstacleCollide()){
      gameState = FINISHED_LOSS;
      menuActive = END_MENU;
      saveScore();
      endMenu.createhighscoresVec(highscores.getHighscores());
    }
  }
  if(gameState == RUNNING) {
    view.drawMap();
    view.drawSnake();
  }
}

void Game::checkScoreUpdate() {
  if (map.checkFoodEat()){
    if (gameMode == EASY) {
      score += 100;
    } else {
      score += 50;
    }
    gameplayMenu.updateScoreTxt(score);
    endMenu.updateEndGameScoreTxt(score);
  }
}

void Game::startGame() {
  gameState = RUNNING;
  menuActive = GAMEPLAY;
}

GameState Game::getGameState() const {
  return gameState;
}

void Game::restart(bool totally) {
  snake.resetState();
  map.createBoard(gameMode);
  resetScore();

  gameplayMenu.updateScoreTxt(score);
  endMenu.updateEndGameScoreTxt(score);

  if (totally) {
    gameState = NOT_RUNNING;
    menuActive = START_MENU;
  } else {
    startGame();
  }
}

void Game::resetScore() {
  score = 0;
}

void Game::saveScore()  {
  highscores.readFromFile();
  highscores.updateVector(score);
  highscores.saveToFile();
}

StartMenu Game::getStartMenu() const {
  return startMenu;
}

EndMenu Game::getEndMenu() const {
  return endMenu;
}

void Game::setGameMode(GameMode mode) {
  gameMode = mode;
  map.createBoard(mode);
}
