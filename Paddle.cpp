#include "stdafx.h"
#include "Paddle.h"


Paddle::Paddle(sf::Vector2f size, sf::Color colour, sf::Vector2f position, sf::Vector2f origin) {
	paddleSize = size;
	paddleColour = colour;
	paddlePosition = position;
	paddleOrigin = origin;
}

sf::RectangleShape Paddle::CreatePaddle() {
	sf::RectangleShape newPaddle;
	newPaddle.setOutlineThickness(3);
	newPaddle.setOutlineColor(sf::Color::White);
	newPaddle.setSize(paddleSize);
	newPaddle.setFillColor(paddleColour);
	newPaddle.setPosition(paddlePosition);
	newPaddle.setOrigin(paddleOrigin);
	return newPaddle;
}