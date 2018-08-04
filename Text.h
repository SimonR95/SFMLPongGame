#pragma once
#include <SFML/Graphics.hpp>

class Text {
public:
	Text(std::string str, sf::Font font, float size, sf::Vector2f position);
	sf::Text CreateText();

private:
	std::string textStr;
	sf::Font textFont;
	float textSize;
	sf::Vector2f textPosition;
};