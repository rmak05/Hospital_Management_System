#include "Entity.hpp"
#include "Theme.hpp"

Entity::Entity() {
	is_active = false;
	type = EntityType::_default;
}

Entity::Entity(EntityType _type) {
	is_active = true;
	type = _type;
}

float Entity::get_center_coord(float div_x, float div_size, float box_size) {
	float box_x = (div_x + (div_size / 2.0f)) - (box_size / 2.0f);

	return box_x;
}

sf::Color Entity::get_comp_color(sf::Color _color) {
	if(_color == darkYellow)		return lightYellow;
	if(_color == lightYellow)		return darkYellow;
	if(_color == darkBlue)			return lightBlue;
	if(_color == lightBlue)			return darkBlue;
	if(_color == lightBlueConst)	return lightBlueConst;
	if(_color == darkBlue)			return bgBlue;
	if(_color == bgBlue)			return darkBlue;
	if (_color == darkRed)			return lightRed;
	if (_color == lightRed)			return darkRed;
	if (_color == bgWhite)			return bgWhite;
	if (_color == lightGrey)		return darkGrey;
	if (_color == darkGrey)			return lightGrey;
	if(_color == sf::Color::White)	return sf::Color::White;
	if(_color == sf::Color::Black)	return sf::Color::Black;

	return sf::Color::Black;
}

bool Entity::isMouseHover(sf::RenderWindow& window) {
	return false;
}

bool Entity::isMouseHover(sf::Vector2f mouse_pos) {
	return false;
}

ScreenId Entity::get_next_screen() {
	return ScreenId::_default;
}

void Entity::perform_not_hover_action() {}

void Entity::perform_hover_action() {}

void Entity::setSelected(sf::Vector2f mouse_pos) {}

void Entity::typedOn(sf::Uint32 input) {}

void Entity::blink_cursor(int curr_frame) {}

std::string Entity::getText() {
	return std::string();
}

FuncType Entity::get_func_type() {
	return FuncType::_default;
}

void Entity::setText(std::string textVal){}

void Entity::setPosition(sf::Vector2f pos){}

void Entity::setBackgroundColor(sf::Color bgColor){}

void Entity::setDoNothing(bool do_nothing) {}