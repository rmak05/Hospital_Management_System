#pragma once

#include <memory>
#include <vector>
#include "Entity.h"
#include "enumScreenId.h"
#include "TextBox.h"
#include "Button.h"
#include "ImageBox.h"
#include "TextInput.h"
#include "Theme.h"
#include "MYSQLDatabase.h"

class Screen;

typedef std::shared_ptr<Screen> scene_ptr;

class Screen {
public:
	std::vector<entity_ptr> all_entities;
	ScreenId id;

	int window_width;
	int window_height;

	Screen();
	Screen(ScreenId _id, int w_width, int w_height);

	void draw_entities(sf::RenderWindow& window);
	void blink_cursor(int curr_frame);
	ScreenId get_next_screen(sf::Vector2f mouse_pos);
	void check_mouse_hover(sf::RenderWindow& window);
	void select_text_input(sf::Vector2f mouse_pos);
	void check_typed_text(sf::Uint32 input);
	std::vector<std::string> callBack(sf::Vector2f mouse_pos, MYSQLDatabase& database);
	std::vector<std::string> extract_form();
	void erase_form();
	void fill_form(std::vector<std::string> &data);

protected:
	float get_center_coord(float div_x, float div_size, float box_size);
	void add_entity(entity_ptr _entity);
};