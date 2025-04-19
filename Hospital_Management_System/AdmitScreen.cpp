#include "AllScreens.h"

Admit_Screen::Admit_Screen(int w_width, int w_height) : Screen(ScreenId::admit, w_width, w_height) {
	add_entity(std::make_shared<Button>(std::string("Back"), 30u, OutlineThickness, sf::Vector2f(150.0f, 80.0f), sf::Vector2f(100.0f, 110.0f), sf::Color::Black, lightRed, sf::Color::Black, ScreenId::patient_home));

	add_entity(std::make_shared<TextBox>(std::string("Admit Request"), 50u, 0.0f, sf::Vector2f(1300.0f, 100.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f), 100.0f), sf::Color::White, darkYellow, sf::Color::White));
	
}

void Admit_Screen::fill_form(std::vector<std::string>& data) {
	patient_id = data[0];
	if (data.size() >= 3) {
		add_entity(std::make_shared<TextBox>(std::string("Request to admit this patient from doctor_id = " + data[1]), 30u, OutlineThickness, sf::Vector2f(1000.0f, 80.0f), sf::Vector2f(300.0f, 400.0f), sf::Color::Black, lightBlue, sf::Color::Black));
		add_entity(std::make_shared<Button>(std::string("Admit"), 30u, OutlineThickness, sf::Vector2f(300.0f, 80.0f), sf::Vector2f(600.0f, 520.0f), sf::Color::Black, lightYellow, sf::Color::Black, ScreenId::choose_room, FuncType::get_room_data));
		add_entity(std::make_shared<ImageBox>(std::string("./Images/patientLogin.png"), sf::Vector2f(1350.0f,400.0f), sf::Vector2f(0.2f, 0.2f)));
	}
	else {
		add_entity(std::make_shared<TextBox>(std::string("No Admit Request"), 30u, OutlineThickness, sf::Vector2f(500.0f, 80.0f), sf::Vector2f(700.0f, 400.0f), sf::Color::Black, lightBlue, sf::Color::Black));
	}
}

std::vector<std::string> Admit_Screen::extract_form(sf::Vector2f mouse_pos) {
	return { patient_id };
}

void Admit_Screen::erase_form() {
	while (all_entities.size() > 2) all_entities.pop_back();
}