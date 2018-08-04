#include "stdafx.h"
#include "Text.h"


Text::Text(std::string str, sf::Font font, float size, sf::Vector2f position) {
	textStr = str;
	textFont = font;
	textSize = size;
	textPosition = position;
}

sf::Text Text::CreateText() {
	sf::Text newText;
	newText.setFillColor(sf::Color::White);
	newText.setString(textStr);
	newText.setFont(textFont);
	newText.setCharacterSize(textSize);
	newText.setPosition(textPosition);
	return newText;
}