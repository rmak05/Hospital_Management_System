#include "Screen.h"

Screen::Screen() {
	id = ScreenId::_default;
	window_width = window_height = 0;
}

Screen::Screen(ScreenId _id, int w_width, int w_height) {
	id = _id;
	window_width = w_width;
	window_height = w_height;
}

ScreenId Screen::get_next_screen(sf::Vector2f mouse_pos) {
	for (entity_ptr& _entity : all_entities) {
		if ((_entity->type == EntityType::button) && (_entity->isMouseHover(mouse_pos))) {
			return _entity->get_next_screen();
		}
	}

	return ScreenId::_default;
}

void Screen::check_mouse_hover(sf::RenderWindow& window) {
	for (entity_ptr& _entity : all_entities) {
		if (_entity->isMouseHover(window)) {
			_entity->perform_hover_action();
		}
		else {
			_entity->perform_not_hover_action();
		}
	}
}

void Screen::select_text_input(sf::Vector2f mouse_pos) {
	for (entity_ptr& _entity : all_entities) {
		if ((_entity->type == EntityType::text_input)) {
			_entity->setSelected(mouse_pos);
		}
	}
}

void Screen::check_typed_text(sf::Uint32 input) {
	for (entity_ptr& _entity : all_entities) {
		if ((_entity->type == EntityType::text_input)) {
			_entity->typedOn(input);
		}
	}
}

float Screen::get_center_coord(float div_x, float div_size, float box_size) {
	float box_x = (div_x + (div_size / 2.0f)) - (box_size / 2.0f);

	return box_x;
}

void Screen::draw_entities(sf::RenderWindow& window) {
	for (entity_ptr& _entity : all_entities) {
		_entity->drawTo(window);
	}
}

void Screen::blink_cursor(int curr_frame) {
	for (entity_ptr& _entity : all_entities) {
		if ((_entity->type == EntityType::text_input)) {
			_entity->blink_cursor(curr_frame);
		}
	}
}

void Screen::add_entity(entity_ptr _entity) {
	all_entities.push_back(_entity);
}

std::vector<std::string> Screen::callBack(sf::Vector2f mouse_pos, MYSQLDatabase& database) {
	for (entity_ptr& _entity : all_entities) {
		if ((_entity->type == EntityType::button) && (_entity->isMouseHover(mouse_pos))) {
			std::vector<std::string> form_details = extract_form();
			FuncType func_type = _entity->get_func_type();

			std::vector<std::string> data = database.callFunction(func_type, form_details);
			int dsize = (int)data.size();
			if (dsize == 0) {
				return { "-1" };
			}
			else if (dsize == 1 and data[0] == "-1") {
				erase_form();
				return { "-1" };
			}
			else if(dsize == 1 and data[0] == "0") {
				erase_form();
				return { "0" };
			}
			else if(data[dsize-1] == "1") {
				return data;
			}
		}
	}
	return { "0" };
}

std::vector<std::string> Screen::extract_form() {
	std::vector<std::string> form_details;

	for (entity_ptr& _entity : all_entities) {
		if (_entity->type == EntityType::text_input) {
			form_details.push_back(_entity->getText());
		}
	}

	return form_details;
}

void Screen::erase_form() {
	for (entity_ptr& _entity : all_entities) {
		if (_entity->type == EntityType::text_input) {
			_entity->setText(std::string(""));
		}
	}
}

void Screen::fill_form(std::vector<std::string> &data) {
	//std::cout << data.size() << "\n";
	//std::cout << "FILL FORM CALLED\n";
}