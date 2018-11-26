#pragma once
#ifndef __BALL_H_INCLUDED__
#define __BALL_H_INCLUDED__
#include <SFML/Graphics.hpp>
#include "Paddle.h"

class Ball : public sf::CircleShape{
public:
	//Constructors
	Ball();
	Ball(int pointCount, int ballRadius, float angle, sf::Color colour, sf::Vector2f position);

	//Methods
	void MoveBall(const float &factor);
	void InverseAngle();
	void BallPaddleCollision(const Paddle &playerPaddle, const int &playerFlag);
	void SetAngle(const float &angle);
	float GetAngle();

private:
	//Variables
	int ballPointCount;
	int ballRadius;
	float ballAngle;

	//SFML Objects
	sf::Color ballColour;
	sf::Vector2f ballPosition;
};

#endif