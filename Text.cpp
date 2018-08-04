#include "stdafx.h"
#include "Text.h"

Text::Text(){};

Text::Text(std::string str, sf::Color colour, float size, sf::Vector2f position) {
	this->setString(str);
	this->setFillColor(colour);
	this->setCharacterSize(size);
	this->setPosition(position);
}