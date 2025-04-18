#include "AllScreens.h"

Approve_Appointment_Screen::Approve_Appointment_Screen(int w_width, int w_height) : Screen(ScreenId::approve_appointment, w_width, w_height) {
	add_entity(std::make_shared<Button>(std::string("Back"), 30u, OutlineThickness, sf::Vector2f(150.0f, 80.0f), sf::Vector2f(100.0f, 110.0f), sf::Color::Black, lightRed, sf::Color::Black, ScreenId::patient_home));

	add_entity(std::make_shared<TextBox>(std::string("Schedule Appointment"), 50u, 0.0f, sf::Vector2f(1300.0f, 100.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f), 100.0f), sf::Color::White, darkYellow, sf::Color::White));
}

void Approve_Appointment_Screen::fill_form(std::vector<std::string>& data) {
	doctor_id = data[0];
	patient_id = data[1];
	_date = data[2];
	_time = data[3];
	room_id = data[4];

	add_entity(std::make_shared<TextBox>("Schedule Appointment on : " + _date + " , " + _time, 30u, OutlineThickness, sf::Vector2f(1000.0f, 80.0f), sf::Vector2f(300.0f, 400.0f), sf::Color::Black, lightBlue, sf::Color::Black));
	add_entity(std::make_shared<Button>(std::string("Confirm"), 30u, OutlineThickness, sf::Vector2f(300.0f, 80.0f), sf::Vector2f(600.0f, 520.0f), sf::Color::Black, lightYellow, sf::Color::Black, ScreenId::patient_home, FuncType::add_appointment));
	add_entity(std::make_shared<ImageBox>(std::string("./Images/patientLogin.png"), sf::Vector2f(1350.0f, 400.0f), sf::Vector2f(0.2f, 0.2f)));
}

std::vector<std::string> Approve_Appointment_Screen::extract_form(sf::Vector2f mouse_pos) {
	return {doctor_id, patient_id, room_id, _date, _time};
}

void Approve_Appointment_Screen::erase_form() {
	while (all_entities.size() > 2) all_entities.pop_back();
}