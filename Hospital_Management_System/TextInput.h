#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "Entity.h"

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class TextInput;

class TextInput : public Entity {
private:
	sf::RectangleShape box;
	sf::Text textbox;
	sf::Font font;
	std::ostringstream text;
	bool isSelected;
	bool hasLimit;
	int limit;
	bool isCentre;
	sf::Color not_hover_color;
	sf::Color hover_color;
	sf::Color not_hover_outline_color;
	sf::Color hover_outline_color;

	void inputLogic(int charTyped);
	void deleteLastChar();

public:
	TextInput();
	TextInput(unsigned charSize, float outline_thickness, int _limit, sf::Vector2f boxSize, sf::Vector2f boxPos, sf::Color textColor, sf::Color bgColor, sf::Color outlineColor, bool centre);

	void setTextSize(int size);
	void setTextPosition();
	void setTextColor(sf::Color color);
	void setBoxSize(sf::Vector2f size);
	void setBackgroundColor(sf::Color color);
	void setOutlineColor(sf::Color color);
	void setFont(std::string file);
	void setPosition(sf::Vector2f pos);
	void setLimit(bool ToF);
	void setLimit(bool ToF, int lim);
	void setSelected(sf::Vector2f mouse_pos);
	std::string getText();
	void drawTo(sf::RenderWindow& window);
	void typedOn(sf::Uint32 input);
	bool isMouseHover(sf::RenderWindow& window);
	bool isMouseHover(sf::Vector2f mouse_pos);
	void perform_not_hover_action();
	void perform_hover_action();
	void blink_cursor(int curr_frame);
};