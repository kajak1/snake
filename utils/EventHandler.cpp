#include <iostream>
#include "../headers/utils/EventHandler.h"

EventHandler::EventHandler(Snake &snake, Game &game, View &view, sf::RenderWindow &window) : snake(snake), game(game), view(view), window(window){}

void EventHandler::listen(sf::Event &event) {
  if (event.type == sf::Event::Closed)
    window.close();

  if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF( static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

    if (game.getGameState() == NOT_RUNNING) {
      if (game.getStartMenu().getEasyBtn().getGlobalBounds().contains(mousePosF)) {
        game.setGameMode(EASY);
        handleStartBtnClick();
        return;
      }

      if (game.getStartMenu().getNormalBtn().getGlobalBounds().contains(mousePosF)) {
        game.setGameMode(NORMAL);
        handleStartBtnClick();
        return;
      }

      if (game.getStartMenu().getHardBtn().getGlobalBounds().contains(mousePosF)) {
        game.setGameMode(HARD);
        handleStartBtnClick();
        return;
      }
    }

    if (game.getGameState() == FINISHED_WIN || game.getGameState() == FINISHED_LOSS) {
      if (game.getEndMenu().getRestartGameBtn().getGlobalBounds().contains(mousePosF)) {
        handleRestartBtnClick(false);
      }

      if (game.getEndMenu().getChangeDiffBtn().getGlobalBounds().contains(mousePosF)) {
        handleRestartBtnClick(true);
      }
    }
  }

  if (event.type == sf::Event::KeyPressed) {
    sf::Keyboard::Key key = event.key.code;
    if (key == sf::Keyboard::W || key == sf::Keyboard::A || key == sf::Keyboard::S || key == sf::Keyboard::D){
      if (game.getGameState() == RUNNING && snake.getDidTurn() == false) handleWASD_Click(event);
    }
  }
}

void EventHandler::handleWASD_Click(sf::Event &event) {
  int dirX = snake.getDirX();
  int dirY = snake.getDirY();
  if (event.key.code == sf::Keyboard::A) {
    if(dirX == 0 && dirY == -1) {
      // going up
      snake.turn(LEFT);
      return;
    }
    if(dirX == 0 && dirY == 1) {
      // going down
      snake.turn(RIGHT);
      return;
    }
  }

  if (event.key.code == sf::Keyboard::W) {
    if(dirX == -1 && dirY == 0){
      // going left
      snake.turn(RIGHT);
      return;
    }
    if(dirX == 1 && dirY == 0){
      // going right
      snake.turn(LEFT);
      return;
    }
  }

  if (event.key.code == sf::Keyboard::D) {
    if(dirX == 0 && dirY == -1){
      // going up
      snake.turn(RIGHT);
      return;
    }
    if(dirX == 0 && dirY == 1){
      // going down
      snake.turn(LEFT);
      return;
    }
  }

  if (event.key.code == sf::Keyboard::S) {
    if(dirX == 1 && dirY == 0){
      // going left
      snake.turn(RIGHT);
      return;
    }
    if(dirX == -1 && dirY == 0){
      // going right
      snake.turn(LEFT);
      return;
    }
  }
}

void EventHandler::handleStartBtnClick() {
    game.startGame();
}

void EventHandler::handleRestartBtnClick(bool totally) {
    game.restart(totally);
}
