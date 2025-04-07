#include "TextInput.h"

TextInput::TextInput() : Entity(EntityType::text_input) {
	isSelected = false;
	hasLimit = false;
	limit = 0;
}

TextInput::TextInput(unsigned charSize, float outline_thickness, int _limit, sf::Vector2f boxSize, sf::Vector2f boxPos, sf::Color textColor, sf::Color bgColor, sf::Color outlineColor) : Entity(EntityType::text_input) {
	isSelected = false;
	hasLimit = true;
	limit = _limit;

	box.setSize(boxSize);
	box.setFillColor(bgColor);
	box.setOutlineThickness(outline_thickness);
	box.setOutlineColor(outlineColor);
	box.setPosition(boxPos);
	
	not_hover_color = bgColor;
	hover_color = get_comp_color(bgColor);
	not_hover_outline_color = outlineColor;
	hover_outline_color = get_comp_color(outlineColor);

	if (!font.loadFromFile("Resources/NotoSans.ttf")) {
		std::cout << "Error loading the font file\n";
		return;
	}

	textbox.setFont(font);
	textbox.setFillColor(textColor);
	textbox.setCharacterSize(charSize);
	//textbox.setStyle(sf::Text::Bold);
	textbox.setPosition(boxPos);
	// below is just dummy text to intitalize textbox,
	// otherwise, while centering the text vertically inside the box, text.size is giving zero
	// hence, text is not being center aligned vertically
	// giving an inital text gives it some size and centering is being done properly
	// this doesn't seem to alter any other logic which is great !!!
	// but do check this once if necessary
	textbox.setString("A");
	setTextPosition();
	textbox.setString("");
}

void TextInput::setTextPosition() {
	float xPos = box.getPosition().x + 10.0f;
	float yPos = get_center_coord(box.getPosition().y, box.getLocalBounds().height - 2 * box.getOutlineThickness(), textbox.getLocalBounds().height + 2 * textbox.getLocalBounds().top);

	textbox.setPosition(xPos, yPos);
}

void TextInput::deleteLastChar() {
	std::string t = text.str();
	std::string newT = "";
	int t_size = (int)t.size();
	for (int i = 0; i < t_size - 1; i++) {
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
	textbox.setString(text.str() + "|");
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
			int t_size = (int)t.size();
			for (int i = 0; i < t_size - 1; i++) {
				newT += t[i];
			}
			textbox.setString(text.str());
		}
		else {
			textbox.setString("");
		}
		//box.setOutlineThickness(2);
	}
	else {
		textbox.setString(text.str() + "|");
		//box.setOutlineThickness(4);
	}
}

void TextInput::setSelected(sf::Vector2f mouse_pos) {
	isSelected = isMouseHover(mouse_pos);
	if (!isSelected) {
		if (text.str().length() > 0) {
			std::string t = text.str();
			std::string newT = "";
			int t_size = (int)t.size();
			for (int i = 0; i < t_size - 1; i++) {
				newT += t[i];
			}
			textbox.setString(text.str());
		}
		else {
			textbox.setString("");
			//box.setOutlineThickness(2);
		}
		textbox.setStyle(sf::Text::Regular);
	}
	else {
		textbox.setString(text.str() + "|");
		textbox.setStyle(sf::Text::Bold);
		//box.setOutlineThickness(4);
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

void TextInput::typedOn(sf::Uint32 input) {
	if (isSelected) {
		int charTyped = (int)input;
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

	if (isSelected) {
		return true;
		//box.setOutlineThickness(2);
	}
	else if (mouseX < btnXPosWidth && mouseX > btnPosX && mouseY < btnYPosHeight && mouseY > btnPosY) {
		//box.setOutlineThickness(4);
		return true;
	}
	else if (!isSelected) {
		return false;
		//box.setOutlineThickness(2);
	}
	return false;
}

bool TextInput::isMouseHover(sf::Vector2f mouse_pos){
	if ((box.getPosition().x <= mouse_pos.x) && (mouse_pos.x <= box.getPosition().x + box.getLocalBounds().width) && (box.getPosition().y <= mouse_pos.y) && (mouse_pos.y <= box.getPosition().y + box.getLocalBounds().height)) {
		return true;
	}
	else {
		return false;
	}
}

void TextInput::perform_not_hover_action() {
	box.setFillColor(not_hover_color);
	//box.setOutlineColor(not_hover_outline_color);
};

void TextInput::perform_hover_action() {
	box.setFillColor(hover_color);
	//box.setOutlineColor(hover_outline_color);
}

void TextInput::blink_cursor(int curr_frame) {
	if(!isSelected) return;

	if(curr_frame % 60 < 30) textbox.setString(text.str());
	else textbox.setString(text.str() + "|");
}