#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "enumEntityType.h"
#include "enumScreenId.h"
#include "enumFuncType.h"

class Entity;
typedef std::shared_ptr<Entity> entity_ptr;

class Entity {
public:
	bool is_active;
	EntityType type;

	Entity();
	Entity(EntityType _type);

	virtual void drawTo(sf::RenderWindow& window) = 0;
	virtual bool isMouseHover(sf::RenderWindow& window);
	virtual bool isMouseHover(sf::Vector2f mouse_pos);
	virtual void perform_not_hover_action();
	virtual void perform_hover_action();
	virtual void setSelected(sf::Vector2f mouse_pos);
	virtual void typedOn(sf::Uint32 input);
	virtual void blink_cursor(int curr_frame);
	virtual ScreenId get_next_screen();
	virtual std::string getText();
	virtual FuncType get_func_type();

protected:
	float get_center_coord(float div_x, float div_size, float box_size);
	sf::Color get_comp_color(sf::Color _color);	
};