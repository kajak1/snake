#include <iostream>
#include <SFML/Window.hpp>

#include "headers/Snake.h"
#include "headers/Game.h"
#include "headers/View.h"
#include "headers/EventHandler.h"
#include "headers/Map.h"

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");

  Map map(NORMAL);
  Snake snake(true);
  Game game(snake, window);
  View view(snake, game, window);

  EventHandler eventHandler(snake, game, view, window);

  window.setFramerateLimit(60);

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      eventHandler.listen(event);
    }

    window.clear(sf::Color::Black);
    snake.update();
//    game.debug_display();
    view.drawSnake();
    window.display();
  }

  return 0;
}