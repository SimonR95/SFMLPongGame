#pragma once
#include <SFML/Graphics.hpp>

class Paddle {
public:
	Paddle(sf::Vector2f size, sf::Color colour, sf::Vector2f position, sf::Vector2f origin);
	sf::RectangleShape CreatePaddle();

private:
	sf::Vector2f paddleSize;
	sf::Color paddleColour;
	sf::Vector2f paddlePosition;
	sf::Vector2f paddleOrigin;
};