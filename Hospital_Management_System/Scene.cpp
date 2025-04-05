#include "Scene.h"
#include "TextBox.h"
#include "ImageBox.h"
#include "Theme.h"

Scene::Scene() {
	id = SceneId::_default;
	window_width = window_height = 0;
}

Scene::Scene(SceneId _id, int w_width, int w_height) {
	id = _id;
	window_width = w_width;
	window_height = w_height;
}

float Scene::get_center_coord(float div_x, float div_size, float box_size) {
	float box_x = (div_x + (div_size / 2.0f)) - (box_size / 2.0f);

	return box_x;
}

void Scene::draw_entities(sf::RenderWindow& window) {
	for (entity_ptr& _entity : all_entities) {
		_entity->drawTo(window);
	}
}

void Scene::add_entity(entity_ptr _entity) {
	all_entities.push_back(_entity);
}

Login_Screen::Login_Screen(int w_width, int w_height) : Scene(SceneId::login_screen, w_width, w_height) {

	add_entity(std::make_shared<TextBox>(std::string("HOSPITAL  MANAGEMENT  SYSTEM"), 50u, 0.0f, sf::Vector2f(1500.0f, 100.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f), 100.0f), sf::Color::White, darkYellow, sf::Color::White));

	add_entity(std::make_shared<TextBox>(std::string(""), 50u, 0.0f, sf::Vector2f(300.0f, 500.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f), 400.0f),		   sf::Color::White, bgBlue, sf::Color::White));
	add_entity(std::make_shared<TextBox>(std::string(""), 50u, 0.0f, sf::Vector2f(300.0f, 500.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 400.0f, 400.0f),  sf::Color::White, bgBlue, sf::Color::White));
	add_entity(std::make_shared<TextBox>(std::string(""), 50u, 0.0f, sf::Vector2f(300.0f, 500.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 800.0f, 400.0f),  sf::Color::White, bgBlue, sf::Color::White));
	add_entity(std::make_shared<TextBox>(std::string(""), 50u, 0.0f, sf::Vector2f(300.0f, 500.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 1200.0f, 400.0f), sf::Color::White, bgBlue, sf::Color::White));

	add_entity(std::make_shared<TextBox>(std::string("Front Desk"), 30u, buttonOutlThick, sf::Vector2f(200.0f, 80.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 50.0f, 770.0f),   sf::Color::Black, darkYellow, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Data Entry"), 30u, buttonOutlThick, sf::Vector2f(200.0f, 80.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 450.0f, 770.0f),  sf::Color::Black, darkYellow, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Doctor"),     30u, buttonOutlThick, sf::Vector2f(200.0f, 80.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 850.0f, 770.0f),  sf::Color::Black, darkYellow, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Admin"),      30u, buttonOutlThick, sf::Vector2f(200.0f, 80.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 1250.0f, 770.0f), sf::Color::Black, darkYellow, sf::Color::Black));

	add_entity(std::make_shared<ImageBox>(std::string("./Images/frontDesk.png"), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 50.0f, 500.0f), sf::Vector2f(1.0f,1.0f)));
	add_entity(std::make_shared<ImageBox>(std::string("./Images/dataEntry.png"), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 480.0f, 500.0f), sf::Vector2f(0.3f, 0.3f)));
	add_entity(std::make_shared<ImageBox>(std::string("./Images/doctors.png"), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 850.0f, 500.0f), sf::Vector2f(1.0f, 1.0f)));
	add_entity(std::make_shared<ImageBox>(std::string("./Images/admin.png"), sf::Vector2f(get_center_coord(LEFT_MARGIN, (w_width - 2 * LEFT_MARGIN) * 1.0f, 1500.0f) + 1270.0f, 500.0f), sf::Vector2f(1.0f, 1.0f)));
}