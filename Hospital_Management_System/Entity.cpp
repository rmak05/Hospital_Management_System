#include "Entity.h"

Entity::Entity() {
	is_active = false;
	type = EntityType::_default;
}

Entity::Entity(EntityType _type) {
	is_active = true;
	type = _type;
}