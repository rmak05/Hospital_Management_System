#include "AllScreens.h"

Admit_Appointment_Screen::Admit_Appointment_Screen(int w_width, int w_height) : Screen(ScreenId::admit_appointment, w_width, w_height) {
	add_entity(std::make_shared<Button>(std::string("Back"), 30u, OutlineThickness, sf::Vector2f(150.0f, 80.0f), sf::Vector2f(100.0f, 110.0f), sf::Color::Black, lightRed, sf::Color::Black, ScreenId::patient_appointment));

	add_entity(std::make_shared<TextBox>(std::string("Send Request To Admit Patient"), 50u, 0.0f, sf::Vector2f(1300.0f, 100.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f), 100.0f), sf::Color::White, darkYellow, sf::Color::White));

	add_entity(std::make_shared<TextBox>(std::string("Enter Disease"), 30u, OutlineThickness, sf::Vector2f(700.0f, 80.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f) + 150.0f, 450.0f), sf::Color::Black, darkBlue, sf::Color::Black));

	add_entity(std::make_shared<TextInput>(30u, OutlineThickness, 35, sf::Vector2f(700.0f, 80.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f) + 150.0f, 570.0f), sf::Color::Black, lightBlue, sf::Color::Black, true));

	add_entity(std::make_shared<Button>(std::string("Send"), 30u, OutlineThickness, sf::Vector2f(200.0f, 80.0f), sf::Vector2f(get_center_coord(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f) + 150.0f, 700.0f, 200.0f), 700.0f), sf::Color::Black, lightYellow, sf::Color::Black, ScreenId::patient_appointment, FuncType::admit_patient));

	add_entity(std::make_shared<ImageBox>(std::string("./Images/patientLogin.png"), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f) + 900.0f, 400.0f), sf::Vector2f(0.2f, 0.2f)));
}

void Admit_Appointment_Screen::fill_form(std::vector<std::string>& data) {
	patient_id = data[1];
	doctor_id = data[2];
}

void Admit_Appointment_Screen::erase_form() {
	all_entities[3]->setText("");
}

std::vector<std::string> Admit_Appointment_Screen::extract_form(sf::Vector2f mouse_pos) {
	return { patient_id, doctor_id, all_entities[3]->getText() };
}