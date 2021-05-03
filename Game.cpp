#include <SFML/Graphics.hpp>

#include "headers/Snake.h"
#include "headers/Game.h"

Game::Game(Snake &snake, sf::RenderWindow &window) : snake(snake), window(window) {}

void Game::debug_display() const {
  sf::RectangleShape snakeShape(sf::Vector2f(snake.getWidth(), snake.getHeight()));
  snakeShape.setPosition(snake.getPosX(), snake.getPosY());
  window.draw(snakeShape);
}
