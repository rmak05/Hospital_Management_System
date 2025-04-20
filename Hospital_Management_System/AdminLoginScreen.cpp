#include "AllScreens.h"

Admin_Login_Screen::Admin_Login_Screen(int w_width, int w_height) : Screen(ScreenId::admin_login, w_width, w_height) {
	add_entity(std::make_shared<Button>(std::string("Back"), 30u, OutlineThickness, sf::Vector2f(150.0f, 80.0f), sf::Vector2f(100.0f, 110.0f), sf::Color::Black, lightRed, sf::Color::Black, ScreenId::home));

	add_entity(std::make_shared<TextBox>(std::string("Admin : Login"), 50u, 0.0f, sf::Vector2f(1300.0f, 100.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f), 100.0f), sf::Color::White, darkYellow, sf::Color::White));

	add_entity(std::make_shared<TextBox>(std::string("Enter Offical ID"), 30u, OutlineThickness, sf::Vector2f(700.0f, 80.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f) + 150.0f, 450.0f), sf::Color::Black, darkBlue, sf::Color::Black));

	add_entity(std::make_shared<TextInput>(30u, OutlineThickness, 35, sf::Vector2f(700.0f, 80.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f) + 150.0f, 570.0f), sf::Color::Black, lightBlue, sf::Color::Black, true));

	add_entity(std::make_shared<Button>(std::string("Login"), 30u, OutlineThickness, sf::Vector2f(200.0f, 80.0f), sf::Vector2f(get_center_coord(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f) + 150.0f, 700.0f, 200.0f), 700.0f), sf::Color::Black, lightYellow, sf::Color::Black, ScreenId::admin_home));

	add_entity(std::make_shared<ImageBox>(std::string("./Images/admin.png"), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f) + 1000.0f, 450.0f), sf::Vector2f(1.4f, 1.4f)));
}