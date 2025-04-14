#include "AllScreens.h"

Register_Patient_Screen::Register_Patient_Screen(int w_width, int w_height) : Screen(ScreenId::patient_register, w_width, w_height) {
	add_entity(std::make_shared<Button>(std::string("Back"), 30u, OutlineThickness, sf::Vector2f(150.0f, 80.0f), sf::Vector2f(100.0f, 110.0f), sf::Color::Black, lightRed, sf::Color::Black, ScreenId::frontdesk_home));

	add_entity(std::make_shared<TextBox>(std::string("Register Patient"), 50u, 0.0f, sf::Vector2f(1300.0f, 100.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f), 100.0f), sf::Color::White, darkYellow, sf::Color::White));

	add_entity(std::make_shared<TextBox>(std::string(""), 30u, OutlineThickness, sf::Vector2f(1000.0f, 70.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1000.0f), 280.0f), sf::Color::Black, lightBlue, sf::Color::Black, false, false));
	
	add_entity(std::make_shared<TextInput>(30u, OutlineThickness, 35, sf::Vector2f(1000.0f, 70.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1000.0f), 390.0f), sf::Color::Black, lightBlue, sf::Color::Black, false));
	add_entity(std::make_shared<TextInput>(30u, OutlineThickness, 35, sf::Vector2f(290.0f, 70.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1000.0f), 500.0f), sf::Color::Black, lightBlue, sf::Color::Black, false));
	add_entity(std::make_shared<TextInput>(30u, OutlineThickness, 35, sf::Vector2f(290.0f, 70.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1000.0f) + 710.0f, 500.0f), sf::Color::Black, lightBlue, sf::Color::Black, false));
	add_entity(std::make_shared<TextInput>(30u, OutlineThickness, 35, sf::Vector2f(1000.0f, 70.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1000.0f), 610.0f), sf::Color::Black, lightBlue, sf::Color::Black, false));
	add_entity(std::make_shared<TextInput>(30u, OutlineThickness, 35, sf::Vector2f(1000.0f, 70.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1000.0f), 720.0f), sf::Color::Black, lightBlue, sf::Color::Black, false));
	add_entity(std::make_shared<TextInput>(30u, OutlineThickness, 35, sf::Vector2f(1000.0f, 70.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1000.0f), 830.0f), sf::Color::Black, lightBlue, sf::Color::Black, false));

	add_entity(std::make_shared<TextBox>(std::string("Patient ID"), 30u, OutlineThickness, sf::Vector2f(300.0f, 80.0f), sf::Vector2f(100.0f, 280.0f), sf::Color::Black, darkBlue, sf::Color::White));
	add_entity(std::make_shared<TextBox>(std::string("Name"),       30u, OutlineThickness, sf::Vector2f(300.0f, 80.0f), sf::Vector2f(100.0f, 390.0f), sf::Color::Black, darkBlue, sf::Color::White));
	add_entity(std::make_shared<TextBox>(std::string("Age"),        30u, OutlineThickness, sf::Vector2f(300.0f, 80.0f), sf::Vector2f(100.0f, 500.0f), sf::Color::Black, darkBlue, sf::Color::White));
	add_entity(std::make_shared<TextBox>(std::string("Gender"),     30u, OutlineThickness, sf::Vector2f(300.0f, 80.0f), sf::Vector2f(810.0f, 500.0f), sf::Color::Black, darkBlue, sf::Color::White));
	add_entity(std::make_shared<TextBox>(std::string("Phone No."),  30u, OutlineThickness, sf::Vector2f(300.0f, 80.0f), sf::Vector2f(100.0f, 610.0f), sf::Color::Black, darkBlue, sf::Color::White));
	add_entity(std::make_shared<TextBox>(std::string("Address"),    30u, OutlineThickness, sf::Vector2f(300.0f, 80.0f), sf::Vector2f(100.0f, 720.0f), sf::Color::Black, darkBlue, sf::Color::White));
	add_entity(std::make_shared<TextBox>(std::string("Email"),      30u, OutlineThickness, sf::Vector2f(300.0f, 80.0f), sf::Vector2f(100.0f, 830.0f), sf::Color::Black, darkBlue, sf::Color::White));

	add_entity(std::make_shared<Button>(std::string("Register"), 30u, OutlineThickness, sf::Vector2f(200.0f, 80.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 200.0f), 960.0f), sf::Color::Black, lightYellow, sf::Color::Black, ScreenId::patient_home, FuncType::register_patient));

	add_entity(std::make_shared<ImageBox>(std::string("./Images/register.png"), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f) + 1300.0f, 300.0f), sf::Vector2f(0.12f, 0.12f)));
}

std::vector<std::string> Register_Patient_Screen::extract_form(sf::Vector2f mouse_pos) {
	std::vector<std::string> form_details;

	for (int i = 2; i <= 8; i++) {
		form_details.push_back(all_entities[i]->getText());
	}

	return form_details;
}

void Register_Patient_Screen::erase_form() {
	int aSize = (int)all_entities.size();
	for (int i = 3; i <= 8; i++) {
		if (all_entities[i]->type == EntityType::text_input) {
			all_entities[i]->setText(std::string(""));
		}
	}
}

void Register_Patient_Screen::fill_form(std::vector<std::string>& data) {
	all_entities[2]->setText(std::string(data[0]));
}