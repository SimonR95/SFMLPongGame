#pragma once
#ifndef __TEXT_H_INCLUDED__
#define __TEXT_H_INCLUDED__
#include <SFML/Graphics.hpp>

class Text : public sf::Text {
public:
	//Constructors
	Text();
	Text(std::string str, sf::Color colour, float size, sf::Vector2f position);

private:
	//Variables
	float textSize;

	//SFML Objects
	std::string textStr;
	sf::Vector2f textPosition;
};

#endif