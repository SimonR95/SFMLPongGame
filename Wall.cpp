#include "stdafx.h"
#include "Wall.h"


Wall::Wall(sf::Vector2f size, sf::Vector2f position) {
	wallSize = size;
	wallPosition = position;
}

sf::RectangleShape Wall::CreateWall() {
	sf::RectangleShape newWall;
	newWall.setSize(wallSize);
	newWall.setPosition(wallPosition);
	return newWall;
}