#include "AllScreens.hpp"

Schedule_Appointment_Screen::Schedule_Appointment_Screen(int w_width, int w_height) : Screen(ScreenId::schedule_appointment, w_width, w_height) {
	add_entity(std::make_shared<Button>(std::string("Back"), 30u, OutlineThickness, sf::Vector2f(150.0f, 80.0f), sf::Vector2f(100.0f, 110.0f), sf::Color::Black, lightRed, sf::Color::Black, ScreenId::patient_home));

	add_entity(std::make_shared<TextBox>(std::string("Schedule Appointment"), 50u, 0.0f, sf::Vector2f(1300.0f, 100.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f), 100.0f), sf::Color::White, darkYellow, sf::Color::White));

	entity_pos = {sf::Vector2f(450.0f, 455.0f), sf::Vector2f(450.0f, 660.0f), sf::Vector2f(450.0f, 865.0f)};
	curr_entity_index = 0;

	scroll_window_size = sf::Vector2f(1300.0f, 800.0f);
	scroll_window_pos = sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f), 250.0f);
}

std::vector<std::string> Schedule_Appointment_Screen::extract_form(sf::Vector2f mouse_pos) {
	std::vector<std::string> form_details;
	int index = 0;

	for (entity_ptr _entity : all_entities) {
		if ((_entity->type == EntityType::button) && (_entity->isMouseHover(mouse_pos))) {
			if((_entity->getText() == "Back")) continue;

			if ((_entity->getText() == "Enter")) {
				form_details.push_back(all_entities[3]->getText());

				break;
			}

			std::string doctor_id = all_entities[index + 1]->getText();
			form_details.push_back(doctor_id.substr(12));

			break;
		}

		index++;
	}

	form_details.push_back(patient_id);

	return form_details;
}

void Schedule_Appointment_Screen::erase_form() {
	while(all_entities.size() > 2) all_entities.pop_back();
}

void Schedule_Appointment_Screen::fill_form(std::vector<std::string>& data) {
	int dsize = ((int)data.size()) - 2;
	float xcoord = get_center_coord(LEFT_MARGIN, (window_width - 2 * LEFT_MARGIN) * 1.0f, 1020.0f);
	float ycoord = 455.0f;

	patient_id = data[dsize + 2 - 2];

	add_entity(std::make_shared<TextBox>(std::string("Doctor ID"),       30u, OutlineThickness, sf::Vector2f(300.0f, 80.0f), sf::Vector2f(xcoord + 50.0f - 20.0f, 300.0f), sf::Color::Black, darkBlue, bgWhite));
	add_entity(std::make_shared<TextInput>(30u, OutlineThickness, 20, sf::Vector2f(350.0f, 80.0f), sf::Vector2f(xcoord + 400.0f - 20.0f, 300.0f), sf::Color::Black, lightBlue, sf::Color::Black, false));
	add_entity(std::make_shared<Button>(std::string("Enter"), 30u, OutlineThickness, sf::Vector2f(200.0f, 80.0f), sf::Vector2f(xcoord + 800.0f - 20.0f, 300.0f), sf::Color::Black, lightYellow, sf::Color::Black, ScreenId::appointment_slots, FuncType::get_appointment_slots));

	for (int i = 0; i < dsize; i++) {
		curr_entity_index = 1;

		add_entity(std::make_shared<Button>(std::string(""), 25u, 8.0f, sf::Vector2f(1020.0f, 145.0f), sf::Vector2f(xcoord, ycoord), sf::Color::Black, lightBlueConst, lightGrey, ScreenId::appointment_slots, FuncType::get_appointment_slots));

		add_entity(std::make_shared<TextBox>(std::string("Doctor ID : ") + data[i++], 25u, 0.0f, sf::Vector2f(500.0f, 65.0f), sf::Vector2f(xcoord + 7, ycoord + 5), sf::Color::Black, lightBlueConst, bgWhite, false));
		add_entity(std::make_shared<TextBox>(std::string("Doctor Name : ") + data[i++], 25u, 0.0f, sf::Vector2f(500.0f, 65.0f), sf::Vector2f(xcoord + 513, ycoord + 5), sf::Color::Black, lightBlueConst, bgWhite, false));
		add_entity(std::make_shared<TextBox>(std::string("Speciality : ") + data[i++], 25u, 0.0f, sf::Vector2f(500.0f, 65.0f), sf::Vector2f(xcoord + 7, ycoord + 75), sf::Color::Black, lightBlueConst, bgWhite, false));
		add_entity(std::make_shared<TextBox>(std::string("Gender : ") + data[i++], 25u, 0.0f, sf::Vector2f(500.0f, 65.0f), sf::Vector2f(xcoord + 513, ycoord + 75), sf::Color::Black, lightBlueConst, bgWhite, false));

		ycoord += 145 + 60;
	}

	add_entity(std::make_shared<TextBox>(std::string(""), 30u, 5.0f, sf::Vector2f(30.0f, 555.0f), sf::Vector2f(xcoord + 1120, 455.0f), sf::Color::Black, bgBlue, sf::Color::Black));

	int entity_count = (((int)all_entities.size()) - 6) / 5;
	float scroll_bar_height = (3.0f / std::max(3, entity_count)) * 555.0f - 10;

	add_entity(std::make_shared<TextBox>(std::string(""), 30u, 5.0f, sf::Vector2f(20.0f, scroll_bar_height), sf::Vector2f(xcoord + 1120 + 5, 250.0f + 5), darkBlue, darkBlue, darkBlue));

	scroll_entities(0);
}

void Schedule_Appointment_Screen::scroll_entities(int delta) {
	int entity_count = (((int)all_entities.size()) - 7) / 5;

	if(entity_count <= 3) return;
	//if(delta == 0) return;
	if ((curr_entity_index == 1) && (delta > 0)) return;
	if ((curr_entity_index + 2 >= entity_count) && (delta < 0)) return;

	curr_entity_index -= delta;
	curr_entity_index = std::max(1, curr_entity_index);
	curr_entity_index = std::min(entity_count - 2, curr_entity_index);

	for (int i = 1; i <= entity_count; i++) {
		if ((curr_entity_index <= i) && (i <= curr_entity_index + 2)) {
			float xcoord = entity_pos[i - curr_entity_index].x;
			float ycoord = entity_pos[i - curr_entity_index].y;
			all_entities[4 + (i - 1) * 5 + 1]->setPosition(sf::Vector2f(xcoord, ycoord));
			all_entities[4 + (i - 1) * 5 + 2]->setPosition(sf::Vector2f(xcoord + 7, ycoord + 5));
			all_entities[4 + (i - 1) * 5 + 3]->setPosition(sf::Vector2f(xcoord + 513, ycoord + 5));
			all_entities[4 + (i - 1) * 5 + 4]->setPosition(sf::Vector2f(xcoord + 7, ycoord + 75));
			all_entities[4 + (i - 1) * 5 + 5]->setPosition(sf::Vector2f(xcoord + 513, ycoord + 75));
		}
		else {
			float xcoord = (-1000.0f);
			float ycoord = (-1000.0f);
			all_entities[4 + (i - 1) * 5 + 1]->setPosition(sf::Vector2f(xcoord, ycoord));
			all_entities[4 + (i - 1) * 5 + 2]->setPosition(sf::Vector2f(xcoord, ycoord));
			all_entities[4 + (i - 1) * 5 + 3]->setPosition(sf::Vector2f(xcoord, ycoord));
			all_entities[4 + (i - 1) * 5 + 4]->setPosition(sf::Vector2f(xcoord, ycoord));
			all_entities[4 + (i - 1) * 5 + 5]->setPosition(sf::Vector2f(xcoord, ycoord));
		}
	}

	float xcoord = get_center_coord(LEFT_MARGIN, (window_width - 2 * LEFT_MARGIN) * 1.0f, 1020.0f) + 1120 + 5;
	float ycoord = 455.0f + (555.0f / entity_count) * (curr_entity_index - 1) + 5;
	all_entities.back()->setPosition(sf::Vector2f(xcoord, ycoord));
}