#include "AllScreens.h"

Doctor_Home_Screen::Doctor_Home_Screen(int w_width, int w_height) : Screen(ScreenId::doctor_home, w_width, w_height) {
	add_entity(std::make_shared<Button>(std::string("Back"), 30u, OutlineThickness, sf::Vector2f(150.0f, 80.0f), sf::Vector2f(100.0f, 110.0f), sf::Color::Black, lightRed, sf::Color::Black, ScreenId::home));

	add_entity(std::make_shared<TextBox>(std::string("Doctor : Home"), 50u, 0.0f, sf::Vector2f(1300.0f, 100.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f), 100.0f), sf::Color::White, darkYellow, sf::Color::White));

	add_entity(std::make_shared<Button>(std::string(""), 50u, OutlineThickness, sf::Vector2f(300.0f, 500.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f), 400.0f),			  sf::Color::White, bgBlue, sf::Color::Black, ScreenId::appointment,    FuncType::get_appointment_data));
	add_entity(std::make_shared<Button>(std::string(""), 50u, OutlineThickness, sf::Vector2f(300.0f, 500.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 400.0f, 400.0f),  sf::Color::White, bgBlue, sf::Color::Black, ScreenId::patient_record, FuncType::get_patient_record));
	add_entity(std::make_shared<Button>(std::string(""), 50u, OutlineThickness, sf::Vector2f(300.0f, 500.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 800.0f, 400.0f),  sf::Color::White, bgBlue, sf::Color::Black, ScreenId::my_information, FuncType::_default));
	add_entity(std::make_shared<Button>(std::string(""), 50u, OutlineThickness, sf::Vector2f(300.0f, 500.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 1200.0f, 400.0f), sf::Color::White, bgBlue, sf::Color::Black, ScreenId::_default,		FuncType::_default));

	add_entity(std::make_shared<TextBox>(std::string("Appointments"),    30u, OutlineThickness, sf::Vector2f(250.0f, 80.0f), sf::Vector2f(235.0f, 770.0f),  sf::Color::Black, darkYellow, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Patient Records"), 30u, OutlineThickness, sf::Vector2f(250.0f, 80.0f), sf::Vector2f(635.0f,770.0f),   sf::Color::Black, darkYellow, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("My Information"),  30u, OutlineThickness, sf::Vector2f(250.0f, 80.0f), sf::Vector2f(1035.0f, 770.0f), sf::Color::Black, darkYellow, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Patient History"), 30u, OutlineThickness, sf::Vector2f(250.0f, 80.0f), sf::Vector2f(1435.0f, 770.0f), sf::Color::Black, darkYellow, sf::Color::Black));

	add_entity(std::make_shared<ImageBox>(std::string("./Images/appointment.png"),    sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 50.0f, 500.0f),   sf::Vector2f(1.0f, 1.0f)));
	add_entity(std::make_shared<ImageBox>(std::string("./Images/patientRecords.png"), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 480.0f, 500.0f),  sf::Vector2f(1.0f, 1.0f)));
	add_entity(std::make_shared<ImageBox>(std::string("./Images/myInformation.png"),  sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 840.0f, 500.0f),  sf::Vector2f(0.9f, 0.9f)));
	add_entity(std::make_shared<ImageBox>(std::string("./Images/patientHistory.png"), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 1270.0f, 500.0f), sf::Vector2f(1.0f, 1.0f)));
}

std::vector<std::string> Doctor_Home_Screen::extract_form(sf::Vector2f mouse_pos) {
	return {doctor_id};
}

void Doctor_Home_Screen::fill_form(std::vector<std::string>& data) {
	doctor_id = data[0];
}