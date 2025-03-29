#include "Button.h"

Button::Button() {}

Button::Button(std::string textVal = "Button", int charSize = 30, sf::Vector2f buttonSize = { 10,10 }, sf::Color bgColor = sf::Color::Green, sf::Color textColor = sf::Color::Black) {
	text.setString(textVal);
	text.setFillColor(textColor);
	text.setCharacterSize(charSize);

	button.setSize(buttonSize);
	button.setFillColor(bgColor);
}

void Button::setTextVal(sf::String textVal) {
	text.setString(textVal);
}

void Button::setTextColor(sf::Color textColor) {
	text.setFillColor(textColor);
}

void Button::setTextSize(int charSize) {
	text.setCharacterSize(charSize);
}

void Button::setFont(sf::Font& font) {
	text.setFont(font);
}

void Button::setButtonSize(sf::Vector2f buttonSize) {
	button.setSize(buttonSize);
}

void Button::setBgColor(sf::Color bgColor) {
	button.setFillColor(bgColor);
}

void Button::setPosition(sf::Vector2f pos) {
	button.setPosition(pos);

	float xPos = (pos.x + button.getLocalBounds().width / 4) - (text.getLocalBounds().width / 4);
	float yPos = (pos.y + button.getLocalBounds().height / 4) - (text.getLocalBounds().height / 4);

	text.setPosition(xPos, yPos);
}

bool Button::isMouseHover(sf::RenderWindow& window) {
	int mouseX = sf::Mouse::getPosition(window).x;
	int mouseY = sf::Mouse::getPosition(window).y;

	float btnPosX = button.getPosition().x;
	float btnPosY = button.getPosition().y;

	float btnXPosWidth = btnPosX + button.getLocalBounds().width;
	float btnYPosHeight = btnPosY + button.getLocalBounds().height;

	if (mouseX < btnXPosWidth && mouseX > btnPosX && mouseY < btnYPosHeight && mouseY > btnPosY) {
		return true;
	}

	return false;
}

void Button::drawTo(sf::RenderWindow& window) {
	window.draw(button);
	window.draw(text);
}

