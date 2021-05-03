#include <iostream>
#include <SFML/Window.hpp>

#include "headers/Snake.h"
#include "headers/Game.h"
#include "headers/EventHandler.h"

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");

  Snake snake;
  Game game(snake, window);

  window.setFramerateLimit(10);

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear(sf::Color::Black);
    snake.update();
    game.debug_display();
    window.display();
  }

  return 0;
}