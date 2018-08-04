#include "stdafx.h"
#include "Wall.h"

Wall::Wall(){};

Wall::Wall(sf::Vector2f size, sf::Color colour, sf::Vector2f position) {
	this->setSize(size);
	this->setFillColor(colour);
	this->setPosition(position);
}
