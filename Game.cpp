#include <SFML/Graphics.hpp>

#include "headers/Snake.h"
#include "headers/Game.h"

Game::Game(Snake &snake, Map &map, View &view, sf::RenderWindow &window)
: snake(snake), map(map), view(view), window(window) {}

void Game::debug_display() const {
  sf::RectangleShape snakeShape(
          sf::Vector2f(snake.getWidth(), snake.getHeight())
          );
  snakeShape.setPosition(snake.getPosX(), snake.getPosY());
  window.draw(snakeShape);
}

void Game::run() {
  if(!gameOver) {
    snake.update();
    map.checkFoodEat();
    map.updateSnakePos();
    gameOver = map.isSnakeOutside() || map.snakeSelfCollide();
  }

  if(!gameOver) {
    view.drawMap();
    view.drawSnake();
  } else {
    view.drawMenu();
  }
//    game.debug_display();
}
