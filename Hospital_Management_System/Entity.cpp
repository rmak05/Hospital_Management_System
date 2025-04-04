#include "Entity.h"

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