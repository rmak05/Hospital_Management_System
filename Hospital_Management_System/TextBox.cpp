#include "TextBox.h"

TextBox::TextBox() : Entity(EntityType::text_box){}

// by default the text will be aligned at the centre of the box
TextBox::TextBox(std::string textVal, unsigned charSize, float outline_thickness, sf::Vector2f boxSize, sf::Vector2f boxPos, sf::Color textColor, sf::Color bgColor, sf::Color outlineColor) : Entity(EntityType::text_box) {
	box.setSize(boxSize);
	box.setFillColor(bgColor);
	box.setOutlineThickness(outline_thickness);
	box.setOutlineColor(outlineColor);
	box.setPosition(boxPos);

	if (!font.loadFromFile("Resources/NotoSans.ttf")) {
		std::cout << "Error loading the font file\n";
		return;
	}

	text.setFont(font);
	text.setString(textVal);
	text.setFillColor(textColor);
	text.setCharacterSize(charSize);
	setTextPosition(sf::Vector2f(0.0f, 0.0f));
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
	setTextPosition(sf::Vector2f(0.0f, 0.0f));
}

// this position is relative the center of the textbox
void TextBox::setTextPosition(sf::Vector2f pos) {
	float xPos = get_center_coord(pos.x + box.getPosition().x, box.getLocalBounds().width - 2 * box.getOutlineThickness(), text.getLocalBounds().width + 2 * text.getLocalBounds().left);
	float yPos = get_center_coord(pos.y + box.getPosition().y, box.getLocalBounds().height - 2 * box.getOutlineThickness(), text.getLocalBounds().height + 2 * text.getLocalBounds().top);

	text.setPosition(xPos, yPos);
}

void TextBox::drawTo(sf::RenderWindow& window) {
	window.draw(box);
	window.draw(text);
}