#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
//#include <map>
#include <memory>
#include "Scene.h"
#include "Theme.h"

class App;
struct config;

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
	unsigned fps;
	int curr_frame;

	std::vector<scene_ptr> all_scenes;
	SceneId curr_scene_id;
	//std::map<SceneId, scene_ptr> scenes_map;

	void set_curr_scene(SceneId _scene_id);
	void initialise_scenes();
	//void change_scene();

public:
	App();

	void run();
};