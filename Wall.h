#pragma once
#include <SFML/Graphics.hpp>

class Wall {
public:
	Wall(sf::Vector2f size, sf::Vector2f position);
	sf::RectangleShape CreateWall();

private:
	sf::Vector2f wallSize;
	sf::Vector2f wallPosition;
};