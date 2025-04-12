#include "AllScreens.h"

Appointment_Screen::Appointment_Screen(int w_width, int w_height) : Screen(ScreenId::appointment, w_width, w_height) {
	add_entity(std::make_shared<Button>(std::string("Back"), 30u, OutlineThickness, sf::Vector2f(150.0f, 80.0f), sf::Vector2f(100.0f, 110.0f), sf::Color::Black, lightRed, sf::Color::Black, ScreenId::doctor_home));

	add_entity(std::make_shared<TextBox>(std::string("Appointments"), 50u, 0.0f, sf::Vector2f(1300.0f, 100.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f), 100.0f), sf::Color::White, darkYellow, sf::Color::White));

	
	add_entity(std::make_shared<Button>(std::string("Click Me"), 30u, OutlineThickness, sf::Vector2f(200.0f, 80.0f), sf::Vector2f(get_center_coord(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f) + 150.0f, 700.0f, 200.0f), 700.0f), sf::Color::Black, lightYellow, sf::Color::Black, ScreenId::patient_appointment));

}