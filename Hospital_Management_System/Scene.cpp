#include "Scene.h"
#include "TextBox.h"

Scene::Scene() {
	id = SceneId::_default;
}

Scene::Scene(SceneId _id) {
	id = _id;
}

void Scene::draw_entities(sf::RenderWindow& window) {
	for (entity_ptr& _entity : all_entities) {
		_entity->drawTo(window);
	}
}

void Scene::add_entity(entity_ptr _entity) {
	all_entities.push_back(_entity);
}

Login_Screen::Login_Screen() : Scene(SceneId::login_screen) {
	add_entity(std::make_shared<TextBox>(std::string("Click"), 30u, sf::Vector2f(500.0f, 50.0f), sf::Vector2f(50.0f, 50.0f), sf::Color::White, sf::Color::Green, sf::Color::White));
}