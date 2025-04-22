#include "AllScreens.hpp"

Appointment_History_Screen::Appointment_History_Screen(int w_width, int w_height) : Screen(ScreenId::appointment_history, w_width, w_height) {
	add_entity(std::make_shared<Button>(std::string("Back"), 30u, OutlineThickness, sf::Vector2f(150.0f, 80.0f), sf::Vector2f(100.0f, 110.0f), sf::Color::Black, lightRed, sf::Color::Black, ScreenId::patient_details_home));

	add_entity(std::make_shared<TextBox>(std::string("Appointment History"), 50u, 0.0f, sf::Vector2f(1300.0f, 100.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f), 100.0f), sf::Color::White, darkYellow, sf::Color::White));

	entity_pos = {sf::Vector2f(450.0f, 250.0f), sf::Vector2f(450.0f, 455.0f), sf::Vector2f(450.0f, 660.0f), sf::Vector2f(450.0f, 865.0f)};
	curr_entity_index = 0;

	scroll_window_size = sf::Vector2f(1300.0f, 800.0f);
	scroll_window_pos = sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f), 250.0f);
}

std::vector<std::string> Appointment_History_Screen::extract_form(sf::Vector2f mouse_pos) {
	std::vector<std::string> form_details;
	int index = 0;

	for (entity_ptr _entity : all_entities) {
		if ((_entity->type == EntityType::button) && (_entity->isMouseHover(mouse_pos))) {
			if((_entity->getText() == "Back")) continue;
			std::string test_id = all_entities[index + 1]->getText();
			form_details.push_back(test_id.substr(17));

			break;
		}

		index++;
	}

	return form_details;
}

void Appointment_History_Screen::erase_form() {
	while(all_entities.size() > 2) all_entities.pop_back();
}

void Appointment_History_Screen::fill_form(std::vector<std::string>& data) {
	int dsize = ((int)data.size()) - 1;
	float xcoord = get_center_coord(LEFT_MARGIN, (window_width - 2 * LEFT_MARGIN) * 1.0f, 1020.0f);
	float ycoord = 250.0f;

	for (int i = 0; i < dsize; i++) {
		curr_entity_index = 1;

		add_entity(std::make_shared<Button>(std::string(""), 30u, 8.0f, sf::Vector2f(1020.0f, 145.0f), sf::Vector2f(xcoord, ycoord), sf::Color::Black, lightBlueConst, lightGrey, ScreenId::presc_given, FuncType::get_presc_data));

		add_entity(std::make_shared<TextBox>(std::string("Appointment ID : ") + data[i++], 30u, 0.0f, sf::Vector2f(500.0f, 65.0f), sf::Vector2f(xcoord + 7, ycoord + 5), sf::Color::Black, lightBlueConst, bgWhite, false));
		add_entity(std::make_shared<TextBox>(std::string("Appointment Date : ") + data[i++], 30u, 0.0f, sf::Vector2f(500.0f, 65.0f), sf::Vector2f(xcoord + 7, ycoord + 75), sf::Color::Black, lightBlueConst, bgWhite));
		add_entity(std::make_shared<TextBox>(std::string("Time : ") + data[i++], 30u, 0.0f, sf::Vector2f(500.0f, 65.0f), sf::Vector2f(xcoord + 513, ycoord + 75), sf::Color::Black, lightBlueConst, bgWhite));

		ycoord += 145 + 60;
	}

	add_entity(std::make_shared<TextBox>(std::string(""), 30u, 5.0f, sf::Vector2f(30.0f, 760.0f), sf::Vector2f(xcoord + 1120, 250.0f), sf::Color::Black, bgBlue, sf::Color::Black));

	int entity_count = (((int)all_entities.size()) - 3) / 4;
	float scroll_bar_height = (4.0f / std::max(4, entity_count)) * 760.0f - 10;

	add_entity(std::make_shared<TextBox>(std::string(""), 30u, 5.0f, sf::Vector2f(20.0f, scroll_bar_height), sf::Vector2f(xcoord + 1120 + 5, 250.0f + 5), darkBlue, darkBlue, darkBlue));

	scroll_entities(0);
}

void Appointment_History_Screen::scroll_entities(int delta) {
	int entity_count = (((int)all_entities.size()) - 4) / 4;

	if(entity_count <= 4) return;
	//if(delta == 0) return;
	if ((curr_entity_index == 1) && (delta > 0)) return;
	if ((curr_entity_index + 3 >= entity_count) && (delta < 0)) return;

	curr_entity_index -= delta;
	curr_entity_index = std::max(1, curr_entity_index);
	curr_entity_index = std::min(entity_count - 3, curr_entity_index);

	for (int i = 1; i <= entity_count; i++) {
		if ((curr_entity_index <= i) && (i <= curr_entity_index + 3)) {
			float xcoord = entity_pos[i - curr_entity_index].x;
			float ycoord = entity_pos[i - curr_entity_index].y;
			all_entities[1 + (i - 1) * 4 + 1]->setPosition(sf::Vector2f(xcoord, ycoord));
			all_entities[1 + (i - 1) * 4 + 2]->setPosition(sf::Vector2f(xcoord + 7, ycoord + 5));
			all_entities[1 + (i - 1) * 4 + 3]->setPosition(sf::Vector2f(xcoord + 513, ycoord + 5));
			all_entities[1 + (i - 1) * 4 + 4]->setPosition(sf::Vector2f(xcoord + 7, ycoord + 75));
		}
		else {
			float xcoord = (-1000.0f);
			float ycoord = (-1000.0f);
			all_entities[1 + (i - 1) * 4 + 1]->setPosition(sf::Vector2f(xcoord, ycoord));
			all_entities[1 + (i - 1) * 4 + 2]->setPosition(sf::Vector2f(xcoord, ycoord));
			all_entities[1 + (i - 1) * 4 + 3]->setPosition(sf::Vector2f(xcoord, ycoord));
			all_entities[1 + (i - 1) * 4 + 4]->setPosition(sf::Vector2f(xcoord, ycoord));
		}
	}

	float xcoord = get_center_coord(LEFT_MARGIN, (window_width - 2 * LEFT_MARGIN) * 1.0f, 1020.0f) + 1120 + 5;
	float ycoord = 250.0f + (760.0f / entity_count) * (curr_entity_index - 1) + 5;
	all_entities.back()->setPosition(sf::Vector2f(xcoord, ycoord));
}