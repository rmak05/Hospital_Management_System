#include "AllScreens.h"

Patient_Home_Screen::Patient_Home_Screen(int w_width, int w_height) : Screen(ScreenId::patient_home, w_width, w_height) {
	add_entity(std::make_shared<Button>(std::string("Back"), 30u, OutlineThickness, sf::Vector2f(150.0f, 80.0f), sf::Vector2f(100.0f, 110.0f), sf::Color::Black, lightRed, sf::Color::Black, ScreenId::frontdesk_home));

	add_entity(std::make_shared<TextBox>(std::string("Front Desk Operations"), 50u, 0.0f, sf::Vector2f(1300.0f, 100.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1300.0f), 100.0f), sf::Color::White, darkYellow, sf::Color::White));

	add_entity(std::make_shared<TextBox>(std::string(""),			30u, 0.0f, sf::Vector2f(1000.0f, 700.0f), sf::Vector2f(100.0f, 300.0f), sf::Color::Black, bgBlue,	sf::Color::White));
	add_entity(std::make_shared<TextBox>(std::string("Patient Id"), 30u, 0.0f, sf::Vector2f(260.0f, 60.0f),	  sf::Vector2f(120.0f, 320.0f),	sf::Color::Black, darkBlue, sf::Color::White));
	add_entity(std::make_shared<TextBox>(std::string("Name"),		30u, 0.0f, sf::Vector2f(260.0f, 60.0f),	  sf::Vector2f(120.0f, 420.0f),	sf::Color::Black, darkBlue, sf::Color::White));
	add_entity(std::make_shared<TextBox>(std::string("Age"),		30u, 0.0f, sf::Vector2f(160.0f, 60.0f),   sf::Vector2f(120.0f, 520.0f),	sf::Color::Black, darkBlue, sf::Color::White));
	add_entity(std::make_shared<TextBox>(std::string("Gender"),		30u, 0.0f, sf::Vector2f(160.0f, 60.0f),   sf::Vector2f(620.0f, 520.0f), sf::Color::Black, darkBlue, sf::Color::White));
	add_entity(std::make_shared<TextBox>(std::string("Phone No."),  30u, 0.0f, sf::Vector2f(260.0f, 60.0f),   sf::Vector2f(120.0f, 620.0f),	sf::Color::Black, darkBlue, sf::Color::White));
	add_entity(std::make_shared<TextBox>(std::string("Doctor"),		30u, 0.0f, sf::Vector2f(260.0f, 60.0f),   sf::Vector2f(120.0f, 720.0f),	sf::Color::Black, darkBlue, sf::Color::White));
	add_entity(std::make_shared<TextBox>(std::string("Disease"),    30u, 0.0f, sf::Vector2f(260.0f, 60.0f),   sf::Vector2f(120.0f, 820.0f),	sf::Color::Black, darkBlue, sf::Color::White));
	add_entity(std::make_shared<TextBox>(std::string("Room No."),   30u, 0.0f, sf::Vector2f(260.0f, 60.0f),   sf::Vector2f(120.0f, 920.0f),	sf::Color::Black, darkBlue, sf::Color::White));

	add_entity(std::make_shared<TextBox>(std::string(""), 30u, OutlineThickness, sf::Vector2f(660.0f, 60.0f), sf::Vector2f(420.0f, 320.0f), sf::Color::Black, lightBlue, sf::Color::Black, false, false));
	add_entity(std::make_shared<TextBox>(std::string(""), 30u, OutlineThickness, sf::Vector2f(660.0f, 60.0f), sf::Vector2f(420.0f, 420.0f), sf::Color::Black, lightBlue, sf::Color::Black, false, false));
	add_entity(std::make_shared<TextBox>(std::string(""), 30u, OutlineThickness, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(320.0f, 520.0f), sf::Color::Black, lightBlue, sf::Color::Black, false, false));
	add_entity(std::make_shared<TextBox>(std::string(""), 30u, OutlineThickness, sf::Vector2f(260.0f, 60.0f), sf::Vector2f(820.0f, 520.0f), sf::Color::Black, lightBlue, sf::Color::Black, false, false));
	add_entity(std::make_shared<TextBox>(std::string(""), 30u, OutlineThickness, sf::Vector2f(660.0f, 60.0f), sf::Vector2f(420.0f, 620.0f), sf::Color::Black, lightBlue, sf::Color::Black, false, false));
	add_entity(std::make_shared<TextBox>(std::string(""), 30u, OutlineThickness, sf::Vector2f(660.0f, 60.0f), sf::Vector2f(420.0f, 720.0f), sf::Color::Black, lightBlue, sf::Color::Black, false, false));
	add_entity(std::make_shared<TextBox>(std::string(""), 30u, OutlineThickness, sf::Vector2f(660.0f, 60.0f), sf::Vector2f(420.0f, 820.0f), sf::Color::Black, lightBlue, sf::Color::Black, false, false));
	add_entity(std::make_shared<TextBox>(std::string(""), 30u, OutlineThickness, sf::Vector2f(660.0f, 60.0f), sf::Vector2f(420.0f, 920.0f), sf::Color::Black, lightBlue, sf::Color::Black, false, false));

	add_entity(std::make_shared<Button>(std::string("Admit"),				30u, OutlineThickness, sf::Vector2f(600.0f, 80.0f), sf::Vector2f(1200.0f, 300.0f), sf::Color::Black, lightYellow, sf::Color::Black, ScreenId::admit));
	add_entity(std::make_shared<Button>(std::string("Discharge"),		    30u, OutlineThickness, sf::Vector2f(600.0f, 80.0f), sf::Vector2f(1200.0f, 420.0f), sf::Color::Black, lightYellow, sf::Color::Black, ScreenId::discharge));
	add_entity(std::make_shared<Button>(std::string("Appointment"),			30u, OutlineThickness, sf::Vector2f(600.0f, 80.0f), sf::Vector2f(1200.0f, 540.0f), sf::Color::Black, lightYellow, sf::Color::Black, ScreenId::schedule_appointment));
	add_entity(std::make_shared<Button>(std::string("Scheduling Tests"),	30u, OutlineThickness, sf::Vector2f(600.0f, 80.0f), sf::Vector2f(1200.0f, 660.0f), sf::Color::Black, lightYellow, sf::Color::Black, ScreenId::schedule_tests));
	add_entity(std::make_shared<Button>(std::string("Patient Information"), 30u, OutlineThickness, sf::Vector2f(600.0f, 80.0f), sf::Vector2f(1200.0f, 780.0f), sf::Color::Black, lightYellow, sf::Color::Black, ScreenId::patient_information, FuncType::get_patient_information));
	add_entity(std::make_shared<Button>(std::string("Admit History"),		30u, OutlineThickness, sf::Vector2f(600.0f, 80.0f), sf::Vector2f(1200.0f, 900.0f), sf::Color::Black, lightYellow, sf::Color::Black, ScreenId::admit_history));
}

void Patient_Home_Screen::erase_form(){
	/*for (int i = 11; i <= 18; i++) {
		all_entities[i]->setText("");
	}*/
}

void Patient_Home_Screen::fill_form(std::vector<std::string>& data) {
	for (int i = 11; i <= 18; i++) {
		all_entities[i]->setText(data[i - 11]);
	}
}

std::vector<std::string> Patient_Home_Screen::extract_form(sf::Vector2f mouse_pos) {
	return { all_entities[11]->getText()};
}
