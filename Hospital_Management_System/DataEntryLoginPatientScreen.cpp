#include "AllScreens.h"

Data_Entry_Login_Patient_Screen::Data_Entry_Login_Patient_Screen(int w_width, int w_height) : Screen(ScreenId::dataentry_login_patient, w_width, w_height) {
	add_entity(std::make_shared<Button>(std::string("Back"), 30u, OutlineThickness, sf::Vector2f(150.0f, 80.0f), sf::Vector2f(100.0f, 110.0f), sf::Color::Black, lightRed, sf::Color::Black, ScreenId::home));

	add_entity(std::make_shared<TextBox>(std::string("Patient : Login"), 50u, 0.0f, sf::Vector2f(1300.0f, 100.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f), 100.0f), sf::Color::White, darkYellow, sf::Color::White));

	add_entity(std::make_shared<TextBox>(std::string("Enter Patient ID to get Tests"), 30u, OutlineThickness, sf::Vector2f(700.0f, 80.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f) + 150.0f, 450.0f), sf::Color::Black, darkBlue, sf::Color::Black));

	add_entity(std::make_shared<TextInput>(30u, OutlineThickness, 35, sf::Vector2f(700.0f, 80.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f) + 150.0f, 570.0f), sf::Color::Black, lightBlue, sf::Color::Black, true));

	add_entity(std::make_shared<Button>(std::string("Login"), 30u, OutlineThickness, sf::Vector2f(200.0f, 80.0f), sf::Vector2f(get_center_coord(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f) + 150.0f, 700.0f, 200.0f), 700.0f), sf::Color::Black, lightYellow, sf::Color::Black, ScreenId::pending_tests, FuncType::get_patient_tests));

	add_entity(std::make_shared<ImageBox>(std::string("./Images/patientLogin.png"), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f) + 900.0f, 400.0f), sf::Vector2f(0.2f, 0.2f)));
}