#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class TextBox {

private:
	sf::RectangleShape box;
	sf::Font font;
	sf::Text text;

public:
	TextBox();
	TextBox(std::string, int, sf::Vector2f, sf::Color, sf::Color, sf::Color);

	void setTextVal(sf::String);
	void setTextColor(sf::Color);
	void setTextSize(int);
	void setFont(std::string);
	void setBoxSize(sf::Vector2f);
	void setBackgroundColor(sf::Color);
	void setOutlineColor(sf::Color);
	void setPosition(sf::Vector2f);
	void drawTo(sf::RenderWindow&);
};