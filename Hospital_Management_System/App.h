#pragma once

#include <SFML/Graphics.hpp>
#include "Scene.h"

#define TOP_MARGIN 20		//in pixels
#define LEFT_MARGIN	20		//in pixels
#define RIGHT_MARGIN 20		//in pixels
#define BOTTOM_MARGIN 20	//in pixels

struct config;
class App;

// can load some app specific configurations if necessary
struct config {

};

// main function will create this object and initiate the application using run function
// the main while loop would be inside run function
class App {
private:
	sf::RenderWindow app_window;
	int window_width;
	int window_height;
	int curr_frame;

	std::vector<scene_ptr> all_scenes;
	SceneId curr_scene_id;
	std::map<SceneId, scene_ptr> scenes_map;

	void set_curr_scene(SceneId _scene_id);
	void change_scene();

public:
	App();

	void run();
};