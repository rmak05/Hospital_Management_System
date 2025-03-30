#include "TextInput.h"

TextInput::TextInput() {}

TextInput::TextInput(int size, sf::Vector2f boxSize, sf::Color textColor, sf::Color bgColor, sf::Color outlineColor) {
	textbox.setCharacterSize(size);
	textbox.setFillColor(textColor);

	box.setSize(boxSize);
	box.setFillColor(bgColor);
	box.setOutlineThickness(2);
	box.setOutlineColor(outlineColor);

	if (!font.loadFromFile("Resources/NotoSans.ttf")) {
		std::cout << "Error loading the font file\n";
		return;
	}
	textbox.setFont(font);
}

void TextInput::deleteLastChar() {
	std::string t = text.str();
	std::string newT = "";
	for (int i = 0; i < t.size() - 1; i++) {
		newT += t[i];
	}
	text.str("");
	text << newT;

	textbox.setString(text.str());
}

void TextInput::inputLogic(int charTyped) {
	if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY) {
		text << static_cast<char>(charTyped);
	}
	else if (charTyped == DELETE_KEY) {
		if (text.str().length() > 0) {
			deleteLastChar();
		}
	}
	textbox.setString(text.str() + "_");
}

void TextInput::setTextSize(int size) {
	textbox.setCharacterSize(size);
}

void TextInput::setTextColor(sf::Color color) {
	textbox.setFillColor(color);
}

void TextInput::setBoxSize(sf::Vector2f size) {
	box.setSize(size);
}

void TextInput::setBackgroundColor(sf::Color color) {
	box.setFillColor(color);
}

void TextInput::setOutlineColor(sf::Color color) {
	box.setOutlineColor(color);
}

void TextInput::setFont(std::string file) {
	if (!font.loadFromFile(file)) {
		std::cout << "Error loading the font file\n";
		return;
	}
	textbox.setFont(font);
}

void TextInput::setPosition(sf::Vector2f pos) {
	box.setPosition(pos);
	textbox.setPosition({pos.x+10,pos.y+10});
}

void TextInput::setLimit(bool ToF) {
	hasLimit = ToF;
}

void TextInput::setLimit(bool ToF, int lim) {
	hasLimit = ToF;
	limit = lim;
}

void TextInput::setSelected(sf::RenderWindow &window) {
	isSelected = isMouseHover(window);
	if (!isSelected) {
		if (text.str().length() > 0) {
			std::string t = text.str();
			std::string newT = "";
			for (int i = 0; i < t.size() - 1; i++) {
				newT += t[i];
			}
			textbox.setString(text.str());
		}
		else {
			textbox.setString("");
		}
		box.setOutlineThickness(2);
	}
	else {
		textbox.setString(text.str() + "_");
		box.setOutlineThickness(4);
	}
}

std::string TextInput::getText() {
	return text.str();
}

void TextInput::drawTo(sf::RenderWindow& window) {
	window.draw(box);
	window.draw(textbox);
}

void TextInput::typedOn(sf::Event input) {
	if (isSelected) {
		int charTyped = input.text.unicode;
		if (charTyped < 128) {
			if (hasLimit) {
				if (text.str().length() <= limit) {
					inputLogic(charTyped);
				}
				else if (text.str().length() > limit && charTyped == DELETE_KEY) {
					deleteLastChar();
				}
			}
			else {
				inputLogic(charTyped);
			}
		}
	}
}

bool TextInput::isMouseHover(sf::RenderWindow& window) {
	int mouseX = sf::Mouse::getPosition(window).x;
	int mouseY = sf::Mouse::getPosition(window).y;

	float btnPosX = box.getPosition().x;
	float btnPosY = box.getPosition().y;

	float btnXPosWidth = btnPosX + box.getLocalBounds().width;
	float btnYPosHeight = btnPosY + box.getLocalBounds().height;

	if (mouseX < btnXPosWidth && mouseX > btnPosX && mouseY < btnYPosHeight && mouseY > btnPosY) {
		box.setOutlineThickness(4);
		return true;
	}
	if(!isSelected)
		box.setOutlineThickness(2);
	return false;
}