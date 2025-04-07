#include "Button.h"

Button::Button() : Entity(EntityType::button) {
	next_scene = SceneId::_default;
}

// by default the text will be aligned at the centre of the box
Button::Button(std::string textVal, unsigned charSize, float outline_thickness, sf::Vector2f buttonSize, sf::Vector2f buttonPos, sf::Color textColor, sf::Color bgColor, sf::Color outlineColor, SceneId _next_scene) : Entity(EntityType::button) {
	next_scene = _next_scene;

	button.setSize(buttonSize);
	button.setFillColor(bgColor);
	button.setOutlineThickness(outline_thickness);
	button.setOutlineColor(outlineColor);
	button.setPosition(buttonPos);
	bounding_box_size = buttonSize;
	bounding_box_pos = buttonPos;
	not_hover_color = bgColor;
	hover_color = get_comp_color(bgColor);
	not_hover_outline_color = outlineColor;
	hover_outline_color = get_comp_color(outlineColor);

	if (!font.loadFromFile("Resources/NotoSans.ttf")) {
		std::cout << "Error loading the font file\n";
		return;
	}

	text.setFont(font);
	text.setString(textVal);
	text.setFillColor(textColor);
	text.setCharacterSize(charSize);
	text.setStyle(sf::Text::Bold);
	setTextPosition(sf::Vector2f(0.0f, 0.0f));
}

// by default the text will be aligned at the centre of the box
Button::Button(std::string textVal, unsigned charSize, float outline_thickness, sf::Vector2f buttonSize, sf::Vector2f buttonPos, sf::Vector2f boundSize, sf::Vector2f boundPos, sf::Color textColor, sf::Color bgColor, sf::Color outlineColor, SceneId _next_scene) : Entity(EntityType::button) {
	next_scene = _next_scene;

	button.setSize(buttonSize);
	button.setFillColor(bgColor);
	button.setOutlineThickness(outline_thickness);
	button.setOutlineColor(outlineColor);
	button.setPosition(buttonPos);
	bounding_box_size = boundSize;
	bounding_box_pos = boundPos;
	not_hover_color = bgColor;
	hover_color = get_comp_color(bgColor);
	not_hover_outline_color = outlineColor;
	hover_outline_color = get_comp_color(outlineColor);

	if (!font.loadFromFile("Resources/NotoSans.ttf")) {
		std::cout << "Error loading the font file\n";
		return;
	}

	text.setFont(font);
	text.setString(textVal);
	text.setFillColor(textColor);
	text.setCharacterSize(charSize);
	text.setStyle(sf::Text::Bold);
	setTextPosition(sf::Vector2f(0.0f, 0.0f));
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
	setTextPosition(sf::Vector2f(0.0f, 0.0f));
}

// this position is relative the center of the textbox
void Button::setTextPosition(sf::Vector2f pos) {
	float xPos = get_center_coord(pos.x + button.getPosition().x, button.getLocalBounds().width - 2 * button.getOutlineThickness(), text.getLocalBounds().width + 2 * text.getLocalBounds().left);
	float yPos = get_center_coord(pos.y + button.getPosition().y, button.getLocalBounds().height - 2 * button.getOutlineThickness(), text.getLocalBounds().height + 2 * text.getLocalBounds().top);

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

bool Button::isMouseHover(sf::Vector2f mouse_pos){
	if ((bounding_box_pos.x <= mouse_pos.x) && (mouse_pos.x <= bounding_box_pos.x + bounding_box_size.x) && (bounding_box_pos.y <= mouse_pos.y) && (mouse_pos.y <= bounding_box_pos.y + bounding_box_size.y)) {
		return true;
	}
	else {
		return false;
	}
}

void Button::drawTo(sf::RenderWindow& window) {
	window.draw(button);
	window.draw(text);
}

SceneId Button::get_next_scene() {
	return next_scene;
}

void Button::perform_not_hover_action() {
	button.setFillColor(not_hover_color);
	button.setOutlineColor(not_hover_outline_color);
}

void Button::perform_hover_action() {
	button.setFillColor(hover_color);
	button.setOutlineColor(hover_outline_color);
}