#include "headers/View.h"

View::View(Snake &snake, Game &game, sf::RenderWindow &window) : snake(snake), game(game), window(window){}

void View::drawSnake() {
  for(int i = 0; i < snake.getLength(); i++){
    window.draw(snake.parts[i]);
  }
}

void View::drawMap() {

}
