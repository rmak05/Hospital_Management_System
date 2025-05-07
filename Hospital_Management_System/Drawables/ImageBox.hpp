#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.hpp"

class ImageBox;

class ImageBox : public Entity {
private:
	sf::Texture texture;
	sf::Sprite sprite;

public:
	ImageBox();
	ImageBox(std::string imageFile, sf::Vector2f pos, sf::Vector2f factor);

	void setPosition(sf::Vector2f pos);
	void movePosition(sf::Vector2f offset);
	void scaleImage(sf::Vector2f factor);
	void drawTo(sf::RenderWindow& window);
};