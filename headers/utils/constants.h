#ifndef SNAKE_CONSTANTS_H
#define SNAKE_CONSTANTS_H

const sf::Color btnColor = sf::Color(42, 157, 143);
const sf::Color snakeColor = sf::Color(207, 231, 149);
const sf::Color obstacleColor = sf::Color(138, 90, 68);
const sf::Color foodColor = sf::Color(185, 0, 0);
const sf::Color textColor = snakeColor;

constexpr int btnWidth = 270.f;
constexpr int btnHeight = 100.f;

enum GameMode { EASY, NORMAL, HARD };

#endif //SNAKE_CONSTANTS_H
