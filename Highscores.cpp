#include "headers/Highscores.h"

#include <iostream>

void Highscores::readFromFile() {

  std::string line;

  scoreCount = 0;

  highscores.clear();

  highscoresOUT.open("../highscores.txt");

  if (highscoresOUT.is_open()) {
    while (getline(highscoresOUT, line)) {
      highscores.push_back(std::stoi(line));
      std::cout << "dodalem " << std::stoi(line) << '\n';
      scoreCount += 1;
    }
    highscoresOUT.close();
  }
}

void Highscores::clear() {
  highscoresOUT.open("../highscores.txt", std::ios::out | std::ios::trunc);
  highscoresOUT.close();
}

void Highscores::saveToFile() {

  clear();

  highscoresIN.open("../highscores.txt", std::ios::app);
  if (highscoresIN.is_open()) {
    for(int highscore: highscores) {
      highscoresIN << highscore << std::endl;
    }
    highscoresIN.close();
  } else {
    std::cout << "error\n";
  }
}

void Highscores::updateVector(int score) {
  if(highscores.empty()){
    highscores.push_back(score);
    return;
  }

    if (score > highscores[0]) {
      if(highscores.size() < 10){
        highscores.push_back(score);
      }
      for(int i = highscores.size() - 1; i >= 1; i--){
        highscores[i] = highscores[i-1];
      }
      highscores[0] = score;
    }
}
