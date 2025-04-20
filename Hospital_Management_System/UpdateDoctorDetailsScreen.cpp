#include "AllScreens.h"

Update_Doctor_Details_Screen::Update_Doctor_Details_Screen(int w_width, int w_height) : Screen(ScreenId::update_doctor_details, w_width, w_height) {
	add_entity(std::make_shared<Button>(std::string("Back"), 30u, OutlineThickness, sf::Vector2f(150.0f, 80.0f), sf::Vector2f(100.0f, 110.0f), sf::Color::Black, lightRed, sf::Color::Black, ScreenId::manage_doctor));

	add_entity(std::make_shared<TextBox>(std::string("Update Doctor Details"), 50u, 0.0f, sf::Vector2f(1300.0f, 100.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f), 100.0f), sf::Color::White, darkYellow, bgWhite));

	add_entity(std::make_shared<TextBox>(std::string(""), 25u, OutlineThickness, sf::Vector2f(350.0f, 80.0f), sf::Vector2f(400.0f, 280.0f), sf::Color::Black, lightBlue, sf::Color::Black, false, false));
	add_entity(std::make_shared<TextInput>(25u, OutlineThickness, 35, sf::Vector2f(450.0f, 80.0f), sf::Vector2f(1100.0f, 280.0f), sf::Color::Black, lightBlue, sf::Color::Black, false));
	add_entity(std::make_shared<TextInput>(25u, OutlineThickness, 35, sf::Vector2f(350.0f, 80.0f), sf::Vector2f(400.0f, 390.0f), sf::Color::Black, lightBlue, sf::Color::Black, false));
	add_entity(std::make_shared<TextInput>(25u, OutlineThickness, 35, sf::Vector2f(450.0f, 80.0f), sf::Vector2f(1100.0f, 390.0f), sf::Color::Black, lightBlue, sf::Color::Black, false));
	add_entity(std::make_shared<TextInput>(25u, OutlineThickness, 35, sf::Vector2f(350.0f, 80.0f), sf::Vector2f(400.0f, 500.0f), sf::Color::Black, lightBlue, sf::Color::Black, false));
	add_entity(std::make_shared<TextInput>(25u, OutlineThickness, 35, sf::Vector2f(450.0f, 80.0f), sf::Vector2f(1100.0f, 500.0f), sf::Color::Black, lightBlue, sf::Color::Black, false));
	add_entity(std::make_shared<TextInput>(25u, OutlineThickness, 90, sf::Vector2f(1150.0f, 80.0f), sf::Vector2f(400.0f, 610.0f), sf::Color::Black, lightBlue, sf::Color::Black, false));
	add_entity(std::make_shared<TextInput>(25u, OutlineThickness, 35, sf::Vector2f(350.0f, 80.0f), sf::Vector2f(400.0f, 720.0f), sf::Color::Black, lightBlue, sf::Color::Black, false));
	add_entity(std::make_shared<TextInput>(25u, OutlineThickness, 35, sf::Vector2f(450.0f, 80.0f), sf::Vector2f(1100.0f, 720.0f), sf::Color::Black, lightBlue, sf::Color::Black, false));
	add_entity(std::make_shared<TextInput>(25u, OutlineThickness, 9, sf::Vector2f(1150.0f, 80.0f), sf::Vector2f(400.0f, 830.0f), sf::Color::Black, lightBlue, sf::Color::Black, false));

	add_entity(std::make_shared<TextBox>(std::string("Doctor ID"), 30u, OutlineThickness, sf::Vector2f(250.0f, 80.0f), sf::Vector2f(100.0f, 280.0f), sf::Color::Black, darkBlue, bgWhite));
	add_entity(std::make_shared<TextBox>(std::string("Name"),       30u, OutlineThickness, sf::Vector2f(250.0f, 80.0f), sf::Vector2f(800.0f, 280.0f), sf::Color::Black, darkBlue, bgWhite));
	add_entity(std::make_shared<TextBox>(std::string("Age"),        30u, OutlineThickness, sf::Vector2f(250.0f, 80.0f), sf::Vector2f(100.0f, 390.0f), sf::Color::Black, darkBlue, bgWhite));
	add_entity(std::make_shared<TextBox>(std::string("Gender"),     30u, OutlineThickness, sf::Vector2f(250.0f, 80.0f), sf::Vector2f(800.0f, 390.0f), sf::Color::Black, darkBlue, bgWhite));
	add_entity(std::make_shared<TextBox>(std::string("Phone No."),  30u, OutlineThickness, sf::Vector2f(250.0f, 80.0f), sf::Vector2f(100.0f, 500.0f), sf::Color::Black, darkBlue, bgWhite));
	add_entity(std::make_shared<TextBox>(std::string("Email"),      30u, OutlineThickness, sf::Vector2f(250.0f, 80.0f), sf::Vector2f(800.0f, 500.0f), sf::Color::Black, darkBlue, bgWhite));
	add_entity(std::make_shared<TextBox>(std::string("Address"),    30u, OutlineThickness, sf::Vector2f(250.0f, 80.0f), sf::Vector2f(100.0f, 610.0f), sf::Color::Black, darkBlue, bgWhite));
	add_entity(std::make_shared<TextBox>(std::string("Speciality"),    30u, OutlineThickness, sf::Vector2f(250.0f, 80.0f), sf::Vector2f(100.0f, 720.0f), sf::Color::Black, darkBlue, bgWhite));
	add_entity(std::make_shared<TextBox>(std::string("Designation"),    30u, OutlineThickness, sf::Vector2f(250.0f, 80.0f), sf::Vector2f(800.0f, 720.0f), sf::Color::Black, darkBlue, bgWhite));
	add_entity(std::make_shared<TextBox>(std::string("Salary"),    30u, OutlineThickness, sf::Vector2f(250.0f, 80.0f), sf::Vector2f(100.0f, 830.0f), sf::Color::Black, darkBlue, bgWhite));

	add_entity(std::make_shared<Button>(std::string("Update"), 30u, OutlineThickness, sf::Vector2f(200.0f, 80.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 200.0f), 960.0f), sf::Color::Black, lightYellow, sf::Color::Black, ScreenId::manage_doctor, FuncType::update_doctor));

	add_entity(std::make_shared<ImageBox>(std::string("./Images/register.png"), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f) + 1300.0f, 300.0f), sf::Vector2f(0.12f, 0.12f)));
}

std::vector<std::string> Update_Doctor_Details_Screen::extract_form(sf::Vector2f mouse_pos) {
	std::vector<std::string> form_details;

	for (int i = 2; i <= 11; i++) {
		form_details.push_back(all_entities[i]->getText());
	}

	return form_details;
}

void Update_Doctor_Details_Screen::erase_form() {
	for (int i = 2; i <= 11; i++) {
		all_entities[i]->setText(std::string(""));
	}
}

void Update_Doctor_Details_Screen::fill_form(std::vector<std::string>& data) {
	for (int i = 2; i <= 11; i++) {
		all_entities[i]->setText(data[i - 2]);
	}
}