// Pong.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Paddle.h"
#include "Wall.h"
#include "Ball.h"
#include "Text.h"
#include <iostream>

int main()
{
	//VARIABLE DEFINITIONS//
	int playerOneScore = 0;
	int playerTwoScore = 0;
	const int screenWidth = 800;
	const int screenHeight = 800;
	const sf::Vector2f paddleSize(10, 100);
	const float paddleSpeed = 800;
	const int ballRadius = 10;
	const int ballPointCount = 30;
	float ballAngle = 0;
	bool paused = false;
	sf::Vector2f velocity;
	sf::Clock clock;
	sf::Font font;
	if (!font.loadFromFile("lucon.ttf")) {
		std::cout << "Error loading font\n";
		return EXIT_FAILURE;
	}
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Pong");

	//TEXT CREATION//
	Text leftText = Text("Player 1: " + std::to_string(playerOneScore), font, 20, sf::Vector2f(65, 50));
	sf::Text playerOneText = leftText.CreateText();
	Text rightText = Text("Player 2: " + std::to_string(playerOneScore), font, 20, sf::Vector2f(screenWidth - 200, 50));
	sf::Text playerTwoText = rightText.CreateText();
	Text spaceText = Text("P A U S E D", font, 50, sf::Vector2f((screenWidth / 2) - 165, screenHeight / 2));
	sf::Text pauseText = spaceText.CreateText();

	//PADDLE CREATION//
	Paddle leftPaddle = Paddle(paddleSize, sf::Color::Red, sf::Vector2f(50, screenWidth / 2), sf::Vector2f(paddleSize.x / 2, paddleSize.y / 2)); //Keep Paddle Origin Vector half of Paddle Size
	sf::RectangleShape playerOnePaddle = leftPaddle.CreatePaddle();
	Paddle rightPaddle = Paddle(paddleSize, sf::Color::Blue, sf::Vector2f(screenWidth - 50, screenWidth / 2), sf::Vector2f(paddleSize.x / 2, paddleSize.y / 2)); //Keep Paddle Origin Vector half of Paddle Size
	sf::RectangleShape playerTwoPaddle = rightPaddle.CreatePaddle();

	//BORDER CREATION//
	Wall topWall = Wall(sf::Vector2f(screenWidth, paddleSize.x), sf::Vector2f(0, 0));
	sf::RectangleShape ceiling = topWall.CreateWall();
	Wall bottomWall = Wall(sf::Vector2f(screenWidth, paddleSize.x), sf::Vector2f(0, screenHeight - paddleSize.x));
	sf::RectangleShape floor = bottomWall.CreateWall();
	floor.setFillColor(sf::Color::Magenta);
	ceiling.setFillColor(sf::Color::Magenta);

	//BALL CREATION//
	Ball ball = Ball(ballPointCount, ballRadius, sf::Color::White, sf::Vector2f(screenWidth / 2, screenHeight / 2));
	sf::CircleShape pongBall = ball.CreateBall();
	
	while (window.isOpen())
	{
		float time = clock.restart().asSeconds();
		float factor = time * 400; //Determines speed of Ball
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
				window.close();
			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space)) {
				paused = !paused;
			}
		}

		if (!paused) { //PLAYING
			pongBall.move(std::cos(ballAngle)*factor, std::sin(ballAngle)*factor);

			//CONTROLS
			//Player 1 Controls
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !(playerOnePaddle.getGlobalBounds().intersects(ceiling.getGlobalBounds())))
			{
				playerOnePaddle.move(0.f, -paddleSpeed * time); //Move in Y Plane only
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !(playerOnePaddle.getGlobalBounds().intersects(floor.getGlobalBounds())))
			{
				playerOnePaddle.move(0.f, paddleSpeed * time); //Move in Y Plane only
			}
			//Player 2 Controls
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !(playerTwoPaddle.getGlobalBounds().intersects(ceiling.getGlobalBounds())))
			{
				playerTwoPaddle.move(0.f, -paddleSpeed * time); //Move in Y Plane only
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !(playerTwoPaddle.getGlobalBounds().intersects(floor.getGlobalBounds())))
			{
				playerTwoPaddle.move(0.f, paddleSpeed * time); //Move in Y Plane only
			}

			//SCORING
			//Player 1 Score
			if (pongBall.getPosition().x > playerTwoPaddle.getPosition().x + 50) {
				playerOneScore++;
				playerOneText.setString("Player 1: " + std::to_string(playerOneScore));
				pongBall.setPosition(sf::Vector2f(screenWidth / 2, screenHeight / 2)); //Reset Ball to centre
				ballAngle = 0;
			}
			//Player 2 Score
			if (pongBall.getPosition().x < playerOnePaddle.getPosition().x - 50) {
				playerTwoScore++;
				playerTwoText.setString("Player 2: " + std::to_string(playerTwoScore));
				pongBall.setPosition(sf::Vector2f(screenWidth / 2, screenHeight / 2)); //Reset Ball to centre
				ballAngle = 180;
			}

			//BALL COLLISION
			//Borders
			if (pongBall.getGlobalBounds().intersects(ceiling.getGlobalBounds()) || pongBall.getGlobalBounds().intersects(floor.getGlobalBounds())) {
				ballAngle = -ballAngle;
			}
			//Player One Paddle
			if (pongBall.getGlobalBounds().intersects(playerOnePaddle.getGlobalBounds()) && cos(ballAngle) < 0) { //cos(ballAngle) < 0 checks that the ball is coming from the right before reflecting
				if (pongBall.getPosition().y > (playerOnePaddle.getPosition().y)) { //Reflect ball differently based on where it collides
					ballAngle = -ballAngle + 10;
				}
				else {
					ballAngle = -ballAngle - 10;
				}
			}
			//Player Two Paddle
			if (pongBall.getGlobalBounds().intersects(playerTwoPaddle.getGlobalBounds()) && cos(ballAngle) > 0) { //cos(ballAngle) > 0 checks that the ball is coming from the left before reflecting
				if (pongBall.getPosition().y > (playerTwoPaddle.getPosition().y)) { //Reflect ball differently based on where it collides
					ballAngle = -ballAngle + 10;
				}
				else if (pongBall.getGlobalBounds().intersects(playerTwoPaddle.getGlobalBounds())) {
					ballAngle = -ballAngle - 10;
				}
			}

		}

		window.clear();

		if (paused) {
			window.draw(pauseText);
		}

		window.draw(playerOnePaddle);
		window.draw(playerTwoPaddle);
		window.draw(playerOneText);
		window.draw(playerTwoText);
		window.draw(ceiling);
		window.draw(floor);
		window.draw(pongBall);
		window.display();
	}

	return 0;
}

