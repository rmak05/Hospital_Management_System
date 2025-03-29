#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Button {

private:
	sf::RectangleShape button;
	sf::Text text;

public:
	Button();
	Button(std::string, int, sf::Vector2f, sf::Color, sf::Color);
	void setTextVal(sf::String);
	void setTextColor(sf::Color);
	void setTextSize(int);
	void setFont(sf::Font&);
	void setButtonSize(sf::Vector2f);
	void setBgColor(sf::Color);
	void setPosition(sf::Vector2f);
	bool isMouseHover(sf::RenderWindow&);
	void drawTo(sf::RenderWindow&);
};