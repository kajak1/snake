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
      sf::Color color = map.hasFood(row, column) ? sf::Color::Magenta : sf::Color::Blue;
      square.setFillColor(color);
      square.setOutlineColor(sf::Color::Red);
      square.setPosition((column*20.f) + map.getOffsetX(), (row*20.f) + map.getOffsetY());
      window.draw(square);
    }
  }
}

void View::drawMenu() {
  if(isMenuActive){
    sf::RectangleShape menu(sf::Vector2f(50.f, 50.f));
    window.draw(menu);
  }
}

void View::toggleMenu() {
  isMenuActive = !isMenuActive;
}
