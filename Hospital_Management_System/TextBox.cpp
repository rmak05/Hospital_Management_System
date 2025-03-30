#include "TextBox.h"

TextBox::TextBox() {}

TextBox::TextBox(std::string textVal, int charSize, sf::Vector2f boxSize, sf::Color textColor, sf::Color bgColor, sf::Color outlineColor) {
	text.setString(textVal);
	text.setFillColor(textColor);
	text.setCharacterSize(charSize);

	box.setSize(boxSize);
	box.setFillColor(bgColor);
	box.setOutlineThickness(2);
	box.setOutlineColor(outlineColor);

	if (!font.loadFromFile("Resources/NotoSans.ttf")) {
		std::cout << "Error loading the font file\n";
		return;
	}
	text.setFont(font);
}

void TextBox::setTextVal(sf::String textVal) {
	text.setString(textVal);
}

void TextBox::setTextColor(sf::Color textColor) {
	text.setFillColor(textColor);
}

void TextBox::setTextSize(int charSize) {
	text.setCharacterSize(charSize);
}


void TextBox::setFont(std::string file) {
	if (!font.loadFromFile(file)) {
		std::cout << "Error loading the font file\n";
		return;
	}
	text.setFont(font);
}

void TextBox::setBoxSize(sf::Vector2f size) {
	box.setSize(size);
}

void TextBox::setBackgroundColor(sf::Color bgColor) {
	box.setFillColor(bgColor);
}

void TextBox::setOutlineColor(sf::Color color) {
	box.setOutlineColor(color);
}

void TextBox::setPosition(sf::Vector2f pos) {
	box.setPosition(pos);

	float xPos = (pos.x + box.getLocalBounds().width / 2) - (text.getLocalBounds().width / 2 + text.getLocalBounds().left);
	float yPos = (pos.y + box.getLocalBounds().height / 2) - (text.getLocalBounds().height / 2 + text.getLocalBounds().top);

	text.setPosition(xPos, yPos);
}

void TextBox::drawTo(sf::RenderWindow& window) {
	window.draw(box);
	window.draw(text);
}