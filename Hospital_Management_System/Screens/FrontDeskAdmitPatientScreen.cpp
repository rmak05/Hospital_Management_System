#include "AllScreens.hpp"

FrontDesk_Admit_Patient_Screen::FrontDesk_Admit_Patient_Screen(int w_width, int w_height) : Screen(ScreenId::frontdesk_admit_patient, w_width, w_height) {
	add_entity(std::make_shared<Button>(std::string("Back"), 30u, OutlineThickness, sf::Vector2f(150.0f, 80.0f), sf::Vector2f(100.0f, 110.0f), sf::Color::Black, lightRed, sf::Color::Black, ScreenId::patient_home));

	add_entity(std::make_shared<TextBox>(std::string("Admit Patient"), 50u, 0.0f, sf::Vector2f(1300.0f, 100.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f), 100.0f), sf::Color::White, darkYellow, sf::Color::White));
	
}

void FrontDesk_Admit_Patient_Screen::erase_form() {
	while (all_entities.size() > 2) all_entities.pop_back();
}

void FrontDesk_Admit_Patient_Screen::fill_form(std::vector<std::string>& data) {
	patient_id = data[0];
	room_id = data[1];
	add_entity(std::make_shared<TextBox>(std::string("Patient " + patient_id + " admitted to room_id " + room_id), 30u, OutlineThickness, sf::Vector2f(1000.0f, 80.0f), sf::Vector2f(300.0f, 400.0f), sf::Color::Black, lightBlue, sf::Color::Black));
	add_entity(std::make_shared<Button>(std::string("Admit"), 30u, OutlineThickness, sf::Vector2f(300.0f, 80.0f), sf::Vector2f(600.0f, 520.0f), sf::Color::Black, lightYellow, sf::Color::Black, ScreenId::patient_home, FuncType::frontdesk_admit_patient));
	add_entity(std::make_shared<ImageBox>(std::string("./Images/patientLogin.png"), sf::Vector2f(1350.0f, 400.0f), sf::Vector2f(0.2f, 0.2f)));
}

std::vector<std::string> FrontDesk_Admit_Patient_Screen::extract_form(sf::Vector2f mouse_pos) {
	return { patient_id, room_id };
}