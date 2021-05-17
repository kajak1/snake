#include <iostream>
#include "headers/EventHandler.h"

EventHandler::EventHandler(Snake &snake, Game &game, View &view, sf::RenderWindow &window) : snake(snake), game(game), view(view), window(window){}

void EventHandler::listen(sf::Event &event) {
  if (event.type == sf::Event::Closed)
    window.close();

  if (event.type == sf::Event::KeyPressed) {
    if (event.key.code == sf::Keyboard::Space) handleSpaceClick();

    sf::Keyboard::Key key = event.key.code;
    if(key == sf::Keyboard::W || key == sf::Keyboard::A || key == sf::Keyboard::S || key == sf::Keyboard::D){
      if (game.getGameState() == RUNNING) handleWASD_Click(event);
    }
  }
}

void EventHandler::handleWASD_Click(sf::Event &event) {
  int dirX = snake.getDirX();
  int dirY = snake.getDirY();
  if (event.key.code == sf::Keyboard::A) {
    std::cout << "left\n";
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
    std::cout << "up\n";
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
    std::cout << "right\n";
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
    std::cout << "down\n";
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

void EventHandler::handleSpaceClick() {
  if(game.getGameState() == NOT_RUNNING) {
    game.startGame();
    return;
  }

  if(game.getGameState() == FINISHED_WIN || game.getGameState() == FINISHED_LOSS){
    game.restart();
    return;
  }
}
