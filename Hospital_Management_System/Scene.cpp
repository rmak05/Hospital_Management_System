#include "Scene.h"
#include "TextBox.h"
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
	add_entity(std::make_shared<TextBox>(std::string("Hospital Management System"), 50u, 0.0f, sf::Vector2f(1500.0f, 100.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, w_width * 1.0f, 1500.0f), 100.0f), sf::Color::White, app_yellow, sf::Color::White));

	add_entity(std::make_shared<TextBox>(std::string(""), 50u, 0.0f, sf::Vector2f(300.0f, 500.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, w_width * 1.0f, 1500.0f), 400.0f), sf::Color::White, app_blue_1, sf::Color::White));
	add_entity(std::make_shared<TextBox>(std::string(""), 50u, 0.0f, sf::Vector2f(300.0f, 500.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, w_width * 1.0f, 1500.0f) + 400.0f, 400.0f), sf::Color::White, app_blue_1, sf::Color::White));
	add_entity(std::make_shared<TextBox>(std::string(""), 50u, 0.0f, sf::Vector2f(300.0f, 500.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, w_width * 1.0f, 1500.0f) + 800.0f, 400.0f), sf::Color::White, app_blue_1, sf::Color::White));
	add_entity(std::make_shared<TextBox>(std::string(""), 50u, 0.0f, sf::Vector2f(300.0f, 500.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, w_width * 1.0f, 1500.0f) + 1200.0f, 400.0f), sf::Color::White, app_blue_1, sf::Color::White));

	add_entity(std::make_shared<TextBox>(std::string("Front Desk"), 30u, 5.0f, sf::Vector2f(270.0f, 100.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, w_width * 1.0f, 1500.0f) + 15.0f, 770.0f), sf::Color::Black, app_yellow, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Data Entry"), 30u, 5.0f, sf::Vector2f(270.0f, 100.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, w_width * 1.0f, 1500.0f) + 415.0f, 770.0f), sf::Color::Black, app_yellow, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Doctor"), 30u, 5.0f, sf::Vector2f(270.0f, 100.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, w_width * 1.0f, 1500.0f) + 815.0f, 770.0f), sf::Color::Black, app_yellow, sf::Color::Black));
	add_entity(std::make_shared<TextBox>(std::string("Admin"), 30u, 5.0f, sf::Vector2f(270.0f, 100.0f), sf::Vector2f(get_center_coord(LEFT_MARGIN, w_width * 1.0f, 1500.0f) + 1215.0f, 770.0f), sf::Color::Black, app_yellow, sf::Color::Black));
}