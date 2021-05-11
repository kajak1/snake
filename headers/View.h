#ifndef SNAKE_VIEW_H
#define SNAKE_VIEW_H

#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "Map.h"

class View {
  Snake &snake;
  Map &map;
  sf::RenderWindow &window;

  bool isMenuActive = true;

  public:
    View(Snake &snake, Map &map, sf::RenderWindow &window);
    void drawSnake();
    void drawMap();
    void drawMenu();
    void toggleMenu();
};

#endif //SNAKE_VIEW_H
