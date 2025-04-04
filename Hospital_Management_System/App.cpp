#include "App.h"

App::App() {
	window_width = window_height = 0;
	curr_frame = 0;
	fps = 60u;
}

void App::set_curr_scene(SceneId _scene_id) {
	curr_scene_id = _scene_id;
}

void App::initialise_scenes() {
	all_scenes.push_back(std::make_shared<Login_Screen>(window_width, window_height));

	set_curr_scene(SceneId::login_screen);
}

void App::run() {
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	window_width	= desktop.width;
	window_height	= desktop.height;

	app_window.create(desktop, "Hostpital DBMS", sf::Style::Fullscreen);
	app_window.setFramerateLimit(fps);

	initialise_scenes();

	while (app_window.isOpen()) {
	    sf::Event event;

	    while (app_window.pollEvent(event)) {
	        if(event.type == sf::Event::Closed) app_window.close();
			if(event.type == sf::Event::KeyPressed) app_window.close();
	    }
	
		app_window.clear(sf::Color::White);
		all_scenes[static_cast<int>(curr_scene_id)]->draw_entities(app_window);
		app_window.display();
	}
}