#pragma once
#ifndef __PADDLE_H_INCLUDED__
#define __PADDLE_H_INCLUDED__
#include <SFML/Graphics.hpp>
#include "Wall.h"

class Paddle : public sf::RectangleShape {
public:
	//Constructors
	Paddle();
	Paddle(sf::Keyboard::Key upKey, sf::Keyboard::Key downKey, sf::Vector2f size, sf::Color colour, sf::Color outlineColour, int outlineThickness, sf::Vector2f position, sf::Vector2f origin);
	
	//Methods
	void ReadInput(const Wall &ceiling, const Wall &floor, const float &factor);

private:
	//Variables
	int paddleOutlineThickness;

	//SFML Object
	sf::Keyboard::Key paddleUpKey;
	sf::Keyboard::Key paddleDownKey;
	sf::Vector2f paddleSize;
	sf::Color paddleColour;
	sf::Color paddleOutlineColour;
	sf::Vector2f paddlePosition;
	sf::Vector2f paddleOrigin;
};

#endif