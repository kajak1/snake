#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <SFML/Graphics.hpp>

#include "Snake.h"
#include "View.h"
#include "Highscores.h"

enum GameMode  { EASY, NORMAL, HARD };
enum GameState { RUNNING, NOT_RUNNING, FINISHED_WIN, FINISHED_LOSS };
enum MenuActive { START_MENU, GAMEPLAY, END_MENU };

class Game {
  Snake &snake;
  Map &map;
  StartMenu &startMenu;
  EndMenu &endMenu;
  GameplayMenu &gameplayMenu;
  View &view;
  sf::RenderWindow &window;

  Highscores highscores;

  int score = 0;

  GameState gameState = NOT_RUNNING;
  GameMode gameMode = NORMAL;
  MenuActive menuActive = START_MENU;

  public:
    Game(Snake &snake,
         Map &map,
         StartMenu &startMenu,
         EndMenu &endMenu,
         GameplayMenu &gameplayMenu,
         View &view,
         sf::RenderWindow &window);

    void debug_display() const;
    void startGame();
    void restart();
    void run();
    GameState getGameState() const;
    MenuActive getActiveMenu() const;
    int getScore() const;
    void resetScore();
    void saveScore();
    void checkScoreUpdate();
};

#endif
