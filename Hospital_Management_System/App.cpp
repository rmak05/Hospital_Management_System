#include "App.h"

App::App() {
	window_width = window_height = 0;
	curr_frame = 0;
	fps = 60u;
	curr_scene_id = SceneId::_default;
}

void App::set_curr_scene(SceneId _scene_id) {
	curr_scene_id = _scene_id;
}

void App::initialise_scenes() {
	all_scenes.push_back(std::make_shared<Login_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Front_Desk_Login_Screen>(window_width, window_height));

	set_curr_scene(SceneId::frontdesk_login);
}

void App::run() {
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	window_width	= desktop.width;
	window_height	= desktop.height;

	app_window.create(desktop, "Hostpital DBMS", sf::Style::Fullscreen);
	app_window.setFramerateLimit(fps);

	initialise_scenes();

	while (app_window.isOpen()) {
		curr_frame++;
		curr_frame %= 1000000000;

	    sf::Event event;
	    while (app_window.pollEvent(event)) {
	        if(event.type == sf::Event::Closed){
				app_window.close();
			}
			else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)) {
				app_window.close();
			}
			else if (event.type == sf::Event::TextEntered) {
				all_scenes[static_cast<int>(curr_scene_id)]->check_typed_text(event.text.unicode);
			}
			else if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Button::Left) {
				    sf::Vector2f mouse_pos((float)(event.mouseButton.x), (float)(event.mouseButton.y));

					SceneId next_scene = all_scenes[static_cast<int>(curr_scene_id)]->get_next_scene(mouse_pos);
					if(next_scene != SceneId::_default) set_curr_scene(next_scene);

					all_scenes[static_cast<int>(curr_scene_id)]->select_text_input(mouse_pos);
				}
			}
	    }

		all_scenes[static_cast<int>(curr_scene_id)]->check_mouse_hover(app_window);
		all_scenes[static_cast<int>(curr_scene_id)]->blink_cursor(curr_frame);
	
		app_window.clear(sf::Color::White);
		all_scenes[static_cast<int>(curr_scene_id)]->draw_entities(app_window);
		app_window.display();
	}
}