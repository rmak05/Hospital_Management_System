#pragma once

#include <memory>
#include <vector>
#include "Entity.h"
#include "Entity_Scene_Types.h"
//#include "Action.h"

class Scene;
class Login_Screen;
class Front_Desk_Login_Screen;
//enum class SceneId;
typedef std::shared_ptr<Scene> scene_ptr;

// one enum value for each screen
//enum class SceneId {
//	_default			= (-1),
//	login				= 0,
//	frontdesk_login		= 1
//};

class Scene {
public:
	std::vector<entity_ptr> all_entities;
	SceneId id;

	int window_width;
	int window_height;

	Scene();
	Scene(SceneId _id, int w_width, int w_height);

	void draw_entities(sf::RenderWindow& window);
	void blink_cursor(int curr_frame);
	SceneId get_next_scene(sf::Vector2f mouse_pos);
	void check_mouse_hover(sf::RenderWindow& window);
	void select_text_input(sf::Vector2f mouse_pos);
	void check_typed_text(sf::Uint32 input);

	//virtual void initialise() = 0;

	// key pressed to action name
	//std::map<int, ActionName> action_map;
	//void registerAction(const int _key, const ActionName _action_name);

protected:
	float get_center_coord(float div_x, float div_size, float box_size);
	void add_entity(entity_ptr _entity);
};

class Login_Screen : public Scene {
public:
	//void initialise();

	Login_Screen(int w_width, int w_height);

	// Systems
};

class Front_Desk_Login_Screen : public Scene {
public:
	//void initialise();

	Front_Desk_Login_Screen(int w_width, int w_height);

	// Systems
};