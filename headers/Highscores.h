#ifndef SNAKE_HIGHSCORES_H
#define SNAKE_HIGHSCORES_H

#include <vector>
#include <fstream>

class Highscores {
  std::vector<int> highscores;

  std::ofstream highscoresIN;
  std::ifstream highscoresOUT;

  int scoreCount = 0;

  public:
    void readFromFile();
    void clear();
    void updateVector(int score);
    void saveToFile();
    std::vector<int> getHighscores() const;
};

#endif //SNAKE_HIGHSCORES_H
