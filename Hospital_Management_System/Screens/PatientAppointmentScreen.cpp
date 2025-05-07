#include "AllScreens.hpp"

Patient_Appointment_Screen::Patient_Appointment_Screen(int w_width, int w_height) : Screen(ScreenId::patient_appointment, w_width, w_height) {
	add_entity(std::make_shared<Button>(std::string("Back"), 30u, OutlineThickness, sf::Vector2f(150.0f, 80.0f), sf::Vector2f(100.0f, 110.0f), sf::Color::Black, lightRed, sf::Color::Black, ScreenId::doctor_home));

	add_entity(std::make_shared<TextBox>(std::string("Patient Appointment"), 50u, 0.0f, sf::Vector2f(1300.0f, 100.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f), 100.0f), sf::Color::White, darkYellow, sf::Color::White));

	add_entity(std::make_shared<ImageBox>(std::string("./Images/appointment.png"), sf::Vector2f(1700.0f,100.0f), sf::Vector2f(1.0f, 1.0f)));

	add_entity(std::make_shared<TextBox>(std::string(""), 50u, 0.0f, sf::Vector2f(1500.0f, 300.0f), sf::Vector2f(200.0f, 300.0f), sf::Color::White, bgBlue, sf::Color::White));

	add_entity(std::make_shared<TextBox>(std::string("Patient Id"), 30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(220.0f, 320.0f), sf::Color::Black, darkBlue, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Name"),		30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(220.0f, 420.0f), sf::Color::Black, darkBlue, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Age"),		30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(220.0f, 520.0f), sf::Color::Black, darkBlue, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Gender"),		30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(980.0f, 520.0f), sf::Color::Black, darkBlue, sf::Color::Black));

	add_entity(std::make_shared<TextBox>(std::string(""), 30u, OutlineThickness, sf::Vector2f(1160.0f, 60.0f), sf::Vector2f(520.0f,320.0f),  sf::Color::Black, lightBlue, sf::Color::Black, false, false));
	add_entity(std::make_shared<TextBox>(std::string(""), 30u, OutlineThickness, sf::Vector2f(1160.0f, 60.0f), sf::Vector2f(520.0f,420.0f),  sf::Color::Black, lightBlue, sf::Color::Black, false, false));
	add_entity(std::make_shared<TextBox>(std::string(""), 30u, OutlineThickness, sf::Vector2f(400.0f, 60.0f),  sf::Vector2f(520.0f,520.0f),  sf::Color::Black, lightBlue, sf::Color::Black, false, false));
	add_entity(std::make_shared<TextBox>(std::string(""), 30u, OutlineThickness, sf::Vector2f(400.0f, 60.0f),  sf::Vector2f(1280.0f,520.0f), sf::Color::Black, lightBlue, sf::Color::Black, false, false));

	add_entity(std::make_shared<Button>(std::string("Prescription"), 30u, OutlineThickness, sf::Vector2f(400.0f, 80.0f), sf::Vector2f(200.0f, 700.0f),  sf::Color::Black, lightYellow, sf::Color::Black, ScreenId::presc_appointment, FuncType::get_meeting_data));
	add_entity(std::make_shared<Button>(std::string("Tests"),        30u, OutlineThickness, sf::Vector2f(400.0f, 80.0f), sf::Vector2f(750.0f, 700.0f),  sf::Color::Black, lightYellow, sf::Color::Black, ScreenId::tests_appointment, FuncType::get_meeting_data));
	add_entity(std::make_shared<Button>(std::string("Admit"),		 30u, OutlineThickness, sf::Vector2f(400.0f, 80.0f), sf::Vector2f(1300.0f, 700.0f), sf::Color::Black, lightYellow, sf::Color::Black, ScreenId::admit_appointment, FuncType::get_meeting_data));
	
	add_entity(std::make_shared<Button>(std::string("Appointment Done"), 30u, OutlineThickness, sf::Vector2f(700.0f, 80.0f), sf::Vector2f(600.0f, 850.0f), sf::Color::Black, lightYellow, sf::Color::Black, ScreenId::doctor_home, FuncType::appointment_done));
}

void Patient_Appointment_Screen::erase_form() {
	/*for (int i = 9; i <= 12; i++) {
		all_entities[i]->setText("");
	}*/
}

void Patient_Appointment_Screen::fill_form(std::vector<std::string>& data) {
	appointment_id = data[0];

	for (int i = 8; i <= 11; i++) {
		all_entities[i]->setText(data[i - 8 + 1]);
	}
}

std::vector<std::string> Patient_Appointment_Screen::extract_form(sf::Vector2f mouse_pos) {
	return { appointment_id };
}