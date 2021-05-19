#include <iostream>
#include <ctime>
#include <SFML/Window.hpp>

#include "headers/Snake.h"
#include "headers/Game.h"
#include "headers/EventHandler.h"

int main() {
  srand(time(NULL));
  sf::RenderWindow window(sf::VideoMode(840, 600), "Snake");

  Snake snake;
  Map map(snake);
  StartMenu startMenu;
  EndMenu endMenu;
  GameplayMenu gameplayMenu;
  View view(snake, map, startMenu, endMenu, gameplayMenu, window);
  Game game(snake, map, startMenu, endMenu, gameplayMenu, view, window);

  EventHandler eventHandler(snake, game, view, window);

  window.setFramerateLimit( 16);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      eventHandler.listen(event);
    }
    window.clear(sf::Color::Black);
    game.run();
    window.display();
  }

  return 0;
}