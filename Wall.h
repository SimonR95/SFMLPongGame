#pragma once
#ifndef __WALL_H_INCLUDED__
#define __WALL_H_INCLUDED__
#include <SFML/Graphics.hpp>

class Wall : public sf::RectangleShape{
public:
	//Constructors
	Wall();
	Wall(sf::Vector2f size, sf::Color colour, sf::Vector2f position);

private:
	//SFML Objects
	sf::Vector2f wallSize;
	sf::Vector2f wallPosition;
};

#endif