#include "stdafx.h"
#include "Ball.h"


Ball::Ball(int pointCount, int radius, sf::Color colour, sf::Vector2f position) {
	ballPointCount = pointCount;
	ballRadius = radius;
	ballColour = colour;
	ballPosition = position;
}

sf::CircleShape Ball::CreateBall() {
	sf::CircleShape newBall;
	newBall.setRadius(ballRadius);
	newBall.setPointCount(ballPointCount);
	newBall.setFillColor(ballColour);
	newBall.setPosition(ballPosition);
	return newBall;
}
