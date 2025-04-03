#pragma once

#include "Entity.h"
#include <memory>
//#include "Action.h"

class Scene;
enum class SceneId;
typedef std::shared_ptr<Scene> scene_ptr;

// one enum value for each screen
enum class SceneId {

};

class Scene {
public:
	std::vector<entity_ptr> all_scene_entities;

	// key pressed to action name
	//std::map<int, ActionName> action_map;
	//void registerAction(const int _key, const ActionName _action_name);

	virtual void initialise() = 0;
};

class SceneMenu : public Scene {
public:
	void initialise();

	// Systems
};