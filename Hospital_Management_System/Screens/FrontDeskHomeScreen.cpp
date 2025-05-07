#include "AllScreens.hpp"

Front_Desk_Home_Screen::Front_Desk_Home_Screen(int w_width, int w_height) : Screen(ScreenId::frontdesk_home, w_width, w_height) {
	add_entity(std::make_shared<Button>(std::string("Back"), 30u, OutlineThickness, sf::Vector2f(150.0f, 80.0f), sf::Vector2f(100.0f, 110.0f), sf::Color::Black, lightRed, sf::Color::Black, ScreenId::home));

	add_entity(std::make_shared<TextBox>(std::string("Front Desk : Home"), 50u, 0.0f, sf::Vector2f(1300.0f, 100.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f), 100.0f), sf::Color::White, darkYellow, sf::Color::White));

	add_entity(std::make_shared<Button>(std::string(""), 50u, OutlineThickness, sf::Vector2f(400.0f, 500.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f), 400.0f),           sf::Color::White, bgBlue, sf::Color::Black, ScreenId::patient_register, FuncType::generate_patient_id));
	add_entity(std::make_shared<Button>(std::string(""), 50u, OutlineThickness, sf::Vector2f(400.0f, 500.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 550.0f, 400.0f),  sf::Color::White, bgBlue, sf::Color::Black, ScreenId::update_login_patient));
	add_entity(std::make_shared<Button>(std::string(""), 50u, OutlineThickness, sf::Vector2f(400.0f, 500.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 1100.0f, 400.0f),  sf::Color::White, bgBlue, sf::Color::Black, ScreenId::patient_login));

	add_entity(std::make_shared<TextBox>(std::string("Register"), 30u, OutlineThickness, sf::Vector2f(200.0f, 80.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 100.0f, 770.0f),   sf::Color::Black, darkYellow, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Update"),   30u, OutlineThickness, sf::Vector2f(200.0f, 80.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 650.0f, 770.0f),  sf::Color::Black, darkYellow, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Login"),     30u, OutlineThickness, sf::Vector2f(200.0f, 80.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 1200.0f, 770.0f),  sf::Color::Black, darkYellow, sf::Color::Black));

	add_entity(std::make_shared<ImageBox>(std::string("./Images/register.png"),     sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1450.0f) + 100.0f, 450.0f),   sf::Vector2f(0.08f, 0.08f)));
	add_entity(std::make_shared<ImageBox>(std::string("./Images/update.png"),       sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1600.0f) + 650.0f, 450.0f),  sf::Vector2f(0.6f, 0.6f)));
	add_entity(std::make_shared<ImageBox>(std::string("./Images/loginPatient.png"), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 1200.0f, 500.0f),  sf::Vector2f(0.1f, 0.1f)));
}