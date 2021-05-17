#ifndef SNAKE_VIEW_H
#define SNAKE_VIEW_H

#include <SFML/Graphics.hpp>

#include "Snake.h"
#include "Map.h"
#include "menus/StartMenu.h"
#include "menus/EndMenu.h"
#include "menus/GameplayMenu.h"

class View {
  Snake &snake;
  Map &map;
  StartMenu &startMenu;
  EndMenu &endMenu;
  GameplayMenu &gameplayMenu;
  sf::RenderWindow &window;

  public:
    View(Snake &snake,
         Map &map,
         StartMenu &startMenu,
         EndMenu &endMenu,
         GameplayMenu &gameplayMenu,
         sf::RenderWindow &window);
    void drawSnake();
    void drawMap();
    void drawStartMenu();
    void drawEndMenu();
    void drawGameplayMenu();
};

#endif //SNAKE_VIEW_H
