#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.h"
#include "enumScreenId.h"
#include "EnumFuncType.h"

class Button;

class Button : public Entity {
private:
	sf::RectangleShape button;
	sf::Font font;
	sf::Text text;
	sf::Vector2f bounding_box_pos;
	sf::Vector2f bounding_box_size;
	ScreenId next_screen;
	FuncType func_type;
	sf::Color not_hover_color;
	sf::Color hover_color;
	sf::Color not_hover_outline_color;
	sf::Color hover_outline_color;
	bool do_nothing;

public:
	Button();
	Button(std::string textVal, unsigned charSize, float outline_thickness, sf::Vector2f buttonSize, sf::Vector2f buttonPos, sf::Color textColor, sf::Color bgColor, sf::Color outlineColor, ScreenId _next_scene, FuncType _type = FuncType::_default, bool do_nothing = false);
	Button(std::string textVal, unsigned charSize, float outline_thickness, sf::Vector2f buttonSize, sf::Vector2f buttonPos, sf::Vector2f boundSize, sf::Vector2f boundPos, sf::Color textColor, sf::Color bgColor, sf::Color outlineColor, ScreenId _next_scene, FuncType _type = FuncType::_default, bool do_nothing = false);

	void setTextVal(sf::String textVal);
	void setTextColor(sf::Color textColor);
	void setTextSize(int charSize);
	void setFont(std::string file);
	void setButtonSize(sf::Vector2f buttonSize);
	void setBackgroundColor(sf::Color bgColor);
	void setPosition(sf::Vector2f pos);
	void setTextPosition(sf::Vector2f pos);
	bool isMouseHover(sf::RenderWindow& window);
	bool isMouseHover(sf::Vector2f mouse_pos);
	void drawTo(sf::RenderWindow& window);
	ScreenId get_next_screen();
	void perform_not_hover_action();
	void perform_hover_action();
	FuncType get_func_type();
	std::string getText();
	void setDoNothing(bool _do_nothing);
};