#include "AllScreens.h"

Admit_Appointment_Screen::Admit_Appointment_Screen(int w_width, int w_height) : Screen(ScreenId::admit_appointment, w_width, w_height) {
	add_entity(std::make_shared<Button>(std::string("Back"), 30u, OutlineThickness, sf::Vector2f(150.0f, 80.0f), sf::Vector2f(100.0f, 110.0f), sf::Color::Black, lightRed, sf::Color::Black, ScreenId::patient_appointment));

	add_entity(std::make_shared<TextBox>(std::string("Admit"), 50u, 0.0f, sf::Vector2f(1300.0f, 100.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f), 100.0f), sf::Color::White, darkYellow, sf::Color::White));

	add_entity(std::make_shared<ImageBox>(std::string("./Images/patientLogin.png"), sf::Vector2f(1050.0f, 400.0f), sf::Vector2f(0.2f, 0.2f)));

	add_entity(std::make_shared<TextBox>(std::string("Send request to admit patient"), 30u, OutlineThickness, sf::Vector2f(500.0f, 80.0f), sf::Vector2f(500.0f, 420.0f), sf::Color::Black, lightBlue, sf::Color::Black));
	
	add_entity(std::make_shared<Button>(std::string("Send"), 30u, OutlineThickness, sf::Vector2f(200.0f, 80.0f), sf::Vector2f(650.0f, 550.0f), sf::Color::Black, lightYellow, sf::Color::Black, ScreenId::patient_appointment));

}