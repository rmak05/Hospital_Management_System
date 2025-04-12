#include "AllScreens.h"

Home_Screen::Home_Screen(int w_width, int w_height) : Screen(ScreenId::home, w_width, w_height) {
	add_entity(std::make_shared<TextBox>(std::string("HOSPITAL  MANAGEMENT  SYSTEM"), 50u, 0.0f, sf::Vector2f(1500.0f, 100.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f), 100.0f), sf::Color::White, darkYellow, sf::Color::White));

	add_entity(std::make_shared<Button>(std::string(""), 50u, OutlineThickness, sf::Vector2f(300.0f, 500.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f), 400.0f),           sf::Color::White, bgBlue, sf::Color::Black, ScreenId::frontdesk_login));
	add_entity(std::make_shared<Button>(std::string(""), 50u, OutlineThickness, sf::Vector2f(300.0f, 500.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 400.0f, 400.0f),  sf::Color::White, bgBlue, sf::Color::Black, ScreenId::dataentry_login));
	add_entity(std::make_shared<Button>(std::string(""), 50u, OutlineThickness, sf::Vector2f(300.0f, 500.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 800.0f, 400.0f),  sf::Color::White, bgBlue, sf::Color::Black, ScreenId::doctor_login));
	add_entity(std::make_shared<Button>(std::string(""), 50u, OutlineThickness, sf::Vector2f(300.0f, 500.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 1200.0f, 400.0f), sf::Color::White, bgBlue, sf::Color::Black, ScreenId::_default));

	add_entity(std::make_shared<TextBox>(std::string("Front Desk"), 30u, OutlineThickness, sf::Vector2f(200.0f, 80.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 50.0f, 770.0f),   sf::Color::Black, darkYellow, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Data Entry"), 30u, OutlineThickness, sf::Vector2f(200.0f, 80.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 450.0f, 770.0f),  sf::Color::Black, darkYellow, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Doctor"),     30u, OutlineThickness, sf::Vector2f(200.0f, 80.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 850.0f, 770.0f),  sf::Color::Black, darkYellow, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Admin"),      30u, OutlineThickness, sf::Vector2f(200.0f, 80.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 1250.0f, 770.0f), sf::Color::Black, darkYellow, sf::Color::Black));

	add_entity(std::make_shared<ImageBox>(std::string("./Images/frontDesk.png"), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 50.0f, 500.0f),   sf::Vector2f(1.0f, 1.0f)));
	add_entity(std::make_shared<ImageBox>(std::string("./Images/dataEntry.png"), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 480.0f, 500.0f),  sf::Vector2f(0.3f, 0.3f)));
	add_entity(std::make_shared<ImageBox>(std::string("./Images/doctors.png"),   sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 850.0f, 500.0f),  sf::Vector2f(1.0f, 1.0f)));
	add_entity(std::make_shared<ImageBox>(std::string("./Images/admin.png"),     sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 1270.0f, 500.0f), sf::Vector2f(1.0f, 1.0f)));
}