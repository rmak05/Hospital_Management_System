#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "Entity_Scene_Types.h"

class Entity;
//enum class EntityType;
typedef std::shared_ptr<Entity> entity_ptr;

//enum class EntityType {
//	_default	= (-1),
//	text_box	= 0,
//	button		= 1,
//	image_box   = 2
//};

class Entity {
public:
	bool is_active;
	//size_t id;
	EntityType type;

	Entity();
	Entity(EntityType _type);

	virtual void drawTo(sf::RenderWindow& window) = 0;
	virtual bool isMouseHover(sf::Vector2f mouse_pos) const = 0;
	virtual SceneId get_next_scene() = 0;

	//bool check_is_active() const;
	//const EntityType get_type() const;
	//const size_t get_id() const;
	// void destroy();

protected:
	// assume a box in a div
	float get_center_coord(float div_x, float div_size, float box_size);
};