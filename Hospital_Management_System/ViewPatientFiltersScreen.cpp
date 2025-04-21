#include "AllScreens.h"

View_Patient_Filters_Screen::View_Patient_Filters_Screen(int w_width, int w_height) : Screen(ScreenId::view_patient_filters, w_width, w_height) {
	add_entity(std::make_shared<Button>(std::string("Back"), 30u, OutlineThickness, sf::Vector2f(150.0f, 80.0f), sf::Vector2f(100.0f, 110.0f), sf::Color::Black, lightRed, sf::Color::Black, ScreenId::manage_patient));

	add_entity(std::make_shared<TextBox>(std::string("View Patients"), 50u, 0.0f, sf::Vector2f(1300.0f, 100.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f), 100.0f), sf::Color::White, darkYellow, sf::Color::White));

	add_entity(std::make_shared<TextInput>(25u, OutlineThickness, 5, sf::Vector2f(350.0f, 80.0f), sf::Vector2f(500.0f, 280.0f), sf::Color::Black, lightBlue, sf::Color::Black, false));
	add_entity(std::make_shared<TextInput>(25u, OutlineThickness, 5, sf::Vector2f(450.0f, 80.0f), sf::Vector2f(1200.0f, 280.0f), sf::Color::Black, lightBlue, sf::Color::Black, false));
	add_entity(std::make_shared<TextInput>(25u, OutlineThickness, 5, sf::Vector2f(350.0f, 80.0f), sf::Vector2f(500.0f, 390.0f), sf::Color::Black, lightBlue, sf::Color::Black, false));
	add_entity(std::make_shared<TextInput>(25u, OutlineThickness, 5, sf::Vector2f(350.0f, 80.0f), sf::Vector2f(500.0f, 500.0f), sf::Color::Black, lightBlue, sf::Color::Black, false));
	add_entity(std::make_shared<TextInput>(25u, OutlineThickness, 30, sf::Vector2f(1150.0f, 80.0f), sf::Vector2f(500.0f, 610.0f), sf::Color::Black, lightBlue, sf::Color::Black, false));

	add_entity(std::make_shared<TextBox>(std::string("Min. Age"), 30u, OutlineThickness, sf::Vector2f(250.0f, 80.0f), sf::Vector2f(200.0f, 280.0f), sf::Color::Black, darkBlue, bgWhite));
	add_entity(std::make_shared<TextBox>(std::string("Max. Age"), 30u, OutlineThickness, sf::Vector2f(250.0f, 80.0f), sf::Vector2f(900.0f, 280.0f), sf::Color::Black, darkBlue, bgWhite));
	add_entity(std::make_shared<TextBox>(std::string("Gender"),  30u, OutlineThickness, sf::Vector2f(250.0f, 80.0f), sf::Vector2f(200.0f, 390.0f), sf::Color::Black, darkBlue, bgWhite));
	add_entity(std::make_shared<TextBox>(std::string("Room ID"),  30u, OutlineThickness, sf::Vector2f(250.0f, 80.0f), sf::Vector2f(200.0f, 500.0f), sf::Color::Black, darkBlue, bgWhite));
	add_entity(std::make_shared<TextBox>(std::string("Disease"),    30u, OutlineThickness, sf::Vector2f(250.0f, 80.0f), sf::Vector2f(200.0f, 610.0f), sf::Color::Black, darkBlue, bgWhite));

	add_entity(std::make_shared<Button>(std::string("Search"), 30u, OutlineThickness, sf::Vector2f(200.0f, 80.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 200.0f), 800.0f), sf::Color::Black, lightYellow, sf::Color::Black, ScreenId::view_patient, FuncType::view_patient));
}

std::vector<std::string> View_Patient_Filters_Screen::extract_form(sf::Vector2f mouse_pos) {
	std::vector<std::string> form_details;

	for (int i = 2; i <= 6; i++) {
		form_details.push_back(all_entities[i]->getText());
	}

	return form_details;
}

void View_Patient_Filters_Screen::erase_form() {
	for (int i = 2; i <= 6; i++) {
		all_entities[i]->setText(std::string(""));
	}
}

//void View_Doctor_Filters_Screen::fill_form(std::vector<std::string>& data) {
//	all_entities[2]->setText(std::string(data[0]));
//}