#include "Entity.h"
#include "Theme.h"

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
	if(_color == darkYellow) return lightYellow;
	if(_color == lightYellow) return darkYellow;
	if(_color == darkBlue) return lightBlue;
	if(_color == lightBlue) return darkBlue;
	if(_color == darkBlue) return bgBlue;
	if(_color == bgBlue) return darkBlue;
	if(_color == sf::Color::Black) return sf::Color::White;
	if(_color == sf::Color::White) return sf::Color::Black;

	return sf::Color::Black;
}

bool Entity::isMouseHover(sf::RenderWindow& window) {
	return false;
}

bool Entity::isMouseHover(sf::Vector2f mouse_pos) {
	return false;
}

SceneId Entity::get_next_scene() {
	return SceneId::_default;
}

void Entity::perform_not_hover_action() {}

void Entity::perform_hover_action() {}

void Entity::setSelected(sf::Vector2f mouse_pos) {}

void Entity::typedOn(sf::Uint32 input) {}