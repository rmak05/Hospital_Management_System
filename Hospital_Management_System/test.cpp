#include "Button.h"
#include "TextInput.h"
#include "TextBox.h"
#include "ImageBox.h"

static void testButton() {

	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(desktop, "Hostpital DBMS", sf::Style::Fullscreen);

	 Button btn("Click", 30, 0.0f, { 500,50 }, {50, 50}, sf::Color::White, sf::Color::Green, sf::Color::White);

	btn.setFont("Resources/NotoSans.ttf");
	btn.setPosition({ 200,100 });

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {

			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::MouseMoved:
				if (btn.isMouseHover(window)) {
					btn.setBackgroundColor(sf::Color::White);
				}
				else {
					btn.setBackgroundColor(sf::Color::Green);
				}
				break;

			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left) {
					if (btn.isMouseHover(window)) {
						window.close();
					}
				}
				if (event.mouseButton.button == sf::Mouse::Right) {
					btn.setBackgroundColor(sf::Color::Red);
				}
				break;
			}
		}

		window.clear();
		btn.drawTo(window);
		window.display();
	}

}

static void testTextInput() {

	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(desktop, "Hostpital DBMS", sf::Style::Fullscreen);

	TextInput ti(30, { 500,50 }, sf::Color::White, sf::Color::Green, sf::Color::White);
	TextInput ti2(30, { 500,50 }, sf::Color::White, sf::Color::Green, sf::Color::White);

	ti.setFont("Resources/NotoSans.ttf");
	ti.setPosition({ 200,100 });
	ti.setBackgroundColor(sf::Color::Magenta);
	ti.setLimit(true, 20);

	ti2.setFont("Resources/NotoSans.ttf");
	ti2.setPosition({ 200,300 });
	ti2.setLimit(true, 20);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {

			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::TextEntered:
				ti.typedOn(event);
				ti2.typedOn(event);
				break;

			case sf::Event::MouseMoved:
				ti.isMouseHover(window);
				ti2.isMouseHover(window);
				break;

			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left) {
					ti.setSelected(window);
					ti2.setSelected(window);
				}
				break;
			}
		}

		if (ti.getText() == "BYE") {
			window.close();
		}
		window.clear();
		ti.drawTo(window);
		ti2.drawTo(window);
		window.display();
	}
}

static void testTextBox() {

	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(desktop, "Hostpital DBMS", sf::Style::Fullscreen);

	TextBox tb("Click", 30, 0.0f, { 500,50 }, {50, 50}, sf::Color::White, sf::Color::Green, sf::Color::White);

	//tb.setFont("Resources/NotoSans.ttf");
	//tb.setPosition({ 200,100 });

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {

				case sf::Event::Closed:
					window.close();
					break;
			}

			if(event.type == sf::Event::Closed) window.close();
			if(event.type == sf::Event::KeyPressed) window.close();
		}

		window.clear();
		tb.drawTo(window);
		window.display();
	}
}

static void testImageBox() {

	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::RenderWindow window(desktop, "Hostpital DBMS", sf::Style::Fullscreen);

	ImageBox ib("./Images/frontDesk.png",{0.0f,0.0f},{0.0f,0.0f});
	ib.setPosition({ 500,500 });
	ib.scaleImage({ 1.5f,2.0f });
	ib.movePosition({ 200,0 });

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type) {

			case sf::Event::Closed:
				window.close();
				break;
			}

			if (event.type == sf::Event::Closed) window.close();
			if (event.type == sf::Event::KeyPressed) window.close();
		}

		window.clear();
		ib.drawTo(window);
		window.display();
	}
}

//int main() {
//	testImageBox();
//	return 0;
//}