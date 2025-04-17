#include "AllScreens.h"

Choose_Room_Screen::Choose_Room_Screen(int w_width, int w_height) : Screen(ScreenId::choose_room, w_width, w_height) {
	add_entity(std::make_shared<TextBox>(std::string("Choose Room"), 50u, 0.0f, sf::Vector2f(1300.0f, 100.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f), 100.0f), sf::Color::White, darkYellow, sf::Color::White));

	add_entity(std::make_shared<TextBox>(std::string(""), 50u, 0.0f, sf::Vector2f(1500.0f, 500.0f), sf::Vector2f(200.0f, 400.0f), sf::Color::Black, bgBlue, sf::Color::Black));

	std::string str = "P101";
	for (int j = 1; j <= 5; j++) {
		for (int i = 1; i <= 15; i++) {
			str[1] = j + '0';
			str[2] = (i / 10) + '0';
			str[3] = (i % 10) + '0';
			add_entity(std::make_shared<Button>(std::string(str), 25u, OutlineThickness, sf::Vector2f(80.0f, 80.0f), sf::Vector2f(210.0f + ((i - 1) * 1.0f * (100)), 410.0f + ((j - 1) * 1.0f * (100))), sf::Color::Black, darkBlue, sf::Color::Black, ScreenId::frontdesk_admit_patient, FuncType::get_room_patient_id));
		}
	}
}

void Choose_Room_Screen::fill_form(std::vector<std::string>& data) {
	patient_id = data[75];
	for (int j = 1; j <= 5; j++) {
		for (int i = 1; i <= 15; i++) {
			if (data[((j - 1) * 15) + (i - 1)] == "0") {
				all_entities[((j - 1) * 15) + (i - 1) + 2]->setBackgroundColor(darkYellow);
				all_entities[((j - 1) * 15) + (i - 1) + 2]->setDoNothing(true);

			}
			else {
				all_entities[((j - 1) * 15) + (i - 1) + 2]->setBackgroundColor(darkBlue);
				all_entities[((j - 1) * 15) + (i - 1) + 2]->setDoNothing(false);
			}
		}
	}
}

std::vector<std::string> Choose_Room_Screen::extract_form(sf::Vector2f mouse_pos) {
	int x_coord = int(mouse_pos.x / 100) - 1;
	int y_coord = int(mouse_pos.y / 100) - 3;
	std::string room_id = all_entities[((y_coord - 1) * 15) + (x_coord - 1) + 2]->getText();
	return { patient_id, room_id };
}

void Choose_Room_Screen::erase_form() {
	
}