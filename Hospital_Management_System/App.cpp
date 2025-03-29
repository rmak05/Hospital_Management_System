#include "App.h"

App::App() {
	window_width = window_height =0;
}

void App::run() {
	sf::VideoMode desktop	= sf::VideoMode::getDesktopMode();
	window_width	= desktop.width;
	window_height	= desktop.height;

	sf::RenderWindow window(desktop, "Hostpital DBMS", sf::Style::Fullscreen);

	sf::CircleShape shape(100.f);
	shape.setPosition(TOP_MARGIN * 1.0f, LEFT_MARGIN * 1.0f);
	shape.setFillColor(sf::Color::Green);
	
	while(window.isOpen()){
	    sf::Event event;

	    while(window.pollEvent(event)){
	        if (event.type == sf::Event::Closed) window.close();
			if(event.type == sf::Event::KeyPressed) window.close();
	    }
	
	    window.clear();
	    window.draw(shape);
	    window.display();
	}
}