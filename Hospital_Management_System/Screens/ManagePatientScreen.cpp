#include "AllScreens.hpp"

Manage_Patient_Screen::Manage_Patient_Screen(int w_width, int w_height) : Screen(ScreenId::manage_patient, w_width, w_height) {
	add_entity(std::make_shared<Button>(std::string("Back"), 30u, OutlineThickness, sf::Vector2f(150.0f, 80.0f), sf::Vector2f(100.0f, 110.0f), sf::Color::Black, lightRed, sf::Color::Black, ScreenId::admin_home));

	add_entity(std::make_shared<TextBox>(std::string("Manage Patients"), 50u, 0.0f, sf::Vector2f(1300.0f, 100.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f), 100.0f), sf::Color::White, darkYellow, sf::Color::White));

	//add_entity(std::make_shared<Button>(std::string(""), 50u, OutlineThickness, sf::Vector2f(300.0f, 500.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f), 400.0f),           sf::Color::White, bgBlue, sf::Color::Black, ScreenId::register_doctor, FuncType::get_doctor_id));
	//add_entity(std::make_shared<Button>(std::string(""), 50u, OutlineThickness, sf::Vector2f(300.0f, 500.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 400.0f, 400.0f),  sf::Color::White, bgBlue, sf::Color::Black, ScreenId::delete_doctor));
	//add_entity(std::make_shared<Button>(std::string(""), 50u, OutlineThickness, sf::Vector2f(300.0f, 500.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 800.0f, 400.0f),  sf::Color::White, bgBlue, sf::Color::Black, ScreenId::update_doctor));
	add_entity(std::make_shared<Button>(std::string(""), 50u, OutlineThickness, sf::Vector2f(300.0f, 500.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 1200.0f - 700.0f, 400.0f), sf::Color::White, bgBlue, sf::Color::Black, ScreenId::view_patient_filters));

	//add_entity(std::make_shared<TextBox>(std::string("Add Doctor"), 30u, OutlineThickness, sf::Vector2f(250.0f, 80.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 50.0f - 25.0f, 770.0f),   sf::Color::Black, darkYellow, sf::Color::Black));
	//add_entity(std::make_shared<TextBox>(std::string("Delete Doctor"), 30u, OutlineThickness, sf::Vector2f(250.0f, 80.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 450.0f - 25.0f, 770.0f),  sf::Color::Black, darkYellow, sf::Color::Black));
	//add_entity(std::make_shared<TextBox>(std::string("Update Doctor"),     30u, OutlineThickness, sf::Vector2f(250.0f, 80.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 850.0f - 25.0f, 770.0f),  sf::Color::Black, darkYellow, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("View Patients"),      30u, OutlineThickness, sf::Vector2f(250.0f, 80.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 1250.0f - 25.0f - 700.0f, 770.0f), sf::Color::Black, darkYellow, sf::Color::Black));

	//add_entity(std::make_shared<ImageBox>(std::string("./Images/admin.png"), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 80.0f, 500.0f),   sf::Vector2f(1.0f, 1.0f)));
	//add_entity(std::make_shared<ImageBox>(std::string("./Images/admin.png"), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 480.0f, 500.0f),  sf::Vector2f(1.0f, 1.0f)));
	//add_entity(std::make_shared<ImageBox>(std::string("./Images/admin.png"),   sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 880.0f, 500.0f),  sf::Vector2f(1.0f, 1.0f)));
	add_entity(std::make_shared<ImageBox>(std::string("./Images/admin.png"),     sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 1280.0f - 700.0f, 500.0f), sf::Vector2f(1.0f, 1.0f)));
}