#include "Button.h"

Button::Button() {}

Button::Button(std::string textVal, int charSize, sf::Vector2f buttonSize, sf::Color bgColor, sf::Color textColor) {
	text.setString(textVal);
	text.setFillColor(textColor);
	text.setCharacterSize(charSize);

	button.setSize(buttonSize);
	button.setFillColor(bgColor);

	if (!font.loadFromFile("Resources/NotoSans.ttf")) {
		std::cout << "Error loading the font file\n";
		return;
	}
	text.setFont(font);
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

void Button::setFont(std::string file) {
	if (!font.loadFromFile(file)) {
		std::cout << "Error loading the font file\n";
		return;
	}
	text.setFont(font);
}

void Button::setButtonSize(sf::Vector2f buttonSize) {
	button.setSize(buttonSize);
}

void Button::setBackgroundColor(sf::Color bgColor) {
	button.setFillColor(bgColor);
}

void Button::setPosition(sf::Vector2f pos) {
	button.setPosition(pos);

	float xPos = (pos.x + button.getLocalBounds().width / 2) - (text.getLocalBounds().width / 2 + text.getLocalBounds().left);
	float yPos = (pos.y + button.getLocalBounds().height / 2) - (text.getLocalBounds().height / 2 + text.getLocalBounds().top);

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