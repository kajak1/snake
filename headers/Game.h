#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <SFML/Graphics.hpp>

#include "Snake.h"
#include "View.h"
#include "utils/Highscores.h"
#include "utils/constants.h"

enum GameState { RUNNING, NOT_RUNNING, FINISHED_WIN, FINISHED_LOSS };
enum MenuActive { START_MENU, GAMEPLAY, END_MENU };

class Game {
  Snake &snake;
  Map &map;
  StartMenu &startMenu;
  EndMenu &endMenu;
  GameplayMenu &gameplayMenu;
  View &view;

  sf::Clock clock;

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
         View &view);

    void setGameMode(GameMode mode);

    void startGame();
    void restart(bool totally);

    void run();
    GameState getGameState() const;
    void resetScore();
    void saveScore();
    void checkScoreUpdate();

    StartMenu getStartMenu() const;
    EndMenu getEndMenu() const;
};

#endif
