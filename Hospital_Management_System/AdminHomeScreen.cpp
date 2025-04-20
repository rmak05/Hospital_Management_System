#include "AllScreens.h"

Admin_Home_Screen::Admin_Home_Screen(int w_width, int w_height) : Screen(ScreenId::admin_home, w_width, w_height) {
	add_entity(std::make_shared<Button>(std::string("Back"), 30u, OutlineThickness, sf::Vector2f(150.0f, 80.0f), sf::Vector2f(100.0f, 110.0f), sf::Color::Black, lightRed, sf::Color::Black, ScreenId::home));

	add_entity(std::make_shared<TextBox>(std::string("Admin : Home"), 50u, 0.0f, sf::Vector2f(1300.0f, 100.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f), 100.0f), sf::Color::White, darkYellow, sf::Color::White));

	add_entity(std::make_shared<Button>(std::string(""), 50u, OutlineThickness, sf::Vector2f(400.0f, 500.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 500.0f, 400.0f),           sf::Color::White, bgBlue, sf::Color::Black, ScreenId::manage_doctor));
	//add_entity(std::make_shared<Button>(std::string(""), 50u, OutlineThickness, sf::Vector2f(400.0f, 500.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 550.0f, 400.0f),  sf::Color::White, bgBlue, sf::Color::Black, ScreenId::_default));
	//add_entity(std::make_shared<Button>(std::string(""), 50u, OutlineThickness, sf::Vector2f(400.0f, 500.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 1100.0f, 400.0f),  sf::Color::White, bgBlue, sf::Color::Black, ScreenId::_default));

	add_entity(std::make_shared<TextBox>(std::string("Manage Doctor"), 30u, OutlineThickness, sf::Vector2f(250.0f, 80.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f - 50.0f, 1500.0f) + 100.0f + 500.0f, 770.0f),   sf::Color::Black, darkYellow, sf::Color::Black));
	//add_entity(std::make_shared<TextBox>(std::string("Demo"),   30u, OutlineThickness, sf::Vector2f(250.0f, 80.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 650.0f - 25.0f, 770.0f),  sf::Color::Black, darkYellow, sf::Color::Black));
	//add_entity(std::make_shared<TextBox>(std::string("Demo"),     30u, OutlineThickness, sf::Vector2f(250.0f, 80.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 1200.0f - 25.0f, 770.0f),  sf::Color::Black, darkYellow, sf::Color::Black));

	add_entity(std::make_shared<ImageBox>(std::string("./Images/doctors.png"),     sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1450.0f) + 80.0f + 500.0f, 500.0f),   sf::Vector2f(1.0f, 1.0f)));
	//add_entity(std::make_shared<ImageBox>(std::string("./Images/demo.png"),       sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1600.0f) + 650.0f, 450.0f),  sf::Vector2f(0.6f, 0.6f)));
	//add_entity(std::make_shared<ImageBox>(std::string("./Images/demo.png"), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 1200.0f, 500.0f),  sf::Vector2f(0.4f, 0.4f)));
}