#include "headers/View.h"

View::View(Snake &snake, Map &map, sf::RenderWindow &window)
: snake(snake), map(map), window(window){}

void View::drawSnake() {
  for(auto part: snake.getParts()){
    window.draw(part);
  }
}

void View::drawMap() {
  for(int row = 0; row < map.getHeight(); row++){
    for(int column = 0; column < map.getWidth(); column++){
      sf::RectangleShape square(sf::Vector2f(20.f, 20.f));
      square.setOutlineThickness(1);
      if(map.hasFood(row, column)) {
        square.setFillColor(sf::Color::Magenta);
      } else{
        square.setFillColor(sf::Color::Blue);
      }
      square.setOutlineColor(sf::Color::Red);
      square.setPosition(row*20.f, column*20.f);
      window.draw(square);
    }
  }
}