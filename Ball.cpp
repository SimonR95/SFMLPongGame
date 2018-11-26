#include "stdafx.h"
#include "Ball.h"
#include <iostream>

Ball::Ball(){
};

Ball::Ball(int pointCount, int radius, float angle, sf::Color colour, sf::Vector2f position) {
	ballAngle = 0;
	ballSpeed = 1;
	this->setPointCount(pointCount);
	this->setRadius(radius);
	this->setOrigin(radius, radius);
	this->setFillColor(colour);
	this->setPosition(position);
}

void Ball::MoveBall(const float &factor) {
	this->move(std::cos(ballAngle)*factor*ballSpeed, std::sin(ballAngle)*factor*ballSpeed);
}

std::string Ball::BallPaddleCollision(const Paddle &playerPaddle, const int &playerFlag) {
	float intersectPoint = playerPaddle.getPosition().y - this->getPosition().y;
	float normalisedIntersectPoint = intersectPoint / 50;
	float bounceModifier = (4 * 3.14159265359) / 15;
	std::cout << normalisedIntersectPoint << std::endl;

	switch (playerFlag) {
	case(1):
		ballAngle = -normalisedIntersectPoint * (bounceModifier);
		break;
	case(2):
		ballAngle = 3.14159265359 + normalisedIntersectPoint * (bounceModifier);
		break;
	}

	if (fabsf(normalisedIntersectPoint) > 0.75) {
		ballSpeed += 0.25;
		return "Up";
	}
	else if (ballSpeed > 1) {
		ballSpeed -= 0.25;
		return "Down";
	}
	return "";
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

void Ball::SetBallSpeed(const int &speed) {
	ballSpeed = 1;
}
