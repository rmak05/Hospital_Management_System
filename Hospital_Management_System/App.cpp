#include "App.h"
#include "Debug.h"

sf::Font global_font;

App::App() {
	window_width = window_height = 0;
	curr_frame = 0;
	fps = 60u;
	curr_scene_id = ScreenId::_default;
	if (!global_font.loadFromFile("Fonts/NotoSans.ttf")) {
		std::cout << "Error loading the font file\n";
		return;
	}
}

void App::set_curr_screen(ScreenId _scene_id) {
	curr_scene_id = _scene_id;
}

void App::initialise_scenes() {
	all_scenes.push_back(std::make_shared<Home_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Front_Desk_Login_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Front_Desk_Home_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Register_Patient_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Update_Patient_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Login_Patient_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Patient_Home_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Update_Login_Patient_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Doctor_Login_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Doctor_Home_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Appointment_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Patient_Appointment_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Presc_Appointment_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Tests_Appointment_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Admit_Appointment_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Patient_Record_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Patient_Details_Home_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Test_History_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Appointment_History_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Patient_Details_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Test_Results_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Presc_Given_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<My_Information_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Data_Entry_Login_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Data_Entry_Login_Patient_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Pending_Tests_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Push_Test_Results_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Patient_Information_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Admit_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Discharge_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Schedule_Appointment_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Schedule_Tests_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Admit_History_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Choose_Room_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<FrontDesk_Admit_Patient_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Admin_Login_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Admin_Home_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Appointment_Slots_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Approve_Appointment_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Test_Slots_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Approve_Test_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Manage_Doctor_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Register_Doctor_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Delete_Doctor_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Update_Doctor_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<Update_Doctor_Details_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<View_Doctor_Filters_Screen>(window_width, window_height));
	all_scenes.push_back(std::make_shared<View_Doctor_Screen>(window_width, window_height));

	set_curr_screen(ScreenId::home);
}

void App::run() {
	debug::activate();

	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	window_width	= desktop.width;
	window_height	= desktop.height;

	//app_window.create(desktop, "Hospital Management System", sf::Style::Fullscreen);
	app_window.create(sf::VideoMode(1920, 1180), "Hospital Management System");
	window_width = 1920;
	window_height = 1180;

	app_window.setFramerateLimit(fps);
	sf::Image app_icon;
	if (app_icon.loadFromFile("Images/hospital_icon.png")) {
		app_window.setIcon(app_icon.getSize().x, app_icon.getSize().y, app_icon.getPixelsPtr());
	}

	initialise_scenes();

	while (app_window.isOpen()) {
		curr_frame++;
		curr_frame %= 1000000000;

		sf::Event event;
		while (app_window.pollEvent(event)) {
			if(event.type == sf::Event::Closed) {
				app_window.close();
			}
			else if ((event.type == sf::Event::KeyPressed)) {
				if(event.key.code == sf::Keyboard::Escape) app_window.close();
			}
			else if (event.type == sf::Event::TextEntered) {
				all_scenes[static_cast<int>(curr_scene_id)]->check_typed_text(event.text.unicode);
			}
			else if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Button::Left) {
					sf::Vector2f mouse_pos((float)(event.mouseButton.x), (float)(event.mouseButton.y));

					all_scenes[static_cast<int>(curr_scene_id)]->select_text_input(mouse_pos);

					std::vector<std::string> data = (all_scenes[static_cast<int>(curr_scene_id)]->callBack(mouse_pos, database));

					if (data.back() == "0") {
						ScreenId next_scene = all_scenes[static_cast<int>(curr_scene_id)]->get_next_screen(mouse_pos);

						if (next_scene == ScreenId::_exit) {
							app_window.close();

							break;
						}

						all_scenes[static_cast<int>(curr_scene_id)]->erase_form();

						if (next_scene != ScreenId::_default) set_curr_screen(next_scene);
					}
					else if (data.back() == "1") {
						ScreenId next_scene = all_scenes[static_cast<int>(curr_scene_id)]->get_next_screen(mouse_pos);

						all_scenes[static_cast<int>(curr_scene_id)]->erase_form();

						if (next_scene != ScreenId::_default) {
							set_curr_screen(next_scene);
							all_scenes[static_cast<int>(curr_scene_id)]->fill_form(data);
						}
					}
				}
				else if (event.mouseButton.button == sf::Mouse::Button::Right) {
					debug::update();
				}
			}
			else if (event.type == sf::Event::MouseWheelScrolled) {
				if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
					int scroll_ticks = (int)event.mouseWheelScroll.delta;
					
					all_scenes[static_cast<int>(curr_scene_id)]->scroll_entities(scroll_ticks);
				}
			}
		}

		all_scenes[static_cast<int>(curr_scene_id)]->check_mouse_hover(app_window);

		all_scenes[static_cast<int>(curr_scene_id)]->blink_cursor(curr_frame);

		app_window.clear(bgWhite);
		all_scenes[static_cast<int>(curr_scene_id)]->draw_entities(app_window);
		debug::draw(app_window);
		app_window.display();
	}

	debug::deactivate();
}