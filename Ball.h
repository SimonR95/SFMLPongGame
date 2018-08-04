#pragma once
#include <SFML/Graphics.hpp>

class Ball {
public:
	Ball(int pointCount, int ballRadius, sf::Color colour, sf::Vector2f position);
	sf::CircleShape CreateBall();

private:
	int ballPointCount;
	int ballRadius;
	sf::Color ballColour;
	sf::Vector2f ballPosition;
};