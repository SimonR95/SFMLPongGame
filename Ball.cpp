#include "stdafx.h"
#include "Ball.h"

Ball::Ball(){
};

Ball::Ball(int pointCount, int radius, float angle, sf::Color colour, sf::Vector2f position) {
	ballAngle = 0;
	this->setPointCount(pointCount);
	this->setRadius(radius);
	this->setFillColor(colour);
	this->setPosition(position);
}

void Ball::MoveBall(const float &factor) {
	this->move(std::cos(ballAngle)*factor, std::sin(ballAngle)*factor);
}

void Ball::BallPaddleCollision(const Paddle &playerPaddle) {
	if (this->getPosition().y > (playerPaddle.getPosition().y)) { //Reflect ball differently based on where it collides
		ballAngle = 3.14159265359 - ballAngle + 10 * (3.14159265359 /180);
	}
	else {
		ballAngle = 3.14159265359 - ballAngle - 10 * (3.14159265359 / 180);
	}
}

void Ball::InverseAngle() {
	ballAngle = -ballAngle;
}

float Ball::GetAngle() {
	return ballAngle;
}

void Ball::SetAngle(const float &angle) {
	ballAngle = angle;
}
