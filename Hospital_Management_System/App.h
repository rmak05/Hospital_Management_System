#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include "Screen.h"
#include "Theme.h"
#include "HomeScreen.h"
#include "FrontDeskLoginScreen.h"

class App;

class App {
private:
	sf::RenderWindow app_window;
	int window_width;
	int window_height;
	unsigned fps;
	int curr_frame;

	std::vector<scene_ptr> all_scenes;
	ScreenId curr_scene_id;

	void set_curr_screen(ScreenId _scene_id);
	void initialise_scenes();

public:
	App();

	void run();
};