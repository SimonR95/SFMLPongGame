#include "stdafx.h"
#include "Menu.h"

Menu::Menu() {};

Menu::Menu(float screenWidth, float screenHeight) {
	width = screenWidth;
	height = screenHeight;
	
	menuTitle = Text("P O N G", sf::Color::White, 50, sf::Vector2f((width / 4) * 1.5, (height / 4) * 1));
	menuText.push_back(Text("Play", sf::Color::Red, 20, sf::Vector2f(width / 2, (height / 4) * 2)));
	menuText.push_back(Text("Quit", sf::Color::White, 20, sf::Vector2f(width / 2, (height / 4) * 3)));

	selectedItemIndex = 0;
}

void Menu::setFont(sf::Font& font) {
	for (int i = 0; i < menuText.size(); i++) {
		menuText[i].setFont(font);
	}
	menuTitle.setFont(font);
}

void Menu::MoveUp(){
	if (selectedItemIndex - 1 >= 0) {
		menuText[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menuText[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown() {
	if (selectedItemIndex + 1 <= (menuText.size()-1)) {
		menuText[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menuText[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

int Menu::ReturnSelectedItemIndex() {
	return selectedItemIndex;
}


void Menu::draw(sf::RenderWindow &window) {
	window.clear();
	for (int i = 0; i < menuText.size(); i++) {
		window.draw(menuText[i]);
	}
	window.draw(menuTitle);
}