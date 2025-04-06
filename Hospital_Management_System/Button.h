#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.h"
#include "Scene.h"

class Button;

class Button : public Entity {
private:
	sf::RectangleShape button;
	sf::Font font;
	sf::Text text;
	sf::Vector2f bounding_box_pos;
	sf::Vector2f bounding_box_size;
	SceneId next_scene;
	sf::Color not_hover_color;
	sf::Color hover_color;
	sf::Color not_hover_outline_color;
	sf::Color hover_outline_color;

public:
	Button();
	Button(std::string textVal, unsigned charSize, float outline_thickness, sf::Vector2f buttonSize, sf::Vector2f buttonPos, sf::Color textColor, sf::Color bgColor, sf::Color outlineColor, SceneId _next_scene);
	Button(std::string textVal, unsigned charSize, float outline_thickness, sf::Vector2f buttonSize, sf::Vector2f buttonPos, sf::Vector2f boundSize, sf::Vector2f boundPos, sf::Color textColor, sf::Color bgColor, sf::Color outlineColor, SceneId _next_scene);

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
	SceneId get_next_scene();
	void perform_not_hover_action();
	void perform_hover_action();
};