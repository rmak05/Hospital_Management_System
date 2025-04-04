#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.h"

class Button;

class Button : public Entity {
private:
	sf::RectangleShape button;
	sf::Font font;
	sf::Text text;
	sf::Vector2f bounding_box_pos;
	sf::Vector2f bounding_box_size;

public:
	Button();
	Button(std::string textVal, unsigned charSize, float outline_thickness, sf::Vector2f buttonSize, sf::Vector2f buttonPos, sf::Color textColor, sf::Color bgColor, sf::Color outlineColor);

	void setTextVal(sf::String textVal);
	void setTextColor(sf::Color textColor);
	void setTextSize(int charSize);
	void setFont(std::string file);
	void setButtonSize(sf::Vector2f buttonSize);
	void setBackgroundColor(sf::Color bgColor);
	void setPosition(sf::Vector2f pos);
	void setTextPosition(sf::Vector2f pos);
	bool isMouseHover(sf::RenderWindow& window);
	void drawTo(sf::RenderWindow& window);
};