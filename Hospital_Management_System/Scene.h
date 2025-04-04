#pragma once

#include <memory>
#include <vector>
#include "Entity.h"
//#include "Action.h"

class Scene;
class Login_Screen;
enum class SceneId;
typedef std::shared_ptr<Scene> scene_ptr;

// one enum value for each screen
enum class SceneId {
	_default		= (-1),
	login_screen	= 0
};

class Scene {
public:
	std::vector<entity_ptr> all_entities;
	SceneId id;

	Scene();
	Scene(SceneId _id);

	void add_entity(entity_ptr _entity);
	void draw_entities(sf::RenderWindow& window);

	//virtual void initialise() = 0;

	// key pressed to action name
	//std::map<int, ActionName> action_map;
	//void registerAction(const int _key, const ActionName _action_name);
};

class Login_Screen : public Scene {
public:
	//void initialise();

	Login_Screen();

	// Systems
};