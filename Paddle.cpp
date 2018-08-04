#include "stdafx.h"
#include "Paddle.h"


Paddle::Paddle(){};

Paddle::Paddle(sf::Keyboard::Key upKey, sf::Keyboard::Key downKey, sf::Vector2f size, sf::Color colour, sf::Color outlineColour, int outlineThickness, sf::Vector2f position, sf::Vector2f origin) {
	paddleUpKey = upKey;
	paddleDownKey = downKey;
	this->setSize(size);
	this->setFillColor(colour);
	this->setOutlineColor(outlineColour);
	this->setOutlineThickness(outlineThickness);
	this->setPosition(position);
	this->setOrigin(origin);
}

void Paddle::ReadInput(const Wall &ceiling, const Wall &floor, const float &factor) {
	if (sf::Keyboard::isKeyPressed(paddleUpKey) && !(this->getGlobalBounds().intersects(ceiling.getGlobalBounds())))
	{
		this->move(0.f, -factor); //Move in Y Plane only
	}
	if (sf::Keyboard::isKeyPressed(paddleDownKey) && !(this->getGlobalBounds().intersects(floor.getGlobalBounds())))
	{
		this->move(0.f, factor);
	}
}