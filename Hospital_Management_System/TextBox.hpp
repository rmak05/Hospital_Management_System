#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.hpp"

class TextBox;

class TextBox : public Entity {
private:
	sf::RectangleShape box;
	sf::Font font;
	sf::Text text;
	sf::Vector2f bounding_box_pos;
	sf::Vector2f bounding_box_size;
	bool isCentre;

public:
	TextBox();
	TextBox(std::string textVal, unsigned charSize,float outline_thickness, sf::Vector2f boxSize, sf::Vector2f boxPos, sf::Color textColor, sf::Color bgColor, sf::Color outlineColor, bool centre = true, bool textBold = true);
	TextBox(std::string textVal, unsigned charSize,float outline_thickness, sf::Vector2f boxSize, sf::Vector2f boxPos, sf::Vector2f boundSize, sf::Vector2f boundPos, sf::Color textColor, sf::Color bgColor, sf::Color outlineColor, bool centre = true, bool textBold = true);

	void setText(std::string textVal);
	void setTextColor(sf::Color textColor);
	void setTextSize(int charSize);
	void setFont(std::string file);
	void setBoxSize(sf::Vector2f size);
	void setBackgroundColor(sf::Color bgColor);
	void setOutlineColor(sf::Color color);
	void setPosition(sf::Vector2f pos);
	void setTextPosition(sf::Vector2f pos);
	void drawTo(sf::RenderWindow& window);
	std::string getText();
};