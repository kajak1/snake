#include <iostream>
#include <ctime>
#include <SFML/Window.hpp>

#include "headers/Snake.h"
#include "headers/Game.h"
#include "headers/EventHandler.h"

int main() {
  srand(time(NULL));
  sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");

  Snake snake;
  Map map(NORMAL, snake);
  View view(snake, map, window);
  Game game(snake, map, view, window);

  EventHandler eventHandler(snake, game, view, window);

  window.setFramerateLimit( 1);

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      eventHandler.listen(event);
    }

    window.clear(sf::Color::Black);
    game.run();
    window.display();
  }

  return 0;
}