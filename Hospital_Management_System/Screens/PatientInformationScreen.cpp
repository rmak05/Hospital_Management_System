#include "AllScreens.hpp"

Patient_Information_Screen::Patient_Information_Screen(int w_width, int w_height) : Screen(ScreenId::patient_information, w_width, w_height) {
	add_entity(std::make_shared<Button>(std::string("Back"), 30u, OutlineThickness, sf::Vector2f(150.0f, 80.0f), sf::Vector2f(100.0f, 110.0f), sf::Color::Black, lightRed, sf::Color::Black, ScreenId::patient_home));

	add_entity(std::make_shared<TextBox>(std::string("Patient Information"), 50u, 0.0f, sf::Vector2f(1300.0f, 100.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f), 100.0f), sf::Color::White, darkYellow, sf::Color::White));

	add_entity(std::make_shared<ImageBox>(std::string("./Images/register.png"), sf::Vector2f(1700.0f, 100.0f), sf::Vector2f(0.07f, 0.07f)));

	add_entity(std::make_shared<TextBox>(std::string("Patient Id"), 30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(220.0f, 320.0f), sf::Color::Black, darkBlue, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Doctor Id"),  30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(980.0f, 320.0f), sf::Color::Black, darkBlue, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Name"),       30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(220.0f, 420.0f), sf::Color::Black, darkBlue, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Age"),		30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(220.0f, 520.0f), sf::Color::Black, darkBlue, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Gender"),		30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(980.0f, 520.0f), sf::Color::Black, darkBlue, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Room Id"),	30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(220.0f, 620.0f), sf::Color::Black, darkBlue, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Disease"),	30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(980.0f, 620.0f), sf::Color::Black, darkBlue, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Phone No."),	30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(220.0f, 720.0f), sf::Color::Black, darkBlue, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Address"),	30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(220.0f, 820.0f), sf::Color::Black, darkBlue, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Email"),		30u, 0.0f, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(220.0f, 920.0f), sf::Color::Black, darkBlue, sf::Color::Black));

	add_entity(std::make_shared<TextBox>(std::string(""), 30u, OutlineThickness, sf::Vector2f(400.0f, 60.0f),  sf::Vector2f(520.0f, 320.0f),  sf::Color::Black, lightBlue, sf::Color::Black, false, false));
	add_entity(std::make_shared<TextBox>(std::string(""), 30u, OutlineThickness, sf::Vector2f(400.0f, 60.0f),  sf::Vector2f(1280.0f, 320.0f), sf::Color::Black, lightBlue, sf::Color::Black, false, false));
	add_entity(std::make_shared<TextBox>(std::string(""), 30u, OutlineThickness, sf::Vector2f(1160.0f, 60.0f), sf::Vector2f(520.0f, 420.0f),  sf::Color::Black, lightBlue, sf::Color::Black, false, false));
	add_entity(std::make_shared<TextBox>(std::string(""), 30u, OutlineThickness, sf::Vector2f(400.0f, 60.0f),  sf::Vector2f(520.0f, 520.0f),  sf::Color::Black, lightBlue, sf::Color::Black, false, false));
	add_entity(std::make_shared<TextBox>(std::string(""), 30u, OutlineThickness, sf::Vector2f(400.0f, 60.0f),  sf::Vector2f(1280.0f, 520.0f), sf::Color::Black, lightBlue, sf::Color::Black, false, false));
	add_entity(std::make_shared<TextBox>(std::string(""), 30u, OutlineThickness, sf::Vector2f(400.0f, 60.0f),  sf::Vector2f(520.0f, 620.0f),  sf::Color::Black, lightBlue, sf::Color::Black, false, false));
	add_entity(std::make_shared<TextBox>(std::string(""), 30u, OutlineThickness, sf::Vector2f(400.0f, 60.0f),  sf::Vector2f(1280.0f, 620.0f), sf::Color::Black, lightBlue, sf::Color::Black, false, false));
	add_entity(std::make_shared<TextBox>(std::string(""), 30u, OutlineThickness, sf::Vector2f(1160.0f, 60.0f), sf::Vector2f(520.0f, 720.0f),  sf::Color::Black, lightBlue, sf::Color::Black, false, false));
	add_entity(std::make_shared<TextBox>(std::string(""), 30u, OutlineThickness, sf::Vector2f(1160.0f, 60.0f), sf::Vector2f(520.0f, 820.0f),  sf::Color::Black, lightBlue, sf::Color::Black, false, false));
	add_entity(std::make_shared<TextBox>(std::string(""), 30u, OutlineThickness, sf::Vector2f(1160.0f, 60.0f), sf::Vector2f(520.0f, 920.0f),  sf::Color::Black, lightBlue, sf::Color::Black, false, false));
}

void Patient_Information_Screen::erase_form() {
	for (int i = 13; i <= 22; i++) {
		all_entities[i]->setText("");
	}
}

void Patient_Information_Screen::fill_form(std::vector<std::string>& data) {
	all_entities[13]->setText(data[0]);
	all_entities[14]->setText(data[7]);
	all_entities[15]->setText(data[1]);
	all_entities[16]->setText(data[2]);
	all_entities[17]->setText(data[3]);
	all_entities[18]->setText(data[8]);
	all_entities[19]->setText(data[9]);
	all_entities[20]->setText(data[4]);
	all_entities[21]->setText(data[5]);
	all_entities[22]->setText(data[6]);
}