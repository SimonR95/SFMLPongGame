#pragma once
#ifndef __PONG_H_INCLUDED__
#define __PONG_H_INCLUDED__
#include <SFML/Audio.hpp>
#include "Paddle.h"
#include "Ball.h"
#include "Wall.h"
#include "Menu.h"
#include "Text.h"

enum class GameState { Paused, Playing, Menu };

class Pong {
public:
	//Constructors
	Pong();

	//Methods
	int Run();
	void LoadFont();
	void LoadSounds();
	void CreatePaddles();
	void CreateBall();
	void CreateBorders();
	void CreateText();
	void RegisterScores(const int &player);
	void RenderGame();
	void ResetGame();

private:
	//Variables
	bool paused;
	int playerOneScore;
	int playerTwoScore;
	float screenWidth;
	float screenHeight;
	float paddleSpeed;

	//SFML Objects
	sf::Music music;
	sf::SoundBuffer collideBuffer;
	sf::Sound collide;
	sf::SoundBuffer scoreBuffer;
	sf::Sound score;
	sf::SoundBuffer pauseBuffer;
	sf::Sound pause;
	sf::RenderWindow window;
	sf::Event event;
	sf::Clock clock;
	sf::Font font;
	sf::Vector2f paddleSize;

	//Custom Objects
	GameState gameState;
	Paddle playerOnePaddle;
	Paddle playerTwoPaddle;
	Ball pongBall;
	Wall ceiling;
	Wall floor;
	Text playerOneText;
	Text playerTwoText;
	Text pauseText;
	Menu menu;
};

#endif