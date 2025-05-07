#include "AllScreens.hpp"

Patient_Details_Home_Screen::Patient_Details_Home_Screen(int w_width, int w_height) : Screen(ScreenId::patient_details_home, w_width, w_height) {

	add_entity(std::make_shared<Button>(std::string("Back"), 30u, OutlineThickness, sf::Vector2f(150.0f, 80.0f), sf::Vector2f(100.0f, 110.0f), sf::Color::Black, lightRed, sf::Color::Black, ScreenId::doctor_home));

	add_entity(std::make_shared<TextBox>(std::string("Patient Details"), 50u, 0.0f, sf::Vector2f(1300.0f, 100.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f), 100.0f), sf::Color::White, darkYellow, sf::Color::White));

	add_entity(std::make_shared<Button>(std::string(""), 50u, OutlineThickness, sf::Vector2f(400.0f, 500.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f), 400.0f), sf::Color::White, bgBlue, sf::Color::Black, ScreenId::patient_details, FuncType::get_patient_information));
	add_entity(std::make_shared<Button>(std::string(""), 50u, OutlineThickness, sf::Vector2f(400.0f, 500.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 550.0f, 400.0f), sf::Color::White, bgBlue, sf::Color::Black, ScreenId::test_history, FuncType::get_test_history));
	add_entity(std::make_shared<Button>(std::string(""), 50u, OutlineThickness, sf::Vector2f(400.0f, 500.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 1100.0f, 400.0f), sf::Color::White, bgBlue, sf::Color::Black, ScreenId::appointment_history, FuncType::get_appointment_history));

	add_entity(std::make_shared<TextBox>(std::string("Patient Information"), 30u, OutlineThickness, sf::Vector2f(340.0f, 80.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1450.0f), 770.0f), sf::Color::Black, darkYellow, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Tests History"), 30u, OutlineThickness, sf::Vector2f(340.0f, 80.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1450.0f) + 550.0f, 770.0f), sf::Color::Black, darkYellow, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Appointment History"), 30u, OutlineThickness, sf::Vector2f(340.0f, 80.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1450.0f) + 1100.0f, 770.0f), sf::Color::Black, darkYellow, sf::Color::Black));

	add_entity(std::make_shared<ImageBox>(std::string("./Images/myInformation.png"), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1450.0f) + 40.0f, 450.0f), sf::Vector2f(1.0f, 1.0f)));
	add_entity(std::make_shared<ImageBox>(std::string("./Images/tests.png"), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1600.0f) + 650.0f, 450.0f), sf::Vector2f(0.6f, 0.6f)));
	add_entity(std::make_shared<ImageBox>(std::string("./Images/appointment.png"), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 1200.0f, 450.0f), sf::Vector2f(1.2f, 1.2f)));
}

void Patient_Details_Home_Screen::fill_form(std::vector<std::string>& data) {
	patient_id = data[0];
}


std::vector<std::string> Patient_Details_Home_Screen::extract_form(sf::Vector2f mouse_pos) {
	return {patient_id};
}