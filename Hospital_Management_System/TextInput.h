#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class TextInput {

private:
	sf::Text textbox;
	std::ostringstream text;
	sf::RectangleShape box;
	bool isSelected = false;
	bool hasLimit = false;
	int limit;
	sf::Font font;

	void inputLogic(int);
	void deleteLastChar();

public:
	TextInput();
	TextInput(int, sf::Vector2f, sf::Color, sf::Color, sf::Color);

	void setTextSize(int);
	void setTextColor(sf::Color);
	void setBoxSize(sf::Vector2f);
	void setBackgroundColor(sf::Color);
	void setOutlineColor(sf::Color);
	void setFont(std::string);
	void setPosition(sf::Vector2f);
	void setLimit(bool);
	void setLimit(bool, int);
	void setSelected(sf::RenderWindow&);
	std::string getText();
	void drawTo(sf::RenderWindow&);
	void typedOn(sf::Event);
	bool isMouseHover(sf::RenderWindow&);
};