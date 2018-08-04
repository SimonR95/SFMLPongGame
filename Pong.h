#pragma once
#ifndef __PONG_H_INCLUDED__
#define __PONG_H_INCLUDED__
#include "Paddle.h"
#include "Ball.h"
#include "Wall.h"
#include "Text.h"

class Pong {
public:
	//Constructors
	Pong();

	//Methods
	int Run();
	void LoadFont();
	void CreatePaddles();
	void CreateBall();
	void CreateBorders();
	void CreateText();
	void RegisterScores(const int &player);
	void Render();

private:
	//Variables
	bool paused;
	int playerOneScore;
	int playerTwoScore;
	float screenWidth;
	float screenHeight;
	float paddleSpeed;

	//SFML Objects
	sf::RenderWindow window;
	sf::Event event;
	sf::Clock clock;
	sf::Font font;
	sf::Vector2f paddleSize;

	//Custom Objects
	Paddle playerOnePaddle;
	Paddle playerTwoPaddle;
	Ball pongBall;
	Wall ceiling;
	Wall floor;
	Text playerOneText;
	Text playerTwoText;
	Text pauseText;
};

#endif