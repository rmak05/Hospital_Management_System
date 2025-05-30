#include "AllScreens.hpp"

Tests_Appointment_Screen::Tests_Appointment_Screen(int w_width, int w_height) : Screen(ScreenId::tests_appointment, w_width, w_height) {
	add_entity(std::make_shared<Button>(std::string("Back"), 30u, OutlineThickness, sf::Vector2f(150.0f, 80.0f), sf::Vector2f(100.0f, 110.0f), sf::Color::Black, lightRed, sf::Color::Black, ScreenId::patient_appointment));

	add_entity(std::make_shared<TextBox>(std::string("Tests"), 50u, 0.0f, sf::Vector2f(1300.0f, 100.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f), 100.0f), sf::Color::White, darkYellow, sf::Color::White));

	add_entity(std::make_shared<ImageBox>(std::string("./Images/tests.png"), sf::Vector2f(1700.0f, 100.0f), sf::Vector2f(0.4f, 0.4f)));

	add_entity(std::make_shared<TextBox>(std::string("Test Id"),	30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(220.0f, 320.0f), sf::Color::Black, darkBlue, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Patient Id"), 30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(220.0f, 420.0f), sf::Color::Black, darkBlue, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Doctor Id"),  30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(980.0f, 420.0f), sf::Color::Black, darkBlue, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Tests"),	    30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(220.0f, 520.0f), sf::Color::Black, darkBlue, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Room"),		30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(220.0f, 620.0f), sf::Color::Black, darkBlue, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Equipment"),  30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(220.0f, 720.0f), sf::Color::Black, darkBlue, sf::Color::Black));

	add_entity(std::make_shared<TextBox>(std::string(""), 30u, OutlineThickness, sf::Vector2f(1160.0f, 60.0f), sf::Vector2f(520.0f, 320.0f),  sf::Color::Black, lightBlue, sf::Color::Black, false, false));
	add_entity(std::make_shared<TextBox>(std::string(""), 30u, OutlineThickness, sf::Vector2f(400.0f, 60.0f),  sf::Vector2f(520.0f, 420.0f),  sf::Color::Black, lightBlue, sf::Color::Black, false, false));
	add_entity(std::make_shared<TextBox>(std::string(""), 30u, OutlineThickness, sf::Vector2f(400.0f, 60.0f),  sf::Vector2f(1280.0f, 420.0f), sf::Color::Black, lightBlue, sf::Color::Black, false, false));

	add_entity(std::make_shared<TextInput>(30u, OutlineThickness, 100, sf::Vector2f(1160.0f, 60.0f),  sf::Vector2f(520.0f, 520.0f),  sf::Color::Black, lightBlue, sf::Color::Black, false));
	add_entity(std::make_shared<TextInput>(30u, OutlineThickness, 100, sf::Vector2f(1160.0f, 60.0f),  sf::Vector2f(520.0f, 620.0f),  sf::Color::Black, lightBlue, sf::Color::Black, false));
	add_entity(std::make_shared<TextInput>(30u, OutlineThickness, 100, sf::Vector2f(1160.0f, 60.0f),  sf::Vector2f(520.0f, 720.0f),  sf::Color::Black, lightBlue, sf::Color::Black, false));

	add_entity(std::make_shared<Button>(std::string("Print"), 30u, OutlineThickness, sf::Vector2f(200.0f, 80.0f), sf::Vector2f(800.0f, 840.0f), sf::Color::Black, lightYellow, sf::Color::Black, ScreenId::patient_appointment, FuncType::push_tests));
}

void Tests_Appointment_Screen::fill_form(std::vector<std::string>& data) {
	all_entities[9]->setText(data[3]);
	all_entities[10]->setText(data[1]);
	all_entities[11]->setText(data[2]);
}

void Tests_Appointment_Screen::erase_form() {
	all_entities[12]->setText("");
	all_entities[13]->setText("");
	all_entities[14]->setText("");
}

std::vector<std::string> Tests_Appointment_Screen::extract_form(sf::Vector2f mouse_pos) {
	std::vector<std::string> form_details;
	for (int i = 9; i <= 14; i++) {
		form_details.push_back(all_entities[i]->getText());
	}
	return form_details;
}