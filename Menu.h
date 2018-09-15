#pragma once
#ifndef __MENU_H_INCLUDED__
#define __MENU_H_INCLUDED__
#include "SFML/Graphics.hpp"
#include "Text.h"

class Menu {
public:
	//Constructor
	Menu();
	Menu(float screenWidth, float screenHeight);
	
	//Methods
	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int ReturnSelectedItemIndex();
	void setFont(sf::Font &font);

private:
	int selectedItemIndex;
	float width;
	float height;
	std::vector<Text> menuText;
	Text menuTitle;
};

#endif