#include "AllScreens.h"

Push_Test_Results_Screen::Push_Test_Results_Screen(int w_width, int w_height) : Screen(ScreenId::push_test_results, w_width, w_height) {
	add_entity(std::make_shared<Button>(std::string("Back"), 30u, OutlineThickness, sf::Vector2f(150.0f, 80.0f), sf::Vector2f(100.0f, 110.0f), sf::Color::Black, lightRed, sf::Color::Black, ScreenId::dataentry_login_patient));

	add_entity(std::make_shared<TextBox>(std::string("Push Test Results"), 50u, 0.0f, sf::Vector2f(1300.0f, 100.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f), 100.0f), sf::Color::White, darkYellow, sf::Color::White));

	add_entity(std::make_shared<TextBox>(std::string("Test Id"), 30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(220.0f, 320.0f), sf::Color::Black, darkBlue, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Patient Id"), 30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(220.0f, 420.0f), sf::Color::Black, darkBlue, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Doctor Id"), 30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(980.0f, 420.0f), sf::Color::Black, darkBlue, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Room Id"), 30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(220.0f, 520.0f), sf::Color::Black, darkBlue, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Equipment"), 30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(980.0f, 520.0f), sf::Color::Black, darkBlue, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Test"), 30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(220.0f, 620.0f), sf::Color::Black, darkBlue, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Date"), 30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(220.0f, 720.0f), sf::Color::Black, darkBlue, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Time"), 30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(980.0f, 720.0f), sf::Color::Black, darkBlue, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Results"), 30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(220.0f, 820.0f), sf::Color::Black, darkBlue, sf::Color::Black));

	add_entity(std::make_shared<TextBox>(std::string(""), 30u, OutlineThickness, sf::Vector2f(1160.0f, 60.0f), sf::Vector2f(520.0f, 320.0f), sf::Color::Black, lightBlue, sf::Color::Black, false, false));
	add_entity(std::make_shared<TextBox>(std::string(""), 30u, OutlineThickness, sf::Vector2f(400.0f, 60.0f), sf::Vector2f(520.0f, 420.0f),  sf::Color::Black, lightBlue, sf::Color::Black, false, false));
	add_entity(std::make_shared<TextBox>(std::string(""), 30u, OutlineThickness, sf::Vector2f(400.0f, 60.0f), sf::Vector2f(1280.0f, 420.0f), sf::Color::Black, lightBlue, sf::Color::Black, false, false));
	add_entity(std::make_shared<TextBox>(std::string(""), 30u, OutlineThickness, sf::Vector2f(400.0f, 60.0f), sf::Vector2f(520.0f, 520.0f),  sf::Color::Black, lightBlue, sf::Color::Black, false, false));
	add_entity(std::make_shared<TextBox>(std::string(""), 30u, OutlineThickness, sf::Vector2f(400.0f, 60.0f), sf::Vector2f(1280.0f, 520.0f), sf::Color::Black, lightBlue, sf::Color::Black, false, false));
	add_entity(std::make_shared<TextBox>(std::string(""), 30u, OutlineThickness, sf::Vector2f(1160.0f, 60.0f), sf::Vector2f(520.0f, 620.0f), sf::Color::Black, lightBlue, sf::Color::Black, false, false));
	add_entity(std::make_shared<TextBox>(std::string(""), 30u, OutlineThickness, sf::Vector2f(400.0f, 60.0f), sf::Vector2f(520.0f, 720.0f),  sf::Color::Black, lightBlue, sf::Color::Black, false, false));
	add_entity(std::make_shared<TextBox>(std::string(""), 30u, OutlineThickness, sf::Vector2f(400.0f, 60.0f), sf::Vector2f(1280.0f, 720.0f), sf::Color::Black, lightBlue, sf::Color::Black, false, false));
	
	add_entity(std::make_shared<TextInput>(30u, OutlineThickness, 100, sf::Vector2f(1160.0f, 60.0f), sf::Vector2f(520.0f, 820.0f), sf::Color::Black, lightBlue, sf::Color::Black, false));

	add_entity(std::make_shared<Button>(std::string("Push"), 30u, OutlineThickness, sf::Vector2f(200.0f, 80.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 200.0f), 920.0f), sf::Color::Black, lightYellow, sf::Color::Black, ScreenId::dataentry_login_patient, FuncType::push_test_data));

	add_entity(std::make_shared<ImageBox>(std::string("./Images/dataEntry.png"), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1400.0f) + 1430.0f, 100.0f), sf::Vector2f(0.4f, 0.4f)));
}

std::vector<std::string> Push_Test_Results_Screen::extract_form(sf::Vector2f mouse_pos) {

	std::vector<std::string> form_details;
	form_details.push_back(all_entities[11]->getText());
	form_details.push_back(all_entities[19]->getText());
	return form_details;
}

void Push_Test_Results_Screen::erase_form() {
	for (int i = 11; i <= 19; i++) {
		all_entities[i]->setText("");
	}
}

void Push_Test_Results_Screen::fill_form(std::vector<std::string>& data) {
	for (int i = 11; i <= 19; i++) {
		all_entities[i]->setText(data[i - 11]);
	}
}