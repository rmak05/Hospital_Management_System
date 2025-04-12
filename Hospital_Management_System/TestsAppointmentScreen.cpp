#include "AllScreens.h"

Tests_Appointment_Screen::Tests_Appointment_Screen(int w_width, int w_height) : Screen(ScreenId::tests_appointment, w_width, w_height) {
	add_entity(std::make_shared<Button>(std::string("Back"), 30u, OutlineThickness, sf::Vector2f(150.0f, 80.0f), sf::Vector2f(100.0f, 110.0f), sf::Color::Black, lightRed, sf::Color::Black, ScreenId::patient_appointment));

	add_entity(std::make_shared<TextBox>(std::string("Tests"), 50u, 0.0f, sf::Vector2f(1300.0f, 100.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f), 100.0f), sf::Color::White, darkYellow, sf::Color::White));

	add_entity(std::make_shared<ImageBox>(std::string("./Images/tests.png"), sf::Vector2f(1700.0f, 100.0f), sf::Vector2f(0.4f, 0.4f)));

	add_entity(std::make_shared<TextBox>(std::string("Test Id"),	30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(220.0f, 320.0f), sf::Color::Black, darkBlue, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Patient Id"), 30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(220.0f, 420.0f), sf::Color::Black, darkBlue, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Doctor Id"),  30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(980.0f, 420.0f), sf::Color::Black, darkBlue, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Tests"),	    30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(220.0f, 520.0f), sf::Color::Black, darkBlue, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Room"),		30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(220.0f, 620.0f), sf::Color::Black, darkBlue, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Equipment"),  30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(220.0f, 720.0f), sf::Color::Black, darkBlue, sf::Color::Black));

	add_entity(std::make_shared<TextInput>(30u, OutlineThickness, 35,  sf::Vector2f(1160.0f, 60.0f),  sf::Vector2f(520.0f, 320.0f),  sf::Color::Black, lightBlue, sf::Color::Black, false));
	add_entity(std::make_shared<TextInput>(30u, OutlineThickness, 35,  sf::Vector2f(400.0f, 60.0f),   sf::Vector2f(520.0f, 420.0f),  sf::Color::Black, lightBlue, sf::Color::Black, false));
	add_entity(std::make_shared<TextInput>(30u, OutlineThickness, 35,  sf::Vector2f(400.0f, 60.0f),   sf::Vector2f(1280.0f, 420.0f), sf::Color::Black, lightBlue, sf::Color::Black, false));
	add_entity(std::make_shared<TextInput>(30u, OutlineThickness, 100, sf::Vector2f(1160.0f, 60.0f),  sf::Vector2f(520.0f, 520.0f),  sf::Color::Black, lightBlue, sf::Color::Black, false));
	add_entity(std::make_shared<TextInput>(30u, OutlineThickness, 100, sf::Vector2f(1160.0f, 60.0f),  sf::Vector2f(520.0f, 620.0f),  sf::Color::Black, lightBlue, sf::Color::Black, false));
	add_entity(std::make_shared<TextInput>(30u, OutlineThickness, 100, sf::Vector2f(1160.0f, 60.0f),  sf::Vector2f(520.0f, 720.0f),  sf::Color::Black, lightBlue, sf::Color::Black, false));

	add_entity(std::make_shared<Button>(std::string("Print"), 30u, OutlineThickness, sf::Vector2f(200.0f, 80.0f), sf::Vector2f(800.0f, 840.0f), sf::Color::Black, lightYellow, sf::Color::Black, ScreenId::patient_appointment));
}